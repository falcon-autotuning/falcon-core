#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
BaseConnection::BaseConnection() : _name("") {}
BaseConnection::BaseConnection(std::string name, DeviceFeature type)
    : _name(name), _type(type) {}
std::string BaseConnection::name() const { return _name; }
std::string BaseConnection::type() const {
  switch (_type) {
    case DeviceFeature::BarrierGate:
      return "BarrierGate";
    case DeviceFeature::PlungerGate:
      return "PlungerGate";
    case DeviceFeature::ReservoirGate:
      return "ReservoirGate";
    case DeviceFeature::ScreeningGate:
      return "ScreeningGate";
    case DeviceFeature::Ohmic:
      return "Ohmic";
    default:
      return "Unknown";
  }
}
bool BaseConnection::is_dot_gate() const {
  return is_barrier_gate() || is_plunger_gate();
}
bool BaseConnection::is_barrier_gate() const {
  return _type == DeviceFeature::BarrierGate;
}
bool BaseConnection::is_plunger_gate() const {
  return _type == DeviceFeature::PlungerGate;
}
bool BaseConnection::is_reservoir_gate() const {
  return _type == DeviceFeature::ReservoirGate;
}
bool BaseConnection::is_screening_gate() const {
  return _type == DeviceFeature::ScreeningGate;
}
bool BaseConnection::is_ohmic() const { return _type == DeviceFeature::Ohmic; }
bool BaseConnection::is_gate() const { return !is_ohmic(); }
bool BaseConnection::operator<(const BaseConnection& other) const {
  return _name < other._name;  // Compare based on name
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BaseConnection)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::BaseConnection)
