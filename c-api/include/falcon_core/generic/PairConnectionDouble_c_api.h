#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionDoubleHandle;
// Function declarations

PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second);
void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle);
ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle);
double PairConnectionDouble_second(PairConnectionDoubleHandle handle);
bool PairConnectionDouble_equal(PairConnectionDoubleHandle a, PairConnectionDoubleHandle b);
// Serialization (from Song)
StringHandle      PairConnectionDouble_to_json_string(PairConnectionDoubleHandle handle);
PairConnectionDoubleHandle PairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif