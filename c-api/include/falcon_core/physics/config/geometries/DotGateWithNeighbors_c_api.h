#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* DotGateWithNeighborsHandle;

// Constructors
DotGateWithNeighborsHandle DotGateWithNeighbors_create_plungergatewithneighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
DotGateWithNeighborsHandle DotGateWithNeighbors_create_barriergatewithneighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);

// Destructor
void DotGateWithNeighbors_destroy(DotGateWithNeighborsHandle handle);

// Methods
bool         DotGateWithNeighbors_equal(DotGateWithNeighborsHandle handle,
                                        DotGateWithNeighborsHandle other);
bool         DotGateWithNeighbors_not_equal(DotGateWithNeighborsHandle handle,
                                            DotGateWithNeighborsHandle other);
StringHandle DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle);
StringHandle DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle);
ConnectionHandle DotGateWithNeighbors_left_neighbor(
    DotGateWithNeighborsHandle handle);
ConnectionHandle DotGateWithNeighbors_right_neighbor(
    DotGateWithNeighborsHandle handle);
bool DotGateWithNeighbors_is_barrier_gate(DotGateWithNeighborsHandle handle);
bool DotGateWithNeighbors_is_plunger_gate(DotGateWithNeighborsHandle handle);

// Serialization (from Song)
StringHandle DotGateWithNeighbors_to_json_string(
    DotGateWithNeighborsHandle handle);
DotGateWithNeighborsHandle DotGateWithNeighbors_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
