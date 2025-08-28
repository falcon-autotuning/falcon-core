#pragma once

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace core {
/**
 * @brief Elements of the config that pertain to an individual group of gates.
 */
class Group : public StandardConfigConnections {
  autotuner_interfaces::names::ChannelSP _name;
  int                                    _num_dots;
  GateGeometryArray1DSP                  _order;
  OhmicsSP                               _ohmics;

 public:
  /**
   * @brief Holds information about a group of gates.
   * @param name The name of the group.
   * @param num_dots The number of dots in the group.
   * @param screening_gates The screening gates in the group.
   * @param reservoir_gates The reservoir gates in the group.
   * @param plunger_gates The plunger gates in the group.
   * @param barrier_gates The barrier gates in the group.
   * @param order The order of the gates in the group.
   */
  Group(const ChannelSP&         name,
        const int&               num_dots,
        const ScreeningGatesSP&  screening_gates,
        const ReservoirGatesSP&  reservoir_gates,
        const PlungerGatesSP&    plunger_gates,
        const BarrierGatesSP&    barrier_gates,
        const BaseConnectionsSP& order);
  /**
   * @brief collect the ohmics pertaining to this group.
   */
  OhmicsSP ohmics() const;
  /**
   * @brief collect the name of this group.
   */
  ChannelSP name() const;
  /**
   * @brief collect the number of dots in this group.
   */
  int num_dots() const;
  /**
   * @brief collect the order of the gates in this group.
   */
  GateGeometryArray1DSP order() const;
  /**
   * @brief Validates if this channel is present.
   * @param channel The channel to validate.
   * @returns true if the channel is present.
   */
  bool has_channel(const ChannelSP& channel) const;
  /**
   * @brief Checks if this channel could be a charge sensor.
   * @returns true if the channel has a single dot.
   */
  bool is_charge_sensor() const;
  /**
   * @brief Gets all of the gates assocciated with this channel from the config.
   * @param channel The channel to collect the gates for.
   * @returns The gates associated with this channel. If the channel is not
   * correct then empty gates are returned.
   */
  GatesSP get_all_channel_gates(const ChannelSP& channel) const;
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  Group();
  friend class cereal::access;
};
using GroupSP = std::shared_ptr<Group>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
