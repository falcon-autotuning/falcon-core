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
FALCON_CORE_C_API GateRelationsHandle
GateRelations_copy(GateRelationsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void GateRelations_destroy(GateRelationsHandle handle);
// @category:read
FALCON_CORE_C_API bool GateRelations_equal(GateRelationsHandle handle,
                                           GateRelationsHandle other);
// @category:read
FALCON_CORE_C_API bool GateRelations_not_equal(GateRelationsHandle handle,
                                               GateRelationsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
GateRelations_to_json_string(GateRelationsHandle handle);
// @category:allocation
FALCON_CORE_C_API GateRelationsHandle
GateRelations_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API GateRelationsHandle GateRelations_create_empty();
// @category:allocation
FALCON_CORE_C_API GateRelationsHandle
GateRelations_create(ListPairConnectionConnectionsHandle items);
// @category:write
/* AUTO-DOC from cpp: GateRelations_insert_or_assign |
 * falcon_core::physics::device_structures::GateRelations::insert_or_assign */
/**
 * @brief Override the default Map assignment to force gate typing.
 */
FALCON_CORE_C_API void GateRelations_insert_or_assign(
    GateRelationsHandle handle, ConnectionHandle key, ConnectionsHandle value);
// @category:write
FALCON_CORE_C_API void GateRelations_insert(GateRelationsHandle handle,
                                            ConnectionHandle    key,
                                            ConnectionsHandle   value);
// @category:read
FALCON_CORE_C_API ConnectionsHandle GateRelations_at(GateRelationsHandle handle,
                                                     ConnectionHandle    key);
// @category:write
FALCON_CORE_C_API void GateRelations_erase(GateRelationsHandle handle,
                                           ConnectionHandle    key);
// @category:read
FALCON_CORE_C_API size_t GateRelations_size(GateRelationsHandle handle);
// @category:read
FALCON_CORE_C_API bool GateRelations_empty(GateRelationsHandle handle);
// @category:write
FALCON_CORE_C_API void GateRelations_clear(GateRelationsHandle handle);
// @category:read
FALCON_CORE_C_API bool GateRelations_contains(GateRelationsHandle handle,
                                              ConnectionHandle    key);
// @category:read
FALCON_CORE_C_API ListConnectionHandle
GateRelations_keys(GateRelationsHandle handle);
// @category:read
FALCON_CORE_C_API ListConnectionsHandle
GateRelations_values(GateRelationsHandle handle);
// @category:read
FALCON_CORE_C_API ListPairConnectionConnectionsHandle
GateRelations_items(GateRelationsHandle handle);

#ifdef __cplusplus
}
#endif
