#include "falcon-core/physics/config/core/VoltageConstraints_c_api.h"

#include <falcon-core/physics/config/core/VoltageConstraints.hpp>

#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/generic/Pair.hpp"
using namespace falcon_core::physics::config::core;

extern "C" {
DEFINE_C_API_COPY(VoltageConstraints);
DEFINE_C_API_DESTROY(VoltageConstraints);
DEFINE_C_API_EQUAL(VoltageConstraints);
DEFINE_C_API_NOT_EQUAL(VoltageConstraints);
DEFINE_C_API_TO_JSON(VoltageConstraints);
DEFINE_C_API_FROM_JSON(VoltageConstraints);
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
}
