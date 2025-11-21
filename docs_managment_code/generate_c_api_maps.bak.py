#!/usr/bin/env python3
"""
Generate *_c_api.map.yml files by matching C++ methods (from cpp_metadata/*.yml)
with C wrapper functions in a mirrored c-api directory.

This version:
  * Handles an 'include/' subdirectory in cpp_metadata_root correctly.
  * Adds a --verbose flag to print detailed information.
"""

import argparse
import re
from pathlib import Path
import yaml
import os


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description="Generate *_c_api.map.yml files.")
    p.add_argument(
        "--cpp-metadata-root",
        type=Path,
        required=True,
        help="Root directory of cpp_metadata YAML files.",
    )
    p.add_argument(
        "--cpp-include-root",
        type=Path,
        required=True,
        help="Root directory of the C++ headers (e.g. cpp/include).",
    )
    p.add_argument(
        "--c-api-root",
        type=Path,
        required=True,
        help="Root directory of the C API headers (e.g. c-api/include).",
    )
    p.add_argument(
        "--overwrite",
        action="store_true",
        help="Overwrite existing *_c_api.map.yml files.",
    )
    p.add_argument(
        "--verbose",
        action="store_true",
        help="Print detailed processing information.",
    )
    return p.parse_args()


def load_metadata_functions(metadata_path: Path, class_name: str, verbose: bool = False):
    """
    Extract methods for the given class from a *_metadata.yml list.

    We keep entries where:
      - kind == "function"
      - name contains "<class_name>::"
      - the part after that is the method name
      - method_name != class_name (skip constructors)
    """
    with metadata_path.open("r", encoding="utf-8") as f:
        data = yaml.safe_load(f)

    if not isinstance(data, list):
        return []

    methods = []
    needle = f"{class_name}::"

    for item in data:
        if not isinstance(item, dict):
            continue
        if item.get("kind") != "function":
            continue

        full_name = item.get("name")
        if not full_name or needle not in full_name:
            continue

        idx = full_name.rfind(needle)
        method_name = full_name[idx + len(needle):]

        if not method_name or method_name == class_name:
            continue  # skip constructors / bad entries

        methods.append((full_name, method_name))

    if verbose:
        print(f"  Methods found for class {class_name}:")
        for cpp, m in methods:
            print(f"    - {cpp} (method '{m}')")

    return methods


def find_c_wrapper_names(
    class_name: str,
    methods: list[tuple[str, str]],
    c_header_text: str,
    verbose: bool = False,
) -> list[tuple[str, str]]:
    """
    Given a list of (full_cpp_name, method_name) and the C header text,
    return the subset where a C wrapper <ClassName>_<method_name>(...) exists.

    Returns list of (full_cpp_name, c_symbol_name).
    """
    result = []
    for full_cpp, method_name in methods:
        c_symbol = f"{class_name}_{method_name}"
        pattern = rf"\b{re.escape(c_symbol)}\s*\("

        if re.search(pattern, c_header_text):
            result.append((full_cpp, c_symbol))
            if verbose:
                print(f"    ✓ Found matching C wrapper: {c_symbol}")
        else:
            if verbose:
                print(f"    ✗ No C wrapper for: {c_symbol}")

    return result


def process_one_metadata_file(
    metadata_path: Path,
    meta_base_root: Path,
    cpp_include_root: Path,
    c_api_root: Path,
    overwrite: bool,
    verbose: bool,
):
    """
    For a single *_metadata.yml file, locate the corresponding C header,
    CPP header, and write the *_c_api.map.yml.
    """
    stem = metadata_path.stem  # e.g. "Config_metadata"
    if not stem.endswith("_metadata"):
        return

    class_name = stem[: -len("_metadata")]

    if verbose:
        print(f"\nProcessing metadata file: {metadata_path}")
        print(f"  → Class name detected: {class_name}")

    # Directory relative to the metadata 'base' (which is often cpp_metadata/include)
    try:
        rel_dir = metadata_path.parent.relative_to(meta_base_root)
    except ValueError:
        # Not under the base root; skip
        if verbose:
            print(f"  ⚠ {metadata_path.parent} is not under {meta_base_root}, skipping.")
        return

    # Mirrored C header path: <c_api_root>/<rel_dir>/<ClassName>_c_api.h
    c_header_path = c_api_root / rel_dir / f"{class_name}_c_api.h"
    if not c_header_path.is_file():
        if verbose:
            print(f"  ⚠ No C header found: {c_header_path}")
        return

    # Mirrored C++ header path: <cpp_include_root>/<rel_dir>/<ClassName>.hpp
    cpp_header_path = cpp_include_root / rel_dir / f"{class_name}.hpp"

    # Load C header text
    with c_header_path.open("r", encoding="utf-8") as f:
        c_header_text = f.read()

    # Load metadata methods for this class
    methods = load_metadata_functions(metadata_path, class_name, verbose=verbose)
    if not methods:
        if verbose:
            print("  ⚠ No methods found in metadata.")
        return

    # Find which methods actually have C wrappers
    matched = find_c_wrapper_names(class_name, methods, c_header_text, verbose=verbose)

    # Path for the map file
    map_yaml_path = c_header_path.with_name(f"{class_name}_c_api.map.yml")

    if map_yaml_path.exists() and not overwrite:
        print(f"[SKIP] Map exists: {map_yaml_path}")
        return

    # Relative C++ header path from the map file's directory
    rel_cpp_header = os.path.relpath(cpp_header_path, start=map_yaml_path.parent)
    rel_cpp_header = rel_cpp_header.replace("\\", "/")

    yobj = {
        "c_header": c_header_path.name,
        "cpp_headers": [rel_cpp_header],
        "mappings": [{"cpp": cpp, "c": c} for cpp, c in matched],
    }

    # Write YAML
    map_yaml_path.parent.mkdir(parents=True, exist_ok=True)
    with map_yaml_path.open("w", encoding="utf-8") as f:
        yaml.safe_dump(yobj, f, sort_keys=False)

    print(f"[OK] Wrote {map_yaml_path}  (entries: {len(matched)})")

    if verbose:
        print("  Saved map contents:")
        print(yaml.safe_dump(yobj, sort_keys=False))


def main():
    args = parse_args()

    cpp_metadata_root = args.cpp_metadata_root.resolve()
    cpp_include_root = args.cpp_include_root.resolve()
    c_api_root = args.c_api_root.resolve()

    # Detect if cpp_metadata_root has an "include" subdir and use that as base
    include_subdir = cpp_metadata_root / "include"
    if include_subdir.is_dir():
        meta_base_root = include_subdir
    else:
        meta_base_root = cpp_metadata_root

    if args.verbose:
        print(f"cpp_metadata_root: {cpp_metadata_root}")
        print(f"meta_base_root   : {meta_base_root}")
        print(f"cpp_include_root : {cpp_include_root}")
        print(f"c_api_root       : {c_api_root}")

    # Walk all *_metadata.yml under cpp_metadata_root
    for metadata_path in cpp_metadata_root.rglob("*_metadata.yml"):
        process_one_metadata_file(
            metadata_path,
            meta_base_root,
            cpp_include_root,
            c_api_root,
            overwrite=args.overwrite,
            verbose=args.verbose,
        )


if __name__ == "__main__":
    main()
