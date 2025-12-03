#include "falcon_core/math/Quantity.hpp"

#include <cmath>
#include <stdexcept>

namespace falcon_core {
namespace math {
Quantity::Quantity(const Quantity& other) {
  std::shared_lock<std::shared_timed_mutex> lock_other_unit(other._mu_unit,
                                                            std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_other_value(other._mu_value,
                                                             std::defer_lock);
  _value = other._value;
  _unit  = other._unit;
}
Quantity Quantity::operator=(const Quantity& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_unit(other._mu_unit,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_value(other._mu_value,
                                                               std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                        std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value,
                                                         std::defer_lock);
    std::lock(lock_unit, lock_value, lock_other_unit, lock_other_value);
    _value = other._value;
    _unit  = other._unit;
  }
  return *this;
}
Quantity::Quantity(double value, physics::units::SymbolUnitSP unit)
    : _value(value), _unit(unit) {
  if (!unit) {
    throw std::invalid_argument("Quantity: The unit must not be null.");
  }
}

double Quantity::value() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_value);
  return _value;
}
physics::units::SymbolUnitSP Quantity::unit() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_unit);
  return _unit;
}

void Quantity::convert_to(physics::units::SymbolUnitSP target_unit) {
  std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                      std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value,
                                                       std::defer_lock);
  std::lock(lock_unit, lock_value);
  if (!target_unit) {
    throw std::invalid_argument(
        "Quantity: The conversion unit must not be null.");
  }
  _value = _unit->convert_value_to(_value, target_unit);
  _unit  = target_unit;
}

QuantitySP Quantity::operator*(const int& other) const {
  return std::make_shared<Quantity>(value() * other, unit());
}
QuantitySP Quantity::operator*(const double& other) const {
  return std::make_shared<Quantity>(value() * other, unit());
}
QuantitySP Quantity::operator*(const QuantitySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  return std::make_shared<Quantity>(value() * other->value(),
                                    *unit() * other->unit());
}
Quantity& Quantity::operator*=(const int& other) {
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value *= other;
  return *this;
}
Quantity& Quantity::operator*=(const double& other) {
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value *= other;
  return *this;
}
Quantity& Quantity::operator*=(const QuantitySP& other) {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  convert_to(other->unit());
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value *= other->value();
  return *this;
}

QuantitySP Quantity::operator/(const int& other) const {
  return std::make_shared<Quantity>(value() / other, unit());
}
QuantitySP Quantity::operator/(const double& other) const {
  return std::make_shared<Quantity>(value() / other, unit());
}
QuantitySP Quantity::operator/(const QuantitySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  return std::make_shared<Quantity>(value() / other->value(),
                                    *unit() / other->unit());
}
Quantity& Quantity::operator/=(const int& other) {
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value /= other;
  return *this;
}
Quantity& Quantity::operator/=(const double& other) {
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value /= other;
  return *this;
}
Quantity& Quantity::operator/=(const QuantitySP& other) {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  convert_to(other->unit());
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value /= other->value();
  return *this;
}

QuantitySP Quantity::operator^(const int& other) const {
  return std::make_shared<Quantity>(std::pow(value(), other), *unit() ^ other);
}

QuantitySP Quantity::operator+(const int& other) const {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
QuantitySP Quantity::operator+(const double& other) const {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
QuantitySP Quantity::operator+(const QuantitySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  if (!unit()->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for addition.");
  }
  double other_val_converted =
      other->unit()->convert_value_to(other->value(), unit());
  return std::make_shared<Quantity>(value() + other_val_converted, unit());
}
Quantity& Quantity::operator+=(const int& other) {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
Quantity& Quantity::operator+=(const double& other) {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
Quantity& Quantity::operator+=(const QuantitySP& other) {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  convert_to(other->unit());
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value += other->value();
  return *this;
}

QuantitySP Quantity::operator-() const {
  return std::make_shared<Quantity>(-value(), unit());
}

QuantitySP Quantity::operator-(const int& other) const {
  throw std::runtime_error(
      "Cannot subtract a scalar from a quantity with units.");
}
QuantitySP Quantity::operator-(const double& other) const {
  throw std::runtime_error(
      "Cannot subtract a scalar from a quantity with units.");
}
QuantitySP Quantity::operator-(const QuantitySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  if (!unit()->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for subtraction.");
  }
  double other_val_converted =
      other->unit()->convert_value_to(other->value(), unit());
  return std::make_shared<Quantity>(value() - other_val_converted, unit());
}
Quantity& Quantity::operator-=(const int& other) {
  throw std::runtime_error(
      "Cannot subtract a scalar from a quantity with units.");
}
Quantity& Quantity::operator-=(const double& other) {
  throw std::runtime_error(
      "Cannot subtract a scalar from a quantity with units.");
}
Quantity& Quantity::operator-=(const QuantitySP& other) {
  if (!other) {
    throw std::invalid_argument(
        "Quantity: The other quantity must not be null.");
  }
  convert_to(other->unit());
  std::unique_lock<std::shared_timed_mutex> lock_value(_mu_value);
  _value -= other->value();
  return *this;
}

QuantitySP Quantity::abs() const {
  return std::make_shared<Quantity>(std::abs(value()), unit());
}

Quantity::Quantity()
    : _value(0.0), _unit(physics::units::SymbolUnit::Dimensionless()) {}
bool Quantity::operator==(const Quantity& other) const {
  return (value() == other.value()) && (*unit() == *other.unit());
}
bool Quantity::operator!=(const Quantity& other) const {
  return !(*this == other);
}

}  // namespace math
}  // namespace falcon_core

// Cereal registration
CEREAL_REGISTER_TYPE(falcon_core::math::Quantity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Quantity)
