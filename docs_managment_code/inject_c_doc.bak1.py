#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
inject_c_docs.py (verbose, robust)

- Reads *.map.yml files from a C API tree
- Loads C++ doc units from cpp_metadata/*_metadata.yml
- Inserts Doxygen blocks above matched C prototypes
- Writes to mirrored c-api_appended_metadata tree (leaves originals untouched)

Improvements vs prior:
- --verbose and --dry-run flags
- Clear per-mapping logs: found doc? found prototype? inserted?
- More permissive prototype regex (tolerates macros/attributes before return type)
"""

from __future__ import annotations
import argparse
import re
import sys
from pathlib import Path
from typing import Dict, List, Any, Optional, Tuple

try:
    import yaml  # PyYAML
except Exception:
    print("ERROR: PyYAML is required. Install with: python3 -m pip install pyyaml", file=sys.stderr)
    raise

AUTO_MARK = "/* AUTO-DOC from cpp:"

def read_text(p: Path) -> str:
    return p.read_text(encoding="utf-8", errors="ignore")

def write_text(p: Path, s: str) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(s, encoding="utf-8")

def load_yaml(p: Path):
    return yaml.safe_load(p.read_text(encoding="utf-8"))

def cpp_header_to_metadata_path(cpp_header: Path, cpp_root: Path, cpp_meta_root: Path) -> Path:
    cpp_header = cpp_header.resolve()
    try:
        rel = cpp_header.relative_to(cpp_root.resolve())
    except Exception:
        parts = list(cpp_header.parts)
        if "cpp" in parts:
            i = parts.index("cpp")
            parts[i] = cpp_meta_root.name
            base = Path(*parts)
            return base.with_name(cpp_header.stem + "_metadata.yml")
        return cpp_header.with_name(cpp_header.stem + "_metadata.yml")
    meta_path = cpp_meta_root.resolve() / rel
    return meta_path.with_name(cpp_header.stem + "_metadata.yml")

def collect_metadata_units(meta_files: List[Path], verbose: bool=False) -> List[Dict[str, Any]]:
    units: List[Dict[str, Any]] = []
    for p in meta_files:
        if not p.exists():
            if verbose:
                print(f"[meta] missing: {p}")
            continue
        data = load_yaml(p)
        if isinstance(data, list):
            units.extend(data)
            if verbose:
                print(f"[meta] loaded {len(data)} units from {p}")
        elif isinstance(data, dict):
            count = 0
            for v in data.values():
                if isinstance(v, list):
                    units.extend(v); count += len(v)
            if verbose:
                print(f"[meta] loaded {count} units from {p}")
    if verbose:
        print(f"[meta] total units: {len(units)}")
    return units

def find_cpp_doc(units: List[Dict[str, Any]], cpp_key: str, verbose: bool=False) -> Optional[Tuple[str, Dict[str, Any], str]]:
    """
    Returns (comment_text, unit, matched_by) or None.
    matched_by ∈ {'name', 'decl', 'regex'}
    """
    if cpp_key.startswith("re:"):
        pat = re.compile(cpp_key[3:])
        for u in units:
            nm = u.get("name") or ""
            dc = u.get("declaration") or ""
            if (nm and pat.search(nm)) or (dc and pat.search(dc)):
                cm = (u.get("comment") or "").strip()
                if cm:
                    if verbose:
                        print(f"[map] cpp regex matched: name='{nm}' decl='{dc[:80]}...'")
                    return cm, u, "regex"
        if verbose:
            print(f"[map] cpp regex found no match: {cpp_key}")
        return None

    # exact name
    for u in units:
        if (u.get("name") or "") == cpp_key:
            cm = (u.get("comment") or "").strip()
            if cm:
                if verbose:
                    print(f"[map] cpp exact name matched: {cpp_key}")
                return cm, u, "name"

    # exact decl
    for u in units:
        if (u.get("declaration") or "") == cpp_key:
            cm = (u.get("comment") or "").strip()
            if cm:
                if verbose:
                    print(f"[map] cpp exact decl matched: {cpp_key}")
                return cm, u, "decl"

    if verbose:
        print(f"[map] cpp key found no doc: {cpp_key}")
    return None

def build_auto_block(c_func: str, cpp_key: str, comment_text: str) -> str:
    lines = []
    lines.append(f"{AUTO_MARK} {c_func} | {cpp_key} */")
    lines.append("/**")
    lines.append(f" * @brief (from C++: {cpp_key})")
    for ln in comment_text.splitlines():
        ln = ln.rstrip()
        lines.append(f" * {ln}" if ln else " *")
    lines.append(" */")
    return "\n".join(lines) + "\n"

def already_has_block_before(text: str, line_idx: int, c_func: str) -> bool:
    start = max(0, line_idx - 30)
    near = text.splitlines()[start:line_idx]
    near_text = "\n".join(near)
    return (AUTO_MARK in near_text) and (c_func in near_text)

def insert_block_above_prototype(header_text: str, c_func: str, block: str, verbose: bool=False) -> Tuple[str, bool]:
    """
    Return (new_text, inserted_bool).
    Prototype regex is permissive: allows macros/attributes before return type.
    """
    proto_rx = re.compile(
        rf'(^[ \t]*[^\n;]*?\b{re.escape(c_func)}\s*\([^;]*\)\s*;)',
        re.MULTILINE | re.DOTALL
    )
    m = proto_rx.search(header_text)
    if not m:
        if verbose:
            print(f"[capi] prototype not found: {c_func}")
        return header_text, False

    start_line = header_text[:m.start()].count("\n")
    if already_has_block_before(header_text, start_line, c_func):
        if verbose:
            print(f"[capi] doc already present: {c_func}")
        return header_text, False

    new_text = header_text[:m.start()] + block + header_text[m.start():]
    if verbose:
        print(f"[capi] inserted doc above: {c_func}")
    return new_text, True

def mirror_capi_path(capi_header: Path, capi_root: Path, out_root: Path) -> Path:
    rel = capi_header.resolve().relative_to(capi_root.resolve())
    return (out_root.resolve() / rel).with_suffix(capi_header.suffix)

def process_map(
    map_file: Path,
    capi_root: Path,
    cpp_root: Path,
    cpp_meta_root: Path,
    out_root: Path,
    *, verbose: bool=False, dry_run: bool=False
) -> Optional[Path]:
    cfg = load_yaml(map_file)
    c_header_rel = Path(cfg.get("c_header", "")).name
    if not c_header_rel:
        print(f"[warn] {map_file}: no c_header", file=sys.stderr)
        return None

    # locate C header
    c_header_path: Optional[Path] = None
    cand = (map_file.parent / c_header_rel)
    if cand.exists():
        c_header_path = cand.resolve()
    else:
        for p in (capi_root / "include").rglob(c_header_rel):
            c_header_path = p.resolve(); break
    if not c_header_path or not c_header_path.exists():
        print(f"[warn] C header not found for {map_file}: {c_header_rel}", file=sys.stderr)
        return None

    if verbose:
        print(f"[map] using C header: {c_header_path}")

    # metadata files from cpp_headers (robust to ../../../ escaping)
    meta_files: List[Path] = []

    def _tail_after_cpp(p: Path) -> Optional[Path]:
        """Return the subpath after the 'cpp' segment, if present."""
        parts = list(p.parts)
        if "cpp" in parts:
            i = parts.index("cpp")
            return Path(*parts[i+1:]) if i+1 < len(parts) else Path()
        return None

    for ch in cfg.get("cpp_headers", []) or []:
        p_rel = Path(ch)

        # 1) Absolute path? use as-is
        if p_rel.is_absolute():
            cpp_h = p_rel.resolve()
            if verbose:
                print(f"[meta] cpp_headers abs -> {cpp_h}")

        else:
            # 2) Try relative to the map file directory
            cand1 = (map_file.parent / p_rel).resolve()
            if cand1.exists():
                cpp_h = cand1
                if verbose:
                    print(f"[meta] cpp_headers map-dir -> {cpp_h}")
            else:
                # 3) Anchor under cpp_root using only the tail after the 'cpp' segment
                tail = _tail_after_cpp(p_rel) or p_rel
                cpp_h = (cpp_root / tail).resolve()
                if verbose:
                    print(f"[meta] cpp_headers cpp-root+tail -> {cpp_h}")

        mf = cpp_header_to_metadata_path(cpp_h, cpp_root, cpp_meta_root)
        if verbose:
            print(f"[meta] will use: {mf}")
        meta_files.append(mf)
    if verbose:
        for mf in meta_files:
            print(f"[meta] will use: {mf}")

    units = collect_metadata_units(meta_files, verbose=verbose)
    header_text = read_text(c_header_path)

    inserted_count = 0
    for m in cfg.get("mappings", []):
        cpp_key = m.get("cpp")
        c_func  = m.get("c")
        if not cpp_key or not c_func:
            continue

        found = find_cpp_doc(units, cpp_key, verbose=verbose)
        if not found:
            continue
        comment_text, unit, matched_by = found
        block = build_auto_block(c_func, cpp_key, comment_text)
        header_text, did = insert_block_above_prototype(header_text, c_func, block, verbose=verbose)
        if did:
            inserted_count += 1

    out_path = mirror_capi_path(c_header_path, capi_root, out_root)
    if dry_run:
        print(f"[dry-run] would write {out_path} (inserted={inserted_count})")
        return out_path

    write_text(out_path, header_text)
    print(f"Wrote {out_path} (inserted={inserted_count})")
    return out_path

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--capi-root", default="c-api")
    ap.add_argument("--cpp-root", default="cpp")
    ap.add_argument("--cpp-metadata-root", default="cpp_metadata")
    ap.add_argument("--maps-dir", default="c-api/include/falcon_core")
    ap.add_argument("--map-file")
    ap.add_argument("--out-root", default="c-api_appended_metadata")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    capi_root = Path(args.capi_root).resolve()
    cpp_root = Path(args.cpp_root).resolve()
    cpp_meta_root = Path(args.cpp_metadata_root).resolve()
    out_root = Path(args.out_root).resolve()

    if args.map_file:
        process_map(Path(args.map_file).resolve(), capi_root, cpp_root, cpp_meta_root, out_root,
                    verbose=args.verbose, dry_run=args.dry_run)
        return

    maps_dir = Path(args.maps_dir).resolve()
    count = 0
    for mf in maps_dir.rglob("*.map.yml"):
        process_map(mf, capi_root, cpp_root, cpp_meta_root, out_root,
                    verbose=args.verbose, dry_run=args.dry_run)
        count += 1
    if count == 0:
        print(f"[warn] no *.map.yml found under {maps_dir}", file=sys.stderr)

if __name__ == "__main__":
    main()
