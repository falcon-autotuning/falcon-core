#pragma once

#include <memory>
#include <string>

#include "falcon_core/generic/Song.hpp"
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
  const std::pair<std::string, std::string> _find_matching_common_unit() const;
  /*
   * @brief Generate a symbol for the unit based on its dimensions.
   * @return A string representing the generated symbol.
   */
  const std::string _generate_symbol() const;
  /*
   * @brief Get the symbol for a given dimension.
   * @param dimension The dimension to get the symbol for.
   * @return A string representing the symbol for the dimension.
   */
  const std::string _get_dimension_symbol(std::string dimension) const;
  /*
   * @brief Generate a name for the unit based on its dimensions.
   * @return A string representing the generated name.
   */
  const std::string _generate_name() const;

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
  const UnitSP unit() const;
  /*
   * @brief Get the name of the unit.
   * @return The name as a string.
   */
  const std::string symbol() const;
  /*
   * @brief Get the name of the unit.
   * @return The name as a string.
   */
  const std::string name() const;
  /*
   * @brief Multiply this symbol unit by another symbol unit.
   * @param other The symbol unit to multiply by.
   * @return A new SymbolUnit representing the product of this symbol unit and
   * the other.
   */
  const std::shared_ptr<SymbolUnit> operator*(
      const std::shared_ptr<SymbolUnit>& other) const;
  const std::shared_ptr<SymbolUnit> operator*(const UnitSP& other) const;
  /*
   * @brief Divide this symbol unit by another symbol unit.
   * @param other The symbol unit to divide by.
   * @return A new SymbolUnit representing the division of this symbol unit by
   * the other.
   */
  const std::shared_ptr<SymbolUnit> operator/(
      const std::shared_ptr<SymbolUnit>& other) const;
  const std::shared_ptr<SymbolUnit> operator/(const UnitSP& other) const;
  /*
   * @brief Raise the symbol unit to a power.
   * @param power The exponent to raise the symbol unit to.
   * @return A new SymbolUnit raised to the specified power.
   */
  const std::shared_ptr<SymbolUnit> operator^(const int power) const;
  /*
   * @brief Apply a prefix to this symbol unit.
   * @param prefix The prefix symbol to apply (e.g. "k" for kilo
   * @return A new SymbolUnit with the specified prefix applied.
   * @throws std::invalid_argument if the prefix is not valid.
   */
  const std::shared_ptr<SymbolUnit> with_prefix(const std::string prefix) const;
  /*
   * @brief Convert a value from this symbol unit to a target symbol unit.
   * @param value The value in this symbol unit to convert.
   * @param target_unit The symbol unit to convert the value to.
   * @return The converted value in the target symbol unit.
   * @throws std::invalid_argument if the units are not compatible.
   */
  const double convert_value_to(
      const double value, const std::shared_ptr<SymbolUnit>& target_unit) const;
  /*
   * @brief Check if this symbol unit is compatible with another symbol unit.
   * @param other The symbol unit to check compatibility with.
   * @return True if the symbol units are compatible (same dimensions), false
   * otherwise.
   */
  const bool is_compatible_with(const std::shared_ptr<SymbolUnit>& other) const;

  const std::vector<std::tuple<UnitSP, std::string, std::string>>
  get_unit_symbols() const;

  const std::map<std::string, std::string> get_dimension_symbols() const;

  const std::string str() const;

 protected:
  SymbolUnit();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _unit, _symbol, _name);
  }
};
using SymbolUnitSP = std::shared_ptr<SymbolUnit>;
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
