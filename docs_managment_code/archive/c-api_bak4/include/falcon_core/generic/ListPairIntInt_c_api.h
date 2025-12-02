#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntInt_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairIntIntHandle;
// Function declarations

// @category:allocation
ListPairIntIntHandle ListPairIntInt_create_empty();

// @category:allocation
ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value);
// @category:allocation
ListPairIntIntHandle ListPairIntInt_create(PairIntIntHandle* data, size_t count);
// @category:deallocation
void ListPairIntInt_destroy(ListPairIntIntHandle handle);
// @category:write
void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value);
// @category:read
size_t ListPairIntInt_size(ListPairIntIntHandle handle);
// @category:read
bool ListPairIntInt_empty(ListPairIntIntHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairIntInt_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairIntInt_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairIntInt_clear(ListPairIntIntHandle handle);
// @category:read
PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx);
// @category:read
size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value);
// @category:read
size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairIntInt_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other);
// @category:read
bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);
// @category:read
bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);

// @category:read
StringHandle      ListPairIntInt_to_json_string(ListPairIntIntHandle handle);
// @category:allocation
ListPairIntIntHandle ListPairIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif