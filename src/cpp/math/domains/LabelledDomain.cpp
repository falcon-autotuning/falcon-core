#include "falcon-core/math/domains/LabelledDomain.hpp"

#include <stdexcept>

#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace domains {
LabelledDomain::LabelledDomain(const LabelledDomain &other) : Domain(other) {
  std::unique_lock<std::shared_timed_mutex> lock_port(_mu_port);
  if (!other._port) {
    throw std::invalid_argument(
        "LabelledDomain copy constructor: Other LabelledDomain contains "
        "null shared pointer.");
  }
  _port = std::make_shared<instrument_interfaces::names::InstrumentPort>(
      *other._port);
}
LabelledDomain &LabelledDomain::operator=(const LabelledDomain &other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_port(_mu_port);
    if (!other._port) {
      throw std::invalid_argument(
          "LabelledDomain copy constructor: Other LabelledDomain contains "
          "null shared pointer.");
    }
    _port = std::make_shared<instrument_interfaces::names::InstrumentPort>(
        *other._port);
    Domain::operator=(other);
  }
  return *this;
}
LabelledDomain::LabelledDomain() = default;
LabelledDomain::LabelledDomain(
    const std::string &default_name, const std::string &instrument_name,
    const instrument_interfaces::names::Scope scope,
    const instrument_interfaces::names::Access access,
    const instrument_interfaces::names::InstrumentCharacteristic characteristic,
    const std::pair<double, double> &bounds,
    const instrument_interfaces::names::PortType type,
    const physics::units::SymbolUnitSP &units, const std::string &description,
    const physics::device_structures::ConnectionSP &psuedo_name,
    const instrument_interfaces::names::Instrument &instrument_type,
    bool lesser_bound_contained, bool greater_bound_contained)
    : Domain(bounds, lesser_bound_contained, greater_bound_contained),
      _port(std::make_shared<instrument_interfaces::names::InstrumentPort>(
          default_name, instrument_name, scope, access, characteristic, type,
          psuedo_name, instrument_type, units, description)) {
  if (!units) {
    throw std::invalid_argument("LabelledDomain: The units must not be null.");
  }
}
const std::shared_ptr<LabelledDomain> LabelledDomain::from_port(
    const std::pair<double, double> &bounds,
    const instrument_interfaces::names::InstrumentPortSP &port,
    const bool &lesser_bound_contained, const bool &greater_bound_contained) {
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain: The instrument port must not be null.");
  }
  if (port->instrument_facing_name() == ToString(port->instrument_type())) {
    return std::make_shared<LabelledDomain>(
        port->default_name(), port->instrument_name(), port->scope(),
        port->access(), port->characteristic(), bounds, port->type(),
        port->units(), port->description(), nullptr, port->instrument_type(),
        lesser_bound_contained, greater_bound_contained);
  }
  return std::make_shared<LabelledDomain>(
      port->default_name(), port->instrument_name(), port->scope(),
      port->access(), port->characteristic(), bounds, port->type(),
      port->units(), port->description(), port->pseudo_name(),
      port->instrument_type(), lesser_bound_contained, greater_bound_contained);
}

const std::shared_ptr<LabelledDomain> LabelledDomain::from_port_and_domain(
    const instrument_interfaces::names::InstrumentPortSP &port,
    const DomainSP &domain) {
  if (!port || !domain) {
    throw std::invalid_argument(
        "LabelledDomain: The instrument port and domain must not be null.");
  }
  return std::make_shared<LabelledDomain>(
      port->default_name(), port->instrument_name(), port->scope(),
      port->access(), port->characteristic(), domain->bounds(), port->type(),
      port->units(), port->description(), port->pseudo_name(),
      port->instrument_type(), domain->lesser_bound_contained(),
      domain->greater_bound_contained());
}
const std::shared_ptr<LabelledDomain> LabelledDomain::from_domain(
    const DomainSP &domain, const std::string &default_name,
    const std::string &instrument_name,
    const instrument_interfaces::names::Scope scope,
    const instrument_interfaces::names::Access access,
    const instrument_interfaces::names::InstrumentCharacteristic characteristic,
    const instrument_interfaces::names::PortType type,
    const physics::units::SymbolUnitSP &units, const std::string &description,
    const physics::device_structures::ConnectionSP &pseudo_name,
    const instrument_interfaces::names::Instrument &instrument_type) {
  if (!domain) {
    throw std::invalid_argument("LabelledDomain: The domain must not be null.");
  }
  return std::make_shared<LabelledDomain>(
      default_name, instrument_name, scope, access, characteristic,
      domain->bounds(), type, units, description, pseudo_name, instrument_type,
      domain->lesser_bound_contained(), domain->greater_bound_contained());
}
const instrument_interfaces::names::InstrumentPortSP &
LabelledDomain::port() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_port);
  return _port;
}
std::shared_ptr<Domain> LabelledDomain::domain() const {
  return std::make_shared<Domain>(this->lesser_bound(), this->greater_bound(),
                                  this->lesser_bound_contained(),
                                  this->greater_bound_contained());
}
bool LabelledDomain::matching_port(
    const instrument_interfaces::names::InstrumentPortSP &port) const {
  if (!port) {
    throw std::invalid_argument("LabelledDomain: The port must not be null.");
  }
  return this->port() && *this->port() == *port;
}
bool LabelledDomain::operator==(const LabelledDomain &other) const {
  if (this == &other)
    return true;
  return *this->domain() == *other.domain() &&
         *(this->port()) == *(other.port());
}
bool LabelledDomain::operator!=(const LabelledDomain &other) const {
  return !(*this == other);
}
} // namespace domains
} // namespace math
} // namespace falcon_core
