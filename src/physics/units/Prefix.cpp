#include "falcon_core/physics/units/Prefix.hpp"

#include <algorithm>
#include <cmath>
#include <sstream>

#include "falcon_core/Constants.hpp"

using namespace falcon_core::physics::units;
std::string get_symbol(int prefix_value) {
  if (power_to_symbol.find(prefix_value) == power_to_symbol.end()) {
    std::ostringstream oss;
    oss << "Prefix value " << prefix_value
        << " not found in power_to_symbol mapping";
    throw std::out_of_range(oss.str());
  }
  return power_to_symbol.at(prefix_value);
}
int get_value(std::string prefix_symbol) {
  if (symbol_to_power.find(prefix_symbol) == symbol_to_power.end()) {
    std::ostringstream oss;
    oss << "Symbol value " << prefix_symbol
        << " not found in symbol_to_power mapping";
    throw std::out_of_range(oss.str());
  }
  return symbol_to_power.at(prefix_symbol);
}
bool is_valid(std::string prefix_symbol) {
  return std::find(std::begin(falcon_core::SI::ALL_PREFIXES),
                   std::end(falcon_core::SI::ALL_PREFIXES),
                   prefix_symbol) != std::end(falcon_core::SI::ALL_PREFIXES);
}
std::pair<double, std::string> prefix_multiplication(std::string first_prefix,
                                                     std::string second_prefix,
                                                     double      scale_factor) {
  int first_value  = get_value(first_prefix);
  int second_value = get_value(second_prefix);
  int scale_exponent =
      int(log10(std::abs(scale_factor))) * int(scale_factor < 0 ? -1 : 1);
  int new_exponent = first_value + second_value + scale_exponent;
  for (int offset = 0; offset <= 2; ++offset) {
    try {
      std::string new_symbol = get_symbol(new_exponent - offset);
      return {scale_factor * std::pow(10, -scale_exponent + offset),
              new_symbol};
    } catch (const std::out_of_range &) {
      // Try next offset
    }
  }
  throw std::out_of_range("No valid prefix symbol found for exponent range.");
}
