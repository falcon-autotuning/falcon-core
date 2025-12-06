#include "falcon_core/physics/config/core/Config_c_api.h"

#include <falcon_core/physics/config/core/Config.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::config::core;

extern "C" {
ConfigHandle Config_create(ConnectionsHandle        screening_gates,
                           ConnectionsHandle        plunger_gates,
                           ConnectionsHandle        ohmics,
                           ConnectionsHandle        barrier_gates,
                           ConnectionsHandle        reservoir_gates,
                           MapGnameGroupHandle      groups,
                           ImpedancesHandle         wiring_DC,
                           VoltageConstraintsHandle constraints) {
  FALCON_C_API_BEGIN

  if (!screening_gates) {
    throw std::invalid_argument(
        "Config_create: screening_gates cannot be null");
  }
  if (!plunger_gates) {
    throw std::invalid_argument("Config_create: plunger_gates cannot be null");
  }
  if (!ohmics) {
    throw std::invalid_argument("Config_create: ohmics cannot be null");
  }
  if (!barrier_gates) {
    throw std::invalid_argument("Config_create: barrier_gates cannot be null");
  }
  if (!reservoir_gates) {
    throw std::invalid_argument(
        "Config_create: reservoir_gates cannot be null");
  }
  if (!groups) {
    throw std::invalid_argument("Config_create: groups cannot be null");
  }
  if (!wiring_DC) {
    throw std::invalid_argument("Config_create: wiring_DC cannot be null");
  }
  if (!constraints) {
    throw std::invalid_argument("Config_create: constraints cannot be null");
  }
  ConnectionsSP real_screening_gates =
      *static_cast<ConnectionsSP*>(screening_gates);
  ConnectionsSP real_plunger_gates =
      *static_cast<ConnectionsSP*>(plunger_gates);
  ConnectionsSP real_ohmics = *static_cast<ConnectionsSP*>(ohmics);
  ConnectionsSP real_barrier_gates =
      *static_cast<ConnectionsSP*>(barrier_gates);

  ConnectionsSP real_reservoir_gates =
      *static_cast<ConnectionsSP*>(reservoir_gates);
  falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,
                              Group>
                       real_groups = *static_cast<falcon_core::generic::MapSP<
                           falcon_core::autotuner_interfaces::names::Gname,
                           Group>*>(groups);
  ImpedancesSP         real_wiring_DC = *static_cast<ImpedancesSP*>(wiring_DC);
  VoltageConstraintsSP real_constraints =
      *static_cast<VoltageConstraintsSP*>(constraints);
  return new ConfigSP(std::make_shared<Config>(real_screening_gates,
                                               real_plunger_gates,
                                               real_ohmics,
                                               real_barrier_gates,
                                               real_reservoir_gates,
                                               real_groups,
                                               real_wiring_DC,
                                               real_constraints));
  FALCON_C_API_END(nullptr)
}

void Config_destroy(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_destroy: handle cannot be null");
  }
  delete static_cast<ConfigSP*>(handle);
  FALCON_C_API_END()
}

int Config_num_unique_channels(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_num_unique_channels: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return self->num_unique_channels();
  FALCON_C_API_END(0)
}

VoltageConstraintsHandle Config_voltage_constraints(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_voltage_constraints: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new VoltageConstraintsSP(self->voltage_constraints());
  FALCON_C_API_END(nullptr)
}

MapGnameGroupHandle Config_groups(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_groups: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Gname, Group>(
          self->groups());
  FALCON_C_API_END(nullptr)
}

ImpedancesHandle Config_wiring_DC(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_wiring_DC: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ImpedancesSP(self->wiring_DC());
  FALCON_C_API_END(nullptr)
}

ChannelsHandle Config_channels(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_channels: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::autotuner_interfaces::names::ChannelsSP(
      self->channels());
  FALCON_C_API_END(nullptr)
}

ImpedanceHandle Config_get_impedance(ConfigHandle     handle,
                                     ConnectionHandle connection) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_impedance: handle cannot be null");
  }
  if (!connection) {
    throw std::invalid_argument(
        "Config_get_impedance: connection cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_connection =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          connection);
  return new ImpedanceSP(self->get_impedance(real_connection));
  FALCON_C_API_END(nullptr)
}

ListGnameHandle Config_get_all_gnames(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_all_gnames: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::ListSP<
      falcon_core::autotuner_interfaces::names::Gname>(self->get_all_gnames());
  FALCON_C_API_END(nullptr)
}

ListGroupHandle Config_get_all_groups(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_all_groups: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::ListSP<Group>(self->get_all_groups());
  FALCON_C_API_END(nullptr)
}

bool Config_has_channel(ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_has_channel: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument("Config_has_channel: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return self->has_channel(real_channel);
  FALCON_C_API_END(false)
}

bool Config_has_gname(ConfigHandle handle, GnameHandle gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_has_gname: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument("Config_has_gname: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return self->has_gname(real_gname);
  FALCON_C_API_END(false)
}

GroupHandle Config_select_group(ConfigHandle handle, GnameHandle gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_select_group: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument("Config_select_group: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new GroupSP(self->select_group(real_gname));
  FALCON_C_API_END(nullptr)
}
int Config_get_dot_number(ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_dot_number: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_dot_number: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return self->get_dot_number(real_channel);
  FALCON_C_API_END(0)
}

ListGnameHandle Config_get_charge_sense_groups(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_charge_sense_groups: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::List<
      falcon_core::autotuner_interfaces::names::Gname>(
      *(self->get_charge_sense_groups()));
  FALCON_C_API_END(nullptr)
}

bool Config_ohmic_in_charge_sensor(ConfigHandle     handle,
                                   ConnectionHandle ohmic) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_ohmic_in_charge_sensor: handle cannot be null");
  }
  if (!ohmic) {
    throw std::invalid_argument(
        "Config_ohmic_in_charge_sensor: ohmic cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          ohmic);
  return self->ohmic_in_charge_sensor(real_ohmic);
  FALCON_C_API_END(false)
}

ConnectionHandle Config_get_associated_ohmic(ConfigHandle     handle,
                                             ConnectionHandle reservoir_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_associated_ohmic: handle cannot be null");
  }
  if (!reservoir_gate) {
    throw std::invalid_argument(
        "Config_get_associated_ohmic: reservoir_gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_reservoir_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          reservoir_gate);
  return new ConnectionSP(self->get_associated_ohmic(real_reservoir_gate));
  FALCON_C_API_END(nullptr)
}

ChannelsHandle Config_get_current_channels(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_current_channels: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::autotuner_interfaces::names::ChannelsSP(
      self->get_current_channels());
  FALCON_C_API_END(nullptr)
}

GnameHandle Config_get_gname(ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_gname: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument("Config_get_gname: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new falcon_core::autotuner_interfaces::names::GnameSP(
      self->get_gname(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_group_barrier_gates(ConfigHandle handle,
                                                 GnameHandle  gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_group_barrier_gates: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument(
        "Config_get_group_barrier_gates: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new ConnectionsSP(self->get_group_barrier_gates(real_gname));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_group_plunger_gates(ConfigHandle handle,
                                                 GnameHandle  gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_group_plunger_gates: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument(
        "Config_get_group_plunger_gates: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new ConnectionsSP(self->get_group_plunger_gates(real_gname));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_group_reservoir_gates(ConfigHandle handle,
                                                   GnameHandle  gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_group_reservoir_gates: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument(
        "Config_get_group_reservoir_gates: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new ConnectionsSP(self->get_group_reservoir_gates(real_gname));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_group_screening_gates(ConfigHandle handle,
                                                   GnameHandle  gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_group_screening_gates: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument(
        "Config_get_group_screening_gates: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new ConnectionsSP(self->get_group_screening_gates(real_gname));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_group_dot_gates(ConfigHandle handle,
                                             GnameHandle  gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_group_dot_gates: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument(
        "Config_get_group_dot_gates: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new ConnectionsSP(self->get_group_dot_gates(real_gname));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_group_gates(ConfigHandle handle,
                                         GnameHandle  gname) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_group_gates: handle cannot be null");
  }
  if (!gname) {
    throw std::invalid_argument("Config_get_group_gates: gname cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(gname);
  return new ConnectionsSP(self->get_group_gates(real_gname));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_barrier_gates(ConfigHandle  handle,
                                                   ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_barrier_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_barrier_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_barrier_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_plunger_gates(ConfigHandle  handle,
                                                   ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_plunger_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_plunger_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_plunger_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_reservoir_gates(ConfigHandle  handle,
                                                     ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_reservoir_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_reservoir_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_reservoir_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_screening_gates(ConfigHandle  handle,
                                                     ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_screening_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_screening_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_screening_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_dot_gates(ConfigHandle  handle,
                                               ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_dot_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_dot_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_dot_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_gates(ConfigHandle  handle,
                                           ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_ohmics(ConfigHandle  handle,
                                            ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_ohmics: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_ohmics: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_ohmics(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_channel_order_no_ohmics(ConfigHandle  handle,
                                                     ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_channel_order_no_ohmics: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_channel_order_no_ohmics: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_channel_order_no_ohmics(real_channel));
  FALCON_C_API_END(nullptr)
}

int Config_get_num_unique_channels(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_num_unique_channels: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return self->num_unique_channels();
  FALCON_C_API_END(0)
}

ChannelsHandle Config_return_channels_from_gate(ConfigHandle     handle,
                                                ConnectionHandle gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_return_channels_from_gate: handle cannot be null");
  }
  if (!gate) {
    throw std::invalid_argument(
        "Config_return_channels_from_gate: gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          gate);
  return new falcon_core::autotuner_interfaces::names::ChannelsSP(
      self->return_channels_from_gate(real_gate));
  FALCON_C_API_END(nullptr)
}

ChannelHandle Config_return_channel_from_gate(ConfigHandle     handle,
                                              ConnectionHandle gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_return_channel_from_gate: handle cannot be null");
  }
  if (!gate) {
    throw std::invalid_argument(
        "Config_return_channel_from_gate: gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          gate);
  return new falcon_core::autotuner_interfaces::names::ChannelSP(
      self->return_channel_from_gate(real_gate));
  FALCON_C_API_END(nullptr)
}

bool Config_ohmic_in_channel(ConfigHandle     handle,
                             ConnectionHandle ohmic,
                             ChannelHandle    channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_ohmic_in_channel: handle cannot be null");
  }
  if (!ohmic) {
    throw std::invalid_argument(
        "Config_ohmic_in_channel: ohmic cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_ohmic_in_channel: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          ohmic);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return self->ohmic_in_channel(real_ohmic, real_channel);
  FALCON_C_API_END(false)
}

PairConnectionConnectionHandle Config_get_dot_channel_neighbors(
    ConfigHandle handle, ConnectionHandle dot_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_dot_channel_neighbors: handle cannot be null");
  }
  if (!dot_gate) {
    throw std::invalid_argument(
        "Config_get_dot_channel_neighbors: dot_gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_dot_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          dot_gate);
  auto neighbors = self->get_dot_channel_neighbors(real_dot_gate);
  return new falcon_core::generic::PairSP<Connection, Connection>(
      std::make_shared<falcon_core::generic::Pair<Connection, Connection>>(
          neighbors.first, neighbors.second));
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_barrier_gate_dict(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_barrier_gate_dict: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_barrier_gate_dict());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_plunger_gate_dict(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_plunger_gate_dict: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_plunger_gate_dict());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_reservoir_gate_dict(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_reservoir_gate_dict: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_reservoir_gate_dict());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_screening_gate_dict(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_screening_gate_dict: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_screening_gate_dict());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_dot_gate_dict(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_dot_gate_dict: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_dot_gate_dict());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_gate_dict(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_gate_dict: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_gate_dict());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_barrier_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_barrier_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_isolated_barrier_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_plunger_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_plunger_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_isolated_plunger_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_reservoir_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_reservoir_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_isolated_reservoir_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_screening_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_screening_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_isolated_screening_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_dot_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_dot_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_isolated_dot_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_isolated_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_barrier_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_barrier_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_shared_barrier_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_plunger_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_plunger_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_shared_plunger_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_reservoir_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_reservoir_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_shared_reservoir_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_screening_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_screening_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_shared_screening_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_dot_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_dot_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_shared_dot_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_shared_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_channel_barrier_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_shared_channel_barrier_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_shared_channel_barrier_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_channel_plunger_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_shared_channel_plunger_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_shared_channel_plunger_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_channel_reservoir_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_shared_channel_reservoir_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_shared_channel_reservoir_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_channel_screening_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_shared_channel_screening_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_shared_channel_screening_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_channel_dot_gates(ConfigHandle  handle,
                                                      ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_channel_dot_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_shared_channel_dot_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_shared_channel_dot_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_shared_channel_gates(ConfigHandle  handle,
                                                  ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_shared_channel_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_shared_channel_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_shared_channel_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_barrier_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_barrier_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_isolated_channel_barrier_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_plunger_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_plunger_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_isolated_channel_plunger_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_reservoir_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_reservoir_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_isolated_channel_reservoir_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_screening_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_screening_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(
      self->get_isolated_channel_screening_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_channel_dot_gates(ConfigHandle  handle,
                                                        ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_dot_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_dot_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_isolated_channel_dot_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_isolated_channel_gates(ConfigHandle  handle,
                                                    ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_gates: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument(
        "Config_get_isolated_channel_gates: channel cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return new ConnectionsSP(self->get_isolated_channel_gates(real_channel));
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_isolated_barrier_gates_by_channel(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_barrier_gates_by_channel: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_isolated_barrier_gates_by_channel());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_isolated_plunger_gates_by_channel(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_plunger_gates_by_channel: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_isolated_plunger_gates_by_channel());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_isolated_reservoir_gates_by_channel(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_reservoir_gates_by_channel: handle cannot be "
        "null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_isolated_reservoir_gates_by_channel());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_isolated_screening_gates_by_channel(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_screening_gates_by_channel: handle cannot be "
        "null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_isolated_screening_gates_by_channel());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_isolated_dot_gates_by_channel(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_dot_gates_by_channel: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_isolated_dot_gates_by_channel());
  FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle Config_get_isolated_gates_by_channel(
    ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_isolated_gates_by_channel: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new falcon_core::generic::
      MapSP<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          self->get_isolated_gates_by_channel());
  FALCON_C_API_END(nullptr)
}

GateRelationsHandle Config_generate_gate_relations(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_generate_gate_relations: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new GateRelationsSP(self->generate_gate_relations());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_screening_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_screening_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->screening_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_reservoir_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_reservoir_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->reservoir_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_plunger_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_plunger_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->plunger_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_barrier_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_barrier_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->barrier_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_ohmics(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_ohmics: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->ohmics());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_dot_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_dot_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->dot_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_ohmic(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_ohmic: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_ohmic());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_barrier_gate(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_barrier_gate: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_barrier_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_plunger_gate(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_plunger_gate: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_plunger_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_reservoir_gate(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_reservoir_gate: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_reservoir_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_screening_gate(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_screening_gate: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_screening_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_dot_gate(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_dot_gate: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_dot_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Config_get_gate(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_gate: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionSP(self->get_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_all_gates(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_get_all_gates: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_all_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Config_get_all_connections(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_get_all_connections: handle cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  return new ConnectionsSP(self->get_all_connections());
  FALCON_C_API_END(nullptr)
}

bool Config_has_ohmic(ConfigHandle handle, ConnectionHandle ohmic) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_has_ohmic: handle cannot be null");
  }
  if (!ohmic) {
    throw std::invalid_argument("Config_has_ohmic: ohmic cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          ohmic);
  return self->has_ohmic(real_ohmic);
  FALCON_C_API_END(false)
}

bool Config_has_gate(ConfigHandle handle, ConnectionHandle gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_has_gate: handle cannot be null");
  }
  if (!gate) {
    throw std::invalid_argument("Config_has_gate: gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          gate);
  return self->has_gate(real_gate);
  FALCON_C_API_END(false)
}

bool Config_has_barrier_gate(ConfigHandle     handle,
                             ConnectionHandle barrier_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_has_barrier_gate: handle cannot be null");
  }
  if (!barrier_gate) {
    throw std::invalid_argument(
        "Config_has_barrier_gate: barrier_gate cannot be null");
  }

  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_barrier_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          barrier_gate);
  return self->has_barrier_gate(real_barrier_gate);
  FALCON_C_API_END(false)
}

bool Config_has_plunger_gate(ConfigHandle     handle,
                             ConnectionHandle plunger_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_has_plunger_gate: handle cannot be null");
  }
  if (!plunger_gate) {
    throw std::invalid_argument(
        "Config_has_plunger_gate: plunger_gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_plunger_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          plunger_gate);
  return self->has_plunger_gate(real_plunger_gate);
  FALCON_C_API_END(false)
}

bool Config_has_reservoir_gate(ConfigHandle     handle,
                               ConnectionHandle reservoir_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_has_reservoir_gate: handle cannot be null");
  }
  if (!reservoir_gate) {
    throw std::invalid_argument(
        "Config_has_reservoir_gate: reservoir_gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_reservoir_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          reservoir_gate);
  return self->has_reservoir_gate(real_reservoir_gate);
  FALCON_C_API_END(false)
}

bool Config_has_screening_gate(ConfigHandle     handle,
                               ConnectionHandle screening_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Config_has_screening_gate: handle cannot be null");
  }
  if (!screening_gate) {
    throw std::invalid_argument(
        "Config_has_screening_gate: screening_gate cannot be null");
  }
  ConfigSP self = *static_cast<ConfigSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_screening_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          screening_gate);
  return self->has_screening_gate(real_screening_gate);
  FALCON_C_API_END(false)
}

bool Config_equal(ConfigHandle handle, ConfigHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Config_equal: other cannot be null");
  }
  ConfigSP* self         = static_cast<ConfigSP*>(handle);
  ConfigSP* other_config = static_cast<ConfigSP*>(other);
  return *self == *other_config;
  FALCON_C_API_END(false)
}

bool Config_not_equal(ConfigHandle handle, ConfigHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Config_not_equal: other cannot be null");
  }
  ConfigSP self{*static_cast<ConfigSP*>(handle)};
  ConfigSP other_config{*static_cast<ConfigSP*>(other)};
  return self != other_config;
  FALCON_C_API_END(false)
}

StringHandle Config_to_json_string(ConfigHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Config_to_json_string: handle cannot be null");
  }
  ConfigSP    self = *static_cast<ConfigSP*>(handle);
  std::string json = self->to_json_string();
  return String_wrap(json.data());
  FALCON_C_API_END(nullptr)
}

ConfigHandle Config_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument("Config_from_json_string: json cannot be null");
  }
  std::string json_str = std::string(json->raw, json->length);
  ConfigSP    ptr      = Config::from_json_string<Config>(json_str);
  return new ConfigSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
