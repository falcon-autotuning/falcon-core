#pragma once

#include <cereal/types/map.hpp>
#include <cereal/types/memory.hpp>
#include <map>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {
class Point
    : public std::map<physics::device_structures::BaseConnection, double>,
      public generic::Song {
 public:
  using BaseMap = std::map<physics::device_structures::BaseConnection, double>;
  using UnitPtr = std::shared_ptr<physics::units::SymbolUnit>;

  // Inherit all std::map constructors
  using BaseMap::BaseMap;

  // Add constructors that take a unit
  template <typename... Args>
  Point(UnitPtr unit, Args&&... args)
      : BaseMap(std::forward<Args>(args)...), _unit(unit) {}

  // Unit accessor
  UnitPtr unit() const { return _unit; }

  // Example operator+
  std::shared_ptr<Point> operator+(const Point& other) const {
    // Union of all connections
    std::shared_ptr<Point> result = std::make_shared<Point>();
    result->_unit                 = this->_unit;
    for (const auto& kv : *this) {
      (*result)[kv.first] = kv.second;
    }
    for (const auto& kv : other) {
      if (result->find(kv.first) != result->end()) {
        (*result)[kv.first] += kv.second;
      } else {
        (*result)[kv.first] = kv.second;
      }
    }
    return result;
  }

  // Operator- for Point
  std::shared_ptr<Point> operator-(const Point& other) const {
    std::shared_ptr<Point> result = std::make_shared<Point>();
    result->_unit                 = this->_unit;
    for (const auto& kv : *this) {
      (*result)[kv.first] = kv.second;
    }
    for (const auto& kv : other) {
      if (result->find(kv.first) != result->end()) {
        (*result)[kv.first] -= kv.second;
      } else {
        (*result)[kv.first] = -kv.second;
      }
    }
    return result;
  }

  // Scalar multiplication
  std::shared_ptr<Point> operator*(double scalar) const {
    std::shared_ptr<Point> result = std::make_shared<Point>();
    result->_unit                 = this->_unit;
    for (const auto& kv : *this) {
      (*result)[kv.first] = kv.second * scalar;
    }
    return result;
  }

  // Scalar division
  std::shared_ptr<Point> operator/(double scalar) const {
    std::shared_ptr<Point> result = std::make_shared<Point>();
    result->_unit                 = this->_unit;
    for (const auto& kv : *this) {
      (*result)[kv.first] = kv.second / scalar;
    }
    return result;
  }

  // Negation
  std::shared_ptr<Point> operator-() const {
    std::shared_ptr<Point> result = std::make_shared<Point>();
    result->_unit                 = this->_unit;
    for (const auto& kv : *this) {
      (*result)[kv.first] = -kv.second;
    }
    return result;
  }

  void set_unit(UnitPtr unit) { _unit = unit; }

  // Set coordinate
  void set(const physics::device_structures::BaseConnection& conn,
           double                                            value) {
    (*this)[conn] = value;
  }

  // Get coordinate
  double get(const physics::device_structures::BaseConnection& conn) const {
    auto it = this->find(conn);
    if (it != this->end()) {
      return it->second;
    }
    return 0.0;
  }

 private:
  UnitPtr _unit;

  friend class cereal::access;  // cereal can access private members
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<BaseMap>(this),
       _unit);
  }

 protected:
  Point() = default;  // for cereal access
};
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Point)
#endif
