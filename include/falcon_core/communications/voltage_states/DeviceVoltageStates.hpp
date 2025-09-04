#pragma once

#include <falcon_core/generic/Song.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon_core/generic/List.hpp>
#include <memory>

namespace falcon_core {
namespace communications {
namespace voltage_states {

class DeviceVoltageStates : public generic::Song {
 public:
  using value_type = DeviceVoltageState;
  using container_type = generic::List<value_type>;

  DeviceVoltageStates();
  DeviceVoltageStates(const container_type& states);

  const container_type& states() const;
  void add_state(const std::shared_ptr<value_type>& state);
  std::shared_ptr<value_type> find_state(
      const std::shared_ptr<physics::device_structures::BaseConnection>& connection) const;

 private:
  container_type _states;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
