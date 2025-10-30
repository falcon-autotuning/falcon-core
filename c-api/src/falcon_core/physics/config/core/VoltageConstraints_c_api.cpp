#include "falcon_core/physics/config/core/VoltageConstraints_c_api.h"

#include <falcon_core/physics/config/core/VoltageConstraints.hpp>
#include <string>

#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::config::core;

extern "C" {

VoltageConstraintsHandle VoltageConstraints_create(
    AdjacencyHandle        adjacency,
    double                 max_safe_diff,
    PairDoubleDoubleHandle bounds) {
  AdjacencySP real_adjacency =
      std::make_shared<Adjacency>(*static_cast<Adjacency*>(adjacency));
  auto first_bound =
      static_cast<falcon_core::generic::Pair<double, double>*>(bounds)->first();
  auto second_bound =
      static_cast<falcon_core::generic::Pair<double, double>*>(bounds)
          ->second();
  return new VoltageConstraints(
      real_adjacency, max_safe_diff, std::make_pair(first_bound, second_bound));
}

void VoltageConstraints_destroy(VoltageConstraintsHandle handle) {
  delete static_cast<VoltageConstraints*>(handle);
}

FArrayDoubleHandle VoltageConstraints_matrix(VoltageConstraintsHandle handle) {
  VoltageConstraints self = *static_cast<VoltageConstraints*>(handle);
  return new falcon_core::generic::FArray<double>(self.matrix());
}

AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle) {
  VoltageConstraints self = *static_cast<VoltageConstraints*>(handle);
  return new Adjacency(*self.adjacency());
}

PairFloatFloatHandle VoltageConstraints_limits(
    VoltageConstraintsHandle handle) {
  VoltageConstraints self = *static_cast<VoltageConstraints*>(handle);
  return new falcon_core::generic::Pair<float, float>(
      static_cast<float>(self.limits().first),
      static_cast<float>(self.limits().second));
}

bool VoltageConstraints_equal(VoltageConstraintsHandle a,
                              VoltageConstraintsHandle b) {
  VoltageConstraints self_a = *static_cast<VoltageConstraints*>(a);
  VoltageConstraints self_b = *static_cast<VoltageConstraints*>(b);
  return self_a == self_b;
}
bool VoltageConstraints_not_equal(VoltageConstraintsHandle a,
                                  VoltageConstraintsHandle b) {
  VoltageConstraints self_a = *static_cast<VoltageConstraints*>(a);
  VoltageConstraints self_b = *static_cast<VoltageConstraints*>(b);
  return self_a != self_b;
}

StringHandle VoltageConstraints_to_json_string(
    VoltageConstraintsHandle handle) {
  VoltageConstraints self = *static_cast<VoltageConstraints*>(handle);
  std::string        json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

VoltageConstraintsHandle VoltageConstraints_from_json_string(
    StringHandle json) {
  std::string json_str = json->raw;
  return new VoltageConstraints(
      *VoltageConstraints::from_json_string<VoltageConstraints>(json_str));
}

#ifdef __cplusplus
}
#endif
