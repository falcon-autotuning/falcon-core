#pragma once

#include "falcon_core/autotuner_interfaces/names/Channels.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/core/VoltageConstraints.hpp"
#include "falcon_core/physics/device_structures/GateRelations.hpp"
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
  int                          _num_unique_channels;
  ImpedancesSP                 _wiring_DC;
  ChannelsSP                   _channels;
  VoltageConstraintsSP         _voltage_constraints;
  generic::MapSP<Gname, Group> _groups;

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
  Config(const ScreeningGatesSP&            screening_gates,
         const PlungerGatesSP&              plunger_gates,
         const OhmicsSP&                    ohmics,
         const BarrierGatesSP&              barrier_gates,
         const ReservoirGatesSP&            reservoir_gates,
         const generic::MapSP<Gname, Group> groups,
         const ImpedancesSP&                wiring_DC,
         const VoltageConstraintsSP&        constriants);
  /**
   * @brief Returns the number of unique channels associated with the current
   * sample.
   */
  int num_unique_channels() const { return _num_unique_channels; }
  /**
   * @brief Return the voltage constraints for the physical layout.
   */
  VoltageConstraintsSP voltage_constraints() const {
    return _voltage_constraints;
  }
  /**
   * @brief Return the DC wiring impedances for the physical layout.
   */
  generic::MapSP<Gname, Group> groups() const { return _groups; }
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
  bool has_channel(const ChannelSP& channel) const;
  /**
   * @brief Validates if this is a proper gatename.
   * @param gname The gname to validate.
   * @returns true if the gname exists, false otherwise.
   */
  bool has_gname(const GnameSP& gname) const;
  /**
   * @brief Finds a group from the name and returns it.
   * @param gname The name of the group to find.
   * @returns The group matching the name. A nullptr if no match is found.
   */
  GroupSP select_group(const GnameSP& gname) const;
  /**
   * @brief Finds the number of dots associated with a current channel from the
   * config.
   * @param channel The channel to find the number of dots for.
   * @returns The number of dots associated with the channel. A 0 if there is no
   * match.
   */
  int get_dot_number(const ChannelSP& channel) const;
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
  bool ohmic_in_charge_sensor(const OhmicSP& ohmic) const;
  /**
   * @brief Every reservoir gate has an associated ohmic.
   *
   * This pulls the associated ohmic from the config.
   * @param reservoir_gate The reservoir gate to find the associated ohmic for.
   * @returns The ohmic associated with the reservoir gate. A nullptr if no
   * match
   */
  OhmicSP get_associated_ohmic(const ReservoirGateSP& reservoir_gate) const;
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
  GnameSP get_gname(const ChannelSP& channel) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  BarrierGatesSP get_group_gates(const GnameSP&       gname,
                                 const BarrierGateSP& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  PlungerGatesSP get_group_gates(const GnameSP&       gname,
                                 const PlungerGateSP& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  ReservoirGatesSP get_group_gates(const GnameSP&         gname,
                                   const ReservoirGateSP& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  ScreeningGatesSP get_group_gates(const GnameSP&         gname,
                                   const ScreeningGateSP& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  DotGatesSP<DotGate> get_group_gates(const GnameSP&   gname,
                                      const DotGateSP& type) const;
  /**
   * @brief Gets all of the gates of a gatetype assocated with the selected
   * group from the config.
   * @param gname The group name to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected group.
   * Otherwise a nullptr if no match is found.
   */
  GatesSP<Gate> get_group_gates(const GnameSP& gname, const GateSP& type) const;
  /**
   * @brief Gets all fo the gates of a gatetype assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  BarrierGatesSP get_channel_gates(const ChannelSP&     channel,
                                   const BarrierGateSP& type) const;
  /**
   * @brief Gets all fo the gates of a gatetype assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  PlungerGatesSP get_channel_gates(const ChannelSP&     channel,
                                   const PlungerGateSP& type) const;
  /**
   * @brief Gets all fo the gates of a gatetype assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  ReservoirGatesSP get_channel_gates(const ChannelSP&       channel,
                                     const ReservoirGateSP& type) const;
  /**
   * @brief Gets all fo the gates of a gatetype assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  ScreeningGatesSP get_channel_gates(const ChannelSP&       channel,
                                     const ScreeningGateSP& type) const;
  /**
   * @brief Gets all fo the gates of a gatetype assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  DotGatesSP<DotGate> get_channel_gates(const ChannelSP& channel,
                                        const DotGateSP& type) const;
  /**
   * @brief Gets all fo the gates of a gatetype assocated with the selected
   * current channel from the config.
   * @param channel The channel to find the gates for.
   * @param type The gate type to find the gates for.
   * @returns All of the gates of a gatetype assocated with the selected
   * channel. Otherwise a nullptr if no match is found.
   */
  GatesSP<Gate> get_channel_gates(const ChannelSP& channel,
                                  const GateSP&    type) const;
  /**
   * @brief Gets all of the gates assocated with the selected current channel
   * from the config.
   * @param channel The channel to find the gates for.
   * @returns All of the gates assocated with the selected channel. Otherwise a
   * nullptr if no match is found.
   */
  GatesSP<Gate> get_all_channel_gates(const ChannelSP& channel) const;
  /**
   * @brief Gets all of the ohmics assocated with the selected current channel.
   * @param channel The channel to find the ohmics for.
   * @returns All of the ohmics assocated with the selected channel. Otherwise a
   * nullptr if no match is found.
   */
  OhmicsSP get_channel_ohmics(const ChannelSP& channel) const;
  /**
   * @brief Gets all of the gates in the order at the selected channel from the
   * config with no ohmics.
   * @param channel The channel to find the gates for.
   * @returns All of the gates in the order at the selected channel. Otherwise a
   * nullptr
   */
  GatesSP<Gate> get_channel_order_no_ohmics(const ChannelSP& channel) const;
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
  ChannelsSP return_channels_from_gate(const GateSP& gate) const;
  /**
   * @brief Returns the channel a given gate belongs to. If the gate is in
   * multiple channels, if will return the first channel if finds.
   * @param gate The gate to find the channel for.
   * @returns The channel the gate belongs to. A nullptr if no match is found.
   */
  ChannelSP return_channel_from_gate(const GateSP& gate) const;
  /**
   * @brief Checks if the ohmic is connected to a channel.
   * @param ohmic The ohmic to diagnose.
   * @param channel The channel to check the ohmic against.
   * @returns true if the ohmic is connected to the channel, false otherwise.
   */
  bool ohmic_in_channel(const OhmicSP& ohmic, const ChannelSP&) const;
  /**
   * @brief Gets the nearby neighbors of the selected gate in the dot channel.
   * @param dotgate The gate of interest (must be in dot channel)
   * @return A pair of GateSP (left, right) if found, nullptr otherwise.
   */
  std::pair<GateSP, GateSP> get_dot_channel_neighbors(
      const DotGateSP& dotgate) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel.
   * @param type The gate type we want.
   * @return A map from ChannelSP to BarrierGatesSP containing the type of gate
   * we want.
   */
  generic::MapSP<Channel, BarrierGates> get_gate_dict(
      const BarrierGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel.
   * @param type The gate type we want.
   * @return A map from ChannelSP to PlungerGatesSP containing the type of gate
   * we want.
   */
  generic::MapSP<Channel, PlungerGates> get_gate_dict(
      const PlungerGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel.
   * @param type The gate type we want.
   * @return A map from ChannelSP to ReservoirGatesSP containing the type of
   * gate we want.
   */
  generic::MapSP<Channel, ReservoirGates> get_gate_dict(
      const ReservoirGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel.
   * @param type The gate type we want.
   * @return A map from ChannelSP to ScreeningGatesSP containing the type of
   * gate we want.
   */
  generic::MapSP<Channel, ScreeningGates> get_gate_dict(
      const ScreeningGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel.
   * @param type The gate type we want.
   * @return A map from ChannelSP to DotGatesSP containing the type of gate we
   * want.
   */
  generic::MapSP<Channel, DotGates<DotGate>> get_gate_dict(
      const DotGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel.
   * @param type The gate type we want.
   * @return A map from ChannelSP to GatesSP<Gate> containing the type of gate
   * we want.
   */
  generic::MapSP<Channel, Gates<Gate>> get_gate_dict(const GateSP& type) const;
  /**
   * @brief Task to find isolated gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return BarrierGatesSP set of all gates that are unshared of the gatetype.
   */
  BarrierGatesSP get_isolated_gates(const BarrierGateSP& type) const;
  /**
   * @brief Task to find isolated gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return PlungerGatesSP set of all gates that are unshared of the gatetype.
   */
  PlungerGatesSP get_isolated_gates(const PlungerGateSP& type) const;
  /**
   * @brief Task to find isolated gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return ReservoirGatesSP set of all gates that are unshared of the
   * gatetype.
   */
  ReservoirGatesSP get_isolated_gates(const ReservoirGateSP& type) const;
  /**
   * @brief Task to find isolated gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return ScreeningGatesSP set of all gates that are unshared of the
   * gatetype.
   */
  ScreeningGatesSP get_isolated_gates(const ScreeningGateSP& type) const;
  /**
   * @brief Task to find isolated gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return DotGatesSP set of all gates that are unshared of the gatetype.
   */
  DotGatesSP<DotGate> get_isolated_gates(const DotGateSP& type) const;
  /**
   * @brief Task to find isolated gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return GatesSP<Gate> set of all gates that are unshared of the gatetype.
   */
  GatesSP<Gate> get_isolated_gates(const GateSP& type) const;
  /**
   * @brief Task to find shared gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return BarrierGatesSP organized from most shared to least shared gate of
   * the gatetype.
   */
  BarrierGatesSP get_shared_gates(const BarrierGateSP& type) const;
  /**
   * @brief Task to find shared gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return PlungerGatesSP organized from most shared to least shared gate of
   * the gatetype.
   */
  PlungerGatesSP get_shared_gates(const PlungerGateSP& type) const;
  /**
   * @brief Task to find shared gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return ReservoirGatesSP organized from most shared to least shared gate of
   * the gatetype.
   */
  ReservoirGatesSP get_shared_gates(const ReservoirGateSP& type) const;
  /**
   * @brief Task to find shared gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return ScreeningGatesSP organized from most shared to least shared gate of
   * the gatetype.
   */
  ScreeningGatesSP get_shared_gates(const ScreeningGateSP& type) const;
  /**
   * @brief Task to find shared gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return DotGatesSP organized from most shared to least shared gate of the
   * gatetype.
   */
  DotGatesSP<DotGate> get_shared_gates(const DotGateSP& type) const;
  /**
   * @brief Task to find shared gates stored in the config.
   * @param type String corresponding to the gatetype pulled from the config.
   * @return GatesSP<Gate> organized from most shared to least shared gate of
   * the gatetype.
   */
  GatesSP<Gate> get_shared_gates(const GateSP& type) const;
  /**
   * @brief Finds the shared gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return BarrierGatesSP list of all gates of the gateytpe that are shared in
   * the selected channel.
   */
  BarrierGatesSP get_shared_channel_gates(const BarrierGateSP& type,
                                          const ChannelSP&     channel) const;
  /**
   * @brief Finds the shared gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return PlungerGatesSP list of all gates of the gateytpe that are shared in
   * the selected channel.
   */
  PlungerGatesSP get_shared_channel_gates(const PlungerGateSP& type,
                                          const ChannelSP&     channel) const;
  /**
   * @brief Finds the shared gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return ReservoirGatesSP list of all gates of the gateytpe that are shared
   * in the selected channel.
   */
  ReservoirGatesSP get_shared_channel_gates(const ReservoirGateSP& type,
                                            const ChannelSP& channel) const;
  /**
   * @brief Finds the shared gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return ScreeningGatesSP list of all gates of the gateytpe that are shared
   * in the selected channel.
   */
  ScreeningGatesSP get_shared_channel_gates(const ScreeningGateSP& type,
                                            const ChannelSP& channel) const;
  /**
   * @brief Finds the shared gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return DotGatesSP list of all gates of the gateytpe that are shared in the
   * selected channel.
   */
  DotGatesSP<DotGate> get_shared_channel_gates(const DotGateSP& type,
                                               const ChannelSP& channel) const;
  /**
   * @brief Finds the shared gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return GatesSP<Gate> list of all gates of the gateytpe that are shared in
   * the selected channel.
   */
  GatesSP<Gate> get_shared_channel_gates(const GateSP&    type,
                                         const ChannelSP& channel) const;
  /**
   * @brief Finds the isolated gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return BarrierGatesSP list of all gates of the gatetype that are isolated
   * in the selected channel.
   */
  BarrierGatesSP get_isolated_channel_gates(const BarrierGateSP& type,
                                            const ChannelSP&     channel) const;
  /**
   * @brief Finds the isolated gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return PlungerGatesSP list of all gates of the gatetype that are isolated
   * in the selected channel.
   */
  PlungerGatesSP get_isolated_channel_gates(const PlungerGateSP& type,
                                            const ChannelSP&     channel) const;
  /**
   * @brief Finds the isolated gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return ReservoirGatesSP list of all gates of the gatetype that are
   * isolated in the selected channel.
   */
  ReservoirGatesSP get_isolated_channel_gates(const ReservoirGateSP& type,
                                              const ChannelSP& channel) const;
  /**
   * @brief Finds the isolated gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return ScreeningGatesSP list of all gates of the gatetype that are
   * isolated in the selected channel.
   */
  ScreeningGatesSP get_isolated_channel_gates(const ScreeningGateSP& type,
                                              const ChannelSP& channel) const;
  /**
   * @brief Finds the isolated gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return DotGatesSP list of all gates of the gatetype that are isolated in
   * the selected channel.
   */
  DotGatesSP<DotGate> get_isolated_channel_gates(
      const DotGateSP& type, const ChannelSP& channel) const;
  /**
   * @brief Finds the isolated gates of the gatetype in the selected channel.
   * @param type The particular gatetype of interest.
   * @param channel The channel of the device of interest.
   * @return GatesSP<Gate> list of all gates of the gatetype that are isolated
   * in the selected channel.
   */
  GatesSP<Gate> get_isolated_channel_gates(const GateSP&    type,
                                           const ChannelSP& channel) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel which are
   * unshared.
   * @param type The type of gate we want.
   * @return A map from ChannelSP to BarrierGatesSP containing the type of gate
   * we want indexed by channel.
   */
  generic::MapSP<Channel, BarrierGates> get_isolated_gates_by_type(
      const BarrierGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel which are
   * unshared.
   * @param type The type of gate we want.
   * @return A map from ChannelSP to PlungerGatesSP containing the type of gate
   * we want indexed by channel.
   */
  generic::MapSP<Channel, PlungerGates> get_isolated_gates_by_type(
      const PlungerGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel which are
   * unshared.
   * @param type The type of gate we want.
   * @return A map from ChannelSP to ReservoirGatesSP containing the type of
   * gate we want indexed by channel.
   */
  generic::MapSP<Channel, ReservoirGates> get_isolated_gates_by_type(
      const ReservoirGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel which are
   * unshared.
   * @param type The type of gate we want.
   * @return A map from ChannelSP to ScreeningGatesSP containing the type of
   * gate we want indexed by channel.
   */
  generic::MapSP<Channel, ScreeningGates> get_isolated_gates_by_type(
      const ScreeningGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel which are
   * unshared.
   * @param type The type of gate we want.
   * @return A map from ChannelSP to DotGatesSP containing the type of gate we
   * want indexed by channel.
   */
  generic::MapSP<Channel, DotGates<DotGate>> get_isolated_gates_by_type(
      const DotGateSP& type) const;
  /**
   * @brief Returns gates of a certain gatetype indexed by channel which are
   * unshared.
   * @param type The type of gate we want.
   * @return A map from ChannelSP to GatesSP<Gate> containing the type of gate
   * we want indexed by channel.
   */
  generic::MapSP<Channel, Gates<Gate>> get_isolated_gates_by_type(
      const GateSP& type) const;

  /**
   * @brief Returns the gate relations in the config.
   * @return GateRelationsSP representing the gate relations.
   */
  GateRelationsSP generate_gate_relations() const;
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
