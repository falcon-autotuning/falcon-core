#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
Connection::Connection() : _name(""), _type(DeviceFeature::Ohmic) {}
Connection::Connection(const std::string& name, const DeviceFeature& type)
    : _name(name), _type(type) {}
ConnectionSP Connection::BarrierGate(const std::string& name) {
  return std::make_shared<Connection>(name, DeviceFeature::BarrierGate);
}
ConnectionSP Connection::PlungerGate(const std::string& name) {
  return std::make_shared<Connection>(name, DeviceFeature::PlungerGate);
}
ConnectionSP Connection::ReservoirGate(const std::string& name) {
  return std::make_shared<Connection>(name, DeviceFeature::ReservoirGate);
}
ConnectionSP Connection::ScreeningGate(const std::string& name) {
  return std::make_shared<Connection>(name, DeviceFeature::ScreeningGate);
}
ConnectionSP Connection::Ohmic(const std::string& name) {
  return std::make_shared<Connection>(name, DeviceFeature::Ohmic);
}
const std::string& Connection::name() const { return _name; }
const std::string  Connection::type() const {
  switch (_type) {
    case DeviceFeature::BarrierGate:
      return "BarrierGate";
    case DeviceFeature::PlungerGate:
      return "PlungerGate";
    case DeviceFeature::ReservoirGate:
      return "ReservoirGate";
    case DeviceFeature::ScreeningGate:
      return "ScreeningGate";
    default:  // DeviceFeature::Ohmic
      return "Ohmic";
  }
}
bool Connection::is_dot_gate() const {
  return is_barrier_gate() || is_plunger_gate();
}
bool Connection::is_barrier_gate() const {
  return _type == DeviceFeature::BarrierGate;
}
bool Connection::is_plunger_gate() const {
  return _type == DeviceFeature::PlungerGate;
}
bool Connection::is_reservoir_gate() const {
  return _type == DeviceFeature::ReservoirGate;
}
bool Connection::is_screening_gate() const {
  return _type == DeviceFeature::ScreeningGate;
}
bool Connection::is_ohmic() const { return _type == DeviceFeature::Ohmic; }
bool Connection::is_gate() const { return !is_ohmic(); }
bool Connection::operator<(const Connection& other) const {
  return _name < other._name;  // Compare based on name
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Connection)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::Connection)
