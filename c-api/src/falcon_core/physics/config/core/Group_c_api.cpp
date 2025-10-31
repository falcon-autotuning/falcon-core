#include "falcon_core/physics/config/core/Group_c_api.h"

#include <falcon_core/physics/config/core/Group.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::config::core;
using namespace falcon_core::physics::device_structures;

extern "C" {

GroupHandle Group_create(ChannelHandle     name,
                         int               num_dots,
                         ConnectionsHandle screening_gates,
                         ConnectionsHandle reservoir_gates,
                         ConnectionsHandle plunger_gates,
                         ConnectionsHandle barrier_gates,
                         ConnectionsHandle order) {
  falcon_core::autotuner_interfaces::names::ChannelSP real_name =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              name));
  ConnectionsSP real_screening_gates = std::make_shared<Connections>(
      *static_cast<Connections*>(screening_gates));
  ConnectionsSP real_reservoir_gates = std::make_shared<Connections>(
      *static_cast<Connections*>(reservoir_gates));
  ConnectionsSP real_plunger_gates =
      std::make_shared<Connections>(*static_cast<Connections*>(plunger_gates));
  ConnectionsSP real_barrier_gates =
      std::make_shared<Connections>(*static_cast<Connections*>(barrier_gates));
  ConnectionsSP real_order =
      std::make_shared<Connections>(*static_cast<Connections*>(order));
  return new Group(real_name,
                   num_dots,
                   real_screening_gates,
                   real_reservoir_gates,
                   real_plunger_gates,
                   real_barrier_gates,
                   real_order);
}

void Group_destroy(GroupHandle handle) { delete static_cast<Group*>(handle); }

ChannelHandle Group_name(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new falcon_core::autotuner_interfaces::names::Channel(*self.name());
}

int Group_num_dots(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return self.num_dots();
}

GateGeometryArray1DHandle Group_order(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new falcon_core::physics::config::geometries::GateGeometryArray1D(
      *self.order());
}

bool Group_has_channel(GroupHandle handle, ChannelHandle channel) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              channel));
  return self.has_channel(real_channel);
}

bool Group_is_charge_sensor(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return self.is_charge_sensor();
}

ConnectionsHandle Group_get_all_channel_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.get_all_gates()));
}

ConnectionsHandle Group_screening_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.screening_gates()));
}

ConnectionsHandle Group_reservoir_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.reservoir_gates()));
}

ConnectionsHandle Group_plunger_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.plunger_gates()));
}

ConnectionsHandle Group_barrier_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.barrier_gates()));
}

ConnectionsHandle Group_ohmics(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.ohmics()));
}

ConnectionsHandle Group_dot_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.dot_gates()));
}

ConnectionHandle Group_get_ohmic(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_ohmic());
}

ConnectionHandle Group_get_barrier_gate(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_barrier_gate());
}

ConnectionHandle Group_get_plunger_gate(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_plunger_gate());
}

ConnectionHandle Group_get_reservoir_gate(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_reservoir_gate());
}

ConnectionHandle Group_get_screening_gate(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_screening_gate());
}

ConnectionHandle Group_get_dot_gate(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_dot_gate());
}

ConnectionHandle Group_get_gate(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connection(*self.get_gate());
}

ConnectionsHandle Group_get_all_gates(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.get_all_gates()));
}

ConnectionsHandle Group_get_all_connections(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return new Connections(*(self.get_all_connections()));
}

bool Group_has_ohmic(GroupHandle handle, ConnectionHandle ohmic) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              ohmic));
  return self.has_ohmic(real_ohmic);
}

bool Group_has_gate(GroupHandle handle, ConnectionHandle gate) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              gate));
  return self.has_gate(real_gate);
}

bool Group_has_barrier_gate(GroupHandle handle, ConnectionHandle barrier_gate) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_barrier_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              barrier_gate));
  return self.has_barrier_gate(real_barrier_gate);
}

bool Group_has_plunger_gate(GroupHandle handle, ConnectionHandle plunger_gate) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_plunger_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              plunger_gate));
  return self.has_plunger_gate(real_plunger_gate);
}

bool Group_has_reservoir_gate(GroupHandle      handle,
                              ConnectionHandle reservoir_gate) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_reservoir_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              reservoir_gate));
  return self.has_reservoir_gate(real_reservoir_gate);
}

bool Group_has_screening_gate(GroupHandle      handle,
                              ConnectionHandle screening_gate) {
  Group self = *static_cast<Group*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_screening_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              screening_gate));
  return self.has_screening_gate(real_screening_gate);
}

bool Group_equal(GroupHandle handle, GroupHandle other) {
  Group self        = *static_cast<Group*>(handle);
  Group other_group = *static_cast<Group*>(other);
  return self == other_group;
}

bool Group_not_equal(GroupHandle handle, GroupHandle other) {
  Group self        = *static_cast<Group*>(handle);
  Group other_group = *static_cast<Group*>(other);
  return self != other_group;
}

StringHandle Group_to_json_string(GroupHandle handle) {
  Group self = *static_cast<Group*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

GroupHandle Group_from_json_string(StringHandle json) {
  std::string json_str(json->raw);
  return new Group(*Group::from_json_string<Group>(json_str));
}

#ifdef __cplusplus
}
#endif
