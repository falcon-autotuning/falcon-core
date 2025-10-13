#!/usr/bin/env python3

# Define your list type combinations
# (c_type, real_type, stored_type, name_suffix)
list_type_combinations = [
    ("int", "int", "int", "Int"),
    ("float", "float", "float", "Float"),
    (
        "PairIntIntHandle",
        "falcon_core::generic::Pair<int, int>",
        "falcon_core::generic::PairSP<int, int>",
        "PairIntInt",
    ),
    (
        "PairFloatFloatHandle",
        "falcon_core::generic::Pair<float, float>",
        "falcon_core::generic::PairSP<float, float>",
        "PairFloatFloat",
    ),
    (
        "PairIntFloatHandle",
        "falcon_core::generic::Pair<int, float>",
        "falcon_core::generic::PairSP<int, float>",
        "PairIntFloat",
    ),
    (
        "ConnectionHandle",
        "falcon_core::physics::device_structures::Connection",
        "falcon_core::physics::device_structures::ConnectionSP",
        "Connection",
    ),
]
header_path = "./include/falcon_core/generic/List_c_api.h"
implementation_path = "./src/falcon_core/generic/List_c_api.cpp"


def generate_header():
    with open(header_path, "w") as f:
        f.write("""#pragma once
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/generic/Pair_c_api.h"

// Forward declarations for opaque handles
""")

        # Generate typedefs
        for c_type, cpp_real, cpp_stored, name in list_type_combinations:
            f.write(f"typedef void* List{name}Handle;\n")

        f.write("\n// Function declarations\n")

        # Generate function declarations
        for c_type, cpp_real, cpp_stored, name in list_type_combinations:
            f.write(f"""
List{name}Handle List{name}_create_empty();
List{name}Handle List{name}_allocate(size_t count);
List{name}Handle List{name}_fill_value(size_t count, {c_type} value);
List{name}Handle List{name}_create(const {c_type}* data, size_t count);
void List{name}_destroy(List{name}Handle handle);
void List{name}_push_back(List{name}Handle handle, {c_type} value);
size_t List{name}_size(List{name}Handle handle);
bool List{name}_empty(List{name}Handle handle);
void List{name}_erase_at(List{name}Handle handle, size_t idx);
void List{name}_clear(List{name}Handle handle);
{c_type} List{name}_const_at(List{name}Handle handle, size_t idx);
{c_type} List{name}_at(List{name}Handle handle, size_t idx);
size_t List{name}_items(List{name}Handle handle, {c_type}* out_buffer, size_t buffer_size);
bool List{name}_contains(List{name}Handle handle, {c_type} value);
size_t List{name}_index(List{name}Handle handle, {c_type} value);
List{name}Handle List{name}_intersection(List{name}Handle handle, List{name}Handle other);
bool List{name}_equal(List{name}Handle a, List{name}Handle b);
bool List{name}_not_equal(List{name}Handle a, List{name}Handle b);
""")

        f.write("""
#ifdef __cplusplus
}
#endif
""")


def generate_implementation():
    with open(implementation_path, "w") as f:
        f.write("""#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/Pair_c_api.h"
#include "falcon_core/generic/List_c_api.h"

using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;

// Implementation for all list types
""")

        for c_type, cpp_real, cpp_stored, name in list_type_combinations:
            # Check if this is a primitive type (c_type == cpp_real)
            is_primitive = c_type == cpp_real

            if is_primitive:
                # Primitive type implementation
                f.write(f"""
List{name}Handle List{name}_create_empty() {{
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>());
}}

List{name}Handle List{name}_allocate(size_t count) {{
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>(count));
}}

List{name}Handle List{name}_fill_value(size_t count, {c_type} value) {{
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>(count, value));
}}

List{name}Handle List{name}_create(const {c_type}* data, size_t count) {{
    std::vector<{cpp_stored}> vec(data, data + count);
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>(vec));
}}

void List{name}_destroy(List{name}Handle handle) {{
    delete static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle);
}}

void List{name}_push_back(List{name}Handle handle, {c_type} value) {{
    (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->push_back(value);
}}

size_t List{name}_size(List{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->size();
}}

bool List{name}_empty(List{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->empty();
}}

void List{name}_erase_at(List{name}Handle handle, size_t idx) {{
    (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->erase_at(idx);
}}

void List{name}_clear(List{name}Handle handle) {{
    (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->clear();
}}

{c_type} List{name}_const_at(List{name}Handle handle, size_t idx) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->at(idx);
}}

{c_type} List{name}_at(List{name}Handle handle, size_t idx) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->at(idx);
}}

size_t List{name}_items(List{name}Handle handle, {c_type}* out_buffer, size_t buffer_size) {{
    auto& list = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}}

bool List{name}_contains(List{name}Handle handle, {c_type} value) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->contains(value);
}}

size_t List{name}_index(List{name}Handle handle, {c_type} value) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->index(value);
}}

List{name}Handle List{name}_intersection(List{name}Handle handle, List{name}Handle other) {{
    auto& listA = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<{cpp_real}>>(result);
}}

bool List{name}_equal(List{name}Handle a, List{name}Handle b) {{
    auto& listA = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(b);
    return *listA == *listB;
}}

bool List{name}_not_equal(List{name}Handle a, List{name}Handle b) {{
    return !List{name}_equal(a, b);
}}
""")
            else:
                # Complex type implementation (handles)
                f.write(f"""
List{name}Handle List{name}_create_empty() {{
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>());
}}

List{name}Handle List{name}_allocate(size_t count) {{
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>(count));
}}

List{name}Handle List{name}_fill_value(size_t count, {c_type} value) {{
    auto stored_obj = *static_cast<{cpp_stored}*>(value);
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>(count, stored_obj));
}}

List{name}Handle List{name}_create(const {c_type}* data, size_t count) {{
    std::vector<{cpp_stored}> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(*static_cast<{cpp_stored}*>(data[i]));
    }}
    return new std::shared_ptr<List<{cpp_real}>>(
        std::make_shared<List<{cpp_real}>>(vec));
}}

void List{name}_destroy(List{name}Handle handle) {{
    delete static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle);
}}

void List{name}_push_back(List{name}Handle handle, {c_type} value) {{
    auto stored_obj = *static_cast<{cpp_stored}*>(value);
    (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->push_back(stored_obj);
}}

size_t List{name}_size(List{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->size();
}}

bool List{name}_empty(List{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->empty();
}}

void List{name}_erase_at(List{name}Handle handle, size_t idx) {{
    (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->erase_at(idx);
}}

void List{name}_clear(List{name}Handle handle) {{
    (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->clear();
}}

{c_type} List{name}_const_at(List{name}Handle handle, size_t idx) {{
    auto& obj = (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->at(idx);
    return new {cpp_stored}(obj);
}}

{c_type} List{name}_at(List{name}Handle handle, size_t idx) {{
    auto& obj = (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->at(idx);
    return new {cpp_stored}(obj);
}}

size_t List{name}_items(List{name}Handle handle, {c_type}* out_buffer, size_t buffer_size) {{
    auto& list = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {{
        out_buffer[i] = new {cpp_stored}(list->items()[i]);
    }}
    return n;
}}

bool List{name}_contains(List{name}Handle handle, {c_type} value) {{
    auto stored_obj = *static_cast<{cpp_stored}*>(value);
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->contains(stored_obj);
}}

size_t List{name}_index(List{name}Handle handle, {c_type} value) {{
    auto stored_obj = *static_cast<{cpp_stored}*>(value);
    return (*static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle))->index(stored_obj);
}}

List{name}Handle List{name}_intersection(List{name}Handle handle, List{name}Handle other) {{
    auto& listA = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<{cpp_real}>>(result);
}}

bool List{name}_equal(List{name}Handle a, List{name}Handle b) {{
    auto& listA = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<{cpp_real}>>*>(b);
    return *listA == *listB;
}}

bool List{name}_not_equal(List{name}Handle a, List{name}Handle b) {{
    return !List{name}_equal(a, b);
}}
""")


if __name__ == "__main__":
    generate_header()
    generate_implementation()
    print("Generated List_c_api.h and List_c_api.cpp")
