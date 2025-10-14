#!/usr/bin/env python3

# Define your map type combinations
# (c_key_type, key_type, stored_key_type, c_value_type, value_type, stored_value_type, key_name_suffix, value_name_suffix)
list_type_combinations = [
    ("int", "int", "int", "int", "int", "int", "Int", "Int"),
    ("float", "float", "float", "float", "float", "float", "Float", "Float"),
    (
        "ConnectionHandle",
        "falcon_core::physics::device_structures::Connection",
        "falcon_core::physics::device_structures::ConnectionSP",
        "float",
        "float",
        "float",
        "Connection",
        "Float",
    ),
]
header_path = "./include/falcon_core/generic/Map_c_api.h"
implementation_path = "./src/falcon_core/generic/Map_c_api.cpp"


def generate_header():
    with open(header_path, "w") as f:
        f.write("""#pragma once
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/generic/Pair_c_api.h"
#include "falcon_core/generic/List_c_api.h"

// Forward declarations for opaque handles
""")

        # Generate typedefs
        for (
            c_key_type,
            cpp_key_type,
            cpp_stored_key_type,
            c_value_type,
            cpp_value_type,
            cpp_stored_value_type,
            key_name,
            value_name,
        ) in list_type_combinations:
            name = key_name + value_name
            f.write(f"typedef void* Map{name}Handle;\n")

        f.write("\n// Function declarations\n")

        # Generate function declarations
        for (
            c_key_type,
            cpp_key_type,
            cpp_stored_key_type,
            c_value_type,
            cpp_value_type,
            cpp_stored_value_type,
            key_name,
            value_name,
        ) in list_type_combinations:
            name = key_name + value_name
            f.write(f"""
Map{name}Handle Map{name}_create_empty();
Map{name}Handle Map{name}_create(const Pair{name}Handle* data, size_t count);
void Map{name}_destroy(Map{name}Handle handle);
void Map{name}_insert_or_assign(Map{name}Handle handle, const {c_key_type} key, const {c_value_type} value);
void Map{name}_insert(Map{name}Handle handle, const {c_key_type} key, const {c_value_type} value);
{c_value_type} Map{name}_at(Map{name}Handle handle, const {c_key_type} key);
void Map{name}_erase(Map{name}Handle handle, const {c_key_type} key);
size_t Map{name}_size(Map{name}Handle handle);
bool Map{name}_empty(Map{name}Handle handle);
void Map{name}_clear(Map{name}Handle handle);
bool Map{name}_contains(Map{name}Handle handle, const {c_key_type} key);
List{key_name}Handle Map{name}_keys(Map{name}Handle handle);
List{value_name}Handle Map{name}_values(Map{name}Handle handle);
ListPair{name}Handle Map{name}_items(Map{name}Handle handle);
bool Map{name}_equal(Map{name}Handle a, Map{name}Handle b);
bool Map{name}_not_equal(Map{name}Handle a, Map{name}Handle b);
""")

        f.write("""
#ifdef __cplusplus
}
#endif
""")


def generate_implementation():
    with open(implementation_path, "w") as f:
        f.write("""#include <falcon_core/generic/Map.hpp>
#include <falcon_core/generic/Map.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/Pair_c_api.h"
#include "falcon_core/generic/List_c_api.h"
#include "falcon_core/generic/Map_c_api.h"

using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;

// Implementation for all map list types
""")

        for (
            c_key_type,
            cpp_key_type,
            cpp_stored_key_type,
            c_value_type,
            cpp_value_type,
            cpp_stored_value_type,
            key_name,
            value_name,
        ) in list_type_combinations:
            name = key_name + value_name
            is_primitive_key = cpp_key_type == c_key_type
            is_primitive_value = cpp_value_type == c_value_type
            if not is_primitive_key:
                correct_key = f"""auto temp_key = *static_cast<{cpp_key_type}*>(key);
                    auto correct_key = std::make_shared<{cpp_key_type}>(temp_key);"""
            else:
                correct_key = """auto correct_key = key;"""
            if not is_primitive_value:
                correct_value = f"""auto temp_value = *static_cast<{cpp_value_type}*>(value);
                    auto correct_value = std::make_shared<{cpp_value_type}>(temp_value);"""
            else:
                correct_value = """auto correct_value = value;"""
            f.write(f"""
Map{name}Handle Map{name}_create_empty() {{
    return new std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>(
            std::make_shared<Map<{cpp_key_type},{cpp_value_type}>>());
}}

Map{name}Handle Map{name}_create(const Pair{name}Handle* data, size_t count) {{
    std::vector<PairSP<{cpp_key_type},{cpp_value_type}>> vec(data, data + count);
    return new std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>(
            std::make_shared<Map<{cpp_key_type},{cpp_value_type}>>(vec));
}}

void Map{name}_destroy(Map{name}Handle handle) {{
    delete static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
}}

void Map{name}_insert_or_assign(Map{name}Handle handle, const {c_key_type} key, const {c_value_type} value) {{
    {correct_key}
    {correct_value}
    (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->insert_or_assign(correct_key,correct_value);
}}

void Map{name}_insert(Map{name}Handle handle, const {c_key_type} key, const {c_value_type} value) {{
    {correct_key}
    {correct_value}
    (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->insert(correct_key,correct_value);
}}

{c_value_type} Map{name}_at(Map{name}Handle handle, const {c_key_type} key) {{
    {correct_key}
    return (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->at(correct_key);
}}

void Map{name}_erase(Map{name}Handle handle, const {c_key_type} key) {{
    {correct_key}
    return (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->erase(correct_key);
}}

size_t Map{name}_size(Map{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->size();
}}

bool Map{name}_empty(Map{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->empty();
}}


void Map{name}_clear(Map{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->clear();
}}

bool Map{name}_contains(Map{name}Handle handle, {c_key_type} key) {{
    {correct_key}
    return (*static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->contains(correct_key);
}}

List{key_name}Handle Map{name}_keys(Map{name}Handle handle) {{
    auto& map = *static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<List<Key>>
    return new std::shared_ptr<List<{cpp_key_type}>>(keys_sp);
}}

List{value_name}Handle Map{name}_values(Map{name}Handle handle) {{
    auto& map = *static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
    auto values_sp = map->values(); // shared_ptr<List<Value>>
    return new std::shared_ptr<List<{cpp_value_type}>>(values_sp);
}}

ListPair{name}Handle Map{name}_items(Map{name}Handle handle) {{
    auto& map = *static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
    List<Pair<{cpp_key_type},{cpp_value_type}>> items_sp = map->items(); // shared_ptr<List<Pair<Key,Value>>>
    return new std::shared_ptr<List<Pair<{cpp_key_type},{cpp_value_type}>>>(std::make_shared<List<Pair<{cpp_key_type},{cpp_value_type}>>>(items_sp));
}}

bool Map{name}_equal(Map{name}Handle a, Map{name}Handle b) {{
    auto& listA = *static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<Map<{cpp_key_type},{cpp_value_type}>>*>(b);
    return *listA == *listB;
}}

bool Map{name}_not_equal(Map{name}Handle a, Map{name}Handle b) {{
    return !Map{name}_equal(a, b);
}}
""")


if __name__ == "__main__":
    generate_header()
    generate_implementation()
    print("Generated Map_c_api.h and Map_c_api.cpp")
