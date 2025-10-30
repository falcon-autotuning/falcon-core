#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"

#include <falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::physics::config::geometries;

extern "C" {

DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty() {
  return new DotGatesWithNeighbors(DotGatesWithNeighbors());
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_create(
    ListDotGateWithNeighborsHandle items) {
  falcon_core::generic::List<DotGateWithNeighbors> list =
      *static_cast<falcon_core::generic::List<DotGateWithNeighbors>*>(items);
  return new DotGatesWithNeighbors(DotGatesWithNeighbors(list.items()));
}

// Destructor
void DotGatesWithNeighbors_destroy(DotGatesWithNeighborsHandle handle) {
  delete static_cast<DotGatesWithNeighbors*>(handle);
}

// Methods
bool DotGatesWithNeighbors_is_plunger_gates(
    DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.is_plunger_gates();
}

bool DotGatesWithNeighbors_is_barrier_gates(
    DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.is_barrier_gates();
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_intersection(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGatesWithNeighbors real_other =
      *static_cast<DotGatesWithNeighbors*>(other);
}

void DotGatesWithNeighbors_push_back(DotGatesWithNeighborsHandle handle,
                                     DotGateWithNeighborsHandle  value) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighbors  real_value = *static_cast<DotGateWithNeighbors*>(value);
}
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
