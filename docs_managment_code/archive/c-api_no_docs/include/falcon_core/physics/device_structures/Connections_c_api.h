#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ConnectionsHandle;

// Constructors
ConnectionsHandle Connections_create_empty();
ConnectionsHandle Connections_create(ListConnectionHandle items);

// Destructor
void Connections_destroy(ConnectionsHandle handle);

// Methods
bool              Connections_is_gates(ConnectionsHandle handle);
bool              Connections_is_ohmics(ConnectionsHandle handle);
bool              Connections_is_dot_gates(ConnectionsHandle handle);
bool              Connections_is_plunger_gates(ConnectionsHandle handle);
bool              Connections_is_barrier_gates(ConnectionsHandle handle);
bool              Connections_is_reservoir_gates(ConnectionsHandle handle);
bool              Connections_is_screening_gates(ConnectionsHandle handle);
ConnectionsHandle Connections_intersection(ConnectionsHandle handle,
                                           ConnectionsHandle other);
void   Connections_push_back(ConnectionsHandle handle, ConnectionHandle value);
size_t Connections_size(ConnectionsHandle handle);
bool   Connections_empty(ConnectionsHandle handle);
void   Connections_erase_at(ConnectionsHandle handle, size_t idx);
void   Connections_clear(ConnectionsHandle handle);
const ConnectionHandle Connections_const_at(ConnectionsHandle handle,
                                            size_t            idx);
ConnectionHandle       Connections_at(ConnectionsHandle handle, size_t idx);
ListConnectionHandle   Connections_items(ConnectionsHandle handle);
bool   Connections_contains(ConnectionsHandle handle, ConnectionHandle value);
size_t Connections_index(ConnectionsHandle handle, ConnectionHandle value);
bool   Connections_equal(ConnectionsHandle a, ConnectionsHandle b);
bool   Connections_not_equal(ConnectionsHandle a, ConnectionsHandle b);

// Serialization (from Song)
StringHandle      Connections_to_json_string(ConnectionsHandle handle);
ConnectionsHandle Connections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
