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
/* AUTO-DOC from cpp: GateGeometryArray1D_append_central_gate | falcon_core::physics::config::geometries::GateGeometryArray1D::append_central_gate */
/**
 * @brief Appends a central gate to the geometry.
 * @param gate The gate to append.
 */
void GateGeometryArray1D_append_central_gate(GateGeometryArray1DHandle handle,
                                             ConnectionHandle left_neighbor,
                                             ConnectionHandle selected_gate,
                                             ConnectionHandle right_neighbor);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_all_dot_gates | falcon_core::physics::config::geometries::GateGeometryArray1D::all_dot_gates */
/**
 * @brief Gets all of the dot gates in the geometry
 * @return A collection of all dot gates in the array with localities.
 */
DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_query_neighbors | falcon_core::physics::config::geometries::GateGeometryArray1D::query_neighbors */
/**
 * @brief Queries the neighbors of a gate
 * @param gate The gate to query neighbors for
 * @return The collection of neighboring gates
 */
ConnectionsHandle GateGeometryArray1D_query_neighbors(
    GateGeometryArray1DHandle handle, ConnectionHandle gate);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_left_reservoir | falcon_core::physics::config::geometries::GateGeometryArray1D::left_reservoir */
/**
 * @brief Gets the left reservoir with implanted ohmic contact.
 * @return The left reservoir with implanted ohmic contact.
 */
LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_right_reservoir | falcon_core::physics::config::geometries::GateGeometryArray1D::right_reservoir */
/**
 * @brief Gets the right reservoir with implanted ohmic contact.
 * @return The right reservoir with implanted ohmic contact.
 */
RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_left_barrier | falcon_core::physics::config::geometries::GateGeometryArray1D::left_barrier */
/**
 * @brief Gets the leftmost barrier gate in the array.
 * @return The leftmost barrier gate.
 */
DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_right_barrier | falcon_core::physics::config::geometries::GateGeometryArray1D::right_barrier */
/**
 * @brief Gets the rightmost barrier gate in the array.
 * @return The rightmost barrier gate.
 */
DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_linear_array(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_screening_gates | falcon_core::physics::config::geometries::GateGeometryArray1D::screening_gates */
/**
 * @brief Gets the screening gates in the geometry.
 * @return The screening gates in the geometry.
 */
ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_raw_central_gates | falcon_core::physics::config::geometries::GateGeometryArray1D::raw_central_gates */
/**
 * @brief Gets the central gates without localities.
 * @return The central gates without localities.
 */
ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_central_dot_gates | falcon_core::physics::config::geometries::GateGeometryArray1D::central_dot_gates */
/**
 * @brief Gets the central gates with localities.
 * @return The central gates with localities.
 */
DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_ohmics | falcon_core::physics::config::geometries::GateGeometryArray1D::ohmics */
/**
 * @brief Gets the ohmics attached the the quantum dot geometry.
 * @return The ohmics attached to the quantum dot geometry.
 */
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
