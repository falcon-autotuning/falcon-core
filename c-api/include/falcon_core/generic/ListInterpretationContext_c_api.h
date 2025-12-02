#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListInterpretationContextHandle;
// Function declarations

// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_create_empty();

// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value);
// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count);
// @category:deallocation
void ListInterpretationContext_destroy(ListInterpretationContextHandle handle);
// @category:write
void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
size_t ListInterpretationContext_size(ListInterpretationContextHandle handle);
// @category:read
bool ListInterpretationContext_empty(ListInterpretationContextHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListInterpretationContext_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListInterpretationContext_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListInterpretationContext_clear(ListInterpretationContextHandle handle);
// @category:read
InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx);
// @category:read
size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
/* AUTO-DOC from cpp: ListInterpretationContext_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);
// @category:read
bool ListInterpretationContext_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b);
// @category:read
bool ListInterpretationContext_not_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b);

// @category:read
StringHandle      ListInterpretationContext_to_json_string(ListInterpretationContextHandle handle);
// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif