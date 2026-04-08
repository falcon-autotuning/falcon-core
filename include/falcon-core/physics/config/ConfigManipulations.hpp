#pragma once
#include <yaml-cpp/yaml.h>

#include "falcon-core/export.h"
#include "falcon-core/physics/config/core/Config.hpp"
#include "falcon-core/physics/config/core/StandardConfigConnections.hpp"
namespace falcon_core {
namespace physics {
namespace config {
/**
 * @brief A utility class for manipulating and extracting information from
 * device configurations.
 */
class FALCON_CORE_CPP_API ConfigManipulations {
 public:
  ConfigManipulations();
  /**
   * @brief Unpacks a mapping into a Config object.
   * @param config A mapping containing configuration details.
   * @return A Config object populated with the provided details.
   */
  core::ConfigSP unpack_device_config(const YAML::Node& config) const;
  /**
   * @brief given the available gates loaded from the config, lets generate the
   * adjacency matrix for this device.
   */
  core::AdjacencySP _extract_adjacency(
      const YAML::Node&                       map,
      const device_structures::ConnectionsSP& total_gates) const;
  /**
   * @brief Given the available gates and the config lets produce a voltage
   * constraints.
   */
  core::VoltageConstraintsSP _extract_voltage_constraints(
      const YAML::Node&                       map,
      const device_structures::ConnectionsSP& total_gates) const;
  /**
   * @brief Extracts a dcwiring from a config dictionary.
   * @param dict A mapping containing dcwiring details.
   * @param ohmics The list of ohmics in the device.
   * @param connections The configuration of the device connections.
   * @returns An impedances object representing the dcwiring.
   * @throws std::runtime_error if the dcwiring extraction fails.
   */
  device_structures::ImpedancesSP _extract_dcwiring(
      const YAML::Node&                        map,
      const device_structures::ConnectionsSP&  ohmics,
      const core::StandardConfigConnectionsSP& connections) const;
  /**
   * @brief Extract the barrier gates from the compressed ";" delimited string
   */
  device_structures::ConnectionsSP _extract_barrier_gates(
      const std::string raw) const;
  /**
   * @brief Extract the plunger gates from the compressed ";" delimited string
   */
  device_structures::ConnectionsSP _extract_plunger_gates(
      const std::string raw) const;
  /**
   * @brief Extract the reservoir gates from the compressed ";" delimited string
   */
  device_structures::ConnectionsSP _extract_reservoir_gates(
      const std::string raw) const;
  /**
   * @brief Extract the screening gates from the compressed ";" delimited string
   */
  device_structures::ConnectionsSP _extract_screening_gates(
      const std::string raw) const;
  /**
   * @brief Extracts the standard connections from a config dictonary
   * @param config The dictionary with keys that are gate types and values which
   * are ";" delimtted strings of gates.
   * @returns a collection of standard connections.
   */
  core::StandardConfigConnectionsSP _extract_standard_config_connections(
      const YAML::Node& config) const;
  /**
   * @brief Extracts the standard connections from a config dictonary
   * @param config The dictionary with keys that are gate types and values which
   * are ";" delimtted strings of gates. This version does not include ohmics.
   * @returns a collection of standard connections.
   */
  core::StandardConfigConnectionsSP _extract_standard_group_config_connections(
      const YAML::Node& config) const;
  /**
   * @brief Extract the ohmics from the compressed ";" delimited string
   */
  device_structures::ConnectionsSP _extract_ohmics(const std::string raw) const;
  /**
   * @brief Extracts the order from the compressed ";" delimited string
   */
  device_structures::ConnectionsSP _extract_order(
      const std::string                        raw,
      const core::StandardConfigConnectionsSP& connections) const;
};
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
