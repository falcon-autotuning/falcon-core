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
FALCON_CORE_C_API PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second);
// @category:allocation
FALCON_CORE_C_API PairInterpretationContextStringHandle PairInterpretationContextString_copy(PairInterpretationContextStringHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle other);
// @category:read
FALCON_CORE_C_API bool PairInterpretationContextString_not_equal(PairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle);
// @category:allocation
FALCON_CORE_C_API PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif