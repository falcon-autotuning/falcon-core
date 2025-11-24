#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
doxygen_port_coverage.py  (with detailed logs)

Logs written:
    cpp_scanned_doc_functions.log      - doc'd functions from header scanning
    cpp_metadata_doc_functions.log     - doc'd functions from metadata
    cpp_ported_functions.log           - C++ functions mapped in *_c_api.map.yml
    cpp_left_to_port_functions.log     - header-doc'd function names with no port
"""

from __future__ import annotations
import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Set, Any
import yaml

# ============================================================
#  Header-scanning logic (same as before)
# ============================================================

CLASS_DEF_RE = re.compile(r'^\s*(class|struct)\s+([A-Za-z_]\w*)\b(?![^;]*;)')

FUNC_DEF_RE = re.compile(
    r'''^
        \s*
        (?:template\s*<[^>]+>\s*)*           
        (?:inline\s+|static\s+|virtual\s+)*  
        [A-Za-z_~][\w:\s<>\*&,\[\]]*         
        \s+
        ([A-Za-z_]\w*)                       
        \s*
        \(
            [^;]*                            
        \)
        \s*
        (?:const\s*)?
        (?:=\s*0\s*)?                        
        (?:;|{|throw\b|noexcept\b)           
        \s*$
    ''',
    re.VERBOSE,
)

DOXY_LINE_RE = re.compile(r'^\s*(///|//!)')
DOXY_BLOCK_START_RE = re.compile(r'/\*\*')
DOXY_BLOCK_END_RE = re.compile(r'\*/')


@dataclass
class FileStats:
    path: Path
    classes: int = 0
    classes_doc: int = 0
    funcs: int = 0
    funcs_doc: int = 0
    func_names: List[str] = None
    func_names_doc: List[str] = None


def is_header_file(path: Path) -> bool:
    return path.suffix.lower() in {".h", ".hpp", ".hh", ".hxx"}


def analyze_file(path: Path) -> FileStats:
    text = path.read_text(encoding="utf-8", errors="ignore")
    lines = text.splitlines()
    stats = FileStats(path=path, func_names=[], func_names_doc=[])

    in_block = False
    doc_pending = False

    for line in lines:
        stripped = line.strip()

        # Block /** ... */
        if not in_block and DOXY_BLOCK_START_RE.search(line):
            in_block = True
            continue

        if in_block:
            if DOXY_BLOCK_END_RE.search(line):
                in_block = False
                doc_pending = True
            continue

        # Single-line Doxygen /// or //!
        if DOXY_LINE_RE.match(line):
            doc_pending = True
            continue

        if not stripped or stripped.startswith("#"):
            continue

        if re.match(r'\s*(if|for|while|switch|else|return|typedef|using)\b', stripped):
            doc_pending = False
            continue

        m_class = CLASS_DEF_RE.match(line)
        if m_class:
            # we don't count classes in this script, only functions
            doc_pending = False
            continue

        m_func = FUNC_DEF_RE.match(line)
        if m_func:
            fn = m_func.group(1)
            stats.func_names.append(fn)
            stats.funcs += 1
            if doc_pending:
                stats.func_names_doc.append(fn)
                stats.funcs_doc += 1
            doc_pending = False
            continue

        doc_pending = False

    return stats


def walk_headers(root: Path) -> List[Path]:
    if root.is_file():
        return [root] if is_header_file(root) else []
    files: List[Path] = []
    for p in root.rglob("*"):
        if p.is_file() and is_header_file(p):
            files.append(p)
    return sorted(files)


def summarize_dir_collect(root: Path) -> tuple[int, int, Set[str], Set[str]]:
    """
    Returns:
        total_funcs,
        funcs_with_docs,
        set_of_all_function_names,
        set_of_all_doc_function_names
    """
    headers = walk_headers(root)
    total = 0
    doc = 0
    names_all: Set[str] = set()
    names_doc: Set[str] = set()

    for h in headers:
        st = analyze_file(h)
        total += st.funcs
        doc += st.funcs_doc
        names_all.update(st.func_names)
        names_doc.update(st.func_names_doc)

    return total, doc, names_all, names_doc


# ============================================================
#  Metadata + mapping logic
# ============================================================

def load_yaml(path: Path) -> Any:
    try:
        return yaml.safe_load(path.read_text(encoding="utf-8", errors="ignore"))
    except Exception:
        return None


def find_cpp_functions_in_metadata(meta_root: Path) -> tuple[Set[str], Set[str]]:
    """
    From cpp_metadata, collect:
      - documented C++ function names (fully qualified)
      - all C++ function names present in metadata (fully qualified)
    """
    doc_funcs: Set[str] = set()
    all_funcs: Set[str] = set()

    for yml in meta_root.rglob("*_metadata.yml"):
        data = load_yaml(yml)
        if not isinstance(data, list):
            continue
        for item in data:
            if not isinstance(item, dict):
                continue
            if item.get("kind") != "function":
                continue
            name = item.get("name")
            if not name:
                continue
            all_funcs.add(name)
            if item.get("comment") or item.get("comment_raw"):
                doc_funcs.add(name)

    return doc_funcs, all_funcs


def find_ported_cpp_functions(c_api_root: Path) -> Set[str]:
    """
    Gather all C++ function names (fully qualified) that appear
    in any *_c_api.map.yml 'cpp' field.
    """
    ported: Set[str] = set()

    for yml in c_api_root.rglob("*_c_api.map.yml"):
        data = load_yaml(yml)
        if not isinstance(data, dict):
            continue
        mappings = data.get("mappings", [])
        if not isinstance(mappings, list):
            continue
        for m in mappings:
            if not isinstance(m, dict):
                continue
            cpp_name = m.get("cpp")
            if cpp_name:
                ported.add(cpp_name)

    return ported


# ============================================================
#  Main
# ============================================================

def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--cpp-root", required=True, type=Path,
                    help="Root of C++ headers (e.g. ./cpp/include).")
    ap.add_argument("--cpp-metadata-root", required=True, type=Path,
                    help="Root of cpp_metadata (e.g. ./cpp_metadata).")
    ap.add_argument("--c-root", required=True, type=Path,
                    help="Root of C API headers (e.g. ./c-api/include).")
    args = ap.parse_args()

    cpp_root = args.cpp_root.resolve()
    cpp_meta_root = args.cpp_metadata_root.resolve()
    c_root = args.c_root.resolve()

    # --- Scan C headers (local coverage) ---
    c_total, c_doc, _, _ = summarize_dir_collect(c_root)
    c_pct = (100.0 * c_doc / c_total) if c_total else 0.0

    # --- Scan C++ headers directly (authoritative for header coverage) ---
    cpp_total, cpp_doc, cpp_names_all, cpp_names_doc = summarize_dir_collect(cpp_root)

    # --- Metadata-based universe (for port mapping) ---
    cpp_doc_meta, cpp_all_meta = find_cpp_functions_in_metadata(cpp_meta_root)

    # --- Ported functions (fully qualified names) ---
    cpp_ported = find_ported_cpp_functions(c_root)

    # ============================================================
    #  Logs
    # ============================================================

    def write_list(path: Path, items: Set[str], title: str):
        with path.open("w", encoding="utf-8") as f:
            f.write(f"# {title}\n")
            for x in sorted(items):
                f.write(x + "\n")

    # 1) doc'd functions from header scan (simple names)
    write_list(
        Path("cpp_scanned_doc_functions.log"),
        cpp_names_doc,
        "C++ SCANNED (header) functions with Doxygen (simple names)",
    )

    # 2) doc'd functions from metadata (fully qualified names)
    write_list(
        Path("cpp_metadata_doc_functions.log"),
        cpp_doc_meta,
        "C++ METADATA extracted functions with Doxygen (fully qualified)",
    )

    # 3) ported functions from map.yml (fully qualified names)
    write_list(
        Path("cpp_ported_functions.log"),
        cpp_ported,
        "C++ functions mapped to C API (fully qualified)",
    )

    # 4) functions left to port (based on header scan, by simple name)
    #    We reduce mapped cpp names to their simple name (last :: segment)
    ported_simple_names: Set[str] = set()
    for fq in cpp_ported:
        if "::" in fq:
            simple = fq.rsplit("::", 1)[-1]
        else:
            # fallback: last token by non-alnum boundary
            m = re.search(r'([A-Za-z_]\w*)$', fq)
            simple = m.group(1) if m else fq
        ported_simple_names.add(simple)

    left_to_port = cpp_names_doc - ported_simple_names

    write_list(
        Path("cpp_left_to_port_functions.log"),
        left_to_port,
        "C++ header-scanned doc functions (simple names) with NO mapped C API function",
    )

    # ============================================================
    #  Port coverage (still using metadata universe)
    # ============================================================

    # Use metadata doc set intersected with mapped set (fully qualified)
    ported_intersection = {x for x in cpp_doc_meta if x in cpp_ported}
    # Denominator: number of doc'd C++ functions as seen from header scan
    # (what you care about as ground truth)
    port_pct = (100.0 * len(ported_intersection) / cpp_doc) if cpp_doc else 0.0

    # ============================================================
    #  Output summary
    # ============================================================

    print(f"C++ headers root: {cpp_root}")
    print(f"C  headers root:  {c_root}")
    print()
    print("C header documentation coverage (local):")
    print(f"  Functions with Doxygen: {c_doc}/{c_total} ({c_pct:.1f}%)")
    print()
    print("C++ header documentation coverage (local, scanned):")
    print(f"  Functions with Doxygen: {cpp_doc}/{cpp_total}")
    print()
    print("Port coverage (C docs vs C++ docs):")
    print(f"  C++ functions with Doxygen (metadata): {len(cpp_doc_meta)}")
    print(f"  Ported docs (C):           {len(ported_intersection)}/{cpp_doc} ({port_pct:.1f}%)")
    print()
    print("Logs written:")
    print("  - cpp_scanned_doc_functions.log")
    print("  - cpp_metadata_doc_functions.log")
    print("  - cpp_ported_functions.log")
    print("  - cpp_left_to_port_functions.log")


if __name__ == "__main__":
    main()
