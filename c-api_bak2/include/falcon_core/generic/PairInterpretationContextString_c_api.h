#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextStringHandle;
// Function declarations

/* AUTO-DOC from cpp: PairInterpretationContextString_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second);
void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle);
/* AUTO-DOC from cpp: PairInterpretationContextString_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle);
/* AUTO-DOC from cpp: PairInterpretationContextString_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle);
bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b);
bool PairInterpretationContextString_not_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b);
// Serialization (from Song)
StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle);
PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif