#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
typedef void* DotGatesWithNeighborsHandle;

// Constructors
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty();
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create(
    ListDotGateWithNeighborsHandle items);

// Destructor
void DotGatesWithNeighbors_destroy(DotGatesWithNeighborsHandle handle);

// Methods
/* AUTO-DOC from cpp: DotGatesWithNeighbors_is_plunger_gates | falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_plunger_gates */
/**
 * @brief (from C++: falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_plunger_gates)
 * @brief Check if all connections are plunger gates.
 */
bool DotGatesWithNeighbors_is_plunger_gates(DotGatesWithNeighborsHandle handle);
/* AUTO-DOC from cpp: DotGatesWithNeighbors_is_barrier_gates | falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_barrier_gates */
/**
 * @brief (from C++: falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_barrier_gates)
 * @brief Check if all connections are barrier gates.
 */
bool DotGatesWithNeighbors_is_barrier_gates(DotGatesWithNeighborsHandle handle);
DotGatesWithNeighborsHandle DotGatesWithNeighbors_intersection(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other);
void   DotGatesWithNeighbors_push_back(DotGatesWithNeighborsHandle handle,
                                       DotGateWithNeighborsHandle  value);
size_t DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle);
bool   DotGatesWithNeighbors_empty(DotGatesWithNeighborsHandle handle);
void   DotGatesWithNeighbors_erase_at(DotGatesWithNeighborsHandle handle,
                                      size_t                      idx);
void   DotGatesWithNeighbors_clear(DotGatesWithNeighborsHandle handle);
const DotGateWithNeighborsHandle DotGatesWithNeighbors_const_at(
    DotGatesWithNeighborsHandle handle, size_t idx);
DotGateWithNeighborsHandle DotGatesWithNeighbors_at(
    DotGatesWithNeighborsHandle handle, size_t idx);
ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items(
    DotGatesWithNeighborsHandle handle);
bool   DotGatesWithNeighbors_contains(DotGatesWithNeighborsHandle handle,
                                      DotGateWithNeighborsHandle  value);
size_t DotGatesWithNeighbors_index(DotGatesWithNeighborsHandle handle,
                                   DotGateWithNeighborsHandle  value);
bool   DotGatesWithNeighbors_equal(DotGatesWithNeighborsHandle a,
                                   DotGatesWithNeighborsHandle b);
bool   DotGatesWithNeighbors_not_equal(DotGatesWithNeighborsHandle a,
                                       DotGatesWithNeighborsHandle b);

// Serialization (from Song)
StringHandle DotGatesWithNeighbors_to_json_string(
    DotGatesWithNeighborsHandle handle);
DotGatesWithNeighborsHandle DotGatesWithNeighbors_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
