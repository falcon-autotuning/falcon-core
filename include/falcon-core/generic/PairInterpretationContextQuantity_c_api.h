#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second);
// @category:allocation
FALCON_CORE_C_API PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_copy(PairInterpretationContextQuantityHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif