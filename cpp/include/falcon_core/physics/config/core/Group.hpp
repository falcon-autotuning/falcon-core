#pragma once

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
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
  geometries::GateGeometryArray1DSP      _order;
  mutable std::shared_timed_mutex        _mu_name;
  mutable std::shared_timed_mutex        _mu_num_dots;
  mutable std::shared_timed_mutex        _mu_order;

 public:
  Group(const Group& other);
  Group& operator=(const Group& other);
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
  Group(const autotuner_interfaces::names::ChannelSP& name,
        const int&                                    num_dots,
        const device_structures::ConnectionsSP&       screening_gates,
        const device_structures::ConnectionsSP&       reservoir_gates,
        const device_structures::ConnectionsSP&       plunger_gates,
        const device_structures::ConnectionsSP&       barrier_gates,
        const device_structures::ConnectionsSP&       order);
  /**
   * @brief collect the ohmics pertaining to this group.
   */
  const device_structures::ConnectionsSP ohmics() const;
  /**
   * @brief collect the name of this group.
   */
  const autotuner_interfaces::names::ChannelSP& name() const;
  /**
   * @brief collect the number of dots in this group.
   */
  const int& num_dots() const;
  /**
   * @brief collect the order of the gates in this group.
   */
  const geometries::GateGeometryArray1DSP& order() const;
  /**
   * @brief Validates if this channel is present.
   * @param channel The channel to validate.
   * @returns true if the channel is present.
   */
  bool has_channel(const autotuner_interfaces::names::ChannelSP& channel) const;
  /**
   * @brief Checks if this channel could be a charge sensor.
   * @returns true if the channel has a single dot.
   */
  bool is_charge_sensor() const;
  /**
   * @brief Gets all of the gates assocciated with this channel from the
   * config.
   * @param channel The channel to collect the gates for.
   * @returns The gates associated with this channel. If the channel is not
   * correct then empty gates are returned.
   */
  device_structures::ConnectionsSP get_all_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;

  bool operator==(const Group& other) const;
  bool operator!=(const Group& other) const;

 protected:
  Group();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_num_dots(_mu_num_dots,
                                                            std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_order(_mu_order,
                                                         std::defer_lock);
    std::lock(lock_name, lock_num_dots, lock_order);
    ar(cereal::base_class<StandardConfigConnections>(this),
       _name,
       _num_dots,
       _order);
  }
};
using GroupSP = std::shared_ptr<Group>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
