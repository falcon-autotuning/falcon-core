#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextQuantityHandle;
// Function declarations

PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second);
void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle);
InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle);
QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle);
bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle a, PairInterpretationContextQuantityHandle b);
bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle a, PairInterpretationContextQuantityHandle b);
// Serialization (from Song)
StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle);
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif