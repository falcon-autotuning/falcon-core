#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairIntFloatHandle;
// Function declarations

// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_create_empty();

// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value);
// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_create(PairIntFloatHandle* data, size_t count);
// @category:deallocation
void ListPairIntFloat_destroy(ListPairIntFloatHandle handle);
// @category:write
void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
size_t ListPairIntFloat_size(ListPairIntFloatHandle handle);
// @category:read
bool ListPairIntFloat_empty(ListPairIntFloatHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairIntFloat_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairIntFloat_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairIntFloat_clear(ListPairIntFloatHandle handle);
// @category:read
PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx);
// @category:read
size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairIntFloat_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
// @category:read
bool ListPairIntFloat_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b);
// @category:read
bool ListPairIntFloat_not_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b);

// @category:read
StringHandle      ListPairIntFloat_to_json_string(ListPairIntFloatHandle handle);
// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif