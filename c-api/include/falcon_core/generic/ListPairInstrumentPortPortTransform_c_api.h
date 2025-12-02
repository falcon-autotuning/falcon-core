#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInstrumentPortPortTransformHandle;
// Function declarations

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create_empty();

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_fill_value(size_t count, PairInstrumentPortPortTransformHandle value);
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count);
void ListPairInstrumentPortPortTransform_destroy(ListPairInstrumentPortPortTransformHandle handle);
void ListPairInstrumentPortPortTransform_push_back(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value);
size_t ListPairInstrumentPortPortTransform_size(ListPairInstrumentPortPortTransformHandle handle);
bool ListPairInstrumentPortPortTransform_empty(ListPairInstrumentPortPortTransformHandle handle);
/* AUTO-DOC from cpp: ListPairInstrumentPortPortTransform_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairInstrumentPortPortTransform_erase_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairInstrumentPortPortTransform_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairInstrumentPortPortTransform_clear(ListPairInstrumentPortPortTransformHandle handle);
PairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx);
size_t ListPairInstrumentPortPortTransform_items(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle* out_buffer, size_t buffer_size);
bool ListPairInstrumentPortPortTransform_contains(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value);
size_t ListPairInstrumentPortPortTransform_index(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value);
/* AUTO-DOC from cpp: ListPairInstrumentPortPortTransform_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_intersection(ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other);
bool ListPairInstrumentPortPortTransform_equal(ListPairInstrumentPortPortTransformHandle a, ListPairInstrumentPortPortTransformHandle b);
bool ListPairInstrumentPortPortTransform_not_equal(ListPairInstrumentPortPortTransformHandle a, ListPairInstrumentPortPortTransformHandle b);

// Serialization (from Song)
StringHandle      ListPairInstrumentPortPortTransform_to_json_string(ListPairInstrumentPortPortTransformHandle handle);
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif