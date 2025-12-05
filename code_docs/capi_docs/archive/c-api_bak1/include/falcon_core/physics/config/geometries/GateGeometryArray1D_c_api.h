#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h"
#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
typedef void* GateGeometryArray1DHandle;

// @category:allocation
GateGeometryArray1DHandle GateGeometryArray1D_create(
    ConnectionsHandle lineararray, ConnectionsHandle screening_gates);
// @category:deallocation
void GateGeometryArray1D_destroy(GateGeometryArray1DHandle handle);
// @category:write
void GateGeometryArray1D_append_central_gate(GateGeometryArray1DHandle handle,
                                             ConnectionHandle left_neighbor,
                                             ConnectionHandle selected_gate,
                                             ConnectionHandle right_neighbor);
// @category:read
DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_query_neighbors(
    GateGeometryArray1DHandle handle, ConnectionHandle gate);
// @category:read
LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle);
// @category:read
RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle);
// @category:read
DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle);
// @category:read
DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_linear_array(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle);
// @category:read
DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_ohmics(GateGeometryArray1DHandle handle);
// @category:read
bool GateGeometryArray1D_equal(GateGeometryArray1DHandle handle,
                               GateGeometryArray1DHandle other);
// @category:read
bool GateGeometryArray1D_not_equal(GateGeometryArray1DHandle handle,
                                   GateGeometryArray1DHandle other);
// @category:read
StringHandle GateGeometryArray1D_to_json_string(
    GateGeometryArray1DHandle handle);
// @category:allocation
GateGeometryArray1DHandle GateGeometryArray1D_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
