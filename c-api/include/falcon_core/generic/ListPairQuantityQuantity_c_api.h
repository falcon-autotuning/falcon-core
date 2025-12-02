#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairQuantityQuantityHandle;
// Function declarations

ListPairQuantityQuantityHandle ListPairQuantityQuantity_create_empty();

ListPairQuantityQuantityHandle ListPairQuantityQuantity_fill_value(size_t count, PairQuantityQuantityHandle value);
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create(PairQuantityQuantityHandle* data, size_t count);
void ListPairQuantityQuantity_destroy(ListPairQuantityQuantityHandle handle);
void ListPairQuantityQuantity_push_back(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
size_t ListPairQuantityQuantity_size(ListPairQuantityQuantityHandle handle);
bool ListPairQuantityQuantity_empty(ListPairQuantityQuantityHandle handle);
/* AUTO-DOC from cpp: ListPairQuantityQuantity_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairQuantityQuantity_erase_at(ListPairQuantityQuantityHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairQuantityQuantity_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairQuantityQuantity_clear(ListPairQuantityQuantityHandle handle);
PairQuantityQuantityHandle ListPairQuantityQuantity_at(ListPairQuantityQuantityHandle handle, size_t idx);
size_t ListPairQuantityQuantity_items(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle* out_buffer, size_t buffer_size);
bool ListPairQuantityQuantity_contains(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
size_t ListPairQuantityQuantity_index(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
/* AUTO-DOC from cpp: ListPairQuantityQuantity_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairQuantityQuantityHandle ListPairQuantityQuantity_intersection(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);
bool ListPairQuantityQuantity_equal(ListPairQuantityQuantityHandle a, ListPairQuantityQuantityHandle b);
bool ListPairQuantityQuantity_not_equal(ListPairQuantityQuantityHandle a, ListPairQuantityQuantityHandle b);

// Serialization (from Song)
StringHandle      ListPairQuantityQuantity_to_json_string(ListPairQuantityQuantityHandle handle);
ListPairQuantityQuantityHandle ListPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif