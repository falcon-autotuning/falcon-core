#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
doxygen_port_coverage.py

Compute:
  1) Local C header documentation coverage (same logic as the old script).
  2) Port coverage: of all C++ functions with Doxygen docs (from cpp_metadata),
     how many have at least one mapping into the C API via *_c_api.map.yml.

Output format matches the old script.
"""

from __future__ import annotations
import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Set, Any
import yaml

# ============================================================
#  Old header-scanning logic (from doxygen_coverage / .bak)
# ============================================================

# class / struct definition (ignore forward declarations with trailing ';')
CLASS_DEF_RE = re.compile(r'^\s*(class|struct)\s+([A-Za-z_]\w*)\b(?![^;]*;)')

# function or prototype (heuristic)
FUNC_DEF_RE = re.compile(
    r'''^
        \s*
        (?:template\s*<[^>]+>\s*)*            # optional template
        (?:inline\s+|static\s+|virtual\s+)*   # optional specifiers
        [A-Za-z_~][\w:\s<>\*&,\[\]]*          # return type-ish (includes dtor)
        \s+
        ([A-Za-z_]\w*)                        # function name (captured)
        \s*
        \(
            [^;]*                             # args (rough)
        \)
        \s*
        (?:const\s*)?
        (?:=\s*0\s*)?                         # pure virtual
        (?:;|{|throw\b|noexcept\b)           # end of decl or start of body
    ''',
    re.VERBOSE,
)

# Doxygen block comment start and end
DOXY_BLOCK_START_RE = re.compile(r"/\*\*")
DOXY_BLOCK_END_RE = re.compile(r"\*/")

# Single-line Doxygen comment: /// or //!
DOXY_LINE_RE = re.compile(r"\s*(///|//!)(?!<)")


@dataclass
class FileStats:
    path: Path
    classes: int = 0
    classes_doc: int = 0
    funcs: int = 0
    funcs_doc: int = 0


def is_header_file(path: Path) -> bool:
    return path.suffix.lower() in {".h", ".hpp", ".hh", ".hxx"}


def analyze_file(path: Path) -> FileStats:
    """
    Analyze a single header file. Same logic as in your original script.
    """
    text = path.read_text(encoding="utf-8", errors="ignore")
    lines = text.splitlines()
    stats = FileStats(path=path)

    in_block = False
    doc_pending = False  # True if the *next* declaration should be considered documented

    for line in lines:
        stripped = line.strip()

        # --- Handle block Doxygen comments: /** ... */
        if not in_block and DOXY_BLOCK_START_RE.search(line):
            in_block = True
            continue

        if in_block:
            if DOXY_BLOCK_END_RE.search(line):
                in_block = False
                doc_pending = True
            continue

        # --- Handle single-line Doxygen comments: /// or //!
        if DOXY_LINE_RE.match(line):
            doc_pending = True
            continue

        # Ignore preprocessor and empty lines (do not clear doc_pending)
        if not stripped or stripped.startswith("#"):
            continue

        # Skip obvious non-top-level constructs
        if re.match(r"\s*(if|for|while|switch|else|return|typedef|using)\b", stripped):
            doc_pending = False
            continue

        # --- Class / struct definition
        m_class = CLASS_DEF_RE.match(line)
        if m_class:
            stats.classes += 1
            if doc_pending:
                stats.classes_doc += 1
            doc_pending = False
            continue

        # --- Function / prototype declaration
        m_func = FUNC_DEF_RE.match(line)
        if m_func:
            stats.funcs += 1
            if doc_pending:
                stats.funcs_doc += 1
            doc_pending = False
            continue

        # Any other non-empty, non-pp line clears pending doc
        doc_pending = False

    return stats


def walk_headers(root: Path) -> List[Path]:
    """
    Return a sorted list of header files under 'root'.
    """
    files: List[Path] = []
    if root.is_file():
        if is_header_file(root):
            files.append(root)
        return files

    for p in root.rglob("*"):
        if p.is_file() and is_header_file(p):
            files.append(p)
    return sorted(files)


def summarize_dir(root: Path) -> tuple[int, int]:
    """
    Return (total_funcs, funcs_with_docs) for all headers under 'root'.
    """
    headers = walk_headers(root)
    total_funcs = 0
    funcs_doc = 0

    for h in headers:
        stats = analyze_file(h)
        total_funcs += stats.funcs
        funcs_doc += stats.funcs_doc

    return total_funcs, funcs_doc


# ============================================================
#  New bits: metadata + map-based port coverage
# ============================================================

def load_yaml(path: Path) -> Any:
    try:
        return yaml.safe_load(path.read_text(encoding="utf-8", errors="ignore"))
    except Exception:
        return None


def find_cpp_functions(meta_root: Path) -> tuple[Set[str], Set[str]]:
    """
    Return:
      - cpp_doc_funcs: set of documented C++ function names
      - cpp_all_funcs: set of all C++ function names in metadata
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
    Gather all C++ function names that appear in any *_c_api.map.yml mapping.
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
    ap = argparse.ArgumentParser(
        description="Compute C header Doxygen coverage and C++→C port coverage."
    )
    ap.add_argument(
        "--cpp-metadata-root",
        type=Path,
        required=True,
        help="Root of cpp_metadata tree (e.g. ./cpp_metadata).",
    )
    ap.add_argument(
        "--c-root",
        type=Path,
        required=True,
        help="Root of C API headers (e.g. ./c-api/include).",
    )
    args = ap.parse_args()

    cpp_meta_root = args.cpp_metadata_root.resolve()
    c_root = args.c_root.resolve()

    # --- Local C coverage (same semantics as old script) ---
    c_total_funcs, c_funcs_doc = summarize_dir(c_root)
    c_pct = (100.0 * c_funcs_doc / c_total_funcs) if c_total_funcs else 0.0

    # --- C++ metadata: documented vs all ---
    cpp_doc_funcs, cpp_all_funcs = find_cpp_functions(cpp_meta_root)
    cpp_doc_count = len(cpp_doc_funcs)
    cpp_all_count = len(cpp_all_funcs)

    # --- Port coverage: unique documented C++ funcs that appear in any map ---
    ported = find_ported_cpp_functions(c_root)
    unique_ported = len(cpp_doc_funcs.intersection(ported))
    port_pct = (100.0 * unique_ported / cpp_doc_count) if cpp_doc_count else 0.0

    # --- Output (old style) ---
    print(f"C++ headers root: {cpp_meta_root}")
    print(f"C  headers root:  {c_root}")
    print()
    print("C header documentation coverage (local):")
    print(f"  Functions with Doxygen: {c_funcs_doc}/{c_total_funcs} ({c_pct:.1f}%)")
    print()
    print("Port coverage (C docs vs C++ docs):")
    print(f"  C++ functions with Doxygen: {cpp_doc_count} (out of {cpp_all_count} total)")
    print(f"  Ported docs (C):           {unique_ported}/{cpp_doc_count} ({port_pct:.1f}%)")


if __name__ == "__main__":
    main()
