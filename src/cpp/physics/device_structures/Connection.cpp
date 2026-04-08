#include "falcon-core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
Connection::Connection(const Connection& other) {
  std::shared_lock<std::shared_timed_mutex> lock_other_type(other._mu_type);
  _name = other.name();
  _type = other._type;
}
Connection& Connection::operator=(const Connection& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_type(other._mu_type,
                                                              std::defer_lock);
    std::lock(lock_name, lock_type, lock_other_type);
    _name = other.name();
    _type = other._type;
  }
  return *this;
}
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
const std::string Connection::name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_name);
  return _name;
}
const std::string Connection::type() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return DeviceFeatureNames.at(_type);
}
bool Connection::is_dot_gate() const {
  return is_barrier_gate() || is_plunger_gate();
}
bool Connection::is_barrier_gate() const {
  return type() == DeviceFeatureNames.at(DeviceFeature::BarrierGate);
}
bool Connection::is_plunger_gate() const {
  return type() == DeviceFeatureNames.at(DeviceFeature::PlungerGate);
}
bool Connection::is_reservoir_gate() const {
  return type() == DeviceFeatureNames.at(DeviceFeature::ReservoirGate);
}
bool Connection::is_screening_gate() const {
  return type() == DeviceFeatureNames.at(DeviceFeature::ScreeningGate);
}
bool Connection::is_ohmic() const {
  return type() == DeviceFeatureNames.at(DeviceFeature::Ohmic);
}
bool Connection::is_gate() const { return !is_ohmic(); }
bool Connection::operator<(const Connection& other) const {
  return name() < other.name();  // Compare based on name
}
bool Connection::operator==(const Connection& other) const {
  if (this == &other) return true;
  return (name() == other.name()) && (type() == other.type());
}
bool Connection::operator!=(const Connection& other) const {
  return !(*this == other);
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
