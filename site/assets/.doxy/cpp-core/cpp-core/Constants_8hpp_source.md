

# File Constants.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**Constants.hpp**](Constants_8hpp.md)

[Go to the documentation of this file](Constants_8hpp.md)


```C++
#pragma once

#include <map>
#include <string>
namespace falcon_core {

// Mathematical and physical constants for unit conversions and calculations

extern const double PI;
extern const double ELECTRON_CHARGE;
extern const double CELSIUS_OFFSET;
extern const double FAHRENHEIT_OFFSET;
extern const int    SECONDS_PER_MINUTE;
extern const int    MINUTES_PER_HOUR;
extern const double UNIT_SCALE_FAHRENHEIT;

// SI prefix values
namespace SI {
extern const int YOCTO_EXPONENT;
extern const int ZEPTO_EXPONENT;
extern const int ATTO_EXPONENT;
extern const int FEMTO_EXPONENT;
extern const int PICO_EXPONENT;
extern const int NANO_EXPONENT;
extern const int MICRO_EXPONENT;
extern const int MILLI_EXPONENT;
extern const int CENTI_EXPONENT;
extern const int UNIT_EXPONENT;
extern const int HECTO_EXPONENT;
extern const int KILO_EXPONENT;
extern const int MEGA_EXPONENT;
extern const int GIGA_EXPONENT;
extern const int TERA_EXPONENT;
extern const int PETA_EXPONENT;
extern const int EXA_EXPONENT;
extern const int ZETTA_EXPONENT;
extern const int YOTTA_EXPONENT;

// SI prefix symbols
extern const char* const YOCTO_SYMBOL;
extern const char* const ZEPTO_SYMBOL;
extern const char* const ATTO_SYMBOL;
extern const char* const FEMTO_SYMBOL;
extern const char* const PICO_SYMBOL;
extern const char* const NANO_SYMBOL;
extern const char* const MICRO_SYMBOL;
extern const char* const MILLI_SYMBOL;
extern const char* const CENTI_SYMBOL;
extern const char* const UNIT_SYMBOL;
extern const char* const HECTO_SYMBOL;
extern const char* const KILO_SYMBOL;
extern const char* const MEGA_SYMBOL;
extern const char* const GIGA_SYMBOL;
extern const char* const TERA_SYMBOL;
extern const char* const PETA_SYMBOL;
extern const char* const EXA_SYMBOL;
extern const char* const ZETTA_SYMBOL;
extern const char* const YOTTA_SYMBOL;

extern const char* const ALL_PREFIXES[19];

// Physical dimension constants
extern const char* const DIMENSION_LENGTH;
extern const char* const DIMENSION_MASS;
extern const char* const DIMENSION_TIME;
extern const char* const DIMENSION_CURRENT;
extern const char* const DIMENSION_TEMPERATURE;
extern const char* const DIMENSION_AMOUNT;
extern const char* const DIMENSION_LUMINOSITY;

// Set of all valid dimensions
extern const char* const ALL_DIMENSIONS[7];

// The following (maps and std::string objects) cannot be extern const char*:
extern const std::map<std::string, int> DIMENSIONS_DIMENSIONLESS;
extern const std::map<std::string, int> DIMENSIONS_METER;
extern const std::map<std::string, int> DIMENSIONS_KILOGRAM;
extern const std::map<std::string, int> DIMENSIONS_SECOND;
extern const std::map<std::string, int> DIMENSIONS_AMPERE;
extern const std::map<std::string, int> DIMENSIONS_KELVIN;
extern const std::map<std::string, int> DIMENSIONS_MOLE;
extern const std::map<std::string, int> DIMENSIONS_CANDELA;
extern const std::map<std::string, int> DIMENSIONS_HERTZ;
extern const std::map<std::string, int> DIMENSIONS_NEWTON;
extern const std::map<std::string, int> DIMENSIONS_PASCAL;
extern const std::map<std::string, int> DIMENSIONS_JOULE;
extern const std::map<std::string, int> DIMENSIONS_WATT;
extern const std::map<std::string, int> DIMENSIONS_COULOMB;
extern const std::map<std::string, int> DIMENSIONS_VOLT;
extern const std::map<std::string, int> DIMENSIONS_FARAD;
extern const std::map<std::string, int> DIMENSIONS_OHM;
extern const std::map<std::string, int> DIMENSIONS_SIEMENS;
extern const std::map<std::string, int> DIMENSIONS_WEBER;
extern const std::map<std::string, int> DIMENSIONS_TESLA;
extern const std::map<std::string, int> DIMENSIONS_HENRY;

// Unit symbols
extern const char* const UNIT_SYMBOL_METER;
extern const char* const UNIT_SYMBOL_KILOGRAM;
extern const char* const UNIT_SYMBOL_SECOND;
extern const char* const UNIT_SYMBOL_AMPERE;
extern const char* const UNIT_SYMBOL_KELVIN;
extern const char* const UNIT_SYMBOL_MOLE;
extern const char* const UNIT_SYMBOL_CANDELA;
extern const char* const UNIT_SYMBOL_HERTZ;
extern const char* const UNIT_SYMBOL_NEWTON;
extern const char* const UNIT_SYMBOL_PASCAL;
extern const char* const UNIT_SYMBOL_JOULE;
extern const char* const UNIT_SYMBOL_WATT;
extern const char* const UNIT_SYMBOL_COULOMB;
extern const char* const UNIT_SYMBOL_VOLT;
extern const char* const UNIT_SYMBOL_FARAD;
extern const char* const UNIT_SYMBOL_OHM;
extern const char* const UNIT_SYMBOL_SIEMENS;
extern const char* const UNIT_SYMBOL_WEBER;
extern const char* const UNIT_SYMBOL_TESLA;
extern const char* const UNIT_SYMBOL_HENRY;
extern const char* const UNIT_SYMBOL_MINUTE;
extern const char* const UNIT_SYMBOL_HOUR;
extern const char* const UNIT_SYMBOL_ELECTRON_VOLT;
extern const char* const UNIT_SYMBOL_CELSIUS;
extern const char* const UNIT_SYMBOL_FAHRENHEIT;
extern const char* const UNIT_SYMBOL_PERCENT;
extern const char* const UNIT_SYMBOL_RADIAN;

// Unit names
extern const char* const UNIT_NAME_METER;
extern const char* const UNIT_NAME_KILOGRAM;
extern const char* const UNIT_NAME_SECOND;
extern const char* const UNIT_NAME_AMPERE;
extern const char* const UNIT_NAME_KELVIN;
extern const char* const UNIT_NAME_MOLE;
extern const char* const UNIT_NAME_CANDELA;
extern const char* const UNIT_NAME_HERTZ;
extern const char* const UNIT_NAME_NEWTON;
extern const char* const UNIT_NAME_PASCAL;
extern const char* const UNIT_NAME_JOULE;
extern const char* const UNIT_NAME_WATT;
extern const char* const UNIT_NAME_COULOMB;
extern const char* const UNIT_NAME_VOLT;
extern const char* const UNIT_NAME_FARAD;
extern const char* const UNIT_NAME_OHM;
extern const char* const UNIT_NAME_SIEMENS;
extern const char* const UNIT_NAME_WEBER;
extern const char* const UNIT_NAME_TESLA;
extern const char* const UNIT_NAME_HENRY;
extern const char* const UNIT_NAME_MINUTE;
extern const char* const UNIT_NAME_HOUR;
extern const char* const UNIT_NAME_ELECTRON_VOLT;
extern const char* const UNIT_NAME_CELSIUS;
extern const char* const UNIT_NAME_FAHRENHEIT;
extern const char* const UNIT_NAME_DIMENSIONLESS;
extern const char* const UNIT_NAME_PERCENT;
extern const char* const UNIT_NAME_RADIAN;
}  // namespace SI

namespace INSTRUMENT_TYPES {
extern const char* const DC_VOLTAGE_SOURCE;
extern const char* const AMNMETER;
extern const char* const MAGNET;
extern const char* const LOCKIN;
extern const char* const VOLTAGE_SOURCE;
extern const char* const CURRENT_SOURCE;
extern const char* const HF_VOLTAGE_SOURCE;
extern const char* const DC_CURRENT_SOURCE;
extern const char* const HF_CURRENT_SOURCE;
extern const char* const THERMOMETER;
extern const char* const VOLTMETER;
extern const char* const FPGA;
extern const char* const CLOCK;
extern const char* const DISCRETE;
}  // namespace INSTRUMENT_TYPES

}  // namespace falcon_core
```


