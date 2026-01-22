

# File Vector.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**Vector.hpp**](Vector_8hpp.md)

[Go to the documentation of this file](Vector_8hpp.md)


```C++


#pragma once

#include "falcon_core/communications/voltage_states/DeviceVoltageStates.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace falcon_core {
namespace math {
class Vector : public generic::Map<physics::device_structures::Connection,
                                   generic::Pair<Quantity, Quantity>> {
  physics::units::SymbolUnitSP              _unit;
  physics::device_structures::ConnectionsSP _connections;
  mutable std::shared_timed_mutex           _mu_unit;
  mutable std::shared_timed_mutex           _mu_connections;

 public:
  Vector(const Vector& other);
  Vector& operator=(const Vector& other);
  Vector(const PointSP& start, const PointSP& end);
  Vector(const PointSP& end);
  Vector(const generic::MapSP<physics::device_structures::Connection, Quantity>&
             end);
  Vector(const generic::MapSP<physics::device_structures::Connection, Quantity>&
             start,
         const generic::MapSP<physics::device_structures::Connection, Quantity>&
             end);
  Vector(
      const generic::MapSP<physics::device_structures::Connection, double>& end,
      falcon_core::physics::units::SymbolUnitSP unit);
  Vector(
      const generic::MapSP<physics::device_structures::Connection, double>&
          start,
      const generic::MapSP<physics::device_structures::Connection, double>& end,
      falcon_core::physics::units::SymbolUnitSP unit);
  Vector(const generic::MapSP<physics::device_structures::Connection,
                              generic::Pair<Quantity, Quantity>> map);
  const PointSP endPoint() const;
  const PointSP startPoint() const;
  const generic::MapSP<physics::device_structures::Connection, Quantity>
  end_quantities() const;
  const generic::MapSP<physics::device_structures::Connection, Quantity>
  start_quantities() const;
  const generic::MapSP<physics::device_structures::Connection, double> end_map()
      const;
  const generic::MapSP<physics::device_structures::Connection, double>
  start_map() const;
  const physics::device_structures::ConnectionsSP& connections() const;
  const falcon_core::physics::units::SymbolUnitSP& unit() const;
  const physics::device_structures::ConnectionSP principle_connection() const;
  const double magnitude() const;

  std::shared_ptr<Vector> operator+(const std::shared_ptr<Vector>& other) const;
  std::shared_ptr<Vector> operator-(const std::shared_ptr<Vector>& other) const;
  std::shared_ptr<Vector> operator*(double scalar) const;
  std::shared_ptr<Vector> operator*(int scalar) const;
  std::shared_ptr<Vector> operator/(double scalar) const;
  std::shared_ptr<Vector> operator/(int scalar) const;
  std::shared_ptr<Vector> operator-() const;

  const std::shared_ptr<Vector> update_start_from_states(
      const communications::voltage_states::DeviceVoltageStatesSP& state) const;
  const std::shared_ptr<Vector> translate(
      const generic::MapSP<physics::device_structures::Connection, double>
                                         point,
      const physics::units::SymbolUnitSP unit) const;
  const std::shared_ptr<Vector> translate(
      const generic::MapSP<physics::device_structures::Connection, Quantity>
          point) const;
  const std::shared_ptr<Vector> translate(const PointSP& point) const;
  const std::shared_ptr<Vector> translate_to_origin() const;
  const std::shared_ptr<Vector> extend(const double& extension) const;
  const std::shared_ptr<Vector> extend(const int& extension) const;
  const std::shared_ptr<Vector> shrink(const double& shrink) const;
  const std::shared_ptr<Vector> shrink(const int& shrink) const;
  const std::shared_ptr<Vector> unit_vector() const;
  const std::shared_ptr<Vector> normalize() const;
  const std::shared_ptr<Vector> project(
      const std::shared_ptr<Vector>& other) const;
  void update_unit(const physics::units::SymbolUnitSP& unit);
  bool operator==(const Vector& other) const;
  bool operator!=(const Vector& other) const;

 protected:
  Vector();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_connections(_mu_connections,
                                                               std::defer_lock);
    std::lock(lock_unit, lock_connections);
    ar(cereal::base_class<generic::Map<physics::device_structures::Connection,
                                       generic::Pair<Quantity, Quantity>>>(
           this),
       _connections,
       _unit);
  }
};
using VectorSP = std::shared_ptr<Vector>;
}  // namespace math
}  // namespace falcon_core
```


