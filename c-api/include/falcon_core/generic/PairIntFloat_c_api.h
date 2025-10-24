#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

PairIntFloatHandle PairIntFloat_create(int first, float second);
void PairIntFloat_destroy(PairIntFloatHandle handle);
int PairIntFloat_first(PairIntFloatHandle handle);
float PairIntFloat_second(PairIntFloatHandle handle);
bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b);
// Serialization (from Song)
StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle);
PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif