#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second);
// @category:allocation
FALCON_CORE_C_API PairConnectionDoubleHandle PairConnectionDouble_copy(PairConnectionDoubleHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double PairConnectionDouble_second(PairConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool PairConnectionDouble_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool PairConnectionDouble_not_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairConnectionDouble_to_json_string(PairConnectionDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API PairConnectionDoubleHandle PairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif