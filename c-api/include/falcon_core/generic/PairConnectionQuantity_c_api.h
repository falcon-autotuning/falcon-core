#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionQuantityHandle;
// Function declarations

PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second);
void PairConnectionQuantity_destroy(PairConnectionQuantityHandle handle);
ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle);
QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle);
bool PairConnectionQuantity_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b);
bool PairConnectionQuantity_not_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b);
// Serialization (from Song)
StringHandle      PairConnectionQuantity_to_json_string(PairConnectionQuantityHandle handle);
PairConnectionQuantityHandle PairConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif