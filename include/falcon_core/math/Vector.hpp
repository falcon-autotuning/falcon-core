/**
 * @file Vector.hpp
 * @brief Defines the Vector class for FalconCore.
 */

#pragma once

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <vector>
#include <unordered_set>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

/**
 * @brief Represents a vector in a multi-dimensional space, defined by start and end points.
 *
 * @details
 * Vector supports arithmetic operations, magnitude calculation, and unit conversion.
 * Each vector is defined by two points and a set of device connections.
 */
class Vector : public generic::Song {
 public:
  using PointPtr      = std::shared_ptr<Point>;
  using Connection    = physics::device_structures::BaseConnection;
  using ConnectionPtr = std::shared_ptr<physics::device_structures::BaseConnection>;
  using UnitPtr       = std::shared_ptr<physics::units::SymbolUnit>;

  /**
   * @brief Construct a vector from start and end points.
   * @param end End point.
   * @param start Start point.
   */
  Vector(PointPtr end, PointPtr start)
      : _end(end), _start(start), _unit(end->unit()) {
    update_connections();
  }

  /**
   * @brief Construct a vector from an end point (start is origin).
   * @param end End point.
   */
  Vector(PointPtr end)
      : _end(end),
        _start(std::make_shared<Point>(end->unit())),
        _unit(end->unit()) {
    update_connections();
  }

  /**
   * @brief Construct a vector from a map of end coordinates and unit.
   * @param end Map of connection to value for end point.
   * @param unit Unit of the vector.
   */
  Vector(const std::map<ConnectionPtr, double>& end, UnitPtr unit)
      : _end(std::make_shared<Point>(unit)),
        _start(std::make_shared<Point>(unit)),
        _unit(unit) {
    for (const auto& kv : end) {
      _end->set(kv.first, kv.second);
      _start->set(kv.first, 0.0);
    }
    update_connections();
  }

  /**
   * @brief Construct a vector from maps of start and end coordinates and unit.
   * @param end Map of connection to value for end point.
   * @param start Map of connection to value for start point.
   * @param unit Unit of the vector.
   */
  Vector(const std::map<ConnectionPtr, double>& end,
         const std::map<ConnectionPtr, double>& start,
         UnitPtr unit)
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

  /**
   * @brief Get the end point.
   * @return Shared pointer to end point.
   */
  const PointPtr& end() const { return _end; }

  /**
   * @brief Get the start point.
   * @return Shared pointer to start point.
   */
  const PointPtr& start() const { return _start; }

  /**
   * @brief Get the set of connections.
   * @return Unordered set of connection pointers.
   */
  const std::unordered_set<ConnectionPtr, generic::SongPtrHash, generic::SongPtrEqual>& connections() const { return _connections; }

  /**
   * @brief Get the unit of the vector.
   * @return Shared pointer to unit.
   */
  UnitPtr unit() const { return _unit; }

  /**
   * @brief Get the values for a connection (end, start).
   * @param conn Connection pointer.
   * @return Pair of (end value, start value).
   */
  std::pair<double, double> operator[](const ConnectionPtr& conn) const {
    double end_val   = _end->get(conn);
    double start_val = _start->get(conn);
    return std::make_pair(end_val, start_val);
  }

  /**
   * @brief Add two vectors.
   * @param other The other vector.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Vector> operator+(const Vector& other) const {
    auto new_start = _start->operator+(*other._start);
    auto new_end   = _end->operator+(*other._end);
    return std::make_shared<Vector>(new_end, new_start);
  }

  /**
   * @brief Subtract two vectors.
   * @param other The other vector.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Vector> operator-(const Vector& other) const {
    auto new_start = _start->operator-(*other._start);
    auto new_end   = _end->operator-(*other._end);
    return std::make_shared<Vector>(new_end, new_start);
  }

  /**
   * @brief Multiply vector by a scalar.
   * @param scalar Scalar value.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Vector> operator*(double scalar) const {
    auto new_start = _start->operator*(scalar);
    auto new_end   = _end->operator*(scalar);
    return std::make_shared<Vector>(new_end, new_start);
  }

  /**
   * @brief Divide vector by a scalar.
   * @param scalar Scalar value.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Vector> operator/(double scalar) const {
    auto new_start = _start->operator/(scalar);
    auto new_end   = _end->operator/(scalar);
    return std::make_shared<Vector>(new_end, new_start);
  }

  /**
   * @brief Negate the vector.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Vector> operator-() const {
    auto new_start = _start->operator-();
    auto new_end   = _end->operator-();
    return std::make_shared<Vector>(new_end, new_start);
  }

  /**
   * @brief Calculate the magnitude of the vector.
   * @return Magnitude as double.
   */
  double magnitude() const {
    double sum = 0.0;
    for (const auto& conn : _connections) {
      double diff = _end->get(conn) - _start->get(conn);
      sum += diff * diff;
    }
    return std::sqrt(sum);
  }

  /**
   * @brief Convert the vector to a different unit.
   * @param target_unit Shared pointer to the target unit.
   */
  void convert_to(UnitPtr target_unit) {
    _end->set_unit(target_unit);
    _start->set_unit(target_unit);
    _unit = target_unit;
  }

  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _end,
       _start,
       _connections,
       _unit);
  }

 public:
  /**
   * @brief Default constructor for cereal/c++ containers.
   */
  Vector() = default;

 private:
  PointPtr                _end;
  PointPtr                _start;
  std::unordered_set<ConnectionPtr, generic::SongPtrHash, generic::SongPtrEqual> _connections;
  UnitPtr                 _unit;

  /**
   * @brief Update the set of connections from start and end points.
   */
  void update_connections() {
    std::unordered_set<ConnectionPtr, generic::SongPtrHash, generic::SongPtrEqual> conns;
    for (const auto& kv : *_end) {
      conns.insert(kv.first);
    }
    for (const auto& kv : *_start) {
      conns.insert(kv.first);
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
#include <cereal/types/unordered_set.hpp>
#endif
