#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairQuantityQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second);
// @category:allocation
FALCON_CORE_C_API PairQuantityQuantityHandle PairQuantityQuantity_copy(PairQuantityQuantityHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool PairQuantityQuantity_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif