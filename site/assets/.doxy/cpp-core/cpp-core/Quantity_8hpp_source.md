

# File Quantity.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**Quantity.hpp**](Quantity_8hpp.md)

[Go to the documentation of this file](Quantity_8hpp.md)


```C++


#pragma once

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

class Quantity : public generic::Song {
  double                          _value;
  physics::units::SymbolUnitSP    _unit;
  mutable std::shared_timed_mutex _mu_value;
  mutable std::shared_timed_mutex _mu_unit;

 public:
  Quantity(const Quantity& other);
  Quantity& operator=(const Quantity& other);
  Quantity(
      double                       value,
      physics::units::SymbolUnitSP unit = physics::units::SymbolUnit::Volt());

  double value() const;
  physics::units::SymbolUnitSP unit() const;
  void convert_to(physics::units::SymbolUnitSP target_unit);

  std::shared_ptr<Quantity> operator*(const int& other) const;
  std::shared_ptr<Quantity> operator*(const double& other) const;
  std::shared_ptr<Quantity> operator*(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator*=(const int& other);
  Quantity& operator*=(const double& other);
  Quantity& operator*=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> operator/(const int& other) const;
  std::shared_ptr<Quantity> operator/(const double& other) const;
  std::shared_ptr<Quantity> operator/(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator/=(const int& other);
  Quantity& operator/=(const double& other);
  Quantity& operator/=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> operator^(const int& other) const;

  std::shared_ptr<Quantity> operator+(const int& other) const;
  std::shared_ptr<Quantity> operator+(const double& other) const;
  std::shared_ptr<Quantity> operator+(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator+=(const int& other);
  Quantity& operator+=(const double& other);
  Quantity& operator+=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> operator-() const;

  std::shared_ptr<Quantity> operator-(const int& other) const;
  std::shared_ptr<Quantity> operator-(const double& other) const;
  std::shared_ptr<Quantity> operator-(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator-=(const int& other);
  Quantity& operator-=(const double& other);
  Quantity& operator-=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> abs() const;
  bool                      operator==(const Quantity& other) const;
  bool                      operator!=(const Quantity& other) const;

 protected:
  friend class cereal::access;
  Quantity();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_value(_mu_value,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                        std::defer_lock);
    std::lock(lock_value, lock_unit);
    ar(cereal::base_class<Song>(this), _value, _unit);
  }
};
using QuantitySP = std::shared_ptr<Quantity>;
}  // namespace math
}  // namespace falcon_core
```


