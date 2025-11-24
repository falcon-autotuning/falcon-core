#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionDoubleHandle;
// Function declarations

/* AUTO-DOC from cpp: PairConnectionDouble_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second);
void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle);
/* AUTO-DOC from cpp: PairConnectionDouble_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle);
/* AUTO-DOC from cpp: PairConnectionDouble_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
double PairConnectionDouble_second(PairConnectionDoubleHandle handle);
bool PairConnectionDouble_equal(PairConnectionDoubleHandle a, PairConnectionDoubleHandle b);
bool PairConnectionDouble_not_equal(PairConnectionDoubleHandle a, PairConnectionDoubleHandle b);
// Serialization (from Song)
StringHandle      PairConnectionDouble_to_json_string(PairConnectionDoubleHandle handle);
PairConnectionDoubleHandle PairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif