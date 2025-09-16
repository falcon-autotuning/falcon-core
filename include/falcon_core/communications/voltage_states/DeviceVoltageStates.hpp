#pragma once

#include "falcon_core/communications/voltage_states/DeviceVoltageState.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/math/Point.hpp"
namespace falcon_core::communications::voltage_states {

class DeviceVoltageStates : public generic::List<DeviceVoltageState> {
 public:
  DeviceVoltageStates();
  /**
   * @brief Initialize a set of DeviceVoltageStates.
   * @param states all of the states contained within the DeviceVotlageStates.
   */
  DeviceVoltageStates(const generic::ListSP<DeviceVoltageState>& states);
  /**
   * @brief Returns the list of voltage states.
   */
  const generic::ListSP<DeviceVoltageState> states() const;
  /**
   * @brief Add a voltage state to the collection.
   * @param state The voltage state to add.
   */
  void add_state(const DeviceVoltageStateSP& state);
  /**
   * @brief Find a voltage state by its connection.
   * @param connection The connection to find.
   * @returns the voltage state if found.
   */
  const DeviceVoltageStateSP find_state(
      const physics::device_structures::BaseConnectionSP& connection) const;
  /**
   * @brief Conversion to the Point datatype.
   */
  const math::PointSP to_point() const;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this));
  }
};
using DeviceVoltageStatesSP = std::shared_ptr<DeviceVoltageStates>;
}  // namespace falcon_core::communications::voltage_states
