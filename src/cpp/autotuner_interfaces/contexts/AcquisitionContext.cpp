#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"

#include <stdexcept>

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
AcquisitionContext::AcquisitionContext(const AcquisitionContext& other)
    : BaseContext(other) {
  std::unique_lock<std::shared_timed_mutex> lock_units(_mu_units,
                                                       std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_other_units(other._mu_units,
                                                             std::defer_lock);
  std::lock(lock_units, lock_other_units);
  if (!other._units) {
    throw std::invalid_argument(
        "AcquisitionContext copy constructor: Other AcquisitionContext "
        "contains null shared pointer.");
  }
  _units = std::make_shared<physics::units::SymbolUnit>(*other._units);
}
AcquisitionContext& AcquisitionContext::operator=(
    const AcquisitionContext& other) {
  if (this != &other) {
    BaseContext::operator=(other);
    std::unique_lock<std::shared_timed_mutex> lock_units(_mu_units,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_units(other._mu_units,
                                                               std::defer_lock);
    std::lock(lock_units, lock_other_units);
    if (!other._units) {
      throw std::invalid_argument(
          "AcquisitionContext copy constructor: Other AcquisitionContext "
          "contains null shared pointer.");
    }
    _units = std::make_shared<physics::units::SymbolUnit>(*other._units);
  }
  return *this;
}
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
    : BaseContext(port), _units(port->units()) {}

AcquisitionContextSP AcquisitionContext::from_context(
    const BaseContextSP&                measurement_context,
    const physics::units::SymbolUnitSP& unit) {
  if (!measurement_context) {
    throw std::invalid_argument(
        "AcquisitionContext: The measurement_context must not be null.");
  }
  return std::make_shared<AcquisitionContext>(
      measurement_context->connection(),
      measurement_context->instrument_type(),
      unit);
}

const physics::units::SymbolUnitSP AcquisitionContext::units() const {
  std::shared_lock<std::shared_timed_mutex> lock_u(_mu_units);
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

bool AcquisitionContext::operator==(const AcquisitionContext& other) const {
  if (this == &other) return true;
  return BaseContext::operator==(other) && *units() == *(other.units());
}

bool AcquisitionContext::operator!=(const AcquisitionContext& other) const {
  return !(*this == other);
}

}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
