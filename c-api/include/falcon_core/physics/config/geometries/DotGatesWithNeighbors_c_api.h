#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
typedef void* DotGatesWithNeighborsHandle;

// @category:allocation
FALCON_CORE_C_API DotGatesWithNeighborsHandle
DotGatesWithNeighbors_copy(DotGatesWithNeighborsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void DotGatesWithNeighbors_destroy(
    DotGatesWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API bool DotGatesWithNeighbors_equal(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other);
// @category:read
FALCON_CORE_C_API bool DotGatesWithNeighbors_not_equal(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
DotGatesWithNeighbors_to_json_string(DotGatesWithNeighborsHandle handle);
// @category:allocation
FALCON_CORE_C_API DotGatesWithNeighborsHandle
DotGatesWithNeighbors_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API DotGatesWithNeighborsHandle
DotGatesWithNeighbors_create_empty();
// @category:allocation
FALCON_CORE_C_API DotGatesWithNeighborsHandle
DotGatesWithNeighbors_create(ListDotGateWithNeighborsHandle items);
// @category:read
/* AUTO-DOC from cpp: DotGatesWithNeighbors_is_plunger_gates |
 * falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_plunger_gates
 */
/**
 * @brief Check if all connections are plunger gates.
 */
FALCON_CORE_C_API bool DotGatesWithNeighbors_is_plunger_gates(
    DotGatesWithNeighborsHandle handle);
// @category:read
/* AUTO-DOC from cpp: DotGatesWithNeighbors_is_barrier_gates |
 * falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_barrier_gates
 */
/**
 * @brief Check if all connections are barrier gates.
 */
FALCON_CORE_C_API bool DotGatesWithNeighbors_is_barrier_gates(
    DotGatesWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API DotGatesWithNeighborsHandle
DotGatesWithNeighbors_intersection(DotGatesWithNeighborsHandle handle,
                                   DotGatesWithNeighborsHandle other);
// @category:write
FALCON_CORE_C_API void DotGatesWithNeighbors_push_back(
    DotGatesWithNeighborsHandle handle, DotGateWithNeighborsHandle value);
// @category:read
FALCON_CORE_C_API size_t
DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API bool DotGatesWithNeighbors_empty(
    DotGatesWithNeighborsHandle handle);
// @category:write
FALCON_CORE_C_API void DotGatesWithNeighbors_erase_at(
    DotGatesWithNeighborsHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void DotGatesWithNeighbors_clear(
    DotGatesWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API DotGateWithNeighborsHandle
DotGatesWithNeighbors_at(DotGatesWithNeighborsHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API ListDotGateWithNeighborsHandle
DotGatesWithNeighbors_items(DotGatesWithNeighborsHandle handle);
// @category:read
FALCON_CORE_C_API bool DotGatesWithNeighbors_contains(
    DotGatesWithNeighborsHandle handle, DotGateWithNeighborsHandle value);
// @category:read
FALCON_CORE_C_API size_t DotGatesWithNeighbors_index(
    DotGatesWithNeighborsHandle handle, DotGateWithNeighborsHandle value);

#ifdef __cplusplus
}
#endif
