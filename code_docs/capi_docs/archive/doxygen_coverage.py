#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
doxygen_coverage.py

Compute approximate "coverage" of Doxygen comments over classes and functions
for C/C++ headers.

- Scans one or more directories recursively
- Looks for files with extensions: .h, .hpp, .hh, .hxx
- Detects:
    * class / struct definitions
    * function / method / prototype declarations
- Checks whether each declaration is directly preceded by a Doxygen-style
  comment (/** ... */, ///, or //!).
- Reports per-file and overall coverage.

Usage:
    python3 doxygen_coverage.py ./cpp/include
    python3 doxygen_coverage.py ./cpp/include ./c-api/include

This is heuristic (regex-based), but works well for "comment immediately above
declaration" patterns like in the codebase.
"""

from __future__ import annotations
import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Tuple, Dict


# --- Regexes for declarations ------------------------------------------------

# class / struct definition (ignore forward declarations with trailing ';')
CLASS_DEF_RE = re.compile(r'^\s*(class|struct)\s+([A-Za-z_]\w*)\b(?![^;]*;)')

# function or prototype (very heuristic)
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
    text = path.read_text(encoding="utf-8", errors="ignore")
    lines = text.splitlines()
    stats = FileStats(path=path)

    in_block = False
    doc_pending = False  # True if the *next* declaration should be considered documented

    for i, line in enumerate(lines):
        stripped = line.strip()

        # --- Handle block Doxygen comments: /** ... */
        if not in_block and DOXY_BLOCK_START_RE.search(line):
            in_block = True
            # We will set doc_pending when we see the end of the block.
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

        # Heuristically skip lines that are obviously not top-level decls
        # e.g. else, if, for, while, etc.
        if re.match(r'\s*(if|for|while|switch|else|return|typedef|using)\b', stripped):
            # Non-declaration code line resets pending docs
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


def walk_dirs(roots: List[Path]) -> List[Path]:
    files: List[Path] = []
    for root in roots:
        if root.is_file():
            if is_header_file(root):
                files.append(root)
            continue
        for p in root.rglob("*"):
            if p.is_file() and is_header_file(p):
                files.append(p)
    return sorted(files)


def main():
    ap = argparse.ArgumentParser(description="Compute Doxygen coverage for C/C++ headers.")
    ap.add_argument(
        "paths",
        nargs="+",
        help="One or more header files or directories (will be scanned recursively).",
    )
    ap.add_argument(
        "--per-file",
        action="store_true",
        help="Print per-file coverage (not just totals).",
    )
    args = ap.parse_args()

    roots = [Path(p).resolve() for p in args.paths]
    files = walk_dirs(roots)

    if not files:
        print("No header files found under:", ", ".join(str(r) for r in roots))
        return

    all_stats: List[FileStats] = []
    for f in files:
        stats = analyze_file(f)
        all_stats.append(stats)

    # Overall totals
    total_classes = sum(s.classes for s in all_stats)
    total_classes_doc = sum(s.classes_doc for s in all_stats)
    total_funcs = sum(s.funcs for s in all_stats)
    total_funcs_doc = sum(s.funcs_doc for s in all_stats)

    if args.per_file:
        print("Per-file coverage:\n")
        for s in all_stats:
            if s.classes == 0 and s.funcs == 0:
                continue
            c_cov = (100.0 * s.classes_doc / s.classes) if s.classes else 0.0
            f_cov = (100.0 * s.funcs_doc / s.funcs) if s.funcs else 0.0
            print(f"{s.path}:")
            print(f"  classes: {s.classes_doc}/{s.classes} ({c_cov:.1f}%)")
            print(f"  funcs:   {s.funcs_doc}/{s.funcs} ({f_cov:.1f}%)")
            print()

    print("Overall coverage:\n")
    if total_classes:
        print(
            f"  Classes: {total_classes_doc}/{total_classes} "
            f"({100.0 * total_classes_doc / total_classes:.1f}%)"
        )
    else:
        print("  Classes: 0")

    if total_funcs:
        print(
            f"  Functions: {total_funcs_doc}/{total_funcs} "
            f"({100.0 * total_funcs_doc / total_funcs:.1f}%)"
        )
    else:
        print("  Functions: 0")


if __name__ == "__main__":
    main()
