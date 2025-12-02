#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionFloatHandle;
// Function declarations

// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty();

// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value);
// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
// @category:deallocation
void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle);
// @category:write
void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle);
// @category:read
bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairConnectionFloat_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairConnectionFloat_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle);
// @category:read
PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx);
// @category:read
size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairConnectionFloat_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
// @category:read
bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b);
// @category:read
bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b);

// @category:read
StringHandle      ListPairConnectionFloat_to_json_string(ListPairConnectionFloatHandle handle);
// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif