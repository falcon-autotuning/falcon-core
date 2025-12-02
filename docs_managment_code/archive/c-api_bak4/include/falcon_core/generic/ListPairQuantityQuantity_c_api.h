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

// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create_empty();

// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_fill_value(size_t count, PairQuantityQuantityHandle value);
// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create(PairQuantityQuantityHandle* data, size_t count);
// @category:deallocation
void ListPairQuantityQuantity_destroy(ListPairQuantityQuantityHandle handle);
// @category:write
void ListPairQuantityQuantity_push_back(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
size_t ListPairQuantityQuantity_size(ListPairQuantityQuantityHandle handle);
// @category:read
bool ListPairQuantityQuantity_empty(ListPairQuantityQuantityHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairQuantityQuantity_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairQuantityQuantity_erase_at(ListPairQuantityQuantityHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairQuantityQuantity_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairQuantityQuantity_clear(ListPairQuantityQuantityHandle handle);
// @category:read
PairQuantityQuantityHandle ListPairQuantityQuantity_at(ListPairQuantityQuantityHandle handle, size_t idx);
// @category:read
size_t ListPairQuantityQuantity_items(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairQuantityQuantity_contains(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
size_t ListPairQuantityQuantity_index(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairQuantityQuantity_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairQuantityQuantityHandle ListPairQuantityQuantity_intersection(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);
// @category:read
bool ListPairQuantityQuantity_equal(ListPairQuantityQuantityHandle a, ListPairQuantityQuantityHandle b);
// @category:read
bool ListPairQuantityQuantity_not_equal(ListPairQuantityQuantityHandle a, ListPairQuantityQuantityHandle b);

// @category:read
StringHandle      ListPairQuantityQuantity_to_json_string(ListPairQuantityQuantityHandle handle);
// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif