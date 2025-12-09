#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"

#include <falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core::physics::config::geometries;

extern "C" {
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty() {
  FALCON_C_API_BEGIN
  return new DotGatesWithNeighborsSP(std::make_shared<DotGatesWithNeighbors>());
  FALCON_C_API_END(nullptr)
}

DotGatesWithNeighborsHandle DotGatesWithNeighbors_create(
    ListDotGateWithNeighborsHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_create: items cannot be null");
  }
  falcon_core::generic::ListSP<DotGateWithNeighbors> list =
      *static_cast<falcon_core::generic::ListSP<DotGateWithNeighbors>*>(items);
  return new DotGatesWithNeighborsSP(
      std::make_shared<DotGatesWithNeighbors>(list->items()));
  FALCON_C_API_END(nullptr)
}

// Destructor
void DotGatesWithNeighbors_destroy(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_destroy: handle cannot be null");
  }
  delete static_cast<DotGatesWithNeighborsSP*>(handle);
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
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return self->is_plunger_gates();
  FALCON_C_API_END(false)
}

bool DotGatesWithNeighbors_is_barrier_gates(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_is_barrier_gates: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return self->is_barrier_gates();
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
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  DotGatesWithNeighborsSP real_other =
      *static_cast<DotGatesWithNeighborsSP*>(other);
  return new DotGatesWithNeighborsSP(std::make_shared<DotGatesWithNeighbors>(
      self->intersection(real_other)->items()));
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
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  DotGateWithNeighborsSP  real_value =
      *static_cast<DotGateWithNeighborsSP*>(value);
  self->push_back(real_value);
  FALCON_C_API_END()
}

size_t DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_size: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool DotGatesWithNeighbors_empty(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_empty: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void DotGatesWithNeighbors_erase_at(DotGatesWithNeighborsHandle handle,
                                    size_t                      idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_erase_at: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void DotGatesWithNeighbors_clear(DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_clear: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
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
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return new DotGateWithNeighborsSP(self->at(idx));
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle DotGatesWithNeighbors_at(
    DotGatesWithNeighborsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_at: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return new DotGateWithNeighborsSP(self->at(idx));
  FALCON_C_API_END(nullptr)
}

ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_items: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return new falcon_core::generic::ListSP<DotGateWithNeighbors>(
      std::make_shared<falcon_core::generic::List<DotGateWithNeighbors>>(
          self->items()));
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
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  DotGateWithNeighborsSP  real_value =
      *static_cast<DotGateWithNeighborsSP*>(value);
  return self->contains(real_value);
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
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  DotGateWithNeighborsSP  real_value =
      *static_cast<DotGateWithNeighborsSP*>(value);
  return self->index(real_value);
  FALCON_C_API_END(0)
}

bool DotGatesWithNeighbors_equal(DotGatesWithNeighborsHandle handle,
                                 DotGatesWithNeighborsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_equal: second handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  DotGatesWithNeighborsSP real_other =
      *static_cast<DotGatesWithNeighborsSP*>(other);
  return *self == *real_other;
  FALCON_C_API_END(false)
}

bool DotGatesWithNeighbors_not_equal(DotGatesWithNeighborsHandle handle,
                                     DotGatesWithNeighborsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_not_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_not_equal: second handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  DotGatesWithNeighborsSP real_other =
      *static_cast<DotGatesWithNeighborsSP*>(other);
  return *self != *real_other;
  FALCON_C_API_END(false)
}

StringHandle DotGatesWithNeighbors_to_json_string(
    DotGatesWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGatesWithNeighbors_to_json_string: handle cannot be null");
  }
  DotGatesWithNeighborsSP self = *static_cast<DotGatesWithNeighborsSP*>(handle);
  return String_create(self->to_json_string().c_str(),
                       self->to_json_string().size());
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
  return new DotGatesWithNeighborsSP(
      DotGatesWithNeighbors::from_json_string<DotGatesWithNeighbors>(
          real_json));
  FALCON_C_API_END(nullptr)
}
}
