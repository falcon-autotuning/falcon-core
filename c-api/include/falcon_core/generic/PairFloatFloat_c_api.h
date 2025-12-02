#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairFloatFloatHandle;
// Function declarations

/* AUTO-DOC from cpp: PairFloatFloat_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairFloatFloatHandle PairFloatFloat_create(float first, float second);
void PairFloatFloat_destroy(PairFloatFloatHandle handle);
/* AUTO-DOC from cpp: PairFloatFloat_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
float PairFloatFloat_first(PairFloatFloatHandle handle);
/* AUTO-DOC from cpp: PairFloatFloat_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
float PairFloatFloat_second(PairFloatFloatHandle handle);
bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);
bool PairFloatFloat_not_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);
// Serialization (from Song)
StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle);
PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif