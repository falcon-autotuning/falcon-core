#include "falcon_core/physics/config/core/VoltageConstraints_c_api.h"

#include <falcon_core/physics/config/core/VoltageConstraints.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/Pair.hpp"
using namespace falcon_core::physics::config::core;

extern "C" {
VoltageConstraintsHandle VoltageConstraints_create(
    AdjacencyHandle        adjacency,
    double                 max_safe_diff,
    PairDoubleDoubleHandle bounds) {
  FALCON_C_API_BEGIN
  if (!adjacency) {
    throw std::invalid_argument(
        "VoltageConstraints_create: adjacency cannot be null");
  }
  if (!bounds) {
    throw std::invalid_argument(
        "VoltageConstraints_create: bounds cannot be null");
  }
  AdjacencySP real_adjacency = *static_cast<AdjacencySP*>(adjacency);
  auto        first_bound =
      (*static_cast<falcon_core::generic::PairSP<double, double>*>(bounds))
          ->first();
  auto second_bound =
      (*static_cast<falcon_core::generic::PairSP<double, double>*>(bounds))
          ->second();
  return new VoltageConstraintsSP(std::make_shared<VoltageConstraints>(
      real_adjacency,
      max_safe_diff,
      std::make_pair(first_bound, second_bound)));
  FALCON_C_API_END(nullptr)
}

void VoltageConstraints_destroy(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_destroy: handle cannot be null");
  }
  delete static_cast<VoltageConstraintsSP*>(handle);
  FALCON_C_API_END()
}

FArrayDoubleHandle VoltageConstraints_matrix(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_matrix: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP*>(handle);
  return new falcon_core::generic::FArraySP<double>(
      std::make_shared<falcon_core::generic::FArray<double>>(self->matrix()));
  FALCON_C_API_END(nullptr)
}

AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_adjacency: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP*>(handle);
  return new AdjacencySP(self->adjacency());
  FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle VoltageConstraints_limits(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_limits: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP*>(handle);
  return new falcon_core::generic::FArraySP<double>(
      std::make_shared<falcon_core::generic::FArray<double>>(self->limits()));
  FALCON_C_API_END(nullptr)
}

bool VoltageConstraints_equal(VoltageConstraintsHandle handle,
                              VoltageConstraintsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("VoltageConstraints_equal: a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("VoltageConstraints_equal: b cannot be null");
  }
  VoltageConstraintsSP self_a = *static_cast<VoltageConstraintsSP*>(handle);
  VoltageConstraintsSP self_b = *static_cast<VoltageConstraintsSP*>(other);
  return *self_a == *self_b;
  FALCON_C_API_END(false)
}

bool VoltageConstraints_not_equal(VoltageConstraintsHandle handle,
                                  VoltageConstraintsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_not_equal: a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "VoltageConstraints_not_equal: b cannot be null");
  }
  VoltageConstraintsSP self_a = *static_cast<VoltageConstraintsSP*>(handle);
  VoltageConstraintsSP self_b = *static_cast<VoltageConstraintsSP*>(other);
  return *self_a != *self_b;
  FALCON_C_API_END(false)
}

StringHandle VoltageConstraints_to_json_string(
    VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_to_json_string: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP*>(handle);
  std::string          json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

VoltageConstraintsHandle VoltageConstraints_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "VoltageConstraints_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new VoltageConstraintsSP(
      VoltageConstraints::from_json_string<VoltageConstraints>(json_str));
  FALCON_C_API_END(nullptr)
}
}
