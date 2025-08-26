/**
 * @file Point.hpp
 * @brief Defines the Point class for FalconCore.
 */

#pragma once

#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <unordered_map>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

/**
 * @brief Represents a point in a multi-dimensional space, indexed by connections.
 *
 * @details
 * Each Point stores a mapping from device connections to coordinate values,
 * along with a unit. Supports arithmetic operations and iteration.
 */
class Point : public generic::Song {
 public:
  using UnitPtr = std::shared_ptr<physics::units::SymbolUnit>;

  /**
   * @brief Construct a Point with a unit.
   * @param unit The unit for the point.
   */
  Point(UnitPtr unit) : _coords(), _unit(unit) {}

  /**
   * @brief Variadic constructor for custom coordinate initialization.
   * @param unit The unit for the point.
   * @param args Arguments for initializing the coordinates.
   */
  template <typename... Args>
  Point(UnitPtr unit, Args&&... args)
      : _coords(std::forward<Args>(args)...), _unit(unit) {}

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
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    // Copy this point's values
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = kv.second;
    }
    // Add other point's values
    for (const auto& kv : other._coords) {
      if (result->_coords.find(kv.first) != result->_coords.end()) {
        result->_coords[kv.first] += kv.second;
      } else {
        result->_coords[kv.first] = kv.second;
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
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = kv.second;
    }
    for (const auto& kv : other._coords) {
      if (result->_coords.find(kv.first) != result->_coords.end()) {
        result->_coords[kv.first] -= kv.second;
      } else {
        result->_coords[kv.first] = -kv.second;
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
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = kv.second * scalar;
    }
    return result;
  }

  /**
   * @brief Divide point coordinates by a scalar.
   * @param scalar The scalar value.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator/(double scalar) const {
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = kv.second / scalar;
    }
    return result;
  }

  /**
   * @brief Negate the point coordinates.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Point> operator-() const {
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = -kv.second;
    }
    return result;
  }

  /**
   * @brief Set the unit of the point.
   * @param unit Shared pointer to the new unit.
   */
  void set_unit(UnitPtr unit) { _unit = unit; }

  /**
   * @brief Set the coordinate value for a connection.
   * @param conn Shared pointer to the connection.
   * @param value The coordinate value.
   */
  void set(const std::shared_ptr<physics::device_structures::BaseConnection>& conn,
           double value) {
    _coords[conn] = value;
  }

  /**
   * @brief Get the coordinate value for a connection.
   * @param conn Shared pointer to the connection.
   * @return The coordinate value.
   */
  double get(const std::shared_ptr<physics::device_structures::BaseConnection>& conn) const {
    auto it = _coords.find(conn);
    if (it != _coords.end()) {
      return it->second;
    }
    return 0.0;
  }

  /**
   * @brief Begin iterator for coordinates.
   */
  std::unordered_map<
      std::shared_ptr<physics::device_structures::BaseConnection>,
      double,
      generic::SongPtrHash,
      generic::SongPtrEqual>::const_iterator begin() const { return _coords.begin(); }

  /**
   * @brief End iterator for coordinates.
   */
  std::unordered_map<
      std::shared_ptr<physics::device_structures::BaseConnection>,
      double,
      generic::SongPtrHash,
      generic::SongPtrEqual>::const_iterator end() const { return _coords.end(); }

 private:
  std::unordered_map<
      std::shared_ptr<physics::device_structures::BaseConnection>,
      double,
      generic::SongPtrHash,
      generic::SongPtrEqual> _coords; ///< Map of connection to value.
  UnitPtr _unit; ///< Unit of the point.

  friend class cereal::access;  // cereal can access private members
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _coords,
       _unit);
  }

 public:
  /**
   * @brief Default constructor for cereal access.
   */
  Point() = default;
};

}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::Point)
#endif
