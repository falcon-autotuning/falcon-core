#include "falcon_core/physics/units/Prefix.hpp"

#include <algorithm>
#include <cmath>
#include <sstream>
#include <stdexcept>

#include "falcon_core/Constants.hpp"

namespace falcon_core {
namespace physics {
namespace units {

const std::map<int, std::string> power_to_symbol = {
    {SI::YOCTO_EXPONENT, SI::YOCTO_SYMBOL},
    {SI::ZEPTO_EXPONENT, SI::ZEPTO_SYMBOL},
    {SI::ATTO_EXPONENT, SI::ATTO_SYMBOL},
    {SI::FEMTO_EXPONENT, SI::FEMTO_SYMBOL},
    {SI::PICO_EXPONENT, SI::PICO_SYMBOL},
    {SI::NANO_EXPONENT, SI::NANO_SYMBOL},
    {SI::MICRO_EXPONENT, SI::MICRO_SYMBOL},
    {SI::MILLI_EXPONENT, SI::MILLI_SYMBOL},
    {SI::CENTI_EXPONENT, SI::CENTI_SYMBOL},
    {SI::UNIT_EXPONENT, SI::UNIT_SYMBOL},
    {SI::HECTO_EXPONENT, SI::HECTO_SYMBOL},
    {SI::KILO_EXPONENT, SI::KILO_SYMBOL},
    {SI::MEGA_EXPONENT, SI::MEGA_SYMBOL},
    {SI::GIGA_EXPONENT, SI::GIGA_SYMBOL},
    {SI::TERA_EXPONENT, SI::TERA_SYMBOL},
    {SI::PETA_EXPONENT, SI::PETA_SYMBOL},
    {SI::EXA_EXPONENT, SI::EXA_SYMBOL},
    {SI::ZETTA_EXPONENT, SI::ZETTA_SYMBOL},
    {SI::YOTTA_EXPONENT, SI::YOTTA_SYMBOL}};

const std::map<std::string, int> symbol_to_power = {
    {SI::YOCTO_SYMBOL, SI::YOCTO_EXPONENT},
    {SI::ZEPTO_SYMBOL, SI::ZEPTO_EXPONENT},
    {SI::ATTO_SYMBOL, SI::ATTO_EXPONENT},
    {SI::FEMTO_SYMBOL, SI::FEMTO_EXPONENT},
    {SI::PICO_SYMBOL, SI::PICO_EXPONENT},
    {SI::NANO_SYMBOL, SI::NANO_EXPONENT},
    {SI::MICRO_SYMBOL, SI::MICRO_EXPONENT},
    {SI::MILLI_SYMBOL, SI::MILLI_EXPONENT},
    {SI::CENTI_SYMBOL, SI::CENTI_EXPONENT},
    {SI::UNIT_SYMBOL, SI::UNIT_EXPONENT},
    {SI::HECTO_SYMBOL, SI::HECTO_EXPONENT},
    {SI::KILO_SYMBOL, SI::KILO_EXPONENT},
    {SI::MEGA_SYMBOL, SI::MEGA_EXPONENT},
    {SI::GIGA_SYMBOL, SI::GIGA_EXPONENT},
    {SI::TERA_SYMBOL, SI::TERA_EXPONENT},
    {SI::PETA_SYMBOL, SI::PETA_EXPONENT},
    {SI::EXA_SYMBOL, SI::EXA_EXPONENT},
    {SI::ZETTA_SYMBOL, SI::ZETTA_EXPONENT},
    {SI::YOTTA_SYMBOL, SI::YOTTA_EXPONENT}};

std::string Prefix::get_symbol(int prefix_value) {
  if (power_to_symbol.find(prefix_value) == power_to_symbol.end()) {
    std::ostringstream oss;
    oss << "Prefix value " << prefix_value
        << " not found in power_to_symbol mapping";
    throw std::out_of_range(oss.str());
  }
  return power_to_symbol.at(prefix_value);
}

int Prefix::get_value(std::string prefix_symbol) {
  if (symbol_to_power.find(prefix_symbol) == symbol_to_power.end()) {
    std::ostringstream oss;
    oss << "Symbol value " << prefix_symbol
        << " not found in symbol_to_power mapping";
    throw std::out_of_range(oss.str());
  }
  return symbol_to_power.at(prefix_symbol);
}

bool Prefix::is_valid(std::string prefix_symbol) {
  return std::find(std::begin(falcon_core::SI::ALL_PREFIXES),
                   std::end(falcon_core::SI::ALL_PREFIXES),
                   prefix_symbol) != std::end(falcon_core::SI::ALL_PREFIXES);
}

std::pair<double, std::string> Prefix::prefix_multiplication(
    std::string first_prefix, std::string second_prefix, double scale_factor) {
  if (scale_factor == 0.0) {
    return {0.0, SI::UNIT_SYMBOL};
  }
  int first_power    = Prefix::get_value(first_prefix);
  int second_power   = Prefix::get_value(second_prefix);
  int scale_exponent = static_cast<int>(floor(log10(std::abs(scale_factor))));
  int total_exponent = first_power + second_power + scale_exponent;

  // Find the closest valid prefix exponent
  int best_exponent = 0;
  int min_diff      = std::abs(total_exponent);

  for (const auto& pair : power_to_symbol) {
    if (std::abs(total_exponent - pair.first) < min_diff) {
      min_diff      = std::abs(total_exponent - pair.first);
      best_exponent = pair.first;
    }
  }

  std::string new_symbol = Prefix::get_symbol(best_exponent);
  double new_scale_factor =
      scale_factor *
      std::pow(10.0, (first_power + second_power) - best_exponent);

  return {new_scale_factor, new_symbol};
}

}  // namespace units
}  // namespace physics
}  // namespace falcon_core
