#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
typedef void* DotGateWithNeighborsHandle;

// @category:allocation
FALCON_CORE_C_API DotGateWithNeighborsHandle
DotGateWithNeighbors_copy(DotGateWithNeighborsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void DotGateWithNeighbors_destroy(
    DotGateWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API bool DotGateWithNeighbors_equal(
    DotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle other);
// @category:read
FALCON_CORE_C_API bool DotGateWithNeighbors_not_equal(
    DotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
DotGateWithNeighbors_to_json_string(DotGateWithNeighborsHandle handle);
// @category:allocation
FALCON_CORE_C_API DotGateWithNeighborsHandle
DotGateWithNeighbors_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API DotGateWithNeighborsHandle
DotGateWithNeighbors_create_plunger_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
// @category:allocation
FALCON_CORE_C_API DotGateWithNeighborsHandle
DotGateWithNeighbors_create_barrier_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
// @category:read
FALCON_CORE_C_API StringHandle
DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
DotGateWithNeighbors_left_neighbor(DotGateWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
DotGateWithNeighbors_right_neighbor(DotGateWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API bool DotGateWithNeighbors_is_barrier_gate(
    DotGateWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API bool DotGateWithNeighbors_is_plunger_gate(
    DotGateWithNeighborsHandle handle);

#ifdef __cplusplus
}
#endif
