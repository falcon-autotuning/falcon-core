#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListConnectionHandle;
// Function declarations

ListConnectionHandle ListConnection_create_empty();

ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value);
ListConnectionHandle ListConnection_create(ConnectionHandle* data, size_t count);
void ListConnection_destroy(ListConnectionHandle handle);
void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value);
size_t ListConnection_size(ListConnectionHandle handle);
bool ListConnection_empty(ListConnectionHandle handle);
/* AUTO-DOC from cpp: ListConnection_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListConnection_erase_at(ListConnectionHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListConnection_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListConnection_clear(ListConnectionHandle handle);
ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx);
size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size);
bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value);
size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value);
/* AUTO-DOC from cpp: ListConnection_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other);
bool ListConnection_equal(ListConnectionHandle a, ListConnectionHandle b);
bool ListConnection_not_equal(ListConnectionHandle a, ListConnectionHandle b);

// Serialization (from Song)
StringHandle      ListConnection_to_json_string(ListConnectionHandle handle);
ListConnectionHandle ListConnection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif