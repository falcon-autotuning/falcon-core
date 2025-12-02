#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListAcquisitionContextHandle;
// Function declarations

ListAcquisitionContextHandle ListAcquisitionContext_create_empty();

ListAcquisitionContextHandle ListAcquisitionContext_fill_value(size_t count, AcquisitionContextHandle value);
ListAcquisitionContextHandle ListAcquisitionContext_create(AcquisitionContextHandle* data, size_t count);
void ListAcquisitionContext_destroy(ListAcquisitionContextHandle handle);
void ListAcquisitionContext_push_back(ListAcquisitionContextHandle handle, AcquisitionContextHandle value);
size_t ListAcquisitionContext_size(ListAcquisitionContextHandle handle);
bool ListAcquisitionContext_empty(ListAcquisitionContextHandle handle);
/* AUTO-DOC from cpp: ListAcquisitionContext_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListAcquisitionContext_erase_at(ListAcquisitionContextHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListAcquisitionContext_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListAcquisitionContext_clear(ListAcquisitionContextHandle handle);
AcquisitionContextHandle ListAcquisitionContext_at(ListAcquisitionContextHandle handle, size_t idx);
size_t ListAcquisitionContext_items(ListAcquisitionContextHandle handle, AcquisitionContextHandle* out_buffer, size_t buffer_size);
bool ListAcquisitionContext_contains(ListAcquisitionContextHandle handle, AcquisitionContextHandle value);
size_t ListAcquisitionContext_index(ListAcquisitionContextHandle handle, AcquisitionContextHandle value);
/* AUTO-DOC from cpp: ListAcquisitionContext_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListAcquisitionContextHandle ListAcquisitionContext_intersection(ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other);
bool ListAcquisitionContext_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b);
bool ListAcquisitionContext_not_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b);

// Serialization (from Song)
StringHandle      ListAcquisitionContext_to_json_string(ListAcquisitionContextHandle handle);
ListAcquisitionContextHandle ListAcquisitionContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif