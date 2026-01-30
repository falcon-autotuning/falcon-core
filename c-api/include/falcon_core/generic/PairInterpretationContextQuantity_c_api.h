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

// @category:allocation
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second);
// @category:allocation
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_copy(PairInterpretationContextQuantityHandle handle);
// @category:deallocation
void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle);
// @category:read
InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle);
// @category:read
QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle);
// @category:read
bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other);
// @category:read
bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other);
// @category:read
StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle);
// @category:allocation
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif