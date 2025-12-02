#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListConnections_c_api.h"
#include "falcon_core/generic/ListPairConnectionConnections_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
typedef void* GateRelationsHandle;

// @category:allocation
GateRelationsHandle GateRelations_create_empty();
// @category:allocation
GateRelationsHandle GateRelations_create(
    ListPairConnectionConnectionsHandle items);
// @category:deallocation
void GateRelations_destroy(GateRelationsHandle handle);
// @category:write
/* AUTO-DOC from cpp: GateRelations_insert_or_assign | falcon_core::physics::device_structures::GateRelations::insert_or_assign */
/**
 * @brief Override the default Map assignment to force gate typing.
 */
void GateRelations_insert_or_assign(GateRelationsHandle handle,
                                    ConnectionHandle    key,
                                    ConnectionsHandle   value);
// @category:write
void GateRelations_insert(GateRelationsHandle handle,
                          ConnectionHandle    key,
                          ConnectionsHandle   value);
// @category:read
ConnectionsHandle GateRelations_at(GateRelationsHandle handle,
                                   ConnectionHandle    key);
// @category:write
void GateRelations_erase(GateRelationsHandle handle, ConnectionHandle key);
// @category:read
size_t GateRelations_size(GateRelationsHandle handle);
// @category:read
bool GateRelations_empty(GateRelationsHandle handle);
// @category:write
void GateRelations_clear(GateRelationsHandle handle);
// @category:read
bool GateRelations_contains(GateRelationsHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle GateRelations_keys(GateRelationsHandle handle);
// @category:read
ListConnectionsHandle GateRelations_values(GateRelationsHandle handle);
// @category:read
ListPairConnectionConnectionsHandle GateRelations_items(
    GateRelationsHandle handle);
// @category:read
bool GateRelations_equal(GateRelationsHandle handle, GateRelationsHandle other);
// @category:read
bool GateRelations_not_equal(GateRelationsHandle handle,
                             GateRelationsHandle other);
// @category:read
StringHandle GateRelations_to_json_string(GateRelationsHandle handle);
// @category:allocation
GateRelationsHandle GateRelations_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
