#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/PairDoubleDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Adjacency_c_api.h"
typedef void* VoltageConstraintsHandle;

// @category:allocation
VoltageConstraintsHandle VoltageConstraints_copy(
    VoltageConstraintsHandle handle);
// @category:deallocation
void VoltageConstraints_destroy(VoltageConstraintsHandle handle);
// @category:read
bool VoltageConstraints_equal(VoltageConstraintsHandle handle,
                              VoltageConstraintsHandle other);
// @category:read
bool VoltageConstraints_not_equal(VoltageConstraintsHandle handle,
                                  VoltageConstraintsHandle other);
// @category:read
StringHandle VoltageConstraints_to_json_string(VoltageConstraintsHandle handle);
// @category:allocation
VoltageConstraintsHandle VoltageConstraints_from_json_string(StringHandle json);
// @category:allocation
VoltageConstraintsHandle VoltageConstraints_create(
    AdjacencyHandle        adjacency,
    double                 max_safe_diff,
    PairDoubleDoubleHandle bounds);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_matrix |
 * falcon_core::physics::config::core::VoltageConstraints::matrix */
/**
 * @brief The constraint matrix.
 */
FArrayDoubleHandle VoltageConstraints_matrix(VoltageConstraintsHandle handle);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_adjacency |
 * falcon_core::physics::config::core::VoltageConstraints::adjacency */
/**
 * @brief The adjacency matrix used to understand the device layout.
 */
AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_limits |
 * falcon_core::physics::config::core::VoltageConstraints::limits */
/**
 * @brief The y axis vector safe voltage limits for each constraint.
 */
FArrayDoubleHandle VoltageConstraints_limits(VoltageConstraintsHandle handle);

#ifdef __cplusplus
}
#endif
