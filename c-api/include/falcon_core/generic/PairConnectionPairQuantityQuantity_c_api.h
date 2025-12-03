#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionPairQuantityQuantityHandle;
// Function declarations

// @category:allocation
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create(ConnectionHandle first, PairQuantityQuantityHandle second);
// @category:deallocation
void PairConnectionPairQuantityQuantity_destroy(PairConnectionPairQuantityQuantityHandle handle);
// @category:read
ConnectionHandle PairConnectionPairQuantityQuantity_first(PairConnectionPairQuantityQuantityHandle handle);
// @category:read
PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second(PairConnectionPairQuantityQuantityHandle handle);
// @category:read
bool PairConnectionPairQuantityQuantity_equal(PairConnectionPairQuantityQuantityHandle a, PairConnectionPairQuantityQuantityHandle b);
// @category:read
bool PairConnectionPairQuantityQuantity_not_equal(PairConnectionPairQuantityQuantityHandle a, PairConnectionPairQuantityQuantityHandle b);
// @category:read
StringHandle      PairConnectionPairQuantityQuantity_to_json_string(PairConnectionPairQuantityQuantityHandle handle);
// @category:allocation
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif