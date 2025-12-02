#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairChannelConnectionsHandle;
// Function declarations

// @category:allocation
ListPairChannelConnectionsHandle ListPairChannelConnections_create_empty();

// @category:allocation
ListPairChannelConnectionsHandle ListPairChannelConnections_fill_value(size_t count, PairChannelConnectionsHandle value);
// @category:allocation
ListPairChannelConnectionsHandle ListPairChannelConnections_create(PairChannelConnectionsHandle* data, size_t count);
// @category:deallocation
void ListPairChannelConnections_destroy(ListPairChannelConnectionsHandle handle);
// @category:write
void ListPairChannelConnections_push_back(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
// @category:read
size_t ListPairChannelConnections_size(ListPairChannelConnectionsHandle handle);
// @category:read
bool ListPairChannelConnections_empty(ListPairChannelConnectionsHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairChannelConnections_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairChannelConnections_erase_at(ListPairChannelConnectionsHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairChannelConnections_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairChannelConnections_clear(ListPairChannelConnectionsHandle handle);
// @category:read
PairChannelConnectionsHandle ListPairChannelConnections_at(ListPairChannelConnectionsHandle handle, size_t idx);
// @category:read
size_t ListPairChannelConnections_items(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairChannelConnections_contains(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
// @category:read
size_t ListPairChannelConnections_index(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairChannelConnections_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairChannelConnectionsHandle ListPairChannelConnections_intersection(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other);
// @category:read
bool ListPairChannelConnections_equal(ListPairChannelConnectionsHandle a, ListPairChannelConnectionsHandle b);
// @category:read
bool ListPairChannelConnections_not_equal(ListPairChannelConnectionsHandle a, ListPairChannelConnectionsHandle b);

// @category:read
StringHandle      ListPairChannelConnections_to_json_string(ListPairChannelConnectionsHandle handle);
// @category:allocation
ListPairChannelConnectionsHandle ListPairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif