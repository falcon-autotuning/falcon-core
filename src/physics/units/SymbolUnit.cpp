#include "falcon_core/physics/units/SymbolUnit.hpp"

#include <cassert>

#include "falcon_core/Constants.hpp"
namespace falcon_core::physics::units {
const std::vector<std::tuple<UnitSP, std::string, std::string>> Units_And_Names{
    {Unit::Meter(), SI::UNIT_SYMBOL_METER, SI::UNIT_NAME_METER},
    {Unit::Kilogram(), SI::UNIT_SYMBOL_KILOGRAM, SI::UNIT_NAME_KILOGRAM},
    {Unit::Second(), SI::UNIT_SYMBOL_SECOND, SI::UNIT_NAME_SECOND},
    {Unit::Ampere(), SI::UNIT_SYMBOL_AMPERE, SI::UNIT_NAME_AMPERE},
    {Unit::Kelvin(), SI::UNIT_SYMBOL_KELVIN, SI::UNIT_NAME_KELVIN},
    {Unit::Mole(), SI::UNIT_SYMBOL_MOLE, SI::UNIT_NAME_MOLE},
    {Unit::Candela(), SI::UNIT_SYMBOL_CANDELA, SI::UNIT_NAME_CANDELA},
    {Unit::Hertz(), SI::UNIT_SYMBOL_HERTZ, SI::UNIT_NAME_HERTZ},
    {Unit::Newton(), SI::UNIT_SYMBOL_NEWTON, SI::UNIT_NAME_NEWTON},
    {Unit::Pascal(), SI::UNIT_SYMBOL_PASCAL, SI::UNIT_NAME_PASCAL},
    {Unit::Joule(), SI::UNIT_SYMBOL_JOULE, SI::UNIT_NAME_JOULE},
    {Unit::Watt(), SI::UNIT_SYMBOL_WATT, SI::UNIT_NAME_WATT},
    {Unit::Coulomb(), SI::UNIT_SYMBOL_COULOMB, SI::UNIT_NAME_COULOMB},
    {Unit::Volt(), SI::UNIT_SYMBOL_VOLT, SI::UNIT_NAME_VOLT},
    {Unit::Farad(), SI::UNIT_SYMBOL_FARAD, SI::UNIT_NAME_FARAD},
    {Unit::Ohm(), SI::UNIT_SYMBOL_OHM, SI::UNIT_NAME_OHM},
    {Unit::Siemens(), SI::UNIT_SYMBOL_SIEMENS, SI::UNIT_NAME_SIEMENS},
    {Unit::Weber(), SI::UNIT_SYMBOL_WEBER, SI::UNIT_NAME_WEBER},
    {Unit::Tesla(), SI::UNIT_SYMBOL_TESLA, SI::UNIT_NAME_TESLA},
    {Unit::Henry(), SI::UNIT_SYMBOL_HENRY, SI::UNIT_NAME_HENRY},
    {Unit::Minute(), SI::UNIT_SYMBOL_MINUTE, SI::UNIT_NAME_MINUTE},
    {Unit::Hour(), SI::UNIT_SYMBOL_HOUR, SI::UNIT_NAME_HOUR},
    {Unit::ElectronVolt(),
     SI::UNIT_SYMBOL_ELECTRON_VOLT,
     SI::UNIT_NAME_ELECTRON_VOLT},
    {Unit::Celsius(), SI::UNIT_SYMBOL_CELSIUS, SI::UNIT_NAME_CELSIUS},
    {Unit::Fahrenheit(), SI::UNIT_SYMBOL_FAHRENHEIT, SI::UNIT_NAME_FAHRENHEIT},
    {Unit::Dimensionless(), SI::UNIT_SYMBOL, SI::UNIT_NAME_DIMENSIONLESS},
    {Unit::Percent(), SI::UNIT_SYMBOL_PERCENT, SI::UNIT_NAME_PERCENT},
    {Unit::Radian(), SI::UNIT_SYMBOL_RADIAN, SI::UNIT_NAME_RADIAN},
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
SymbolUnitSP SymbolUnit::Meter() {
  return std::make_shared<SymbolUnit>(Unit::Meter());
}
SymbolUnitSP SymbolUnit::Kilogram() {
  return std::make_shared<SymbolUnit>(Unit::Kilogram());
}
SymbolUnitSP SymbolUnit::Second() {
  return std::make_shared<SymbolUnit>(Unit::Second());
}
SymbolUnitSP SymbolUnit::Ampere() {
  return std::make_shared<SymbolUnit>(Unit::Ampere());
}
SymbolUnitSP SymbolUnit::Kelvin() {
  return std::make_shared<SymbolUnit>(Unit::Kelvin());
}
SymbolUnitSP SymbolUnit::Mole() {
  return std::make_shared<SymbolUnit>(Unit::Mole());
}
SymbolUnitSP SymbolUnit::Candela() {
  return std::make_shared<SymbolUnit>(Unit::Candela());
}
SymbolUnitSP SymbolUnit::Hertz() {
  return std::make_shared<SymbolUnit>(Unit::Hertz());
}
SymbolUnitSP SymbolUnit::Newton() {
  return std::make_shared<SymbolUnit>(Unit::Newton());
}
SymbolUnitSP SymbolUnit::Pascal() {
  return std::make_shared<SymbolUnit>(Unit::Pascal());
}
SymbolUnitSP SymbolUnit::Joule() {
  return std::make_shared<SymbolUnit>(Unit::Joule());
}
SymbolUnitSP SymbolUnit::Watt() {
  return std::make_shared<SymbolUnit>(Unit::Watt());
}
SymbolUnitSP SymbolUnit::Coulomb() {
  return std::make_shared<SymbolUnit>(Unit::Coulomb());
}
SymbolUnitSP SymbolUnit::Volt() {
  return std::make_shared<SymbolUnit>(Unit::Volt());
}
SymbolUnitSP SymbolUnit::Farad() {
  return std::make_shared<SymbolUnit>(Unit::Farad());
}
SymbolUnitSP SymbolUnit::Ohm() {
  return std::make_shared<SymbolUnit>(Unit::Ohm());
}
SymbolUnitSP SymbolUnit::Siemens() {
  return std::make_shared<SymbolUnit>(Unit::Siemens());
}
SymbolUnitSP SymbolUnit::Weber() {
  return std::make_shared<SymbolUnit>(Unit::Weber());
}
SymbolUnitSP SymbolUnit::Tesla() {
  return std::make_shared<SymbolUnit>(Unit::Tesla());
}
SymbolUnitSP SymbolUnit::Henry() {
  return std::make_shared<SymbolUnit>(Unit::Henry());
}
SymbolUnitSP SymbolUnit::Minute() {
  return std::make_shared<SymbolUnit>(Unit::Minute());
}
SymbolUnitSP SymbolUnit::Hour() {
  return std::make_shared<SymbolUnit>(Unit::Hour());
}
SymbolUnitSP SymbolUnit::ElectronVolt() {
  return std::make_shared<SymbolUnit>(Unit::ElectronVolt());
}
SymbolUnitSP SymbolUnit::Celsius() {
  return std::make_shared<SymbolUnit>(Unit::Celsius());
}
SymbolUnitSP SymbolUnit::Fahrenheit() {
  return std::make_shared<SymbolUnit>(Unit::Fahrenheit());
}
SymbolUnitSP SymbolUnit::Dimensionless() {
  return std::make_shared<SymbolUnit>(Unit::Dimensionless());
}
SymbolUnitSP SymbolUnit::Percent() {
  return std::make_shared<SymbolUnit>(Unit::Percent());
}
SymbolUnitSP SymbolUnit::Radian() {
  return std::make_shared<SymbolUnit>(Unit::Radian());
}
SymbolUnitSP SymbolUnit::KiloMeter() {
  return std::make_shared<SymbolUnit>(Unit::Meter()->get_kilo());
}
SymbolUnitSP SymbolUnit::MilliMeter() {
  return std::make_shared<SymbolUnit>(Unit::Meter()->get_milli());
}
SymbolUnitSP SymbolUnit::MilliVolt() {
  return std::make_shared<SymbolUnit>(Unit::Volt()->get_milli());
}
SymbolUnitSP SymbolUnit::KiloVolt() {
  return std::make_shared<SymbolUnit>(Unit::Volt()->get_kilo());
}
SymbolUnitSP SymbolUnit::MilliAmpere() {
  return std::make_shared<SymbolUnit>(Unit::Ampere()->get_milli());
}
SymbolUnitSP SymbolUnit::MicroAmpere() {
  return std::make_shared<SymbolUnit>(Unit::Ampere()->get_micro());
}
SymbolUnitSP SymbolUnit::NanoAmpere() {
  return std::make_shared<SymbolUnit>(Unit::Ampere()->get_nano());
}
SymbolUnitSP SymbolUnit::PicoAmpere() {
  return std::make_shared<SymbolUnit>(Unit::Ampere()->get_pico());
}
SymbolUnitSP SymbolUnit::MilliSecond() {
  return std::make_shared<SymbolUnit>(Unit::Second()->get_milli());
}
SymbolUnitSP SymbolUnit::MicroSecond() {
  return std::make_shared<SymbolUnit>(Unit::Second()->get_micro());
}
SymbolUnitSP SymbolUnit::NanoSecond() {
  return std::make_shared<SymbolUnit>(Unit::Second()->get_nano());
}
SymbolUnitSP SymbolUnit::PicoSecond() {
  return std::make_shared<SymbolUnit>(Unit::Second()->get_pico());
}
SymbolUnitSP SymbolUnit::MilliOhm() {
  return std::make_shared<SymbolUnit>(Unit::Ohm()->get_milli());
}
SymbolUnitSP SymbolUnit::KiloOhm() {
  return std::make_shared<SymbolUnit>(Unit::Ohm()->get_kilo());
}
SymbolUnitSP SymbolUnit::MegaOhm() {
  return std::make_shared<SymbolUnit>(Unit::Ohm()->get_mega());
}
SymbolUnitSP SymbolUnit::MilliHertz() {
  return std::make_shared<SymbolUnit>(Unit::Hertz()->get_milli());
}
SymbolUnitSP SymbolUnit::KiloHertz() {
  return std::make_shared<SymbolUnit>(Unit::Hertz()->get_kilo());
}
SymbolUnitSP SymbolUnit::MegaHertz() {
  return std::make_shared<SymbolUnit>(Unit::Hertz()->get_mega());
}
SymbolUnitSP SymbolUnit::GigaHertz() {
  return std::make_shared<SymbolUnit>(Unit::Hertz()->get_giga());
}
SymbolUnitSP SymbolUnit::MetersPerSecond() {
  return std::make_shared<SymbolUnit>(*Unit::Meter() / Unit::Second());
}
SymbolUnitSP SymbolUnit::MetersPerSecondSquared() {
  return std::make_shared<SymbolUnit>(*Unit::Meter() / (*Unit::Second() ^ 2));
}
SymbolUnitSP SymbolUnit::NewtonMeter() {
  return std::make_shared<SymbolUnit>(*Unit::Newton() * Unit::Meter());
}
SymbolUnitSP SymbolUnit::NewtonPerMeter() {
  return std::make_shared<SymbolUnit>(*Unit::Newton() / Unit::Meter());
}
SymbolUnitSP SymbolUnit::VoltsPerMeter() {
  return std::make_shared<SymbolUnit>(*Unit::Volt() / Unit::Meter());
}
SymbolUnitSP SymbolUnit::VoltsPerSecond() {
  return std::make_shared<SymbolUnit>(*Unit::Volt() / Unit::Second());
}
SymbolUnitSP SymbolUnit::AmperesPerMeter() {
  return std::make_shared<SymbolUnit>(*Unit::Ampere() / Unit::Meter());
}
SymbolUnitSP SymbolUnit::VoltsPerAmpere() {
  return std::make_shared<SymbolUnit>(*Unit::Volt() / Unit::Ampere());
}
SymbolUnitSP SymbolUnit::WattsPerMeterKelvin() {
  return std::make_shared<SymbolUnit>(*Unit::Watt() /
                                      (*Unit::Meter() * Unit::Kelvin()));
}
const UnitSP SymbolUnit::unit() const {
  if (!_unit) {
    throw std::runtime_error("Our Unit " + name() + " is a null pointer");
  }
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
const std::string  SymbolUnit::name() const { return _name; }
const SymbolUnitSP SymbolUnit::operator*(const SymbolUnitSP& other) const {
  return std::make_shared<SymbolUnit>(*unit() * other->unit());
}
const SymbolUnitSP SymbolUnit::operator*(
    const std::shared_ptr<Unit>& other) const {
  return std::make_shared<SymbolUnit>(*unit() * other);
}
const SymbolUnitSP SymbolUnit::operator/(const SymbolUnitSP& other) const {
  return std::make_shared<SymbolUnit>(*unit() / other->unit());
}
const SymbolUnitSP SymbolUnit::operator/(
    const std::shared_ptr<Unit>& other) const {
  return std::make_shared<SymbolUnit>(*unit() / other);
}
const SymbolUnitSP SymbolUnit::operator^(const int power) const {
  return std::make_shared<SymbolUnit>(*unit() ^ power);
}
const SymbolUnitSP SymbolUnit::with_prefix(const std::string prefix) const {
  return std::make_shared<SymbolUnit>(unit()->with_prefix(prefix));
}
const double SymbolUnit::convert_value_to(
    const double value, const SymbolUnitSP& target_unit) const {
  return unit()->convert_value_to(value, target_unit->unit());
}
const bool SymbolUnit::is_compatible_with(const SymbolUnitSP& other) const {
  return unit()->is_compatible_with(other->unit());
}
const std::string SymbolUnit::str() const { return _symbol; }

const std::pair<std::string, std::string>
SymbolUnit::_find_matching_common_unit() const {
  for (const std::tuple<UnitSP, std::string, std::string>& triplet :
       get_unit_symbols()) {
    if (!std::get<0>(triplet)) {
      throw std::runtime_error("Unit " + std::get<1>(triplet) +
                               " is a null pointer");
    }
    if (std::get<0>(triplet)->dimensions() == unit()->dimensions()) {
      return {unit()->prefix() + std::get<1>(triplet),
              unit()->prefix() + std::get<2>(triplet)};
    }
  }
  // No exact match found, generate a custom symbol and name
  return std::make_pair(_generate_symbol(), _generate_name());
}
const std::string SymbolUnit::_generate_symbol() const {
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
const std::vector<std::tuple<UnitSP, std::string, std::string>>
SymbolUnit::get_unit_symbols() const {
  return Units_And_Names;
}

const std::map<std::string, std::string> SymbolUnit::get_dimension_symbols()
    const {
  return Dimension_Symbols;
}
const std::string SymbolUnit::_get_dimension_symbol(
    std::string dimension) const {
  // Check if the dimension is in the common units map
  std::map<std::string, std::string> symbols = get_dimension_symbols();
  auto                               it      = symbols.find(dimension);
  if (it != symbols.end()) {
    return it->second;
  }
  // If not found, return the dimension as is
  return dimension;
}
const std::string SymbolUnit::_generate_name() const {
  // Look for a predefined name based on dimensions
  for (const auto& triplet : get_unit_symbols()) {
    if (!std::get<0>(triplet)) {
      throw std::runtime_error("Unit " + std::get<1>(triplet) +
                               " is a null pointer");
    }
    if (std::get<0>(triplet)->dimensions() == unit()->dimensions()) {
      return std::get<1>(triplet);
    }
  }
  // Otherwise, use the symbol as the name
  return _generate_symbol();
}
}  // namespace falcon_core::physics::units
CEREAL_REGISTER_TYPE(falcon_core::physics::units::SymbolUnit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::SymbolUnit)
