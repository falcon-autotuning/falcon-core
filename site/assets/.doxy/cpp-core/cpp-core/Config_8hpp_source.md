

# File Config.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**core**](dir_21a9197520b9e1fed8f7aab3c046d422.md) **>** [**Config.hpp**](Config_8hpp.md)

[Go to the documentation of this file](Config_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/names/Channels.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/core/VoltageConstraints.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/GateRelations.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace core {
class Config : public StandardConfigConnections {
  int                                     _num_unique_channels;
  device_structures::ImpedancesSP         _wiring_DC;
  autotuner_interfaces::names::ChannelsSP _channels;
  VoltageConstraintsSP                    _voltage_constraints;
  generic::MapSP<autotuner_interfaces::names::Gname, Group> _groups;
  mutable std::shared_timed_mutex                           _mu_channels;
  mutable std::shared_timed_mutex                           _mu_groups;
  mutable std::shared_timed_mutex                           _mu_wiring_DC;
  mutable std::shared_timed_mutex _mu_voltage_constraints;
  mutable std::shared_timed_mutex _mu_num_unique_channels;

 public:
  Config(const Config& other);
  Config& operator=(const Config& other);
  Config(const device_structures::ConnectionsSP& screening_gates,
         const device_structures::ConnectionsSP& plunger_gates,
         const device_structures::ConnectionsSP& ohmics,
         const device_structures::ConnectionsSP& barrier_gates,
         const device_structures::ConnectionsSP& reservoir_gates,
         const generic::MapSP<autotuner_interfaces::names::Gname, Group> groups,
         const device_structures::ImpedancesSP& wiring_DC,
         const VoltageConstraintsSP&            constriants);
  int num_unique_channels() const;
  VoltageConstraintsSP voltage_constraints() const;
  generic::MapSP<autotuner_interfaces::names::Gname, Group> groups() const;
  device_structures::ImpedancesSP wiring_DC() const;
  autotuner_interfaces::names::ChannelsSP channels() const;
  void check_impedance_consistency() const;
  void check_group_consistency() const;
  device_structures::ImpedanceSP get_impedance(
      const device_structures::ConnectionSP& connection) const;
  generic::ListSP<autotuner_interfaces::names::Gname> get_all_gnames() const;
  generic::ListSP<Group> get_all_groups() const;
  void compile_channels() const;
  bool has_channel(const autotuner_interfaces::names::ChannelSP& channel) const;
  bool has_gname(const autotuner_interfaces::names::GnameSP& gname) const;
  GroupSP select_group(const autotuner_interfaces::names::GnameSP& gname) const;
  int get_dot_number(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  generic::ListSP<autotuner_interfaces::names::Gname> get_charge_sense_groups()
      const;
  bool ohmic_in_charge_sensor(
      const device_structures::ConnectionSP& ohmic) const;
  device_structures::ConnectionSP get_associated_ohmic(
      const device_structures::ConnectionSP& reservoir_gate) const;
  autotuner_interfaces::names::ChannelsSP get_current_channels() const;
  autotuner_interfaces::names::GnameSP get_gname(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_group_barrier_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  device_structures::ConnectionsSP get_group_plunger_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  device_structures::ConnectionsSP get_group_reservoir_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  device_structures::ConnectionsSP get_group_screening_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  device_structures::ConnectionsSP get_group_dot_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  device_structures::ConnectionsSP get_group_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  device_structures::ConnectionsSP get_channel_barrier_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_plunger_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_reservoir_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_screening_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_dot_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_ohmics(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_channel_order_no_ohmics(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  int get_num_unique_channels() const;
  autotuner_interfaces::names::ChannelsSP return_channels_from_gate(
      const device_structures::ConnectionSP& gate) const;
  autotuner_interfaces::names::ChannelSP return_channel_from_gate(
      const device_structures::ConnectionSP& gate) const;
  bool ohmic_in_channel(const device_structures::ConnectionSP& ohmic,
                        const autotuner_interfaces::names::ChannelSP&) const;
  std::pair<device_structures::ConnectionSP, device_structures::ConnectionSP>
  get_dot_channel_neighbors(
      const device_structures::ConnectionSP& dotgate) const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_barrier_gate_dict() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_plunger_gate_dict() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_reservoir_gate_dict() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_screening_gate_dict() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_dot_gate_dict() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_gate_dict() const;
  device_structures::ConnectionsSP get_isolated_barrier_gates() const;
  device_structures::ConnectionsSP get_isolated_plunger_gates() const;
  device_structures::ConnectionsSP get_isolated_reservoir_gates() const;
  device_structures::ConnectionsSP get_isolated_screening_gates() const;
  device_structures::ConnectionsSP get_isolated_dot_gates() const;
  device_structures::ConnectionsSP get_isolated_gates() const;
  device_structures::ConnectionsSP get_shared_barrier_gates() const;
  device_structures::ConnectionsSP get_shared_plunger_gates() const;
  device_structures::ConnectionsSP get_shared_reservoir_gates() const;
  device_structures::ConnectionsSP get_shared_screening_gates() const;
  device_structures::ConnectionsSP get_shared_dot_gates() const;
  device_structures::ConnectionsSP get_shared_gates() const;
  device_structures::ConnectionsSP get_shared_channel_barrier_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_shared_channel_plunger_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_shared_channel_reservoir_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_shared_channel_screening_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_shared_channel_dot_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_shared_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_isolated_channel_barrier_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_isolated_channel_plunger_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_isolated_channel_reservoir_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_isolated_channel_screening_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_isolated_channel_dot_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  device_structures::ConnectionsSP get_isolated_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_barrier_gates_by_channel() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_plunger_gates_by_channel() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_reservoir_gates_by_channel() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_screening_gates_by_channel() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_dot_gates_by_channel() const;
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_gates_by_channel() const;

  device_structures::GateRelationsSP generate_gate_relations() const;
  bool                               operator==(const Config& other) const;
  bool                               operator!=(const Config& other) const;

 protected:
  Config();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_channels(_mu_channels,
                                                            std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_groups(_mu_groups,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_wiring_DC(_mu_wiring_DC,
                                                             std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_voltage_constraints(
        _mu_voltage_constraints, std::defer_lock);
    std::lock(
        lock_channels, lock_voltage_constraints, lock_groups, lock_wiring_DC);
    ar(cereal::base_class<StandardConfigConnections>(this),
       _num_unique_channels,
       _wiring_DC,
       _channels,
       _voltage_constraints,
       _groups);
  }
};
using ConfigSP = std::shared_ptr<Config>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


