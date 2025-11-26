#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* DotGateWithNeighborsHandle;

// @category:allocation
DotGateWithNeighborsHandle
DotGateWithNeighbors_create_plunger_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
// @category:allocation
DotGateWithNeighborsHandle
DotGateWithNeighbors_create_barrier_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
// @category:deallocation
void DotGateWithNeighbors_destroy(DotGateWithNeighborsHandle handle);
// @category:read
bool DotGateWithNeighbors_equal(DotGateWithNeighborsHandle handle,
                                DotGateWithNeighborsHandle other);
// @category:read
bool DotGateWithNeighbors_not_equal(DotGateWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle other);
// @category:read
StringHandle DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle);
// @category:read
StringHandle DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle);
// @category:read
ConnectionHandle DotGateWithNeighbors_left_neighbor(
    DotGateWithNeighborsHandle handle);
// @category:read
ConnectionHandle DotGateWithNeighbors_right_neighbor(
    DotGateWithNeighborsHandle handle);
// @category:read
bool DotGateWithNeighbors_is_barrier_gate(DotGateWithNeighborsHandle handle);
// @category:read
bool DotGateWithNeighbors_is_plunger_gate(DotGateWithNeighborsHandle handle);
// @category:read
StringHandle DotGateWithNeighbors_to_json_string(
    DotGateWithNeighborsHandle handle);
// @category:allocation
DotGateWithNeighborsHandle DotGateWithNeighbors_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
