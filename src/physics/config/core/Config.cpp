#include "falcon_core/physics/config/core/Config.hpp"

#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

using namespace falcon_core::physics::config::core;

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

BarrierGatesSP Config::get_group_gates(const GnameSP&       gname,
                                       const BarrierGateSP& type) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

PlungerGatesSP Config::get_group_gates(const GnameSP&       gname,
                                       const PlungerGateSP& type) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

ReservoirGatesSP Config::get_group_gates(const GnameSP&         gname,
                                         const ReservoirGateSP& type) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

ScreeningGatesSP Config::get_group_gates(const GnameSP&         gname,
                                         const ScreeningGateSP& type) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

DotGatesSP<DotGate> Config::get_group_gates(const GnameSP&   gname,
                                            const DotGateSP& type) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

GatesSP<Gate> Config::get_group_gates(const GnameSP& gname,
                                      const GateSP&  type) const {
  if (!has_gname(gname)) return nullptr;
  GroupSP group = select_group(gname);
  if (group) return group->get_connections(type);
  return nullptr;
}

BarrierGatesSP Config::get_channel_gates(const ChannelSP&     channel,
                                         const BarrierGateSP& type) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_gates(gname, type);
}

PlungerGatesSP Config::get_channel_gates(const ChannelSP&     channel,
                                         const PlungerGateSP& type) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_gates(gname, type);
}

ReservoirGatesSP Config::get_channel_gates(const ChannelSP&       channel,
                                           const ReservoirGateSP& type) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_gates(gname, type);
}

ScreeningGatesSP Config::get_channel_gates(const ChannelSP&       channel,
                                           const ScreeningGateSP& type) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_gates(gname, type);
}

DotGatesSP<DotGate> Config::get_channel_gates(const ChannelSP& channel,
                                              const DotGateSP& type) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_gates(gname, type);
}

GatesSP<Gate> Config::get_channel_gates(const ChannelSP& channel,
                                        const GateSP&    type) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  return get_group_gates(gname, type);
}

GatesSP<Gate> Config::get_all_channel_gates(const ChannelSP& channel) const {
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

GatesSP<Gate> Config::get_channel_order_no_ohmics(
    const ChannelSP& channel) const {
  GnameSP gname = get_gname(channel);
  if (!gname) return nullptr;
  GroupSP group = select_group(gname);
  if (!group) return nullptr;
  GateGeometryArray1DSP order = group->order();
  if (!order) return nullptr;
  GatesSP<Gate> typed_order;
  for (const auto& gate : *order) {
    // Assume dynamic_cast for type checking, or use a type enum if available
    if (/* gate is Ohmic or ScreeningGate */) continue;
    // Only add DotGate or ReservoirGate
    // If you have type info, check here
    typed_order->push_back(gate);
  }
  return typed_order;
}

int Config::get_num_unique_channels() const { return num_unique_channels(); }

ChannelsSP Config::return_channels_from_gate(const Gate& gate) const {
  if (!has_gate(gate)) return nullptr;
  std::set<ChannelSP> channels;
  for (const GroupSP& group : get_all_groups()) {
    if (group->has_gate(gate)) {
      channels.insert(group->name());
    }
  }
  return std::make_shared<std::vector<ChannelSP>>(channels.begin(),
                                                  channels.end());
}

ChannelSP Config::return_channel_from_gate(const Gate& gate) const {
  auto channels = return_channels_from_gate(gate);
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
