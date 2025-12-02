#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairSizeTSizeTHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairSizeTSizeT_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second);
// @category:deallocation
void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairSizeTSizeT_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairSizeTSizeT_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle);
// @category:read
bool PairSizeTSizeT_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b);
// @category:read
bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b);
// @category:read
StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle);
// @category:allocation
PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif