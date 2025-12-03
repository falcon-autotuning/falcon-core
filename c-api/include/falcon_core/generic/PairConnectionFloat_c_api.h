#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionFloatHandle;
// Function declarations

// @category:allocation
PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second);
// @category:deallocation
void PairConnectionFloat_destroy(PairConnectionFloatHandle handle);
// @category:read
ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle);
// @category:read
float PairConnectionFloat_second(PairConnectionFloatHandle handle);
// @category:read
bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);
// @category:read
bool PairConnectionFloat_not_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);
// @category:read
StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle);
// @category:allocation
PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif