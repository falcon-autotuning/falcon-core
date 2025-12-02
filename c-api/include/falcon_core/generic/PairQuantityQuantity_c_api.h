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

/* AUTO-DOC from cpp: PairQuantityQuantity_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second);
void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle);
/* AUTO-DOC from cpp: PairQuantityQuantity_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle);
/* AUTO-DOC from cpp: PairQuantityQuantity_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle);
bool PairQuantityQuantity_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b);
bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b);
// Serialization (from Song)
StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle);
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif