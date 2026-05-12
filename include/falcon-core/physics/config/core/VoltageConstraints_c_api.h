#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/PairDoubleDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon-core/math/Point_c_api.h"
#include "falcon-core/math/domains/CoupledLabelledDomain_c_api.h"
#include "falcon-core/physics/config/core/Adjacency_c_api.h"
typedef void *VoltageConstraintsHandle;

// @category:allocation
FALCON_CORE_C_API VoltageConstraintsHandle
VoltageConstraints_copy(VoltageConstraintsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void
VoltageConstraints_destroy(VoltageConstraintsHandle handle);
// @category:read
FALCON_CORE_C_API bool VoltageConstraints_equal(VoltageConstraintsHandle handle,
                                                VoltageConstraintsHandle other);
// @category:read
FALCON_CORE_C_API bool
VoltageConstraints_not_equal(VoltageConstraintsHandle handle,
                             VoltageConstraintsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
VoltageConstraints_to_json_string(VoltageConstraintsHandle handle);
// @category:allocation
FALCON_CORE_C_API VoltageConstraintsHandle
VoltageConstraints_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API VoltageConstraintsHandle
VoltageConstraints_create(AdjacencyHandle adjacency, double max_safe_diff,
                          PairDoubleDoubleHandle bounds);
// @category:read
FALCON_CORE_C_API AdjacencyHandle
VoltageConstraints_adjacency(VoltageConstraintsHandle handle);
// @category:read
FALCON_CORE_C_API double
VoltageConstraints_max_safe_diff(VoltageConstraintsHandle handle);
// @category:read
FALCON_CORE_C_API double
VoltageConstraints_min_bound(VoltageConstraintsHandle handle);
// @category:read
FALCON_CORE_C_API double
VoltageConstraints_max_bound(VoltageConstraintsHandle handle);
// @category:read
FALCON_CORE_C_API CoupledLabelledDomainHandle
VoltageConstraints_compute_maximal_domain(
    VoltageConstraintsHandle handle, PortsHandle search_domain,
    DeviceVoltageStatesHandle current_state);
// @category:read
FALCON_CORE_C_API bool
VoltageConstraints_validate_voltage_state(VoltageConstraintsHandle handle,
                                          PointHandle voltage_state);

#ifdef __cplusplus
}
#endif
