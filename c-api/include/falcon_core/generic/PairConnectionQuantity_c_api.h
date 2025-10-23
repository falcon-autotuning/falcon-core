#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionQuantityHandle;
// Function declarations

PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second);
void PairConnectionQuantity_destroy(PairConnectionQuantityHandle handle);
ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle);
QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle);
bool PairConnectionQuantity_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b);
#ifdef __cplusplus
}
#endif