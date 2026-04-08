#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second);
// @category:allocation
FALCON_CORE_C_API PairInterpretationContextDoubleHandle PairInterpretationContextDouble_copy(PairInterpretationContextDoubleHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif