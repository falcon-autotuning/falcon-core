#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

// @category:allocation
PairIntFloatHandle PairIntFloat_create(int first, float second);
// @category:allocation
PairIntFloatHandle PairIntFloat_copy(PairIntFloatHandle handle);
// @category:deallocation
void PairIntFloat_destroy(PairIntFloatHandle handle);
// @category:read
int PairIntFloat_first(PairIntFloatHandle handle);
// @category:read
float PairIntFloat_second(PairIntFloatHandle handle);
// @category:read
bool PairIntFloat_equal(PairIntFloatHandle handle, PairIntFloatHandle other);
// @category:read
bool PairIntFloat_not_equal(PairIntFloatHandle handle, PairIntFloatHandle other);
// @category:read
StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle);
// @category:allocation
PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif