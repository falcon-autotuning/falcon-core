#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionPairQuantityQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionPairQuantityQuantityHandle;
// Function declarations

// @category:allocation
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_create_empty();

// @category:allocation
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_fill_value(size_t count, PairConnectionPairQuantityQuantityHandle value);
// @category:allocation
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_create(PairConnectionPairQuantityQuantityHandle* data, size_t count);
// @category:deallocation
void ListPairConnectionPairQuantityQuantity_destroy(ListPairConnectionPairQuantityQuantityHandle handle);
// @category:write
void ListPairConnectionPairQuantityQuantity_push_back(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value);
// @category:read
size_t ListPairConnectionPairQuantityQuantity_size(ListPairConnectionPairQuantityQuantityHandle handle);
// @category:read
bool ListPairConnectionPairQuantityQuantity_empty(ListPairConnectionPairQuantityQuantityHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairConnectionPairQuantityQuantity_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairConnectionPairQuantityQuantity_erase_at(ListPairConnectionPairQuantityQuantityHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairConnectionPairQuantityQuantity_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairConnectionPairQuantityQuantity_clear(ListPairConnectionPairQuantityQuantityHandle handle);
// @category:read
PairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_at(ListPairConnectionPairQuantityQuantityHandle handle, size_t idx);
// @category:read
size_t ListPairConnectionPairQuantityQuantity_items(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairConnectionPairQuantityQuantity_contains(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value);
// @category:read
size_t ListPairConnectionPairQuantityQuantity_index(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairConnectionPairQuantityQuantity_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_intersection(ListPairConnectionPairQuantityQuantityHandle handle, ListPairConnectionPairQuantityQuantityHandle other);
// @category:read
bool ListPairConnectionPairQuantityQuantity_equal(ListPairConnectionPairQuantityQuantityHandle a, ListPairConnectionPairQuantityQuantityHandle b);
// @category:read
bool ListPairConnectionPairQuantityQuantity_not_equal(ListPairConnectionPairQuantityQuantityHandle a, ListPairConnectionPairQuantityQuantityHandle b);

// @category:read
StringHandle      ListPairConnectionPairQuantityQuantity_to_json_string(ListPairConnectionPairQuantityQuantityHandle handle);
// @category:allocation
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif