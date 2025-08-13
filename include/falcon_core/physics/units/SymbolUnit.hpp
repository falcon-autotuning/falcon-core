#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/Unit.hpp"

#include <memory>
#include <string>

namespace falcon_core
{
namespace physics
{
namespace units
{

class SymbolUnit : public generic::Song
{
public:
  /*
   * @brief Construct a SymbolUnit with a specific symbol and associated Unit.
   * @param unit The Unit object associated with this symbol.
   */
  SymbolUnit (std::shared_ptr<Unit> unit);

  const std::map<Unit, std::string> _UNIT_SYMBOLS = {
    { Meter, SI::UNIT_SYMBOL_METER },
    { Kilogram, SI::UNIT_SYMBOL_KILOGRAM },
    { Second, SI::UNIT_NAME_SECOND },
    { Ampere, SI::UNIT_SYMBOL_AMPERE },
    { Kelvin, SI::UNIT_SYMBOL_KELVIN },
    { Mole, SI::UNIT_SYMBOL_MOLE },
    { Candela, SI::UNIT_SYMBOL_CANDELA },
    { Hertz, SI::UNIT_SYMBOL_HERTZ },
    { Newton, SI::UNIT_SYMBOL_NEWTON },
    { Pascal, SI::UNIT_SYMBOL_PASCAL },
    { Joule, SI::UNIT_SYMBOL_JOULE },
    { Watt, SI::UNIT_SYMBOL_WATT },
    { Coulomb, SI::UNIT_SYMBOL_COULOMB },
    { Volt, SI::UNIT_SYMBOL_VOLT },
    { Farad, SI::UNIT_SYMBOL_FARAD },
    { Ohm, SI::UNIT_SYMBOL_OHM },
    { Siemens, SI::UNIT_SYMBOL_SIEMENS },
    { Weber, SI::UNIT_SYMBOL_WEBER },
    { Tesla, SI::UNIT_SYMBOL_TESLA },
    { Henry, SI::UNIT_SYMBOL_HENRY },
    { Minute, SI::UNIT_SYMBOL_MINUTE },
    { Hour, SI::UNIT_SYMBOL_HOUR },
    { ElectronVolt, SI::UNIT_SYMBOL_ELECTRON_VOLT },
    { Celsius, SI::UNIT_SYMBOL_CELSIUS },
    { Fahrenheit, SI::UNIT_SYMBOL_FAHRENHEIT },
    { Dimensionless, SI::UNIT_SYMBOL },
    { Percent, SI::UNIT_SYMBOL_PERCENT },
    { Radian, SI::UNIT_SYMBOL_RADIAN },
  };

  const std::map<Unit, std::string> _UNIT_NAMES = {
    { Meter, SI::UNIT_NAME_METER },
    { Kilogram, SI::UNIT_NAME_KILOGRAM },
    { Second, SI::UNIT_NAME_SECOND },
    { Ampere, SI::UNIT_NAME_AMPERE },
    { Kelvin, SI::UNIT_NAME_KELVIN },
    { Mole, SI::UNIT_NAME_MOLE },
    { Candela, SI::UNIT_NAME_CANDELA },
    { Hertz, SI::UNIT_NAME_HERTZ },
    { Newton, SI::UNIT_NAME_NEWTON },
    { Pascal, SI::UNIT_NAME_PASCAL },
    { Joule, SI::UNIT_NAME_JOULE },
    { Watt, SI::UNIT_NAME_WATT },
    { Coulomb, SI::UNIT_NAME_COULOMB },
    { Volt, SI::UNIT_NAME_VOLT },
    { Farad, SI::UNIT_NAME_FARAD },
    { Ohm, SI::UNIT_NAME_OHM },
    { Siemens, SI::UNIT_NAME_SIEMENS },
    { Weber, SI::UNIT_NAME_WEBER },
    { Tesla, SI::UNIT_NAME_TESLA },
    { Henry, SI::UNIT_NAME_HENRY },
    { Minute, SI::UNIT_NAME_MINUTE },
    { Hour, SI::UNIT_NAME_HOUR },
    { ElectronVolt, SI::UNIT_NAME_ELECTRON_VOLT },
    { Celsius, SI::UNIT_NAME_CELSIUS },
    { Fahrenheit, SI::UNIT_NAME_FAHRENHEIT },
    { Dimensionless, SI::UNIT_NAME_DIMENSIONLESS },
    { Percent, SI::UNIT_NAME_PERCENT },
    { Radian, SI::UNIT_NAME_RADIAN },
  };

  const std::map<std::string, std::string> _DIMENSION_SYMBOLS = {
    { SI::DIMENSION_LENGTH, SI::UNIT_SYMBOL_METER },
    { SI::DIMENSION_MASS, SI::UNIT_SYMBOL_KILOGRAM },
    { SI::DIMENSION_TIME, SI::UNIT_SYMBOL_SECOND },
    { SI::DIMENSION_CURRENT, SI::UNIT_SYMBOL_AMPERE },
    { SI::DIMENSION_TEMPERATURE, SI::UNIT_SYMBOL_KELVIN },
    { SI::DIMENSION_AMOUNT, SI::UNIT_SYMBOL_MOLE },
    { SI::DIMENSION_LUMINOSITY, SI::UNIT_SYMBOL_CANDELA },
  };
  /*
   * @brief Get the symbol of the unit.
   * @return The symbol as a string.
   */
  const std::shared_ptr<Unit>
  unit () const
  {
    return _unit;
  }
  /*
   * @brief Get the name of the unit.
   * @return The name as a string.
   */
  const std::string &
  symbol () const
  {
    return _symbol;
  }
  /*
   * @brief Get the name of the unit.
   * @return The name as a string.
   */
  const std::string &
  name () const
  {
    return _name;
  }
  /*
   * @brief Multiply this symbol unit by another symbol unit.
   * @param other The symbol unit to multiply by.
   * @return A new SymbolUnit representing the product of this symbol unit and
   * the other.
   */
  std::shared_ptr<SymbolUnit> operator* (const SymbolUnit &other) const;
  std::shared_ptr<SymbolUnit> operator* (const Unit &other) const;
  /*
   * @brief Divide this symbol unit by another symbol unit.
   * @param other The symbol unit to divide by.
   * @return A new SymbolUnit representing the division of this symbol unit by
   * the other.
   */
  std::shared_ptr<SymbolUnit> operator/ (const SymbolUnit &other) const;
  std::shared_ptr<SymbolUnit> operator/ (const Unit &other) const;
  /*
   * @brief Raise the symbol unit to a power.
   * @param power The exponent to raise the symbol unit to.
   * @return A new SymbolUnit raised to the specified power.
   */
  std::shared_ptr<SymbolUnit> operator^ (const int power) const;
  /*
   * @brief Apply a prefix to this symbol unit.
   * @param prefix The prefix symbol to apply (e.g. "k" for kilo
   * @return A new SymbolUnit with the specified prefix applied.
   * @throws std::invalid_argument if the prefix is not valid.
   */
  std::shared_ptr<SymbolUnit> with_prefix (const std::string prefix) const;
  /*
   * @brief Convert a value from this symbol unit to a target symbol unit.
   * @param value The value in this symbol unit to convert.
   * @param target_unit The symbol unit to convert the value to.
   * @return The converted value in the target symbol unit.
   * @throws std::invalid_argument if the units are not compatible.
   */
  double
  convert_value_to (const double                      value,
                    const std::shared_ptr<SymbolUnit> target_unit) const;
  /*
   * @brief Check if this symbol unit is compatible with another symbol unit.
   * @param other The symbol unit to check compatibility with.
   * @return True if the symbol units are compatible (same dimensions), false
   * otherwise.
   */
  bool is_compatible_with (const std::shared_ptr<SymbolUnit> other) const;

private:
  std::shared_ptr<Unit> _unit;
  std::string           _symbol;
  std::string           _name;

  /*
   * @brief Find a matching common unit for the given unit.
   * @return A pair containing the matching common unit's symbol and name.
   */
  std::pair<std::string, std::string> _find_matching_common_unit () const;
  /*
   * @brief Generate a symbol for the unit based on its dimensions.
   * @return A string representing the generated symbol.
   */
  std::string _generate_symbol () const;
  /*
   * @brief Get the symbol for a given dimension.
   * @param dimension The dimension to get the symbol for.
   * @return A string representing the symbol for the dimension.
   */
  std::string _get_dimension_symbol (std::string dimension) const;
  /*
   * @brief Generate a name for the unit based on its dimensions.
   * @return A string representing the generated name.
   */
  std::string _generate_name () const;
};

}
}
} // namespace falcon_core
