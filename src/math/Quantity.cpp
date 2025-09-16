#include "falcon_core/math/Quantity.hpp"

#include <cmath>

namespace falcon_core::math {

Quantity::Quantity(double value, physics::units::SymbolUnitSP unit)
    : _value(value), _unit(std::move(unit)) {}

double                       Quantity::value() const { return _value; }
physics::units::SymbolUnitSP Quantity::unit() { return _unit; }

void Quantity::convert_to(physics::units::SymbolUnitSP target_unit) {
  _value = _unit->convert_value_to(_value, target_unit);
  _unit  = target_unit;
}

QuantitySP Quantity::operator*(const int& other) const {
  return std::make_shared<Quantity>(_value * other, _unit);
}
QuantitySP Quantity::operator*(const double& other) const {
  return std::make_shared<Quantity>(_value * other, _unit);
}
QuantitySP Quantity::operator*(const QuantitySP& other) const {
  return std::make_shared<Quantity>(_value * other->value(),
                                    *_unit * other->unit());
}
Quantity& Quantity::operator*=(const int& other) {
  _value *= other;
  return *this;
}
Quantity& Quantity::operator*=(const double& other) {
  _value *= other;
  return *this;
}
Quantity& Quantity::operator*=(const QuantitySP& other) {
  convert_to(other->unit());
  _value *= other->value();
  return *this;
}

QuantitySP Quantity::operator/(const int& other) const {
  return std::make_shared<Quantity>(_value / other, _unit);
}
QuantitySP Quantity::operator/(const double& other) const {
  return std::make_shared<Quantity>(_value / other, _unit);
}
QuantitySP Quantity::operator/(const QuantitySP& other) const {
  return std::make_shared<Quantity>(_value / other->value(),
                                    *_unit / other->unit());
}
Quantity& Quantity::operator/=(const int& other) {
  _value /= other;
  return *this;
}
Quantity& Quantity::operator/=(const double& other) {
  _value /= other;
  return *this;
}
Quantity& Quantity::operator/=(const QuantitySP& other) {
  convert_to(other->unit());
  _value /= other->value();
  return *this;
}

QuantitySP Quantity::operator^(const int& other) const {
  return std::make_shared<Quantity>(std::pow(_value, other), *_unit ^ other);
}

QuantitySP Quantity::operator+(const int& other) const {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
QuantitySP Quantity::operator+(const double& other) const {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
QuantitySP Quantity::operator+(const QuantitySP& other) const {
  if (!_unit->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for addition.");
  }
  double other_val_converted =
      other->unit()->convert_value_to(other->value(), _unit);
  return std::make_shared<Quantity>(_value + other_val_converted, _unit);
}
Quantity& Quantity::operator+=(const int& other) {
  _value += other;
  return *this;
}
Quantity& Quantity::operator+=(const double& other) {
  _value += other;
  return *this;
}
Quantity& Quantity::operator+=(const QuantitySP& other) {
  convert_to(other->unit());
  _value += other->value();
  return *this;
}

QuantitySP Quantity::operator-() const {
  return std::make_shared<Quantity>(-_value, _unit);
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
  if (!_unit->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for subtraction.");
  }
  double other_val_converted =
      other->unit()->convert_value_to(other->value(), _unit);
  return std::make_shared<Quantity>(_value - other_val_converted, _unit);
}
Quantity& Quantity::operator-=(const int& other) {
  _value -= other;
  return *this;
}
Quantity& Quantity::operator-=(const double& other) {
  _value -= other;
  return *this;
}
Quantity& Quantity::operator-=(const QuantitySP& other) {
  convert_to(other->unit());
  _value -= other->value();
  return *this;
}

QuantitySP Quantity::abs() const {
  return std::make_shared<Quantity>(std::abs(_value), _unit);
}

Quantity::Quantity() = default;

}  // namespace falcon_core::math

// Cereal registration
CEREAL_REGISTER_TYPE(falcon_core::math::Quantity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Quantity)
