#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
typedef void* DotGatesWithNeighborsHandle;

// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty();
// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create(
    ListDotGateWithNeighborsHandle items);
// @category:deallocation
void DotGatesWithNeighbors_destroy(DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_is_plunger_gates(DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_is_barrier_gates(DotGatesWithNeighborsHandle handle);
// @category:read
DotGatesWithNeighborsHandle DotGatesWithNeighbors_intersection(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other);
// @category:write
void DotGatesWithNeighbors_push_back(DotGatesWithNeighborsHandle handle,
                                     DotGateWithNeighborsHandle  value);
// @category:read
size_t DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_empty(DotGatesWithNeighborsHandle handle);
// @category:write
void DotGatesWithNeighbors_erase_at(DotGatesWithNeighborsHandle handle,
                                    size_t                      idx);
// @category:write
void DotGatesWithNeighbors_clear(DotGatesWithNeighborsHandle handle);
// @category:read
DotGateWithNeighborsHandle DotGatesWithNeighbors_at(
    DotGatesWithNeighborsHandle handle, size_t idx);
// @category:read
ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items(
    DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_contains(DotGatesWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle  value);
// @category:read
size_t DotGatesWithNeighbors_index(DotGatesWithNeighborsHandle handle,
                                   DotGateWithNeighborsHandle  value);
// @category:read
bool DotGatesWithNeighbors_equal(DotGatesWithNeighborsHandle handle,
                                 DotGatesWithNeighborsHandle other);
// @category:read
bool DotGatesWithNeighbors_not_equal(DotGatesWithNeighborsHandle handle,
                                     DotGatesWithNeighborsHandle other);
// @category:read
StringHandle DotGatesWithNeighbors_to_json_string(
    DotGatesWithNeighborsHandle handle);
// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
