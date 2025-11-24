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

ListPairIntIntHandle ListPairIntInt_create_empty();

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value);
ListPairIntIntHandle ListPairIntInt_create(PairIntIntHandle* data, size_t count);
void ListPairIntInt_destroy(ListPairIntIntHandle handle);
void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value);
size_t ListPairIntInt_size(ListPairIntIntHandle handle);
bool ListPairIntInt_empty(ListPairIntIntHandle handle);
/* AUTO-DOC from cpp: ListPairIntInt_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairIntInt_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairIntInt_clear(ListPairIntIntHandle handle);
PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx);
size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size);
bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value);
size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value);
/* AUTO-DOC from cpp: ListPairIntInt_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other);
bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);
bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListPairIntInt_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListPairIntInt_to_json_string(ListPairIntIntHandle handle);
/* AUTO-DOC from cpp: ListPairIntInt_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListPairIntIntHandle ListPairIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif