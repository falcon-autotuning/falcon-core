

# File GateGeometryArray1D\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**GateGeometryArray1D\_c\_api.h**](GateGeometryArray1D__c__api_8h.md)

[Go to the documentation of this file](GateGeometryArray1D__c__api_8h.md)


```C++
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
GateGeometryArray1DHandle GateGeometryArray1D_copy(
    GateGeometryArray1DHandle handle);
// @category:deallocation
void GateGeometryArray1D_destroy(GateGeometryArray1DHandle handle);
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
// @category:allocation
GateGeometryArray1DHandle GateGeometryArray1D_create(
    ConnectionsHandle lineararray, ConnectionsHandle screening_gates);
// @category:write
/* AUTO-DOC from cpp: GateGeometryArray1D_append_central_gate |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::append_central_gate
 */
void GateGeometryArray1D_append_central_gate(GateGeometryArray1DHandle handle,
                                             ConnectionHandle left_neighbor,
                                             ConnectionHandle selected_gate,
                                             ConnectionHandle right_neighbor);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_all_dot_gates |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::all_dot_gates
 */
DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_query_neighbors |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::query_neighbors
 */
ConnectionsHandle GateGeometryArray1D_query_neighbors(
    GateGeometryArray1DHandle handle, ConnectionHandle gate);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_left_reservoir |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::left_reservoir
 */
LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_right_reservoir |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::right_reservoir
 */
RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_left_barrier |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::left_barrier
 */
DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_right_barrier |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::right_barrier
 */
DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle);
// @category:read
ConnectionsHandle GateGeometryArray1D_linear_array(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_screening_gates |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::screening_gates
 */
ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_raw_central_gates |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::raw_central_gates
 */
ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_central_dot_gates |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::central_dot_gates
 */
DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: GateGeometryArray1D_ohmics |
 * falcon_core::physics::config::geometries::GateGeometryArray1D::ohmics */
ConnectionsHandle GateGeometryArray1D_ohmics(GateGeometryArray1DHandle handle);

#ifdef __cplusplus
}
#endif
```


