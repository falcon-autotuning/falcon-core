

# File Point.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**Point.hpp**](Point_8hpp.md)

[Go to the documentation of this file](Point_8hpp.md)


```C++


#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace falcon_core {
namespace math {
class Point
    : public generic::Map<physics::device_structures::Connection, Quantity> {
  physics::units::SymbolUnitSP    _unit;
  mutable std::shared_timed_mutex _mu_unit;

 public:
  Point(const Point& other);
  Point& operator=(const Point& other);
  Point();
  Point(const generic::MapSP<physics::device_structures::Connection, double>&
                                            init,
        const physics::units::SymbolUnitSP& unit);
  Point(const generic::MapSP<physics::device_structures::Connection, Quantity>&
            init);
  void insert_or_assign(const physics::device_structures::ConnectionSP& key,
                        const QuantitySP&                               value);

  std::pair<iterator, bool> insert(
      const physics::device_structures::ConnectionSP& key,
      const QuantitySP&                               value);
  const physics::units::SymbolUnitSP unit() const;
  const generic::MapSP<physics::device_structures::Connection, Quantity>
  coordinates() const;
  const generic::ListSP<physics::device_structures::Connection> connections()
      const;

  std::shared_ptr<Point> operator+(const std::shared_ptr<Point>& other) const;
  std::shared_ptr<Point> operator-(const std::shared_ptr<Point>& other) const;
  std::shared_ptr<Point> operator*(double scalar) const;
  std::shared_ptr<Point> operator/(double scalar) const;
  std::shared_ptr<Point> operator-() const;

  void set_unit(physics::units::SymbolUnitSP unit);
  bool operator==(const Point& other) const;
  bool operator!=(const Point& other) const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
    ar(cereal::base_class<
           generic::Map<physics::device_structures::Connection, Quantity>>(
           this),
       _unit);
  }
};
using PointSP = std::shared_ptr<Point>;
}  // namespace math
}  // namespace falcon_core
```


