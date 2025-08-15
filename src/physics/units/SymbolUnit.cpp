#include "falcon_core/physics/units/SymbolUnit.hpp"

#include <memory>
#include <sstream>

#include "falcon_core/physics/units/Unit.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::units;

SymbolUnit::SymbolUnit(std::shared_ptr<Unit> unit) : _unit(std::move(unit)) {
  auto results = this->_find_matching_common_unit();
  _symbol      = results.first;
  _name        = results.second;
}

std::shared_ptr<SymbolUnit> SymbolUnit::operator*(
    const std::shared_ptr<SymbolUnit> other) const {
  return std::make_shared<SymbolUnit>(*_unit * *other->_unit);
}
std::shared_ptr<SymbolUnit> SymbolUnit::operator*(
    const std::shared_ptr<Unit> other) const {
  return std::make_shared<SymbolUnit>(*_unit * *other);
}
std::shared_ptr<SymbolUnit> SymbolUnit::operator/(
    const std::shared_ptr<SymbolUnit> other) const {
  return std::make_shared<SymbolUnit>(*_unit / *other->_unit);
}
std::shared_ptr<SymbolUnit> SymbolUnit::operator/(
    const std::shared_ptr<Unit> other) const {
  return std::make_shared<SymbolUnit>(*_unit / *other);
}
std::shared_ptr<SymbolUnit> SymbolUnit::operator^(const int power) const {
  return std::make_shared<SymbolUnit>(*_unit ^ power);
}
std::shared_ptr<SymbolUnit> SymbolUnit::with_prefix(
    const std::string prefix) const {
  return std::make_shared<SymbolUnit>(_unit->with_prefix(prefix));
}
double SymbolUnit::convert_value_to(
    const double value, const std::shared_ptr<SymbolUnit> target_unit) const {
  return _unit->convert_value_to(value, *target_unit->_unit);
}
bool SymbolUnit::is_compatible_with(
    const std::shared_ptr<SymbolUnit> other) const {
  return _unit->is_compatible_with(*other->_unit);
}
std::pair<std::string, std::string> SymbolUnit::_find_matching_common_unit()
    const {
  for (const auto &triplet : _UNIT_SYMBOLS) {
    if (std::get<0>(triplet).dimensions() == _unit->dimensions()) {
      return {_unit->prefix() + std::get<1>(triplet),
              _unit->prefix() + std::get<2>(triplet)};
    }
  }
  // No exact match found, generate a custom symbol and name
  return std::make_pair(_generate_symbol(), _generate_name());
}
std::string SymbolUnit::_generate_symbol() const {
  // If dimensions are empty, return the appropriate SI unit symbol
  if (_unit->dimensions().empty()) {
    if (_unit->scale_factor() == 0.01) {
      return SI::UNIT_SYMBOL_PERCENT;
    } else {
      return SI::UNIT_SYMBOL;  // Dimensionless
    }
  }

  std::map<std::string, int> numerator, denominator;

  // Separate numerator and denominator
  for (const auto &dim : _unit->dimensions()) {
    if (dim.second > 0) {
      numerator[dim.first] = dim.second;
    } else if (dim.second < 0) {
      denominator[dim.first] = -dim.second;
    }
  }

  // Build numerator string
  std::vector<std::string> num_symbols;
  for (const auto &pair : numerator) {
    std::string symbol = _get_dimension_symbol(pair.first);
    if (pair.second == 1)
      num_symbols.push_back(symbol);
    else
      num_symbols.push_back(symbol + "^" + std::to_string(pair.second));
  }

  // Build denominator string
  std::vector<std::string> denom_symbols;
  for (const auto &pair : denominator) {
    std::string symbol = _get_dimension_symbol(pair.first);
    if (pair.second == 1)
      denom_symbols.push_back(symbol);
    else
      denom_symbols.push_back(symbol + "^" + std::to_string(pair.second));
  }

  // Add prefix if present
  std::string prefix = _unit->prefix();

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
std::string SymbolUnit::_get_dimension_symbol(std::string dimension) const {
  // Check if the dimension is in the common units map
  auto it = _DIMENSION_SYMBOLS.find(dimension);
  if (it != _DIMENSION_SYMBOLS.end()) {
    return it->second;
  }
  // If not found, return the dimension as is
  return dimension;
}
std::string SymbolUnit::_generate_name() const {
  // Look for a predefined name based on dimensions
  for (const auto &triplet : _UNIT_SYMBOLS) {
    if (std::get<0>(triplet).dimensions() == _unit->dimensions()) {
      return std::get<1>(triplet);
    }
  }
  // Otherwise, use the symbol as the name
  return _generate_symbol();
}
CEREAL_REGISTER_TYPE(SymbolUnit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, SymbolUnit)
