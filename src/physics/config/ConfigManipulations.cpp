#include "falcon_core/physics/config/ConfigManipulations.hpp"

#include <ranges>

#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"
namespace falcon_core::physics::config {
using core::StandardConfigConnections;

std::vector<std::string> split_on_semicolon(const std::string& s) {
  std::vector<std::string> result;
  for (auto&& sub : std::views::split(s, ';')) {
    result.emplace_back(sub.begin(), sub.end());
  }
  return result;
}
core::ConfigSP ConfigManipulations::unpack_device_config(
    const YAML::Node& config) const {
  generic::Map<Gname, core::Group>  groups;
  core::StandardConfigConnectionsSP connections =
      _extract_standard_config_connections(config);
  for (const auto& group_pair : config["groups"]) {
    auto key         = group_pair.first.as<std::string>();
    auto value       = group_pair.second;
    auto connections = _extract_standard_config_connections(value);
    auto order = _extract_order(value["Order"].as<std::string>(), connections);
    core::GroupSP new_group =
        std::make_shared<core::Group>(std::make_shared<Channel>(key),
                                      value["NumDots"].as<int>(),
                                      connections->screening_gates(),
                                      connections->reservoir_gates(),
                                      connections->plunger_gates(),
                                      connections->barrier_gates(),
                                      order);
    groups[std::make_shared<Gname>(key)] = new_group;
  }
  auto ohmics    = _extract_ohmics(config["Ohmics"].as<std::string>());
  auto wiring_DC = _extract_dcwiring(config, ohmics, connections);

  generic::List<device_structures::BaseConnection> total_gates;
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
      config,
      std::make_shared<generic::List<device_structures::BaseConnection>>(
          total_gates));

  return std::make_shared<core::Config>(ohmics,
                                        wiring_DC,
                                        groups,
                                        connections->screening_gates(),
                                        connections->reservoir_gates(),
                                        connections->plunger_gates(),
                                        connections->barrier_gates(),
                                        constraints);
}

core::AdjacencySP ConfigManipulations::_extract_adjacency(
    const YAML::Node&                                         map,
    const generic::ListSP<device_structures::BaseConnection>& total_gates)
    const {
  size_t                         num_gates = total_gates->size();
  std::vector<std::vector<bool>> adjacency(num_gates,
                                           std::vector<bool>(num_gates, false));
  std::vector<std::string>       total_gate_names;
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
        adjacency[i][j] = true;
        adjacency[j][i] = true;
      }
    }
  }
  return std::make_shared<core::Adjacency>(adjacency, total_gates);
}

core::VoltageConstraintsSP ConfigManipulations::_extract_voltage_constraints(
    const YAML::Node&                                         map,
    const generic::ListSP<device_structures::BaseConnection>& total_gates)
    const {
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
    const device_structures::OhmicsSP&       ohmics,
    const core::StandardConfigConnectionsSP& connections) const {
  device_structures::Impedances outs;
  auto                          impedances = map["wiringDC"];
  for (const auto& entry : impedances) {
    auto key    = entry.first.as<std::string>();
    auto values = entry.second;
    if (!values) continue;
    if (ohmics->contains(std::make_shared<device_structures::Ohmic>(key))) {
      outs.push_back(std::make_shared<device_structures::Impedance>(
          std::make_shared<device_structures::Ohmic>(key),
          values["resistance"].as<double>(),
          values["capacitance"].as<double>()));
    } else {
      device_structures::BaseConnectionSP gt;
      if (connections->has_plunger_gate(
              std::make_shared<device_structures::PlungerGate>(key)))
        gt = std::make_shared<device_structures::PlungerGate>(key);
      else if (connections->has_barrier_gate(
                   std::make_shared<device_structures::BarrierGate>(key)))
        gt = std::make_shared<device_structures::BarrierGate>(key);
      else if (connections->has_screening_gate(
                   std::make_shared<device_structures::ScreeningGate>(key)))
        gt = std::make_shared<device_structures::ScreeningGate>(key);
      else if (connections->has_reservoir_gate(
                   std::make_shared<device_structures::ReservoirGate>(key)))
        gt = std::make_shared<device_structures::ReservoirGate>(key);
      else
        throw std::runtime_error("Cannot use that gate");
      outs.push_back(std::make_shared<device_structures::Impedance>(
          gt,
          values["resistance"].as<double>(),
          values["capacitance"].as<double>()));
    }
  }
  return std::make_shared<device_structures::Impedances>(outs);
}

device_structures::BarrierGatesSP ConfigManipulations::_extract_barrier_gates(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::BarrierGateSP> barriergates;
  for (const auto& name : gate_names)
    barriergates.push_back(
        std::make_shared<device_structures::BarrierGate>(name));
  return std::make_shared<device_structures::BarrierGates>(barriergates);
}
device_structures::PlungerGatesSP ConfigManipulations::_extract_plunger_gates(
    const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::PlungerGateSP> plungergates;
  for (const auto& name : gate_names)
    plungergates.push_back(
        std::make_shared<device_structures::PlungerGate>(name));
  return std::make_shared<device_structures::PlungerGates>(plungergates);
}
device_structures::ReservoirGatesSP
ConfigManipulations::_extract_reservoir_gates(const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ReservoirGateSP> reservoirgates;
  for (const auto& name : gate_names)
    reservoirgates.push_back(
        std::make_shared<device_structures::ReservoirGate>(name));
  return std::make_shared<device_structures::ReservoirGates>(reservoirgates);
}
device_structures::ScreeningGatesSP
ConfigManipulations::_extract_screening_gates(const std::string raw) const {
  auto gate_names = split_on_semicolon(raw);
  std::vector<device_structures::ScreeningGateSP> screeninggates;
  for (const auto& name : gate_names)
    screeninggates.push_back(
        std::make_shared<device_structures::ScreeningGate>(name));
  return std::make_shared<device_structures::ScreeningGates>(screeninggates);
}
device_structures::OhmicsSP ConfigManipulations::_extract_ohmics(
    const std::string raw) const {
  auto                                    gate_names = split_on_semicolon(raw);
  std::vector<device_structures::OhmicSP> ohmics;
  for (const auto& name : gate_names)
    ohmics.push_back(std::make_shared<device_structures::Ohmic>(name));
  return std::make_shared<device_structures::Ohmics>(ohmics);
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
  return std::make_shared<core::StandardConfigConnections>(
      screening_gates, reservoir_gates, plunger_gates, barrier_gates, nullptr);
}

device_structures::BaseConnectionsSP ConfigManipulations::_extract_order(
    const std::string                        raw,
    const core::StandardConfigConnectionsSP& connections) const {
  auto raworder = split_on_semicolon(raw);
  std::vector<device_structures::BaseConnectionSP> order;
  for (size_t i = 1; i + 1 < raworder.size(); ++i) {
    const auto& gate = raworder[i];
    if (connections->has_screening_gate(
            std::make_shared<device_structures::ScreeningGate>(gate)))
      order.push_back(std::make_shared<device_structures::ScreeningGate>(gate));
    else if (connections->has_barrier_gate(
                 std::make_shared<device_structures::BarrierGate>(gate)))
      order.push_back(std::make_shared<device_structures::BarrierGate>(gate));
    else if (connections->has_plunger_gate(
                 std::make_shared<device_structures::PlungerGate>(gate)))
      order.push_back(std::make_shared<device_structures::PlungerGate>(gate));
    else
      order.push_back(std::make_shared<device_structures::ReservoirGate>(gate));
  }
  order.insert(order.begin(),
               std::make_shared<device_structures::Ohmic>(raworder.front()));
  order.push_back(std::make_shared<device_structures::Ohmic>(raworder.back()));
  return std::make_shared<device_structures::BaseConnections>(order);
}

}  // namespace falcon_core::physics::config
