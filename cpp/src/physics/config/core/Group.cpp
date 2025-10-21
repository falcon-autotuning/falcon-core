#include "falcon_core/physics/config/core/Group.hpp"

#include <stdexcept>

#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Group::Group() = default;
Group::Group(const autotuner_interfaces::names::ChannelSP& name,
             const int&                                    num_dots,
             const device_structures::ConnectionsSP&       screening_gates,
             const device_structures::ConnectionsSP&       reservoir_gates,
             const device_structures::ConnectionsSP&       plunger_gates,
             const device_structures::ConnectionsSP&       barrier_gates,
             const device_structures::ConnectionsSP&       order)
    : StandardConfigConnections(
          screening_gates,
          reservoir_gates,
          plunger_gates,
          barrier_gates,
          std::make_shared<device_structures::Connections>()),
      _name(name),
      _num_dots(num_dots),
      _order(std::make_shared<geometries::GateGeometryArray1D>(
          order, screening_gates)) {
  if (!name) {
    throw std::invalid_argument("Group: the channel must not be null.");
  }
}
const device_structures::ConnectionsSP Group::ohmics() const {
  return _order->ohmics();
}
const autotuner_interfaces::names::ChannelSP& Group::name() const {
  return _name;
}
const int& Group::num_dots() const { return _num_dots; }
const geometries::GateGeometryArray1DSP& Group::order() const { return _order; }
bool                                     Group::has_channel(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Group: The channel must not be null.");
  }
  return *this->_name == *channel;
}
bool Group::is_charge_sensor() const { return this->_num_dots == 1; }
device_structures::ConnectionsSP Group::get_all_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (has_channel(channel)) {
    return get_all_gates();
  }
  return std::make_shared<device_structures::Connections>();
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Group)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::core::StandardConfigConnections,
    falcon_core::physics::config::core::Group)
