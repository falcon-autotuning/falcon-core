#pragma once

#include <map>
#include <string>

#include "falcon_core/Constants.hpp"

namespace falcon_core {
namespace physics {
namespace units {

class Prefix {
 public:
  /**
   * @brief Get the symbol to power map.
   * @return A constant reference to the symbol to power map.
   */
  static const std::map<std::string, int>& get_symbol_to_power_map();
  /**
   * @brief Get the power to symbol map.
   * @return A constant reference to the power to symbol map.
   */
  static const std::map<int, std::string>& get_power_to_symbol_map();
  /*
   * @brief Get the symbol for a prefix value.
   * @param prefix_value The exponent value of the prefix.
   * @return The symbol corresponding to the prefix value.
   */
  static std::string get_symbol(int prefix_value);
  /*
   * @brief Get the exponent value for a prefix symbol.
   * @param prefix_symbol The symbol of the prefix.
   * @return The exponent value corresponding to the prefix symbol.
   */
  static int get_value(std::string prefix_symbol);
  /*
   * @brief Check if a prefix symbol is valid.
   * @param prefix_symbol The symbol of the prefix.
   * @return True if the prefix is valid
   */
  static bool is_valid(std::string prefix_symbol);
  /*
   * @brief Multiply two prefixes together.
   * @param first_prefix The first prefix symbol.
   * @param second_prefix The second prefix symbol.
   * @param scale_factor The scale factor to apply.
   * @return A pair containing the resulting prefix symbol and scale factor.
   */
  static std::pair<double, std::string> prefix_multiplication(
      std::string first_prefix, std::string second_prefix, double scale_factor);
};
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
