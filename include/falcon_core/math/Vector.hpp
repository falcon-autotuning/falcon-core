#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

class Vector : public generic::Song {
  PointSP                           _end;
  PointSP                           _start;
  BaseConnectionsSP<BaseConnection> _connections;
  SymbolUnitSP                      _unit;

 public:
  // Constructors
  Vector(PointSP end, PointSP start)
      : _end(end), _start(start), _unit(end->unit()) {
    update_connections();
  }
  Vector(PointSP end)
      : _end(end),
        _start(std::make_shared<Point>(end->unit())),
        _unit(end->unit()) {
    update_connections();
  }
  Vector(const generic::Map<BaseConnection, double>& end, SymbolUnitSP unit)
      : _end(std::make_shared<Point>(unit)),
        _start(std::make_shared<Point>(unit)),
        _unit(unit) {
    for (const auto& kv : end) {
      (*_end)[kv.first]   = kv.second;
      (*_start)[kv.first] = 0.0;
    }
    update_connections();
  }
  Vector(const generic::Map<BaseConnection, double>& end,
         const generic::Map<BaseConnection, double>& start,
         SymbolUnitSP                                unit)
      : _end(std::make_shared<Point>(unit)),
        _start(std::make_shared<Point>(unit)),
        _unit(unit) {
    for (const auto& kv : end) {
      (*_end)[kv.first] = kv.second;
    }
    for (const auto& kv : start) {
      (*_start)[kv.first] = kv.second;
    }
    update_connections();
  }

  // Accessors
  const PointSP&                          end() const { return _end; }
  const PointSP&                          start() const { return _start; }
  const BaseConnectionsSP<BaseConnection> connections() const {
    return _connections;
  }
  SymbolUnitSP unit() const { return _unit; }

  // Indexing
  std::pair<double, double> operator[](const BaseConnectionSP& conn) const {
    double end_val   = (*_end)[conn];
    double start_val = (*_start)[conn];
    return std::make_pair(end_val, start_val);
  }

  // Arithmetic
  std::shared_ptr<Vector> operator+(const Vector& other) const {
    auto new_start = _start->operator+(*other._start);
    auto new_end   = _end->operator+(*other._end);
    return std::make_shared<Vector>(new_end, new_start);
  }
  std::shared_ptr<Vector> operator-(const Vector& other) const {
    auto new_start = _start->operator-(*other._start);
    auto new_end   = _end->operator-(*other._end);
    return std::make_shared<Vector>(new_end, new_start);
  }
  std::shared_ptr<Vector> operator*(double scalar) const {
    auto new_start = _start->operator*(scalar);
    auto new_end   = _end->operator*(scalar);
    return std::make_shared<Vector>(new_end, new_start);
  }
  std::shared_ptr<Vector> operator/(double scalar) const {
    auto new_start = _start->operator/(scalar);
    auto new_end   = _end->operator/(scalar);
    return std::make_shared<Vector>(new_end, new_start);
  }
  std::shared_ptr<Vector> operator-() const {
    auto new_start = _start->operator-();
    auto new_end   = _end->operator-();
    return std::make_shared<Vector>(new_end, new_start);
  }

  // Magnitude
  double magnitude() const {
    double sum = 0.0;
    for (const auto& conn : *_connections) {
      double diff = (*end())[conn] - (*start())[conn];
      sum += diff * diff;
    }
    return std::sqrt(sum);
  }

  // Unit conversion
  void convert_to(SymbolUnitSP target_unit) {
    _end->set_unit(target_unit);
    _start->set_unit(target_unit);
    _unit = target_unit;
  }

  // Serialization
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _end,
       _start,
       _connections,
       _unit);
  }

 public:
  Vector() = default;  // for cereal/c++ containers

 private:
  void update_connections() {
    std::set<BaseConnectionSP> result;
    for (const auto& ptr : _end->keys()) {
      if (ptr) result.insert(ptr);
    }
    for (const auto& ptr : _start->keys()) {
      if (ptr) result.insert(ptr);
    }
    _connections = std::make_shared<BaseConnections<BaseConnection>>(
        std::vector<BaseConnectionSP>(result.begin(), result.end()));
  }
};

}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
CEREAL_REGISTER_TYPE(falcon_core::math::Vector)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Vector)
#endif
