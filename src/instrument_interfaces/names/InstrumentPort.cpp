#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/instrument_interfaces/InstrumentTypes.hpp"

namespace falcon_core::instrument_interfaces::names {

InstrumentPort::InstrumentPort(
    std::string                                             default_name,
    std::shared_ptr<physics::device_structures::Connection> pseudo_name,
    Instrument                                              instrument_type,
    std::shared_ptr<physics::units::SymbolUnit>             units,
    std::string                                             description)
    : _default_name(std::move(default_name)),
      _pseudo_name(std::move(pseudo_name)),
      _instrument_type(std::move(instrument_type)),
      _units(std::move(units)),
      _description(std::move(description)) {}

InstrumentPort::InstrumentPort()
    : _default_name(""),
      _pseudo_name(nullptr),
      _instrument_type(falcon_core::instrument_interfaces::InstrumentTypes::
                           DC_VOLTAGE_SOURCE),
      _units(physics::units::SymbolUnit::Volt()),
      _description("") {}

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

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::InstrumentPort)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::InstrumentPort)
