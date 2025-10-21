#include "falcon_core/Constants.hpp"

namespace falcon_core {
// Mathematical and physical constants for unit conversions and calculations

const double PI                    = 3.14159265358979323846;
const double ELECTRON_CHARGE       = 1.602176634e-19;
const double CELSIUS_OFFSET        = 273.15;
const double FAHRENHEIT_OFFSET     = 459.67;
const int    SECONDS_PER_MINUTE    = 60;
const int    MINUTES_PER_HOUR      = 60;
const double UNIT_SCALE_FAHRENHEIT = 5.0 / 9.0;

// SI prefix values
namespace SI {
const int YOCTO_EXPONENT = -24;
const int ZEPTO_EXPONENT = -21;
const int ATTO_EXPONENT  = -18;
const int FEMTO_EXPONENT = -15;
const int PICO_EXPONENT  = -12;
const int NANO_EXPONENT  = -9;
const int MICRO_EXPONENT = -6;
const int MILLI_EXPONENT = -3;
const int CENTI_EXPONENT = -2;
const int UNIT_EXPONENT  = 0;  // No prefix
const int HECTO_EXPONENT = 2;
const int KILO_EXPONENT  = 3;
const int MEGA_EXPONENT  = 6;
const int GIGA_EXPONENT  = 9;
const int TERA_EXPONENT  = 12;
const int PETA_EXPONENT  = 15;
const int EXA_EXPONENT   = 18;
const int ZETTA_EXPONENT = 21;
const int YOTTA_EXPONENT = 24;

// SI prefix symbols
const char* const YOCTO_SYMBOL = "y";
const char* const ZEPTO_SYMBOL = "z";
const char* const ATTO_SYMBOL  = "a";
const char* const FEMTO_SYMBOL = "f";
const char* const PICO_SYMBOL  = "p";
const char* const NANO_SYMBOL  = "n";
const char* const MICRO_SYMBOL = "μ";
const char* const MILLI_SYMBOL = "m";
const char* const CENTI_SYMBOL = "c";
const char* const UNIT_SYMBOL  = "";  // No prefix
const char* const HECTO_SYMBOL = "h";
const char* const KILO_SYMBOL  = "k";
const char* const MEGA_SYMBOL  = "M";
const char* const GIGA_SYMBOL  = "G";
const char* const TERA_SYMBOL  = "T";
const char* const PETA_SYMBOL  = "P";
const char* const EXA_SYMBOL   = "E";
const char* const ZETTA_SYMBOL = "Z";
const char* const YOTTA_SYMBOL = "Y";

const char* const ALL_PREFIXES[] = {YOCTO_SYMBOL,
                                    ZEPTO_SYMBOL,
                                    ATTO_SYMBOL,
                                    FEMTO_SYMBOL,
                                    PICO_SYMBOL,
                                    NANO_SYMBOL,
                                    MICRO_SYMBOL,
                                    MILLI_SYMBOL,
                                    CENTI_SYMBOL,
                                    UNIT_SYMBOL,
                                    HECTO_SYMBOL,
                                    KILO_SYMBOL,
                                    MEGA_SYMBOL,
                                    GIGA_SYMBOL,
                                    TERA_SYMBOL,
                                    PETA_SYMBOL,
                                    EXA_SYMBOL,
                                    ZETTA_SYMBOL,
                                    YOTTA_SYMBOL};

// Physical dimension constants
const char* const DIMENSION_LENGTH      = "LENGTH";
const char* const DIMENSION_MASS        = "MASS";
const char* const DIMENSION_TIME        = "TIME";
const char* const DIMENSION_CURRENT     = "CURRENT";
const char* const DIMENSION_TEMPERATURE = "TEMPERATURE";
const char* const DIMENSION_AMOUNT      = "AMOUNT";
const char* const DIMENSION_LUMINOSITY  = "LUMINOSITY";

// Set of all valid dimensions
const char* const ALL_DIMENSIONS[] = {DIMENSION_LENGTH,
                                      DIMENSION_MASS,
                                      DIMENSION_TIME,
                                      DIMENSION_CURRENT,
                                      DIMENSION_TEMPERATURE,
                                      DIMENSION_AMOUNT,
                                      DIMENSION_LUMINOSITY};

// The following (maps and std::string objects) cannot be  const char*:
const std::map<std::string, int> DIMENSIONS_DIMENSIONLESS = {};
const std::map<std::string, int> DIMENSIONS_METER    = {{DIMENSION_LENGTH, 1}};
const std::map<std::string, int> DIMENSIONS_KILOGRAM = {{DIMENSION_MASS, 1}};
const std::map<std::string, int> DIMENSIONS_SECOND   = {{DIMENSION_TIME, 1}};
const std::map<std::string, int> DIMENSIONS_AMPERE   = {{DIMENSION_CURRENT, 1}};
const std::map<std::string, int> DIMENSIONS_KELVIN   = {
    {DIMENSION_TEMPERATURE, 1}};
const std::map<std::string, int> DIMENSIONS_MOLE    = {{DIMENSION_AMOUNT, 1}};
const std::map<std::string, int> DIMENSIONS_CANDELA = {
    {DIMENSION_LUMINOSITY, 1}};
const std::map<std::string, int> DIMENSIONS_HERTZ  = {{DIMENSION_TIME, -1}};
const std::map<std::string, int> DIMENSIONS_NEWTON = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, 1}, {DIMENSION_TIME, -2}};
const std::map<std::string, int> DIMENSIONS_PASCAL = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, -1}, {DIMENSION_TIME, -2}};
const std::map<std::string, int> DIMENSIONS_JOULE = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, 2}, {DIMENSION_TIME, -2}};
const std::map<std::string, int> DIMENSIONS_WATT = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, 2}, {DIMENSION_TIME, -3}};
const std::map<std::string, int> DIMENSIONS_COULOMB = {{DIMENSION_TIME, 1},
                                                       {DIMENSION_CURRENT, 1}};
const std::map<std::string, int> DIMENSIONS_VOLT    = {{DIMENSION_MASS, 1},
                                                       {DIMENSION_LENGTH, 2},
                                                       {DIMENSION_TIME, -3},
                                                       {DIMENSION_CURRENT, -1}};
const std::map<std::string, int> DIMENSIONS_FARAD   = {{DIMENSION_MASS, -1},
                                                       {DIMENSION_LENGTH, -2},
                                                       {DIMENSION_TIME, 4},
                                                       {DIMENSION_CURRENT, 2}};
const std::map<std::string, int> DIMENSIONS_OHM     = {{DIMENSION_MASS, 1},
                                                       {DIMENSION_LENGTH, 2},
                                                       {DIMENSION_TIME, -3},
                                                       {DIMENSION_CURRENT, -2}};
const std::map<std::string, int> DIMENSIONS_SIEMENS = {{DIMENSION_MASS, -1},
                                                       {DIMENSION_LENGTH, -2},
                                                       {DIMENSION_TIME, 3},
                                                       {DIMENSION_CURRENT, 2}};
const std::map<std::string, int> DIMENSIONS_WEBER   = {{DIMENSION_MASS, 1},
                                                       {DIMENSION_LENGTH, 2},
                                                       {DIMENSION_TIME, -2},
                                                       {DIMENSION_CURRENT, -1}};
const std::map<std::string, int> DIMENSIONS_TESLA   = {
    {DIMENSION_MASS, 1}, {DIMENSION_TIME, -2}, {DIMENSION_CURRENT, -1}};
const std::map<std::string, int> DIMENSIONS_HENRY = {{DIMENSION_MASS, 1},
                                                     {DIMENSION_LENGTH, 2},
                                                     {DIMENSION_TIME, -2},
                                                     {DIMENSION_CURRENT, -2}};

// Unit symbols
const char* const UNIT_SYMBOL_METER         = "m";
const char* const UNIT_SYMBOL_KILOGRAM      = "kg";
const char* const UNIT_SYMBOL_SECOND        = "s";
const char* const UNIT_SYMBOL_AMPERE        = "A";
const char* const UNIT_SYMBOL_KELVIN        = "K";
const char* const UNIT_SYMBOL_MOLE          = "mol";
const char* const UNIT_SYMBOL_CANDELA       = "cd";
const char* const UNIT_SYMBOL_HERTZ         = "Hz";
const char* const UNIT_SYMBOL_NEWTON        = "N";
const char* const UNIT_SYMBOL_PASCAL        = "Pa";
const char* const UNIT_SYMBOL_JOULE         = "J";
const char* const UNIT_SYMBOL_WATT          = "W";
const char* const UNIT_SYMBOL_COULOMB       = "C";
const char* const UNIT_SYMBOL_VOLT          = "V";
const char* const UNIT_SYMBOL_FARAD         = "F";
const char* const UNIT_SYMBOL_OHM           = "Ω";
const char* const UNIT_SYMBOL_SIEMENS       = "S";
const char* const UNIT_SYMBOL_WEBER         = "Wb";
const char* const UNIT_SYMBOL_TESLA         = "T";
const char* const UNIT_SYMBOL_HENRY         = "H";
const char* const UNIT_SYMBOL_MINUTE        = "min";
const char* const UNIT_SYMBOL_HOUR          = "h";
const char* const UNIT_SYMBOL_ELECTRON_VOLT = "eV";
const char* const UNIT_SYMBOL_CELSIUS       = "°C";
const char* const UNIT_SYMBOL_FAHRENHEIT    = "°F";
const char* const UNIT_SYMBOL_PERCENT       = "%";
const char* const UNIT_SYMBOL_RADIAN        = "rad";

// Unit names
const char* const UNIT_NAME_METER         = "meter";
const char* const UNIT_NAME_KILOGRAM      = "kilogram";
const char* const UNIT_NAME_SECOND        = "second";
const char* const UNIT_NAME_AMPERE        = "ampere";
const char* const UNIT_NAME_KELVIN        = "kelvin";
const char* const UNIT_NAME_MOLE          = "mole";
const char* const UNIT_NAME_CANDELA       = "candela";
const char* const UNIT_NAME_HERTZ         = "hertz";
const char* const UNIT_NAME_NEWTON        = "newton";
const char* const UNIT_NAME_PASCAL        = "pascal";
const char* const UNIT_NAME_JOULE         = "joule";
const char* const UNIT_NAME_WATT          = "watt";
const char* const UNIT_NAME_COULOMB       = "coulomb";
const char* const UNIT_NAME_VOLT          = "volt";
const char* const UNIT_NAME_FARAD         = "farad";
const char* const UNIT_NAME_OHM           = "ohm";
const char* const UNIT_NAME_SIEMENS       = "siemens";
const char* const UNIT_NAME_WEBER         = "weber";
const char* const UNIT_NAME_TESLA         = "tesla";
const char* const UNIT_NAME_HENRY         = "henry";
const char* const UNIT_NAME_MINUTE        = "minute";
const char* const UNIT_NAME_HOUR          = "hour";
const char* const UNIT_NAME_ELECTRON_VOLT = "electron-volt";
const char* const UNIT_NAME_CELSIUS       = "celsius";
const char* const UNIT_NAME_FAHRENHEIT    = "fahrenheit";
const char* const UNIT_NAME_DIMENSIONLESS = "dimensionless";
const char* const UNIT_NAME_PERCENT       = "percent";
const char* const UNIT_NAME_RADIAN        = "radian";
}  // namespace SI

/**
 * @namespace INSTRUMENT_TYPES
 * @brief Different Instrument types supported by falcon software.
 */
namespace INSTRUMENT_TYPES {
const char* const DC_VOLTAGE_SOURCE = "dc_voltage_source";
const char* const AMNMETER          = "amnmeter";
const char* const MAGNET            = "magnet";
const char* const LOCKIN            = "lockin";
const char* const VOLTAGE_SOURCE    = "voltage_source";
const char* const CURRENT_SOURCE    = "current_source";
const char* const HF_VOLTAGE_SOURCE = "hf_voltage_source";
const char* const DC_CURRENT_SOURCE = "dc_current_source";
const char* const HF_CURRENT_SOURCE = "hf_current_source";
const char* const THERMOMETER       = "thermometer";
const char* const VOLTMETER         = "voltmeter";
const char* const FPGA              = "fpga";
const char* const CLOCK             = "clock";
const char* const DISCRETE          = "discrete";
}  // namespace INSTRUMENT_TYPES

}  // namespace falcon_core
