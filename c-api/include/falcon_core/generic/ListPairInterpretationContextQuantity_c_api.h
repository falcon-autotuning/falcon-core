#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInterpretationContextQuantityHandle;
// Function declarations

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create_empty();

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_fill_value(size_t count, PairInterpretationContextQuantityHandle value);
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count);
void ListPairInterpretationContextQuantity_destroy(ListPairInterpretationContextQuantityHandle handle);
void ListPairInterpretationContextQuantity_push_back(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value);
size_t ListPairInterpretationContextQuantity_size(ListPairInterpretationContextQuantityHandle handle);
bool ListPairInterpretationContextQuantity_empty(ListPairInterpretationContextQuantityHandle handle);
/* AUTO-DOC from cpp: ListPairInterpretationContextQuantity_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairInterpretationContextQuantity_erase_at(ListPairInterpretationContextQuantityHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairInterpretationContextQuantity_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairInterpretationContextQuantity_clear(ListPairInterpretationContextQuantityHandle handle);
PairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_at(ListPairInterpretationContextQuantityHandle handle, size_t idx);
size_t ListPairInterpretationContextQuantity_items(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle* out_buffer, size_t buffer_size);
bool ListPairInterpretationContextQuantity_contains(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value);
size_t ListPairInterpretationContextQuantity_index(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value);
/* AUTO-DOC from cpp: ListPairInterpretationContextQuantity_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_intersection(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other);
bool ListPairInterpretationContextQuantity_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b);
bool ListPairInterpretationContextQuantity_not_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b);

// Serialization (from Song)
StringHandle      ListPairInterpretationContextQuantity_to_json_string(ListPairInterpretationContextQuantityHandle handle);
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif