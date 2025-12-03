/**
 * @file Point.hpp
 * @brief Defines a Point in voltage space.
 */

#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace falcon_core {
namespace math {
/**
 * @brief Represents a point in a multi-dimensional space, indexed by
 * connections.
 *
 * @details
 * Each Point stores a mapping from device connections to coordinate values,
 * along with a unit. Supports arithmetic operations and iteration.
 */
class Point
    : public generic::Map<physics::device_structures::Connection, Quantity> {
  physics::units::SymbolUnitSP    _unit;
  mutable std::shared_timed_mutex _mu_unit;

 public:
  Point(const Point& other);
  Point operator=(const Point& other);
  Point();
  Point(const generic::MapSP<physics::device_structures::Connection, double>&
                                            init,
        const physics::units::SymbolUnitSP& unit);
  Point(const generic::MapSP<physics::device_structures::Connection, Quantity>&
            init);
  /**
   * @brief an overide of insert to make sure units are fixed.
   */
  void insert_or_assign(const physics::device_structures::ConnectionSP& key,
                        const QuantitySP&                               value);

  /**
   * @brief an overide of insert to make sure units are fixed.
   */
  std::pair<iterator, bool> insert(
      const physics::device_structures::ConnectionSP& key,
      const QuantitySP&                               value);
  /**
   * @brief Returns the SI unit for the point.
   */
  const physics::units::SymbolUnitSP unit() const;
  /**
   * @brief Returns the coordinates for the point.
   */
  const generic::MapSP<physics::device_structures::Connection, Quantity>
  coordinates() const;
  /**
   * @brief Returns the connections for the point.
   */
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
