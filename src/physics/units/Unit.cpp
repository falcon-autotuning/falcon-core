#include "falcon_core/physics/units/Unit.hpp"

#include <cmath>
#include <stdexcept>
#include <string>

#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"
using namespace falcon_core;
using namespace falcon_core::physics::units;

Unit::Unit(TotalDimensions dimensions,
           double          scale_factor,
           double          offset,
           std::string     prefix)
    : _scale_factor(scale_factor),
      _dimensions(dimensions),
      _offset(offset),
      _prefix(prefix) {}

std::shared_ptr<Unit> Unit::operator*(const UnitSP &other) const {
  TotalDimensions copy_dims = dimensions();
  for (const auto &pair : other->dimensions()) {
    if (copy_dims.count(pair.first)) {
      copy_dims[pair.first] += pair.second;
      if (copy_dims[pair.first] == 0) {
        copy_dims.erase(pair.first);
      }
    } else {
      copy_dims[pair.first] = pair.second;
    }
  }
  double new_scale = scale_factor() * other->scale_factor() +
                     scale_factor() * other->offset() +
                     offset() * other->scale_factor();

  auto result =
      Prefix::prefix_multiplication(prefix(), other->prefix(), new_scale);
  double      &new_mult = result.first;
  std::string &prefix   = result.second;

  return std::make_shared<Unit>(
      copy_dims, new_mult, offset() * other->offset(), prefix);
}

std::shared_ptr<Unit> Unit::operator/(const UnitSP &other) const {
  TotalDimensions copy_dims = dimensions();
  for (const auto &pair : other->dimensions()) {
    if (copy_dims.count(pair.first)) {
      copy_dims[pair.first] -= pair.second;
      if (copy_dims[pair.first] == 0) {
        copy_dims.erase(pair.first);
      }
    } else {
      copy_dims[pair.first] = -pair.second;
    }
  }

  // Create an inverse of `other` to calculate the new scale factor and offset
  Unit inverse_other({},
                     1.0 / other->scale_factor(),
                     -other->offset() / other->scale_factor(),
                     Prefix::get_symbol(-Prefix::get_value(other->prefix())));

  // Now multiply `this` by the `inverse_other` to get the final unit
  // properties
  double new_scale = scale_factor() * inverse_other.scale_factor() +
                     scale_factor() * inverse_other.offset() +
                     offset() * inverse_other.scale_factor();

  auto result = Prefix::prefix_multiplication(
      prefix(), inverse_other.prefix(), new_scale);
  double      &new_mult = result.first;
  std::string &prefix   = result.second;

  return std::make_shared<Unit>(
      copy_dims, new_mult, offset() * inverse_other.offset(), prefix);
}

std::shared_ptr<Unit> Unit::operator^(int power) const {
  TotalDimensions new_dims;
  for (const auto &pair : dimensions()) {
    const std::string &dim_ptr   = pair.first;
    const int         &power_ptr = pair.second;
    new_dims[dim_ptr]            = power_ptr * power;
  }
  double new_scale = std::pow(scale_factor(), power);
  // Assuming _prefix and _offset can be copied directly
  return std::make_shared<Unit>(new_dims, new_scale, offset(), prefix());
}

std::shared_ptr<Unit> Unit::with_prefix(const std::string prefix) const {
  if (!Prefix::is_valid(prefix)) {
    std::ostringstream oss;
    std::copy(std::begin(falcon_core::SI::ALL_PREFIXES),
              std::end(falcon_core::SI::ALL_PREFIXES),
              std::ostream_iterator<std::string>(oss, ", "));
    throw std::invalid_argument("Invalid prefix: " + prefix +
                                ". The valid prefixes are: " + oss.str());
  }
  int    current_prefix_value = Prefix::get_value(this->prefix());
  int    new_prefix_value     = Prefix::get_value(prefix);
  double scale_adjustment =
      pow(10, (double)current_prefix_value - (double)new_prefix_value);
  return std::make_shared<Unit>(
      dimensions(), scale_factor() / scale_adjustment, offset(), prefix);
}

double Unit::convert_value_to(const double  value,
                              const UnitSP &target_unit) const {
  if (dimensions() != target_unit->dimensions()) {
    throw std::invalid_argument(
        "Cannot convert between units with different dimensions.");
  }
  // Convert from source unit to base SI unit
  double base_value = (value + offset()) * scale_factor();

  // Convert from base SI unit to target unit
  return (base_value - target_unit->offset()) / target_unit->scale_factor();
}

bool Unit::is_compatible_with(const UnitSP &other) const {
  return dimensions() == other->dimensions();
}
CEREAL_REGISTER_TYPE(falcon_core::physics::units::Unit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::Unit)
