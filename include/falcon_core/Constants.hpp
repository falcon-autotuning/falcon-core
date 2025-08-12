#pragma once

#include <map>
#include <string>

// Mathematical and physical constants for unit conversions and calculations

// The mathematical constant pi (π), ratio of a circle's circumference to its
// diameter
constexpr double PI = 3.14159265358979323846;

// The elementary charge (Coulombs), charge of a single proton
constexpr double ELECTRON_CHARGE = 1.602176634e-19;

// The offset to convert Celsius to Kelvin (add to Celsius temperature to get
// Kelvin)
constexpr double CELSIUS_OFFSET = 273.15;

// The offset to convert Fahrenheit to Rankine (add to Fahrenheit temperature
// to get Rankine)
constexpr double FAHRENHEIT_OFFSET = 459.67;

// Number of seconds in one minute
constexpr int SECONDS_PER_MINUTE = 60;

// Number of minutes in one hour
constexpr int MINUTES_PER_HOUR = 60;

// Scale factor for converting Fahrenheit to Celsius: (F - 32) *
// UNIT_SCALE_FAHRENHEIT = C
constexpr double UNIT_SCALE_FAHRENHEIT = 5.0 / 9.0;

// SI prefix values
namespace SI
{
constexpr int YOCTO_EXPONENT = -24;
constexpr int ZEPTO_EXPONENT = -21;
constexpr int ATTO_EXPONENT  = -18;
constexpr int FEMTO_EXPONENT = -15;
constexpr int PICO_EXPONENT  = -12;
constexpr int NANO_EXPONENT  = -9;
constexpr int MICRO_EXPONENT = -6;
constexpr int MILLI_EXPONENT = -3;
constexpr int CENTI_EXPONENT = -2;
constexpr int DECI_EXPONENT  = -1;
constexpr int UNIT_EXPONENT  = 0; // No prefix
constexpr int DECA_EXPONENT  = 1;
constexpr int HECTO_EXPONENT = 2;
constexpr int KILO_EXPONENT  = 3;
constexpr int MEGA_EXPONENT  = 6;
constexpr int GIGA_EXPONENT  = 9;
constexpr int TERA_EXPONENT  = 12;
constexpr int PETA_EXPONENT  = 15;
constexpr int EXA_EXPONENT   = 18;
constexpr int ZETTA_EXPONENT = 21;
constexpr int YOTTA_EXPONENT = 24;
// SI prefix symbols
constexpr const char *YOCTO_SYMBOL = "y";
constexpr const char *ZEPTO_SYMBOL = "z";
constexpr const char *ATTO_SYMBOL  = "a";
constexpr const char *FEMTO_SYMBOL = "f";
constexpr const char *PICO_SYMBOL  = "p";
constexpr const char *NANO_SYMBOL  = "n";
constexpr const char *MICRO_SYMBOL = "μ";
constexpr const char *MILLI_SYMBOL = "m";
constexpr const char *CENTI_SYMBOL = "c";
constexpr const char *DECI_SYMBOL  = "d";
constexpr const char *UNIT_SYMBOL  = ""; // No prefix
constexpr const char *DECA_SYMBOL  = "da";
constexpr const char *HECTO_SYMBOL = "h";
constexpr const char *KILO_SYMBOL  = "k";
constexpr const char *MEGA_SYMBOL  = "M";
constexpr const char *GIGA_SYMBOL  = "G";
constexpr const char *TERA_SYMBOL  = "T";
constexpr const char *PETA_SYMBOL  = "P";
constexpr const char *EXA_SYMBOL   = "E";
constexpr const char *ZETTA_SYMBOL = "Z";
constexpr const char *YOTTA_SYMBOL = "Y";

constexpr const char *ALL_PREFIXES[]
    = { YOCTO_SYMBOL, ZEPTO_SYMBOL, ATTO_SYMBOL,  FEMTO_SYMBOL, PICO_SYMBOL,
        NANO_SYMBOL,  MICRO_SYMBOL, MILLI_SYMBOL, CENTI_SYMBOL, DECI_SYMBOL,
        UNIT_SYMBOL,  DECA_SYMBOL,  HECTO_SYMBOL, KILO_SYMBOL,  MEGA_SYMBOL,
        GIGA_SYMBOL,  TERA_SYMBOL,  PETA_SYMBOL,  EXA_SYMBOL,   ZETTA_SYMBOL,
        YOTTA_SYMBOL };
// Physical dimension constants
constexpr const char *DIMENSION_LENGTH      = "LENGTH";
constexpr const char *DIMENSION_MASS        = "MASS";
constexpr const char *DIMENSION_TIME        = "TIME";
constexpr const char *DIMENSION_CURRENT     = "CURRENT";
constexpr const char *DIMENSION_TEMPERATURE = "TEMPERATURE";
constexpr const char *DIMENSION_AMOUNT      = "AMOUNT";
constexpr const char *DIMENSION_LUMINOSITY  = "LUMINOSITY";

// Set of all valid dimensions
constexpr const char *ALL_DIMENSIONS[]
    = { DIMENSION_LENGTH,    DIMENSION_MASS,        DIMENSION_TIME,
        DIMENSION_CURRENT,   DIMENSION_TEMPERATURE, DIMENSION_AMOUNT,
        DIMENSION_LUMINOSITY };
// Unit dimensions dictionaries - centralize the dimensional relationships
const std::map<std::string, int> DIMENSIONS_DIMENSIONLESS = {};

const std::map<std::string, int> DIMENSIONS_METER
    = { { DIMENSION_LENGTH, 1 } };

const std::map<std::string, int> DIMENSIONS_KILOGRAM
    = { { DIMENSION_MASS, 1 } };

const std::map<std::string, int> DIMENSIONS_SECOND = { { DIMENSION_TIME, 1 } };

const std::map<std::string, int> DIMENSIONS_AMPERE
    = { { DIMENSION_CURRENT, 1 } };

const std::map<std::string, int> DIMENSIONS_KELVIN
    = { { DIMENSION_TEMPERATURE, 1 } };

const std::map<std::string, int> DIMENSIONS_MOLE = { { DIMENSION_AMOUNT, 1 } };

const std::map<std::string, int> DIMENSIONS_CANDELA
    = { { DIMENSION_LUMINOSITY, 1 } };

const std::map<std::string, int> DIMENSIONS_HERTZ = { { DIMENSION_TIME, -1 } };

const std::map<std::string, int> DIMENSIONS_NEWTON = {
  { DIMENSION_MASS, 1 }, { DIMENSION_LENGTH, 1 }, { DIMENSION_TIME, -2 }
};

const std::map<std::string, int> DIMENSIONS_PASCAL = {
  { DIMENSION_MASS, 1 }, { DIMENSION_LENGTH, -1 }, { DIMENSION_TIME, -2 }
};

const std::map<std::string, int> DIMENSIONS_JOULE = { { DIMENSION_MASS, 1 },
                                                      { DIMENSION_LENGTH, 2 },
                                                      { DIMENSION_TIME, -2 } };

const std::map<std::string, int> DIMENSIONS_WATT = { { DIMENSION_MASS, 1 },
                                                     { DIMENSION_LENGTH, 2 },
                                                     { DIMENSION_TIME, -3 } };

const std::map<std::string, int> DIMENSIONS_COULOMB
    = { { DIMENSION_TIME, 1 }, { DIMENSION_CURRENT, 1 } };

const std::map<std::string, int> DIMENSIONS_VOLT
    = { { DIMENSION_MASS, 1 },
        { DIMENSION_LENGTH, 2 },
        { DIMENSION_TIME, -3 },
        { DIMENSION_CURRENT, -1 } };

const std::map<std::string, int> DIMENSIONS_FARAD
    = { { DIMENSION_MASS, -1 },
        { DIMENSION_LENGTH, -2 },
        { DIMENSION_TIME, 4 },
        { DIMENSION_CURRENT, 2 } };

const std::map<std::string, int> DIMENSIONS_OHM
    = { { DIMENSION_MASS, 1 },
        { DIMENSION_LENGTH, 2 },
        { DIMENSION_TIME, -3 },
        { DIMENSION_CURRENT, -2 } };

const std::map<std::string, int> DIMENSIONS_SIEMENS
    = { { DIMENSION_MASS, -1 },
        { DIMENSION_LENGTH, -2 },
        { DIMENSION_TIME, 3 },
        { DIMENSION_CURRENT, 2 } };

const std::map<std::string, int> DIMENSIONS_WEBER
    = { { DIMENSION_MASS, 1 },
        { DIMENSION_LENGTH, 2 },
        { DIMENSION_TIME, -2 },
        { DIMENSION_CURRENT, -1 } };

const std::map<std::string, int> DIMENSIONS_TESLA = {
  { DIMENSION_MASS, 1 }, { DIMENSION_TIME, -2 }, { DIMENSION_CURRENT, -1 }
};

const std::map<std::string, int> DIMENSIONS_HENRY
    = { { DIMENSION_MASS, 1 },
        { DIMENSION_LENGTH, 2 },
        { DIMENSION_TIME, -2 },
        { DIMENSION_CURRENT, -2 } };
// Unit symbols
constexpr const char *UNIT_SYMBOL_METER         = "m";
constexpr const char *UNIT_SYMBOL_KILOGRAM      = "kg";
constexpr const char *UNIT_SYMBOL_SECOND        = "s";
constexpr const char *UNIT_SYMBOL_AMPERE        = "A";
constexpr const char *UNIT_SYMBOL_KELVIN        = "K";
constexpr const char *UNIT_SYMBOL_MOLE          = "mol";
constexpr const char *UNIT_SYMBOL_CANDELA       = "cd";
constexpr const char *UNIT_SYMBOL_HERTZ         = "Hz";
constexpr const char *UNIT_SYMBOL_NEWTON        = "N";
constexpr const char *UNIT_SYMBOL_PASCAL        = "Pa";
constexpr const char *UNIT_SYMBOL_JOULE         = "J";
constexpr const char *UNIT_SYMBOL_WATT          = "W";
constexpr const char *UNIT_SYMBOL_COULOMB       = "C";
constexpr const char *UNIT_SYMBOL_VOLT          = "V";
constexpr const char *UNIT_SYMBOL_FARAD         = "F";
constexpr const char *UNIT_SYMBOL_OHM           = "Ω";
constexpr const char *UNIT_SYMBOL_SIEMENS       = "S";
constexpr const char *UNIT_SYMBOL_WEBER         = "Wb";
constexpr const char *UNIT_SYMBOL_TESLA         = "T";
constexpr const char *UNIT_SYMBOL_HENRY         = "H";
constexpr const char *UNIT_SYMBOL_MINUTE        = "min";
constexpr const char *UNIT_SYMBOL_HOUR          = "h";
constexpr const char *UNIT_SYMBOL_ELECTRON_VOLT = "eV";
constexpr const char *UNIT_SYMBOL_CELSIUS       = "°C";
constexpr const char *UNIT_SYMBOL_FAHRENHEIT    = "°F";
constexpr const char *UNIT_SYMBOL_PERCENT       = "%";
constexpr const char *UNIT_SYMBOL_RADIAN        = "rad";

// Unit names
constexpr const char *UNIT_NAME_METER         = "meter";
constexpr const char *UNIT_NAME_KILOGRAM      = "kilogram";
constexpr const char *UNIT_NAME_SECOND        = "second";
constexpr const char *UNIT_NAME_AMPERE        = "ampere";
constexpr const char *UNIT_NAME_KELVIN        = "kelvin";
constexpr const char *UNIT_NAME_MOLE          = "mole";
constexpr const char *UNIT_NAME_CANDELA       = "candela";
constexpr const char *UNIT_NAME_HERTZ         = "hertz";
constexpr const char *UNIT_NAME_NEWTON        = "newton";
constexpr const char *UNIT_NAME_PASCAL        = "pascal";
constexpr const char *UNIT_NAME_JOULE         = "joule";
constexpr const char *UNIT_NAME_WATT          = "watt";
constexpr const char *UNIT_NAME_COULOMB       = "coulomb";
constexpr const char *UNIT_NAME_VOLT          = "volt";
constexpr const char *UNIT_NAME_FARAD         = "farad";
constexpr const char *UNIT_NAME_OHM           = "ohm";
constexpr const char *UNIT_NAME_SIEMENS       = "siemens";
constexpr const char *UNIT_NAME_WEBER         = "weber";
constexpr const char *UNIT_NAME_TESLA         = "tesla";
constexpr const char *UNIT_NAME_HENRY         = "henry";
constexpr const char *UNIT_NAME_MINUTE        = "minute";
constexpr const char *UNIT_NAME_HOUR          = "hour";
constexpr const char *UNIT_NAME_ELECTRON_VOLT = "electron-volt";
constexpr const char *UNIT_NAME_CELSIUS       = "celsius";
constexpr const char *UNIT_NAME_FAHRENHEIT    = "fahrenheit";
constexpr const char *UNIT_NAME_DIMENSIONLESS = "dimensionless";
constexpr const char *UNIT_NAME_PERCENT       = "percent";
constexpr const char *UNIT_NAME_RADIAN        = "radian";
}

/**
 * @namespace INSTRUMENT_TYPES
 * @brief Different Instrument types supported by falcon software.
 */
namespace INSTRUMENT_TYPES
{
constexpr const char *DC_VOLTAGE_SOURCE = "dc_voltage_source";
constexpr const char *AMNMETER          = "amnmeter";
constexpr const char *MAGNET            = "magnet";
constexpr const char *LOCKIN            = "lockin";
constexpr const char *VOLTAGE_SOURCE    = "voltage_source";
constexpr const char *CURRENT_SOURCE    = "current_source";
constexpr const char *HF_VOLTAGE_SOURCE = "hf_voltage_source";
constexpr const char *DC_CURRENT_SOURCE = "dc_current_source";
constexpr const char *HF_CURRENT_SOURCE = "hf_current_source";
constexpr const char *THERMOMETER       = "thermometer";
constexpr const char *VOLTMETER         = "voltmeter";
constexpr const char *FPGA              = "fpga";
constexpr const char *CLOCK             = "clock";
constexpr const char *DISCRETE          = "discrete";
}
