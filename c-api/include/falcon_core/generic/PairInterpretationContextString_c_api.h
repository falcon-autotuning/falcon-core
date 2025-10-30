#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextStringHandle;
// Function declarations

PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second);
void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle);
InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle);
StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle);
bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b);
// Serialization (from Song)
StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle);
PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif