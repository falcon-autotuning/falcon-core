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

PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second);
void PairConnectionFloat_destroy(PairConnectionFloatHandle handle);
ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle);
float PairConnectionFloat_second(PairConnectionFloatHandle handle);
bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);
bool PairConnectionFloat_not_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);
// Serialization (from Song)
StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle);
PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif