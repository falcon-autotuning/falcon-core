#include "falcon_core/physics/config/core/Group.hpp"

#include "falcon_core/physics/device_structures/BaseConnections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Group::Group() = default;
Group::Group(const ChannelSP&                            name,
             const int&                                  num_dots,
             const device_structures::ScreeningGatesSP&  screening_gates,
             const device_structures::ReservoirGatesSP&  reservoir_gates,
             const device_structures::PlungerGatesSP&    plunger_gates,
             const device_structures::BarrierGatesSP&    barrier_gates,
             const device_structures::BaseConnectionsSP& order)
    : StandardConfigConnections(screening_gates,
                                reservoir_gates,
                                plunger_gates,
                                barrier_gates,
                                std::make_shared<device_structures::Ohmics>()),
      _name(name),
      _num_dots(num_dots),
      _order(std::make_shared<geometries::GateGeometryArray1D>(
          order, screening_gates)) {}
device_structures::OhmicsSP       Group::ohmics() const { return _ohmics; }
ChannelSP                         Group::name() const { return _name; }
int                               Group::num_dots() const { return _num_dots; }
geometries::GateGeometryArray1DSP Group::order() const { return _order; }
bool Group::has_channel(const ChannelSP& channel) const {
  return *this->_name == *channel;
}
bool Group::is_charge_sensor() const { return this->_num_dots == 1; }
device_structures::BaseConnectionsSP Group::get_all_channel_gates(
    const ChannelSP& channel) const {
  if (has_channel(channel)) {
    return get_all_gates();
  }
  return nullptr;
}
template <class Archive>
void Group::serialize(Archive& ar) {
  ar(cereal::base_class<StandardConfigConnections>(this),
     _name,
     _num_dots,
     _order,
     _ohmics);
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Group)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::core::StandardConfigConnections,
    falcon_core::physics::config::core::Group)
