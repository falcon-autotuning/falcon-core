import re
from pathlib import Path

DOXY_START = re.compile(r"/\*\*|///|//!")
DOXY_END = re.compile(r"\*/")

# Matches the start of ANY function declaration (extremely permissive)
FUNC_START = re.compile(
    r"""^
        \s*
        (template\s*<[^>]+>\s*)*         # templates
        ([A-Za-z_~][\w:\<\>\*&\s]+)?     # return type (very flexible)
        \s*
        ([A-Za-z_][A-Za-z0-9_]*)         # function name
        \s*
        \(
    """,
    re.VERBOSE,
)

def scan_cpp_header(path: Path):
    """
    Returns list of tuples:
        (file_path, line_number, fqn, raw_decl)
    Only for functions that have a real Doxygen block immediately before them.
    """

    results = []
    lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()

    namespace_stack = []
    class_stack = []
    pending_doc = False
    pending_doc_line = None

    i = 0
    while i < len(lines):
        line = lines[i]

        # --- namespace begin ---
        ns_match = re.match(r"\s*namespace\s+([A-Za-z_][A-Za-z0-9_]*)", line)
        if ns_match and "{" in line:
            namespace_stack.append(ns_match.group(1))

        # --- class / struct begin ---
        cl_match = re.match(r"\s*(class|struct)\s+([A-Za-z_][A-Za-z0-9_]*)", line)
        if cl_match and "{" in line:
            class_stack.append(cl_match.group(2))

        # --- block endings ---
        if "}" in line:
            # close class first (inner-most)
            if class_stack:
                class_stack.pop()
            # then namespace if needed
            elif namespace_stack:
                namespace_stack.pop()

        # --- Detect Doxygen start ---
        if DOXY_START.search(line):
            pending_doc = True
            pending_doc_line = i

            # If block comment /** ... */, skip to end
            if "/**" in line:
                j = i + 1
                while j < len(lines) and not DOXY_END.search(lines[j]):
                    j += 1
                i = j  # continue after end of block
            i += 1
            continue

        # --- We saw a doc block, now expect a declaration ---
        if pending_doc:
            # Collect consecutive lines until a '(' is found
            decl_lines = []
            j = i
            found_decl = False

            while j < len(lines):
                dl = lines[j].strip()
                if not dl:
                    j += 1
                    continue
                decl_lines.append(dl)
                if "(" in dl:
                    # check if this is a function declaration
                    if FUNC_START.search(dl):
                        found_decl = True
                    break
                j += 1

            if found_decl:
                raw_decl = " ".join(decl_lines)

                name_match = FUNC_START.search(decl_lines[0])
                if name_match:
                    func_name = name_match.group(3)
                else:
                    func_name = "unknown"

                # Build FQN
                components = namespace_stack + class_stack + [func_name]
                fqn = "::".join(components)

                results.append((
                    str(path),
                    pending_doc_line + 1,
                    fqn,
                    raw_decl
                ))

            pending_doc = False

        i += 1

    return results


def scan_directory(root: Path):
    """Scan all C++ headers under a directory."""
    all_results = []
    for h in root.rglob("*.hpp"):
        all_results.extend(scan_cpp_header(h))
    for h in root.rglob("*.h"):
        all_results.extend(scan_cpp_header(h))
    return all_results
