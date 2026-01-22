

# File Unit.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**units**](dir_666a9a136551104f62f39018fd37905b.md) **>** [**Unit.hpp**](Unit_8hpp.md)

[Go to the documentation of this file](Unit_8hpp.md)


```C++
#pragma once

#include <memory>

#include "falcon_core/Constants.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

namespace falcon_core {
namespace physics {
namespace units {

class Unit : public generic::Song {
  double          _scale_factor;  // Scale factor relative to SI base units
  double          _offset;        // Offset form base unit (e.g. for Celsius)
  std::string     _prefix;        // The SI prefix symbol (e.g. "k" for kilo)
  TotalDimensions _dimensions;  // dictionary mapping dimensions to their powers
 public:
  Unit(TotalDimensions dimensions,
       double          scale_factor = 1.0,
       double          offset       = 0.0,
       std::string     prefix       = SI::UNIT_SYMBOL);
  static std::shared_ptr<Unit> Meter();
  static std::shared_ptr<Unit> Kilogram();
  static std::shared_ptr<Unit> Second();
  static std::shared_ptr<Unit> Ampere();
  static std::shared_ptr<Unit> Kelvin();
  static std::shared_ptr<Unit> Mole();
  static std::shared_ptr<Unit> Candela();
  static std::shared_ptr<Unit> Hertz();
  static std::shared_ptr<Unit> Newton();
  static std::shared_ptr<Unit> Pascal();
  static std::shared_ptr<Unit> Joule();
  static std::shared_ptr<Unit> Watt();
  static std::shared_ptr<Unit> Coulomb();
  static std::shared_ptr<Unit> Volt();
  static std::shared_ptr<Unit> Farad();
  static std::shared_ptr<Unit> Ohm();
  static std::shared_ptr<Unit> Siemens();
  static std::shared_ptr<Unit> Weber();
  static std::shared_ptr<Unit> Tesla();
  static std::shared_ptr<Unit> Henry();
  static std::shared_ptr<Unit> Minute();
  static std::shared_ptr<Unit> Hour();
  static std::shared_ptr<Unit> ElectronVolt();
  static std::shared_ptr<Unit> Celsius();
  static std::shared_ptr<Unit> Fahrenheit();
  static std::shared_ptr<Unit> Dimensionless();
  static std::shared_ptr<Unit> Percent();
  static std::shared_ptr<Unit> Radian();

  // Utility to clean dimensions: remove zero exponents
  static void clean_dimensions(TotalDimensions& dims);

  std::string prefix() const;
  TotalDimensions dimensions() const;
  double scale_factor() const;
  double offset() const;

  std::shared_ptr<Unit> operator*(const std::shared_ptr<Unit>& other) const;
  std::shared_ptr<Unit> operator/(const std::shared_ptr<Unit>& other) const;
  std::shared_ptr<Unit> operator^(const int power) const;
  std::shared_ptr<Unit> with_prefix(const std::string prefix) const;
  std::shared_ptr<Unit> get_milli() const;
  std::shared_ptr<Unit> get_micro() const;
  std::shared_ptr<Unit> get_nano() const;
  std::shared_ptr<Unit> get_pico() const;
  std::shared_ptr<Unit> get_kilo() const;
  std::shared_ptr<Unit> get_mega() const;
  std::shared_ptr<Unit> get_giga() const;
  double convert_value_to(const double                 value,
                          const std::shared_ptr<Unit>& target_unit) const;
  bool is_compatible_with(const std::shared_ptr<Unit>& other) const;
  bool operator==(const Unit& other) const;
  bool operator!=(const Unit& other) const;

 protected:
  Unit() = default;  // or initialize _name with a default value
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this),
       _scale_factor,
       _offset,
       _prefix,
       _dimensions);
  }
};
using UnitSP = std::shared_ptr<Unit>;
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
```


