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
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Map<BaseConnection, double, Point>>(this),
       _unit);
  }

 public:
  /**
   * @brief Construct a Point with a unit.
   * @param unit The unit for the point.
   */
  Point(UnitPtr unit) : _unit(unit) {}
  /**
   * @brief Construct a Point from connection coordinate pairs.
   * @param unit The unit for the point.
   * @param initializer_list The list of pairs.
   */
  Point(std::initializer_list<std::pair<BaseConnectionSP, double>> init,
        UnitPtr                                                    unit)
      : _unit(unit), Map<BaseConnection, double, Point>(init) {}

  /**
   * @brief Get the unit of the point.
   * @return Shared pointer to the unit.
   */
  UnitPtr unit() const { return _unit; }

  /**
   * @brief Add two points.
   * @param other The other point.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator+(const Point& other) const {
    std::shared_ptr<Point> result = clone();
    // Add other point's values
    for (const auto& kv : other.items()) {
      auto it = result->find(kv.first);
      if (it != result->end()) {
        it->second += kv.second;
      } else {
        result->insert_or_assign(kv.first, kv.second);
      }
    }
    return result;
  }

  /**
   * @brief Subtract two points.
   * @param other The other point.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator-(const Point& other) const {
    std::shared_ptr<Point> result = clone();
    for (const auto& kv : other.items()) {
      auto it = result->find(kv.first);
      if (it != result->end()) {
        it->second -= kv.second;
      } else {
        result->insert_or_assign(kv.first, kv.second);
      }
    }
    return result;
  }

  /**
   * @brief Multiply point coordinates by a scalar.
   * @param scalar The scalar value.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator*(double scalar) const {
    std::shared_ptr<Point> result = clone();
    for (double value : result->values()) {
      value = value * scalar;
    }
    return result;
  }

  /**
   * @brief Divide point coordinates by a scalar.
   * @param scalar The scalar value.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator/(double scalar) const {
    std::shared_ptr<Point> result = clone();
    for (double value : result->values()) {
      value = value / scalar;
    }
    return result;
  }

  /**
   * @brief Negate the point coordinates.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator-() const {
    std::shared_ptr<Point> result = clone();
    for (double value : result->values()) {
      value = -value;
    }
    return result;
  }

  /**
   * @brief Set the unit of the point.
   * @param unit Shared pointer to the new unit.
   */
  void set_unit(UnitPtr unit) { _unit = unit; }

 protected:
  Point() = default;  // for cereal access
  friend class cereal::access;
};
using PointSP = std::shared_ptr<Point>;
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
using MapP = falcon_core::generic::
    Map<falcon_core::physics::device_structures::BaseConnection, double>;
CEREAL_REGISTER_TYPE(MapP)
CEREAL_REGISTER_TYPE(Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MapP)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Point)
#endif
