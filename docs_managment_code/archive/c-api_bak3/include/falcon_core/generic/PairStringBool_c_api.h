#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringBoolHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairStringBool_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairStringBoolHandle PairStringBool_create(StringHandle first, bool second);
// @category:deallocation
void PairStringBool_destroy(PairStringBoolHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairStringBool_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
StringHandle PairStringBool_first(PairStringBoolHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairStringBool_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
bool PairStringBool_second(PairStringBoolHandle handle);
// @category:read
bool PairStringBool_equal(PairStringBoolHandle a, PairStringBoolHandle b);
// @category:read
bool PairStringBool_not_equal(PairStringBoolHandle a, PairStringBoolHandle b);
// @category:read
StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle);
// @category:allocation
PairStringBoolHandle PairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif