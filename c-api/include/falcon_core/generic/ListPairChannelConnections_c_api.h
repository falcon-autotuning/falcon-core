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

ListPairChannelConnectionsHandle ListPairChannelConnections_create_empty();

ListPairChannelConnectionsHandle ListPairChannelConnections_fill_value(size_t count, PairChannelConnectionsHandle value);
ListPairChannelConnectionsHandle ListPairChannelConnections_create(PairChannelConnectionsHandle* data, size_t count);
void ListPairChannelConnections_destroy(ListPairChannelConnectionsHandle handle);
void ListPairChannelConnections_push_back(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
size_t ListPairChannelConnections_size(ListPairChannelConnectionsHandle handle);
bool ListPairChannelConnections_empty(ListPairChannelConnectionsHandle handle);
void ListPairChannelConnections_erase_at(ListPairChannelConnectionsHandle handle, size_t idx);
void ListPairChannelConnections_clear(ListPairChannelConnectionsHandle handle);
PairChannelConnectionsHandle ListPairChannelConnections_at(ListPairChannelConnectionsHandle handle, size_t idx);
size_t ListPairChannelConnections_items(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle* out_buffer, size_t buffer_size);
bool ListPairChannelConnections_contains(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
size_t ListPairChannelConnections_index(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
ListPairChannelConnectionsHandle ListPairChannelConnections_intersection(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other);
bool ListPairChannelConnections_equal(ListPairChannelConnectionsHandle a, ListPairChannelConnectionsHandle b);
bool ListPairChannelConnections_not_equal(ListPairChannelConnectionsHandle a, ListPairChannelConnectionsHandle b);

// Serialization (from Song)
StringHandle      ListPairChannelConnections_to_json_string(ListPairChannelConnectionsHandle handle);
ListPairChannelConnectionsHandle ListPairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif