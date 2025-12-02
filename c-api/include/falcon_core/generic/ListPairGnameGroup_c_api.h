#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairGnameGroupHandle;
// Function declarations

// @category:allocation
ListPairGnameGroupHandle ListPairGnameGroup_create_empty();

// @category:allocation
ListPairGnameGroupHandle ListPairGnameGroup_fill_value(size_t count, PairGnameGroupHandle value);
// @category:allocation
ListPairGnameGroupHandle ListPairGnameGroup_create(PairGnameGroupHandle* data, size_t count);
// @category:deallocation
void ListPairGnameGroup_destroy(ListPairGnameGroupHandle handle);
// @category:write
void ListPairGnameGroup_push_back(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
// @category:read
size_t ListPairGnameGroup_size(ListPairGnameGroupHandle handle);
// @category:read
bool ListPairGnameGroup_empty(ListPairGnameGroupHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairGnameGroup_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairGnameGroup_erase_at(ListPairGnameGroupHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairGnameGroup_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairGnameGroup_clear(ListPairGnameGroupHandle handle);
// @category:read
PairGnameGroupHandle ListPairGnameGroup_at(ListPairGnameGroupHandle handle, size_t idx);
// @category:read
size_t ListPairGnameGroup_items(ListPairGnameGroupHandle handle, PairGnameGroupHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairGnameGroup_contains(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
// @category:read
size_t ListPairGnameGroup_index(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairGnameGroup_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairGnameGroupHandle ListPairGnameGroup_intersection(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other);
// @category:read
bool ListPairGnameGroup_equal(ListPairGnameGroupHandle a, ListPairGnameGroupHandle b);
// @category:read
bool ListPairGnameGroup_not_equal(ListPairGnameGroupHandle a, ListPairGnameGroupHandle b);

// @category:read
StringHandle      ListPairGnameGroup_to_json_string(ListPairGnameGroupHandle handle);
// @category:allocation
ListPairGnameGroupHandle ListPairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif