#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDiscretizerHandle;
// Function declarations

ListDiscretizerHandle ListDiscretizer_create_empty();

ListDiscretizerHandle ListDiscretizer_fill_value(size_t count, DiscretizerHandle value);
ListDiscretizerHandle ListDiscretizer_create(DiscretizerHandle* data, size_t count);
void ListDiscretizer_destroy(ListDiscretizerHandle handle);
void ListDiscretizer_push_back(ListDiscretizerHandle handle, DiscretizerHandle value);
size_t ListDiscretizer_size(ListDiscretizerHandle handle);
bool ListDiscretizer_empty(ListDiscretizerHandle handle);
/* AUTO-DOC from cpp: ListDiscretizer_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListDiscretizer_erase_at(ListDiscretizerHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListDiscretizer_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListDiscretizer_clear(ListDiscretizerHandle handle);
DiscretizerHandle ListDiscretizer_at(ListDiscretizerHandle handle, size_t idx);
size_t ListDiscretizer_items(ListDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
bool ListDiscretizer_contains(ListDiscretizerHandle handle, DiscretizerHandle value);
size_t ListDiscretizer_index(ListDiscretizerHandle handle, DiscretizerHandle value);
/* AUTO-DOC from cpp: ListDiscretizer_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListDiscretizerHandle ListDiscretizer_intersection(ListDiscretizerHandle handle, ListDiscretizerHandle other);
bool ListDiscretizer_equal(ListDiscretizerHandle a, ListDiscretizerHandle b);
bool ListDiscretizer_not_equal(ListDiscretizerHandle a, ListDiscretizerHandle b);

// Serialization (from Song)
StringHandle      ListDiscretizer_to_json_string(ListDiscretizerHandle handle);
ListDiscretizerHandle ListDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif