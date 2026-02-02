#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second);
// @category:allocation
FALCON_CORE_C_API PairConnectionQuantityHandle PairConnectionQuantity_copy(PairConnectionQuantityHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairConnectionQuantity_destroy(PairConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool PairConnectionQuantity_equal(PairConnectionQuantityHandle handle, PairConnectionQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool PairConnectionQuantity_not_equal(PairConnectionQuantityHandle handle, PairConnectionQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairConnectionQuantity_to_json_string(PairConnectionQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API PairConnectionQuantityHandle PairConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif