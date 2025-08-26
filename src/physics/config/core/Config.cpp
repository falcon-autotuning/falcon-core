#include "falcon_core/physics/config/core/Config.hpp"

#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"

using namespace falcon_core::physics::config::core;

Config::Config(const ScreeningGatesSP&          screening_gates,
               const PlungerGatesSP&            plunger_gates,
               const OhmicsSP&                  ohmics,
               const BarrierGatesSP&            barrier_gates,
               const ReservoirGatesSP&          reservoir_gates,
               const std::map<GnameSP, GroupSP> groups,
               const ImpedancesSP&              wiring_DC,
               const VoltageConstraintsSP&      constraints)
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
  // This requires CONNECTION_TO_ATTRIBUTE_NAME mapping and
  // group.get_connections Not implemented: depends on project-specific details.
}

ImpedanceSP Config::get_impedance(const BaseConnection& connection) const {
  if (!_wiring_DC) return nullptr;
  for (const auto& imp : *_wiring_DC) {
    if (imp->connection == connection) return imp;
  }
  return nullptr;
}

std::vector<GnameSP> Config::get_all_gnames() const {
  std::vector<GnameSP> out;
  for (const auto& kv : _groups) out.push_back(kv.first);
  return out;
}

std::vector<GroupSP> Config::get_all_groups() const {
  std::vector<GroupSP> out;
  for (const auto& kv : _groups) out.push_back(kv.second);
  return out;
}

void Config::compile_channels() const {
  // This should collect all group names as channels
  // _channels = std::make_shared<Channels>(...);
  // Not implemented: depends on Channels constructor.
}

bool Config::has_channel(const ChannelSP& channel) const {
  if (!_channels) return false;
  for (const auto& ch : *_channels) {
    if (ch == channel) return true;
  }
  return false;
}

bool Config::has_gname(const GnameSP& gname) const {
  for (const auto& kv : _groups) {
    if (kv.first == gname) return true;
  }
  return false;
}

GroupSP Config::select_group(const GnameSP& gname) const {
  auto it = _groups.find(gname);
  if (it != _groups.end()) return it->second;
  return nullptr;
}

int Config::get_dot_number(const ChannelSP& channel) const {
  if (!has_channel(channel)) return 0;
  for (const auto& group : get_all_groups()) {
    if (group->has_channel(channel)) return group->get_num_dots();
  }
  return 0;
}

std::vector<GnameSP> Config::get_charge_sense_groups() const {
  std::vector<GnameSP> outs;
  if (!_channels) return outs;
  for (const auto& channel : *_channels) {
    int number = get_dot_number(channel);
    if (number != 1) continue;
    GnameSP gname = get_gname(channel);
    if (!gname) continue;
    outs.push_back(gname);
  }
  return outs;
}

// ... (implement the rest as needed, following the above style)
