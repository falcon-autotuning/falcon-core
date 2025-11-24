#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
doxygen_port_coverage.py

Estimate "porting coverage" of Doxygen comments from C++ headers to C headers.

Given:
  --cpp-root   : directory of C++ headers (original docs)
  --c-root     : directory of C headers (where docs are being ported)

This script:
  1. Scans C++ headers under --cpp-root and counts:
       - total C++ functions
       - C++ functions with Doxygen comments
  2. Scans C headers under --c-root and counts:
       - total C functions
       - C functions with Doxygen comments
  3. Reports:
       - C header local coverage: C_doc / C_total
       - Port coverage:          C_doc / Cpp_doc

NOTES:
  - "Function" = any function / method / prototype that matches the same
    heuristic as in doxygen_coverage.py.
  - "Doxygen comment" = comment directly above the declaration, in one of:
        /** ... */
        /// ...
        //! ...

Usage:
    python3 doxygen_port_coverage.py \
        --cpp-root ./cpp/include \
        --c-root   ./c-api/include
"""

from __future__ import annotations
import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List


# --- Regexes for declarations (same as doxygen_coverage.py) ------------------

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
        \s*$
    ''',
    re.VERBOSE,
)

# Line-level Doxygen one-liners
DOXY_LINE_RE = re.compile(r'^\s*(///|//!)')

# Start/end of block Doxygen
DOXY_BLOCK_START_RE = re.compile(r'/\*\*')
DOXY_BLOCK_END_RE = re.compile(r'\*/')


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
    Analyze a single header file. Same logic as in doxygen_coverage.py.
    """
    text = path.read_text(encoding="utf-8", errors="ignore")
    lines = text.splitlines()
    stats = FileStats(path=path)

    in_block = False
    doc_pending = False  # True if the next decl should be considered documented

    for line in lines:
        stripped = line.strip()

        # --- Handle block Doxygen comments: /** ... */
        if not in_block and DOXY_BLOCK_START_RE.search(line):
            in_block = True
            # doc_pending will be set when we see the end of the block
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

        # Ignore preprocessor lines and empty lines (do not clear doc_pending)
        if not stripped or stripped.startswith("#"):
            continue

        # Skip obvious non-top-level decls
        if re.match(r'\s*(if|for|while|switch|else|return|typedef|using)\b', stripped):
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
    Recursively collect all header files under 'root'.
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


def main():
    ap = argparse.ArgumentParser(
        description="Compute Doxygen *porting* coverage from C++ headers to C headers."
    )
    ap.add_argument(
        "--cpp-root",
        required=True,
        type=Path,
        help="Root directory of C++ headers (source of Doxygen comments).",
    )
    ap.add_argument(
        "--c-root",
        required=True,
        type=Path,
        help="Root directory of C headers (destination of ported comments).",
    )
    args = ap.parse_args()

    cpp_root = args.cpp_root.resolve()
    c_root = args.c_root.resolve()

    # --- Summaries ---
    cpp_total_funcs, cpp_funcs_doc = summarize_dir(cpp_root)
    c_total_funcs, c_funcs_doc = summarize_dir(c_root)

    print(f"C++ headers root: {cpp_root}")
    print(f"C  headers root:  {c_root}")
    print()

    # 1) C-local coverage: how many C functions already have docs?
    print("C header documentation coverage (local):")
    if c_total_funcs:
        c_local_pct = 100.0 * c_funcs_doc / c_total_funcs
        print(f"  Functions with Doxygen: {c_funcs_doc}/{c_total_funcs} ({c_local_pct:.1f}%)")
    else:
        print("  No C functions found.")
    print()

    # 2) Port coverage: C-documented vs C++-documented
    print("Port coverage (C docs vs C++ docs):")
    print(f"  C++ functions with Doxygen: {cpp_funcs_doc} (out of {cpp_total_funcs} total)")
    if cpp_funcs_doc:
        port_pct = 100.0 * c_funcs_doc / cpp_funcs_doc
        print(
            f"  Ported docs (C):          {c_funcs_doc}/{cpp_funcs_doc} "
            f"({port_pct:.1f}%)"
        )
    else:
        print("  No documented functions found in C++ headers -> cannot compute port coverage.")


if __name__ == "__main__":
    main()
