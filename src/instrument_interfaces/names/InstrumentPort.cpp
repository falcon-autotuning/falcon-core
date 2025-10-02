#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

#include <stdexcept>

#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"

namespace falcon_core::instrument_interfaces::names {

InstrumentPort::InstrumentPort(
    const std::string&                              default_name,
    const physics::device_structures::ConnectionSP& pseudo_name,
    const Instrument&                               instrument_type,
    const physics::units::SymbolUnitSP&             units,
    const std::string&                              description,
    const PortType&                                 type)
    : _default_name(default_name),
      _pseudo_name(pseudo_name),
      _instrument_type(instrument_type),
      _units(units),
      _description(description),
      _type(type) {
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort: The units needs to not be null.");
  }
}
std::shared_ptr<InstrumentPort> InstrumentPort::Knob(
    const std::string&                              default_name,
    const physics::device_structures::ConnectionSP& pseudo_name,
    const Instrument&                               instrument_type,
    const physics::units::SymbolUnitSP              units,
    const std::string&                              description) {
  if (!pseudo_name) {
    throw std::invalid_argument(
        "InstrumentPort: The pseudo_name needs to not be null.");
  }
  return std::make_shared<InstrumentPort>(default_name,
                                          pseudo_name,
                                          instrument_type,
                                          units,
                                          description,
                                          PortType::Knob);
}
std::shared_ptr<InstrumentPort> InstrumentPort::Meter(
    const std::string&                              default_name,
    const physics::device_structures::ConnectionSP& pseudo_name,
    const Instrument&                               instrument_type,
    const physics::units::SymbolUnitSP              units,
    const std::string&                              description) {
  if (!pseudo_name) {
    throw std::invalid_argument(
        "InstrumentPort: The pseudo_name needs to not be null.");
  }
  return std::make_shared<InstrumentPort>(default_name,
                                          pseudo_name,
                                          instrument_type,
                                          units,
                                          description,
                                          PortType::Meter);
}
std::shared_ptr<InstrumentPort> InstrumentPort::Timer() {
  return std::make_shared<InstrumentPort>(
      INSTRUMENT_TYPES::CLOCK,
      nullptr,
      INSTRUMENT_TYPES::CLOCK,
      physics::units::SymbolUnit::Second(),
      "A time clock used for measurment aquisition and synchronization");
}
std::shared_ptr<InstrumentPort> InstrumentPort::ExecutionClock() {
  return std::make_shared<InstrumentPort>(
      INSTRUMENT_TYPES::CLOCK,
      nullptr,
      INSTRUMENT_TYPES::CLOCK,
      physics::units::SymbolUnit::Second(),
      "A time clock to show time traces after execution");
}

InstrumentPort::InstrumentPort()
    : _default_name(""),
      _pseudo_name(nullptr),
      _instrument_type(InstrumentTypes::DC_VOLTAGE_SOURCE),
      _units(physics::units::SymbolUnit::Volt()),
      _description(""),
      _type(PortType::InstrumentPort) {}

const std::string InstrumentPort::default_name() const { return _default_name; }
const std::shared_ptr<physics::device_structures::Connection>
InstrumentPort::pseudo_name() const {
  if (!_pseudo_name) {
    throw std::runtime_error("The pseudo_name of the port is not set");
  }
  return _pseudo_name;
}
const Instrument InstrumentPort::instrument_type() const {
  return _instrument_type;
}
const std::shared_ptr<physics::units::SymbolUnit> InstrumentPort::units()
    const {
  return _units;
}
const std::string InstrumentPort::description() const { return _description; }
const std::string InstrumentPort::instrument_facing_name() const {
  if (_pseudo_name) {
    return pseudo_name()->name();
  } else {
    return instrument_type();
  }
}
const bool InstrumentPort::is_knob() const { return _type == PortType::Knob; }
const bool InstrumentPort::is_meter() const { return _type == PortType::Meter; }
const bool InstrumentPort::is_port() const {
  return _type == PortType::InstrumentPort;
}
bool InstrumentPort::operator==(const InstrumentPort& other) const {
  return (default_name() == other.default_name()) &&
         (instrument_type() == other.instrument_type()) &&
         (*units() == *other.units()) &&
         (description() == other.description()) && (_type == other._type) &&
         (instrument_facing_name() == other.instrument_facing_name());
}
bool InstrumentPort::operator!=(const InstrumentPort& other) const {
  return !(*this == other);
}
const PortType InstrumentPort::type() const { return _type; }

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::InstrumentPort)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::InstrumentPort)
