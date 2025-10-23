#include "falcon_core/physics/units/SymbolUnit_c_api.h"

#include <falcon_core/physics/units/SymbolUnit.hpp>
using namespace falcon_core::physics::units;

extern "C" {

SymbolUnitHandle SymbolUnit_create_meter() {
  return new SymbolUnit(*SymbolUnit::Meter());
}

SymbolUnitHandle SymbolUnit_create_kilogram() {
  return new SymbolUnit(*SymbolUnit::Kilogram());
}

SymbolUnitHandle SymbolUnit_create_second() {
  return new SymbolUnit(*SymbolUnit::Second());
}

SymbolUnitHandle SymbolUnit_create_ampere() {
  return new SymbolUnit(*SymbolUnit::Ampere());
}

SymbolUnitHandle SymbolUnit_create_kelvin() {
  return new SymbolUnit(*SymbolUnit::Kelvin());
}

SymbolUnitHandle SymbolUnit_create_mole() {
  return new SymbolUnit(*SymbolUnit::Mole());
}

SymbolUnitHandle SymbolUnit_create_candela() {
  return new SymbolUnit(*SymbolUnit::Candela());
}

SymbolUnitHandle SymbolUnit_create_hertz() {
  return new SymbolUnit(*SymbolUnit::Hertz());
}

SymbolUnitHandle SymbolUnit_create_newton() {
  return new SymbolUnit(*SymbolUnit::Newton());
}

SymbolUnitHandle SymbolUnit_create_pascal() {
  return new SymbolUnit(*SymbolUnit::Pascal());
}

SymbolUnitHandle SymbolUnit_create_joule() {
  return new SymbolUnit(*SymbolUnit::Joule());
}

SymbolUnitHandle SymbolUnit_create_watt() {
  return new SymbolUnit(*SymbolUnit::Watt());
}

SymbolUnitHandle SymbolUnit_create_coulomb() {
  return new SymbolUnit(*SymbolUnit::Coulomb());
}

SymbolUnitHandle SymbolUnit_create_volt() {
  return new SymbolUnit(*SymbolUnit::Volt());
}

SymbolUnitHandle SymbolUnit_create_farad() {
  return new SymbolUnit(*SymbolUnit::Farad());
}

SymbolUnitHandle SymbolUnit_create_ohm() {
  return new SymbolUnit(*SymbolUnit::Ohm());
}

SymbolUnitHandle SymbolUnit_create_siemens() {
  return new SymbolUnit(*SymbolUnit::Siemens());
}

SymbolUnitHandle SymbolUnit_create_weber() {
  return new SymbolUnit(*SymbolUnit::Weber());
}

SymbolUnitHandle SymbolUnit_create_tesla() {
  return new SymbolUnit(*SymbolUnit::Tesla());
}

SymbolUnitHandle SymbolUnit_create_henry() {
  return new SymbolUnit(*SymbolUnit::Henry());
}

SymbolUnitHandle SymbolUnit_create_minute() {
  return new SymbolUnit(*SymbolUnit::Minute());
}

SymbolUnitHandle SymbolUnit_create_hour() {
  return new SymbolUnit(*SymbolUnit::Hour());
}

SymbolUnitHandle SymbolUnit_create_electronvolt() {
  return new SymbolUnit(*SymbolUnit::ElectronVolt());
}

SymbolUnitHandle SymbolUnit_create_celsius() {
  return new SymbolUnit(*SymbolUnit::Celsius());
}

SymbolUnitHandle SymbolUnit_create_fahrenheit() {
  return new SymbolUnit(*SymbolUnit::Fahrenheit());
}

SymbolUnitHandle SymbolUnit_create_dimensionless() {
  return new SymbolUnit(*SymbolUnit::Dimensionless());
}

SymbolUnitHandle SymbolUnit_create_percent() {
  return new SymbolUnit(*SymbolUnit::Percent());
}

SymbolUnitHandle SymbolUnit_create_radian() {
  return new SymbolUnit(*SymbolUnit::Radian());
}

SymbolUnitHandle SymbolUnit_create_kilometer() {
  return new SymbolUnit(*SymbolUnit::KiloMeter());
}

SymbolUnitHandle SymbolUnit_create_millimeter() {
  return new SymbolUnit(*SymbolUnit::MilliMeter());
}

SymbolUnitHandle SymbolUnit_create_millivolt() {
  return new SymbolUnit(*SymbolUnit::MilliVolt());
}

SymbolUnitHandle SymbolUnit_create_kilovolt() {
  return new SymbolUnit(*SymbolUnit::KiloVolt());
}

SymbolUnitHandle SymbolUnit_create_milliampere() {
  return new SymbolUnit(*SymbolUnit::MilliAmpere());
}

SymbolUnitHandle SymbolUnit_create_microampere() {
  return new SymbolUnit(*SymbolUnit::MicroAmpere());
}

SymbolUnitHandle SymbolUnit_create_nanoampere() {
  return new SymbolUnit(*SymbolUnit::NanoAmpere());
}

SymbolUnitHandle SymbolUnit_create_picoampere() {
  return new SymbolUnit(*SymbolUnit::PicoAmpere());
}

SymbolUnitHandle SymbolUnit_create_millisecond() {
  return new SymbolUnit(*SymbolUnit::MilliSecond());
}

SymbolUnitHandle SymbolUnit_create_microsecond() {
  return new SymbolUnit(*SymbolUnit::MicroSecond());
}

SymbolUnitHandle SymbolUnit_create_nanosecond() {
  return new SymbolUnit(*SymbolUnit::NanoSecond());
}

SymbolUnitHandle SymbolUnit_create_picosecond() {
  return new SymbolUnit(*SymbolUnit::PicoSecond());
}

SymbolUnitHandle SymbolUnit_create_milliohm() {
  return new SymbolUnit(*SymbolUnit::MilliOhm());
}

SymbolUnitHandle SymbolUnit_create_kiloohm() {
  return new SymbolUnit(*SymbolUnit::KiloOhm());
}

SymbolUnitHandle SymbolUnit_create_megaohm() {
  return new SymbolUnit(*SymbolUnit::MegaOhm());
}

SymbolUnitHandle SymbolUnit_create_millihertz() {
  return new SymbolUnit(*SymbolUnit::MilliHertz());
}

SymbolUnitHandle SymbolUnit_create_kilohertz() {
  return new SymbolUnit(*SymbolUnit::KiloHertz());
}

SymbolUnitHandle SymbolUnit_create_megahertz() {
  return new SymbolUnit(*SymbolUnit::MegaHertz());
}

SymbolUnitHandle SymbolUnit_create_gigahertz() {
  return new SymbolUnit(*SymbolUnit::GigaHertz());
}

SymbolUnitHandle SymbolUnit_create_meters_per_second() {
  return new SymbolUnit(*SymbolUnit::MetersPerSecond());
}

SymbolUnitHandle SymbolUnit_create_meters_per_second_squared() {
  return new SymbolUnit(*SymbolUnit::MetersPerSecondSquared());
}

SymbolUnitHandle SymbolUnit_create_newton_meter() {
  return new SymbolUnit(*SymbolUnit::NewtonMeter());
}

SymbolUnitHandle SymbolUnit_create_newtons_per_meter() {
  return new SymbolUnit(*SymbolUnit::NewtonPerMeter());
}

SymbolUnitHandle SymbolUnit_create_volts_per_meter() {
  return new SymbolUnit(*SymbolUnit::VoltsPerMeter());
}

SymbolUnitHandle SymbolUnit_create_volts_per_second() {
  return new SymbolUnit(*SymbolUnit::VoltsPerSecond());
}

SymbolUnitHandle SymbolUnit_create_amperes_per_meter() {
  return new SymbolUnit(*SymbolUnit::AmperesPerMeter());
}

SymbolUnitHandle SymbolUnit_create_volts_per_ampere() {
  return new SymbolUnit(*SymbolUnit::VoltsPerAmpere());
}

SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin() {
  return new SymbolUnit(*SymbolUnit::WattsPerMeterKelvin());
}

void SymbolUnit_destroy(SymbolUnitHandle handle) {
  delete static_cast<SymbolUnit*>(handle);
}

const char* SymbolUnit_symbol(SymbolUnitHandle handle) {
  static thread_local std::string symbol;
  symbol = static_cast<SymbolUnit*>(handle)->symbol();
  return symbol.c_str();
}

const char* SymbolUnit_name(SymbolUnitHandle handle) {
  static thread_local std::string name;
  name = static_cast<SymbolUnit*>(handle)->name();
  return name.c_str();
}

SymbolUnitHandle SymbolUnit_multiplication(SymbolUnitHandle handle,
                                           SymbolUnitHandle other) {
  return new SymbolUnit(
      *(*static_cast<SymbolUnit*>(handle) *
        std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(other),
                                    [](SymbolUnit*) {})));
}

SymbolUnitHandle SymbolUnit_division(SymbolUnitHandle handle,
                                     SymbolUnitHandle other) {
  return new SymbolUnit(
      *(*static_cast<SymbolUnit*>(handle) /
        std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(other),
                                    [](SymbolUnit*) {})));
}

SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power) {
  return new SymbolUnit(*((*static_cast<SymbolUnit*>(handle)) ^ power));
}

SymbolUnitHandle SymbolUnit_with_prefix(SymbolUnitHandle handle,
                                        const char*      prefix) {
  return new SymbolUnit(
      *static_cast<SymbolUnit*>(handle)->with_prefix(std::string(prefix)));
}

double SymbolUnit_convert_value_to(SymbolUnitHandle handle,
                                   double           value,
                                   SymbolUnitHandle target) {
  return static_cast<SymbolUnit*>(handle)->convert_value_to(
      value,
      std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(target),
                                  [](SymbolUnit*) {}));
}

bool SymbolUnit_is_compatible_with(SymbolUnitHandle handle,
                                   SymbolUnitHandle other) {
  return static_cast<SymbolUnit*>(handle)->is_compatible_with(
      std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(other),
                                  [](SymbolUnit*) {}));
}

bool SymbolUnit_equal(SymbolUnitHandle handle, SymbolUnitHandle other) {
  return *(static_cast<SymbolUnit*>(handle)) ==
         *(static_cast<SymbolUnit*>(other));
}

bool SymbolUnit_not_equal(SymbolUnitHandle handle, SymbolUnitHandle other) {
  return *(static_cast<SymbolUnit*>(handle)) !=
         *(static_cast<SymbolUnit*>(other));
}

const char* SymbolUnit_to_json_string(SymbolUnitHandle handle) {
  static thread_local std::string json;
  json = static_cast<SymbolUnit*>(handle)->to_json_string();
  return json.c_str();
}

SymbolUnitHandle SymbolUnit_from_json_string(const char* json) {
  return new SymbolUnit(
      *SymbolUnit::from_json_string<SymbolUnit>(std::string(json)));
}
}
