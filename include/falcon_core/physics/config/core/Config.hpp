#pragma once

#include "falcon_core/autotuner_interfaces/names/Channels.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/core/VoltageConstraints.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
/**
 * @brief The imported config file for falcon use.
 */
class Config : public StandardConfigConnections {
  int                        _num_unique_channels;
  ImpedancesSP               _wiring_DC;
  ChannelsSP                 _channels;
  VoltageConstraintsSP       _voltage_constraints;
  std::map<GnameSP, GroupSP> _groups;

 public:
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
  Config(const ScreeningGatesSP&          screening_gates,
         const PlungerGates&              plunger_gates,
         const Ohmics&                    ohmics,
         const BarrierGates&              barrier_gates,
         const ReservoirGates&            reservoir_gates,
         const std::map<GnameSP, GroupSP> groups,
         const ImpedancesSP&              wiring_DC,
         const VoltageConstraintsSP&      constriants);
  /**
   * @brief Returns the number of unique channels associated with the current
   * sample.
   */
  int num_unique_channels() const;
  /**
   * @brief Return the voltage constraints for the physical layout.
   */
  VoltageConstraintsSP voltage_constraints() const {
    return _voltage_constraints;
  }
  /**
   * @brief Return the DC wiring impedances for the physical layout.
   */
  std::map<GnameSP, GroupSP> groups() const { return _groups; }
  /**
   * @brief Returns the wiring impedances of the config.
   */
  ImpedancesSP wiring_DC() const { return _wiring_DC; }
  /**
   * @brief Returns the channels of the config.
   */
  ChannelsSP channels() const { return _channels; }
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
  ImpedanceSP get_impedance(const BaseConnection& connection) const;
  /**
   * @brief Returns all of the group names.
   */
  std::vector<GnameSP> get_all_gnames() const;
  /**
   * @brief Returns all of the groups.
   */
  std::vector<GroupSP> get_all_groups() const;
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
  bool has_channel(const Channel& channel) const;
  /**
   * @brief Validates if this is a proper gatename.
   * @param gname The gname to validate.
   * @returns true if the gname exists, false otherwise.
   */
  bool has_gname(const Gname& gname) const;
  /**
   * @brief Finds a group from the name and returns it.
   * @param gname The name of the group to find.
   * @returns The group matching the name. A nullptr if no match is found.
   */
  GroupSP select_group(const Gname& gname) const;
  /**
   * @brief Finds the number of dots associated with a current channel from the
   * config.
   * @param channel The channel to find the number of dots for.
   * @returns The number of dots associated with the channel. A 0 if there is no
   * match.
   */
  int get_dot_number(const Channel& channel) const;
  /**
   * @brief Finds all of the arrays of dots that are charge sensors, i.e. only
   * one quantum dot per channel.
   * @returns A vector of gnames that are charge sensors.
   */
  std::vector<GnameSP> get_charge_sense_groups() const;
  /**
   * @brief If the ohmic is inside of a charge sensor channel
   * @param ohmic The ohmic to check
   * @returns true if the ohmic is inside a charge sensor channel
   */
  bool ohmic_in_charge_sensor(const Ohmic& ohmic) const;
  /**
   * @brief Every reservoir gate has an associated ohmic.
   *
   * This pulls the associated ohmic from the config.
   * @param reservoir_gate The reservoir gate to find the associated ohmic for.
   * @returns The ohmic associated with the reservoir gate. A nullptr if no
   * match
   */
  OhmicSP get_associated_ohmic(const ReservoirGate& reservoir_gate) const;
  /**
   * @brief Gets all of the current channels from the config.
   * @returns All of the current channels from the config.
   */
  ChannelsSP get_current_channels() const;
  /**
   * @brief Gets the associated Gname with a Channel if it exists.
   * @param channel The channel to find the associated Gname for.
   * @returns The Gname associated with the Channel. A nullptr if no match is
   * found.
   */
  GnameSP get_gname(const Channel& channel) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  BarrierGatesSP get_group_gates(const Gname&       gname,
                                 const BarrierGate& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  PlungerGatesSP get_group_gates(const Gname&       gname,
                                 const PlungerGate& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  ReservoirGatesSP get_group_gates(const Gname&         gname,
                                   const ReservoirGate& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  ScreeningGatesSP get_group_gates(const Gname&         gname,
                                   const ScreeningGate& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  DotGatesSP<DotGate> get_group_gates(const Gname&   gname,
                                      const DotGate& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  GatesSP<Gate> get_group_gates(const Gname& gname, const Gate& type) const;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<StandardConfigConnections>(this),
       _num_unique_channels,
       _wiring_DC,
       _channels,
       _voltage_constraints,
       _groups);
  }

 protected:
  Config() = default;
  friend class cereal::access;
};
using ConfigSP = std::shared_ptr<Config>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::core;
CEREAL_REGISTER_TYPE(Config)
CEREAL_REGISTER_POLYMORPHIC_RELATION(StandardConfigConnections, Config)
#endif
