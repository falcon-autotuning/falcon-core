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

// @category:allocation
ListImpedanceHandle ListImpedance_create_empty();

// @category:allocation
ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value);
// @category:allocation
ListImpedanceHandle ListImpedance_create(ImpedanceHandle* data, size_t count);
// @category:deallocation
void ListImpedance_destroy(ListImpedanceHandle handle);
// @category:write
void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
size_t ListImpedance_size(ListImpedanceHandle handle);
// @category:read
bool ListImpedance_empty(ListImpedanceHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListImpedance_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListImpedance_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListImpedance_clear(ListImpedanceHandle handle);
// @category:read
ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx);
// @category:read
size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
/* AUTO-DOC from cpp: ListImpedance_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other);
// @category:read
bool ListImpedance_equal(ListImpedanceHandle a, ListImpedanceHandle b);
// @category:read
bool ListImpedance_not_equal(ListImpedanceHandle a, ListImpedanceHandle b);

// @category:read
StringHandle      ListImpedance_to_json_string(ListImpedanceHandle handle);
// @category:allocation
ListImpedanceHandle ListImpedance_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif