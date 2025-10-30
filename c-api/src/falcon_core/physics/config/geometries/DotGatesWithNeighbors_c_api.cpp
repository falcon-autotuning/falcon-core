#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"

#include <falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"

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
  DotGatesWithNeighbors   self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGatesWithNeighborsSP real_other = std::make_shared<DotGatesWithNeighbors>(
      *static_cast<DotGatesWithNeighbors*>(other));
  return new DotGatesWithNeighbors(self.intersection(real_other)->items());
}

void DotGatesWithNeighbors_push_back(DotGatesWithNeighborsHandle handle,
                                     DotGateWithNeighborsHandle  value) {
  DotGatesWithNeighbors  self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighborsSP real_value = std::make_shared<DotGateWithNeighbors>(
      *static_cast<DotGateWithNeighbors*>(value));
  self.push_back(real_value);
}

size_t DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.size();
}

bool DotGatesWithNeighbors_empty(DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.empty();
}

void DotGatesWithNeighbors_erase_at(DotGatesWithNeighborsHandle handle,
                                    size_t                      idx) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  self.erase_at(idx);
}

void DotGatesWithNeighbors_clear(DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  self.clear();
}

const DotGateWithNeighborsHandle DotGatesWithNeighbors_const_at(
    DotGatesWithNeighborsHandle handle, size_t idx) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return new DotGateWithNeighbors(*(self.at(idx)));
}

DotGateWithNeighborsHandle DotGatesWithNeighbors_at(
    DotGatesWithNeighborsHandle handle, size_t idx) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return new DotGateWithNeighbors(*(self.at(idx)));
}

ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items(
    DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return new falcon_core::generic::List<DotGateWithNeighbors>(self.items());
}

bool DotGatesWithNeighbors_contains(DotGatesWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle  value) {
  DotGatesWithNeighbors  self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighborsSP real_value = std::make_shared<DotGateWithNeighbors>(
      *static_cast<DotGateWithNeighbors*>(value));
  return self.contains(real_value);
}

size_t DotGatesWithNeighbors_index(DotGatesWithNeighborsHandle handle,
                                   DotGateWithNeighborsHandle  value) {
  DotGatesWithNeighbors  self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighborsSP real_value = std::make_shared<DotGateWithNeighbors>(
      *static_cast<DotGateWithNeighbors*>(value));
  return self.index(real_value);
}

bool DotGatesWithNeighbors_equal(DotGatesWithNeighborsHandle a,
                                 DotGatesWithNeighborsHandle b) {
  DotGatesWithNeighbors self       = *static_cast<DotGatesWithNeighbors*>(a);
  DotGatesWithNeighbors real_other = *static_cast<DotGatesWithNeighbors*>(b);
  return self == real_other;
}

bool DotGatesWithNeighbors_not_equal(DotGatesWithNeighborsHandle a,
                                     DotGatesWithNeighborsHandle b) {
  DotGatesWithNeighbors self       = *static_cast<DotGatesWithNeighbors*>(a);
  DotGatesWithNeighbors real_other = *static_cast<DotGatesWithNeighbors*>(b);
  return self == real_other;
}

StringHandle DotGatesWithNeighbors_to_json_string(
    DotGatesWithNeighborsHandle handle) {
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_from_json_string(
    StringHandle json) {
  std::string real_json(json->raw, json->length);
  return new DotGatesWithNeighbors(
      DotGatesWithNeighbors::from_json_string<DotGatesWithNeighbors>(real_json)
          ->items());
}
#ifdef __cplusplus
}
#endif
