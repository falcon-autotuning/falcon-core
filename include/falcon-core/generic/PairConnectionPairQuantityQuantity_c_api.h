#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/generic/PairQuantityQuantity_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionPairQuantityQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create(ConnectionHandle first, PairQuantityQuantityHandle second);
// @category:allocation
FALCON_CORE_C_API PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_copy(PairConnectionPairQuantityQuantityHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairConnectionPairQuantityQuantity_destroy(PairConnectionPairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionPairQuantityQuantity_first(PairConnectionPairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second(PairConnectionPairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool PairConnectionPairQuantityQuantity_equal(PairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool PairConnectionPairQuantityQuantity_not_equal(PairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairConnectionPairQuantityQuantity_to_json_string(PairConnectionPairQuantityQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif