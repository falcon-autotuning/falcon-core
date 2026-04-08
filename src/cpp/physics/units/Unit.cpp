#include "falcon-core/physics/units/Unit.hpp"

#include <cereal/archives/binary.hpp>
#include <cmath>
#include <stdexcept>

#include "falcon-core/Constants.hpp"
#include "falcon-core/physics/units/Prefix.hpp"
#include "falcon-core/physics/units/TotalDimensions.hpp"
namespace falcon_core {
namespace physics {
namespace units {
Unit::Unit(TotalDimensions dimensions,
           double          scale_factor,
           double          offset,
           std::string     prefix)
    : _scale_factor(scale_factor),
      _offset(offset),
      _prefix(prefix),
      _dimensions(dimensions) {}

UnitSP Unit::Meter() { return std::make_shared<Unit>(SI::DIMENSIONS_METER()); }
UnitSP Unit::Kilogram() {
  return std::make_shared<Unit>(SI::DIMENSIONS_KILOGRAM());
}
UnitSP Unit::Second() {
  return std::make_shared<Unit>(SI::DIMENSIONS_SECOND());
}
UnitSP Unit::Ampere() {
  return std::make_shared<Unit>(SI::DIMENSIONS_AMPERE());
}
UnitSP Unit::Kelvin() {
  return std::make_shared<Unit>(SI::DIMENSIONS_KELVIN());
}
UnitSP Unit::Mole() { return std::make_shared<Unit>(SI::DIMENSIONS_MOLE()); }
UnitSP Unit::Candela() {
  return std::make_shared<Unit>(SI::DIMENSIONS_CANDELA());
}
UnitSP Unit::Hertz() { return std::make_shared<Unit>(SI::DIMENSIONS_HERTZ()); }
UnitSP Unit::Newton() {
  return std::make_shared<Unit>(SI::DIMENSIONS_NEWTON());
}
UnitSP Unit::Pascal() {
  return std::make_shared<Unit>(SI::DIMENSIONS_PASCAL());
}
UnitSP Unit::Joule() { return std::make_shared<Unit>(SI::DIMENSIONS_JOULE()); }
UnitSP Unit::Watt() { return std::make_shared<Unit>(SI::DIMENSIONS_WATT()); }
UnitSP Unit::Coulomb() {
  return std::make_shared<Unit>(SI::DIMENSIONS_COULOMB());
}
UnitSP Unit::Volt() { return std::make_shared<Unit>(SI::DIMENSIONS_VOLT()); }
UnitSP Unit::Farad() { return std::make_shared<Unit>(SI::DIMENSIONS_FARAD()); }
UnitSP Unit::Ohm() { return std::make_shared<Unit>(SI::DIMENSIONS_OHM()); }
UnitSP Unit::Siemens() {
  return std::make_shared<Unit>(SI::DIMENSIONS_SIEMENS());
}
UnitSP Unit::Weber() { return std::make_shared<Unit>(SI::DIMENSIONS_WEBER()); }
UnitSP Unit::Tesla() { return std::make_shared<Unit>(SI::DIMENSIONS_TESLA()); }
UnitSP Unit::Henry() { return std::make_shared<Unit>(SI::DIMENSIONS_HENRY()); }
UnitSP Unit::Minute() {
  return std::make_shared<Unit>(
      SI::DIMENSIONS_SECOND(), SECONDS_PER_MINUTE, 0.0, SI::UNIT_SYMBOL);
}
UnitSP Unit::Hour() {
  return std::make_shared<Unit>(SI::DIMENSIONS_SECOND(),
                                SECONDS_PER_MINUTE * MINUTES_PER_HOUR,
                                0.0,
                                SI::UNIT_SYMBOL);
}
UnitSP Unit::ElectronVolt() {
  return std::make_shared<Unit>(
      SI::DIMENSIONS_JOULE(), ELECTRON_CHARGE, 0.0, SI::UNIT_SYMBOL);
}
UnitSP Unit::Celsius() {
  return std::make_shared<Unit>(
      SI::DIMENSIONS_KELVIN(), 1.0, CELSIUS_OFFSET, SI::UNIT_SYMBOL);
}
UnitSP Unit::Fahrenheit() {
  return std::make_shared<Unit>(SI::DIMENSIONS_KELVIN(),
                                UNIT_SCALE_FAHRENHEIT,
                                FAHRENHEIT_OFFSET,
                                SI::UNIT_SYMBOL);
}
UnitSP Unit::Dimensionless() {
  return std::make_shared<Unit>(SI::DIMENSIONS_DIMENSIONLESS());
}
UnitSP Unit::Percent() {
  return std::make_shared<Unit>(
      SI::DIMENSIONS_DIMENSIONLESS(), 0.01, 0.0, SI::UNIT_SYMBOL);
}
UnitSP Unit::Radian() {
  return std::make_shared<Unit>(
      SI::DIMENSIONS_DIMENSIONLESS(), 1 / (2 * PI), 0.0, SI::UNIT_SYMBOL);
}
UnitSP Unit::operator*(const UnitSP& other) const {
  if (!other) {
    throw std::invalid_argument("Unit: Don't multiply by null");
  }
  TotalDimensions result_dims = this->_dimensions;
  for (auto it = other->_dimensions.begin(); it != other->_dimensions.end();
       ++it) {
    const std::string& dim = it->first;
    int                exp = it->second;
    result_dims[dim] += exp;
  }
  Unit::clean_dimensions(result_dims);
  return std::make_shared<Unit>(result_dims,
                                this->_scale_factor * other->_scale_factor,
                                this->_offset + other->_offset,
                                this->_prefix);
}
void Unit::clean_dimensions(TotalDimensions& dims) {
  for (auto it = dims.begin(); it != dims.end();) {
    if (it->second == 0) {
      it = dims.erase(it);
    } else {
      ++it;
    }
  }
}

std::string     Unit::prefix() const { return this->_prefix; }
TotalDimensions Unit::dimensions() const { return this->_dimensions; }
double          Unit::scale_factor() const { return this->_scale_factor; }
double          Unit::offset() const { return this->_offset; }

UnitSP Unit::operator/(const UnitSP& other) const {
  if (!other) {
    throw std::invalid_argument("Unit: Don't divide by null");
  }
  TotalDimensions result_dims = this->_dimensions;
  for (auto it = other->_dimensions.begin(); it != other->_dimensions.end();
       ++it) {
    const std::string& dim = it->first;
    int                exp = it->second;
    result_dims[dim] -= exp;
  }
  Unit::clean_dimensions(result_dims);
  return std::make_shared<Unit>(result_dims,
                                this->_scale_factor / other->_scale_factor,
                                this->_offset - other->_offset,
                                this->_prefix);
}

UnitSP Unit::operator^(const int power) const {
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

UnitSP Unit::with_prefix(const std::string prefix) const {
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
UnitSP Unit::get_milli() const { return with_prefix(SI::MILLI_SYMBOL); }
UnitSP Unit::get_micro() const { return with_prefix(SI::MICRO_SYMBOL); }
UnitSP Unit::get_nano() const { return with_prefix(SI::NANO_SYMBOL); }
UnitSP Unit::get_pico() const { return with_prefix(SI::PICO_SYMBOL); }
UnitSP Unit::get_kilo() const { return with_prefix(SI::KILO_SYMBOL); }
UnitSP Unit::get_mega() const { return with_prefix(SI::MEGA_SYMBOL); }
UnitSP Unit::get_giga() const { return with_prefix(SI::GIGA_SYMBOL); }

std::string dimensions_to_string(const TotalDimensions& dims) {
  std::ostringstream oss;
  oss << "{";
  bool first = true;
  for (auto it = dims.begin(); it != dims.end(); ++it) {
    if (!first) oss << ", ";
    first = false;
    oss << it->first << ": " << it->second;
  }
  oss << "}";
  return oss.str();
}
double Unit::convert_value_to(const double  value,
                              const UnitSP& target_unit) const {
  if (!target_unit) {
    throw std::invalid_argument(
        "Unit: The target to convert to cannot be null.");
  }
  if (dimensions() != target_unit->dimensions()) {
    throw std::invalid_argument(
        "Unit: Cannot convert between units with different dimensions. Our "
        "dimensions are " +
        dimensions_to_string(dimensions()) +
        " but the units we are converting to are " +
        dimensions_to_string(target_unit->dimensions()));
  }

  // Convert from source unit to base SI unit
  double base_value = (value + offset()) * scale_factor();

  // Convert from base SI unit to target unit
  return (base_value - target_unit->offset()) / target_unit->scale_factor();
}

bool Unit::is_compatible_with(const UnitSP& other) const {
  if (!other) {
    throw std::invalid_argument("Unit: The other cannot be null.");
  }
  return dimensions() == other->dimensions();
}

bool Unit::operator==(const Unit& other) const {
  if (this == &other) return true;
  return (this->dimensions() == other.dimensions()) &&
         (std::abs(this->scale_factor() - other.scale_factor()) < 1e-12) &&
         (std::abs(this->offset() - other.offset()) < 1e-12) &&
         (this->prefix() == other.prefix());
}
bool Unit::operator!=(const Unit& other) const { return !(*this == other); }
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
