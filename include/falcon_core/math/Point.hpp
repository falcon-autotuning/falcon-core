/**
 * @file Point.hpp
 * @brief Defines the Point class for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <cereal/types/unordered_map.hpp>
#include <memory>

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
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
class Point : public generic::Map<BaseConnection, double, Point> {
  using UnitPtr = std::shared_ptr<physics::units::SymbolUnit>;
  UnitPtr _unit;

  template <class Archive>
  void serialize(Archive& ar);

 public:
  Point(UnitPtr unit);
  Point(std::initializer_list<std::pair<BaseConnectionSP, double>> init,
        UnitPtr unit);

  UnitPtr unit() const;

  std::shared_ptr<Point> operator+(const Point& other) const;
  std::shared_ptr<Point> operator-(const Point& other) const;
  std::shared_ptr<Point> operator*(double scalar) const;
  std::shared_ptr<Point> operator/(double scalar) const;
  std::shared_ptr<Point> operator-() const;

  void set_unit(UnitPtr unit);

 protected:
  Point();
  friend class cereal::access;
};
using PointSP = std::shared_ptr<Point>;
}  // namespace math
}  // namespace falcon_core
