#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
doxygen_port_coverage.py

Compute:
  1) Local C header Doxygen coverage (scanning c-api/include).
  2) Local C++ header Doxygen coverage (scanning cpp/include directly).
  3) Port coverage: of all documented C++ functions (from headers),
     how many appear in *_c_api.map.yml (exact FQN match, Option A).

Outputs logs:
  - cpp_scanned_doc_functions.log       (FQNs from headers)
  - cpp_ported_functions.log            (FQNs from map.yml)
  - cpp_left_to_port_functions.log      (FQNs doc’d in headers but not ported)
"""

from __future__ import annotations
import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List, Set, Any, Tuple, Dict
import yaml


# ============================================================
#  C header coverage (same idea as your original script)
# ============================================================

CLASS_DEF_RE = re.compile(r'^\s*(class|struct)\s+([A-Za-z_]\w*)\b(?![^;]*;)')

FUNC_DEF_RE = re.compile(
    r'''^
        \s*
        (?:template\s*<[^>]+>\s*)*           # templates
        (?:inline\s+|static\s+|virtual\s+|constexpr\s+|friend\s+|explicit\s+|extern\s+)* 
        [A-Za-z_~][\w:\s<>\*&,\[\]]*         # return type-ish
        \s+
        ([A-Za-z_]\w*)                       # function name
        \s*
        \(
            [^;]*                            # args
        \)
        \s*
        (?:const\s*)?
        (?:noexcept\s*)?
        (?:=\s*0\s*)?                        # pure virtual
        (?:;|{|throw\b)                      # end or body start
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


def summarize_dir_collect(root: Path) -> Tuple[int, int, Set[str], Set[str]]:
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
#  C++ header Doxygen scanner → fully qualified names (Option A)
# ============================================================

DOXY_START_RE = re.compile(r"/\*\*|///|//!")
DOXY_END_RE = re.compile(r"\*/")

# Rough function-name finder: last identifier before '(' that isn't a control keyword
CONTROL_KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "static_assert"}


def extract_func_name_from_decl(decl_text: str) -> str | None:
    # Skip macros/preprocessor
    if decl_text.lstrip().startswith("#"):
        return None

    # Avoid obvious control constructs
    if re.match(r'\s*(if|for|while|switch)\b', decl_text):
        return None

    # Find all identifier + '(' occurrences, take the last
    matches = list(re.finditer(r'([A-Za-z_]\w*)\s*\(', decl_text))
    if not matches:
        return None

    name = matches[-1].group(1)
    if name in CONTROL_KEYWORDS:
        return None
    return name


def scan_cpp_header_for_docs(path: Path) -> Set[str]:
    """
    Return fully qualified names of functions in this header that have an
    attached Doxygen block immediately above them.
    """
    fqns: Set[str] = set()
    text = path.read_text(encoding="utf-8", errors="ignore")
    lines = text.splitlines()

    namespace_stack: List[str] = []
    class_stack: List[str] = []
    scope_stack: List[str] = []  # 'namespace' | 'class' | 'other'

    pending_doc = False
    i = 0
    n = len(lines)

    while i < n:
        line = lines[i]

        # --- Track namespace/class scopes ---
        ns_match = re.match(r'\s*namespace\s+([A-Za-z_]\w*)', line)
        if ns_match and "{" in line:
            namespace_stack.append(ns_match.group(1))
            scope_stack.append("namespace")

        cl_match = re.match(r'\s*(class|struct)\s+([A-Za-z_]\w*)', line)
        if cl_match and "{" in line and ";" not in line.split("{", 1)[-1]:
            class_stack.append(cl_match.group(2))
            scope_stack.append("class")

        # opening brace not tied to namespace/class
        if "{" in line and not (ns_match or cl_match):
            scope_stack.append("other")

        # handle closing braces
        for ch in line:
            if ch == "}":
                if scope_stack:
                    kind = scope_stack.pop()
                    if kind == "class" and class_stack:
                        class_stack.pop()
                    elif kind == "namespace" and namespace_stack:
                        namespace_stack.pop()

        # --- Doxygen start ---
        stripped = line.strip()
        if DOXY_START_RE.search(line):
            pending_doc = True

            # If block comment /** ... */, skip to end of block
            if "/**" in line and "*/" not in line:
                j = i + 1
                while j < n and not DOXY_END_RE.search(lines[j]):
                    j += 1
                i = j  # jump to end of block
            i += 1
            continue

        # --- If we just saw a doc block, now look for the declaration ---
        if pending_doc:
            j = i
            decl_lines: List[str] = []
            seen_paren = False

            while j < n:
                dl = lines[j].strip()
                if not dl:
                    j += 1
                    continue
                # skip preprocessor
                if dl.startswith("#"):
                    j += 1
                    continue

                decl_lines.append(dl)
                if "(" in dl:
                    seen_paren = True
                # stop once we've seen '(' AND ';' or '{'
                if seen_paren and (";" in dl or "{" in dl):
                    break
                j += 1

            if decl_lines:
                decl_text = " ".join(decl_lines)
                func_name = extract_func_name_from_decl(decl_text)
                if func_name:
                    components = namespace_stack + class_stack + [func_name]
                    fqn = "::".join(components) if components else func_name
                    fqns.add(fqn)

            pending_doc = False
            i = j + 1
            continue

        i += 1

    return fqns


def scan_cpp_docs_fqn(cpp_root: Path) -> Set[str]:
    """
    Scan all C++ headers for documented functions, return a set of FQNs.
    """
    fqns: Set[str] = set()
    for h in walk_headers(cpp_root):
        # only treat .hpp/.h files as C++ headers here
        if h.suffix.lower() not in {".h", ".hpp", ".hh", ".hxx"}:
            continue
        fqns.update(scan_cpp_header_for_docs(h))
    return fqns


# ============================================================
#  Map files: ported C++ functions (FQN, Option A)
# ============================================================

def load_yaml(path: Path) -> Any:
    try:
        return yaml.safe_load(path.read_text(encoding="utf-8", errors="ignore"))
    except Exception:
        return None


def find_ported_cpp_functions(c_api_root: Path) -> Set[str]:
    """
    Gather all C++ function FQNs that appear in any *_c_api.map.yml 'cpp' field.
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

def write_list(path: Path, items: Set[str], title: str) -> None:
    with path.open("w", encoding="utf-8") as f:
        f.write(f"# {title}\n")
        for x in sorted(items):
            f.write(x + "\n")


def main() -> None:
    ap = argparse.ArgumentParser(
        description="Compute C header Doxygen coverage and C++→C port coverage (header-based, FQN)."
    )
    ap.add_argument("--cpp-root", required=True, type=Path,
                    help="Root of C++ headers (e.g. ./cpp/include).")
    ap.add_argument("--c-root", required=True, type=Path,
                    help="Root of C API headers (e.g. ./c-api/include).")
    args = ap.parse_args()

    cpp_root = args.cpp_root.resolve()
    c_root = args.c_root.resolve()

    # --- C coverage (unchanged) ---
    c_total, c_doc, _, _ = summarize_dir_collect(c_root)
    c_pct = (100.0 * c_doc / c_total) if c_total else 0.0

    # --- C++ total functions (for reference only) ---
    cpp_total, _, _, _ = summarize_dir_collect(cpp_root)

    # --- C++ doc functions from HEADERS (FQN, ground truth) ---
    cpp_doc_fqns: Set[str] = scan_cpp_docs_fqn(cpp_root)
    cpp_doc_count = len(cpp_doc_fqns)

    # --- Ported functions from map.yml (FQN) ---
    cpp_ported_fqns: Set[str] = find_ported_cpp_functions(c_root)

    # --- Functions left to port (FQN) ---
    left_to_port_fqns = cpp_doc_fqns - cpp_ported_fqns
    ported_from_doc = cpp_doc_fqns & cpp_ported_fqns

    port_pct = (100.0 * len(ported_from_doc) / cpp_doc_count) if cpp_doc_count else 0.0

    # --- Logs ---
    write_list(
        Path("cpp_scanned_doc_functions.log"),
        cpp_doc_fqns,
        "C++ SCANNED doc functions (FQN, from headers)",
    )
    write_list(
        Path("cpp_ported_functions.log"),
        cpp_ported_fqns,
        "C++ functions mapped to C API (FQN, from *_c_api.map.yml)",
    )
    write_list(
        Path("cpp_left_to_port_functions.log"),
        left_to_port_fqns,
        "C++ doc functions (FQN, from headers) with NO C API mapping",
    )

    # --- Output summary ---
    print(f"C++ headers root: {cpp_root}")
    print(f"C  headers root:  {c_root}")
    print()
    print("C header documentation coverage (local):")
    print(f"  Functions with Doxygen: {c_doc}/{c_total} ({c_pct:.1f}%)")
    print()
    print("C++ header documentation coverage (local, header scan):")
    print(f"  Functions with Doxygen: {cpp_doc_count}/{cpp_total}")
    print()
    print("Port coverage (C docs vs C++ docs):")
    print(f"  C++ functions with Doxygen (from headers): {cpp_doc_count}")
    print(f"  Ported docs (C):           {len(ported_from_doc)}/{cpp_doc_count} ({port_pct:.1f}%)")
    print()
    print("Logs written:")
    print("  - cpp_scanned_doc_functions.log")
    print("  - cpp_ported_functions.log")
    print("  - cpp_left_to_port_functions.log")


if __name__ == "__main__":
    main()
