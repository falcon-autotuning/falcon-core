#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListConnections_c_api.h"
#include "falcon_core/generic/ListPairConnectionConnections_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
typedef void* GateRelationsHandle;

// Constructors
GateRelationsHandle GateRelations_create_empty();
GateRelationsHandle GateRelations_create(
    ListPairConnectionConnectionsHandle items);

// Destructor
void GateRelations_destroy(GateRelationsHandle handle);

// Methods
void              GateRelations_insert_or_assign(GateRelationsHandle handle,
                                                 ConnectionHandle    key,
                                                 ConnectionsHandle   value);
void              GateRelations_insert(GateRelationsHandle handle,
                                       ConnectionHandle    key,
                                       ConnectionsHandle   value);
ConnectionsHandle GateRelations_at(GateRelationsHandle handle,
                                   ConnectionHandle    key);
void   GateRelations_erase(GateRelationsHandle handle, ConnectionHandle key);
size_t GateRelations_size(GateRelationsHandle handle);
bool   GateRelations_empty(GateRelationsHandle handle);
void   GateRelations_clear(GateRelationsHandle handle);
bool   GateRelations_contains(GateRelationsHandle handle, ConnectionHandle key);
ListConnectionHandle  GateRelations_keys(GateRelationsHandle handle);
ListConnectionsHandle GateRelations_values(GateRelationsHandle handle);
ListPairConnectionConnectionsHandle GateRelations_items(
    GateRelationsHandle handle);
bool GateRelations_equal(GateRelationsHandle a, GateRelationsHandle b);
bool GateRelations_not_equal(GateRelationsHandle a, GateRelationsHandle b);

// Serialization (from Song)
const char*         GateRelations_to_json_string(GateRelationsHandle handle);
GateRelationsHandle GateRelations_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
