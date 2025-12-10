#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
upgrade_doxygen_comments.py

Search recursively for C/C++ header files under a given root (e.g. ./cpp/include)
and upgrade comment blocks of the form

    /* ... */

to

    /** ... */

IF AND ONLY IF the block contains Doxygen-style tags such as @brief, @param,
@return, etc. This makes them proper Doxygen comments and allows tools (and your
extractor) to see them as documentation.

Usage:
    # Dry run (default): just report what would be changed
    python3 upgrade_doxygen_comments.py ./cpp/include

    # Actually modify files in place:
    python3 upgrade_doxygen_comments.py ./cpp/include --write

    # Show verbose info about each file:
    python3 upgrade_doxygen_comments.py ./cpp/include --write --verbose
"""

from __future__ import annotations
import argparse
import re
from pathlib import Path
from typing import Iterable, Tuple


# File extensions to treat as "header" files
HEADER_EXTS = {".h", ".hpp", ".hh", ".hxx"}

# Doxygen tags we treat as evidence that the block should be a doc comment
DOXYGEN_TAGS = (
    "@brief",
    "@param",
    "@tparam",
    "@return",
    "@retval",
    "@throws",
    "@exception",
    "@note",
    "@warning",
    "@deprecated",
    "@see",
    "@ingroup",
    "@since",
    "\\brief",
    "\\param",
    "\\tparam",
    "\\return",
    "\\retval",
    "\\throws",
    "\\exception",
    "\\note",
    "\\warning",
    "\\deprecated",
    "\\see",
    "\\ingroup",
    "\\since",
)

# Regex to find non-Doxygen block comments: /* ... */
# - Starts with '/*'
# - NOT followed by '*' or '!' (to avoid /** and /*! which are already Doxygen)
# - Non-greedy until the next '*/'
BLOCK_COMMENT_RE = re.compile(
    r"/\*(?![\*!])"      # '/*' but not '/**' or '/*!'
    r"(.*?)"            # comment body (group 1)
    r"\*/",             # closing
    re.DOTALL,
)


def find_header_files(root: Path) -> Iterable[Path]:
    """Yield all header-like files under root (recursively)."""
    if root.is_file():
        if root.suffix.lower() in HEADER_EXTS:
            yield root
        return

    for p in root.rglob("*"):
        if p.is_file() and p.suffix.lower() in HEADER_EXTS:
            yield p


def block_needs_upgrade(body: str) -> bool:
    """Return True if this comment body appears to be a Doxygen comment."""
    text = body.lower()
    return any(tag.lower() in text for tag in DOXYGEN_TAGS)


def upgrade_comments_in_text(text: str) -> Tuple[str, int]:
    """
    Upgrade '/* ... */' to '/** ... */' for any block that contains
    Doxygen tags. Return (new_text, num_changes).
    """

    def repl(match: re.Match) -> str:
        body = match.group(1)
        if block_needs_upgrade(body):
            # Replace the opening '/*' with '/**'
            # Original: '/*' + body + '*/'
            # New:      '/**' + body + '*/'
            return "/**" + body + "*/"
        else:
            # Leave unchanged
            return match.group(0)

    new_text, n_subs = BLOCK_COMMENT_RE.subn(repl, text)
    return new_text, n_subs


def process_file(path: Path, write: bool = False, verbose: bool = False) -> int:
    """Process a single file. Return number of comment blocks upgraded."""
    original = path.read_text(encoding="utf-8", errors="ignore")
    upgraded, n_changed = upgrade_comments_in_text(original)

    if n_changed and verbose:
        print(f"[update] {path} (upgraded {n_changed} comment block(s))")

    if write and n_changed:
        path.write_text(upgraded, encoding="utf-8")

    return n_changed


def main() -> None:
    ap = argparse.ArgumentParser(
        description="Upgrade /* ... */ comments with Doxygen tags to /** ... */ in header files."
    )
    ap.add_argument(
        "root",
        help="Root directory (or a single file) to scan, e.g. ./cpp/include",
    )
    ap.add_argument(
        "--write",
        action="store_true",
        help="Actually modify files in place. Without this, runs in dry-run mode.",
    )
    ap.add_argument(
        "--verbose",
        action="store_true",
        help="Print per-file changes.",
    )
    args = ap.parse_args()

    root = Path(args.root).resolve()
    if not root.exists():
        print(f"ERROR: path does not exist: {root}")
        return

    total_files = 0
    total_blocks = 0

    for hdr in find_header_files(root):
        total_files += 1
        n = process_file(hdr, write=args.write, verbose=args.verbose)
        total_blocks += n

    mode = "WRITE" if args.write else "DRY-RUN"
    print(f"\n[{mode}] Scanned {total_files} header file(s) under {root}")
    print(f"  Upgradable Doxygen-style block comments found: {total_blocks}")


if __name__ == "__main__":
    main()
