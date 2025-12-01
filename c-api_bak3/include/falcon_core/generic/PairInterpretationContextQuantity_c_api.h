#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextQuantityHandle;
// Function declarations

/* AUTO-DOC from cpp: PairInterpretationContextQuantity_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second);
void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle);
/* AUTO-DOC from cpp: PairInterpretationContextQuantity_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle);
/* AUTO-DOC from cpp: PairInterpretationContextQuantity_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle);
bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle a, PairInterpretationContextQuantityHandle b);
bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle a, PairInterpretationContextQuantityHandle b);
// Serialization (from Song)
StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle);
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif