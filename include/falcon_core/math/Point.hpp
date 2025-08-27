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
class Point : public generic::Map<BaseConnection, double, Point> {
  using UnitPtr = std::shared_ptr<physics::units::SymbolUnit>;
  UnitPtr _unit;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Map<BaseConnection, double, Point>>(this),
       _unit);
  }

 public:
  // Constructors
  Point(UnitPtr unit) : _unit(unit) {}
  Point(std::initializer_list<std::pair<BaseConnectionSP, double>> init,
        UnitPtr                                                    unit)
      : _unit(unit), Map<BaseConnection, double, Point>(init) {}

  // Unit accessor
  UnitPtr unit() const { return _unit; }

  // Example operator+
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

  // Operator- for Point
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

  // Scalar multiplication
  std::shared_ptr<Point> operator*(double scalar) const {
    std::shared_ptr<Point> result = clone();
    for (double value : result->values()) {
      value = value * scalar;
    }
    return result;
  }

  // Scalar division
  std::shared_ptr<Point> operator/(double scalar) const {
    std::shared_ptr<Point> result = clone();
    for (double value : result->values()) {
      value = value / scalar;
    }
    return result;
  }

  // Negation
  std::shared_ptr<Point> operator-() const {
    std::shared_ptr<Point> result = clone();
    for (double value : result->values()) {
      value = -value;
    }
    return result;
  }

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
