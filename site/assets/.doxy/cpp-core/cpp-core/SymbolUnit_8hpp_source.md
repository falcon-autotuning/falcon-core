

# File SymbolUnit.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**units**](dir_666a9a136551104f62f39018fd37905b.md) **>** [**SymbolUnit.hpp**](SymbolUnit_8hpp.md)

[Go to the documentation of this file](SymbolUnit_8hpp.md)


```C++
#pragma once

#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/Unit.hpp"
namespace falcon_core {
namespace physics {
namespace units {

class SymbolUnit : public generic::Song {
  UnitSP                          _unit;
  std::string                     _symbol;
  std::string                     _name;
  mutable std::shared_timed_mutex _mu_unit;
  mutable std::shared_timed_mutex _mu_symbol;
  mutable std::shared_timed_mutex _mu_name;
  const std::pair<std::string, std::string> _find_matching_common_unit() const;
  const std::string _generate_symbol() const;
  const std::string _get_dimension_symbol(std::string dimension) const;

 public:
  SymbolUnit(const SymbolUnit& other);
  SymbolUnit& operator=(const SymbolUnit& other);
  SymbolUnit(UnitSP unit);
  static std::shared_ptr<SymbolUnit> Meter();
  static std::shared_ptr<SymbolUnit> Kilogram();
  static std::shared_ptr<SymbolUnit> Second();
  static std::shared_ptr<SymbolUnit> Ampere();
  static std::shared_ptr<SymbolUnit> Kelvin();
  static std::shared_ptr<SymbolUnit> Mole();
  static std::shared_ptr<SymbolUnit> Candela();
  static std::shared_ptr<SymbolUnit> Hertz();
  static std::shared_ptr<SymbolUnit> Newton();
  static std::shared_ptr<SymbolUnit> Pascal();
  static std::shared_ptr<SymbolUnit> Joule();
  static std::shared_ptr<SymbolUnit> Watt();
  static std::shared_ptr<SymbolUnit> Coulomb();
  static std::shared_ptr<SymbolUnit> Volt();
  static std::shared_ptr<SymbolUnit> Farad();
  static std::shared_ptr<SymbolUnit> Ohm();
  static std::shared_ptr<SymbolUnit> Siemens();
  static std::shared_ptr<SymbolUnit> Weber();
  static std::shared_ptr<SymbolUnit> Tesla();
  static std::shared_ptr<SymbolUnit> Henry();
  static std::shared_ptr<SymbolUnit> Minute();
  static std::shared_ptr<SymbolUnit> Hour();
  static std::shared_ptr<SymbolUnit> ElectronVolt();
  static std::shared_ptr<SymbolUnit> Celsius();
  static std::shared_ptr<SymbolUnit> Fahrenheit();
  static std::shared_ptr<SymbolUnit> Dimensionless();
  static std::shared_ptr<SymbolUnit> Percent();
  static std::shared_ptr<SymbolUnit> Radian();
  static std::shared_ptr<SymbolUnit> KiloMeter();
  static std::shared_ptr<SymbolUnit> MilliMeter();
  static std::shared_ptr<SymbolUnit> MilliVolt();
  static std::shared_ptr<SymbolUnit> KiloVolt();
  static std::shared_ptr<SymbolUnit> MilliAmpere();
  static std::shared_ptr<SymbolUnit> MicroAmpere();
  static std::shared_ptr<SymbolUnit> NanoAmpere();
  static std::shared_ptr<SymbolUnit> PicoAmpere();
  static std::shared_ptr<SymbolUnit> MilliSecond();
  static std::shared_ptr<SymbolUnit> MicroSecond();
  static std::shared_ptr<SymbolUnit> NanoSecond();
  static std::shared_ptr<SymbolUnit> PicoSecond();
  static std::shared_ptr<SymbolUnit> MilliOhm();
  static std::shared_ptr<SymbolUnit> KiloOhm();
  static std::shared_ptr<SymbolUnit> MegaOhm();
  static std::shared_ptr<SymbolUnit> MilliHertz();
  static std::shared_ptr<SymbolUnit> KiloHertz();
  static std::shared_ptr<SymbolUnit> MegaHertz();
  static std::shared_ptr<SymbolUnit> GigaHertz();
  static std::shared_ptr<SymbolUnit> MetersPerSecond();
  static std::shared_ptr<SymbolUnit> MetersPerSecondSquared();
  static std::shared_ptr<SymbolUnit> NewtonMeter();
  static std::shared_ptr<SymbolUnit> NewtonPerMeter();
  static std::shared_ptr<SymbolUnit> VoltsPerMeter();
  static std::shared_ptr<SymbolUnit> VoltsPerSecond();
  static std::shared_ptr<SymbolUnit> AmperesPerMeter();
  static std::shared_ptr<SymbolUnit> VoltsPerAmpere();
  static std::shared_ptr<SymbolUnit> WattsPerMeterKelvin();
  const UnitSP unit() const;
  const std::string symbol() const;
  const std::string name() const;
  const std::shared_ptr<SymbolUnit> operator*(
      const std::shared_ptr<SymbolUnit>& other) const;
  const std::shared_ptr<SymbolUnit> operator*(const UnitSP& other) const;
  const std::shared_ptr<SymbolUnit> operator/(
      const std::shared_ptr<SymbolUnit>& other) const;
  const std::shared_ptr<SymbolUnit> operator/(const UnitSP& other) const;
  const std::shared_ptr<SymbolUnit> operator^(const int power) const;
  const std::shared_ptr<SymbolUnit> with_prefix(const std::string prefix) const;
  const double convert_value_to(
      const double value, const std::shared_ptr<SymbolUnit>& target_unit) const;
  const bool is_compatible_with(const std::shared_ptr<SymbolUnit>& other) const;

  const std::vector<std::tuple<UnitSP, const char*, const char*>>
  get_unit_symbols() const;

  const std::map<std::string, std::string> get_dimension_symbols() const;

  bool operator==(const SymbolUnit& other) const;
  bool operator!=(const SymbolUnit& other) const;

 protected:
  SymbolUnit();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_symbol(_mu_symbol,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::lock(lock_unit, lock_symbol, lock_name);
    ar(cereal::base_class<Song>(this), _unit, _symbol, _name);
  }
};
using SymbolUnitSP = std::shared_ptr<SymbolUnit>;
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
```


