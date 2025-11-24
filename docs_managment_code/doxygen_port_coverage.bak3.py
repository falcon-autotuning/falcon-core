#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
doxygen_port_coverage.py  (using extract_cpp_docs for C++ doc functions)

What this script does:

1) C header documentation coverage (local, direct scan of c-api/include):
   - Counts total functions & how many have attached Doxygen comments
     (/** ... */ or triple-slash), using the old regex-based logic.

2) C++ header documentation coverage (local, scanned FROM HEADERS):
   - Uses extract_cpp_docs.walk_and_extract to find all documented
     declarations in cpp/include.
   - Collects fully-qualified function names (namespace + class + method).
   - The "Functions with Doxygen" count for C++ is based on THIS,
     not on metadata, so it reflects the headers directly.

3) Port coverage (C docs vs C++ docs):
   - Loads all C++ doc’d functions from headers (fully qualified).
   - Loads all ported C++ functions from *_c_api.map.yml (fully qualified).
   - Port coverage = |ported ∩ doc_from_headers| / |doc_from_headers|.

4) Logs:
   - cpp_scanned_doc_functions.log
       → fully-qualified C++ function names with Doxygen (from headers)
   - cpp_metadata_doc_functions.log
       → fully-qualified C++ function names with Doxygen (from metadata)
   - cpp_ported_functions.log
       → fully-qualified C++ function names mapped to C (from map.yml)
   - cpp_left_to_port_functions.log
       → fully-qualified C++ functions with Doxygen (from headers)
         that do NOT appear in any map.yml (left to port)
"""

from __future__ import annotations
import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Set, Any, Dict
import yaml

# Import your extractor logic (must be on PYTHONPATH / same dir)
from extract_cpp_docs import walk_and_extract  # type: ignore


# ============================================================
#  C/C++ header scanning logic for total function counts
#  (same style as your original coverage script)
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
        set_of_all_function_names (simple),
        set_of_doc_function_names (simple)
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


def find_cpp_functions_in_metadata(meta_root: Path) -> Set[str]:
    """
    From cpp_metadata, collect documented C++ function names (fully qualified).
    """
    doc_funcs: Set[str] = set()

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
            # Treat all function entries as documented (metadata only created when docs exist)
            doc_funcs.add(name)

    return doc_funcs


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


def get_cpp_doc_functions_from_headers(cpp_root: Path) -> Set[str]:
    """
    Use extract_cpp_docs.walk_and_extract to find all documented
    function declarations in cpp_root, with FULLY QUALIFIED names.

    This uses the exact same logic that produces cpp_metadata. :contentReference[oaicite:1]{index=1}
    """
    results: Dict[str, List[Dict[str, Any]]] = walk_and_extract([cpp_root])
    doc_funcs_full: Set[str] = set()

    for units in results.values():
        for u in units:
            if u.get("kind") != "function":
                continue
            name = u.get("name")
            if not name:
                continue
            doc_funcs_full.add(name)

    return doc_funcs_full


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

    # --- Total number of C++ functions (for reference) ---
    cpp_total, _, _, _ = summarize_dir_collect(cpp_root)

    # --- C++ doc functions from HEADERS using extractor (fully qualified) ---
    cpp_doc_from_headers: Set[str] = get_cpp_doc_functions_from_headers(cpp_root)
    cpp_doc_count = len(cpp_doc_from_headers)

    # --- C++ doc functions from METADATA (fully qualified) ---
    cpp_doc_meta: Set[str] = find_cpp_functions_in_metadata(cpp_meta_root)

    # --- Ported functions (fully qualified) ---
    cpp_ported: Set[str] = find_ported_cpp_functions(c_root)

    # ============================================================
    #  Logs
    # ============================================================

    def write_list(path: Path, items: Set[str], title: str):
        with path.open("w", encoding="utf-8") as f:
            f.write(f"# {title}\n")
            for x in sorted(items):
                f.write(x + "\n")

    # 1) doc'd functions from header scan (fully qualified)
    write_list(
        Path("cpp_scanned_doc_functions.log"),
        cpp_doc_from_headers,
        "C++ SCANNED (from headers, via extract_cpp_docs) functions with Doxygen (fully qualified)",
    )

    # 2) doc'd functions from metadata (fully qualified)
    write_list(
        Path("cpp_metadata_doc_functions.log"),
        cpp_doc_meta,
        "C++ METADATA extracted functions with Doxygen (fully qualified)",
    )

    # 3) ported functions from map.yml (fully qualified)
    write_list(
        Path("cpp_ported_functions.log"),
        cpp_ported,
        "C++ functions mapped to C API (fully qualified)",
    )

    # 4) functions left to port (fully qualified)
    left_to_port_full = cpp_doc_from_headers - cpp_ported
    write_list(
        Path("cpp_left_to_port_functions.log"),
        left_to_port_full,
        "C++ header-scanned doc functions (fully qualified) with NO mapped C API function",
    )

    # ============================================================
    #  Port coverage (using header-based doc count)
    # ============================================================

    # --- Scan C++ headers directly (authoritative for header coverage) ---
    cpp_total, cpp_doc, cpp_names_all, cpp_names_doc = summarize_dir_collect(cpp_root)

    ported_from_headers = cpp_doc_from_headers & cpp_ported
    port_pct = (100.0 * len(ported_from_headers) / cpp_doc) if cpp_doc_count else 0.0
    

    # ============================================================
    #  Output summary
    # ============================================================

    print(f"C++ headers root: {cpp_root}")
    print(f"C  headers root:  {c_root}")
    print()
    print("C header documentation coverage (local):")
    print(f"  Functions with Doxygen: {c_doc}/{c_total} ({c_pct:.1f}%)")
    print()
    print("C++ header documentation coverage (local, scanned via extract_cpp_docs):")
    print(f"  Functions with Doxygen: {cpp_doc}/{cpp_total}")
    print()
    print("Port coverage (C docs vs C++ docs):")
    print(f"  C++ functions with Doxygen (from headers): {cpp_doc_count}")
    print(f"  Ported docs (C):           {len(ported_from_headers)}/{cpp_doc} ({port_pct:.1f}%)")
    print()
    print("Logs written:")
    print("  - cpp_scanned_doc_functions.log")
    print("  - cpp_metadata_doc_functions.log")
    print("  - cpp_ported_functions.log")
    print("  - cpp_left_to_port_functions.log")


if __name__ == "__main__":
    main()
