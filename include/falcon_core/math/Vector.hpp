#pragma once

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

class Vector : public generic::Song {
 public:
  using PointPtr   = std::shared_ptr<Point>;
  using Connection = physics::device_structures::BaseConnection;
  using UnitPtr    = std::shared_ptr<physics::units::SymbolUnit>;

  // Constructors
  Vector(PointPtr end, PointPtr start)
      : _end(end), _start(start), _unit(end->unit()) {
    update_connections();
  }
  Vector(PointPtr end)
      : _end(end),
        _start(std::make_shared<Point>(end->unit())),
        _unit(end->unit()) {
    update_connections();
  }
  Vector(const std::map<Connection, double>& end, UnitPtr unit)
      : _end(std::make_shared<Point>(unit)),
        _start(std::make_shared<Point>(unit)),
        _unit(unit) {
    for (const auto& kv : end) {
      _end->set(kv.first, kv.second);
      _start->set(kv.first, 0.0);
    }
    update_connections();
  }
  Vector(const std::map<Connection, double>& end,
         const std::map<Connection, double>& start,
         UnitPtr                             unit)
      : _end(std::make_shared<Point>(unit)),
        _start(std::make_shared<Point>(unit)),
        _unit(unit) {
    for (const auto& kv : end) {
      _end->set(kv.first, kv.second);
    }
    for (const auto& kv : start) {
      _start->set(kv.first, kv.second);
    }
    update_connections();
  }

  // Accessors
  const PointPtr&                end() const { return _end; }
  const PointPtr&                start() const { return _start; }
  const std::vector<Connection>& connections() const { return _connections; }
  UnitPtr                        unit() const { return _unit; }

  // Indexing
  std::pair<double, double> operator[](const Connection& conn) const {
    double end_val   = _end->get(conn);
    double start_val = _start->get(conn);
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
    for (const auto& conn : _connections) {
      double diff = _end->get(conn) - _start->get(conn);
      sum += diff * diff;
    }
    return std::sqrt(sum);
  }

  // Unit conversion
  void convert_to(UnitPtr target_unit) {
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
  PointPtr                _end;
  PointPtr                _start;
  std::vector<Connection> _connections;
  UnitPtr                 _unit;

  void update_connections() {
    std::vector<Connection> conns;
    for (const auto& kv : *_end) {
      conns.push_back(kv.first);
    }
    for (const auto& kv : *_start) {
      if (std::find(conns.begin(), conns.end(), kv.first) == conns.end()) {
        conns.push_back(kv.first);
      }
    }
    _connections = conns;
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
