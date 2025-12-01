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

/* AUTO-DOC from cpp: PairConnectionQuantity_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second);
void PairConnectionQuantity_destroy(PairConnectionQuantityHandle handle);
/* AUTO-DOC from cpp: PairConnectionQuantity_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle);
/* AUTO-DOC from cpp: PairConnectionQuantity_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle);
bool PairConnectionQuantity_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b);
bool PairConnectionQuantity_not_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b);
// Serialization (from Song)
StringHandle      PairConnectionQuantity_to_json_string(PairConnectionQuantityHandle handle);
PairConnectionQuantityHandle PairConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif