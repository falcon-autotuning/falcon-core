#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextDoubleHandle;
// Function declarations

/* AUTO-DOC from cpp: PairInterpretationContextDouble_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second);
void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle);
/* AUTO-DOC from cpp: PairInterpretationContextDouble_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle);
/* AUTO-DOC from cpp: PairInterpretationContextDouble_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle);
bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle a, PairInterpretationContextDoubleHandle b);
bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle a, PairInterpretationContextDoubleHandle b);
// Serialization (from Song)
StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle);
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif