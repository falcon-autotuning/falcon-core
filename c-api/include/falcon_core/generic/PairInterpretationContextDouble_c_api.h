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

PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second);
void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle);
InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle);
double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle);
bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle a, PairInterpretationContextDoubleHandle b);
bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle a, PairInterpretationContextDoubleHandle b);
// Serialization (from Song)
StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle);
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif