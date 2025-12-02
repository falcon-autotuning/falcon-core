#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextStringHandle;
// Function declarations

// @category:allocation
PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second);
// @category:deallocation
void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle);
// @category:read
InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle);
// @category:read
StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle);
// @category:read
bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b);
// @category:read
bool PairInterpretationContextString_not_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b);
// @category:read
StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle);
// @category:allocation
PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif