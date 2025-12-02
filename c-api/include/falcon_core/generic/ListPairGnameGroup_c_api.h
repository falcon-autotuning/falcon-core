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

ListPairGnameGroupHandle ListPairGnameGroup_create_empty();

ListPairGnameGroupHandle ListPairGnameGroup_fill_value(size_t count, PairGnameGroupHandle value);
ListPairGnameGroupHandle ListPairGnameGroup_create(PairGnameGroupHandle* data, size_t count);
void ListPairGnameGroup_destroy(ListPairGnameGroupHandle handle);
void ListPairGnameGroup_push_back(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
size_t ListPairGnameGroup_size(ListPairGnameGroupHandle handle);
bool ListPairGnameGroup_empty(ListPairGnameGroupHandle handle);
/* AUTO-DOC from cpp: ListPairGnameGroup_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairGnameGroup_erase_at(ListPairGnameGroupHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairGnameGroup_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairGnameGroup_clear(ListPairGnameGroupHandle handle);
PairGnameGroupHandle ListPairGnameGroup_at(ListPairGnameGroupHandle handle, size_t idx);
size_t ListPairGnameGroup_items(ListPairGnameGroupHandle handle, PairGnameGroupHandle* out_buffer, size_t buffer_size);
bool ListPairGnameGroup_contains(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
size_t ListPairGnameGroup_index(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
/* AUTO-DOC from cpp: ListPairGnameGroup_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairGnameGroupHandle ListPairGnameGroup_intersection(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other);
bool ListPairGnameGroup_equal(ListPairGnameGroupHandle a, ListPairGnameGroupHandle b);
bool ListPairGnameGroup_not_equal(ListPairGnameGroupHandle a, ListPairGnameGroupHandle b);

// Serialization (from Song)
StringHandle      ListPairGnameGroup_to_json_string(ListPairGnameGroupHandle handle);
ListPairGnameGroupHandle ListPairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif