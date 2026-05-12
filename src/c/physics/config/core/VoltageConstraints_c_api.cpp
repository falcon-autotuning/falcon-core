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
VoltageConstraintsHandle
VoltageConstraints_create(AdjacencyHandle adjacency, double max_safe_diff,
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
  AdjacencySP real_adjacency = *static_cast<AdjacencySP *>(adjacency);
  auto first_bound =
      (*static_cast<falcon_core::generic::PairSP<double, double> *>(bounds))
          ->first();
  auto second_bound =
      (*static_cast<falcon_core::generic::PairSP<double, double> *>(bounds))
          ->second();
  return new VoltageConstraintsSP(std::make_shared<VoltageConstraints>(
      real_adjacency, max_safe_diff,
      std::make_pair(first_bound, second_bound)));
  FALCON_C_API_END(nullptr)
}

AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_adjacency: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP *>(handle);
  return new AdjacencySP(self->adjacency());
  FALCON_C_API_END(nullptr)
}

double VoltageConstraints_max_safe_diff(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_max_safe_diff: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP *>(handle);
  return self->max_safe_diff();
  FALCON_C_API_END(0.0)
}

double VoltageConstraints_min_bound(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_min_bound: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP *>(handle);
  return self->min_bound();
  FALCON_C_API_END(0.0)
}

double VoltageConstraints_max_bound(VoltageConstraintsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_max_bound: handle cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP *>(handle);
  return self->max_bound();
  FALCON_C_API_END(0.0)
}

CoupledLabelledDomainHandle VoltageConstraints_compute_maximal_domain(
    VoltageConstraintsHandle handle, PortsHandle search_domain,
    DeviceVoltageStatesHandle current_state) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_compute_maximal_domain: handle cannot be null");
  }
  if (!search_domain) {
    throw std::invalid_argument("VoltageConstraints_compute_maximal_domain: "
                                "search_domain cannot be null");
  }
  if (!current_state) {
    throw std::invalid_argument("VoltageConstraints_compute_maximal_domain: "
                                "current_state cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP *>(handle);
  auto real_search_domain =
      *static_cast<falcon_core::instrument_interfaces::names::PortsSP *>(
          search_domain);
  auto real_current_state = *static_cast<
      falcon_core::communications::voltage_states::DeviceVoltageStatesSP *>(
      current_state);
  return new falcon_core::math::domains::CoupledLabelledDomainSP(
      self->compute_maximal_domain(real_search_domain, real_current_state));
  FALCON_C_API_END(nullptr)
}

bool VoltageConstraints_validate_voltage_state(VoltageConstraintsHandle handle,
                                               PointHandle voltage_state) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "VoltageConstraints_validate_voltage_state: handle cannot be null");
  }
  if (!voltage_state) {
    throw std::invalid_argument("VoltageConstraints_validate_voltage_state: "
                                "voltage_state cannot be null");
  }
  VoltageConstraintsSP self = *static_cast<VoltageConstraintsSP *>(handle);
  auto real_voltage_state =
      *static_cast<falcon_core::math::PointSP *>(voltage_state);
  return self->validate_voltage_state(real_voltage_state);
  FALCON_C_API_END(false)
}
}
