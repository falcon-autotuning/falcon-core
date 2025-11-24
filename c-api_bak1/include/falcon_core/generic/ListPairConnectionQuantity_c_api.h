#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionQuantityHandle;
// Function declarations

ListPairConnectionQuantityHandle ListPairConnectionQuantity_create_empty();

ListPairConnectionQuantityHandle ListPairConnectionQuantity_fill_value(size_t count, PairConnectionQuantityHandle value);
ListPairConnectionQuantityHandle ListPairConnectionQuantity_create(PairConnectionQuantityHandle* data, size_t count);
void ListPairConnectionQuantity_destroy(ListPairConnectionQuantityHandle handle);
void ListPairConnectionQuantity_push_back(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value);
size_t ListPairConnectionQuantity_size(ListPairConnectionQuantityHandle handle);
bool ListPairConnectionQuantity_empty(ListPairConnectionQuantityHandle handle);
/* AUTO-DOC from cpp: ListPairConnectionQuantity_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairConnectionQuantity_erase_at(ListPairConnectionQuantityHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairConnectionQuantity_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairConnectionQuantity_clear(ListPairConnectionQuantityHandle handle);
PairConnectionQuantityHandle ListPairConnectionQuantity_at(ListPairConnectionQuantityHandle handle, size_t idx);
size_t ListPairConnectionQuantity_items(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle* out_buffer, size_t buffer_size);
bool ListPairConnectionQuantity_contains(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value);
size_t ListPairConnectionQuantity_index(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value);
/* AUTO-DOC from cpp: ListPairConnectionQuantity_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairConnectionQuantityHandle ListPairConnectionQuantity_intersection(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other);
bool ListPairConnectionQuantity_equal(ListPairConnectionQuantityHandle a, ListPairConnectionQuantityHandle b);
bool ListPairConnectionQuantity_not_equal(ListPairConnectionQuantityHandle a, ListPairConnectionQuantityHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListPairConnectionQuantity_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListPairConnectionQuantity_to_json_string(ListPairConnectionQuantityHandle handle);
/* AUTO-DOC from cpp: ListPairConnectionQuantity_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListPairConnectionQuantityHandle ListPairConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif