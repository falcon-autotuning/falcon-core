#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
extract_cpp_docs.py

Reads C/C++ header files, extracts leading doc comments (/** ... */ or triple
/// lines) and associates each with the immediately following declaration
(function/class/struct/using/enum). Emits either:

  1) Per-file metadata (default): one YAML (or JSON fallback) file per header,
     saved to a *mirrored* tree rooted at --meta-root
     (default: ./docs_managment_code/cpp_metadata), preserving the path
     *after* "cpp/". Example:

         /path/.../cpp/include/.../Thing.hpp
     ->  ./docs_managment_code/cpp_metadata/include/.../Thing_metadata.yml

     Use --same-dir to place the metadata next to the header instead:
         /path/.../cpp/include/.../Thing_metadata.yml

  2) Aggregate output: if --out is provided, write a single JSON/YAML file
     containing all extracted data (old behavior).

Optional mapping:
  --map MAP.yml --mapped-out OUT.(yml|json)
  Applies a YAML mapping (cpp symbol -> C function) and emits a flat list
  with C function name, original C++ name/decl, and cleaned comment.

Directory processing:
  You can pass one or more **directories** as inputs; by default we recurse and
  pick up all headers with extensions in --exts (default: .h,.hpp,.hh,.hxx).
  Use --no-recursive to disable recursion, and --include/--exclude to filter.

Usage examples:
  # Process one header (per-file mirrored outputs under meta-root)
  python3 extract_cpp_docs.py ./cpp/include/.../Connection.hpp

  # Process an entire directory (recursively)
  python3 extract_cpp_docs.py ./cpp/include/falcon_core/physics/device_structures

  # Same as above, but write metadata next to headers (no mirroring)
  python3 extract_cpp_docs.py ./cpp/include/... --same-dir

  # Aggregate output (single file)
  python3 extract_cpp_docs.py ./cpp/include/... --out ./c-api/include/.../AllDocs.yml

  # Mapping step
  python3 extract_cpp_docs.py ./cpp/include/... \
      --map ./c-api/include/.../Connection_c_api.map.yml \
      --mapped-out ./c-api/include/.../Connection_mapped.yml

  # Directory with filters and custom extensions
  python3 extract_cpp_docs.py ./cpp/include \
      --exts .hpp,.hxx \
      --include 'device_structures/' \
      --exclude '/test/'
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional

# --- Comment + declaration matching (regex-based, pragmatic) -----------------

# Match either a Doxygen block comment or one/more /// lines
BLOCK_OR_TRIPLE = r'(?:/\*\*[\s\S]*?\*/|(?:///[^\n]*\n)+)'

# Find class definitions
# CLASS_DEF_RE = re.compile(r'\bclass\s+([A-Za-z_]\w*)[^;{]*\{', re.MULTILINE)
CLASS_DEF_RE = re.compile(
    r'^\s*class\s+([A-Za-z_]\w*)[^;{]*\{',
    re.MULTILINE,
)


# A declaration ends at ';' or '{' (prototype or definition start)
DECL_RE = re.compile(
    rf"""
    (?P<comment>{BLOCK_OR_TRIPLE})\s*               # leading doc comment
    (?P<decl>                                       # the declaration we attach to
        (?:template\s*<[^>]*>\s*)?                  # optional template header
        (?:
            # Type declarations (class/struct/enum/union)
            (?:(?P<kw>class|struct|enum|union)\s+[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*[^;{{]*[;{{])|
            # Using/typedef aliases
            (?:(?:using|typedef)\s+[^;]+;)|
            # Function-like: includes free functions, methods, ctors/dtors
            (?:[^;{{\n]+?\([^;{{]*\)\s*(?:const|noexcept)?\s*[;{{])
        )
    )
    """,
    re.VERBOSE | re.DOTALL,
)

# --- New, more robust doc & decl matchers ---

# 1) Match a docblock ONLY (no code)
DOC_RE = re.compile(
    r'/\*\*[\s\S]*?\*/'          # /** ... */ block
    r'|(?:///[^\n]*\n)+',        # or one-or-more /// lines
    re.DOTALL,
)

# 2) Match the FIRST declaration that follows a docblock.
#    We allow multi-line return types and templates; we only insist
#    that somewhere we see "name(...)" followed by ';' or '{'.
DECL_AFTER_DOC_RE = re.compile(
    r"""
    (?:template\s*<[^>]*>\s*)*           # optional template header(s)

    # Eat any leading whitespace / newlines
    [ \t\r\n]*

    # Capture a declaration that ends with a function-like pattern
    (?:
        # Type declarations: class/struct/enum/union (for completeness)
        (?:(?:class|struct|enum|union)\s+[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*[^;{]*[;{])
        |
        # using / typedef aliases
        (?:(?:using|typedef)\s+[^;]+;)
        |
        # Function-ish: allow multi-line return type, then name(...)[const/noexcept][;|{]
        (?:
            # Return type (possibly multi-line, with templates)
            [^\(\);{}]*?
            # Function name
            ([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)
            \s*
            \(
                [^;{}]*        # parameter list (may be multi-line, no semicolons/braces)
            \)
            \s*
            (?:const\b\s*)?
            (?:noexcept\b\s*)?
            [;{]
        )
    )
    """,
    re.VERBOSE | re.DOTALL,
)


FUN_NAME_RE = re.compile(r'([~A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s*\(')
NS_OPEN_RE  = re.compile(r'^\s*namespace\s+([A-Za-z_]\w*)\s*\{', re.MULTILINE)
CLEAN_PREFIX = re.compile(r'^\s*(/\*\*|\*/|\* ?|///)\s?', re.MULTILINE)


def clean_comment(c: str) -> str:
    return CLEAN_PREFIX.sub('', c).strip()


def likely_kind_and_name(decl: str) -> Dict[str, Optional[str]]:
    d = decl.strip()
    if d.startswith('class '):  return {'kind': 'class', 'name': None}
    if d.startswith('struct '): return {'kind': 'struct', 'name': None}
    if d.startswith('enum '):   return {'kind': 'enum', 'name': None}
    if d.startswith('union '):  return {'kind': 'union', 'name': None}
    if d.startswith('using ') or d.startswith('typedef '):
        return {'kind': 'alias', 'name': None}
    fm = FUN_NAME_RE.search(d)
    if fm:
        return {'kind': 'function', 'name': fm.group(1)}
    return {'kind': 'declaration', 'name': None}


def extract_units(text: str) -> list[dict]:
    """
    Extract doc+declaration units from C++ source text.

    Strategy:
      1) Find each Doxygen-style docblock (/** ... */ or ///...).
      2) From the end of that block, find the FIRST declaration that follows.
      3) Use likely_kind_and_name + namespace + class scopes to build 'name' and 'kind'.
    """
    units: list[dict] = []

    # --- 1) Namespace hint (unchanged from your original logic) ---
    ns_parts = [m.group(1) for m in NS_OPEN_RE.finditer(text)]
    ns_hint = '::'.join(ns_parts) if ns_parts else ''

    # --- 2) Find class scopes for method qualification ---
    class_scopes = []

    def find_class_end(start_pos: int) -> int:
        """
        Given the position of the '{' after 'class Name', scan forward
        to find the matching '}' using a simple brace counter.
        """
        depth = 0
        for i, ch in enumerate(text[start_pos:], start=start_pos):
            if ch == '{':
                depth += 1
            elif ch == '}':
                depth -= 1
                if depth == 0:
                    return i + 1
        return len(text)

    for cm in CLASS_DEF_RE.finditer(text):
        class_name = cm.group(1)
        brace_pos = text.find('{', cm.end() - 1)
        if brace_pos == -1:
            continue
        end_pos = find_class_end(brace_pos)
        class_scopes.append({
            "name": class_name,
            "start": cm.start(),
            "end":   end_pos,
        })

    def containing_class(pos: int) -> str | None:
        for cs in class_scopes:
            if cs["start"] <= pos < cs["end"]:
                return cs["name"]
        return None

    # --- 3) Walk through each docblock, attach first decl after it ---
    pos = 0
    while True:
        doc_match = DOC_RE.search(text, pos)
        if not doc_match:
            break

        comment_raw = doc_match.group(0)
        decl_search_start = doc_match.end()

        decl_match = DECL_AFTER_DOC_RE.search(text, decl_search_start)
        if not decl_match:
            # No declaration after this docblock; move past the comment and continue
            pos = doc_match.end()
            continue

        decl_text = decl_match.group(0).strip()
        decl_pos = decl_match.start()

        info = likely_kind_and_name(decl_text)
        base_name = info["name"]
        kind = info["kind"]

        # Which class scope is this inside?
        cls_name = containing_class(decl_pos)

        full_name = base_name
        if base_name:
            # If we're inside a class and name isn't already qualified, add Class::name
            if cls_name and '::' not in base_name and base_name != cls_name:
                full_name = f"{cls_name}::{base_name}"

            # Add namespace prefix if not already present
            if ns_hint and not full_name.startswith(ns_hint + '::'):
                full_name = f"{ns_hint}::{full_name}"

        units.append({
            "comment_raw": comment_raw,
            "comment":     clean_comment(comment_raw),
            "declaration": decl_text,
            "kind":        kind,
            "name":        full_name,
        })

        # Advance past this declaration to avoid re-matching it
        pos = decl_match.end()

    return units


def _gather_headers(inputs: List[Path], exts: List[str], recursive: bool,
                    include_rx: Optional[re.Pattern], exclude_rx: Optional[re.Pattern]) -> List[Path]:
    headers: List[Path] = []

    def want(p: Path) -> bool:
        s = str(p)
        if include_rx and not include_rx.search(s):
            return False
        if exclude_rx and exclude_rx.search(s):
            return False
        return True

    for inp in inputs:
        if inp.is_file() and inp.suffix.lower() in exts:
            if want(inp):
                headers.append(inp)
        elif inp.is_dir():
            it = inp.rglob('*') if recursive else inp.glob('*')
            for q in it:
                if q.is_file() and q.suffix.lower() in exts:
                    if want(q):
                        headers.append(q)
    # De-dup and sort
    return sorted(set(h.resolve() for h in headers))


def walk_and_extract(paths: List[Path], exts=('.h', '.hpp', '.hh', '.hxx'),
                     recursive: bool = True,
                     include_rx: Optional[re.Pattern] = None,
                     exclude_rx: Optional[re.Pattern] = None
                     ) -> Dict[str, List[Dict[str, Any]]]:
    """Walk files/dirs and extract units from headers."""
    results: Dict[str, List[Dict[str, Any]]] = {}
    headers = _gather_headers(paths, list(exts), recursive, include_rx, exclude_rx)
    for f in headers:
        try:
            text = f.read_text(encoding='utf-8', errors='ignore')
        except Exception as e:
            print(f'warn: cannot read {f}: {e}', file=sys.stderr)
            continue
        units = extract_units(text)
        if units:
            results[str(f)] = units
    return results


# --- Mapping (C++ docs -> C function names) ----------------------------------

def apply_mapping(extracted: Dict[str, List[Dict[str, Any]]], map_path: Path) -> List[Dict[str, Any]]:
    try:
        import yaml  # type: ignore
    except Exception:
        print("pyyaml is required for --map/--mapped-out", file=sys.stderr)
        raise
    cfg = yaml.safe_load(map_path.read_text(encoding='utf-8'))
    mappings = cfg.get('mappings', [])

    items = []
    for file, units in extracted.items():
        for u in units:
            items.append({
                'file': file,
                'name': u.get('name'),
                'decl': u.get('declaration'),
                'comment': u.get('comment'),
                'kind': u.get('kind'),
            })

    out: List[Dict[str, Any]] = []
    for m in mappings:
        cpp_key = m.get('cpp') or m.get('cpp_decl') or m.get('cpp_name')
        c_name  = m.get('c') or m.get('c_func') or m.get('c_name')
        if not cpp_key or not c_name:
            continue
        is_regex = isinstance(cpp_key, str) and cpp_key.startswith('re:')
        rx = re.compile(cpp_key[3:]) if is_regex else None
        for it in items:
            matched = False
            if is_regex:
                if (it['name'] and rx.search(it['name'])) or (it['decl'] and rx.search(it['decl'])):
                    matched = True
            else:
                if it['name'] == cpp_key or it['decl'] == cpp_key:
                    matched = True
            if matched:
                out.append({'c': c_name, 'cpp': it['name'], 'decl': it['decl'], 'comment': it['comment']})
    return out


# --- Per-file output helpers (mirrored tree by default) ----------------------

def _mirror_path_for_header(
    header_path: Path,
    same_dir: bool = False,
    meta_root: Optional[Path] = None,
) -> Path:
    """
    /.../cpp/include/foo/bar/Baz.hpp ->
    META_ROOT/include/foo/bar/Baz_metadata.yml  (default)

    or next to header with --same-dir:
    /.../cpp/include/foo/bar/Baz_metadata.yml
    """
    header_path = header_path.resolve()
    meta_root_path = Path(meta_root or "./docs_managment_code/cpp_metadata").resolve()
    stem = header_path.stem + "_metadata.yml"

    if same_dir:
        return header_path.with_name(stem)

    parts = list(header_path.parts)
    try:
        idx = parts.index("cpp")
    except ValueError:
        # If there's no "cpp" component, just drop it in meta_root flat
        return meta_root_path / stem

    # Preserve path after "cpp/"
    rel_after_cpp = Path(*parts[idx + 1:])  # e.g. include/falcon_core/.../Baz.hpp
    out = meta_root_path / rel_after_cpp.parent / stem
    return out


def write_per_file_outputs(
    results: Dict[str, List[Dict[str, Any]]],
    same_dir: bool = False,
    force_json: bool = False,
    meta_root: Optional[Path] = None,
) -> Dict[str, str]:
    written: Dict[str, str] = {}
    want_yaml = not force_json
    yaml_mod = None
    if want_yaml:
        try:
            import yaml as _yaml  # type: ignore
            yaml_mod = _yaml
        except Exception:
            want_yaml = False

    for file_str, units in results.items():
        hdr = Path(file_str)
        out_path = _mirror_path_for_header(hdr, same_dir=same_dir, meta_root=meta_root)
        out_path.parent.mkdir(parents=True, exist_ok=True)
        if want_yaml:
            assert yaml_mod is not None
            with open(out_path, "w", encoding="utf-8") as fh:
                yaml_mod.safe_dump(units, fh, sort_keys=False, allow_unicode=True)  # type: ignore
        else:
            out_path = out_path.with_suffix(".json")
            out_path.write_text(json.dumps(units, indent=2, ensure_ascii=False), encoding="utf-8")
        written[file_str] = str(out_path.resolve())
        print(f"Wrote {written[file_str]}")
    return written


# --- CLI ---------------------------------------------------------------------

def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument('--map', help='YAML mapping file (cpp symbol -> c function)')
    ap.add_argument('--mapped-out', help='Where to write mapped docs (.json/.yml)')
    ap.add_argument('inputs', nargs='+', help='Header files or directories to scan')
    ap.add_argument(
        '--out',
        help='Aggregate output file (.json or .yml/.yaml). '
             'If omitted, writes one metadata file per header.',
    )
    ap.add_argument(
        '--same-dir',
        action='store_true',
        help='Write the per-header metadata file next to the header '
             '(instead of mirrored tree under --meta-root).',
    )
    ap.add_argument(
        '--meta-root',
        default='./docs_managment_code/cpp_metadata',
        help='Root directory for mirrored per-header metadata '
             '(default: ./docs_managment_code/cpp_metadata)',
    )
    ap.add_argument(
        '--exts',
        default='.h,.hpp,.hh,.hxx',
        help='Comma-separated extensions to scan (default: .h,.hpp,.hh,.hxx)',
    )
    ap.add_argument(
        '--no-recursive',
        action='store_true',
        help='Do not recurse into subdirectories when inputs are directories.',
    )
    ap.add_argument('--include', help='Regex; only process paths that match this pattern.')
    ap.add_argument('--exclude', help='Regex; skip paths that match this pattern.')
    args = ap.parse_args()

    # Prepare scanning options
    exts = [e.strip().lower() for e in args.exts.split(',') if e.strip()]
    recursive = not args.no_recursive
    include_rx = re.compile(args.include) if args.include else None
    exclude_rx = re.compile(args.exclude) if args.exclude else None

    paths = [Path(p) for p in args.inputs]
    data = walk_and_extract(
        paths,
        exts=tuple(exts),
        recursive=recursive,
        include_rx=include_rx,
        exclude_rx=exclude_rx,
    )

    meta_root_path = Path(args.meta_root).resolve()

    # Optional mapping (aggregate, independent of --out)
    if args.map and args.mapped_out:
        mapped = apply_mapping(data, Path(args.map))
        mout = Path(args.mapped_out)
        mout.parent.mkdir(parents=True, exist_ok=True)
        if mout.suffix.lower() == '.json':
            mout.write_text(json.dumps(mapped, indent=2, ensure_ascii=False), encoding='utf-8')
        elif mout.suffix.lower() in ('.yml', '.yaml'):
            import yaml as _yaml  # type: ignore
            with open(mout, 'w', encoding='utf-8') as fh:
                _yaml.safe_dump(mapped, fh, sort_keys=False, allow_unicode=True)
        else:
            print('Unknown mapped-out extension; use .json or .yml/.yaml', file=sys.stderr)
        print(f'Wrote {mout.resolve()}')

    # Output strategy:
    # - If --out: write the aggregate data there (JSON/YAML)
    # - Else: per-file outputs (mirrored tree under --meta-root, or same dir with --same-dir)
    if args.out:
        out = Path(args.out)
        out.parent.mkdir(parents=True, exist_ok=True)
        if out.suffix.lower() == '.json':
            out.write_text(json.dumps(data, indent=2, ensure_ascii=False), encoding='utf-8')
            print(f'Wrote {out.resolve()}')
        elif out.suffix.lower() in ('.yml', '.yaml'):
            try:
                import yaml  # type: ignore
            except Exception:
                print('pyyaml not installed; falling back to JSON', file=sys.stderr)
                out = out.with_suffix('.json')
                out.write_text(json.dumps(data, indent=2, ensure_ascii=False), encoding='utf-8')
                print(f'Wrote {out.resolve()}')
            else:
                with open(out, 'w', encoding='utf-8') as fh:
                    import yaml as _yaml  # type: ignore
                    _yaml.safe_dump(data, fh, sort_keys=False, allow_unicode=True)
                print(f'Wrote {out.resolve()}')
        else:
            print('Unknown output extension; use .json or .yml/.yaml', file=sys.stderr)
            sys.exit(2)
    else:
        write_per_file_outputs(
            data,
            same_dir=args.same_dir,
            meta_root=meta_root_path,
        )


if __name__ == '__main__':
    main()
