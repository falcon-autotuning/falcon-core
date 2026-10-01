#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"

#include <stdexcept>

namespace falcon_core {
namespace instrument_interfaces {
namespace names {
InstrumentPort::InstrumentPort(const InstrumentPort &other)
    : generic::Song(other) {
  std::shared_lock<std::shared_timed_mutex> lock_default_name(_mu_default_name,
                                                              std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_pseudo_name(_mu_pseudo_name,
                                                             std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_instrument_type(
      _mu_instrument_type, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_units(_mu_units,
                                                       std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_description(_mu_description,
                                                             std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                      std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_instrument_name(
      _mu_instrument_name, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_scope(_mu_scope,
                                                       std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_access(_mu_access,
                                                        std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_characteristic_name(
      _mu_characteristic_name, std::defer_lock);
  std::lock(lock_default_name, lock_pseudo_name, lock_instrument_type,
            lock_units, lock_description, lock_type, lock_instrument_name,
            lock_scope, lock_access, lock_characteristic_name);
  if (!other.units()) {
    throw std::invalid_argument(
        "InstrumentPort copy constructor: Other InstrumentPort contains null "
        "shared pointer for units.");
  }
  _default_name = other.default_name();
  _instrument_name = other.instrument_name();
  _instrument_type = other.instrument_type();
  _units = std::make_shared<physics::units::SymbolUnit>(*other.units());
  _description = other.description();
  _type = other.type();
  _scope = other.scope();
  _access = other.access();
  _characteristic_name = other.characteristic();
  if (other._pseudo_name) {
    _pseudo_name = std::make_shared<physics::device_structures::Connection>(
        *other.pseudo_name());
  } else {
    _pseudo_name = nullptr;
  }
}
InstrumentPort &InstrumentPort::operator=(const InstrumentPort &other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_default_name(
        _mu_default_name, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_pseudo_name(_mu_pseudo_name,
                                                               std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_instrument_type(
        _mu_instrument_type, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_units(_mu_units,
                                                         std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_description(_mu_description,
                                                               std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_instrument_name(
        _mu_instrument_name, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_scope(_mu_scope,
                                                         std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_access(_mu_access,
                                                          std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_characteristic_name(
        _mu_characteristic_name, std::defer_lock);
    std::lock(lock_default_name, lock_pseudo_name, lock_instrument_type,
              lock_units, lock_description, lock_type, lock_instrument_name,
              lock_scope, lock_access, lock_characteristic_name);
    if (!other.units()) {
      throw std::invalid_argument(
          "InstrumentPort copy constructor: Other InstrumentPort contains null "
          "shared pointer for units.");
    }
    _default_name = other.default_name();
    _instrument_name = other.instrument_name();
    _instrument_type = other.instrument_type();
    _units = std::make_shared<physics::units::SymbolUnit>(*other.units());
    _description = other.description();
    _type = other.type();
    _scope = other.scope();
    _access = other.access();
    _characteristic_name = other.characteristic();
    if (other.pseudo_name()) {
      _pseudo_name = std::make_shared<physics::device_structures::Connection>(
          *other.pseudo_name());
    } else {
      _pseudo_name = nullptr;
    }
  }
  return *this;
}

InstrumentPort::InstrumentPort(
    const std::string &default_name, const std::string &instrument_name,
    const Scope scope, const Access access,
    const InstrumentCharacteristic characteristic, const PortType type,
    const physics::device_structures::ConnectionSP &pseudo_name,
    const Instrument &instrument_type,
    const physics::units::SymbolUnitSP &units, const std::string &description)
    : _default_name(default_name), _pseudo_name(pseudo_name),
      _instrument_type(instrument_type), _units(units),
      _description(description), _type(type), _instrument_name(instrument_name),
      _scope(scope), _access(access), _characteristic_name(characteristic) {
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort: The units needs to not be null.");
  }
}
std::shared_ptr<InstrumentPort> InstrumentPort::Setting(
    const std::string &default_name, const std::string &instrument_name,
    const Scope scope, const Access access,
    const InstrumentCharacteristic characteristic,
    const physics::device_structures::ConnectionSP &pseudo_name,
    const Instrument &instrument_type,
    const physics::units::SymbolUnitSP &units, const std::string &description) {
  return std::make_shared<InstrumentPort>(
      default_name, instrument_name, scope, access, characteristic,
      PortType::Setting, pseudo_name, instrument_type, units, description);
}
std::shared_ptr<InstrumentPort> InstrumentPort::Knob(
    const std::string &default_name, const std::string &instrument_name,
    const physics::device_structures::ConnectionSP &pseudo_name,
    const Instrument &instrument_type, const physics::units::SymbolUnitSP units,
    const std::string &description) {
  if (!pseudo_name) {
    throw std::invalid_argument(
        "InstrumentPort: The pseudo_name needs to not be null.");
  }
  return std::make_shared<InstrumentPort>(
      default_name, instrument_name, Scope::Local, Access::Write,
      InstrumentCharacteristic::None, PortType::Knob, pseudo_name,
      instrument_type, units, description);
}
std::shared_ptr<InstrumentPort> InstrumentPort::Meter(
    const std::string &default_name, const std::string &instrument_name,
    const physics::device_structures::ConnectionSP &pseudo_name,
    const Instrument &instrument_type, const physics::units::SymbolUnitSP units,
    const std::string &description) {
  if (!pseudo_name) {
    throw std::invalid_argument(
        "InstrumentPort: The pseudo_name needs to not be null.");
  }
  return std::make_shared<InstrumentPort>(
      default_name, instrument_name, Scope::Local, Access::Read,
      InstrumentCharacteristic::None, PortType::Meter, pseudo_name,
      instrument_type, units, description);
}
std::shared_ptr<InstrumentPort> InstrumentPort::Timer() {
  return std::make_shared<InstrumentPort>(
      "Timer", "Timer", Scope::Global, Access::Write,
      InstrumentCharacteristic::None, PortType::Knob, nullptr,
      Instrument::Clock, physics::units::SymbolUnit::Second(),
      "A time clock used for measurment aquisition and synchronization");
}
std::shared_ptr<InstrumentPort> InstrumentPort::ExecutionClock() {
  return std::make_shared<InstrumentPort>(
      "ExecutionClock", "ExecutionClock", Scope::Global, Access::Read,
      InstrumentCharacteristic::None, PortType::Meter, nullptr,
      Instrument::Clock, physics::units::SymbolUnit::Second(),
      "A time clock to show time traces after execution");
}

InstrumentPort::InstrumentPort()
    : _default_name(""), _instrument_name(""), _scope(Scope::Local),
      _access(Access::ReadWrite),
      _characteristic_name(InstrumentCharacteristic::None),
      _type(PortType::Setting), _pseudo_name(nullptr),
      _instrument_type(Instrument::DC_Voltage_Source),
      _units(physics::units::SymbolUnit::Volt()), _description("") {}

const std::string InstrumentPort::default_name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_default_name);
  return _default_name;
}
const std::string InstrumentPort::instrument_name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_instrument_name);
  return _instrument_name;
}
const std::shared_ptr<physics::device_structures::Connection>
InstrumentPort::pseudo_name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_pseudo_name);
  if (!_pseudo_name) {
    throw std::runtime_error("The pseudo_name of the port is not set");
  }
  return _pseudo_name;
}
const Instrument InstrumentPort::instrument_type() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_instrument_type);
  return _instrument_type;
}
const Scope InstrumentPort::scope() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_scope);
  return _scope;
}
const Access InstrumentPort::access() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_access);
  return _access;
}
const InstrumentCharacteristic InstrumentPort::characteristic() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_characteristic_name);
  return _characteristic_name;
}
const std::shared_ptr<physics::units::SymbolUnit>
InstrumentPort::units() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_units);
  return _units;
}
const std::string InstrumentPort::description() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_description);
  return _description;
}
const std::string InstrumentPort::instrument_facing_name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_pseudo_name);
  if (_pseudo_name) {
    return pseudo_name()->name();
  } else {
    return ToString(instrument_type());
  }
}
const bool InstrumentPort::is_knob() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return _type == PortType::Knob;
}
const bool InstrumentPort::is_meter() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return _type == PortType::Meter;
}
const bool InstrumentPort::is_setting() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return _type == PortType::Setting;
}
const PortType InstrumentPort::type() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return _type;
}
bool InstrumentPort::operator==(const InstrumentPort &other) const {
  if (this == &other) {
    return true;
  }
  return (default_name() == other.default_name()) &&
         (instrument_name() == other.instrument_name()) &&
         (scope() == other.scope()) && (access() == other.access()) &&
         (characteristic() == other.characteristic()) &&
         (instrument_type() == other.instrument_type()) &&
         (*units() == *other.units()) &&
         (description() == other.description()) && (type() == other.type()) &&
         (instrument_facing_name() == other.instrument_facing_name());
}
bool InstrumentPort::operator!=(const InstrumentPort &other) const {
  return !(*this == other);
}

} // namespace names
} // namespace instrument_interfaces
} // namespace falcon_core
