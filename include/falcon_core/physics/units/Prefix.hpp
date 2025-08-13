#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/generic/Song.hpp"

#include <map>
#include <string>

namespace falcon_core
{
namespace physics
{
namespace units
{

const std::map<int, std::string> power_to_symbol
    = { { SI::YOCTO_EXPONENT, SI::YOCTO_SYMBOL },
        { SI::ZEPTO_EXPONENT, SI::ZEPTO_SYMBOL },
        { SI::ATTO_EXPONENT, SI::ATTO_SYMBOL },
        { SI::FEMTO_EXPONENT, SI::FEMTO_SYMBOL },
        { SI::PICO_EXPONENT, SI::PICO_SYMBOL },
        { SI::NANO_EXPONENT, SI::NANO_SYMBOL },
        { SI::MICRO_EXPONENT, SI::MICRO_SYMBOL },
        { SI::MILLI_EXPONENT, SI::MILLI_SYMBOL },
        { SI::CENTI_EXPONENT, SI::CENTI_SYMBOL },
        { SI::UNIT_EXPONENT, SI::UNIT_SYMBOL },
        { SI::HECTO_EXPONENT, SI::HECTO_SYMBOL },
        { SI::KILO_EXPONENT, SI::KILO_SYMBOL },
        { SI::MEGA_EXPONENT, SI::MEGA_SYMBOL },
        { SI::GIGA_EXPONENT, SI::GIGA_SYMBOL },
        { SI::TERA_EXPONENT, SI::TERA_SYMBOL },
        { SI::PETA_EXPONENT, SI::PETA_SYMBOL },
        { SI::EXA_EXPONENT, SI::EXA_SYMBOL },
        { SI::ZETTA_EXPONENT, SI::ZETTA_SYMBOL },
        { SI::YOTTA_EXPONENT, SI::YOTTA_SYMBOL } };

const std::map<std::string, int> symbol_to_power
    = { { SI::YOCTO_SYMBOL, SI::YOCTO_EXPONENT },
        { SI::ZEPTO_SYMBOL, SI::ZEPTO_EXPONENT },
        { SI::ATTO_SYMBOL, SI::ATTO_EXPONENT },
        { SI::FEMTO_SYMBOL, SI::FEMTO_EXPONENT },
        { SI::PICO_SYMBOL, SI::PICO_EXPONENT },
        { SI::NANO_SYMBOL, SI::NANO_EXPONENT },
        { SI::MICRO_SYMBOL, SI::MICRO_EXPONENT },
        { SI::MILLI_SYMBOL, SI::MILLI_EXPONENT },
        { SI::CENTI_SYMBOL, SI::CENTI_EXPONENT },
        { SI::UNIT_SYMBOL, SI::UNIT_EXPONENT },
        { SI::HECTO_SYMBOL, SI::HECTO_EXPONENT },
        { SI::KILO_SYMBOL, SI::KILO_EXPONENT },
        { SI::MEGA_SYMBOL, SI::MEGA_EXPONENT },
        { SI::GIGA_SYMBOL, SI::GIGA_EXPONENT },
        { SI::TERA_SYMBOL, SI::TERA_EXPONENT },
        { SI::PETA_SYMBOL, SI::PETA_EXPONENT },
        { SI::EXA_SYMBOL, SI::EXA_EXPONENT },
        { SI::ZETTA_SYMBOL, SI::ZETTA_EXPONENT },
        { SI::YOTTA_SYMBOL, SI::YOTTA_EXPONENT } };

class Prefix : public generic::Song
{
public:
  /*
   * @brief Get the symbol for a prefix value.
   * @param prefix_value The exponent value of the prefix.
   * @return The symbol corresponding to the prefix value.
   */
  static std::string get_symbol (int prefix_value);
  /*
   * @brief Get the exponent value for a prefix symbol.
   * @param prefix_symbol The symbol of the prefix.
   * @return The exponent value corresponding to the prefix symbol.
   */
  static int get_value (std::string prefix_symbol);
  /*
   * @brief Check if a prefix symbol is valid.
   * @param prefix_symbol The symbol of the prefix.
   * @return True if the prefix is valid
   */
  static bool is_valid (std::string prefix_symbol);
  /*
   * @brief Multiply two prefixes together.
   * @param first_prefix The first prefix symbol.
   * @param second_prefix The second prefix symbol.
   * @param scale_factor The scale factor to apply.
   * @return A pair containing the resulting prefix symbol and scale factor.
   */
  static std::pair<double, std::string>
  prefix_multiplication (std::string first_prefix,
                         std::string second_prefix,
                         double      scale_factor);
};
}
}
} // namespace falcon_core
