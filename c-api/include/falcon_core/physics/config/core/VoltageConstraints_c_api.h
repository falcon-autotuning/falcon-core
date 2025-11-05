#pragma once
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/physics/config/core/Adjacency_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/PairDoubleDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* VoltageConstraintsHandle;

// Constructors
VoltageConstraintsHandle VoltageConstraints_create(
    AdjacencyHandle        adjacency,
    double                 max_safe_diff,
    PairDoubleDoubleHandle bounds);

// Destructor
void VoltageConstraints_destroy(VoltageConstraintsHandle handle);

// Methods
FArrayDoubleHandle VoltageConstraints_matrix(VoltageConstraintsHandle handle);
AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle);
FArrayDoubleHandle VoltageConstraints_limits(VoltageConstraintsHandle handle);
bool               VoltageConstraints_equal(VoltageConstraintsHandle a,
                                            VoltageConstraintsHandle b);
bool               VoltageConstraints_not_equal(VoltageConstraintsHandle a,
                                                VoltageConstraintsHandle b);

// Serialization (from Song)
StringHandle VoltageConstraints_to_json_string(VoltageConstraintsHandle handle);
VoltageConstraintsHandle VoltageConstraints_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
