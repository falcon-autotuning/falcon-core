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

// Constructors
GateGeometryArray1DHandle GateGeometryArray1D_create(
    ConnectionsHandle lineararray, ConnectionsHandle screening_gates);

// Destructor
void GateGeometryArray1D_destroy(GateGeometryArray1DHandle handle);

// Methods
void GateGeometryArray1D_append_central_gate(GateGeometryArray1DHandle handle,
                                             ConnectionHandle left_neighbor,
                                             ConnectionHandle selected_gate,
                                             ConnectionHandle right_neighbor);
DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates(
    GateGeometryArray1DHandle handle);
ConnectionsHandle GateGeometryArray1D_query_neighbors(
    GateGeometryArray1DHandle handle, ConnectionHandle gate);
LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle);
RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle);
DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle);
DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle);
ConnectionsHandle GateGeometryArray1D_lineararray(
    GateGeometryArray1DHandle handle);
ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle);
ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle);
DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle);
ConnectionsHandle GateGeometryArray1D_ohmics(GateGeometryArray1DHandle handle);
bool              GateGeometryArray1D_equal(GateGeometryArray1DHandle handle,
                                            GateGeometryArray1DHandle other);
bool GateGeometryArray1D_not_equal(GateGeometryArray1DHandle handle,
                                   GateGeometryArray1DHandle other);

// Serialization (from Song)
StringHandle GateGeometryArray1D_to_json_string(
    GateGeometryArray1DHandle handle);
GateGeometryArray1DHandle GateGeometryArray1D_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
