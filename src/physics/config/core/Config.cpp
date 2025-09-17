#include "falcon_core/physics/config/core/Config.hpp"

#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

namespace falcon_core::physics::config::core {
Config::Config() = default;
Config::Config(
    const device_structures::ScreeningGatesSP& screening_gates,
    const device_structures::PlungerGatesSP&   plunger_gates,
    const device_structures::OhmicsSP&         ohmics,
    const device_structures::BarrierGatesSP&   barrier_gates,
    const device_structures::ReservoirGatesSP& reservoir_gates,
    const generic::MapSP<autotuner_interfaces::names::Gname, Group> groups,
    const device_structures::ImpedancesSP&                          wiring_DC,
    const VoltageConstraintsSP&                                     constraints)
    : StandardConfigConnections(screening_gates,
                                reservoir_gates,
                                plunger_gates,
                                barrier_gates,
                                ohmics),
      _groups(groups),
      _wiring_DC(wiring_DC),
      _voltage_constraints(constraints) {
  _num_unique_channels = static_cast<int>(get_all_gnames().size());
  if (_num_unique_channels <= 0)
    throw std::runtime_error("No unique channels found in config.");
  compile_channels();
  check_group_consistency();
  check_impedance_consistency();
}
void Config::check_impedance_consistency() const {
  if (!_wiring_DC || _wiring_DC->empty()) return;
  for (const device_structures::BaseConnectionSP& connection :
       *get_all_connections()) {
    if (!std::any_of(wiring_DC()->begin(),
                     wiring_DC()->end(),
                     [&](const device_structures::ImpedanceSP& imp) {
                       return imp->connection() == connection;
                     })) {
      throw std::runtime_error(
          "Connection not in wiring_DC. Include all or none.");
    }
  }
}

void Config::check_group_consistency() const {
  device_structures::ScreeningGates sgates;
  device_structures::ReservoirGates rgates;
  device_structures::PlungerGates   pgates;
  device_structures::BarrierGates   bgates;
  device_structures::Ohmics         os;
  for (const GroupSP& group : get_all_groups()) {
    sgates.insert(sgates.end(),
                  group->screening_gates()->begin(),
                  group->screening_gates()->end());
    rgates.insert(rgates.end(),
                  group->reservoir_gates()->begin(),
                  group->reservoir_gates()->end());
    pgates.insert(pgates.end(),
                  group->plunger_gates()->begin(),
                  group->plunger_gates()->end());
    bgates.insert(bgates.end(),
                  group->barrier_gates()->begin(),
                  group->barrier_gates()->end());
    os.insert(os.end(), group->ohmics()->begin(), group->ohmics()->end());
  }
  if (sgates != *screening_gates()) {
    throw std::logic_error(
        "Inconsistent between the groups and the total config for "
        "screening_gates");
  }
  if (rgates != *reservoir_gates()) {
    throw std::logic_error(
        "Inconsistent between the groups and the total config for "
        "reservoir_gates");
  }
  if (pgates != *plunger_gates()) {
    throw std::logic_error(
        "Inconsistent between the groups and the total config for "
        "plunger_gates");
  }
  if (bgates != *barrier_gates()) {
    throw std::logic_error(
        "Inconsistent between the groups and the total config for "
        "barrier_gates");
  }
  if (os != *ohmics()) {
    throw std::logic_error(
        "Inconsistent between the groups and the total config for "
        "ohmics");
  }
}

int Config::num_unique_channels() const { return _num_unique_channels; }
VoltageConstraintsSP Config::voltage_constraints() const {
  return _voltage_constraints;
}
generic::MapSP<autotuner_interfaces::names::Gname, Group> Config::groups()
    const {
  return _groups;
}
device_structures::ImpedancesSP Config::wiring_DC() const { return _wiring_DC; }
autotuner_interfaces::names::ChannelsSP Config::channels() const {
  return _channels;
}
device_structures::ImpedanceSP Config::get_impedance(
    const device_structures::BaseConnection& connection) const {
  if (!wiring_DC()) return nullptr;
  for (const device_structures::ImpedanceSP& imp : *wiring_DC()) {
    if (*imp->connection() == connection) return imp;
  }
  return nullptr;
}

std::vector<autotuner_interfaces::names::GnameSP> Config::get_all_gnames()
    const {
  return groups()->keys();
}

std::vector<GroupSP> Config::get_all_groups() const {
  return groups()->values();
}

void Config::compile_channels() const {
  for (const GroupSP& group : groups()->values()) {
    channels()->push_back(group->name());
  }
}

bool Config::has_channel(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channels()) return false;
  for (const autotuner_interfaces::names::ChannelSP& ch : *channels()) {
    if (*ch == *channel) return true;
  }
  return false;
}

bool Config::has_gname(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!groups()) return false;
  for (const autotuner_interfaces::names::GnameSP& gn : get_all_gnames()) {
    if (*gn == *gname) return true;
  }
  return false;
}

GroupSP Config::select_group(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (has_gname(gname)) {
    return groups()->at(gname);
  }
  return nullptr;
}

int Config::get_dot_number(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel)) return 0;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_channel(channel)) return group->num_dots();
  }
  return 0;
}

std::vector<autotuner_interfaces::names::GnameSP>
Config::get_charge_sense_groups() const {
  std::vector<autotuner_interfaces::names::GnameSP> outs;
  if (!groups()) return outs;
  for (const auto& it : *groups()) {
    if (it.second->is_charge_sensor()) {
      outs.push_back(it.first);
    }
  }
  return outs;
}

bool Config::ohmic_in_charge_sensor(
    const device_structures::OhmicSP& ohmic) const {
  if (!has_ohmic(ohmic)) return false;
  for (const GroupSP& group : get_all_groups()) {
    if (group->is_charge_sensor() && group->has_ohmic(ohmic)) {
      return true;
    }
  }
  return false;
}

device_structures::OhmicSP Config::get_associated_ohmic(
    const device_structures::ReservoirGateSP& reservoir_gate) const {
  for (const GroupSP& group : get_all_groups()) {
    if (!group->has_gate(reservoir_gate)) continue;
    auto left_reservoir  = group->order()->left_reservoir();
    auto right_reservoir = group->order()->right_reservoir();
    if (left_reservoir->name() == reservoir_gate->name()) {
      return left_reservoir->ohmic();
    }
    if (right_reservoir->name() == reservoir_gate->name()) {
      return right_reservoir->ohmic();
    }
  }
  return nullptr;
}

autotuner_interfaces::names::ChannelsSP Config::get_current_channels() const {
  return channels();
}

autotuner_interfaces::names::GnameSP Config::get_gname(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel)) return nullptr;
  for (const auto& it : *groups()) {
    if (it.second->has_channel(channel)) {
      return it.first;
    }
  }
  return nullptr;
}

device_structures::BarrierGatesSP Config::get_group_barrier_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->barrier_gates();
  return nullptr;
}

device_structures::PlungerGatesSP Config::get_group_plunger_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->plunger_gates();
  return nullptr;
}

device_structures::ReservoirGatesSP Config::get_group_reservoir_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->reservoir_gates();
  return nullptr;
}

device_structures::ScreeningGatesSP Config::get_group_screening_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->screening_gates();
  return nullptr;
}

device_structures::BaseConnectionsSP Config::get_group_dot_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->dot_gates();
  return nullptr;
}

device_structures::BaseConnectionsSP Config::get_group_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_all_gates();
  return nullptr;
}

device_structures::BarrierGatesSP Config::get_channel_barrier_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_barrier_gates(gname);
}

device_structures::PlungerGatesSP Config::get_channel_plunger_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_plunger_gates(gname);
}

device_structures::ReservoirGatesSP Config::get_channel_reservoir_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_reservoir_gates(gname);
}

device_structures::ScreeningGatesSP Config::get_channel_screening_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_screening_gates(gname);
}

device_structures::BaseConnectionsSP Config::get_channel_dot_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_dot_gates(gname);
}

device_structures::BaseConnectionsSP Config::get_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_dot_gates(gname);
}

device_structures::OhmicsSP Config::get_channel_ohmics(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel)) return nullptr;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_channel(channel)) {
      return group->get_all_ohmics();
    }
  }
  return nullptr;
}

device_structures::BaseConnectionsSP Config::get_channel_order_no_ohmics(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  GroupSP group = select_group(gname);
  if (!group) return nullptr;
  geometries::GateGeometryArray1DSP order = group->order();
  if (!order) return nullptr;
  device_structures::BaseConnectionsSP typed_order;
  for (const auto& gate : *order) {
    if (gate->is_dot_gate()) {
      typed_order->push_back(gate);
    }
    if (gate->is_reservoir_gate()) {
      typed_order->push_back(gate);
    }
  }
  return typed_order;
}

int Config::get_num_unique_channels() const { return num_unique_channels(); }

autotuner_interfaces::names::ChannelsSP Config::return_channels_from_gate(
    const device_structures::BaseConnectionSP& gate) const {
  if (!has_gate(gate)) return nullptr;
  std::set<autotuner_interfaces::names::ChannelSP> channels;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_gate(gate)) {
      channels.insert(group->name());
    }
  }
  return std::make_shared<autotuner_interfaces::names::Channels>(
      std::vector<autotuner_interfaces::names::ChannelSP>(channels.begin(),
                                                          channels.end()));
}

autotuner_interfaces::names::ChannelSP Config::return_channel_from_gate(
    const device_structures::BaseConnectionSP& gate) const {
  autotuner_interfaces::names::ChannelsSP channels =
      return_channels_from_gate(gate);
  if (!channels || channels->empty()) return nullptr;
  return channels->at(0);
}

bool Config::ohmic_in_channel(
    const device_structures::OhmicSP&             ohmic,
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel) || !has_ohmic(ohmic)) return false;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_channel(channel)) {
      return group->has_ohmic(ohmic);
    }
  }
  return false;
}

std::pair<device_structures::BaseConnectionSP,
          device_structures::BaseConnectionSP>
Config::get_dot_channel_neighbors(
    const device_structures::BaseConnectionSP& dotgate) const {
  autotuner_interfaces::names::ChannelSP channel =
      return_channel_from_gate(dotgate);
  if (!channel) return {nullptr, nullptr};
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  if (!gname) return {nullptr, nullptr};
  GroupSP group = select_group(gname);
  if (!group) return {nullptr, nullptr};

  auto all_dot_gates = group->order()->all_dot_gates();
  for (const auto& connection : *all_dot_gates) {
    if (dotgate->name() == connection->name()) {
      auto left_neighbor  = connection->left_neighbor();
      auto right_neighbor = connection->right_neighbor();
      return {left_neighbor, right_neighbor};
    }
  }
  return {nullptr, nullptr};
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::BarrierGates>
Config::get_barrier_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::BarrierGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->barrier_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::PlungerGates>
Config::get_plunger_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::PlungerGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->plunger_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::ReservoirGates>
Config::get_reservoir_gate_dict() const {
  auto out =
      std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                    device_structures::ReservoirGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->reservoir_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::ScreeningGates>
Config::get_screening_gate_dict() const {
  auto out =
      std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                    device_structures::ScreeningGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->screening_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::BaseConnections>
Config::get_dot_gate_dict() const {
  auto out =
      std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                    device_structures::BaseConnections>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->dot_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::BaseConnections>
Config::get_gate_dict() const {
  auto out =
      std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                    device_structures::BaseConnections>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_all_gates();
    out->insert(group->name(), gates);
  }
  return out;
}
device_structures::BarrierGatesSP Config::get_isolated_barrier_gates() const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_barrier_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::BarrierGatesSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}

device_structures::PlungerGatesSP Config::get_isolated_plunger_gates() const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_plunger_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::PlungerGatesSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::ReservoirGatesSP Config::get_isolated_reservoir_gates()
    const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_reservoir_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ReservoirGatesSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::ScreeningGatesSP Config::get_isolated_screening_gates()
    const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_screening_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ScreeningGatesSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::BaseConnectionsSP Config::get_isolated_dot_gates() const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_dot_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::BaseConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::BaseConnectionsSP Config::get_isolated_gates() const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::BaseConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}

device_structures::BarrierGatesSP Config::get_shared_barrier_gates() const {
  std::vector<device_structures::BarrierGateSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_barrier_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                              gate_count;
  std::unordered_map<std::string, device_structures::BarrierGateSP> gate_map;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
    gate_map[gate->name()] = gate;
  }
  std::vector<std::pair<std::string, int>> shared;
  for (const auto& it : gate_count) {
    if (it.second > 1) {
      shared.emplace_back(it.first, it.second);
    }
  }
  std::sort(
      shared.begin(),
      shared.end(),
      [](const std::pair<std::string, int>& a,
         const std::pair<std::string, int>& b) { return a.second > b.second; });
  auto result = std::make_shared<
      typename device_structures::BarrierGatesSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}

device_structures::PlungerGatesSP Config::get_shared_plunger_gates() const {
  std::vector<device_structures::PlungerGateSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_plunger_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                              gate_count;
  std::unordered_map<std::string, device_structures::PlungerGateSP> gate_map;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
    gate_map[gate->name()] = gate;
  }
  std::vector<std::pair<std::string, int>> shared;
  for (const auto& it : gate_count) {
    if (it.second > 1) {
      shared.emplace_back(it.first, it.second);
    }
  }
  std::sort(
      shared.begin(),
      shared.end(),
      [](const std::pair<std::string, int>& a,
         const std::pair<std::string, int>& b) { return a.second > b.second; });
  auto result = std::make_shared<
      typename device_structures::PlungerGatesSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::ReservoirGatesSP Config::get_shared_reservoir_gates() const {
  std::vector<device_structures::ReservoirGateSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_reservoir_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  std::unordered_map<std::string, device_structures::ReservoirGateSP> gate_map;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
    gate_map[gate->name()] = gate;
  }
  std::vector<std::pair<std::string, int>> shared;
  for (const auto& it : gate_count) {
    if (it.second > 1) {
      shared.emplace_back(it.first, it.second);
    }
  }
  std::sort(
      shared.begin(),
      shared.end(),
      [](const std::pair<std::string, int>& a,
         const std::pair<std::string, int>& b) { return a.second > b.second; });
  auto result = std::make_shared<
      typename device_structures::ReservoirGatesSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::ScreeningGatesSP Config::get_shared_screening_gates() const {
  std::vector<device_structures::ScreeningGateSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_screening_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  std::unordered_map<std::string, device_structures::ScreeningGateSP> gate_map;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
    gate_map[gate->name()] = gate;
  }
  std::vector<std::pair<std::string, int>> shared;
  for (const auto& it : gate_count) {
    if (it.second > 1) {
      shared.emplace_back(it.first, it.second);
    }
  }
  std::sort(
      shared.begin(),
      shared.end(),
      [](const std::pair<std::string, int>& a,
         const std::pair<std::string, int>& b) { return a.second > b.second; });
  auto result = std::make_shared<
      typename device_structures::ScreeningGatesSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::BaseConnectionsSP Config::get_shared_dot_gates() const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_dot_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  std::unordered_map<std::string, device_structures::BaseConnectionSP> gate_map;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
    gate_map[gate->name()] = gate;
  }
  std::vector<std::pair<std::string, int>> shared;
  for (const auto& it : gate_count) {
    if (it.second > 1) {
      shared.emplace_back(it.first, it.second);
    }
  }
  std::sort(
      shared.begin(),
      shared.end(),
      [](const std::pair<std::string, int>& a,
         const std::pair<std::string, int>& b) { return a.second > b.second; });
  auto result = std::make_shared<
      typename device_structures::BaseConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::BaseConnectionsSP Config::get_shared_gates() const {
  std::vector<device_structures::BaseConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connection = group.second->get_gate();
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  std::unordered_map<std::string, device_structures::BaseConnectionSP> gate_map;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
    gate_map[gate->name()] = gate;
  }
  std::vector<std::pair<std::string, int>> shared;
  for (const auto& it : gate_count) {
    if (it.second > 1) {
      shared.emplace_back(it.first, it.second);
    }
  }
  std::sort(
      shared.begin(),
      shared.end(),
      [](const std::pair<std::string, int>& a,
         const std::pair<std::string, int>& b) { return a.second > b.second; });
  auto result = std::make_shared<
      typename device_structures::BaseConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}

// BarrierGate
device_structures::BarrierGatesSP Config::get_isolated_channel_barrier_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::BarrierGatesSP channel_gates =
      get_channel_barrier_gates(channel);
  device_structures::BarrierGatesSP isolated_gates =
      get_isolated_barrier_gates();
  if (!channel_gates)
    return std::make_shared<
        typename device_structures::BarrierGatesSP::element_type>();
  auto result = std::make_shared<
      typename device_structures::BarrierGatesSP::element_type>();
  std::unordered_set<std::string> isolated_names;
  for (const auto& gate : *isolated_gates) {
    isolated_names.insert(gate->name());
  }
  for (const auto& gate : *channel_gates) {
    if (isolated_names.count(gate->name())) {
      result->push_back(gate);
    }
  }
  return result;
}

// PlungerGate
device_structures::PlungerGatesSP Config::get_isolated_channel_plunger_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::PlungerGatesSP channel_gates =
      get_channel_plunger_gates(channel);
  device_structures::PlungerGatesSP isolated_gates =
      get_isolated_plunger_gates();
  if (!channel_gates)
    return std::make_shared<
        typename device_structures::PlungerGatesSP::element_type>();
  auto result = std::make_shared<
      typename device_structures::PlungerGatesSP::element_type>();
  std::unordered_set<std::string> isolated_names;
  for (const auto& gate : *isolated_gates) {
    isolated_names.insert(gate->name());
  }
  for (const auto& gate : *channel_gates) {
    if (isolated_names.count(gate->name())) {
      result->push_back(gate);
    }
  }
  return result;
}

// ReservoirGate
device_structures::ReservoirGatesSP
Config::get_isolated_channel_reservoir_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ReservoirGatesSP channel_gates =
      get_channel_reservoir_gates(channel);
  device_structures::ReservoirGatesSP isolated_gates =
      get_isolated_reservoir_gates();
  if (!channel_gates)
    return std::make_shared<
        typename device_structures::ReservoirGatesSP::element_type>();
  auto result = std::make_shared<
      typename device_structures::ReservoirGatesSP::element_type>();
  std::unordered_set<std::string> isolated_names;
  for (const auto& gate : *isolated_gates) {
    isolated_names.insert(gate->name());
  }
  for (const auto& gate : *channel_gates) {
    if (isolated_names.count(gate->name())) {
      result->push_back(gate);
    }
  }
  return result;
}

// ScreeningGate
device_structures::ScreeningGatesSP
Config::get_isolated_channel_screening_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ScreeningGatesSP channel_gates =
      get_channel_screening_gates(channel);
  device_structures::ScreeningGatesSP isolated_gates =
      get_isolated_screening_gates();
  if (!channel_gates)
    return std::make_shared<
        typename device_structures::ScreeningGatesSP::element_type>();
  auto result = std::make_shared<
      typename device_structures::ScreeningGatesSP::element_type>();
  std::unordered_set<std::string> isolated_names;
  for (const auto& gate : *isolated_gates) {
    isolated_names.insert(gate->name());
  }
  for (const auto& gate : *channel_gates) {
    if (isolated_names.count(gate->name())) {
      result->push_back(gate);
    }
  }
  return result;
}

// DotGate
device_structures::BaseConnectionsSP Config::get_isolated_channel_dot_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::BaseConnectionsSP channel_gates =
      get_channel_dot_gates(channel);
  device_structures::BaseConnectionsSP isolated_gates =
      get_isolated_dot_gates();
  if (!channel_gates)
    return std::make_shared<
        typename device_structures::BaseConnectionsSP::element_type>();
  auto result = std::make_shared<
      typename device_structures::BaseConnectionsSP::element_type>();
  std::unordered_set<std::string> isolated_names;
  for (const auto& gate : *isolated_gates) {
    isolated_names.insert(gate->name());
  }
  for (const auto& gate : *channel_gates) {
    if (isolated_names.count(gate->name())) {
      result->push_back(gate);
    }
  }
  return result;
}

// Gate
device_structures::BaseConnectionsSP Config::get_isolated_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::BaseConnectionsSP channel_gates =
      get_channel_gates(channel);
  device_structures::BaseConnectionsSP isolated_gates = get_isolated_gates();
  if (!channel_gates)
    return std::make_shared<
        typename device_structures::BaseConnectionsSP::element_type>();
  auto result = std::make_shared<
      typename device_structures::BaseConnectionsSP::element_type>();
  std::unordered_set<std::string> isolated_names;
  for (const auto& gate : *isolated_gates) {
    isolated_names.insert(gate->name());
  }
  for (const auto& gate : *channel_gates) {
    if (isolated_names.count(gate->name())) {
      result->push_back(gate);
    }
  }
  return result;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::BarrierGates>
Config::get_isolated_barrier_gates_by_channel() const {
  auto out = generic::MapSP<autotuner_interfaces::names::Channel,
                            device_structures::BarrierGates>();
  device_structures::BarrierGatesSP unshared_gates =
      get_isolated_barrier_gates();
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::BarrierGates>
                                          gate_dict = get_barrier_gate_dict();
  autotuner_interfaces::names::ChannelsSP channels  = get_current_channels();
  std::unordered_set<std::string>         unshared_names;
  for (const auto& gate : *unshared_gates) {
    unshared_names.insert(gate->name());
  }
  for (const auto& channel : *channels) {
    auto gates_it = gate_dict->find(channel);
    if (gates_it != gate_dict->end()) {
      const auto& gates        = gates_it->second;
      bool        all_unshared = true;
      for (const auto& gate : *gates) {
        if (!unshared_names.count(gate->name())) {
          all_unshared = false;
          break;
        }
      }
      if (all_unshared) {
        out->insert(channel, gates);
      }
    }
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::PlungerGates>
Config::get_isolated_plunger_gates_by_channel() const {
  auto out = generic::MapSP<autotuner_interfaces::names::Channel,
                            device_structures::PlungerGates>();
  device_structures::PlungerGatesSP unshared_gates =
      get_isolated_plunger_gates();
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::PlungerGates>
                                          gate_dict = get_plunger_gate_dict();
  autotuner_interfaces::names::ChannelsSP channels  = get_current_channels();
  std::unordered_set<std::string>         unshared_names;
  for (const auto& gate : *unshared_gates) {
    unshared_names.insert(gate->name());
  }
  for (const auto& channel : *channels) {
    auto gates_it = gate_dict->find(channel);
    if (gates_it != gate_dict->end()) {
      const auto& gates        = gates_it->second;
      bool        all_unshared = true;
      for (const auto& gate : *gates) {
        if (!unshared_names.count(gate->name())) {
          all_unshared = false;
          break;
        }
      }
      if (all_unshared) {
        out->insert(channel, gates);
      }
    }
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::ReservoirGates>
Config::get_isolated_reservoir_gates_by_channel() const {
  auto out = generic::MapSP<autotuner_interfaces::names::Channel,
                            device_structures::ReservoirGates>();
  device_structures::ReservoirGatesSP unshared_gates =
      get_isolated_reservoir_gates();
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::ReservoirGates>
                                          gate_dict = get_reservoir_gate_dict();
  autotuner_interfaces::names::ChannelsSP channels  = get_current_channels();
  std::unordered_set<std::string>         unshared_names;
  for (const auto& gate : *unshared_gates) {
    unshared_names.insert(gate->name());
  }
  for (const auto& channel : *channels) {
    auto gates_it = gate_dict->find(channel);
    if (gates_it != gate_dict->end()) {
      const auto& gates        = gates_it->second;
      bool        all_unshared = true;
      for (const auto& gate : *gates) {
        if (!unshared_names.count(gate->name())) {
          all_unshared = false;
          break;
        }
      }
      if (all_unshared) {
        out->insert(channel, gates);
      }
    }
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::ScreeningGates>
Config::get_isolated_screening_gates_by_channel() const {
  auto out = generic::MapSP<autotuner_interfaces::names::Channel,
                            device_structures::ScreeningGates>();
  device_structures::ScreeningGatesSP unshared_gates =
      get_isolated_screening_gates();
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::ScreeningGates>
                                          gate_dict = get_screening_gate_dict();
  autotuner_interfaces::names::ChannelsSP channels  = get_current_channels();
  std::unordered_set<std::string>         unshared_names;
  for (const auto& gate : *unshared_gates) {
    unshared_names.insert(gate->name());
  }
  for (const auto& channel : *channels) {
    auto gates_it = gate_dict->find(channel);
    if (gates_it != gate_dict->end()) {
      const auto& gates        = gates_it->second;
      bool        all_unshared = true;
      for (const auto& gate : *gates) {
        if (!unshared_names.count(gate->name())) {
          all_unshared = false;
          break;
        }
      }
      if (all_unshared) {
        out->insert(channel, gates);
      }
    }
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::BaseConnections>
Config::get_isolated_dot_gates_by_channel() const {
  auto out = generic::MapSP<autotuner_interfaces::names::Channel,
                            device_structures::BaseConnections>();
  device_structures::BaseConnectionsSP unshared_gates =
      get_isolated_dot_gates();
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::BaseConnections>
                                          gate_dict = get_dot_gate_dict();
  autotuner_interfaces::names::ChannelsSP channels  = get_current_channels();
  std::unordered_set<std::string>         unshared_names;
  for (const auto& gate : *unshared_gates) {
    unshared_names.insert(gate->name());
  }
  for (const auto& channel : *channels) {
    auto gates_it = gate_dict->find(channel);
    if (gates_it != gate_dict->end()) {
      const auto& gates        = gates_it->second;
      bool        all_unshared = true;
      for (const auto& gate : *gates) {
        if (!unshared_names.count(gate->name())) {
          all_unshared = false;
          break;
        }
      }
      if (all_unshared) {
        out->insert(channel, gates);
      }
    }
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::BaseConnections>
Config::get_isolated_gates_by_channel() const {
  auto out = generic::MapSP<autotuner_interfaces::names::Channel,
                            device_structures::BaseConnections>();
  device_structures::BaseConnectionsSP unshared_gates = get_isolated_gates();
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::BaseConnections>
                                          gate_dict = get_gate_dict();
  autotuner_interfaces::names::ChannelsSP channels  = get_current_channels();
  std::unordered_set<std::string>         unshared_names;
  for (const auto& gate : *unshared_gates) {
    unshared_names.insert(gate->name());
  }
  for (const auto& channel : *channels) {
    auto gates_it = gate_dict->find(channel);
    if (gates_it != gate_dict->end()) {
      const auto& gates        = gates_it->second;
      bool        all_unshared = true;
      for (const auto& gate : *gates) {
        if (!unshared_names.count(gate->name())) {
          all_unshared = false;
          break;
        }
      }
      if (all_unshared) {
        out->insert(channel, gates);
      }
    }
  }
  return out;
}
device_structures::GateRelationsSP Config::generate_gate_relations() const {
  device_structures::GateRelations     out;
  device_structures::BaseConnectionsSP all_gates  = get_all_gates();
  std::vector<GroupSP>                 all_groups = get_all_groups();
  for (const device_structures::BaseConnectionSP& gate : *all_gates) {
    device_structures::BaseConnectionsSP neighbors;
    for (const GroupSP& group : all_groups) {
      if (!group->has_gate(gate)) continue;
      device_structures::BaseConnectionsSP group_neighbors =
          group->order()->query_neighbors(gate);
      neighbors->insert(
          neighbors->end(), group_neighbors->begin(), group_neighbors->end());
    }
    out[gate] = neighbors;
  }
  return std::make_shared<device_structures::GateRelations>(out);
}
}  // namespace falcon_core::physics::config::core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Config)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::core::StandardConfigConnections,
    falcon_core::physics::config::core::Config)
