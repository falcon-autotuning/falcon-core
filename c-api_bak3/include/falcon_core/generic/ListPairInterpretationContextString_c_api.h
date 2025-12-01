#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInterpretationContextStringHandle;
// Function declarations

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create_empty();

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_fill_value(size_t count, PairInterpretationContextStringHandle value);
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count);
void ListPairInterpretationContextString_destroy(ListPairInterpretationContextStringHandle handle);
void ListPairInterpretationContextString_push_back(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
size_t ListPairInterpretationContextString_size(ListPairInterpretationContextStringHandle handle);
bool ListPairInterpretationContextString_empty(ListPairInterpretationContextStringHandle handle);
/* AUTO-DOC from cpp: ListPairInterpretationContextString_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairInterpretationContextString_erase_at(ListPairInterpretationContextStringHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairInterpretationContextString_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairInterpretationContextString_clear(ListPairInterpretationContextStringHandle handle);
PairInterpretationContextStringHandle ListPairInterpretationContextString_at(ListPairInterpretationContextStringHandle handle, size_t idx);
size_t ListPairInterpretationContextString_items(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle* out_buffer, size_t buffer_size);
bool ListPairInterpretationContextString_contains(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
size_t ListPairInterpretationContextString_index(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
/* AUTO-DOC from cpp: ListPairInterpretationContextString_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_intersection(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);
bool ListPairInterpretationContextString_equal(ListPairInterpretationContextStringHandle a, ListPairInterpretationContextStringHandle b);
bool ListPairInterpretationContextString_not_equal(ListPairInterpretationContextStringHandle a, ListPairInterpretationContextStringHandle b);

// Serialization (from Song)
StringHandle      ListPairInterpretationContextString_to_json_string(ListPairInterpretationContextStringHandle handle);
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif