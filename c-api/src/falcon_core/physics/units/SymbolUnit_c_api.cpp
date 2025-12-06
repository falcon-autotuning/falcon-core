#include "falcon_core/physics/units/SymbolUnit_c_api.h"

#include <falcon_core/physics/units/SymbolUnit.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
using namespace falcon_core::physics::units;

extern "C" {
SymbolUnitHandle SymbolUnit_create_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Meter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilogram() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Kilogram());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_second() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Second());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_ampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Ampere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kelvin() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Kelvin());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_mole() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Mole());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_candela() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Candela());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_hertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Hertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_newton() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Newton());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_pascal() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Pascal());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_joule() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Joule());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_watt() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Watt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_coulomb() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Coulomb());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volt() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Volt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_farad() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Farad());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_ohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Ohm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_siemens() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Siemens());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_weber() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Weber());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_tesla() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Tesla());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_henry() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Henry());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_minute() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Minute());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_hour() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Hour());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_electronvolt() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::ElectronVolt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_celsius() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Celsius());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_fahrenheit() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Fahrenheit());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_dimensionless() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Dimensionless());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_percent() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Percent());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_radian() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::Radian());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilometer() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::KiloMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millimeter() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MilliMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millivolt() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MilliVolt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilovolt() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::KiloVolt());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_milliampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MilliAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_microampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MicroAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_nanoampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::NanoAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_picoampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::PicoAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millisecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MilliSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_microsecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MicroSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_nanosecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::NanoSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_picosecond() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::PicoSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_milliohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MilliOhm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kiloohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::KiloOhm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_megaohm() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MegaOhm());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_millihertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MilliHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_kilohertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::KiloHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_megahertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MegaHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_gigahertz() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::GigaHertz());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_meters_per_second() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MetersPerSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_meters_per_second_squared() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::MetersPerSecondSquared());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_newton_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::NewtonMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_newtons_per_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::NewtonPerMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volts_per_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::VoltsPerMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volts_per_second() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::VoltsPerSecond());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_amperes_per_meter() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::AmperesPerMeter());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_volts_per_ampere() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::VoltsPerAmpere());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin() {
  FALCON_C_API_BEGIN
  return new SymbolUnitSP(SymbolUnit::WattsPerMeterKelvin());
  FALCON_C_API_END(nullptr)
}

void SymbolUnit_destroy(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_destroy: handle cannot be null");
  }
  delete static_cast<SymbolUnitSP*>(handle);
  FALCON_C_API_END()
}

StringHandle SymbolUnit_symbol(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_symbol: handle cannot be null");
  }
  std::string symbol = (*static_cast<SymbolUnitSP*>(handle))->symbol();
  return String_create(symbol.c_str(), symbol.size());
  FALCON_C_API_END(nullptr)
}

StringHandle SymbolUnit_name(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_name: handle cannot be null");
  }
  std::string name = (*static_cast<SymbolUnitSP*>(handle))->name();
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
  return new SymbolUnitSP(*(*static_cast<SymbolUnitSP*>(handle)) *
                          *static_cast<SymbolUnitSP*>(other));
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
  return new SymbolUnitSP(*(*static_cast<SymbolUnitSP*>(handle)) /
                          *static_cast<SymbolUnitSP*>(other));
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("SymbolUnit_power: handle cannot be null");
  }
  return new SymbolUnitSP(*(*static_cast<SymbolUnitSP*>(handle)) ^ power);
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
  return new SymbolUnitSP(
      (*static_cast<SymbolUnitSP*>(handle))
          ->with_prefix(std::string(prefix->raw, prefix->length)));
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
  return (*static_cast<SymbolUnitSP*>(handle))
      ->convert_value_to(value, *static_cast<SymbolUnitSP*>(target));
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
  return (*static_cast<SymbolUnitSP*>(handle))
      ->is_compatible_with(*static_cast<SymbolUnitSP*>(other));
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
  return *(static_cast<SymbolUnitSP*>(handle)) ==
         *(static_cast<SymbolUnitSP*>(other));
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
  return *(static_cast<SymbolUnitSP*>(handle)) !=
         *(static_cast<SymbolUnitSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle SymbolUnit_to_json_string(SymbolUnitHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "SymbolUnit_to_json_string: handle cannot be null");
  }
  std::string json = (*static_cast<SymbolUnitSP*>(handle))->to_json_string();
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
  return new SymbolUnitSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
