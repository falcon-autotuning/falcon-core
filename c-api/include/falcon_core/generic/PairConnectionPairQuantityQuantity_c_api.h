#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionPairQuantityQuantityHandle;
// Function declarations

PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create(ConnectionHandle first, PairQuantityQuantityHandle second);
void PairConnectionPairQuantityQuantity_destroy(PairConnectionPairQuantityQuantityHandle handle);
ConnectionHandle PairConnectionPairQuantityQuantity_first(PairConnectionPairQuantityQuantityHandle handle);
PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second(PairConnectionPairQuantityQuantityHandle handle);
bool PairConnectionPairQuantityQuantity_equal(PairConnectionPairQuantityQuantityHandle a, PairConnectionPairQuantityQuantityHandle b);
bool PairConnectionPairQuantityQuantity_not_equal(PairConnectionPairQuantityQuantityHandle a, PairConnectionPairQuantityQuantityHandle b);
// Serialization (from Song)
StringHandle      PairConnectionPairQuantityQuantity_to_json_string(PairConnectionPairQuantityQuantityHandle handle);
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif