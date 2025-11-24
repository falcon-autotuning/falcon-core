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

ListInterpretationContextHandle ListInterpretationContext_create_empty();

ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value);
ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count);
void ListInterpretationContext_destroy(ListInterpretationContextHandle handle);
void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value);
size_t ListInterpretationContext_size(ListInterpretationContextHandle handle);
bool ListInterpretationContext_empty(ListInterpretationContextHandle handle);
/* AUTO-DOC from cpp: ListInterpretationContext_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListInterpretationContext_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListInterpretationContext_clear(ListInterpretationContextHandle handle);
InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx);
size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size);
bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value);
size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value);
/* AUTO-DOC from cpp: ListInterpretationContext_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);
bool ListInterpretationContext_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b);
bool ListInterpretationContext_not_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListInterpretationContext_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListInterpretationContext_to_json_string(ListInterpretationContextHandle handle);
/* AUTO-DOC from cpp: ListInterpretationContext_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListInterpretationContextHandle ListInterpretationContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif