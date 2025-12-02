#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionConnectionsHandle;
// Function declarations

// @category:allocation
ListPairConnectionConnectionsHandle ListPairConnectionConnections_create_empty();

// @category:allocation
ListPairConnectionConnectionsHandle ListPairConnectionConnections_fill_value(size_t count, PairConnectionConnectionsHandle value);
// @category:allocation
ListPairConnectionConnectionsHandle ListPairConnectionConnections_create(PairConnectionConnectionsHandle* data, size_t count);
// @category:deallocation
void ListPairConnectionConnections_destroy(ListPairConnectionConnectionsHandle handle);
// @category:write
void ListPairConnectionConnections_push_back(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
// @category:read
size_t ListPairConnectionConnections_size(ListPairConnectionConnectionsHandle handle);
// @category:read
bool ListPairConnectionConnections_empty(ListPairConnectionConnectionsHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPairConnectionConnections_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairConnectionConnections_erase_at(ListPairConnectionConnectionsHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPairConnectionConnections_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPairConnectionConnections_clear(ListPairConnectionConnectionsHandle handle);
// @category:read
PairConnectionConnectionsHandle ListPairConnectionConnections_at(ListPairConnectionConnectionsHandle handle, size_t idx);
// @category:read
size_t ListPairConnectionConnections_items(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairConnectionConnections_contains(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
// @category:read
size_t ListPairConnectionConnections_index(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPairConnectionConnections_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairConnectionConnectionsHandle ListPairConnectionConnections_intersection(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other);
// @category:read
bool ListPairConnectionConnections_equal(ListPairConnectionConnectionsHandle a, ListPairConnectionConnectionsHandle b);
// @category:read
bool ListPairConnectionConnections_not_equal(ListPairConnectionConnectionsHandle a, ListPairConnectionConnectionsHandle b);

// @category:read
StringHandle      ListPairConnectionConnections_to_json_string(ListPairConnectionConnectionsHandle handle);
// @category:allocation
ListPairConnectionConnectionsHandle ListPairConnectionConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif