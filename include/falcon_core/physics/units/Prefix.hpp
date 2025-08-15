#pragma once

#include <map>
#include <string>

#include "falcon_core/Constants.hpp"

namespace falcon_core {
namespace physics {
namespace units {

extern const std::map<int, std::string> power_to_symbol;
extern const std::map<std::string, int> symbol_to_power;

class Prefix {
 public:
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
