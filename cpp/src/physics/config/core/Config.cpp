#include "falcon_core/physics/config/core/Config.hpp"

#include <functional>
#include <stdexcept>

#include "falcon_core/autotuner_interfaces/names/Channels.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Config::Config(const Config& other) : StandardConfigConnections(other) {
  std::unique_lock<std::shared_timed_mutex> lock_groups(_mu_groups,
                                                        std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_wiring_DC(_mu_wiring_DC,
                                                           std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_voltage_constraints(
      _mu_voltage_constraints, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_channels(_mu_channels,
                                                          std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_num_unique_channels(
      _mu_num_unique_channels, std::defer_lock);
  std::lock(lock_groups,
            lock_wiring_DC,
            lock_voltage_constraints,
            lock_channels,
            lock_num_unique_channels);
  if (!other.groups() || !other.wiring_DC() || !other.voltage_constraints() ||
      !other.channels()) {
    throw std::invalid_argument(
        "Config: The constraints, wiring, groups, and channels are not "
        "permitted to be null.");
  }
  _groups =
      std::make_shared<generic::Map<autotuner_interfaces::names::Gname, Group>>(
          *other.groups());
  _wiring_DC =
      std::make_shared<device_structures::Impedances>(*other.wiring_DC());
  _voltage_constraints =
      std::make_shared<VoltageConstraints>(*other.voltage_constraints());
  _channels = std::make_shared<autotuner_interfaces::names::Channels>(
      *other.channels());
  _num_unique_channels = other.num_unique_channels();
}
Config& Config::operator=(const Config& other) {
  if (this != &other) {
    StandardConfigConnections::operator=(other);
    std::unique_lock<std::shared_timed_mutex> lock_groups(_mu_groups,
                                                          std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_wiring_DC(_mu_wiring_DC,
                                                             std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_voltage_constraints(
        _mu_voltage_constraints, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_channels(_mu_channels,
                                                            std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_num_unique_channels(
        _mu_num_unique_channels, std::defer_lock);
    std::lock(lock_groups,
              lock_wiring_DC,
              lock_voltage_constraints,
              lock_channels,
              lock_num_unique_channels);
    if (!other.groups() || !other.wiring_DC() || !other.voltage_constraints() ||
        !other.channels()) {
      throw std::invalid_argument(
          "Config: The constraints, wiring, groups, and channels are not "
          "permitted to be null.");
    }
    _groups = std::make_shared<
        generic::Map<autotuner_interfaces::names::Gname, Group>>(
        *other.groups());
    _wiring_DC =
        std::make_shared<device_structures::Impedances>(*other.wiring_DC());
    _voltage_constraints =
        std::make_shared<VoltageConstraints>(*other.voltage_constraints());
    _channels = std::make_shared<autotuner_interfaces::names::Channels>(
        *other.channels());
    _num_unique_channels = other.num_unique_channels();
  }
  return *this;
}
Config::Config() = default;
Config::Config(
    const device_structures::ConnectionsSP& screening_gates,
    const device_structures::ConnectionsSP& plunger_gates,
    const device_structures::ConnectionsSP& ohmics,
    const device_structures::ConnectionsSP& barrier_gates,
    const device_structures::ConnectionsSP& reservoir_gates,
    const generic::MapSP<autotuner_interfaces::names::Gname, Group> groups,
    const device_structures::ImpedancesSP&                          wiring_DC,
    const VoltageConstraintsSP&                                     constraints)
    : StandardConfigConnections(screening_gates,
                                reservoir_gates,
                                plunger_gates,
                                barrier_gates,
                                ohmics),
      _wiring_DC(wiring_DC),
      _channels(std::make_shared<autotuner_interfaces::names::Channels>()),
      _voltage_constraints(constraints),
      _groups(groups) {
  if (!constraints || !wiring_DC || !groups) {
    throw std::invalid_argument(
        "Config: The constraints, wiring, and groups are not permitted to be "
        "null.");
  }
  _num_unique_channels = static_cast<int>(get_all_gnames()->size());
  if (_num_unique_channels <= 0)
    throw std::runtime_error("Config: No unique channels found in config.");
  compile_channels();
  check_group_consistency();
  check_impedance_consistency();
}
void Config::check_impedance_consistency() const {
  if (!wiring_DC() || wiring_DC()->empty()) return;
  auto all_connections = get_all_connections();
  auto wiring_DC       = *this->wiring_DC();
  for (const device_structures::ImpedanceSP& imp : wiring_DC) {
    if (!all_connections->contains(imp->connection())) {
      throw std::runtime_error("Config: Connection " +
                               imp->connection()->name() +
                               " not in wiring_DC.");
    }
  }
  if (all_connections->size() != wiring_DC.size()) {
    throw std::runtime_error(
        "Config: Include all connections or none in wiring_DC.");
  }
}

void Config::check_group_consistency() const {
  device_structures::Connections sgates;
  device_structures::Connections rgates;
  device_structures::Connections pgates;
  device_structures::Connections bgates;
  device_structures::Connections os;
  auto                           all_groups = get_all_groups();
  auto                           storage_vector =
      std::vector<std::reference_wrapper<device_structures::Connections>>{
          sgates, rgates, pgates, bgates, os};
  for (const GroupSP& group : *all_groups) {
    const std::vector<device_structures::Connections> group_connections =
        std::vector<device_structures::Connections>{*group->screening_gates(),
                                                    *group->reservoir_gates(),
                                                    *group->plunger_gates(),
                                                    *group->barrier_gates(),
                                                    *group->ohmics()};
    for (size_t i = 0; i < group_connections.size(); i++) {
      const auto connections = group_connections[i];
      auto&      storage     = storage_vector[i].get();
      for (const device_structures::ConnectionSP& conn : connections) {
        if (!storage.contains(conn)) {
          storage.push_back(conn);
        }
      }
    }
  }
  if (sgates != *screening_gates()) {
    throw std::logic_error(
        "Config: Inconsistent between the groups and the total config for "
        "screening_gates");
  }
  if (rgates != *reservoir_gates()) {
    throw std::logic_error(
        "Config: Inconsistent between the groups and the total config for "
        "reservoir_gates");
  }
  if (pgates != *plunger_gates()) {
    throw std::logic_error(
        "Config: Inconsistent between the groups and the total config for "
        "plunger_gates");
  }
  if (bgates != *barrier_gates()) {
    throw std::logic_error(
        "Config: Inconsistent between the groups and the total config for "
        "barrier_gates");
  }
  if (os != *ohmics()) {
    throw std::logic_error(
        "Config: Inconsistent between the groups and the total config for "
        "ohmics");
  }
}

int Config::num_unique_channels() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_num_unique_channels);
  return _num_unique_channels;
}
VoltageConstraintsSP Config::voltage_constraints() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_voltage_constraints);
  return _voltage_constraints;
}
generic::MapSP<autotuner_interfaces::names::Gname, Group> Config::groups()
    const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_groups);
  return _groups;
}
device_structures::ImpedancesSP Config::wiring_DC() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_wiring_DC);
  return _wiring_DC;
}
autotuner_interfaces::names::ChannelsSP Config::channels() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_channels);
  return _channels;
}
device_structures::ImpedanceSP Config::get_impedance(
    const device_structures::ConnectionSP& connection) const {
  if (!connection) {
    throw std::invalid_argument("Config: A null connection is not searchable.");
  }
  auto wiring_dc = *wiring_DC();
  for (const device_structures::ImpedanceSP& imp : wiring_dc) {
    auto search = *imp->connection();
    if (search == *connection) return imp;
  }
  throw std::invalid_argument(
      "Config: The selected connection is not a part of the config.");
}

generic::ListSP<autotuner_interfaces::names::Gname> Config::get_all_gnames()
    const {
  return groups()->keys();
}

generic::ListSP<Group> Config::get_all_groups() const {
  return groups()->values();
}

void Config::compile_channels() const {
  auto groupvalues = *groups()->values();
  for (const GroupSP& group : groupvalues) {
    channels()->push_back(group->name());
  }
}

bool Config::has_channel(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  if (!channels()) return false;
  auto all_channels = *channels();
  for (const autotuner_interfaces::names::ChannelSP& ch : all_channels) {
    if (*ch == *channel) return true;
  }
  return false;
}

bool Config::has_gname(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!gname) {
    throw std::invalid_argument("Config: The group name must not be null.");
  }
  if (!groups()) return false;
  auto all_gnames = *get_all_gnames();
  for (const autotuner_interfaces::names::GnameSP& gn : all_gnames) {
    if (gn->name() == gname->name()) return true;
  }
  return false;
}

GroupSP Config::select_group(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (has_gname(gname)) {
    return groups()->at(gname);
  }
  throw std::invalid_argument(
      "Config: The gname provided did not exist in the config.");
}

int Config::get_dot_number(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel)) return 0;
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    if (group->has_channel(channel)) return group->num_dots();
  }
  return 0;
}

generic::ListSP<autotuner_interfaces::names::Gname>
Config::get_charge_sense_groups() const {
  generic::ListSP<autotuner_interfaces::names::Gname> outs =
      std::make_shared<generic::List<autotuner_interfaces::names::Gname>>();
  if (!groups()) return outs;
  for (const auto& it : *groups()) {
    if (it->second()->is_charge_sensor()) {
      outs->push_back(it->first());
    }
  }
  return outs;
}

bool Config::ohmic_in_charge_sensor(
    const device_structures::ConnectionSP& ohmic) const {
  if (!has_ohmic(ohmic)) return false;
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    if (group->is_charge_sensor() && group->has_ohmic(ohmic)) {
      return true;
    }
  }
  return false;
}

device_structures::ConnectionSP Config::get_associated_ohmic(
    const device_structures::ConnectionSP& reservoir_gate) const {
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    if (!group->has_gate(reservoir_gate)) continue;
    auto left_reservoir  = group->order()->left_reservoir();
    auto right_reservoir = group->order()->right_reservoir();
    if (*left_reservoir == *reservoir_gate) {
      return left_reservoir->ohmic();
    }
    if (*right_reservoir == *reservoir_gate) {
      return right_reservoir->ohmic();
    }
  }
  throw std::invalid_argument(
      "Config: The reservoir_gate selected did not match a connection in the "
      "config.");
}

autotuner_interfaces::names::ChannelsSP Config::get_current_channels() const {
  return channels();
}

autotuner_interfaces::names::GnameSP Config::get_gname(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel))
    throw std::invalid_argument("Config: The channel supplied is invalid.");
  for (const auto& it : *groups()) {
    if (it->second()->has_channel(channel)) {
      return it->first();
    }
  }
  throw std::invalid_argument(
      "Config: The channel supplied is does not match any groups.");
}

device_structures::ConnectionsSP Config::get_group_barrier_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname))
    throw std::invalid_argument("Config: The group name supplied is invalid.");
  GroupSP group = select_group(gname);
  if (group) return group->barrier_gates();
  throw std::invalid_argument(
      "Config: The gname supplied does not match any groups.");
}

device_structures::ConnectionsSP Config::get_group_plunger_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname))
    throw std::invalid_argument("Config: The group name supplied is invalid.");
  GroupSP group = select_group(gname);
  if (group) return group->plunger_gates();
  throw std::invalid_argument(
      "Config: The gname supplied does not match any groups.");
}

device_structures::ConnectionsSP Config::get_group_reservoir_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname))
    throw std::invalid_argument("Config: The group name supplied is invalid.");
  GroupSP group = select_group(gname);
  if (group) return group->reservoir_gates();
  throw std::invalid_argument(
      "Config: The gname supplied does not match any groups.");
}

device_structures::ConnectionsSP Config::get_group_screening_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname))
    throw std::invalid_argument("Config: The group name supplied is invalid.");
  GroupSP group = select_group(gname);
  if (group) return group->screening_gates();
  throw std::invalid_argument(
      "Config: The gname supplied does not match any groups.");
}

device_structures::ConnectionsSP Config::get_group_dot_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname))
    throw std::invalid_argument("Config: The group name supplied is invalid.");
  GroupSP group = select_group(gname);
  if (group) return group->dot_gates();
  throw std::invalid_argument(
      "Config: The gname supplied does not match any groups.");
}

device_structures::ConnectionsSP Config::get_group_gates(
    const autotuner_interfaces::names::GnameSP& gname) const {
  if (!has_gname(gname))
    throw std::invalid_argument("Config: The group name supplied is invalid.");
  GroupSP group = select_group(gname);
  if (group) return group->get_all_gates();
  throw std::invalid_argument(
      "Config: The gname supplied does not match any groups.");
}

device_structures::ConnectionsSP Config::get_channel_barrier_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  return get_group_barrier_gates(gname);
}

device_structures::ConnectionsSP Config::get_channel_plunger_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  return get_group_plunger_gates(gname);
}

device_structures::ConnectionsSP Config::get_channel_reservoir_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  return get_group_reservoir_gates(gname);
}

device_structures::ConnectionsSP Config::get_channel_screening_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  return get_group_screening_gates(gname);
}

device_structures::ConnectionsSP Config::get_channel_dot_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  return get_group_dot_gates(gname);
}

device_structures::ConnectionsSP Config::get_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  return get_group_gates(gname);
}

device_structures::ConnectionsSP Config::get_channel_ohmics(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!has_channel(channel))
    throw std::invalid_argument("Config: The channel is not in the Config.");
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    if (group->has_channel(channel)) {
      return group->ohmics();
    }
  }
  throw std::invalid_argument("Config: The channel has no ohmics.");
}

device_structures::ConnectionsSP Config::get_channel_order_no_ohmics(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  GroupSP                              group = select_group(gname);
  geometries::GateGeometryArray1DSP    order = group->order();
  device_structures::ConnectionsSP     typed_order =
      std::make_shared<device_structures::Connections>();
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
    const device_structures::ConnectionSP& gate) const {
  std::set<autotuner_interfaces::names::ChannelSP> channels;
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    if (group->has_gate(gate)) {
      channels.insert(group->name());
    }
  }
  return std::make_shared<autotuner_interfaces::names::Channels>(
      std::vector<autotuner_interfaces::names::ChannelSP>(channels.begin(),
                                                          channels.end()));
}

autotuner_interfaces::names::ChannelSP Config::return_channel_from_gate(
    const device_structures::ConnectionSP& gate) const {
  autotuner_interfaces::names::ChannelsSP channels =
      return_channels_from_gate(gate);
  if (!channels || channels->empty())
    throw std::invalid_argument(
        "Config: The selected channels associated with the gate are empty or "
        "do not exist.");
  return channels->at(0);
}

bool Config::ohmic_in_channel(
    const device_structures::ConnectionSP&        ohmic,
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!ohmic) {
    throw std::invalid_argument("Config: The ohmic must not be null.");
  }
  if (!has_channel(channel) || !ohmic->is_ohmic()) return false;
  auto gname = get_gname(channel);
  auto group = select_group(gname);
  return group->has_ohmic(ohmic);
}

std::pair<device_structures::ConnectionSP, device_structures::ConnectionSP>
Config::get_dot_channel_neighbors(
    const device_structures::ConnectionSP& dotgate) const {
  autotuner_interfaces::names::ChannelSP channel =
      return_channel_from_gate(dotgate);
  autotuner_interfaces::names::GnameSP gname = get_gname(channel);
  GroupSP                              group = select_group(gname);

  auto all_dot_gates = group->order()->all_dot_gates();
  for (const auto& connection : *all_dot_gates) {
    if (*dotgate == *connection) {
      auto left_neighbor  = connection->left_neighbor();
      auto right_neighbor = connection->right_neighbor();
      return {left_neighbor, right_neighbor};
    }
  }
  throw std::invalid_argument(
      "Config: The selected dotgate's name does match entries in the config");
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_barrier_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    auto gates = group->barrier_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_plunger_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    auto gates = group->plunger_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_reservoir_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    auto gates = group->reservoir_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_screening_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    auto gates = group->screening_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_dot_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    auto gates = group->dot_gates();
    out->insert(group->name(), gates);
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_gate_dict() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  auto all_groups = *get_all_groups();
  for (const GroupSP& group : all_groups) {
    auto gates = group->get_all_gates();
    out->insert(group->name(), gates);
  }
  return out;
}
device_structures::ConnectionsSP Config::get_isolated_barrier_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->barrier_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}

device_structures::ConnectionsSP Config::get_isolated_plunger_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->plunger_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::ConnectionsSP Config::get_isolated_reservoir_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->reservoir_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::ConnectionsSP Config::get_isolated_screening_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->screening_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::ConnectionsSP Config::get_isolated_dot_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->dot_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}
device_structures::ConnectionsSP Config::get_isolated_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->get_all_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int> gate_count;
  for (const auto& gate : gates) {
    gate_count[gate->name()]++;
  }
  auto isolated = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& gate : gates) {
    if (gate_count[gate->name()] == 1) {
      isolated->push_back(gate);
    }
  }
  return isolated;
}

device_structures::ConnectionsSP Config::get_shared_barrier_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->barrier_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                             gate_count;
  std::unordered_map<std::string, device_structures::ConnectionSP> gate_map;
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
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}

device_structures::ConnectionsSP Config::get_shared_plunger_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->plunger_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                             gate_count;
  std::unordered_map<std::string, device_structures::ConnectionSP> gate_map;
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
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::ConnectionsSP Config::get_shared_reservoir_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->reservoir_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                             gate_count;
  std::unordered_map<std::string, device_structures::ConnectionSP> gate_map;
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
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::ConnectionsSP Config::get_shared_screening_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->screening_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                             gate_count;
  std::unordered_map<std::string, device_structures::ConnectionSP> gate_map;
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
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::ConnectionsSP Config::get_shared_dot_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->dot_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                             gate_count;
  std::unordered_map<std::string, device_structures::ConnectionSP> gate_map;
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
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}
device_structures::ConnectionsSP Config::get_shared_gates() const {
  std::vector<device_structures::ConnectionSP> gates;
  for (const auto& group : *groups()) {
    auto connections = group->second()->get_all_gates();
    for (const auto& conn : *connections) {
      gates.push_back(conn);
    }
  }
  if (gates.empty()) {
    throw std::runtime_error(
        "Config: No gates found in the config for the given type");
  }
  std::unordered_map<std::string, int>                             gate_count;
  std::unordered_map<std::string, device_structures::ConnectionSP> gate_map;
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
      typename device_structures::ConnectionsSP::element_type>();
  for (const auto& it : shared) {
    result->push_back(gate_map[it.first]);
  }
  return result;
}

// Connection
device_structures::ConnectionsSP Config::get_isolated_channel_barrier_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ConnectionsSP channel_gates =
      get_channel_barrier_gates(channel);
  device_structures::ConnectionsSP isolated_gates =
      get_isolated_barrier_gates();
  auto result = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
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

// Connection
device_structures::ConnectionsSP Config::get_isolated_channel_plunger_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ConnectionsSP channel_gates =
      get_channel_plunger_gates(channel);
  device_structures::ConnectionsSP isolated_gates =
      get_isolated_plunger_gates();
  auto result = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
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

// Connection
device_structures::ConnectionsSP Config::get_isolated_channel_reservoir_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ConnectionsSP channel_gates =
      get_channel_reservoir_gates(channel);
  device_structures::ConnectionsSP isolated_gates =
      get_isolated_reservoir_gates();
  auto result = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
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

// Connection
device_structures::ConnectionsSP Config::get_isolated_channel_screening_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ConnectionsSP channel_gates =
      get_channel_screening_gates(channel);
  device_structures::ConnectionsSP isolated_gates =
      get_isolated_screening_gates();
  auto result = std::make_shared<
      typename device_structures::ConnectionsSP::element_type>();
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
device_structures::ConnectionsSP Config::get_isolated_channel_dot_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ConnectionsSP channel_gates =
      get_channel_dot_gates(channel);
  device_structures::ConnectionsSP isolated_gates = get_isolated_dot_gates();
  auto                             result         = std::make_shared<
                                          typename device_structures::ConnectionsSP::element_type>();
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
device_structures::ConnectionsSP Config::get_isolated_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  device_structures::ConnectionsSP channel_gates  = get_channel_gates(channel);
  device_structures::ConnectionsSP isolated_gates = get_isolated_gates();
  auto                             result         = std::make_shared<
                                          typename device_structures::ConnectionsSP::element_type>();
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
               device_structures::Connections>
Config::get_isolated_barrier_gates_by_channel() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  autotuner_interfaces::names::ChannelsSP channels = get_current_channels();
  for (const auto& channel : *channels) {
    out->insert(channel, get_isolated_channel_barrier_gates(channel));
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_isolated_plunger_gates_by_channel() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  autotuner_interfaces::names::ChannelsSP channels = get_current_channels();
  for (const auto& channel : *channels) {
    out->insert(channel, get_isolated_channel_plunger_gates(channel));
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_isolated_reservoir_gates_by_channel() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  autotuner_interfaces::names::ChannelsSP channels = get_current_channels();
  for (const auto& channel : *channels) {
    out->insert(channel, get_isolated_channel_reservoir_gates(channel));
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_isolated_screening_gates_by_channel() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  autotuner_interfaces::names::ChannelsSP channels = get_current_channels();
  for (const auto& channel : *channels) {
    out->insert(channel, get_isolated_channel_screening_gates(channel));
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_isolated_dot_gates_by_channel() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  autotuner_interfaces::names::ChannelsSP channels = get_current_channels();
  for (const auto& channel : *channels) {
    out->insert(channel, get_isolated_channel_dot_gates(channel));
  }
  return out;
}

generic::MapSP<autotuner_interfaces::names::Channel,
               device_structures::Connections>
Config::get_isolated_gates_by_channel() const {
  auto out = std::make_shared<generic::Map<autotuner_interfaces::names::Channel,
                                           device_structures::Connections>>();
  autotuner_interfaces::names::ChannelsSP channels = get_current_channels();
  for (const auto& channel : *channels) {
    out->insert(channel, get_isolated_channel_gates(channel));
  }
  return out;
}
device_structures::GateRelationsSP Config::generate_gate_relations() const {
  device_structures::GateRelations out;
  device_structures::Connections   all_gates  = *get_all_gates();
  auto                             all_groups = *get_all_groups();
  for (const device_structures::ConnectionSP& gate : all_gates) {
    device_structures::ConnectionsSP neighbors =
        std::make_shared<device_structures::Connections>();
    for (const GroupSP& group : all_groups) {
      if (!group->has_gate(gate)) continue;
      device_structures::Connections group_neighbors =
          *group->order()->query_neighbors(gate);
      for (const device_structures::ConnectionSP& conn : group_neighbors) {
        neighbors->push_back(conn);
      }
    }
    out.insert(gate, neighbors);
  }
  return std::make_shared<device_structures::GateRelations>(out);
}
device_structures::ConnectionsSP Config::get_shared_channel_barrier_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  device_structures::ConnectionsSP outs =
      std::make_shared<device_structures::Connections>();
  auto shared_bgates = get_shared_barrier_gates();
  auto channel_gates = get_channel_barrier_gates(channel);
  for (const device_structures::ConnectionSP& bgate : *channel_gates) {
    if (shared_bgates->contains(bgate)) outs->push_back(bgate);
  }
  return outs;
}
device_structures::ConnectionsSP Config::get_shared_channel_plunger_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  device_structures::ConnectionsSP outs =
      std::make_shared<device_structures::Connections>();
  auto shared_bgates = get_shared_plunger_gates();
  auto channel_gates = get_channel_plunger_gates(channel);
  for (const device_structures::ConnectionSP& pgate : *channel_gates) {
    if (shared_bgates->contains(pgate)) outs->push_back(pgate);
  }
  return outs;
}
device_structures::ConnectionsSP Config::get_shared_channel_reservoir_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  device_structures::ConnectionsSP outs =
      std::make_shared<device_structures::Connections>();
  auto shared_bgates = get_shared_reservoir_gates();
  auto channel_gates = get_channel_reservoir_gates(channel);
  for (const device_structures::ConnectionSP& rgate : *channel_gates) {
    if (shared_bgates->contains(rgate)) outs->push_back(rgate);
  }
  return outs;
}
device_structures::ConnectionsSP Config::get_shared_channel_screening_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  device_structures::ConnectionsSP outs =
      std::make_shared<device_structures::Connections>();
  auto shared_gates  = get_shared_screening_gates();
  auto channel_gates = get_channel_screening_gates(channel);
  for (const device_structures::ConnectionSP& sgate : *channel_gates) {
    if (shared_gates->contains(sgate)) outs->push_back(sgate);
  }
  return outs;
}
device_structures::ConnectionsSP Config::get_shared_channel_dot_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  device_structures::ConnectionsSP outs =
      std::make_shared<device_structures::Connections>();
  auto shared_gates  = get_shared_dot_gates();
  auto channel_gates = get_channel_dot_gates(channel);
  for (const device_structures::ConnectionSP& dgate : *channel_gates) {
    if (shared_gates->contains(dgate)) outs->push_back(dgate);
  }
  return outs;
}
device_structures::ConnectionsSP Config::get_shared_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Config: The channel must not be null.");
  }
  device_structures::ConnectionsSP outs =
      std::make_shared<device_structures::Connections>();
  auto shared_gates  = get_shared_gates();
  auto channel_gates = get_channel_gates(channel);
  for (const device_structures::ConnectionSP& gate : *channel_gates) {
    if (shared_gates->contains(gate)) outs->push_back(gate);
  }
  return outs;
}

bool Config::operator==(const Config& other) const {
  if (this == &other) return true;
  return StandardConfigConnections::operator==(other) &&
         (*_groups == *other._groups) && (*_wiring_DC == *other._wiring_DC) &&
         (*_voltage_constraints == *other._voltage_constraints) &&
         (*_channels == *other._channels) &&
         (_num_unique_channels == other._num_unique_channels);
}

bool Config::operator!=(const Config& other) const { return !(*this == other); }
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
