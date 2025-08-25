#pragma once

#include <cereal/types/map.hpp>
#include <cereal/types/memory.hpp>
#include <map>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {
class Point : public generic::Song {
 public:
  using UnitPtr = std::shared_ptr<physics::units::SymbolUnit>;

  // Constructors
  Point(UnitPtr unit) : _coords(), _unit(unit) {}
  template <typename... Args>
  Point(UnitPtr unit, Args&&... args)
      : _coords(std::forward<Args>(args)...), _unit(unit) {}

  // Unit accessor
  UnitPtr unit() const { return _unit; }

  // Example operator+
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

  // Operator- for Point
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

  // Scalar multiplication
  std::shared_ptr<Point> operator*(double scalar) const {
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = kv.second * scalar;
    }
    return result;
  }

  // Scalar division
  std::shared_ptr<Point> operator/(double scalar) const {
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = kv.second / scalar;
    }
    return result;
  }

  // Negation
  std::shared_ptr<Point> operator-() const {
    std::shared_ptr<Point> result = std::make_shared<Point>(_unit);
    for (const auto& kv : _coords) {
      result->_coords[kv.first] = -kv.second;
    }
    return result;
  }

  void set_unit(UnitPtr unit) { _unit = unit; }

  // Set coordinate
  void set(const std::shared_ptr<physics::device_structures::BaseConnection>& conn,
           double value) {
    _coords[conn] = value;
  }

  // Get coordinate
  double get(const std::shared_ptr<physics::device_structures::BaseConnection>& conn) const {
    auto it = _coords.find(conn);
    if (it != _coords.end()) {
      return it->second;
    }
    return 0.0;
  }

  // Iteration support
  std::map<std::shared_ptr<physics::device_structures::BaseConnection>, double>::const_iterator begin() const { return _coords.begin(); }
  std::map<std::shared_ptr<physics::device_structures::BaseConnection>, double>::const_iterator end() const { return _coords.end(); }

 private:
  std::map<std::shared_ptr<physics::device_structures::BaseConnection>, double> _coords;
  UnitPtr _unit;

  friend class cereal::access;  // cereal can access private members
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _coords,
       _unit);
  }

 public:
  Point() = default;  // for cereal access
};
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::Point)
#endif
