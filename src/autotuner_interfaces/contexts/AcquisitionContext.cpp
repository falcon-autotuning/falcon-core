#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"

#include <stdexcept>

namespace falcon_core::autotuner_interfaces::contexts {

AcquisitionContext::AcquisitionContext() : BaseContext(), _units(nullptr) {}

AcquisitionContext::AcquisitionContext(
    const physics::device_structures::ConnectionSP& connection,
    const instrument_interfaces::names::Instrument& instrument_type,
    const physics::units::SymbolUnitSP&             units)
    : BaseContext(connection, instrument_type), _units(units) {
  if (!units) {
    throw std::invalid_argument(
        "AcquisitionContext: The units must not be null.");
  }
}

AcquisitionContext::AcquisitionContext(
    const instrument_interfaces::names::InstrumentPortSP& port)
    : BaseContext(port) {
  if (!port) {
    throw std::invalid_argument(
        "AcquisitionContext: The port must not be null.");
  }
  _units = port->units();
}

AcquisitionContext::AcquisitionContext(const BaseContextSP& measurement_context,
                                       const physics::units::SymbolUnitSP& unit)
    : BaseContext(
          measurement_context ? measurement_context->connection() : nullptr,
          measurement_context ? measurement_context->instrument_type()
                              : instrument_interfaces::names::Instrument{}) {
  if (!measurement_context) {
    throw std::invalid_argument(
        "AcquisitionContext: The measurement_context must not be null.");
  }
  if (!unit) {
    throw std::invalid_argument(
        "AcquisitionContext: The units must not be null.");
  }
  _units = unit;
}

const physics::units::SymbolUnitSP AcquisitionContext::units() const {
  return _units;
}

const AcquisitionContextSP AcquisitionContext::operator/(
    const physics::units::SymbolUnitSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext: The connection to divide by must not be "
        "null.");
  }
  return std::make_shared<AcquisitionContext>(
      connection(), instrument_type(), *units() / other);
}

const AcquisitionContextSP AcquisitionContext::operator/(
    const std::shared_ptr<AcquisitionContext>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext: The connection to divide by must not be "
        "null.");
  }
  return std::make_shared<AcquisitionContext>(
      connection(), instrument_type(), *units() / other->units());
}

const bool AcquisitionContext::match_connection(
    physics::device_structures::ConnectionSP other) const {
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext: The connection to compare against must not be "
        "null.");
  }
  return *connection() == *other;
}

const bool AcquisitionContext::match_instrument_type(
    instrument_interfaces::names::Instrument other) const {
  return instrument_type() == other;
}

}  // namespace falcon_core::autotuner_interfaces::contexts

CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::contexts::BaseContext,
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
