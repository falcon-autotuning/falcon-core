#include "falcon_core/physics/config/core/Config_c_api.h"

#include <falcon_core/physics/config/core/Config.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
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
  ConnectionsSP real_screening_gates = std::make_shared<Connections>(
      *static_cast<Connections*>(screening_gates));
  ConnectionsSP real_plunger_gates =
      std::make_shared<Connections>(*static_cast<Connections*>(plunger_gates));
  ConnectionsSP real_ohmics =
      std::make_shared<Connections>(*static_cast<Connections*>(ohmics));
  ConnectionsSP real_barrier_gates =
      std::make_shared<Connections>(*static_cast<Connections*>(barrier_gates));

  ConnectionsSP real_reservoir_gates = std::make_shared<Connections>(
      *static_cast<Connections*>(reservoir_gates));
  falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,
                              Group>
      real_groups = std::make_shared<falcon_core::generic::Map<
          falcon_core::autotuner_interfaces::names::Gname,
          Group>>(
          *static_cast<falcon_core::generic::Map<
              falcon_core::autotuner_interfaces::names::Gname,
              Group>*>(groups));
  ImpedancesSP real_wiring_DC =
      std::make_shared<Impedances>(*static_cast<Impedances*>(wiring_DC));
  VoltageConstraintsSP real_constraints = std::make_shared<VoltageConstraints>(
      *static_cast<VoltageConstraints*>(constraints));
  return new Config(real_screening_gates,
                    real_plunger_gates,
                    real_ohmics,
                    real_barrier_gates,
                    real_reservoir_gates,
                    real_groups,
                    real_wiring_DC,
                    real_constraints);
}

void Config_destroy(ConfigHandle handle) {
  delete static_cast<Config*>(handle);
}

int Config_num_unique_channels(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return self.num_unique_channels();
}

VoltageConstraintsHandle Config_voltage_constraints(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new VoltageConstraints(*self.voltage_constraints());
}

MapGnameGroupHandle Config_groups(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Gname, Group>(
          *self.groups());
}

ImpedancesHandle Config_wiring_DC(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Impedances(*self.wiring_DC());
}

ChannelsHandle Config_channels(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::autotuner_interfaces::names::Channels(
      *self.channels());
}

ImpedanceHandle Config_get_impedance(ConfigHandle     handle,
                                     ConnectionHandle connection) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_connection =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              connection));
  return new Impedance(*self.get_impedance(real_connection));
}

ListGnameHandle Config_get_all_gnames(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::List<
      falcon_core::autotuner_interfaces::names::Gname>(
      *(self.get_all_gnames()));
}

ListGroupHandle Config_get_all_groups(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::List<Group>(*(self.get_all_groups()));
}

bool Config_has_channel(ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return self.has_channel(real_channel);
}

bool Config_has_gname(ConfigHandle handle, GnameHandle gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return self.has_gname(real_gname);
}

GroupHandle Config_select_group(ConfigHandle handle, GnameHandle gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Group(*self.select_group(real_gname));
}
int Config_get_dot_number(ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return self.get_dot_number(real_channel);
}

ListGnameHandle Config_get_charge_sense_groups(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::List<
      falcon_core::autotuner_interfaces::names::Gname>(
      *(self.get_charge_sense_groups()));
}

bool Config_ohmic_in_charge_sensor(ConfigHandle     handle,
                                   ConnectionHandle ohmic) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              ohmic));
  return self.ohmic_in_charge_sensor(real_ohmic);
}

ConnectionHandle Config_get_associated_ohmic(ConfigHandle     handle,
                                             ConnectionHandle reservoir_gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_reservoir_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              reservoir_gate));
  return new Connection(*self.get_associated_ohmic(real_reservoir_gate));
}

ChannelsHandle Config_get_current_channels(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::autotuner_interfaces::names::Channels(
      *self.get_current_channels());
}

GnameHandle Config_get_gname(ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new falcon_core::autotuner_interfaces::names::Gname(
      *self.get_gname(real_channel));
}

ConnectionsHandle Config_get_group_barrier_gates(ConfigHandle handle,
                                                 GnameHandle  gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Connections(*(self.get_group_barrier_gates(real_gname)));
}

ConnectionsHandle Config_get_group_plunger_gates(ConfigHandle handle,
                                                 GnameHandle  gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Connections(*(self.get_group_plunger_gates(real_gname)));
}

ConnectionsHandle Config_get_group_reservoir_gates(ConfigHandle handle,
                                                   GnameHandle  gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Connections(*(self.get_group_reservoir_gates(real_gname)));
}

ConnectionsHandle Config_get_group_screening_gates(ConfigHandle handle,
                                                   GnameHandle  gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Connections(*(self.get_group_screening_gates(real_gname)));
}

ConnectionsHandle Config_get_group_dot_gates(ConfigHandle handle,
                                             GnameHandle  gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Connections(*(self.get_group_dot_gates(real_gname)));
}

ConnectionsHandle Config_get_group_gates(ConfigHandle handle,
                                         GnameHandle  gname) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::GnameSP real_gname =
      std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(
          *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(
              gname));
  return new Connections(*(self.get_group_gates(real_gname)));
}

ConnectionsHandle Config_get_channel_barrier_gates(ConfigHandle  handle,
                                                   ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_barrier_gates(real_channel)));
}

ConnectionsHandle Config_get_channel_plunger_gates(ConfigHandle  handle,
                                                   ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_plunger_gates(real_channel)));
}

ConnectionsHandle Config_get_channel_reservoir_gates(ConfigHandle  handle,
                                                     ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_reservoir_gates(real_channel)));
}

ConnectionsHandle Config_get_channel_screening_gates(ConfigHandle  handle,
                                                     ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_screening_gates(real_channel)));
}

ConnectionsHandle Config_get_channel_dot_gates(ConfigHandle  handle,
                                               ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_dot_gates(real_channel)));
}

ConnectionsHandle Config_get_channel_gates(ConfigHandle  handle,
                                           ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_gates(real_channel)));
}

ConnectionsHandle Config_get_channel_ohmics(ConfigHandle  handle,
                                            ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_ohmics(real_channel)));
}

ConnectionsHandle Config_get_channel_order_no_ohmics(ConfigHandle  handle,
                                                     ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_channel_order_no_ohmics(real_channel)));
}

int Config_get_num_unique_channels(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return self.num_unique_channels();
}

ChannelsHandle Config_return_channels_from_gate(ConfigHandle     handle,
                                                ConnectionHandle gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              gate));
  return new falcon_core::autotuner_interfaces::names::Channels(
      *(self.return_channels_from_gate(real_gate)));
}

ChannelHandle Config_return_channel_from_gate(ConfigHandle     handle,
                                              ConnectionHandle gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              gate));
  return new falcon_core::autotuner_interfaces::names::Channel(
      *self.return_channel_from_gate(real_gate));
}

bool Config_ohmic_in_channel(ConfigHandle     handle,
                             ConnectionHandle ohmic,
                             ChannelHandle    channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              ohmic));
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return self.ohmic_in_channel(real_ohmic, real_channel);
}

PairConnectionConnectionHandle Config_get_dot_channel_neighbors(
    ConfigHandle handle, ConnectionHandle dot_gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_dot_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              dot_gate));
  auto neighbors = self.get_dot_channel_neighbors(real_dot_gate);
  return new std::pair<Connection, Connection>(*(neighbors.first),
                                               *(neighbors.second));
}

MapChannelConnectionsHandle Config_get_barrier_gate_dict(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_barrier_gate_dict()));
}

MapChannelConnectionsHandle Config_get_plunger_gate_dict(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_plunger_gate_dict()));
}

MapChannelConnectionsHandle Config_get_reservoir_gate_dict(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_reservoir_gate_dict()));
}

MapChannelConnectionsHandle Config_get_screening_gate_dict(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_screening_gate_dict()));
}

MapChannelConnectionsHandle Config_get_dot_gate_dict(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_dot_gate_dict()));
}

MapChannelConnectionsHandle Config_get_gate_dict(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_gate_dict()));
}

ConnectionsHandle Config_get_isolated_barrier_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_isolated_barrier_gates()));
}

ConnectionsHandle Config_get_isolated_plunger_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_isolated_plunger_gates()));
}

ConnectionsHandle Config_get_isolated_reservoir_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_isolated_reservoir_gates()));
}

ConnectionsHandle Config_get_isolated_screening_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_isolated_screening_gates()));
}

ConnectionsHandle Config_get_isolated_dot_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_isolated_dot_gates()));
}

ConnectionsHandle Config_get_isolated_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_isolated_gates()));
}

ConnectionsHandle Config_get_shared_barrier_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_shared_barrier_gates()));
}

ConnectionsHandle Config_get_shared_plunger_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_shared_plunger_gates()));
}

ConnectionsHandle Config_get_shared_reservoir_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_shared_reservoir_gates()));
}

ConnectionsHandle Config_get_shared_screening_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_shared_screening_gates()));
}

ConnectionsHandle Config_get_shared_dot_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_shared_dot_gates()));
}

ConnectionsHandle Config_get_shared_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_shared_gates()));
}

ConnectionsHandle Config_get_chared_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_shared_channel_barrier_gates(real_channel)));
}

ConnectionsHandle Config_get_shared_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_shared_channel_plunger_gates(real_channel)));
}

ConnectionsHandle Config_get_shared_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_shared_channel_reservoir_gates(real_channel)));
}

ConnectionsHandle Config_get_shared_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_shared_channel_screening_gates(real_channel)));
}

ConnectionsHandle Config_get_shared_channel_dot_gates(ConfigHandle  handle,
                                                      ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_shared_channel_dot_gates(real_channel)));
}

ConnectionsHandle Config_get_shared_channel_gates(ConfigHandle  handle,
                                                  ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_shared_channel_gates(real_channel)));
}

ConnectionsHandle Config_get_isolated_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_isolated_channel_barrier_gates(real_channel)));
}

ConnectionsHandle Config_get_isolated_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_isolated_channel_plunger_gates(real_channel)));
}

ConnectionsHandle Config_get_isolated_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_isolated_channel_reservoir_gates(real_channel)));
}

ConnectionsHandle Config_get_isolated_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(
      *(self.get_isolated_channel_screening_gates(real_channel)));
}

ConnectionsHandle Config_get_isolated_channel_dot_gates(ConfigHandle  handle,
                                                        ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_isolated_channel_dot_gates(real_channel)));
}

ConnectionsHandle Config_get_isolated_channel_gates(ConfigHandle  handle,
                                                    ChannelHandle channel) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return new Connections(*(self.get_isolated_channel_gates(real_channel)));
}

MapChannelConnectionsHandle Config_get_isolated_barrier_gates_by_channel(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_isolated_barrier_gates_by_channel()));
}

MapChannelConnectionsHandle Config_get_isolated_plunger_gates_by_channel(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_isolated_plunger_gates_by_channel()));
}

MapChannelConnectionsHandle Config_get_isolated_reservoir_gates_by_channel(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_isolated_reservoir_gates_by_channel()));
}

MapChannelConnectionsHandle Config_get_isolated_screening_gates_by_channel(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_isolated_screening_gates_by_channel()));
}

MapChannelConnectionsHandle Config_get_isolated_dot_gates_by_channel(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_isolated_dot_gates_by_channel()));
}

MapChannelConnectionsHandle Config_get_isolated_gates_by_channel(
    ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::autotuner_interfaces::names::Channel, Connections>(
          *(self.get_isolated_gates_by_channel()));
}

GateRelationsHandle Config_generate_gate_relations(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new GateRelations(*(self.generate_gate_relations()));
}

ConnectionsHandle Config_screening_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.screening_gates()));
}

ConnectionsHandle Config_reservoir_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.reservoir_gates()));
}

ConnectionsHandle Config_plunger_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.plunger_gates()));
}

ConnectionsHandle Config_barrier_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.barrier_gates()));
}

ConnectionsHandle Config_ohmics(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.ohmics()));
}

ConnectionsHandle Config_dot_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.dot_gates()));
}

ConnectionHandle Config_get_ohmic(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_ohmic());
}

ConnectionHandle Config_get_barrier_gate(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_barrier_gate());
}

ConnectionHandle Config_get_plunger_gate(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_plunger_gate());
}

ConnectionHandle Config_get_reservoir_gate(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_reservoir_gate());
}

ConnectionHandle Config_get_screening_gate(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_screening_gate());
}

ConnectionHandle Config_get_dot_gate(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_dot_gate());
}

ConnectionHandle Config_get_gate(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connection(*self.get_gate());
}

ConnectionsHandle Config_get_all_gates(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_all_gates()));
}

ConnectionsHandle Config_get_all_connections(ConfigHandle handle) {
  Config self = *static_cast<Config*>(handle);
  return new Connections(*(self.get_all_connections()));
}

bool Config_has_ohmic(ConfigHandle handle, ConnectionHandle ohmic) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              ohmic));
  return self.has_ohmic(real_ohmic);
}

bool Config_has_gate(ConfigHandle handle, ConnectionHandle gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              gate));
  return self.has_gate(real_gate);
}

bool Config_has_barrier_gate(ConfigHandle     handle,
                             ConnectionHandle barrier_gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_barrier_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              barrier_gate));
  return self.has_barrier_gate(real_barrier_gate);
}

bool Config_has_plunger_gate(ConfigHandle     handle,
                             ConnectionHandle plunger_gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_plunger_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              plunger_gate));
  return self.has_plunger_gate(real_plunger_gate);
}

bool Config_has_reservoir_gate(ConfigHandle     handle,
                               ConnectionHandle reservoir_gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_reservoir_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              reservoir_gate));
  return self.has_reservoir_gate(real_reservoir_gate);
}

bool Config_has_screening_gate(ConfigHandle     handle,
                               ConnectionHandle screening_gate) {
  Config self = *static_cast<Config*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_screening_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              screening_gate));
  return self.has_screening_gate(real_screening_gate);
}

bool Config_equal(ConfigHandle handle, ConfigHandle other) {
  Config self         = *static_cast<Config*>(handle);
  Config other_config = *static_cast<Config*>(other);
  return self == other_config;
}

bool Config_not_equal(ConfigHandle handle, ConfigHandle other) {
  Config self         = *static_cast<Config*>(handle);
  Config other_config = *static_cast<Config*>(other);
  return self != other_config;
}

StringHandle Config_to_json_string(ConfigHandle handle) {
  Config      self = *static_cast<Config*>(handle);
  std::string json = static_cast<Connection*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

ConfigHandle Config_from_json_string(StringHandle json) {
  auto ptr = Config::from_json_string<Config>(json->raw);
  return new Config(*ptr);
}

#ifdef __cplusplus
}
#endif
