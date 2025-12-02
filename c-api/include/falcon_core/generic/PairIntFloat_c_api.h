#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairIntFloat_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairIntFloatHandle PairIntFloat_create(int first, float second);
// @category:deallocation
void PairIntFloat_destroy(PairIntFloatHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairIntFloat_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
int PairIntFloat_first(PairIntFloatHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairIntFloat_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
float PairIntFloat_second(PairIntFloatHandle handle);
// @category:read
bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b);
// @category:read
bool PairIntFloat_not_equal(PairIntFloatHandle a, PairIntFloatHandle b);
// @category:read
StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle);
// @category:allocation
PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif