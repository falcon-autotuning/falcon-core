#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/PairDoubleDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/config/core/Adjacency_c_api.h"
typedef void* VoltageConstraintsHandle;

// @category:allocation
FALCON_CORE_C_API VoltageConstraintsHandle
VoltageConstraints_copy(VoltageConstraintsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void VoltageConstraints_destroy(
    VoltageConstraintsHandle handle);
// @category:read
FALCON_CORE_C_API bool VoltageConstraints_equal(VoltageConstraintsHandle handle,
                                                VoltageConstraintsHandle other);
// @category:read
FALCON_CORE_C_API bool VoltageConstraints_not_equal(
    VoltageConstraintsHandle handle, VoltageConstraintsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
VoltageConstraints_to_json_string(VoltageConstraintsHandle handle);
// @category:allocation
FALCON_CORE_C_API VoltageConstraintsHandle
VoltageConstraints_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API VoltageConstraintsHandle
VoltageConstraints_create(AdjacencyHandle        adjacency,
                          double                 max_safe_diff,
                          PairDoubleDoubleHandle bounds);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_matrix |
 * falcon_core::physics::config::core::VoltageConstraints::matrix */
/**
 * @brief The constraint matrix.
 */
FALCON_CORE_C_API FArrayDoubleHandle
VoltageConstraints_matrix(VoltageConstraintsHandle handle);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_adjacency |
 * falcon_core::physics::config::core::VoltageConstraints::adjacency */
/**
 * @brief The adjacency matrix used to understand the device layout.
 */
FALCON_CORE_C_API AdjacencyHandle
VoltageConstraints_adjacency(VoltageConstraintsHandle handle);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_limits |
 * falcon_core::physics::config::core::VoltageConstraints::limits */
/**
 * @brief The y axis vector safe voltage limits for each constraint.
 */
FALCON_CORE_C_API FArrayDoubleHandle
VoltageConstraints_limits(VoltageConstraintsHandle handle);

#ifdef __cplusplus
}
#endif
