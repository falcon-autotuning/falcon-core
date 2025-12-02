#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionFloatHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairConnectionFloat_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second);
// @category:deallocation
void PairConnectionFloat_destroy(PairConnectionFloatHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairConnectionFloat_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairConnectionFloat_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
float PairConnectionFloat_second(PairConnectionFloatHandle handle);
// @category:read
bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);
// @category:read
bool PairConnectionFloat_not_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);
// @category:read
StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle);
// @category:allocation
PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif