#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListQuantityHandle;
// Function declarations

ListQuantityHandle ListQuantity_create_empty();

ListQuantityHandle ListQuantity_fill_value(size_t count, QuantityHandle value);
ListQuantityHandle ListQuantity_create(QuantityHandle* data, size_t count);
void ListQuantity_destroy(ListQuantityHandle handle);
void ListQuantity_push_back(ListQuantityHandle handle, QuantityHandle value);
size_t ListQuantity_size(ListQuantityHandle handle);
bool ListQuantity_empty(ListQuantityHandle handle);
/* AUTO-DOC from cpp: ListQuantity_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListQuantity_erase_at(ListQuantityHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListQuantity_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListQuantity_clear(ListQuantityHandle handle);
QuantityHandle ListQuantity_at(ListQuantityHandle handle, size_t idx);
size_t ListQuantity_items(ListQuantityHandle handle, QuantityHandle* out_buffer, size_t buffer_size);
bool ListQuantity_contains(ListQuantityHandle handle, QuantityHandle value);
size_t ListQuantity_index(ListQuantityHandle handle, QuantityHandle value);
/* AUTO-DOC from cpp: ListQuantity_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListQuantityHandle ListQuantity_intersection(ListQuantityHandle handle, ListQuantityHandle other);
bool ListQuantity_equal(ListQuantityHandle a, ListQuantityHandle b);
bool ListQuantity_not_equal(ListQuantityHandle a, ListQuantityHandle b);

// Serialization (from Song)
StringHandle      ListQuantity_to_json_string(ListQuantityHandle handle);
ListQuantityHandle ListQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif