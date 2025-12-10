#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextDoubleHandle;
// Function declarations

// @category:allocation
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second);
// @category:allocation
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_copy(PairInterpretationContextDoubleHandle handle);
// @category:deallocation
void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle);
// @category:read
InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle);
// @category:read
double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle);
// @category:read
bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other);
// @category:read
bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other);
// @category:read
StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle);
// @category:allocation
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif