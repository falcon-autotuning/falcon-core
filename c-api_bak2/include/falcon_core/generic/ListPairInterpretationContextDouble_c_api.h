#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInterpretationContextDoubleHandle;
// Function declarations

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_create_empty();

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_fill_value(size_t count, PairInterpretationContextDoubleHandle value);
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_create(PairInterpretationContextDoubleHandle* data, size_t count);
void ListPairInterpretationContextDouble_destroy(ListPairInterpretationContextDoubleHandle handle);
void ListPairInterpretationContextDouble_push_back(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value);
size_t ListPairInterpretationContextDouble_size(ListPairInterpretationContextDoubleHandle handle);
bool ListPairInterpretationContextDouble_empty(ListPairInterpretationContextDoubleHandle handle);
/* AUTO-DOC from cpp: ListPairInterpretationContextDouble_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairInterpretationContextDouble_erase_at(ListPairInterpretationContextDoubleHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairInterpretationContextDouble_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairInterpretationContextDouble_clear(ListPairInterpretationContextDoubleHandle handle);
PairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_at(ListPairInterpretationContextDoubleHandle handle, size_t idx);
size_t ListPairInterpretationContextDouble_items(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle* out_buffer, size_t buffer_size);
bool ListPairInterpretationContextDouble_contains(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value);
size_t ListPairInterpretationContextDouble_index(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value);
/* AUTO-DOC from cpp: ListPairInterpretationContextDouble_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_intersection(ListPairInterpretationContextDoubleHandle handle, ListPairInterpretationContextDoubleHandle other);
bool ListPairInterpretationContextDouble_equal(ListPairInterpretationContextDoubleHandle a, ListPairInterpretationContextDoubleHandle b);
bool ListPairInterpretationContextDouble_not_equal(ListPairInterpretationContextDoubleHandle a, ListPairInterpretationContextDoubleHandle b);

// Serialization (from Song)
StringHandle      ListPairInterpretationContextDouble_to_json_string(ListPairInterpretationContextDoubleHandle handle);
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif