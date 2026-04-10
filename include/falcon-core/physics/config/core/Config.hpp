#pragma once

#include "falcon-core/autotuner_interfaces/names/Channels.hpp"
#include "falcon-core/autotuner_interfaces/names/Gname.hpp"
#include "falcon-core/export.h"
#include "falcon-core/physics/config/core/Group.hpp"
#include "falcon-core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon-core/physics/config/core/VoltageConstraints.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
#include "falcon-core/physics/device_structures/GateRelations.hpp"
#include "falcon-core/physics/device_structures/Impedances.hpp"
namespace falcon_core {
namespace generic {
extern template class 
    Map<autotuner_interfaces::names::Channel,
        physics::device_structures::Connections>;
}
namespace physics {
namespace config {
namespace core {
/**
 * @brief The imported config file for falcon use.
 */
class FALCON_CORE_CPP_API Config : public StandardConfigConnections {
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
  /**
   * @brief Constructs a new Config object for falcon use.
   * @param screening_gates The screening gates configuration.
   * @param plunger_gates The plunger gates configuration.
   * @param ohmics The ohmic contacts configuration.
   * @param barrier_gates The barrier gates configuration.
   * @param reservoir_gates The reservoir gates configuration.
   * @param groups A map of group names to Group objects.
   * @param wiring_DC The DC wiring impedances.
   * @param constriants The voltage constraints configuration.
   */
  Config(const device_structures::ConnectionsSP& screening_gates,
         const device_structures::ConnectionsSP& plunger_gates,
         const device_structures::ConnectionsSP& ohmics,
         const device_structures::ConnectionsSP& barrier_gates,
         const device_structures::ConnectionsSP& reservoir_gates,
         const generic::MapSP<autotuner_interfaces::names::Gname, Group> groups,
         const device_structures::ImpedancesSP& wiring_DC,
         const VoltageConstraintsSP&            constriants);
  /**
   * @brief Returns the number of unique channels associated with the current
   * sample.
   */
  int num_unique_channels() const;
  /**
   * @brief Return the voltage constraints for the physical layout.
   */
  VoltageConstraintsSP voltage_constraints() const;
  /**
   * @brief Return the DC wiring impedances for the physical layout.
   */
  generic::MapSP<autotuner_interfaces::names::Gname, Group> groups() const;
  /**
   * @brief Returns the wiring impedances of the config.
   */
  device_structures::ImpedancesSP wiring_DC() const;
  /**
   * @brief Returns the channels of the config.
   */
  autotuner_interfaces::names::ChannelsSP channels() const;
  /**
   * @brief Check that all impedances are consistent.
   *
   * None of the gates or ohmics should be missing from the impedances.
   * @throws std::runtime_error if any of the impedances are inconsistent.
   */
  void check_impedance_consistency() const;
  /**
   * @brief Check that all groups are consistent.
   *
   * None of the gates or ohmics should be missing from the groups.
   *
   * @throws std::runtime_error if any of the groups are inconsistent.
   */
  void check_group_consistency() const;
  /**
   * @brief Returns the impedance matching the connection in teh dcwiring.
   * @returns The impedance matching the connection in teh dcwiring. A nullptr
   * if no match is found.
   */
  device_structures::ImpedanceSP get_impedance(
      const device_structures::ConnectionSP& connection) const;
  /**
   * @brief Returns all of the group names.
   */
  generic::ListSP<autotuner_interfaces::names::Gname> get_all_gnames() const;
  /**
   * @brief Returns all of the groups.
   */
  generic::ListSP<Group> get_all_groups() const;
  /**
   * @brief Searches through all Group and collects all of the Channel.
   */
  void compile_channels() const;
  /**
   * @brief Validates if this is a proper Channel name in the set of all device
   * Channels.
   * @param channel The channel to validate.
   * @returns true if the channel exists, false otherwise.
   */
  bool has_channel(const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Validates if this is a proper gatename.
   * @param gname The gname to validate.
   * @returns true if the gname exists, false otherwise.
   */
  bool has_gname(const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Finds a group from the name and returns it.
   * @param gname The name of the group to find.
   * @returns The group matching the name. A nullptr if no match is found.
   */
  GroupSP select_group(const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Finds the number of dots associated with a current channel from the
   * config.
   * @param channel The channel to find the number of dots for.
   * @returns The number of dots associated with the channel. A 0 if there is no
   * match.
   */
  int get_dot_number(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds all of the arrays of dots that are charge sensors, i.e. only
   * one quantum dot per channel.
   * @returns A vector of gnames that are charge sensors.
   */
  generic::ListSP<autotuner_interfaces::names::Gname> get_charge_sense_groups()
      const;
  /**
   * @brief If the ohmic is inside of a charge sensor channel
   * @param ohmic The ohmic to check
   * @returns true if the ohmic is inside a charge sensor channel
   */
  bool ohmic_in_charge_sensor(
      const device_structures::ConnectionSP& ohmic) const;
  /**
   * @brief Every reservoir gate has an associated ohmic.
   *
   * This pulls the associated ohmic from the config.
   * @param reservoir_gate The reservoir gate to find the associated ohmic for.
   * @returns The ohmic associated with the reservoir gate. A nullptr if no
   * match
   */
  device_structures::ConnectionSP get_associated_ohmic(
      const device_structures::ConnectionSP& reservoir_gate) const;
  /**
   * @brief Gets all of the current channels from the config.
   * @returns All of the current channels from the config.
   */
  autotuner_interfaces::names::ChannelsSP get_current_channels() const;
  /**
   * @brief Gets the associated Gname with a Channel if it exists.
   * @param channel The channel to find the associated Gname for.
   * @returns The Gname associated with the Channel. A nullptr if no match is
   * found.
   */
  autotuner_interfaces::names::GnameSP get_gname(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the barrier gates assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_group_barrier_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Gets all of the plunger gates assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_group_plunger_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Gets all of the reservoir gates assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_group_reservoir_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Gets all of the screening gates assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_group_screening_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Gets all of the dot gates assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_group_dot_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Gets all of the gates assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_group_gates(
      const autotuner_interfaces::names::GnameSP& gname) const;
  /**
   * @brief Gets all of the barrier gates assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_barrier_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the plunger gates assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_plunger_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the reservoir gates assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * channel. Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_reservoir_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the screening gates assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_screening_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the dot gates assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_dot_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the gates assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the ohmics assocated with the selected current channel.
   * @param channel The channel to find the ohmics for.
   * @returns All of the ohmics assocated with the selected channel. Otherwise a
   * nullptr if no match is found.
   */
  device_structures::ConnectionsSP get_channel_ohmics(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Gets all of the gates in the order at the selected channel from the
   * config with no ohmics.
   * @param channel The channel to find the gates for.
   * @returns All of the gates in the order at the selected channel. Otherwise a
   * nullptr
   */
  device_structures::ConnectionsSP get_channel_order_no_ohmics(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Returns the number of unique channels associated with the current
   * sample.
   */
  int get_num_unique_channels() const;
  /**
   * @brief Returns all of the channels associated with a gate.
   * @param gate The gate to find the channels for.
   * @returns All of the channels associated with a gate. Otherwise a nullptr if
   * no match is found.
   */
  autotuner_interfaces::names::ChannelsSP return_channels_from_gate(
      const device_structures::ConnectionSP& gate) const;
  /**
   * @brief Returns the channel a given gate belongs to. If the gate is in
   * multiple channels, if will return the first channel if finds.
   * @param gate The gate to find the channel for.
   * @returns The channel the gate belongs to. A nullptr if no match is found.
   */
  autotuner_interfaces::names::ChannelSP return_channel_from_gate(
      const device_structures::ConnectionSP& gate) const;
  /**
   * @brief Checks if the ohmic is connected to a channel.
   * @param ohmic The ohmic to diagnose.
   * @param channel The channel to check the ohmic against.
   * @returns true if the ohmic is connected to the channel, false otherwise.
   */
  bool ohmic_in_channel(const device_structures::ConnectionSP& ohmic,
                        const autotuner_interfaces::names::ChannelSP&) const;
  /**
   * @brief Gets the nearby neighbors of the selected gate in the dot channel.
   * @param dotgate The gate of interest (must be in dot channel)
   * @return A pair of GateSP (left, right) if found, nullptr otherwise.
   */
  std::pair<device_structures::ConnectionSP, device_structures::ConnectionSP>
  get_dot_channel_neighbors(
      const device_structures::ConnectionSP& dotgate) const;
  /**
   * @brief Returns barrier gates indexed by channel.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_barrier_gate_dict() const;
  /**
   * @brief Returns plunger gates indexed by channel.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_plunger_gate_dict() const;
  /**
   * @brief Returns reservoir gates indexed by channel.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_reservoir_gate_dict() const;
  /**
   * @brief Returns screening gates indexed by channel.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_screening_gate_dict() const;
  /**
   * @brief Returns dot gates indexed by channel.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_dot_gate_dict() const;
  /**
   * @brief Returns gates indexed by channel.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_gate_dict() const;
  /**
   * @brief Task to find isolated barrier gates stored in the config.
   */
  device_structures::ConnectionsSP get_isolated_barrier_gates() const;
  /**
   * @brief Task to find isolated plunger gates stored in the config.
   */
  device_structures::ConnectionsSP get_isolated_plunger_gates() const;
  /**
   * @brief Task to find isolated reservoir gates stored in the config.
   */
  device_structures::ConnectionsSP get_isolated_reservoir_gates() const;
  /**
   * @brief Task to find isolated screening gates stored in the config.
   */
  device_structures::ConnectionsSP get_isolated_screening_gates() const;
  /**
   * @brief Task to find isolated dot gates stored in the config.
   */
  device_structures::ConnectionsSP get_isolated_dot_gates() const;
  /**
   * @brief Task to find isolated gates stored in the config.
   */
  device_structures::ConnectionsSP get_isolated_gates() const;
  /**
   * @brief Task to find shared barrier gates stored in the config.
   */
  device_structures::ConnectionsSP get_shared_barrier_gates() const;
  /**
   * @brief Task to find shared plunger gates stored in the config.
   */
  device_structures::ConnectionsSP get_shared_plunger_gates() const;
  /**
   * @brief Task to find shared reservoir gates stored in the config.
   */
  device_structures::ConnectionsSP get_shared_reservoir_gates() const;
  /**
   * @brief Task to find shared screening gates stored in the config.
   */
  device_structures::ConnectionsSP get_shared_screening_gates() const;
  /**
   * @brief Task to find shared dot gates stored in the config.
   */
  device_structures::ConnectionsSP get_shared_dot_gates() const;
  /**
   * @brief Task to find shared gates stored in the config.
   */
  device_structures::ConnectionsSP get_shared_gates() const;
  /**
   * @brief Finds the shared barrier gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gateytpe that are shared in
   * the selected channel.
   */
  device_structures::ConnectionsSP get_shared_channel_barrier_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the shared plunger gates in the selected
   * channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gateytpe that are shared in
   * the selected channel.
   */
  device_structures::ConnectionsSP get_shared_channel_plunger_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the shared reservoir gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gateytpe that are shared
   * in the selected channel.
   */
  device_structures::ConnectionsSP get_shared_channel_reservoir_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the shared screening gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gateytpe that are shared
   * in the selected channel.
   */
  device_structures::ConnectionsSP get_shared_channel_screening_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the shared dot gates of the gatetype in the selected channel.
   * @param channel The channel of the device of interest.
   * @return DotGatesSP list of all gates of the gateytpe that are shared in the
   * selected channel.
   */
  device_structures::ConnectionsSP get_shared_channel_dot_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the shared gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return GatesSP<Gate> list of all gates of the gateytpe that are shared in
   * the selected channel.
   */
  device_structures::ConnectionsSP get_shared_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the isolated barrier gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gatetype that are isolated
   * in the selected channel.
   */
  device_structures::ConnectionsSP get_isolated_channel_barrier_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the isolated plunger gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gatetype that are isolated
   * in the selected channel.
   */
  device_structures::ConnectionsSP get_isolated_channel_plunger_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the isolated reservoir gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gatetype that are
   * isolated in the selected channel.
   */
  device_structures::ConnectionsSP get_isolated_channel_reservoir_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the isolated screening gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return ConnectionsSP list of all gates of the gatetype that are
   * isolated in the selected channel.
   */
  device_structures::ConnectionsSP get_isolated_channel_screening_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the isolated dot gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return DotGatesSP list of all gates of the gatetype that are isolated in
   * the selected channel.
   */
  device_structures::ConnectionsSP get_isolated_channel_dot_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Finds the isolated gates in the selected channel.
   * @param channel The channel of the device of interest.
   * @return GatesSP<Gate> list of all gates of the gatetype that are isolated
   * in the selected channel.
   */
  device_structures::ConnectionsSP get_isolated_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Returns barrier gates indexed by channel which are
   * unshared.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_barrier_gates_by_channel() const;
  /**
   * @brief Returns plunger gates indexed by channel which are
   * unshared.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_plunger_gates_by_channel() const;
  /**
   * @brief Returns reservoir gates indexed by channel which are
   * unshared.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_reservoir_gates_by_channel() const;
  /**
   * @brief Returns screening gates indexed by channel which are
   * unshared.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_screening_gates_by_channel() const;
  /**
   * @brief Returns dot gates indexed by channel which are
   * unshared.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_dot_gates_by_channel() const;
  /**
   * @brief Returns gates indexed by channel which are
   * unshared.
   */
  generic::MapSP<autotuner_interfaces::names::Channel,
                 device_structures::Connections>
  get_isolated_gates_by_channel() const;

  /**
   * @brief Returns the gate relations in the config.
   */
  device_structures::GateRelationsSP generate_gate_relations() const;
  bool                               operator==(const Config& other) const;
  bool                               operator!=(const Config& other) const;

 protected:
  Config();
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
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
