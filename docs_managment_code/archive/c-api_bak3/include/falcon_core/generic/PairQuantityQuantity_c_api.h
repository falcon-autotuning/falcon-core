#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairQuantityQuantityHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairQuantityQuantity_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second);
// @category:deallocation
void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairQuantityQuantity_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairQuantityQuantity_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle);
// @category:read
bool PairQuantityQuantity_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b);
// @category:read
bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b);
// @category:read
StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle);
// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif