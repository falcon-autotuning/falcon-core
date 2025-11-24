#include "falcon_core/physics/units/SymbolUnit_c_api.h"

#include <falcon_core/physics/units/SymbolUnit.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
using namespace falcon_core::physics::units;

extern "C" {
SymbolUnitHandle SymbolUnit_create_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Meter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilogram() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Kilogram());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_second() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Second());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_ampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Ampere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kelvin() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Kelvin());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_mole() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Mole());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_candela() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Candela());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_hertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Hertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_newton() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Newton());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_pascal() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Pascal());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_joule() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Joule());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_watt() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Watt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_coulomb() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Coulomb());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volt() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Volt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_farad() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Farad());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_ohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Ohm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_siemens() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Siemens());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_weber() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Weber());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_tesla() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Tesla());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_henry() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Henry());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_minute() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Minute());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_hour() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Hour());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_electronvolt() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::ElectronVolt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_celsius() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Celsius());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_fahrenheit() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Fahrenheit());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_dimensionless() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Dimensionless());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_percent() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Percent());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_radian() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::Radian());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilometer() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::KiloMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millimeter() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MilliMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millivolt() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MilliVolt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilovolt() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::KiloVolt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_milliampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MilliAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_microampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MicroAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_nanoampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::NanoAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_picoampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::PicoAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millisecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MilliSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_microsecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MicroSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_nanosecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::NanoSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_picosecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::PicoSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_milliohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MilliOhm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kiloohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::KiloOhm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_megaohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MegaOhm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millihertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MilliHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilohertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::KiloHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_megahertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MegaHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_gigahertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::GigaHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_meters_per_second() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MetersPerSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_meters_per_second_squared() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::MetersPerSecondSquared());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_newton_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::NewtonMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_newtons_per_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::NewtonPerMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volts_per_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::VoltsPerMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volts_per_second() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::VoltsPerSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_amperes_per_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::AmperesPerMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volts_per_ampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::VoltsPerAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin() {
  FALCON_C_API_BEGIN
  return new SymbolUnit(*SymbolUnit::WattsPerMeterKelvin());
  FALCON_C_API_END(nullptr)
}

void SymbolUnit_destroy(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_destroy: handle cannot be null");
  }
  delete static_cast<SymbolUnit*>(handle);
  FALCON_C_API_END()
}

StringHandle SymbolUnit_symbol(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_symbol: handle cannot be null");
  }
  std::string symbol = static_cast<SymbolUnit*>(handle)->symbol();
  return String_create(symbol.c_str(), symbol.size());
  FALCON_C_API_END(nullptr)
}

StringHandle SymbolUnit_name(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_name: handle cannot be null");
  }
  std::string name = static_cast<SymbolUnit*>(handle)->name();
  return String_create(name.c_str(), name.size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_multiplication(SymbolUnitHandle handle,
                                           SymbolUnitHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "SymbolUnit_multiplication: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "SymbolUnit_multiplication: other cannot be null");
  }
  return new SymbolUnit(
      *(*static_cast<SymbolUnit*>(handle) *
        std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(other),
                                    [](SymbolUnit*) {})));
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_division(SymbolUnitHandle handle,
                                     SymbolUnitHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_division: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("SymbolUnit_division: other cannot be null");
  }
  return new SymbolUnit(
      *(*static_cast<SymbolUnit*>(handle) /
        std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(other),
                                    [](SymbolUnit*) {})));
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_power: handle cannot be null");
  }
  return new SymbolUnit(*((*static_cast<SymbolUnit*>(handle)) ^ power));
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_with_prefix(SymbolUnitHandle handle,
                                        StringHandle     prefix) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "SymbolUnit_with_prefix: handle cannot be null");
  }
  if (!prefix) {
    throw std::invalid_argument(
        "SymbolUnit_with_prefix: prefix cannot be null");
  }
  return new SymbolUnit(*static_cast<SymbolUnit*>(handle)->with_prefix(
      std::string(prefix->raw, prefix->length)));
  FALCON_C_API_END(nullptr)
}

double SymbolUnit_convert_value_to(SymbolUnitHandle handle,
                                   double           value,
                                   SymbolUnitHandle target) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "SymbolUnit_convert_value_to: handle cannot be null");
  }
  if (!target) {
    throw std::invalid_argument(
        "SymbolUnit_convert_value_to: target cannot be null");
  }
  return static_cast<SymbolUnit*>(handle)->convert_value_to(
      value,
      std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(target),
                                  [](SymbolUnit*) {}));
  FALCON_C_API_END(0.0)
}

bool SymbolUnit_is_compatible_with(SymbolUnitHandle handle,
                                   SymbolUnitHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "SymbolUnit_is_compatible_with: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "SymbolUnit_is_compatible_with: other cannot be null");
  }
  return static_cast<SymbolUnit*>(handle)->is_compatible_with(
      std::shared_ptr<SymbolUnit>(static_cast<SymbolUnit*>(other),
                                  [](SymbolUnit*) {}));
  FALCON_C_API_END(false)
}

bool SymbolUnit_equal(SymbolUnitHandle handle, SymbolUnitHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("SymbolUnit_equal: other cannot be null");
  }
  return *(static_cast<SymbolUnit*>(handle)) ==
         *(static_cast<SymbolUnit*>(other));
  FALCON_C_API_END(false)
}

bool SymbolUnit_not_equal(SymbolUnitHandle handle, SymbolUnitHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("SymbolUnit_not_equal: other cannot be null");
  }
  return *(static_cast<SymbolUnit*>(handle)) !=
         *(static_cast<SymbolUnit*>(other));
  FALCON_C_API_END(false)
}

StringHandle SymbolUnit_to_json_string(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "SymbolUnit_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<SymbolUnit*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "SymbolUnit_from_json_string: json cannot be null");
  }
  auto ptr = SymbolUnit::from_json_string<SymbolUnit>(json->raw);
  return new SymbolUnit(*ptr);
  FALCON_C_API_END(nullptr)
}
}
