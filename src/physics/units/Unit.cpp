#include "falcon_core/physics/units/Unit.hpp"

#include <cmath>

#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"
namespace falcon_core {
namespace physics {
namespace units {
Unit::Unit(TotalDimensions dimensions,
           double          scale_factor,
           double          offset,
           std::string     prefix)
    : _scale_factor(scale_factor),
      _dimensions(dimensions),
      _offset(offset),
      _prefix(prefix) {}

UnitSP Unit::operator*(const UnitSP &other) const {
  TotalDimensions result_dims = this->_dimensions;
  for (auto it = other->_dimensions.begin(); it != other->_dimensions.end();
       ++it) {
    const std::string &dim = it->first;
    int                exp = it->second;
    result_dims[dim] += exp;
  }
  Unit::clean_dimensions(result_dims);
  return std::make_shared<Unit>(result_dims,
                                this->_scale_factor * other->_scale_factor,
                                this->_offset + other->_offset,
                                this->_prefix);
}
void Unit::clean_dimensions(TotalDimensions &dims) {
  for (auto it = dims.begin(); it != dims.end();) {
    if (it->second == 0) {
      it = dims.erase(it);
    } else {
      ++it;
    }
  }
}

/**
 * @brief The prefix applied to this unit.
 */
std::string Unit::prefix() const { return this->_prefix; }
/**
 * @brief Dimensions of this unit.
 */
TotalDimensions Unit::dimensions() const { return this->_dimensions; }
/**
 * @brief Scale factor relatice to SI base units.
 */
double Unit::scale_factor() const { return this->_scale_factor; }
/**
 * @brief Offset from base unit.
 */
double Unit::offset() const { return this->_offset; }

UnitSP Unit::operator/(const UnitSP &other) const {
  TotalDimensions result_dims = this->_dimensions;
  for (auto it = other->_dimensions.begin(); it != other->_dimensions.end();
       ++it) {
    const std::string &dim = it->first;
    int                exp = it->second;
    result_dims[dim] -= exp;
  }
  Unit::clean_dimensions(result_dims);
  return std::make_shared<Unit>(result_dims,
                                this->_scale_factor / other->_scale_factor,
                                this->_offset - other->_offset,
                                this->_prefix);
}

std::shared_ptr<Unit> Unit::operator^(const int power) const {
  TotalDimensions result_dims = this->_dimensions;
  for (auto it = result_dims.begin(); it != result_dims.end(); ++it) {
    it->second *= power;
  }
  Unit::clean_dimensions(result_dims);
  return std::make_shared<Unit>(result_dims,
                                std::pow(this->_scale_factor, power),
                                this->_offset * power,
                                this->_prefix);
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
template <class Archive>
void Unit::serialize(Archive &ar) {
  ar(cereal::base_class<Song>(this),
     _scale_factor,
     _offset,
     _prefix,
     _dimensions);
}
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::units::Unit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::Unit)
