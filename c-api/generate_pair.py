#!/usr/bin/env python3

# Define your type combinations
type_combinations = [
    # (C_type_1, CPP_real_type_1, CPP_stored_type_1, C_type_2, CPP_real_type_2, CPP_stored_type_2,  name_suffix)
    ("int", "int", "int", "int", "int", "int", "IntInt"),
    ("float", "float", "float", "float", "float", "float", "FloatFloat"),
    ("int", "int", "int", "float", "float", "float", "IntFloat"),
    (
        "ConnectionHandle",
        "falcon_core::physics::device_structures::Connection",
        "falcon_core::physics::device_structures::ConnectionSP",
        "ConnectionHandle",
        "falcon_core::physics::device_structures::Connection",
        "falcon_core::physics::device_structures::ConnectionSP",
        "ConnectionConnection",
    ),
]

header_path = "./include/falcon_core/generic/Pair_c_api.h"
implementation_path = "./src/falcon_core/generic/Pair_c_api.cpp"


def generate_header():
    with open(header_path, "w") as f:
        f.write("""#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"

// Forward declarations for opaque handles
""")

        # Generate typedefs
        for (
            c_type_1,
            cpp_real_1,
            cpp_stored_1,
            c_type_2,
            cpp_real_2,
            cpp_stored_2,
            name,
        ) in type_combinations:
            f.write(f"typedef void* Pair{name}Handle;\n")

        f.write("\n// Function declarations\n")

        # Generate function declarations
        for (
            c_type_1,
            cpp_real_1,
            cpp_stored_1,
            c_type_2,
            cpp_real_2,
            cpp_stored_2,
            name,
        ) in type_combinations:
            f.write(f"""
Pair{name}Handle Pair{name}_create({c_type_1} first, {c_type_2} second);
void Pair{name}_destroy(Pair{name}Handle handle);
{c_type_1} Pair{name}_first(Pair{name}Handle handle);
{c_type_2} Pair{name}_second(Pair{name}Handle handle);
bool Pair{name}_equal(Pair{name}Handle a, Pair{name}Handle b);
""")

        f.write("""
#ifdef __cplusplus
}
#endif
""")


def generate_implementation():
    with open(implementation_path, "w") as f:
        f.write("""
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/Pair_c_api.h"

using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;

// Implementation for all pair types
""")

        for (
            c_type_1,
            cpp_real_1,
            cpp_stored_1,
            c_type_2,
            cpp_real_2,
            cpp_stored_2,
            name,
        ) in type_combinations:
            # Check if each type is primitive (c_type == cpp_real)
            is_primitive_1 = c_type_1 == cpp_real_1
            is_primitive_2 = c_type_2 == cpp_real_2

            # Generate create function
            if is_primitive_1 and is_primitive_2:
                # Both primitive
                create_func = f"Pair{name}_create({c_type_1} first, {c_type_2} second)"
                create_body = (
                    f"return new Pair<{cpp_real_1}, {cpp_real_2}>(first, second);"
                )
            elif is_primitive_1 and not is_primitive_2:
                # First primitive, second complex
                create_func = f"Pair{name}_create({c_type_1} first, {c_type_2} second)"
                create_body = f"""auto second_obj = static_cast<{cpp_stored_2}*>(second);
    return new Pair<{cpp_real_1}, {cpp_real_2}>(first, *second_obj);"""
            elif not is_primitive_1 and is_primitive_2:
                # First complex, second primitive
                create_func = f"Pair{name}_create({c_type_1} first, {c_type_2} second)"
                create_body = f"""auto first_obj = static_cast<{cpp_stored_1}*>(first);
    return new Pair<{cpp_real_1}, {cpp_real_2}>(*first_obj, second);"""
            else:
                # Both complex
                create_func = f"Pair{name}_create({c_type_1} first, {c_type_2} second)"
                create_body = f"""auto first_obj = static_cast<{cpp_stored_1}*>(first);
    auto second_obj = static_cast<{cpp_stored_2}*>(second);
    return new Pair<{cpp_real_1}, {cpp_real_2}>(*first_obj, *second_obj);"""

            # Generate first() function
            if is_primitive_1:
                first_return = f"return static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->first();"
            else:
                first_return = f"""auto pair = static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new {cpp_stored_1}(pair->first());"""

            # Generate second() function
            if is_primitive_2:
                second_return = f"return static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->second();"
            else:
                second_return = f"""auto pair = static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new {cpp_stored_2}(pair->second());"""

            # Write the complete implementation
            f.write(f"""
Pair{name}Handle {create_func} {{
    {create_body}
}}

void Pair{name}_destroy(Pair{name}Handle handle) {{
    delete static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
}}

{c_type_1} Pair{name}_first(Pair{name}Handle handle) {{
    {first_return}
}}

{c_type_2} Pair{name}_second(Pair{name}Handle handle) {{
    {second_return}
}}

bool Pair{name}_equal(Pair{name}Handle a, Pair{name}Handle b) {{
    auto pair_a = static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(a);
    auto pair_b = static_cast<Pair<{cpp_real_1}, {cpp_real_2}>*>(b);
    return *pair_a == *pair_b;
}}
""")


if __name__ == "__main__":
    generate_header()
    generate_implementation()
    print("Generated PairTypes_c_api.h and PairTypes_c_api.cpp")
