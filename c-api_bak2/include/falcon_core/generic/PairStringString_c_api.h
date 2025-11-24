#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringStringHandle;
// Function declarations

/* AUTO-DOC from cpp: PairStringString_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second);
void PairStringString_destroy(PairStringStringHandle handle);
/* AUTO-DOC from cpp: PairStringString_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
StringHandle PairStringString_first(PairStringStringHandle handle);
/* AUTO-DOC from cpp: PairStringString_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
StringHandle PairStringString_second(PairStringStringHandle handle);
bool PairStringString_equal(PairStringStringHandle a, PairStringStringHandle b);
bool PairStringString_not_equal(PairStringStringHandle a, PairStringStringHandle b);
// Serialization (from Song)
StringHandle      PairStringString_to_json_string(PairStringStringHandle handle);
PairStringStringHandle PairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif