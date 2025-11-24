#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairStringDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringDoubleHandle;
// Function declarations

ListPairStringDoubleHandle ListPairStringDouble_create_empty();

ListPairStringDoubleHandle ListPairStringDouble_fill_value(size_t count, PairStringDoubleHandle value);
ListPairStringDoubleHandle ListPairStringDouble_create(PairStringDoubleHandle* data, size_t count);
void ListPairStringDouble_destroy(ListPairStringDoubleHandle handle);
void ListPairStringDouble_push_back(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
size_t ListPairStringDouble_size(ListPairStringDoubleHandle handle);
bool ListPairStringDouble_empty(ListPairStringDoubleHandle handle);
/* AUTO-DOC from cpp: ListPairStringDouble_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairStringDouble_erase_at(ListPairStringDoubleHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairStringDouble_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairStringDouble_clear(ListPairStringDoubleHandle handle);
PairStringDoubleHandle ListPairStringDouble_at(ListPairStringDoubleHandle handle, size_t idx);
size_t ListPairStringDouble_items(ListPairStringDoubleHandle handle, PairStringDoubleHandle* out_buffer, size_t buffer_size);
bool ListPairStringDouble_contains(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
size_t ListPairStringDouble_index(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
/* AUTO-DOC from cpp: ListPairStringDouble_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairStringDoubleHandle ListPairStringDouble_intersection(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other);
bool ListPairStringDouble_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b);
bool ListPairStringDouble_not_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListPairStringDouble_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListPairStringDouble_to_json_string(ListPairStringDoubleHandle handle);
/* AUTO-DOC from cpp: ListPairStringDouble_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListPairStringDoubleHandle ListPairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif