#pragma once

#include <memory>
#include <string>

#include "falcon_core/Constants.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/macros.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/Unit.hpp"
namespace falcon_core {
namespace physics {
namespace units {

class SymbolUnit : public generic::Song {
  UnitSP      _unit;
  std::string _symbol;
  std::string _name;
  /*
   * @brief Find a matching common unit for the given unit.
   * @return A pair containing the matching common unit's symbol and name.
   */
  std::pair<std::string, std::string> _find_matching_common_unit() const;
  /*
   * @brief Generate a symbol for the unit based on its dimensions.
   * @return A string representing the generated symbol.
   */
  std::string _generate_symbol() const;
  /*
   * @brief Get the symbol for a given dimension.
   * @param dimension The dimension to get the symbol for.
   * @return A string representing the symbol for the dimension.
   */
  std::string _get_dimension_symbol(std::string dimension) const;
  /*
   * @brief Generate a name for the unit based on its dimensions.
   * @return A string representing the generated name.
   */
  std::string _generate_name() const;

  static std::vector<std::tuple<Unit, std::string, std::string>>
  get_unit_symbols() {
    return std::vector<std::tuple<Unit, std::string, std::string>>{
        {common_units::Meter, SI::UNIT_SYMBOL_METER, SI::UNIT_NAME_METER},
        {common_units::Kilogram,
         SI::UNIT_SYMBOL_KILOGRAM,
         SI::UNIT_NAME_KILOGRAM},
        {common_units::Second, SI::UNIT_SYMBOL_SECOND, SI::UNIT_NAME_SECOND},
        {common_units::Ampere, SI::UNIT_SYMBOL_AMPERE, SI::UNIT_NAME_AMPERE},
        {common_units::Kelvin, SI::UNIT_SYMBOL_KELVIN, SI::UNIT_NAME_KELVIN},
        {common_units::Mole, SI::UNIT_SYMBOL_MOLE, SI::UNIT_NAME_MOLE},
        {common_units::Candela, SI::UNIT_SYMBOL_CANDELA, SI::UNIT_NAME_CANDELA},
        {common_units::Hertz, SI::UNIT_SYMBOL_HERTZ, SI::UNIT_NAME_HERTZ},
        {common_units::Newton, SI::UNIT_SYMBOL_NEWTON, SI::UNIT_NAME_NEWTON},
        {common_units::Pascal, SI::UNIT_SYMBOL_PASCAL, SI::UNIT_NAME_PASCAL},
        {common_units::Joule, SI::UNIT_SYMBOL_JOULE, SI::UNIT_NAME_JOULE},
        {common_units::Watt, SI::UNIT_SYMBOL_WATT, SI::UNIT_NAME_WATT},
        {common_units::Coulomb, SI::UNIT_SYMBOL_COULOMB, SI::UNIT_NAME_COULOMB},
        {common_units::Volt, SI::UNIT_SYMBOL_VOLT, SI::UNIT_NAME_VOLT},
        {common_units::Farad, SI::UNIT_SYMBOL_FARAD, SI::UNIT_NAME_FARAD},
        {common_units::Ohm, SI::UNIT_SYMBOL_OHM, SI::UNIT_NAME_OHM},
        {common_units::Siemens, SI::UNIT_SYMBOL_SIEMENS, SI::UNIT_NAME_SIEMENS},
        {common_units::Weber, SI::UNIT_SYMBOL_WEBER, SI::UNIT_NAME_WEBER},
        {common_units::Tesla, SI::UNIT_SYMBOL_TESLA, SI::UNIT_NAME_TESLA},
        {common_units::Henry, SI::UNIT_SYMBOL_HENRY, SI::UNIT_NAME_HENRY},
        {common_units::Minute, SI::UNIT_SYMBOL_MINUTE, SI::UNIT_NAME_MINUTE},
        {common_units::Hour, SI::UNIT_SYMBOL_HOUR, SI::UNIT_NAME_HOUR},
        {common_units::ElectronVolt,
         SI::UNIT_SYMBOL_ELECTRON_VOLT,
         SI::UNIT_NAME_ELECTRON_VOLT},
        {common_units::Celsius, SI::UNIT_SYMBOL_CELSIUS, SI::UNIT_NAME_CELSIUS},
        {common_units::Fahrenheit,
         SI::UNIT_SYMBOL_FAHRENHEIT,
         SI::UNIT_NAME_FAHRENHEIT},
        {common_units::Dimensionless,
         SI::UNIT_SYMBOL,
         SI::UNIT_NAME_DIMENSIONLESS},
        {common_units::Percent, SI::UNIT_SYMBOL_PERCENT, SI::UNIT_NAME_PERCENT},
        {common_units::Radian, SI::UNIT_SYMBOL_RADIAN, SI::UNIT_NAME_RADIAN},
    };
  }

  static std::map<std::string, std::string> get_dimension_symbols() {
    return {
        {SI::DIMENSION_LENGTH, SI::UNIT_SYMBOL_METER},
        {SI::DIMENSION_MASS, SI::UNIT_SYMBOL_KILOGRAM},
        {SI::DIMENSION_TIME, SI::UNIT_SYMBOL_SECOND},
        {SI::DIMENSION_CURRENT, SI::UNIT_SYMBOL_AMPERE},
        {SI::DIMENSION_TEMPERATURE, SI::UNIT_SYMBOL_KELVIN},
        {SI::DIMENSION_AMOUNT, SI::UNIT_SYMBOL_MOLE},
        {SI::DIMENSION_LUMINOSITY, SI::UNIT_SYMBOL_CANDELA},
    };
  }

 public:
  /*
   * @brief Construct a SymbolUnit with a specific symbol and associated Unit.
   * @param unit The Unit object associated with this symbol.
   */
  SymbolUnit(UnitSP unit);
  /*
   * @brief Get the symbol of the unit.
   * @return The symbol as a string.
   */
  const UnitSP unit() const {
    if (!_unit) throw std::runtime_error("_unit is null");
    return _unit;
  }
  /*
   * @brief Get the name of the unit.
   * @return The name as a string.
   */
  const std::string symbol() const { return _symbol; }
  /*
   * @brief Get the name of the unit.
   * @return The name as a string.
   */
  const std::string name() const { return _name; }
  /*
   * @brief Multiply this symbol unit by another symbol unit.
   * @param other The symbol unit to multiply by.
   * @return A new SymbolUnit representing the product of this symbol unit and
   * the other.
   */
  std::shared_ptr<SymbolUnit> operator*(
      const std::shared_ptr<SymbolUnit> other) const;
  std::shared_ptr<SymbolUnit> operator*(const UnitSP other) const;
  /*
   * @brief Divide this symbol unit by another symbol unit.
   * @param other The symbol unit to divide by.
   * @return A new SymbolUnit representing the division of this symbol unit by
   * the other.
   */
  std::shared_ptr<SymbolUnit> operator/(
      const std::shared_ptr<SymbolUnit> other) const;
  std::shared_ptr<SymbolUnit> operator/(const UnitSP other) const;
  /*
   * @brief Raise the symbol unit to a power.
   * @param power The exponent to raise the symbol unit to.
   * @return A new SymbolUnit raised to the specified power.
   */
  std::shared_ptr<SymbolUnit> operator^(const int power) const;
  /*
   * @brief Apply a prefix to this symbol unit.
   * @param prefix The prefix symbol to apply (e.g. "k" for kilo
   * @return A new SymbolUnit with the specified prefix applied.
   * @throws std::invalid_argument if the prefix is not valid.
   */
  std::shared_ptr<SymbolUnit> with_prefix(const std::string prefix) const;
  /*
   * @brief Convert a value from this symbol unit to a target symbol unit.
   * @param value The value in this symbol unit to convert.
   * @param target_unit The symbol unit to convert the value to.
   * @return The converted value in the target symbol unit.
   * @throws std::invalid_argument if the units are not compatible.
   */
  double convert_value_to(const double                      value,
                          const std::shared_ptr<SymbolUnit> target_unit) const;
  /*
   * @brief Check if this symbol unit is compatible with another symbol unit.
   * @param other The symbol unit to check compatibility with.
   * @return True if the symbol units are compatible (same dimensions), false
   * otherwise.
   */
  bool is_compatible_with(const std::shared_ptr<SymbolUnit> other) const;

  std::string str() const { return _symbol; }
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Song>(this), _unit, _symbol, _name);
  }
  // template <class Archive>
  // void serialize(Archive& ar) {
  //   ar(cereal::base_class<Song>(this), _unit, _symbol, _name);
  //   if (ar.isLoading()) {
  //     if (!_unit) {
  //       throw std::runtime_error("Deserialized SymbolUnit has null _unit");
  //     }
  //     auto results = this->_find_matching_common_unit();
  //     _symbol      = results.first;
  //     _name        = results.second;
  //   }
  // }

 protected:
  SymbolUnit() : _unit(nullptr), _symbol(""), _name("") {};
  friend class cereal::access;
};
using SymbolUnitSP = std::shared_ptr<SymbolUnit>;
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
