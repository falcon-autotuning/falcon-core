#include "falcon_core/physics/units/SymbolUnit.hpp"

#include <cereal/archives/binary.hpp>
#include <memory>
#include <sstream>

#include "falcon_core/Constants.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/Unit.hpp"
using namespace falcon_core;
using namespace falcon_core::physics::units;
namespace falcon_core {
namespace physics {
namespace units {
const std::vector<std::tuple<UnitSP, std::string, std::string>> Units_And_Names{
    {CommonUnits::Meter, SI::UNIT_SYMBOL_METER, SI::UNIT_NAME_METER},
    {CommonUnits::Kilogram, SI::UNIT_SYMBOL_KILOGRAM, SI::UNIT_NAME_KILOGRAM},
    {CommonUnits::Second, SI::UNIT_SYMBOL_SECOND, SI::UNIT_NAME_SECOND},
    {CommonUnits::Ampere, SI::UNIT_SYMBOL_AMPERE, SI::UNIT_NAME_AMPERE},
    {CommonUnits::Kelvin, SI::UNIT_SYMBOL_KELVIN, SI::UNIT_NAME_KELVIN},
    {CommonUnits::Mole, SI::UNIT_SYMBOL_MOLE, SI::UNIT_NAME_MOLE},
    {CommonUnits::Candela, SI::UNIT_SYMBOL_CANDELA, SI::UNIT_NAME_CANDELA},
    {CommonUnits::Hertz, SI::UNIT_SYMBOL_HERTZ, SI::UNIT_NAME_HERTZ},
    {CommonUnits::Newton, SI::UNIT_SYMBOL_NEWTON, SI::UNIT_NAME_NEWTON},
    {CommonUnits::Pascal, SI::UNIT_SYMBOL_PASCAL, SI::UNIT_NAME_PASCAL},
    {CommonUnits::Joule, SI::UNIT_SYMBOL_JOULE, SI::UNIT_NAME_JOULE},
    {CommonUnits::Watt, SI::UNIT_SYMBOL_WATT, SI::UNIT_NAME_WATT},
    {CommonUnits::Coulomb, SI::UNIT_SYMBOL_COULOMB, SI::UNIT_NAME_COULOMB},
    {CommonUnits::Volt, SI::UNIT_SYMBOL_VOLT, SI::UNIT_NAME_VOLT},
    {CommonUnits::Farad, SI::UNIT_SYMBOL_FARAD, SI::UNIT_NAME_FARAD},
    {CommonUnits::Ohm, SI::UNIT_SYMBOL_OHM, SI::UNIT_NAME_OHM},
    {CommonUnits::Siemens, SI::UNIT_SYMBOL_SIEMENS, SI::UNIT_NAME_SIEMENS},
    {CommonUnits::Weber, SI::UNIT_SYMBOL_WEBER, SI::UNIT_NAME_WEBER},
    {CommonUnits::Tesla, SI::UNIT_SYMBOL_TESLA, SI::UNIT_NAME_TESLA},
    {CommonUnits::Henry, SI::UNIT_SYMBOL_HENRY, SI::UNIT_NAME_HENRY},
    {CommonUnits::Minute, SI::UNIT_SYMBOL_MINUTE, SI::UNIT_NAME_MINUTE},
    {CommonUnits::Hour, SI::UNIT_SYMBOL_HOUR, SI::UNIT_NAME_HOUR},
    {CommonUnits::ElectronVolt,
     SI::UNIT_SYMBOL_ELECTRON_VOLT,
     SI::UNIT_NAME_ELECTRON_VOLT},
    {CommonUnits::Celsius, SI::UNIT_SYMBOL_CELSIUS, SI::UNIT_NAME_CELSIUS},
    {CommonUnits::Fahrenheit,
     SI::UNIT_SYMBOL_FAHRENHEIT,
     SI::UNIT_NAME_FAHRENHEIT},
    {CommonUnits::Dimensionless, SI::UNIT_SYMBOL, SI::UNIT_NAME_DIMENSIONLESS},
    {CommonUnits::Percent, SI::UNIT_SYMBOL_PERCENT, SI::UNIT_NAME_PERCENT},
    {CommonUnits::Radian, SI::UNIT_SYMBOL_RADIAN, SI::UNIT_NAME_RADIAN},
};
const std::map<std::string, std::string> Dimension_Symbols{
    {SI::DIMENSION_LENGTH, SI::UNIT_SYMBOL_METER},
    {SI::DIMENSION_MASS, SI::UNIT_SYMBOL_KILOGRAM},
    {SI::DIMENSION_TIME, SI::UNIT_SYMBOL_SECOND},
    {SI::DIMENSION_CURRENT, SI::UNIT_SYMBOL_AMPERE},
    {SI::DIMENSION_TEMPERATURE, SI::UNIT_SYMBOL_KELVIN},
    {SI::DIMENSION_AMOUNT, SI::UNIT_SYMBOL_MOLE},
    {SI::DIMENSION_LUMINOSITY, SI::UNIT_SYMBOL_CANDELA},
};

SymbolUnit::SymbolUnit() = default;
SymbolUnit::SymbolUnit(UnitSP unit) : _unit(unit) {
  auto results = this->_find_matching_common_unit();
  _symbol      = results.first;
  _name        = results.second;
}

const UnitSP SymbolUnit::unit() const {
  if (!_unit) throw std::runtime_error("_unit is null");
  return _unit;
}
/*
 * @brief Get the name of the unit.
 * @return The name as a string.
 */
const std::string SymbolUnit::symbol() const { return _symbol; }
/*
 * @brief Get the name of the unit.
 * @return The name as a string.
 */
const std::string SymbolUnit::name() const { return _name; }
SymbolUnitSP      SymbolUnit::operator*(const SymbolUnitSP& other) const {
  return std::make_shared<SymbolUnit>(*unit() * other->unit());
}
SymbolUnitSP SymbolUnit::operator*(const std::shared_ptr<Unit>& other) const {
  return std::make_shared<SymbolUnit>(*unit() * other);
}
SymbolUnitSP SymbolUnit::operator/(const SymbolUnitSP& other) const {
  return std::make_shared<SymbolUnit>(*unit() / other->unit());
}
SymbolUnitSP SymbolUnit::operator/(const std::shared_ptr<Unit>& other) const {
  return std::make_shared<SymbolUnit>(*unit() / other);
}
SymbolUnitSP SymbolUnit::operator^(const int power) const {
  return std::make_shared<SymbolUnit>(*unit() ^ power);
}
SymbolUnitSP SymbolUnit::with_prefix(const std::string prefix) const {
  return std::make_shared<SymbolUnit>(unit()->with_prefix(prefix));
}
double SymbolUnit::convert_value_to(const double        value,
                                    const SymbolUnitSP& target_unit) const {
  return unit()->convert_value_to(value, target_unit->unit());
}
bool SymbolUnit::is_compatible_with(const SymbolUnitSP& other) const {
  return unit()->is_compatible_with(other->unit());
}
std::string SymbolUnit::str() const { return _symbol; }

std::pair<std::string, std::string> SymbolUnit::_find_matching_common_unit()
    const {
  for (const auto& triplet : get_unit_symbols()) {
    if (std::get<0>(triplet)->dimensions() == unit()->dimensions()) {
      return {unit()->prefix() + std::get<1>(triplet),
              unit()->prefix() + std::get<2>(triplet)};
    }
  }
  // No exact match found, generate a custom symbol and name
  return std::make_pair(_generate_symbol(), _generate_name());
}
std::string SymbolUnit::_generate_symbol() const {
  // If dimensions are empty, return the appropriate SI unit symbol
  if (unit()->dimensions().empty()) {
    if (unit()->scale_factor() == 0.01) {
      return SI::UNIT_SYMBOL_PERCENT;
    } else {
      return SI::UNIT_SYMBOL;  // Dimensionless
    }
  }

  std::map<std::string, int> numerator, denominator;

  // Separate numerator and denominator
  for (const auto& dim : unit()->dimensions()) {
    if (dim.second > 0) {
      numerator[dim.first] = dim.second;
    } else if (dim.second < 0) {
      denominator[dim.first] = -dim.second;
    }
  }

  // Build numerator string
  std::vector<std::string> num_symbols;
  for (const auto& pair : numerator) {
    std::string symbol = _get_dimension_symbol(pair.first);
    if (pair.second == 1)
      num_symbols.push_back(symbol);
    else
      num_symbols.push_back(symbol + "^" + std::to_string(pair.second));
  }

  // Build denominator string
  std::vector<std::string> denom_symbols;
  for (const auto& pair : denominator) {
    std::string symbol = _get_dimension_symbol(pair.first);
    if (pair.second == 1)
      denom_symbols.push_back(symbol);
    else
      denom_symbols.push_back(symbol + "^" + std::to_string(-pair.second));
  }

  // Add prefix if present
  std::string prefix = unit()->prefix();

  // Combine with proper formatting
  std::string numerator_str;
  if (num_symbols.empty()) {
    numerator_str = "1";
  } else if (num_symbols.size() == 1) {
    numerator_str = prefix + num_symbols[0];
  } else {
    std::ostringstream oss;
    oss << prefix << num_symbols[0];
    for (size_t i = 1; i < num_symbols.size(); ++i) {
      oss << "·" << num_symbols[i];
    }
    numerator_str = oss.str();
  }

  if (denom_symbols.empty()) {
    return numerator_str;
  }

  // If there's a single denominator with power 1, use slash notation
  if (denom_symbols.size() == 1 &&
      denom_symbols[0].find('^') == std::string::npos) {
    return numerator_str + "/" + denom_symbols[0];
  }

  // Otherwise, use dot notation for denominator
  std::ostringstream denom_oss;
  denom_oss << denom_symbols[0];
  for (size_t i = 1; i < denom_symbols.size(); ++i) {
    denom_oss << "·" << denom_symbols[i];
  }
  std::string denominator_str = denom_oss.str();

  return numerator_str + "·" + denominator_str;
}
std::vector<std::tuple<UnitSP, std::string, std::string>>
SymbolUnit::get_unit_symbols() const {
  return Units_And_Names;
}

std::map<std::string, std::string> SymbolUnit::get_dimension_symbols() const {
  return Dimension_Symbols;
}
std::string SymbolUnit::_get_dimension_symbol(std::string dimension) const {
  // Check if the dimension is in the common units map
  std::map<std::string, std::string> symbols = get_dimension_symbols();
  auto                               it      = symbols.find(dimension);
  if (it != symbols.end()) {
    return it->second;
  }
  // If not found, return the dimension as is
  return dimension;
}
std::string SymbolUnit::_generate_name() const {
  // Look for a predefined name based on dimensions
  for (const auto& triplet : get_unit_symbols()) {
    if (std::get<0>(triplet)->dimensions() == unit()->dimensions()) {
      return std::get<1>(triplet);
    }
  }
  // Otherwise, use the symbol as the name
  return _generate_symbol();
}
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::units::SymbolUnit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::SymbolUnit)
