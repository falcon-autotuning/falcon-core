#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
inject_c_docs.py

Injector that:

- Walks a maps directory for *.auto_map.yml files (auto-generated mappings).
- Optionally walks a manual-maps directory for *.man_map.yml (or legacy
  *.user_map.yml) files.
- For each map, finds the corresponding C header and C++ metadata file(s).
- If a user-written Doxygen block exists for a function (with a nearby
  /* USER-DOC */ marker), merges in exactly one C++ doc snippet (from either
  a manual or auto map) into that block.
- Otherwise, inserts a new Doxygen block built from the C++ docs, tagged as
  AUTO-DOC or MAN-DOC.
- Writes updated headers under --out-root, mirroring the structure under
  --capi-root.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional

try:
    import yaml  # type: ignore
except Exception:
    print("ERROR: PyYAML is required. Install with: python3 -m pip install pyyaml", file=sys.stderr)
    raise

AUTO_MARK = "/* AUTO-DOC from cpp:"
MAN_MARK  = "/* MAN-DOC from cpp:"
USER_MARK = "/* USER-DOC"  # marker used by humans in C headers


# ---------------------------------------------------------------------------
# Small helpers
# ---------------------------------------------------------------------------

def read_text(p: Path) -> str:
    return p.read_text(encoding="utf-8", errors="ignore")


def write_text(p: Path, s: str) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(s, encoding="utf-8")


def load_yaml(p: Path) -> Any:
    return yaml.safe_load(p.read_text(encoding="utf-8"))


# ---------------------------------------------------------------------------
# Metadata lookup
# ---------------------------------------------------------------------------

def find_metadata_files_for_cpp_headers(
    cpp_headers_field: Any,
    cpp_meta_root: Path,
    verbose: bool = False,
) -> List[Path]:
    """Given the cpp_headers list from a map, return a list of metadata files.

    For each entry like "../../../../cpp/include/falcon_core/math/Vector.hpp",
    we only care about the stem ("Vector") and look for
    "<stem>_metadata.yml" anywhere under cpp_meta_root.
    """
    if not cpp_headers_field:
        return []

    meta_files: List[Path] = []
    seen: set[Path] = set()

    for entry in cpp_headers_field:
        stem = Path(entry).stem  # e.g. "Vector" from ".../Vector.hpp"
        if not stem:
            continue
        pattern = f"{stem}_metadata.yml"
        found_for_this_entry = False

        for mf in cpp_meta_root.rglob(pattern):
            mf = mf.resolve()
            if mf not in seen:
                seen.add(mf)
                meta_files.append(mf)
                found_for_this_entry = True
                if verbose:
                    print(f"[meta] matched stem '{stem}' -> {mf}")
                break  # stop at first match for this stem

        if verbose and not found_for_this_entry:
            print(f"[meta] no metadata found for stem '{stem}' (entry '{entry}')")

    return meta_files


def collect_metadata_units(meta_files: List[Path], verbose: bool = False) -> List[Dict[str, Any]]:
    """Load all metadata units from the given *_metadata.yml files.
    Each file can be either a list[...] or a dict whose values may be lists.
    """
    units: List[Dict[str, Any]] = []

    for mf in meta_files:
        if not mf.exists():
            if verbose:
                print(f"[meta] missing metadata file: {mf}")
            continue

        if verbose:
            print(f"[meta] loading {mf}")
        data = load_yaml(mf)

        if isinstance(data, list):
            units.extend(data)
        elif isinstance(data, dict):
            for v in data.values():
                if isinstance(v, list):
                    units.extend(v)

    if verbose:
        print(f"[meta] total units loaded: {len(units)}")
    return units


def find_cpp_doc(units: List[Dict[str, Any]], cpp_key: str, verbose: bool = False) -> Optional[str]:
    """Find the 'comment' string for cpp_key in the list of metadata units.

    Resolution order:
      1) exact match on 'name'
      2) exact match on 'declaration'
      3) substring match on 'name'
      4) substring match on 'declaration'
    """
    # 1) exact name
    for u in units:
        if (u.get("name") or "") == cpp_key and u.get("comment"):
            if verbose:
                print(f"[map] matched by name: {cpp_key}")
            return u["comment"]

    # 2) exact declaration
    for u in units:
        if (u.get("declaration") or "") == cpp_key and u.get("comment"):
            if verbose:
                print(f"[map] matched by declaration: {cpp_key}")
            return u["comment"]

    # 3) substring in name
    for u in units:
        if cpp_key in (u.get("name") or "") and u.get("comment"):
            if verbose:
                print(f"[map] substring match in name: {cpp_key} -> {u.get('name')}")
            return u["comment"]

    # 4) substring in declaration
    for u in units:
        if cpp_key in (u.get("declaration") or "") and u.get("comment"):
            if verbose:
                print(f"[map] substring match in declaration: {cpp_key}")
            return u["comment"]

    if verbose:
        print(f"[map] no doc found for cpp key: {cpp_key}")
    return None


def _normalize_cpp_comment_for_details(comment_text: str) -> List[str]:
    """Normalize cpp comment text for embedding inside a 'Documentation imported from C++:' section.

    We strip a leading '@brief' from lines so we don't confuse Doxygen by
    nesting a new @brief inside an existing block.
    """
    lines: List[str] = []
    for ln in str(comment_text).splitlines():
        s = ln.rstrip()
        stripped = s.strip()
        if stripped.startswith("@brief"):
            stripped = stripped[len("@brief"):].lstrip(" :-\t")
        lines.append(stripped)
    return lines


def build_auto_block(c_func: str, cpp_key: str, comment_text: str) -> str:
    """Build the AUTO-DOC doxygen block that will be injected above the C prototype."""
    lines: List[str] = []
    lines.append(f"{AUTO_MARK} {c_func} | {cpp_key} */")
    lines.append("/**")
    for ln in str(comment_text).splitlines():
        ln = ln.rstrip()
        if ln:
            lines.append(f" * {ln}")
        else:
            lines.append(" *")
    lines.append(" */")
    return "\n".join(lines) + "\n"


def build_man_block(c_func: str, cpp_key: str, comment_text: str) -> str:
    """Build the MAN-DOC doxygen block (manual maps)."""
    lines: List[str] = []
    lines.append(f"{MAN_MARK} {c_func} | {cpp_key} */")
    lines.append("/**")
    for ln in str(comment_text).splitlines():
        ln = ln.rstrip()
        if ln:
            lines.append(f" * {ln}")
        else:
            lines.append(" *")
    lines.append(" */")
    return "\n".join(lines) + "\n"


# ---------------------------------------------------------------------------
# Header injection
# ---------------------------------------------------------------------------

def already_has_block_near(header_text: str, insert_pos: int, c_func: str) -> bool:
    """Check if there is already an AUTO-DOC or MAN-DOC block for this function
    in the ~500 characters before insert_pos."""
    start = max(0, insert_pos - 500)
    snippet = header_text[start:insert_pos]
    return ((AUTO_MARK in snippet) or (MAN_MARK in snippet)) and (c_func in snippet)


def _merge_into_existing_block(
    header_text: str,
    line_start: int,
    c_func: str,
    cpp_key: str,
    comment_text: str,
    is_manual_map: bool,
    verbose: bool = False,
) -> tuple[str, bool]:
    """Try to merge cpp-derived docs into an existing *user* Doxygen block.

    Conditions:
      - We look backwards from line_start for a '/**' that ends with '*/'
        before the function prototype.
      - We only treat that block as belonging to this function if there is
        no intervening *code* (only whitespace/comments) between the end
        of the block and the function prototype line.
      - We only merge if there is a nearby '/* USER-DOC */' marker above
        the block (i.e., this is user-authored documentation).
      - We only merge once; if "Documentation imported from C++" is already
        present, we skip.
    """
    # Limit backward search to keep things cheap and localized
    search_start = max(0, line_start - 2000)
    prefix = header_text[search_start:line_start]
    rel_block_start = prefix.rfind("/**")
    if rel_block_start == -1:
        return header_text, False

    block_start = search_start + rel_block_start
    end_idx = header_text.find("*/", block_start)
    if end_idx == -1 or end_idx > line_start:
        # No complete block before the prototype
        return header_text, False

    block_end = end_idx + 2
    block_text = header_text[block_start:block_end]

    # Make sure the block is *directly* attached to this function:
    # allow only whitespace and comments between the block and prototype.
    gap = header_text[block_end:line_start]
    # If we see obvious "code punctuation" in the gap, assume this block
    # belongs to a previous function and do not merge.
    if any(ch in gap for ch in "();{}#"):
        return header_text, False

    # Ensure this block is tagged as user-authored (USER-DOC nearby)
    snippet_above = header_text[max(0, block_start - 200):block_start]
    if USER_MARK not in snippet_above:
        return header_text, False

    # Avoid re-merging if we already added a "Documentation imported from C++" section
    if "Documentation imported from C++" in block_text:
        if verbose:
            print(f"[capi] existing imported C++ docs found near {c_func}, skipping merge")
        return header_text, False

    # Build the extra details section from cpp comment
    detail_lines = _normalize_cpp_comment_for_details(comment_text)
    insert_pos = block_text.rfind("*/")
    if insert_pos == -1:
        return header_text, False

    before = block_text[:insert_pos].rstrip("\n")
    after = block_text[insert_pos:]

    extra = "\n *\n * Documentation imported from C++:\n"
    for ln in detail_lines:
        if ln:
            extra += f" * {ln}\n"
        else:
            extra += " *\n"

    new_block_text = before + extra + "\n" + after

    # Add provenance comment above the block if not already present
    prov_comment = (
        f"{MAN_MARK} {c_func} | {cpp_key} */\n"
        if is_manual_map
        else f"{AUTO_MARK} {c_func} | {cpp_key} */\n"
    )
    snippet_start = max(0, block_start - 500)
    before_block = header_text[snippet_start:block_start]

    if prov_comment.strip() in before_block:
        new_prefix = header_text[:block_start]
    else:
        new_prefix = header_text[:block_start] + prov_comment

    new_header_text = new_prefix + new_block_text + header_text[block_end:]
    if verbose:
        print(f"[capi] merged C++ docs into existing user block for: {c_func}")
    return new_header_text, True


def insert_block_above_prototype(
    header_text: str,
    c_func: str,
    cpp_key: str,
    comment_text: str,
    block: str,
    is_manual_map: bool,
    verbose: bool = False,
) -> tuple[str, bool]:
    """Insert or merge a doc block above the C prototype for c_func.

    Behaviour:
      1) Locate the first occurrence of 'c_func('.
      2) If a user Doxygen block (with USER-DOC) is directly attached to
         this function, merge the C++ docs into that block (for either
         manual or auto maps), and add a provenance comment (MAN/AUTO).
      3) Otherwise, insert the given 'block' at the beginning of the line,
         unless an AUTO/MAN block is already present nearby.
    """
    needle = f"{c_func}("
    idx = header_text.find(needle)
    if idx == -1:
        if verbose:
            print(f"[capi] prototype not found for: {c_func}")
        return header_text, False

    # Find the start of the line containing the function name
    line_start = header_text.rfind("\n", 0, idx)
    if line_start == -1:
        line_start = 0
    else:
        line_start += 1

    # First try to merge into an existing user-authored block
    header_text, merged = _merge_into_existing_block(
        header_text,
        line_start,
        c_func,
        cpp_key,
        comment_text,
        is_manual_map,
        verbose=verbose,
    )
    if merged:
        return header_text, True

    # If there is already an AUTO/MAN block near this prototype, skip insertion
    if already_has_block_near(header_text, line_start, c_func):
        if verbose:
            print(f"[capi] existing AUTO-DOC/MAN-DOC found, skipping: {c_func}")
        return header_text, False

    # Insert new block (AUTO or MAN)
    new_text = header_text[:line_start] + block + header_text[line_start:]
    if verbose:
        print(f"[capi] inserted doc above: {c_func}")
    return new_text, True


def mirror_capi_path(c_header: Path, capi_root: Path, out_root: Path) -> Path:
    """Map a C header path under capi_root to its corresponding output path
    under out_root, preserving the relative directory structure."""
    c_header = c_header.resolve()
    capi_root = capi_root.resolve()
    rel = c_header.relative_to(capi_root)
    return (out_root.resolve() / rel).with_suffix(c_header.suffix)


# ---------------------------------------------------------------------------
# Map processing
# ---------------------------------------------------------------------------

def resolve_c_header_path(
    cfg: Dict[str, Any],
    map_file: Path,
    capi_root: Path,
    verbose: bool = False,
) -> Optional[Path]:
    """Resolve cfg['c_header'] to an actual file path.

    Handles:
      - c_header: "Vector_c_api.h" with the map in the same directory
      - c_header: "falcon_core/math/Vector_c_api.h" relative to capi_root
    """
    raw = cfg.get("c_header")
    if not raw:
        print(f"[warn] {map_file}: no c_header field", file=sys.stderr)
        return None

    c_path = Path(raw)

    # 1) Try relative to the map file directory (typical case for auto maps)
    cand1 = (map_file.parent / c_path).resolve()
    if cand1.exists():
        if verbose:
            print(f"[map] C header (map-dir): {cand1}")
        return cand1

    # 2) Try relative to capi_root
    cand2 = (capi_root / c_path).resolve()
    if cand2.exists():
        if verbose:
            print(f"[map] C header (capi-root): {cand2}")
        return cand2

    # 3) Fallback: search by basename under capi_root
    basename = c_path.name
    for p in capi_root.rglob(basename):
        if p.is_file():
            if verbose:
                print(f"[map] C header (search): {p}")
            return p.resolve()

    print(f"[warn] C header not found for {map_file}: {raw}", file=sys.stderr)
    return None


def process_map(
    map_file: Path,
    capi_root: Path,
    cpp_meta_root: Path,
    out_root: Path,
    *,
    verbose: bool = False,
    dry_run: bool = False,
) -> None:
    """Process a single *.auto_map.yml, *.man_map.yml, or *.user_map.yml file."""
    map_file = map_file.resolve()
    if verbose:
        print(f"\n[map] processing: {map_file}")

    cfg = load_yaml(map_file)
    if not isinstance(cfg, dict):
        print(f"[warn] {map_file}: not a dict at top level", file=sys.stderr)
        return

    # Locate the C header
    c_header_path = resolve_c_header_path(cfg, map_file, capi_root, verbose=verbose)
    if not c_header_path:
        return

    # Locate all relevant metadata files based on cpp_headers
    cpp_headers_field = cfg.get("cpp_headers") or []
    meta_files = find_metadata_files_for_cpp_headers(cpp_headers_field, cpp_meta_root, verbose=verbose)
    if not meta_files:
        if verbose:
            print(f"[meta] no metadata files for {map_file}, skipping.")
        return

    units = collect_metadata_units(meta_files, verbose=verbose)
    if not units:
        if verbose:
            print(f"[meta] no metadata units for {map_file}, skipping.")
        return

    header_text = read_text(c_header_path)
    inserted = 0

    # Decide manual vs auto based on filename
    is_manual_map = map_file.name.endswith("man_map.yml") or map_file.name.endswith("user_map.yml")

    for m in cfg.get("mappings") or []:
        cpp_key = m.get("cpp")
        c_func = m.get("c")
        if not cpp_key or not c_func:
            continue

        comment_text = find_cpp_doc(units, cpp_key, verbose=verbose)
        if not comment_text:
            continue

        if is_manual_map:
            block = build_man_block(c_func, cpp_key, comment_text)
        else:
            block = build_auto_block(c_func, cpp_key, comment_text)

        header_text, did = insert_block_above_prototype(
            header_text,
            c_func,
            cpp_key,
            comment_text,
            block,
            is_manual_map,
            verbose=verbose,
        )
        if did:
            inserted += 1

    out_path = mirror_capi_path(c_header_path, capi_root, out_root)
    if dry_run:
        print(f"[dry-run] would write {out_path} (inserted={inserted})")
        return

    write_text(out_path, header_text)
    print(f"[ok] wrote {out_path} (inserted={inserted})")


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--capi-root", default="c-api",
                    help="Root of the C API tree (e.g. ./c-api)")
    ap.add_argument("--cpp-root", default="cpp",
                    help="(Unused by this script, kept for CLI compatibility.)")
    ap.add_argument("--cpp-metadata-root", default="cpp_metadata",
                    help="Root of the extracted C++ metadata (e.g. ./cpp_metadata)")

    # Original argument: where the auto maps live.
    ap.add_argument("--maps-dir", required=False, default="c-api/include",
                    help="Root to search for *.auto_map.yml files "
                         "(e.g. ./c-api/include/falcon_core)")

    # Legacy: user maps dir with *.user_map.yml
    ap.add_argument("--user-maps-dir", required=False,
                    help="(DEPRECATED) Root to search for *.user_map.yml files "
                         "(e.g. ./docs_managment_code/c-api_user_maps)")

    # New: manual maps dir with *.man_map.yml (preferred)
    ap.add_argument("--man-maps-dir", required=False,
                    help="Root to search for *.man_map.yml files "
                         "(e.g. ./docs_managment_code/c-api_man_maps)")

    # Optional: debug a single map file directly
    ap.add_argument("--map-file",
                    help="Process a single map file (auto or manual map) instead of walking trees")

    ap.add_argument("--out-root", default="c-api_appended_metadata",
                    help="Root where updated C headers will be written")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--dry-run", action="store_true")

    args = ap.parse_args()

    capi_root = Path(args.capi_root).resolve()
    cpp_meta_root = Path(args.cpp_metadata_root).resolve()
    out_root = Path(args.out_root).resolve()

    # Resolve manual maps dir preference: new flag wins, old is fallback.
    man_maps_dir = args.man_maps_dir or args.user_maps_dir

    # Single-file debugging mode
    if args.map_file:
        process_map(
            Path(args.map_file),
            capi_root,
            cpp_meta_root,
            out_root,
            verbose=args.verbose,
            dry_run=args.dry_run,
        )
        return

    processed = 0

    # 1) Auto maps
    if args.maps_dir:
        maps_dir = Path(args.maps_dir).resolve()
        for mf in maps_dir.rglob("*.auto_map.yml"):
            process_map(
                mf,
                capi_root,
                cpp_meta_root,
                out_root,
                verbose=args.verbose,
                dry_run=args.dry_run,
            )
            processed += 1

    # 2) Manual maps (formerly "user" maps)
    if man_maps_dir:
        man_dir = Path(man_maps_dir).resolve()
        # Support both new *.man_map.yml and legacy *.user_map.yml
        for pattern in ("*.man_map.yml", "*.user_map.yml"):
            for mf in man_dir.rglob(pattern):
                process_map(
                    mf,
                    capi_root,
                    cpp_meta_root,
                    out_root,
                    verbose=args.verbose,
                    dry_run=args.dry_run,
                )
                processed += 1

    if processed == 0:
        print(
            f"[warn] no map files found. "
            f"auto maps root='{args.maps_dir}', manual maps root='{man_maps_dir}'",
            file=sys.stderr,
        )


if __name__ == "__main__":
    main()
