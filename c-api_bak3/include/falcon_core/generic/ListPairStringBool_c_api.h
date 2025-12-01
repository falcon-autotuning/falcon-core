#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringBoolHandle;
// Function declarations

ListPairStringBoolHandle ListPairStringBool_create_empty();

ListPairStringBoolHandle ListPairStringBool_fill_value(size_t count, PairStringBoolHandle value);
ListPairStringBoolHandle ListPairStringBool_create(PairStringBoolHandle* data, size_t count);
void ListPairStringBool_destroy(ListPairStringBoolHandle handle);
void ListPairStringBool_push_back(ListPairStringBoolHandle handle, PairStringBoolHandle value);
size_t ListPairStringBool_size(ListPairStringBoolHandle handle);
bool ListPairStringBool_empty(ListPairStringBoolHandle handle);
/* AUTO-DOC from cpp: ListPairStringBool_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairStringBool_erase_at(ListPairStringBoolHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairStringBool_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairStringBool_clear(ListPairStringBoolHandle handle);
PairStringBoolHandle ListPairStringBool_at(ListPairStringBoolHandle handle, size_t idx);
size_t ListPairStringBool_items(ListPairStringBoolHandle handle, PairStringBoolHandle* out_buffer, size_t buffer_size);
bool ListPairStringBool_contains(ListPairStringBoolHandle handle, PairStringBoolHandle value);
size_t ListPairStringBool_index(ListPairStringBoolHandle handle, PairStringBoolHandle value);
/* AUTO-DOC from cpp: ListPairStringBool_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairStringBoolHandle ListPairStringBool_intersection(ListPairStringBoolHandle handle, ListPairStringBoolHandle other);
bool ListPairStringBool_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b);
bool ListPairStringBool_not_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b);

// Serialization (from Song)
StringHandle      ListPairStringBool_to_json_string(ListPairStringBoolHandle handle);
ListPairStringBoolHandle ListPairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif