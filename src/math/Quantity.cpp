#include "falcon_core/math/Quantity.hpp"

#include <cmath>
#include <stdexcept>
#include <cereal/types/polymorphic.hpp>
#include "falcon_core/generic/Song.hpp"

CEREAL_REGISTER_TYPE(falcon_core::math::Quantity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::Quantity)

namespace falcon_core {
namespace math {

void Quantity::convert_to(
    std::shared_ptr<physics::units::SymbolUnit> target_unit) {
  _value = _unit->convert_value_to(_value, target_unit);
  _unit  = target_unit;
}

std::shared_ptr<Quantity> Quantity::operator*(int other) const {
  return std::make_shared<Quantity>(_value * other, _unit);
}
std::shared_ptr<Quantity> Quantity::operator*(double other) const {
  return std::make_shared<Quantity>(_value * other, _unit);
}
std::shared_ptr<Quantity> Quantity::operator*(
    std::shared_ptr<Quantity> other) const {
  return std::make_shared<Quantity>(_value * other->value(),
                                     *_unit * other->unit());
}

std::shared_ptr<Quantity> Quantity::operator/(int other) const {
  return std::make_shared<Quantity>(_value / other, _unit);
}
std::shared_ptr<Quantity> Quantity::operator/(double other) const {
  return std::make_shared<Quantity>(_value / other, _unit);
}
std::shared_ptr<Quantity> Quantity::operator/(
    std::shared_ptr<Quantity> other) const {
  return std::make_shared<Quantity>(_value / other->value(),
                                     *_unit / other->unit());
}

std::shared_ptr<Quantity> Quantity::operator^(int other) const {
  return std::make_shared<Quantity>(std::pow(_value, other), *_unit ^ other);
}

std::shared_ptr<Quantity> Quantity::operator+(int other) const {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
std::shared_ptr<Quantity> Quantity::operator+(double other) const {
  throw std::runtime_error("Cannot add a scalar to a quantity with units.");
}
std::shared_ptr<Quantity> Quantity::operator+(
    std::shared_ptr<Quantity> other) const {
  if (!_unit->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for addition.");
  }
  double other_val_converted =
      other->unit()->convert_value_to(other->value(), _unit);
  return std::make_shared<Quantity>(_value + other_val_converted, _unit);
}

std::shared_ptr<Quantity> Quantity::operator-() const {
  return std::make_shared<Quantity>(-_value, _unit);
}

std::shared_ptr<Quantity> Quantity::operator-(int other) const {
  throw std::runtime_error(
      "Cannot subtract a scalar from a quantity with units.");
}
std::shared_ptr<Quantity> Quantity::operator-(double other) const {
  throw std::runtime_error(
      "Cannot subtract a scalar from a quantity with units.");
}
std::shared_ptr<Quantity> Quantity::operator-(
    std::shared_ptr<Quantity> other) const {
  if (!_unit->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for subtraction.");
  }
  double other_val_converted =
      other->unit()->convert_value_to(other->value(), _unit);
  return std::make_shared<Quantity>(_value - other_val_converted, _unit);
}

std::shared_ptr<Quantity> Quantity::abs() const {
  return std::make_shared<Quantity>(std::abs(_value), _unit);
}

}  // namespace math
}  // namespace falcon_core
