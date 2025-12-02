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
VoltageConstraintsHandle VoltageConstraints_create(
    AdjacencyHandle        adjacency,
    double                 max_safe_diff,
    PairDoubleDoubleHandle bounds);
// @category:deallocation
void VoltageConstraints_destroy(VoltageConstraintsHandle handle);
// @category:read
FArrayDoubleHandle VoltageConstraints_matrix(VoltageConstraintsHandle handle);
// @category:read
AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle);
// @category:read
FArrayDoubleHandle VoltageConstraints_limits(VoltageConstraintsHandle handle);
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

#ifdef __cplusplus
}
#endif
