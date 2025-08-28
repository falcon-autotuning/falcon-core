#include "falcon_core/physics/config/core/Config.hpp"

#include <memory>

#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

using namespace falcon_core::physics::config::core;
namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Config::Config() = default;
Config::Config(const ScreeningGatesSP&            screening_gates,
               const PlungerGatesSP&              plunger_gates,
               const OhmicsSP&                    ohmics,
               const BarrierGatesSP&              barrier_gates,
               const ReservoirGatesSP&            reservoir_gates,
               const generic::MapSP<Gname, Group> groups,
               const ImpedancesSP&                wiring_DC,
               const VoltageConstraintsSP&        constraints)
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
  for (const BaseConnectionSP& connection : *get_all_connections()) {
    if (!std::any_of(wiring_DC()->begin(),
                     wiring_DC()->end(),
                     [&](const ImpedanceSP& imp) {
                       return imp->connection() == connection;
                     })) {
      throw std::runtime_error(
          "Connection not in wiring_DC. Include all or none.");
    }
  }
}

void Config::check_group_consistency() const {
  ScreeningGates sgates;
  ReservoirGates rgates;
  PlungerGates   pgates;
  BarrierGates   bgates;
  Ohmics         os;
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
generic::MapSP<Gname, Group> Config::groups() const { return _groups; }
ImpedancesSP                 Config::wiring_DC() const { return _wiring_DC; }
ChannelsSP                   Config::channels() const { return _channels; }
ImpedanceSP Config::get_impedance(const BaseConnection& connection) const {
  if (!wiring_DC()) return nullptr;
  for (const ImpedanceSP& imp : *wiring_DC()) {
    if (*imp->connection() == connection) return imp;
  }
  return nullptr;
}

std::vector<GnameSP> Config::get_all_gnames() const { return groups()->keys(); }

std::vector<GroupSP> Config::get_all_groups() const {
  return groups()->values();
}

void Config::compile_channels() const {
  channels()->clear();
  channels()->reserve(groups()->size());
  for (const GroupSP& group : groups()->values()) {
    channels()->push_back(group->name());
  }
}

bool Config::has_channel(const ChannelSP& channel) const {
  if (!channels()) return false;
  for (const ChannelSP& ch : *channels()) {
    if (*ch == *channel) return true;
  }
  return false;
}

bool Config::has_gname(const GnameSP& gname) const {
  if (!groups()) return false;
  for (const GnameSP& gn : get_all_gnames()) {
    if (*gn == *gname) return true;
  }
  return false;
}

GroupSP Config::select_group(const GnameSP& gname) const {
  if (has_gname(gname)) {
    return groups()->at(gname);
  }
  return nullptr;
}

int Config::get_dot_number(const ChannelSP& channel) const {
  if (!has_channel(channel)) return 0;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_channel(channel)) return group->num_dots();
  }
  return 0;
}

std::vector<GnameSP> Config::get_charge_sense_groups() const {
  std::vector<GnameSP> outs;
  if (!groups()) return outs;
  for (const auto& it : *groups()) {
    if (it.second->is_charge_sensor()) {
      outs.push_back(it.first);
    }
  }
  return outs;
}

bool Config::ohmic_in_charge_sensor(const OhmicSP& ohmic) const {
  if (!has_ohmic(ohmic)) return false;
  for (const GroupSP& group : get_all_groups()) {
    if (group->is_charge_sensor() && group->has_ohmic(ohmic)) {
      return true;
    }
  }
  return false;
}

OhmicSP Config::get_associated_ohmic(
    const ReservoirGateSP& reservoir_gate) const {
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

ChannelsSP Config::get_current_channels() const { return channels(); }

GnameSP Config::get_gname(const ChannelSP& channel) const {
  if (!has_channel(channel)) return nullptr;
  for (const auto& it : *groups()) {
    if (it.second->has_channel(channel)) {
      return it.first;
    }
  }
  return nullptr;
}

template <typename GateSPT, typename GatesSPT>
GatesSPT get_group_gates_impl(const Config*  config,
                              const GnameSP& gname,
                              const GateSPT& type) {
  if (!config->has_gname(gname)) return nullptr;
  GroupSP group = config->select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

BarrierGatesSP Config::get_group_gates(const GnameSP&       gname,
                                       const BarrierGateSP& type) const {
  return get_group_gates_impl<BarrierGateSP, BarrierGatesSP>(this, gname, type);
}

PlungerGatesSP Config::get_group_gates(const GnameSP&       gname,
                                       const PlungerGateSP& type) const {
  return get_group_gates_impl<PlungerGateSP, PlungerGatesSP>(this, gname, type);
}

ReservoirGatesSP Config::get_group_gates(const GnameSP&         gname,
                                         const ReservoirGateSP& type) const {
  return get_group_gates_impl<ReservoirGateSP, ReservoirGatesSP>(
      this, gname, type);
}

ScreeningGatesSP Config::get_group_gates(const GnameSP&         gname,
                                         const ScreeningGateSP& type) const {
  return get_group_gates_impl<ScreeningGateSP, ScreeningGatesSP>(
      this, gname, type);
}

DotGatesSP Config::get_group_gates(const GnameSP&   gname,
                                   const DotGateSP& type) const {
  return get_group_gates_impl<DotGateSP, DotGatesSP>(this, gname, type);
}

GatesSP Config::get_group_gates(const GnameSP& gname,
                                const GateSP&  type) const {
  return get_group_gates_impl<GateSP, GatesSP>(this, gname, type);
}

template <typename GateSPT, typename GatesSPT>
GatesSPT get_channel_gates_impl(const Config*    config,
                                const ChannelSP& channel,
                                const GateSPT&   type) {
  GnameSP gname = config->get_gname(channel);
  if (!gname) return nullptr;
  return config->get_group_gates(gname, type);
}

BarrierGatesSP Config::get_channel_gates(const ChannelSP&     channel,
                                         const BarrierGateSP& type) const {
  return get_channel_gates_impl<BarrierGateSP, BarrierGatesSP>(
      this, channel, type);
}

PlungerGatesSP Config::get_channel_gates(const ChannelSP&     channel,
                                         const PlungerGateSP& type) const {
  return get_channel_gates_impl<PlungerGateSP, PlungerGatesSP>(
      this, channel, type);
}

ReservoirGatesSP Config::get_channel_gates(const ChannelSP&       channel,
                                           const ReservoirGateSP& type) const {
  return get_channel_gates_impl<ReservoirGateSP, ReservoirGatesSP>(
      this, channel, type);
}

ScreeningGatesSP Config::get_channel_gates(const ChannelSP&       channel,
                                           const ScreeningGateSP& type) const {
  return get_channel_gates_impl<ScreeningGateSP, ScreeningGatesSP>(
      this, channel, type);
}

DotGatesSP Config::get_channel_gates(const ChannelSP& channel,
                                     const DotGateSP& type) const {
  return get_channel_gates_impl<DotGateSP, DotGatesSP>(this, channel, type);
}

GatesSP Config::get_channel_gates(const ChannelSP& channel,
                                  const GateSP&    type) const {
  return get_channel_gates_impl<GateSP, GatesSP>(this, channel, type);
}

GatesSP Config::get_all_channel_gates(const ChannelSP& channel) const {
  if (!has_channel(channel)) return nullptr;
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_all_channel_gates(channel);
    if (gates) return gates;
  }
  return nullptr;
}

OhmicsSP Config::get_channel_ohmics(const ChannelSP& channel) const {
  if (!has_channel(channel)) return nullptr;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_channel(channel)) {
      return group->get_all_ohmics();
    }
  }
  return nullptr;
}

GatesSP Config::get_channel_order_no_ohmics(const ChannelSP& channel) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  GroupSP group = select_group(gname);
  if (!group) return nullptr;
  GateGeometryArray1DSP order = group->order();
  if (!order) return nullptr;
  GatesSP typed_order;
  for (const auto& gate : *order) {
    DotGateSP dotgate = std::dynamic_pointer_cast<DotGate>(gate);
    if (dotgate) {
      typed_order->push_back(dotgate);
    }
    ReservoirGateSP reservoir_gate =
        std::dynamic_pointer_cast<ReservoirGate>(gate);
    if (reservoir_gate) {
      typed_order->push_back(reservoir_gate);
    }
  }
  return typed_order;
}

int Config::get_num_unique_channels() const { return num_unique_channels(); }

ChannelsSP Config::return_channels_from_gate(const GateSP& gate) const {
  if (!has_gate(gate)) return nullptr;
  std::set<ChannelSP> channels;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_gate(gate)) {
      channels.insert(group->name());
    }
  }
  return std::make_shared<Channels>(
      std::vector<ChannelSP>(channels.begin(), channels.end()));
}

ChannelSP Config::return_channel_from_gate(const GateSP& gate) const {
  ChannelsSP channels = return_channels_from_gate(gate);
  if (!channels || channels->empty()) return nullptr;
  return channels->at(0);
}

bool Config::ohmic_in_channel(const OhmicSP&   ohmic,
                              const ChannelSP& channel) const {
  if (!has_channel(channel) || !has_ohmic(ohmic)) return false;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_channel(channel)) {
      return group->has_ohmic(ohmic);
    }
  }
  return false;
}

std::pair<GateSP, GateSP> Config::get_dot_channel_neighbors(
    const DotGateSP& dotgate) const {
  ChannelSP channel = return_channel_from_gate(dotgate);
  if (!channel) return {nullptr, nullptr};
  GnameSP gname = get_gname(channel);
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

generic::MapSP<Channel, BarrierGates> Config::get_gate_dict(
    const BarrierGateSP& type) const {
  auto out = std::make_shared<generic::Map<Channel, BarrierGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_connections(type);
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<Channel, PlungerGates> Config::get_gate_dict(
    const PlungerGateSP& type) const {
  auto out = std::make_shared<generic::Map<Channel, PlungerGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_connections(type);
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<Channel, ReservoirGates> Config::get_gate_dict(
    const ReservoirGateSP& type) const {
  auto out = std::make_shared<generic::Map<Channel, ReservoirGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_connections(type);
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<Channel, ScreeningGates> Config::get_gate_dict(
    const ScreeningGateSP& type) const {
  auto out = std::make_shared<generic::Map<Channel, ScreeningGates>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_connections(type);
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<Channel, DotGates<DotGate>> Config::get_gate_dict(
    const DotGateSP& type) const {
  auto out = std::make_shared<generic::Map<Channel, DotGates<DotGate>>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_connections(type);
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<Channel, Gates<Gate>> Config::get_gate_dict(
    const GateSP& type) const {
  auto out = std::make_shared<generic::Map<Channel, Gates<Gate>>>();
  for (const GroupSP& group : get_all_groups()) {
    auto gates = group->get_connections(type);
    out->insert(group->name(), gates);
  }
  return out;
}
template <typename GateSPT, typename GatesSPT>
GatesSPT get_isolated_gates_impl(const std::vector<GroupSP>& groups,
                                 const GateSPT&              type) {
  std::vector<GateSPT> gates;
  for (const auto& group : groups) {
    auto connection = group->get_connection(type);
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<typename GatesSPT::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
BarrierGatesSP Config::get_isolated_gates(const BarrierGateSP& type) const {
  return get_isolated_gates_impl<BarrierGateSP, BarrierGatesSP>(
      get_all_groups(), type);
}

PlungerGatesSP Config::get_isolated_gates(const PlungerGateSP& type) const {
  return get_isolated_gates_impl<PlungerGateSP, PlungerGatesSP>(
      get_all_groups(), type);
}
ReservoirGatesSP Config::get_isolated_gates(const ReservoirGateSP& type) const {
  return get_isolated_gates_impl<ReservoirGateSP, ReservoirGatesSP>(
      get_all_groups(), type);
}
ScreeningGatesSP Config::get_isolated_gates(const ScreeningGateSP& type) const {
  return get_isolated_gates_impl<ScreeningGateSP, ScreeningGatesSP>(
      get_all_groups(), type);
}
DotGatesSP Config::get_isolated_gates(const DotGateSP& type) const {
  return get_isolated_gates_impl<DotGateSP, DotGatesSP>(get_all_groups(), type);
}
GatesSP Config::get_isolated_gates(const GateSP& type) const {
  return get_isolated_gates_impl<GateSP, GatesSP>(get_all_groups(), type);
}

template <typename GateSPT, typename GatesSPT>
GatesSPT get_shared_gates_impl(const std::vector<GroupSP>& groups,
                               const GateSPT&              type) {
  std::vector<GateSPT> gates;
  for (const auto& group : groups) {
    auto connection = group->get_connection(type);
    if (connection) gates.push_back(connection);
  }
  if (gates.empty()) {
    throw std::runtime_error("No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>     gate_count;
  std::unordered_map<std::string, GateSPT> gate_map;
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
  auto result = std::make_shared<typename GatesSPT::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
BarrierGatesSP Config::get_shared_gates(const BarrierGateSP& type) const {
  return get_shared_gates_impl<BarrierGateSP, BarrierGatesSP>(get_all_groups(),
                                                              type);
}

PlungerGatesSP Config::get_shared_gates(const PlungerGateSP& type) const {
  return get_shared_gates_impl<PlungerGateSP, PlungerGatesSP>(get_all_groups(),
                                                              type);
}
ReservoirGatesSP Config::get_shared_gates(const ReservoirGateSP& type) const {
  return get_shared_gates_impl<ReservoirGateSP, ReservoirGatesSP>(
      get_all_groups(), type);
}
ScreeningGatesSP Config::get_shared_gates(const ScreeningGateSP& type) const {
  return get_shared_gates_impl<ScreeningGateSP, ScreeningGatesSP>(
      get_all_groups(), type);
}
DotGatesSP Config::get_shared_gates(const DotGateSP& type) const {
  return get_shared_gates_impl<DotGateSP, DotGatesSP>(get_all_groups(), type);
}
GatesSP Config::get_shared_gates(const GateSP& type) const {
  return get_shared_gates_impl<GateSP, GatesSP>(get_all_groups(), type);
}
template <typename GateSPT, typename GatesSPT>
GatesSPT get_isolated_channel_gates_impl(const GatesSPT& isolated_gates,
                                         const GatesSPT& channel_gates) {
  if (!channel_gates)
    return std::make_shared<typename GatesSPT::element_type>();
  auto result = std::make_shared<typename GatesSPT::element_type>();
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

// BarrierGate
BarrierGatesSP Config::get_isolated_channel_gates(
    const BarrierGateSP& type, const ChannelSP& channel) const {
  return get_isolated_channel_gates_impl<BarrierGateSP, BarrierGatesSP>(
      get_isolated_gates(type), get_channel_gates(channel, type));
}

// PlungerGate
PlungerGatesSP Config::get_isolated_channel_gates(
    const PlungerGateSP& type, const ChannelSP& channel) const {
  return get_isolated_channel_gates_impl<PlungerGateSP, PlungerGatesSP>(
      get_isolated_gates(type), get_channel_gates(channel, type));
}

// ReservoirGate
ReservoirGatesSP Config::get_isolated_channel_gates(
    const ReservoirGateSP& type, const ChannelSP& channel) const {
  return get_isolated_channel_gates_impl<ReservoirGateSP, ReservoirGatesSP>(
      get_isolated_gates(type), get_channel_gates(channel, type));
}

// ScreeningGate
ScreeningGatesSP Config::get_isolated_channel_gates(
    const ScreeningGateSP& type, const ChannelSP& channel) const {
  return get_isolated_channel_gates_impl<ScreeningGateSP, ScreeningGatesSP>(
      get_isolated_gates(type), get_channel_gates(channel, type));
}

// DotGate
DotGatesSP Config::get_isolated_channel_gates(const DotGateSP& type,
                                              const ChannelSP& channel) const {
  return get_isolated_channel_gates_impl<DotGateSP, DotGatesSP>(
      get_isolated_gates(type), get_channel_gates(channel, type));
}

// Gate
GatesSP Config::get_isolated_channel_gates(const GateSP&    type,
                                           const ChannelSP& channel) const {
  return get_isolated_channel_gates_impl<GateSP, GatesSP>(
      get_isolated_gates(type), get_channel_gates(channel, type));
}

template <typename GatesSPT, typename MapSPT>
MapSPT get_isolated_gates_by_type_impl(const ChannelsSP& channels,
                                       const MapSPT&     gate_dict,
                                       const GatesSPT&   unshared_gates) {
  auto out = std::make_shared<typename MapSPT::element_type>();
  std::unordered_set<std::string> unshared_names;
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

generic::MapSP<Channel, BarrierGates> Config::get_isolated_gates_by_type(
    const BarrierGateSP& type) const {
  return get_isolated_gates_by_type_impl(
      get_current_channels(), get_gate_dict(type), get_isolated_gates(type));
}

generic::MapSP<Channel, PlungerGates> Config::get_isolated_gates_by_type(
    const PlungerGateSP& type) const {
  return get_isolated_gates_by_type_impl(
      get_current_channels(), get_gate_dict(type), get_isolated_gates(type));
}

generic::MapSP<Channel, ReservoirGates> Config::get_isolated_gates_by_type(
    const ReservoirGateSP& type) const {
  return get_isolated_gates_by_type_impl(
      get_current_channels(), get_gate_dict(type), get_isolated_gates(type));
}

generic::MapSP<Channel, ScreeningGates> Config::get_isolated_gates_by_type(
    const ScreeningGateSP& type) const {
  return get_isolated_gates_by_type_impl(
      get_current_channels(), get_gate_dict(type), get_isolated_gates(type));
}

generic::MapSP<Channel, DotGates<DotGate>> Config::get_isolated_gates_by_type(
    const DotGateSP& type) const {
  return get_isolated_gates_by_type_impl(
      get_current_channels(), get_gate_dict(type), get_isolated_gates(type));
}

generic::MapSP<Channel, Gates<Gate>> Config::get_isolated_gates_by_type(
    const GateSP& type) const {
  return get_isolated_gates_by_type_impl(
      get_current_channels(), get_gate_dict(type), get_isolated_gates(type));
}
GateRelationsSP Config::generate_gate_relations() const {
  GateRelations        out;
  GatesSP              all_gates  = get_all_gates();
  std::vector<GroupSP> all_groups = get_all_groups();
  for (const GateSP& gate : *all_gates) {
    GatesSP neighbors;
    for (const GroupSP& group : all_groups) {
      if (!group->has_gate(gate)) continue;
      GatesSP group_neighbors = group->order()->query_neighbors(gate);
      neighbors->insert(
          neighbors->end(), group_neighbors->begin(), group_neighbors->end());
    }
    out[gate] = neighbors;
  }
  return std::make_shared<GateRelations>(out);
}
template <class Archive>
void Config::serialize(Archive& ar) {
  ar(cereal::base_class<StandardConfigConnections>(this),
     _num_unique_channels,
     _wiring_DC,
     _channels,
     _voltage_constraints,
     _groups);
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
using MapGG = Map<Gname, Group>;
CEREAL_REGISTER_TYPE(MapGG)
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Config)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MapGG)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::config::core::Config)
