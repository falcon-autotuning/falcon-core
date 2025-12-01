#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Impedance_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListImpedanceHandle;
// Function declarations

ListImpedanceHandle ListImpedance_create_empty();

ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value);
ListImpedanceHandle ListImpedance_create(ImpedanceHandle* data, size_t count);
void ListImpedance_destroy(ListImpedanceHandle handle);
void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value);
size_t ListImpedance_size(ListImpedanceHandle handle);
bool ListImpedance_empty(ListImpedanceHandle handle);
/* AUTO-DOC from cpp: ListImpedance_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListImpedance_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListImpedance_clear(ListImpedanceHandle handle);
ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx);
size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size);
bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value);
size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value);
/* AUTO-DOC from cpp: ListImpedance_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other);
bool ListImpedance_equal(ListImpedanceHandle a, ListImpedanceHandle b);
bool ListImpedance_not_equal(ListImpedanceHandle a, ListImpedanceHandle b);

// Serialization (from Song)
StringHandle      ListImpedance_to_json_string(ListImpedanceHandle handle);
ListImpedanceHandle ListImpedance_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif