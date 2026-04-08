#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairDoubleDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second);
// @category:allocation
FALCON_CORE_C_API PairDoubleDoubleHandle PairDoubleDouble_copy(PairDoubleDoubleHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double PairDoubleDouble_first(PairDoubleDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double PairDoubleDouble_second(PairDoubleDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool PairDoubleDouble_equal(PairDoubleDoubleHandle handle, PairDoubleDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool PairDoubleDouble_not_equal(PairDoubleDoubleHandle handle, PairDoubleDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif