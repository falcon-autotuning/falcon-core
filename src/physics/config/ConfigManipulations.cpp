#include "falcon_core/physics/config/ConfigManipulations.hpp"

#include "falcon_core/physics/config/core/Group.hpp"
namespace falcon_core::physics::config {

core::ConfigSP ConfigManipulations::unpack_device_config(
    const YAML::Node& config) const {
  std::map<Gname, core::Group> groups;
  for (const auto& group_pair : config["groups"]) {
    auto        key         = group_pair.first.as<std::string>();
    auto        value       = group_pair.second;
    auto        connections = _extract_standard_config_connections(value);
    auto        order       = _extract_order(value["Order"].as<std::string>());
    core::Group new_group(std::make_shared<Channel>(key),
                          value["NumDots"].as<int>(),
                          connections->screening_gates(),
                          connections->reservoir_gates(),
                          connections->plunger_gates(),
                          connections->barrier_gates(),
                          order);
    groups[Gname(key)] = new_group;
  }
  auto connections = _extract_standard_config_connections(config);
  auto ohmics      = _extract_ohmics(config["Ohmics"].as<std::string>());
  auto wiring_DC   = _extract_dcwiring(config, ohmics, connections);

  std::vector<Gate> total_gates;
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

  auto constraints = _extract_voltage_constraints(config, total_gates);

  return Config(ohmics,
                wiring_DC,
                groups,
                connections->screening_gates(),
                connections->reservoir_gates(),
                connections->plunger_gates(),
                connections->barrier_gates(),
                constraints);
}

core::Adjacency ConfigManipulations::_extract_adjacency(
    const YAML::Node& map, const std::vector<Gate>& total_gates) const {
  size_t                         num_gates = total_gates.size();
  std::vector<std::vector<bool>> adjacency(num_gates,
                                           std::vector<bool>(num_gates, false));
  std::vector<std::string>       total_gate_names;
  for (const auto& gate : total_gates) total_gate_names.push_back(gate.name);

  if (!map["adjacency"])
    throw std::runtime_error("Expected to find adjacency in config");
  auto adjacency_map = map["adjacency"];
  for (size_t i = 0; i < total_gate_names.size(); ++i) {
    auto gate = total_gate_names[i];
    if (!adjacency_map[gate]) continue;
    auto adjacent_matches = adjacency_map[gate].as<std::string>();
    auto gate_names       = split(adjacent_matches, ';');
    for (size_t j = 0; j < total_gate_names.size(); ++j) {
      if (std::find(gate_names.begin(),
                    gate_names.end(),
                    total_gate_names[j]) != gate_names.end()) {
        adjacency[i][j] = true;
        adjacency[j][i] = true;
      }
    }
  }
  return Adjacency(adjacency, total_gates);
}

core::VoltageConstraints ConfigManipulations::_extract_voltage_constraints(
    const YAML::Node& map, const std::vector<Gate>& total_gates) const {
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
  return VoltageConstraints(
      adjacency, max_safe_diff, std::make_tuple(bounds[0], bounds[1]));
}

device_structures::ImpedancesSP ConfigManipulations::_extract_dcwiring(
    const YAML::Node&                        map,
    const device_structures::OhmicsSP&       ohmics,
    const core::StandardConfigConnectionsSP& connections) const {
  std::vector<device_structures::Impedance> outs;
  auto                                      impedances = dictionary["wiringDC"];
  for (const auto& entry : impedances) {
    auto key    = entry.first.as<std::string>();
    auto values = entry.second;
    if (!values) continue;
    if (ohmics.has_name(key)) {
      outs.emplace_back(Ohmic(key),
                        values["resistance"].as<double>(),
                        values["capacitance"].as<double>());
    } else {
      GateType gt;
      if (connections.has_plunger_gate(key))
        gt = PlungerGate;
      else if (connections.has_barrier_gate(key))
        gt = BarrierGate;
      else if (connections.has_screening_gate(key))
        gt = ScreeningGate;
      else if (connections.has_reservoir_gate(key))
        gt = ReservoirGate;
      else
        throw std::runtime_error("Cannot use that gate");
      outs.emplace_back(gt(key),
                        values["resistance"].as<double>(),
                        values["capacitance"].as<double>());
    }
  }
  return Impedances(outs);
}

Gates _extract_gates(const YAML::Node& dictionary, GateType gate_type) const {
  std::string       gatetype   = gate_type_to_string(gate_type);
  auto              gates_str  = dictionary[gatetype].as<std::string>();
  auto              gate_names = split(gates_str, ';');
  std::vector<Gate> gates;
  for (const auto& name : gate_names) gates.push_back(gate_type(name));
  return Gates(gates);
}

StandardConfigConnections _extract_standard_config_connections(
    const YAML::Node& config) const {
  auto screening_gates = _extract_gates(config, ScreeningGate);
  auto reservoir_gates = _extract_gates(config, ReservoirGate);
  auto plunger_gates   = _extract_gates(config, PlungerGate);
  auto barrier_gates   = _extract_gates(config, BarrierGate);
  return StandardConfigConnections(screening_gates,
                                   reservoir_gates,
                                   plunger_gates,
                                   barrier_gates,
                                   Ohmics({}));
}

Ohmics _extract_ohmics(const std::string raw) const {
  auto               gate_names = split(raw, ';');
  std::vector<Ohmic> ohmics;
  for (const auto& name : gate_names) ohmics.push_back(Ohmic(name));
  return Ohmics(ohmics);
}
BarrierGates _extract_barrier_gates(const std::string raw) const {
  auto                     gate_names = split(raw, ';');
  std::vector<BarrierGate> barriergates;
  for (const auto& name : gate_names) barriergates.push_back(BarrierGate(name));
  return device_structures::BarrierGates(ohmics);
}

BaseConnections _extract_order(
    const YAML::Node&                dictionary,
    const StandardConfigConnections& connections) const {
  auto                    config_str = dictionary["Order"].as<std::string>();
  auto                    raworder   = split(config_str, ';');
  std::vector<Connection> order;
  for (size_t i = 1; i + 1 < raworder.size(); ++i) {
    const auto& gate = raworder[i];
    if (connections.has_screening_gate(gate))
      order.push_back(ScreeningGate(gate));
    else if (connections.has_barrier_gate(gate))
      order.push_back(BarrierGate(gate));
    else if (connections.has_plunger_gate(gate))
      order.push_back(PlungerGate(gate));
    else
      order.push_back(ReservoirGate(gate));
  }
  order.insert(order.begin(), Ohmic(raworder.front()));
  order.push_back(Ohmic(raworder.back()));
  return BaseConnections(order);
}

// Utility: split string by delimiter
std::vector<std::string> split(const std::string& s, char delim) const {
  std::vector<std::string> elems;
  std::stringstream        ss(s);
  std::string              item;
  while (std::getline(ss, item, delim)) elems.push_back(item);
  return elems;
}

// Utility: convert GateType to string
std::string gate_type_to_string(GateType gt) const {
  // Implement this based on your GateType enum/class
}

}  // namespace falcon_core::physics::config
