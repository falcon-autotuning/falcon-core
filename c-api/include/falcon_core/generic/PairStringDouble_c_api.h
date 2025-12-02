#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringDoubleHandle;
// Function declarations

/* AUTO-DOC from cpp: PairStringDouble_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second);
void PairStringDouble_destroy(PairStringDoubleHandle handle);
/* AUTO-DOC from cpp: PairStringDouble_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
StringHandle PairStringDouble_first(PairStringDoubleHandle handle);
/* AUTO-DOC from cpp: PairStringDouble_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
double PairStringDouble_second(PairStringDoubleHandle handle);
bool PairStringDouble_equal(PairStringDoubleHandle a, PairStringDoubleHandle b);
bool PairStringDouble_not_equal(PairStringDoubleHandle a, PairStringDoubleHandle b);
// Serialization (from Song)
StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle);
PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif