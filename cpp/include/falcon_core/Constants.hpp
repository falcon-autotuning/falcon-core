#pragma once

#include <map>
#include <string>

#include "falcon_core/export.h"
namespace falcon_core {

// Mathematical and physical constants for unit conversions and calculations

extern FALCON_CORE_CPP_API const double PI;
extern FALCON_CORE_CPP_API const double ELECTRON_CHARGE;
extern FALCON_CORE_CPP_API const double CELSIUS_OFFSET;
extern FALCON_CORE_CPP_API const double FAHRENHEIT_OFFSET;
extern FALCON_CORE_CPP_API const double UNIT_SCALE_FAHRENHEIT;
extern FALCON_CORE_CPP_API const int    SECONDS_PER_MINUTE;
extern FALCON_CORE_CPP_API const int    MINUTES_PER_HOUR;

// SI prefix values
namespace SI {
extern FALCON_CORE_CPP_API const int YOCTO_EXPONENT;
extern FALCON_CORE_CPP_API const int ZEPTO_EXPONENT;
extern FALCON_CORE_CPP_API const int ATTO_EXPONENT;
extern FALCON_CORE_CPP_API const int FEMTO_EXPONENT;
extern FALCON_CORE_CPP_API const int PICO_EXPONENT;
extern FALCON_CORE_CPP_API const int NANO_EXPONENT;
extern FALCON_CORE_CPP_API const int MICRO_EXPONENT;
extern FALCON_CORE_CPP_API const int MILLI_EXPONENT;
extern FALCON_CORE_CPP_API const int CENTI_EXPONENT;
extern FALCON_CORE_CPP_API const int UNIT_EXPONENT;
extern FALCON_CORE_CPP_API const int HECTO_EXPONENT;
extern FALCON_CORE_CPP_API const int KILO_EXPONENT;
extern FALCON_CORE_CPP_API const int MEGA_EXPONENT;
extern FALCON_CORE_CPP_API const int GIGA_EXPONENT;
extern FALCON_CORE_CPP_API const int TERA_EXPONENT;
extern FALCON_CORE_CPP_API const int PETA_EXPONENT;
extern FALCON_CORE_CPP_API const int EXA_EXPONENT;
extern FALCON_CORE_CPP_API const int ZETTA_EXPONENT;
extern FALCON_CORE_CPP_API const int YOTTA_EXPONENT;

// SI prefix symbols
extern FALCON_CORE_CPP_API const char* const YOCTO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const ZEPTO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const ATTO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const FEMTO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const PICO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const NANO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const MICRO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const MILLI_SYMBOL;
extern FALCON_CORE_CPP_API const char* const CENTI_SYMBOL;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL;
extern FALCON_CORE_CPP_API const char* const HECTO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const KILO_SYMBOL;
extern FALCON_CORE_CPP_API const char* const MEGA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const GIGA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const TERA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const PETA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const EXA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const ZETTA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const YOTTA_SYMBOL;
extern FALCON_CORE_CPP_API const char* const ALL_PREFIXES[19];

// Physical dimension constants
extern FALCON_CORE_CPP_API const char* const DIMENSION_LENGTH;
extern FALCON_CORE_CPP_API const char* const DIMENSION_MASS;
extern FALCON_CORE_CPP_API const char* const DIMENSION_TIME;
extern FALCON_CORE_CPP_API const char* const DIMENSION_CURRENT;
extern FALCON_CORE_CPP_API const char* const DIMENSION_TEMPERATURE;
extern FALCON_CORE_CPP_API const char* const DIMENSION_AMOUNT;
extern FALCON_CORE_CPP_API const char* const DIMENSION_LUMINOSITY;

// Set of all valid dimensions
extern FALCON_CORE_CPP_API const char* const ALL_DIMENSIONS[7];

// The following (maps and std::string objects) cannot be extern const char*:
extern FALCON_CORE_CPP_API const std::map<std::string, int>
                                 DIMENSIONS_DIMENSIONLESS;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_METER;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_KILOGRAM;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_SECOND;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_AMPERE;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_KELVIN;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_MOLE;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_CANDELA;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_HERTZ;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_NEWTON;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_PASCAL;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_JOULE;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_WATT;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_COULOMB;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_VOLT;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_FARAD;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_OHM;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_SIEMENS;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_WEBER;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_TESLA;
extern FALCON_CORE_CPP_API const std::map<std::string, int> DIMENSIONS_HENRY;

// Unit symbols
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_METER;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_KILOGRAM;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_SECOND;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_AMPERE;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_KELVIN;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_MOLE;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_CANDELA;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_HERTZ;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_NEWTON;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_PASCAL;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_JOULE;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_WATT;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_COULOMB;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_VOLT;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_FARAD;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_OHM;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_SIEMENS;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_WEBER;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_TESLA;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_HENRY;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_MINUTE;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_HOUR;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_ELECTRON_VOLT;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_CELSIUS;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_FAHRENHEIT;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_PERCENT;
extern FALCON_CORE_CPP_API const char* const UNIT_SYMBOL_RADIAN;

// Unit names
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_METER;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_KILOGRAM;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_SECOND;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_AMPERE;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_KELVIN;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_MOLE;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_CANDELA;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_HERTZ;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_NEWTON;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_PASCAL;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_JOULE;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_WATT;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_COULOMB;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_VOLT;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_FARAD;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_OHM;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_SIEMENS;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_WEBER;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_TESLA;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_HENRY;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_MINUTE;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_HOUR;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_ELECTRON_VOLT;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_CELSIUS;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_FAHRENHEIT;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_DIMENSIONLESS;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_PERCENT;
extern FALCON_CORE_CPP_API const char* const UNIT_NAME_RADIAN;
}  // namespace SI

/**
 * @namespace INSTRUMENT_TYPES
 * @brief Different Instrument types supported by falcon software.
 */
namespace INSTRUMENT_TYPES {
extern FALCON_CORE_CPP_API const char* const DC_VOLTAGE_SOURCE;
extern FALCON_CORE_CPP_API const char* const AMNMETER;
extern FALCON_CORE_CPP_API const char* const MAGNET;
extern FALCON_CORE_CPP_API const char* const LOCKIN;
extern FALCON_CORE_CPP_API const char* const VOLTAGE_SOURCE;
extern FALCON_CORE_CPP_API const char* const CURRENT_SOURCE;
extern FALCON_CORE_CPP_API const char* const HF_VOLTAGE_SOURCE;
extern FALCON_CORE_CPP_API const char* const DC_CURRENT_SOURCE;
extern FALCON_CORE_CPP_API const char* const HF_CURRENT_SOURCE;
extern FALCON_CORE_CPP_API const char* const THERMOMETER;
extern FALCON_CORE_CPP_API const char* const VOLTMETER;
extern FALCON_CORE_CPP_API const char* const FPGA;
extern FALCON_CORE_CPP_API const char* const CLOCK;
extern FALCON_CORE_CPP_API const char* const DISCRETE;
}  // namespace INSTRUMENT_TYPES

}  // namespace falcon_core
