#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"

#include <falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"

using namespace falcon_core::physics::config::geometries;

extern "C" {
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty() {
  FALCON_C_API_BEGIN
  return new DotGatesWithNeighbors(DotGatesWithNeighbors());
  FALCON_C_API_END(nullptr)
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_create(
    ListDotGateWithNeighborsHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_create: items cannot be null");
  }
  falcon_core::generic::List<DotGateWithNeighbors> list =
      *static_cast<falcon_core::generic::List<DotGateWithNeighbors>*>(items);
  return new DotGatesWithNeighbors(DotGatesWithNeighbors(list.items()));
  FALCON_C_API_END(nullptr)
}

// Destructor
void DotGatesWithNeighbors_destroy(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_destroy: handle cannot be null");
  }
  delete static_cast<DotGatesWithNeighbors*>(handle);
  FALCON_C_API_END()
}

// Methods
bool DotGatesWithNeighbors_is_plunger_gates(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_is_plunger_gates: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.is_plunger_gates();
  FALCON_C_API_END(false)
}

bool DotGatesWithNeighbors_is_barrier_gates(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_is_barrier_gates: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.is_barrier_gates();
  FALCON_C_API_END(false)
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_intersection(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_intersection: other cannot be null");
  }
  DotGatesWithNeighbors   self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGatesWithNeighborsSP real_other = std::make_shared<DotGatesWithNeighbors>(
      *static_cast<DotGatesWithNeighbors*>(other));
  return new DotGatesWithNeighbors(self.intersection(real_other)->items());
  FALCON_C_API_END(nullptr)
}

void DotGatesWithNeighbors_push_back(DotGatesWithNeighborsHandle handle,
                                     DotGateWithNeighborsHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_push_back: value cannot be null");
  }
  DotGatesWithNeighbors* self = static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighborsSP real_value = std::make_shared<DotGateWithNeighbors>(
      *static_cast<DotGateWithNeighbors*>(value));
  self->push_back(real_value);
  FALCON_C_API_END()
}

size_t DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_size: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.size();
  FALCON_C_API_END(0)
}

bool DotGatesWithNeighbors_empty(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_empty: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return self.empty();
  FALCON_C_API_END(false)
}

void DotGatesWithNeighbors_erase_at(DotGatesWithNeighborsHandle handle,
                                    size_t                      idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_erase_at: handle cannot be null");
  }
  DotGatesWithNeighbors* self = static_cast<DotGatesWithNeighbors*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void DotGatesWithNeighbors_clear(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_clear: handle cannot be null");
  }
  DotGatesWithNeighbors* self = static_cast<DotGatesWithNeighbors*>(handle);
  self->clear();
  FALCON_C_API_END()
}

const DotGateWithNeighborsHandle DotGatesWithNeighbors_const_at(
    DotGatesWithNeighborsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_const_at: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return new DotGateWithNeighbors(*(self.at(idx)));
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle DotGatesWithNeighbors_at(
    DotGatesWithNeighborsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_at: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return new DotGateWithNeighbors(*(self.at(idx)));
  FALCON_C_API_END(nullptr)
}

ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_items: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return new falcon_core::generic::List<DotGateWithNeighbors>(self.items());
  FALCON_C_API_END(nullptr)
}

bool DotGatesWithNeighbors_contains(DotGatesWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_contains: value cannot be null");
  }
  DotGatesWithNeighbors  self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighborsSP real_value = std::make_shared<DotGateWithNeighbors>(
      *static_cast<DotGateWithNeighbors*>(value));
  return self.contains(real_value);
  FALCON_C_API_END(false)
}

size_t DotGatesWithNeighbors_index(DotGatesWithNeighborsHandle handle,
                                   DotGateWithNeighborsHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_index: value cannot be null");
  }
  DotGatesWithNeighbors  self = *static_cast<DotGatesWithNeighbors*>(handle);
  DotGateWithNeighborsSP real_value = std::make_shared<DotGateWithNeighbors>(
      *static_cast<DotGateWithNeighbors*>(value));
  return self.index(real_value);
  FALCON_C_API_END(0)
}

bool DotGatesWithNeighbors_equal(DotGatesWithNeighborsHandle a,
                                 DotGatesWithNeighborsHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_equal: second handle cannot be null");
  }
  DotGatesWithNeighbors self       = *static_cast<DotGatesWithNeighbors*>(a);
  DotGatesWithNeighbors real_other = *static_cast<DotGatesWithNeighbors*>(b);
  return self == real_other;
  FALCON_C_API_END(false)
}

bool DotGatesWithNeighbors_not_equal(DotGatesWithNeighborsHandle a,
                                     DotGatesWithNeighborsHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_not_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_not_equal: second handle cannot be null");
  }
  DotGatesWithNeighbors self       = *static_cast<DotGatesWithNeighbors*>(a);
  DotGatesWithNeighbors real_other = *static_cast<DotGatesWithNeighbors*>(b);
  return self != real_other;
  FALCON_C_API_END(false)
}

StringHandle DotGatesWithNeighbors_to_json_string(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_to_json_string: handle cannot be null");
  }
  DotGatesWithNeighbors self = *static_cast<DotGatesWithNeighbors*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
  FALCON_C_API_END(nullptr)
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_from_json_string: json cannot be null");
  }
  std::string real_json(json->raw, json->length);
  return new DotGatesWithNeighbors(
      DotGatesWithNeighbors::from_json_string<DotGatesWithNeighbors>(real_json)
          ->items());
  FALCON_C_API_END(nullptr)
}
}
