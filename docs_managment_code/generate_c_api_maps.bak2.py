#!/usr/bin/env python3
"""
Generate *_c_api.map.yml files by matching C++ methods (from cpp_metadata/*.yml)
with C wrapper functions in a mirrored c-api directory.

Features:
  * Handles an 'include/' subdirectory in cpp_metadata_root correctly.
  * Adds a --verbose flag to print detailed processing information.
  * Supports exceptions to the default C symbol naming rule <Class>_<method>,
    e.g. SymbolUnit_c_api.h where some functions are named
    <Class>_create_<method>, with method names lowercased and special
    handling of "Per" constructs.
  * Handles cases like generic List, where one C++ class (List) fans out
    into many C headers (ListBool_c_api.h, ListConnection_c_api.h, ...).
    For such cases, if <Class>_<method> does not exist in any header,
    the script tries <HeaderBase>_<method> for each *_c_api.h in the same
    directory and generates a separate .map.yml for each header.
"""

import argparse
import os
import re
from pathlib import Path
from typing import Dict, List, Tuple

import yaml


# ---------------------------------------------------------------------------
# Exception rules for C symbol naming
#
# Default rule:
#   C wrapper name = <ClassName>_<methodName>
#
# For some classes / headers, we allow additional patterns.
# For example, in SymbolUnit_c_api.h:
#   - normal wrappers:    SymbolUnit_<method>
#   - factory wrappers:   SymbolUnit_create_<method>
#
# Patterns can use:
#   {cls}    -> prefix for the C symbol (usually class name or header base)
#   {method} -> transformed method name (lowercase + Per rule)
# ---------------------------------------------------------------------------
EXCEPTION_PATTERNS: Dict[str, List[str]] = {
    "SymbolUnit": [
        "{cls}_{method}",
        "{cls}_create_{method}",
    ],
    "Waveform": [
        "{cls}_{method}",
        "{cls}_create_{method}",
    ],
    # Add more per-class patterns if needed
}

# Special C++ → C method name overrides for certain classes (currently SymbolUnit).
# These are applied before the generic "Per" rule and lowercasing.
SPECIAL_METHOD_NAME_MAP: Dict[str, str] = {
    # SymbolUnit special cases
    "NewtonMeter": "newton_meter",
    "NewtonPerMeter": "newtons_per_meter",

    # Waveform special cases
    "CartesianWaveform2D": "cartesianwaveform2D",
    "CartesianIdentityWaveform2D": "cartesianidentitywaveform2D",
    "CartesianWaveform1D": "cartesianwaveform1D",
    "CartesianIdentityWaveform1D": "cartesianidentitywaveform1D",
    # Add more explicit overrides if needed
}


def transform_method_name(raw: str) -> str:
    """
    Transform a C++ method name into the 'method' portion of the C API name.

    Rules:
      1. If the name is in SPECIAL_METHOD_NAME_MAP, use that.
      2. Else, if it contains 'Per' between two strings and the next char
         is capital (e.g. 'NewtonPerMeter', 'WattsPerMeterKelvin'):
           - split on capital letters,
           - join with '_',
           - lowercase.
      3. Else, just lowercase the whole name.
    """
    if raw in SPECIAL_METHOD_NAME_MAP:
        return SPECIAL_METHOD_NAME_MAP[raw]

    # "Per" rule: ...PerX... with a capital after Per
    if re.search(r"[A-Za-z0-9]Per[A-Z]", raw):
        # Split on capitals: 'WattsPerMeterKelvin' -> ['Watts','Per','Meter','Kelvin']
        parts = re.findall(r"[A-Z][a-z0-9]*|[0-9]+", raw)
        return "_".join(p.lower() for p in parts)

    # Default: just lowercase
    return raw.lower()


def candidate_c_names_for_base(
    class_name: str, method_name: str, base_prefix: str
) -> List[str]:
    """
    Return all candidate C symbol names for a given class method,
    given a particular base prefix (e.g. 'List', 'ListBool', 'SymbolUnit').

    class_name controls which exception pattern set we use (if any);
    base_prefix is what actually appears in the C symbol (before the '_').
    """
    patterns = EXCEPTION_PATTERNS.get(class_name, ["{cls}_{method}"])
    transformed = transform_method_name(method_name)
    return [pat.format(cls=base_prefix, method=transformed) for pat in patterns]


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


def load_metadata_functions(
    metadata_path: Path, class_name: str, verbose: bool = False
) -> List[Tuple[str, str]]:
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

    methods: List[Tuple[str, str]] = []
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
        method_name = full_name[idx + len(needle) :]

        if not method_name or method_name == class_name:
            # skip constructors / malformed entries
            continue

        methods.append((full_name, method_name))

    if verbose:
        print(f"  Methods found for class {class_name}:")
        for cpp, m in methods:
            print(f"    - {cpp} (method '{m}')")

    return methods


def collect_c_headers_for_class(
    class_name: str, rel_dir: Path, c_api_root: Path, verbose: bool = False
) -> List[Path]:
    """
    Return a list of *_c_api.h headers under c_api_root/rel_dir that are
    relevant for this class.

    Rule:
      - Only include headers whose base name starts with the class name.
        e.g. for class 'List':
             List_c_api.h, ListBool_c_api.h, ListConnection_c_api.h, ...
             are included (bases: 'List', 'ListBool', 'ListConnection').
        e.g. for class 'Song':
             Song_c_api.h, SongFoo_c_api.h, ...
             but NOT ListBool_c_api.h.
    """
    dir_path = c_api_root / rel_dir
    if not dir_path.is_dir():
        if verbose:
            print(f"  ⚠ C API directory does not exist: {dir_path}")
        return []

    headers: List[Path] = []
    for p in dir_path.glob("*_c_api.h"):
        if not p.is_file():
            continue

        stem = p.stem  # e.g. 'ListBool_c_api'
        base = stem[:-len("_c_api")] if stem.endswith("_c_api") else stem

        # Only take headers whose base starts with the class name
        if base == class_name or base.startswith(class_name):
            headers.append(p)

    headers = sorted(headers)

    if verbose:
        print(f"  C headers under {dir_path} for class {class_name}:")
        for h in headers:
            print(f"    - {h.name}")

    return headers

def find_c_wrappers_for_methods(
    class_name: str,
    methods: List[Tuple[str, str]],
    c_headers: List[Path],
    verbose: bool = False,
) -> Dict[Path, List[Tuple[str, str]]]:
    """
    For each method (full_cpp_name, method_name), try to find matching C
    wrappers in the given list of C headers.

    Strategy per method:
      1. Try <ClassName>_<method> (using exception patterns and transforms)
         in all C headers.
      2. If no such symbol exists in any header, then for each header H:
           - let base = H.stem[:-len('_c_api')]
           - try <base>_<method> in that header only.
           - If found, we record that mapping for H.

    Returns:
      {c_header_path: [(cpp_full_name, c_symbol_name), ...], ...}
    """
    # Pre-load header texts for efficiency
    header_texts: Dict[Path, str] = {}
    for h in c_headers:
        header_texts[h] = h.read_text(encoding="utf-8", errors="ignore")

    mappings_by_header: Dict[Path, List[Tuple[str, str]]] = {h: [] for h in c_headers}

    for full_cpp, method_name in methods:
        if verbose:
            print(f"\n  Processing method: {full_cpp} (method name: {method_name})")

        # --- Step 1: try <ClassName>_<method> in all headers ---
        any_primary_match = False

        primary_candidates = candidate_c_names_for_base(
            class_name, method_name, base_prefix=class_name
        )

        if verbose:
            print(f"    Primary candidates (base={class_name}): {primary_candidates}")

        for h in c_headers:
            text = header_texts[h]
            for c_symbol in primary_candidates:
                pattern = rf"\b{re.escape(c_symbol)}\s*\("
                if re.search(pattern, text):
                    mappings_by_header[h].append((full_cpp, c_symbol))
                    any_primary_match = True
                    if verbose:
                        print(f"      ✓ Found primary C wrapper in {h.name}: {c_symbol}")
                    # we *could* break here to avoid duplicates per header;
                    # but if patterns can yield multiple names, we only want
                    # the first that matches.
                    break

        if any_primary_match:
            # We found at least one <Class>_<method> somewhere; do not
            # attempt the fallback for this method.
            continue

        # --- Step 2: fallback: <HeaderBase>_<method> for each header ---
        if verbose:
            print("    No primary <Class>_<method> symbol found; trying per-header base names.")

        for h in c_headers:
            stem = h.stem  # e.g. "ListBool_c_api"
            base = stem[:-len("_c_api")] if stem.endswith("_c_api") else stem

            fallback_candidates = candidate_c_names_for_base(
                class_name, method_name, base_prefix=base
            )

            if verbose:
                print(f"      Header {h.name}: base={base}, candidates={fallback_candidates}")

            text = header_texts[h]
            for c_symbol in fallback_candidates:
                pattern = rf"\b{re.escape(c_symbol)}\s*\("
                if re.search(pattern, text):
                    mappings_by_header[h].append((full_cpp, c_symbol))
                    if verbose:
                        print(
                            f"        ✓ Found fallback C wrapper in {h.name}: {c_symbol}"
                        )
                    break

    # Drop headers with no mappings at all
    mappings_by_header = {
        h: lst for h, lst in mappings_by_header.items() if lst
    }

    return mappings_by_header


def process_one_metadata_file(
    metadata_path: Path,
    meta_base_root: Path,
    cpp_include_root: Path,
    c_api_root: Path,
    overwrite: bool,
    verbose: bool,
):
    """
    For a single *_metadata.yml file, locate the corresponding C++ header,
    all relevant C headers, and write one *_c_api.map.yml per C header that
    has matches.
    """
    stem = metadata_path.stem  # e.g. "List_metadata"
    if not stem.endswith("_metadata"):
        return

    class_name = stem[: -len("_metadata")]

    if verbose:
        print(f"\n=== Processing metadata file: {metadata_path}")
        print(f"  → Class name detected: {class_name}")

    # Directory relative to the metadata 'base' (which is often cpp_metadata/include)
    try:
        rel_dir = metadata_path.parent.relative_to(meta_base_root)
    except ValueError:
        if verbose:
            print(f"  ⚠ {metadata_path.parent} is not under {meta_base_root}, skipping.")
        return

    # Collect all relevant C headers in this directory
    c_headers = collect_c_headers_for_class(class_name, rel_dir, c_api_root, verbose)
    if not c_headers:
        if verbose:
            print("  ⚠ No *_c_api.h headers found for this class; skipping.")
        return

    # Mirrored C++ header path: <cpp_include_root>/<rel_dir>/<ClassName>.hpp
    cpp_header_path = cpp_include_root / rel_dir / f"{class_name}.hpp"

    # Load methods from metadata
    methods = load_metadata_functions(metadata_path, class_name, verbose=verbose)
    if not methods:
        if verbose:
            print("  ⚠ No methods found in metadata.")
        return

    # Find C wrappers across all headers
    mappings_by_header = find_c_wrappers_for_methods(
        class_name, methods, c_headers, verbose=verbose
    )

    if not mappings_by_header:
        if verbose:
            print("  ⚠ No C wrappers found for any methods; skipping map generation.")
        return

    # For each header with mappings, write a .map.yml for that header
    for h, mappings in mappings_by_header.items():
        # map file name: <HeaderStem>.map.yml, e.g. ListBool_c_api.map.yml
        map_yaml_path = h.with_suffix(".map.yml")

        if map_yaml_path.exists() and not overwrite:
            print(f"[SKIP] Map exists: {map_yaml_path}")
            continue

        # Relative C++ header path from this map file's directory
        rel_cpp_header = os.path.relpath(cpp_header_path, start=map_yaml_path.parent)
        rel_cpp_header = rel_cpp_header.replace("\\", "/")

        yobj = {
            "c_header": h.name,
            "cpp_headers": [rel_cpp_header],
            "mappings": [{"cpp": cpp, "c": c} for cpp, c in mappings],
        }

        map_yaml_path.parent.mkdir(parents=True, exist_ok=True)
        with map_yaml_path.open("w", encoding="utf-8") as f:
            yaml.safe_dump(yobj, f, sort_keys=False)

        print(f"[OK] Wrote {map_yaml_path}  (entries: {len(mappings)})")

        if verbose:
            print("  Map contents:")
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
