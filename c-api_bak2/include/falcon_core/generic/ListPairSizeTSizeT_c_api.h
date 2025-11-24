#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairSizeTSizeT_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairSizeTSizeTHandle;
// Function declarations

ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty();

ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value(size_t count, PairSizeTSizeTHandle value);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create(PairSizeTSizeTHandle* data, size_t count);
void ListPairSizeTSizeT_destroy(ListPairSizeTSizeTHandle handle);
void ListPairSizeTSizeT_push_back(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
size_t ListPairSizeTSizeT_size(ListPairSizeTSizeTHandle handle);
bool ListPairSizeTSizeT_empty(ListPairSizeTSizeTHandle handle);
/* AUTO-DOC from cpp: ListPairSizeTSizeT_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairSizeTSizeT_erase_at(ListPairSizeTSizeTHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairSizeTSizeT_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairSizeTSizeT_clear(ListPairSizeTSizeTHandle handle);
PairSizeTSizeTHandle ListPairSizeTSizeT_at(ListPairSizeTSizeTHandle handle, size_t idx);
size_t ListPairSizeTSizeT_items(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle* out_buffer, size_t buffer_size);
bool ListPairSizeTSizeT_contains(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
size_t ListPairSizeTSizeT_index(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
/* AUTO-DOC from cpp: ListPairSizeTSizeT_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other);
bool ListPairSizeTSizeT_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b);
bool ListPairSizeTSizeT_not_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b);

// Serialization (from Song)
StringHandle      ListPairSizeTSizeT_to_json_string(ListPairSizeTSizeTHandle handle);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif