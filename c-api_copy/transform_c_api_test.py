import re
import sys


def process_file(filename):
    with open(filename, "r") as f:
        lines = f.readlines()

    # Insert ErrorHandling include after line 0
    lines.insert(1, '#include "falcon_core/generic/ErrorHandling_c_api.h"\n')

    throw_pattern = re.compile(
        r"EXPECT_THROW\s*\(\s*(.+?),\s*std::[a-zA-Z_][\w:]*\s*\)\s*;"
    )
    any_throw_pattern = re.compile(r"EXPECT_ANY_THROW\s*\(\s*(.+?)\s*\)\s*;")

    new_lines = []
    i = 0
    while i < len(lines):
        line = lines[i]
        # Handle multi-line EXPECT_THROW
        if "EXPECT_THROW" in line and not line.strip().endswith(";"):
            # Join with next line(s) until we find the closing );
            combined = line.rstrip("\n")
            j = i + 1
            while j < len(lines):
                combined += lines[j].rstrip("\n")
                if ");" in lines[j]:
                    break
                j += 1
            m = throw_pattern.search(combined)
            if m:
                func_call = m.group(1).strip()
                new_lines.append("  set_last_error(0, nullptr);\n")
                new_lines.append(f"  {func_call};\n")
                new_lines.append("  EXPECT_EQ(get_last_error_code(), 1);\n")
                i = j + 1
                continue
        # Handle multi-line EXPECT_ANY_THROW
        if "EXPECT_ANY_THROW" in line and not line.strip().endswith(";"):
            combined = line.rstrip("\n")
            j = i + 1
            while j < len(lines):
                combined += lines[j].rstrip("\n")
                if ");" in lines[j]:
                    break
                j += 1
            n = any_throw_pattern.search(combined)
            if n:
                func_call = n.group(1).strip()
                new_lines.append("  set_last_error(0, nullptr);\n")
                new_lines.append(f"  {func_call};\n")
                new_lines.append("  EXPECT_EQ(get_last_error_code(), 1);\n")
                i = j + 1
                continue
        # Handle single-line cases
        m = throw_pattern.search(line)
        n = any_throw_pattern.search(line)
        if m:
            func_call = m.group(1).strip()
            new_lines.append("  set_last_error(0, nullptr);\n")
            new_lines.append(f"  {func_call};\n")
            new_lines.append("  EXPECT_EQ(get_last_error_code(), 1);\n")
        elif n:
            func_call = n.group(1).strip()
            new_lines.append("  set_last_error(0, nullptr);\n")
            new_lines.append(f"  {func_call};\n")
            new_lines.append("  EXPECT_EQ(get_last_error_code(), 1);\n")
        else:
            new_lines.append(line)
        i += 1

    with open(filename, "w") as f:
        f.writelines(new_lines)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python transform_c_api_tests.py <filename>")
        sys.exit(1)
    process_file(sys.argv[1])
