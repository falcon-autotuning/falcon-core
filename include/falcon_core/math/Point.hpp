/**
 * @file Point.hpp
 * @brief Defines a Point in voltage space.
 */

#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::math {
/**
 * @brief Represents a point in a multi-dimensional space, indexed by
 * connections.
 *
 * @details
 * Each Point stores a mapping from device connections to coordinate values,
 * along with a unit. Supports arithmetic operations and iteration.
 */
class Point : public generic::Map<physics::device_structures::BaseConnection,
                                  Quantity,
                                  Point> {
  physics::units::SymbolUnitSP _unit;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
           generic::Map<physics::device_structures::BaseConnection,
                        Quantity,
                        Point>>(this),
       _unit);
  }

 public:
  Point(const generic::MapSP<physics::device_structures::BaseConnection,
                             double>&       init,
        const physics::units::SymbolUnitSP& unit);
  Point(const generic::MapSP<physics::device_structures::BaseConnection,
                             Quantity>& init);
  /**
   * @brief Returns the SI unit for the point.
   */
  const physics::units::SymbolUnitSP unit() const;
  /**
   * @brief Returns the coordinates for the point.
   */
  const generic::MapSP<physics::device_structures::BaseConnection, Quantity>
  coordinates() const;
  /**
   * @brief Returns the connections for the point.
   */
  const generic::ListSP<physics::device_structures::BaseConnection>
  connections() const;

  std::shared_ptr<Point> operator+(const Point& other) const;
  std::shared_ptr<Point> operator-(const Point& other) const;
  std::shared_ptr<Point> operator*(double scalar) const;
  std::shared_ptr<Point> operator/(double scalar) const;
  std::shared_ptr<Point> operator-() const;

  void set_unit(physics::units::SymbolUnitSP unit);

 protected:
  Point();
  friend class cereal::access;
};
using PointSP = std::shared_ptr<Point>;
}  // namespace falcon_core::math
