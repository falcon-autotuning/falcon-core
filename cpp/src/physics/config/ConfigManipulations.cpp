#include "falcon_core/physics/config/ConfigManipulations.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
namespace falcon_core {
namespace physics {
namespace config {
using core::StandardConfigConnections;

std::vector<std::string> split_on_semicolon(const std::string& s) {
  std::vector<std::string> result;
  std::string::size_type   start = 0, end;
  while ((end = s.find(';', start)) != std::string::npos) {
    result.push_back(s.substr(start, end - start));
    start = end + 1;
  }
  result.push_back(s.substr(start));
  return result;
}
ConfigManipulations::ConfigManipulations() = default;
core::ConfigSP ConfigManipulations::unpack_device_config(
    const YAML::Node& config) const {
  generic::Map<autotuner_interfaces::names::Gname, core::Group> groups;
  core::StandardConfigConnectionsSP                             connections =
      _extract_standard_config_connections(config);
  for (const auto& group_pair : config["groups"]) {
    auto key               = group_pair.first.as<std::string>();
    auto value             = group_pair.second;
    auto group_connections = _extract_standard_group_config_connections(value);
    auto order =
        _extract_order(value["Order"].as<std::string>(), group_connections);
    core::GroupSP new_group = std::make_shared<core::Group>(
        std::make_shared<autotuner_interfaces::names::Channel>(key),
        value["NumDots"].as<int>(),
        group_connections->screening_gates(),
        group_connections->reservoir_gates(),
        group_connections->plunger_gates(),
        group_connections->barrier_gates(),
        order);
    groups.insert(std::make_shared<autotuner_interfaces::names::Gname>(key),
                  new_group);
  }
  auto ohmics    = _extract_ohmics(config["Ohmics"].as<std::string>());
  auto wiring_DC = _extract_dcwiring(config, ohmics, connections);

  device_structures::Connections total_gates;
  total_gates.insert(total_gates.end(),
                     connections->screening_gates()->begin(),
                     connections->screening_gates()->end());
  total_gates.insert(total_gates.end(),
                     connections->reservoir_gates()->begin(),
                     connections->reservoir_gates()->end());
  total_gates.insert(total_gates.end(),
                     connections->plunger_gates()->begin(),
                     connections->plunger_gates()->end());
  total_gates.insert(total_gates.end(),
                     connections->barrier_gates()->begin(),
                     connections->barrier_gates()->end());

  auto constraints = _extract_voltage_constraints(
      config, std::make_shared<device_structures::Connections>(total_gates));

  return std::make_shared<core::Config>(
      connections->screening_gates(),
      connections->plunger_gates(),
      ohmics,
      connections->barrier_gates(),
      connections->reservoir_gates(),
      std::make_shared<
          generic::Map<autotuner_interfaces::names::Gname, core::Group>>(
          groups),
      wiring_DC,
      constraints);
}

core::AdjacencySP ConfigManipulations::_extract_adjacency(
    const YAML::Node&                       map,
    const device_structures::ConnectionsSP& total_gates) const {
  if (!total_gates) {
    throw std::invalid_argument(
        "ConfigManipulations: The total_gates cannot be null.");
  }
  size_t               num_gates = total_gates->size();
  generic::FArray<int> adjacency =
      *generic::FArray<int>::zeros({num_gates, num_gates});
  std::vector<std::string> total_gate_names;
  for (const auto& gate : *total_gates)
    total_gate_names.push_back(gate->name());

  if (!map["adjacency"])
    throw std::runtime_error("Expected to find adjacency in config");
  auto adjacency_map = map["adjacency"];
  for (size_t i = 0; i < total_gate_names.size(); ++i) {
    auto gate = total_gate_names[i];
    if (!adjacency_map[gate]) continue;
    auto adjacent_matches = adjacency_map[gate].as<std::string>();
    auto gate_names       = split_on_semicolon(adjacent_matches);
    for (size_t j = 0; j < total_gate_names.size(); ++j) {
      if (std::find(gate_names.begin(),
                    gate_names.end(),
                    total_gate_names[j]) != gate_names.end()) {
        adjacency(i, j) = 1;
        adjacency(j, i) = 1;
      }
    }
  }
  return std::make_shared<core::Adjacency>(adjacency.data(), total_gates);
}

core::VoltageConstraintsSP ConfigManipulations::_extract_voltage_constraints(
    const YAML::Node&                       map,
    const device_structures::ConnectionsSP& total_gates) const {
  auto adjacency = _extract_adjacency(map, total_gates);
  if (!map["max_safe_diff"])
    throw std::runtime_error("Expected max_safe_diff in config");
  double max_safe_diff = map["max_safe_diff"].as<double>();
  if (!map["safe_voltage_bounds"])
    throw std::runtime_error("Expected safe_voltage_bounds in config");
  auto                bounds_node = map["safe_voltage_bounds"];
  std::vector<double> bounds;
  for (const auto& b : bounds_node) bounds.push_back(b.as<double>());
  if (bounds.size() != 2)
    throw std::runtime_error("Expected two bounds for voltage");
  return std::make_shared<core::VoltageConstraints>(
      adjacency, max_safe_diff, std::make_pair(bounds[0], bounds[1]));
}

device_structures::ImpedancesSP ConfigManipulations::_extract_dcwiring(
    const YAML::Node&                        map,
    const device_structures::ConnectionsSP&  ohmics,
    const core::StandardConfigConnectionsSP& connections) const {
  if (!ohmics || !connections) {
    throw std ::runtime_error(
        "ConfigManipulations: The ohmics and the connecations "
        "cannot be null.");
  }
  device_structures::Impedances outs;
  auto                          impedances = map["wiringDC"];
  for (const auto& entry : impedances) {
    std::string                     key    = entry.first.as<std::string>();
    auto                            values = entry.second;
    device_structures::ConnectionSP gt;
    device_structures::ConnectionSP ohmic =
        device_structures::Connection::Ohmic(key);
    if (connections->has_ohmic(ohmic)) {
      gt = ohmic;
    } else {
      device_structures::ConnectionSP plunger_gate =
          device_structures::Connection::PlungerGate(key);
      if (connections->has_plunger_gate(plunger_gate)) {
        gt = plunger_gate;
      } else {
        device_structures::ConnectionSP barrier_gate =
            device_structures::Connection::BarrierGate(key);
        if (connections->has_barrier_gate(barrier_gate)) {
          gt = barrier_gate;
        } else {
          device_structures::ConnectionSP screening_gate =
              device_structures::Connection::ScreeningGate(key);
          if (connections->has_screening_gate(screening_gate)) {
            gt = screening_gate;
          } else {
            device_structures::ConnectionSP reservoir_gate =
                device_structures::Connection::ReservoirGate(key);
            if (connections->has_reservoir_gate(reservoir_gate)) {
              gt = reservoir_gate;
            } else {
              throw std::runtime_error(
                  "ConfigManipulations: Cannot use that connection : " + key);
            }
          }
        }
      }
    }

    outs.push_back(std::make_shared<device_structures::Impedance>(
        gt,
        values["resistance"].as<double>(),
        values["capacitance"].as<double>()));
  }
  return std::make_shared<device_structures::Impedances>(outs);
}

device_structures::ConnectionsSP ConfigManipulations::_extract_barrier_gates(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ConnectionSP> barriergates;
  for (const auto& name : gate_names)
    barriergates.push_back(device_structures::Connection::BarrierGate(name));
  return std::make_shared<device_structures::Connections>(barriergates);
}
device_structures::ConnectionsSP ConfigManipulations::_extract_plunger_gates(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ConnectionSP> plungergates;
  for (const auto& name : gate_names)
    plungergates.push_back(device_structures::Connection::PlungerGate(name));
  return std::make_shared<device_structures::Connections>(plungergates);
}
device_structures::ConnectionsSP ConfigManipulations::_extract_reservoir_gates(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ConnectionSP> reservoirgates;
  for (const auto& name : gate_names)
    reservoirgates.push_back(
        device_structures::Connection::ReservoirGate(name));
  return std::make_shared<device_structures::Connections>(reservoirgates);
}
device_structures::ConnectionsSP ConfigManipulations::_extract_screening_gates(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ConnectionSP> screeninggates;
  for (const auto& name : gate_names)
    screeninggates.push_back(
        device_structures::Connection::ScreeningGate(name));
  return std::make_shared<device_structures::Connections>(screeninggates);
}
device_structures::ConnectionsSP ConfigManipulations::_extract_ohmics(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ConnectionSP> ohmics;
  for (const auto& name : gate_names)
    ohmics.push_back(device_structures::Connection::Ohmic(name));
  return std::make_shared<device_structures::Connections>(ohmics);
}

core::StandardConfigConnectionsSP
ConfigManipulations::_extract_standard_group_config_connections(
    const YAML::Node& config) const {
  auto screening_gates =
      _extract_screening_gates(config["ScreeningGates"].as<std::string>());
  auto reservoir_gates =
      _extract_reservoir_gates(config["ReservoirGates"].as<std::string>());
  auto plunger_gates =
      _extract_plunger_gates(config["PlungerGates"].as<std::string>());
  auto barrier_gates =
      _extract_barrier_gates(config["BarrierGates"].as<std::string>());
  return std::make_shared<core::StandardConfigConnections>(
      screening_gates,
      reservoir_gates,
      plunger_gates,
      barrier_gates,
      std::make_shared<device_structures::Connections>());
}

core::StandardConfigConnectionsSP
ConfigManipulations::_extract_standard_config_connections(
    const YAML::Node& config) const {
  auto screening_gates =
      _extract_screening_gates(config["ScreeningGates"].as<std::string>());
  auto reservoir_gates =
      _extract_reservoir_gates(config["ReservoirGates"].as<std::string>());
  auto plunger_gates =
      _extract_plunger_gates(config["PlungerGates"].as<std::string>());
  auto barrier_gates =
      _extract_barrier_gates(config["BarrierGates"].as<std::string>());
  auto ohmics = _extract_ohmics(config["Ohmics"].as<std::string>());
  return std::make_shared<core::StandardConfigConnections>(
      screening_gates, reservoir_gates, plunger_gates, barrier_gates, ohmics);
}

device_structures::ConnectionsSP ConfigManipulations::_extract_order(
    const std::string                        raw,
    const core::StandardConfigConnectionsSP& connections) const {
  if (!connections) {
    throw std::invalid_argument(
        "ConfigManipulations: The connections cannot be null.");
  }
  auto                             raworder = split_on_semicolon(raw);
  device_structures::ConnectionsSP order =
      std::make_shared<device_structures::Connections>();
  for (size_t i = 1; i + 1 < raworder.size(); ++i) {
    const auto&                     gate = raworder[i];
    device_structures::ConnectionSP realGate =
        device_structures::Connection::ScreeningGate(gate);
    if (connections->has_screening_gate(realGate)) {
      order->push_back(realGate);
    } else {
      device_structures::ConnectionSP realGate =
          device_structures::Connection::BarrierGate(gate);
      if (connections->has_barrier_gate(realGate)) {
        order->push_back(realGate);
      } else {
        device_structures::ConnectionSP realGate =
            device_structures::Connection::PlungerGate(gate);
        if (connections->has_plunger_gate(realGate)) {
          order->push_back(realGate);
        } else {
          device_structures::ConnectionSP realGate =
              device_structures::Connection::ReservoirGate(gate);
          if (connections->has_reservoir_gate(realGate)) {
            order->push_back(realGate);
          } else
            throw std::runtime_error("Unexpected gate name found of " + gate +
                                     " does not belong in config.");
        }
      }
    }
  }
  auto ohmic_conn = device_structures::Connection::Ohmic(raworder.front());
  std::vector<device_structures::ConnectionSP> temp{ohmic_conn};
  order->insert(order->begin(), temp.begin(), temp.end());
  order->push_back(device_structures::Connection::Ohmic(raworder.back()));
  return order;
}

}  // namespace config
}  // namespace physics
}  // namespace falcon_core
