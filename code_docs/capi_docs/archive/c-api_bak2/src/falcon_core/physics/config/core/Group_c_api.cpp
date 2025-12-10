#include "falcon_core/physics/config/core/Group_c_api.h"

#include <falcon_core/physics/config/core/Group.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::physics::config::core;
using namespace falcon_core::physics::device_structures;

extern "C" {
DEFINE_C_API_COPY(Group);
DEFINE_C_API_DESTROY(Group);
DEFINE_C_API_EQUAL(Group);
DEFINE_C_API_NOT_EQUAL(Group);
DEFINE_C_API_TO_JSON(Group);
DEFINE_C_API_FROM_JSON(Group);
GroupHandle Group_create(ChannelHandle     name,
                         int               num_dots,
                         ConnectionsHandle screening_gates,
                         ConnectionsHandle reservoir_gates,
                         ConnectionsHandle plunger_gates,
                         ConnectionsHandle barrier_gates,
                         ConnectionsHandle order) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument("Group_create: name cannot be null");
  }
  if (!screening_gates) {
    throw std::invalid_argument("Group_create: screening_gates cannot be null");
  }
  if (!reservoir_gates) {
    throw std::invalid_argument("Group_create: reservoir_gates cannot be null");
  }
  if (!plunger_gates) {
    throw std::invalid_argument("Group_create: plunger_gates cannot be null");
  }
  if (!barrier_gates) {
    throw std::invalid_argument("Group_create: barrier_gates cannot be null");
  }
  if (!order) {
    throw std::invalid_argument("Group_create: order cannot be null");
  }
  falcon_core::autotuner_interfaces::names::ChannelSP real_name =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(name);
  ConnectionsSP real_screening_gates =
      *static_cast<ConnectionsSP*>(screening_gates);
  ConnectionsSP real_reservoir_gates =
      *static_cast<ConnectionsSP*>(reservoir_gates);
  ConnectionsSP real_plunger_gates =
      *static_cast<ConnectionsSP*>(plunger_gates);
  ConnectionsSP real_barrier_gates =
      *static_cast<ConnectionsSP*>(barrier_gates);
  ConnectionsSP real_order = *static_cast<ConnectionsSP*>(order);
  return new GroupSP(std::make_shared<Group>(real_name,
                                             num_dots,
                                             real_screening_gates,
                                             real_reservoir_gates,
                                             real_plunger_gates,
                                             real_barrier_gates,
                                             real_order));
  FALCON_C_API_END(nullptr)
}

ChannelHandle Group_name(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_name: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new falcon_core::autotuner_interfaces::names::ChannelSP(self->name());
  FALCON_C_API_END(nullptr)
}

int Group_num_dots(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_num_dots: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return self->num_dots();
  FALCON_C_API_END(0)
}

GateGeometryArray1DHandle Group_order(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_order: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new falcon_core::physics::config::geometries::GateGeometryArray1DSP(
      self->order());
  FALCON_C_API_END(nullptr)
}

bool Group_has_channel(GroupHandle handle, ChannelHandle channel) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_has_channel: handle cannot be null");
  }
  if (!channel) {
    throw std::invalid_argument("Group_has_channel: channel cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_channel =
      *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(
          channel);
  return self->has_channel(real_channel);
  FALCON_C_API_END(false)
}

bool Group_is_charge_sensor(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_is_charge_sensor: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return self->is_charge_sensor();
  FALCON_C_API_END(false)
}

ConnectionsHandle Group_get_all_channel_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_get_all_channel_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->get_all_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_screening_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_screening_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->screening_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_reservoir_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_reservoir_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->reservoir_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_plunger_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_plunger_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->plunger_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_barrier_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_barrier_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->barrier_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_ohmics(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_ohmics: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->ohmics());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_dot_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_dot_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->dot_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_ohmic(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_get_ohmic: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_ohmic());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_barrier_gate(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_get_barrier_gate: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_barrier_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_plunger_gate(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_get_plunger_gate: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_plunger_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_reservoir_gate(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_get_reservoir_gate: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_reservoir_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_screening_gate(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_get_screening_gate: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_screening_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_dot_gate(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_get_dot_gate: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_dot_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Group_get_gate(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_get_gate: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionSP(self->get_gate());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_get_all_gates(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_get_all_gates: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->get_all_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Group_get_all_connections(GroupHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_get_all_connections: handle cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  return new ConnectionsSP(self->get_all_connections());
  FALCON_C_API_END(nullptr)
}

bool Group_has_ohmic(GroupHandle handle, ConnectionHandle ohmic) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_has_ohmic: handle cannot be null");
  }
  if (!ohmic) {
    throw std::invalid_argument("Group_has_ohmic: ohmic cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_ohmic =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          ohmic);
  return self->has_ohmic(real_ohmic);
  FALCON_C_API_END(false)
}

bool Group_has_gate(GroupHandle handle, ConnectionHandle gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Group_has_gate: handle cannot be null");
  }
  if (!gate) {
    throw std::invalid_argument("Group_has_gate: gate cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          gate);
  return self->has_gate(real_gate);
  FALCON_C_API_END(false)
}

bool Group_has_barrier_gate(GroupHandle handle, ConnectionHandle barrier_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_has_barrier_gate: handle cannot be null");
  }
  if (!barrier_gate) {
    throw std::invalid_argument(
        "Group_has_barrier_gate: barrier_gate cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_barrier_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          barrier_gate);
  return self->has_barrier_gate(real_barrier_gate);
  FALCON_C_API_END(false)
}

bool Group_has_plunger_gate(GroupHandle handle, ConnectionHandle plunger_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_has_plunger_gate: handle cannot be null");
  }
  if (!plunger_gate) {
    throw std::invalid_argument(
        "Group_has_plunger_gate: plunger_gate cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_plunger_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          plunger_gate);
  return self->has_plunger_gate(real_plunger_gate);
  FALCON_C_API_END(false)
}

bool Group_has_reservoir_gate(GroupHandle      handle,
                              ConnectionHandle reservoir_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_has_reservoir_gate: handle cannot be null");
  }
  if (!reservoir_gate) {
    throw std::invalid_argument(
        "Group_has_reservoir_gate: reservoir_gate cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_reservoir_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          reservoir_gate);
  return self->has_reservoir_gate(real_reservoir_gate);
  FALCON_C_API_END(false)
}

bool Group_has_screening_gate(GroupHandle      handle,
                              ConnectionHandle screening_gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Group_has_screening_gate: handle cannot be null");
  }
  if (!screening_gate) {
    throw std::invalid_argument(
        "Group_has_screening_gate: screening_gate cannot be null");
  }
  GroupSP self = *static_cast<GroupSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_screening_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          screening_gate);
  return self->has_screening_gate(real_screening_gate);
  FALCON_C_API_END(false)
}
}
