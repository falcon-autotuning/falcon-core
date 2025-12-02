#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionHandle;
// Function declarations

/* AUTO-DOC from cpp: PairConnectionConnection_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second);
void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle);
/* AUTO-DOC from cpp: PairConnectionConnection_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle);
/* AUTO-DOC from cpp: PairConnectionConnection_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle);
bool PairConnectionConnection_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b);
bool PairConnectionConnection_not_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b);
// Serialization (from Song)
StringHandle      PairConnectionConnection_to_json_string(PairConnectionConnectionHandle handle);
PairConnectionConnectionHandle PairConnectionConnection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif