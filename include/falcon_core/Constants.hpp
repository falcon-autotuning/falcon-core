#pragma once

#include <map>
#include <string>
namespace falcon_core {
// Mathematical and physical constants for unit conversions and calculations

// The mathematical constant pi (π), ratio of a circle's circumference to its
// diameter
static const double PI = 3.14159265358979323846;

// The elementary charge (Coulombs), charge of a single proton
static const double ELECTRON_CHARGE = 1.602176634e-19;

// The offset to convert Celsius to Kelvin (add to Celsius temperature to get
// Kelvin)
static const double CELSIUS_OFFSET = 273.15;

// The offset to convert Fahrenheit to Rankine (add to Fahrenheit temperature
// to get Rankine)
static const double FAHRENHEIT_OFFSET = 459.67;

// Number of seconds in one minute
static const int SECONDS_PER_MINUTE = 60;

// Number of minutes in one hour
static const int MINUTES_PER_HOUR = 60;

// Scale factor for converting Fahrenheit to Celsius: (F - 32) *
// UNIT_SCALE_FAHRENHEIT = C
static const double UNIT_SCALE_FAHRENHEIT = 5.0 / 9.0;

// SI prefix values
namespace SI {
static const int YOCTO_EXPONENT = -24;
static const int ZEPTO_EXPONENT = -21;
static const int ATTO_EXPONENT  = -18;
static const int FEMTO_EXPONENT = -15;
static const int PICO_EXPONENT  = -12;
static const int NANO_EXPONENT  = -9;
static const int MICRO_EXPONENT = -6;
static const int MILLI_EXPONENT = -3;
static const int CENTI_EXPONENT = -2;
static const int UNIT_EXPONENT  = 0;  // No prefix
static const int HECTO_EXPONENT = 2;
static const int KILO_EXPONENT  = 3;
static const int MEGA_EXPONENT  = 6;
static const int GIGA_EXPONENT  = 9;
static const int TERA_EXPONENT  = 12;
static const int PETA_EXPONENT  = 15;
static const int EXA_EXPONENT   = 18;
static const int ZETTA_EXPONENT = 21;
static const int YOTTA_EXPONENT = 24;
// SI prefix symbols
static const std::string YOCTO_SYMBOL = "y";
static const std::string ZEPTO_SYMBOL = "z";
static const std::string ATTO_SYMBOL  = "a";
static const std::string FEMTO_SYMBOL = "f";
static const std::string PICO_SYMBOL  = "p";
static const std::string NANO_SYMBOL  = "n";
static const std::string MICRO_SYMBOL = "μ";
static const std::string MILLI_SYMBOL = "m";
static const std::string CENTI_SYMBOL = "c";
static const std::string UNIT_SYMBOL  = "";  // No prefix
static const std::string HECTO_SYMBOL = "h";
static const std::string KILO_SYMBOL  = "k";
static const std::string MEGA_SYMBOL  = "M";
static const std::string GIGA_SYMBOL  = "G";
static const std::string TERA_SYMBOL  = "T";
static const std::string PETA_SYMBOL  = "P";
static const std::string EXA_SYMBOL   = "E";
static const std::string ZETTA_SYMBOL = "Z";
static const std::string YOTTA_SYMBOL = "Y";

static const std::string ALL_PREFIXES[] = {YOCTO_SYMBOL,
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
static const std::string DIMENSION_LENGTH      = "LENGTH";
static const std::string DIMENSION_MASS        = "MASS";
static const std::string DIMENSION_TIME        = "TIME";
static const std::string DIMENSION_CURRENT     = "CURRENT";
static const std::string DIMENSION_TEMPERATURE = "TEMPERATURE";
static const std::string DIMENSION_AMOUNT      = "AMOUNT";
static const std::string DIMENSION_LUMINOSITY  = "LUMINOSITY";

// Set of all valid dimensions
static const std::string ALL_DIMENSIONS[] = {DIMENSION_LENGTH,
                                             DIMENSION_MASS,
                                             DIMENSION_TIME,
                                             DIMENSION_CURRENT,
                                             DIMENSION_TEMPERATURE,
                                             DIMENSION_AMOUNT,
                                             DIMENSION_LUMINOSITY};
// Unit dimensions dictionaries - centralize the dimensional relationships
static const std::map<std::string, int> DIMENSIONS_DIMENSIONLESS = {};

static const std::map<std::string, int> DIMENSIONS_METER = {
    {DIMENSION_LENGTH, 1}};

static const std::map<std::string, int> DIMENSIONS_KILOGRAM = {
    {DIMENSION_MASS, 1}};

static const std::map<std::string, int> DIMENSIONS_SECOND = {
    {DIMENSION_TIME, 1}};

static const std::map<std::string, int> DIMENSIONS_AMPERE = {
    {DIMENSION_CURRENT, 1}};

static const std::map<std::string, int> DIMENSIONS_KELVIN = {
    {DIMENSION_TEMPERATURE, 1}};

static const std::map<std::string, int> DIMENSIONS_MOLE = {
    {DIMENSION_AMOUNT, 1}};

static const std::map<std::string, int> DIMENSIONS_CANDELA = {
    {DIMENSION_LUMINOSITY, 1}};

static const std::map<std::string, int> DIMENSIONS_HERTZ = {
    {DIMENSION_TIME, -1}};

static const std::map<std::string, int> DIMENSIONS_NEWTON = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, 1}, {DIMENSION_TIME, -2}};

static const std::map<std::string, int> DIMENSIONS_PASCAL = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, -1}, {DIMENSION_TIME, -2}};

static const std::map<std::string, int> DIMENSIONS_JOULE = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, 2}, {DIMENSION_TIME, -2}};

static const std::map<std::string, int> DIMENSIONS_WATT = {
    {DIMENSION_MASS, 1}, {DIMENSION_LENGTH, 2}, {DIMENSION_TIME, -3}};

static const std::map<std::string, int> DIMENSIONS_COULOMB = {
    {DIMENSION_TIME, 1}, {DIMENSION_CURRENT, 1}};

static const std::map<std::string, int> DIMENSIONS_VOLT = {
    {DIMENSION_MASS, 1},
    {DIMENSION_LENGTH, 2},
    {DIMENSION_TIME, -3},
    {DIMENSION_CURRENT, -1}};

static const std::map<std::string, int> DIMENSIONS_FARAD = {
    {DIMENSION_MASS, -1},
    {DIMENSION_LENGTH, -2},
    {DIMENSION_TIME, 4},
    {DIMENSION_CURRENT, 2}};

static const std::map<std::string, int> DIMENSIONS_OHM = {
    {DIMENSION_MASS, 1},
    {DIMENSION_LENGTH, 2},
    {DIMENSION_TIME, -3},
    {DIMENSION_CURRENT, -2}};

static const std::map<std::string, int> DIMENSIONS_SIEMENS = {
    {DIMENSION_MASS, -1},
    {DIMENSION_LENGTH, -2},
    {DIMENSION_TIME, 3},
    {DIMENSION_CURRENT, 2}};

static const std::map<std::string, int> DIMENSIONS_WEBER = {
    {DIMENSION_MASS, 1},
    {DIMENSION_LENGTH, 2},
    {DIMENSION_TIME, -2},
    {DIMENSION_CURRENT, -1}};

static const std::map<std::string, int> DIMENSIONS_TESLA = {
    {DIMENSION_MASS, 1}, {DIMENSION_TIME, -2}, {DIMENSION_CURRENT, -1}};

static const std::map<std::string, int> DIMENSIONS_HENRY = {
    {DIMENSION_MASS, 1},
    {DIMENSION_LENGTH, 2},
    {DIMENSION_TIME, -2},
    {DIMENSION_CURRENT, -2}};
// Unit symbols
static const std::string UNIT_SYMBOL_METER         = "m";
static const std::string UNIT_SYMBOL_KILOGRAM      = "kg";
static const std::string UNIT_SYMBOL_SECOND        = "s";
static const std::string UNIT_SYMBOL_AMPERE        = "A";
static const std::string UNIT_SYMBOL_KELVIN        = "K";
static const std::string UNIT_SYMBOL_MOLE          = "mol";
static const std::string UNIT_SYMBOL_CANDELA       = "cd";
static const std::string UNIT_SYMBOL_HERTZ         = "Hz";
static const std::string UNIT_SYMBOL_NEWTON        = "N";
static const std::string UNIT_SYMBOL_PASCAL        = "Pa";
static const std::string UNIT_SYMBOL_JOULE         = "J";
static const std::string UNIT_SYMBOL_WATT          = "W";
static const std::string UNIT_SYMBOL_COULOMB       = "C";
static const std::string UNIT_SYMBOL_VOLT          = "V";
static const std::string UNIT_SYMBOL_FARAD         = "F";
static const std::string UNIT_SYMBOL_OHM           = "Ω";
static const std::string UNIT_SYMBOL_SIEMENS       = "S";
static const std::string UNIT_SYMBOL_WEBER         = "Wb";
static const std::string UNIT_SYMBOL_TESLA         = "T";
static const std::string UNIT_SYMBOL_HENRY         = "H";
static const std::string UNIT_SYMBOL_MINUTE        = "min";
static const std::string UNIT_SYMBOL_HOUR          = "h";
static const std::string UNIT_SYMBOL_ELECTRON_VOLT = "eV";
static const std::string UNIT_SYMBOL_CELSIUS       = "°C";
static const std::string UNIT_SYMBOL_FAHRENHEIT    = "°F";
static const std::string UNIT_SYMBOL_PERCENT       = "%";
static const std::string UNIT_SYMBOL_RADIAN        = "rad";

// Unit names
static const std::string UNIT_NAME_METER         = "meter";
static const std::string UNIT_NAME_KILOGRAM      = "kilogram";
static const std::string UNIT_NAME_SECOND        = "second";
static const std::string UNIT_NAME_AMPERE        = "ampere";
static const std::string UNIT_NAME_KELVIN        = "kelvin";
static const std::string UNIT_NAME_MOLE          = "mole";
static const std::string UNIT_NAME_CANDELA       = "candela";
static const std::string UNIT_NAME_HERTZ         = "hertz";
static const std::string UNIT_NAME_NEWTON        = "newton";
static const std::string UNIT_NAME_PASCAL        = "pascal";
static const std::string UNIT_NAME_JOULE         = "joule";
static const std::string UNIT_NAME_WATT          = "watt";
static const std::string UNIT_NAME_COULOMB       = "coulomb";
static const std::string UNIT_NAME_VOLT          = "volt";
static const std::string UNIT_NAME_FARAD         = "farad";
static const std::string UNIT_NAME_OHM           = "ohm";
static const std::string UNIT_NAME_SIEMENS       = "siemens";
static const std::string UNIT_NAME_WEBER         = "weber";
static const std::string UNIT_NAME_TESLA         = "tesla";
static const std::string UNIT_NAME_HENRY         = "henry";
static const std::string UNIT_NAME_MINUTE        = "minute";
static const std::string UNIT_NAME_HOUR          = "hour";
static const std::string UNIT_NAME_ELECTRON_VOLT = "electron-volt";
static const std::string UNIT_NAME_CELSIUS       = "celsius";
static const std::string UNIT_NAME_FAHRENHEIT    = "fahrenheit";
static const std::string UNIT_NAME_DIMENSIONLESS = "dimensionless";
static const std::string UNIT_NAME_PERCENT       = "percent";
static const std::string UNIT_NAME_RADIAN        = "radian";
}  // namespace SI

/**
 * @namespace INSTRUMENT_TYPES
 * @brief Different Instrument types supported by falcon software.
 */
namespace INSTRUMENT_TYPES {
static const std::string DC_VOLTAGE_SOURCE = "dc_voltage_source";
static const std::string AMNMETER          = "amnmeter";
static const std::string MAGNET            = "magnet";
static const std::string LOCKIN            = "lockin";
static const std::string VOLTAGE_SOURCE    = "voltage_source";
static const std::string CURRENT_SOURCE    = "current_source";
static const std::string HF_VOLTAGE_SOURCE = "hf_voltage_source";
static const std::string DC_CURRENT_SOURCE = "dc_current_source";
static const std::string HF_CURRENT_SOURCE = "hf_current_source";
static const std::string THERMOMETER       = "thermometer";
static const std::string VOLTMETER         = "voltmeter";
static const std::string FPGA              = "fpga";
static const std::string CLOCK             = "clock";
static const std::string DISCRETE          = "discrete";
}  // namespace INSTRUMENT_TYPES
}  // namespace falcon_core
