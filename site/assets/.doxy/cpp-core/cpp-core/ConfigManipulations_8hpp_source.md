

# File ConfigManipulations.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**ConfigManipulations.hpp**](ConfigManipulations_8hpp.md)

[Go to the documentation of this file](ConfigManipulations_8hpp.md)


```C++
#pragma once
#include <yaml-cpp/yaml.h>

#include "falcon_core/physics/config/core/Config.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
namespace falcon_core {
namespace physics {
namespace config {
class ConfigManipulations {
 public:
  ConfigManipulations();
  core::ConfigSP unpack_device_config(const YAML::Node& config) const;
  core::AdjacencySP _extract_adjacency(
      const YAML::Node&                       map,
      const device_structures::ConnectionsSP& total_gates) const;
  core::VoltageConstraintsSP _extract_voltage_constraints(
      const YAML::Node&                       map,
      const device_structures::ConnectionsSP& total_gates) const;
  device_structures::ImpedancesSP _extract_dcwiring(
      const YAML::Node&                        map,
      const device_structures::ConnectionsSP&  ohmics,
      const core::StandardConfigConnectionsSP& connections) const;
  device_structures::ConnectionsSP _extract_barrier_gates(
      const std::string raw) const;
  device_structures::ConnectionsSP _extract_plunger_gates(
      const std::string raw) const;
  device_structures::ConnectionsSP _extract_reservoir_gates(
      const std::string raw) const;
  device_structures::ConnectionsSP _extract_screening_gates(
      const std::string raw) const;
  core::StandardConfigConnectionsSP _extract_standard_config_connections(
      const YAML::Node& config) const;
  core::StandardConfigConnectionsSP _extract_standard_group_config_connections(
      const YAML::Node& config) const;
  device_structures::ConnectionsSP _extract_ohmics(const std::string raw) const;
  device_structures::ConnectionsSP _extract_order(
      const std::string                        raw,
      const core::StandardConfigConnectionsSP& connections) const;
};
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


