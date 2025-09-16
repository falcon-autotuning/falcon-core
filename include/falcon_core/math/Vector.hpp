/**
 * @file Vector.hpp
 * @brief Defines the Vector class for FalconCore.
 */

#pragma once

#include "falcon_core/communications/voltage_states/DeviceVoltageStates.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::math {
/**
 * @brief a Tuple of two quantities that is serializeable.
 */
class DeltaQuantity : public generic::Song {
  QuantitySP _first;
  QuantitySP _second;

 public:
  DeltaQuantity(const QuantitySP& first, const QuantitySP& second);
  const QuantitySP& first() const;
  const QuantitySP& second() const;

 protected:
  DeltaQuantity();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _first, _second);
  }
};
using DeltaQuantitySP = std::shared_ptr<DeltaQuantity>;
/**
 * @brief Represents a vector in a multi-dimensional space, defined by start and
 * end points.
 *
 * @details
 * Vector supports arithmetic operations, magnitude calculation, and unit
 * conversion. Each vector is defined by two points and a set of device
 * connections.
 */
class Vector : public generic::Map<physics::device_structures::BaseConnection,
                                   DeltaQuantity> {
  physics::units::SymbolUnitSP                  _unit;
  physics::device_structures::BaseConnectionsSP _connections;

 public:
  Vector(const PointSP& start, const PointSP& end);
  Vector(const PointSP& end);
  Vector(const generic::MapSP<physics::device_structures::BaseConnection,
                              Quantity>& end);
  Vector(const generic::MapSP<physics::device_structures::BaseConnection,
                              Quantity>& start,
         const generic::MapSP<physics::device_structures::BaseConnection,
                              Quantity>& end);
  Vector(const generic::MapSP<physics::device_structures::BaseConnection,
                              double>&             end,
         falcon_core::physics::units::SymbolUnitSP unit);
  Vector(const generic::MapSP<physics::device_structures::BaseConnection,
                              double>&             start,
         const generic::MapSP<physics::device_structures::BaseConnection,
                              double>&             end,
         falcon_core::physics::units::SymbolUnitSP unit);
  /**
   * @brief Returns the point at the end.
   */
  const PointSP endPoint() const;
  /**
   * @brief Returns the point at the start.
   */
  const PointSP startPoint() const;
  /**
   * @brief Returns the raw map of the ending point.
   */
  const generic::MapSP<physics::device_structures::BaseConnection, Quantity>
  end_quantities() const;
  /**
   * @brief Returns the raw map of the starting point.
   */
  const generic::MapSP<physics::device_structures::BaseConnection, Quantity>
  start_quantities() const;
  /**
   * @brief Returns the raw unitless map of the ending point.
   */
  const generic::MapSP<physics::device_structures::BaseConnection, double>
  end_map() const;
  /**
   * @brief Returns the raw unitless map of the starting point.
   */
  const generic::MapSP<physics::device_structures::BaseConnection, double>
  start_map() const;
  /**
   * @brief Returns the affected connections for this vector.
   */
  const physics::device_structures::BaseConnectionsSP& connections() const;
  /**
   * @brief Returns the unit of this vector.
   */
  const falcon_core::physics::units::SymbolUnitSP& unit() const;
  /**
   * @brief returns the principle_connection that is the largest.
   */
  const physics::device_structures::BaseConnectionSP principle_connection()
      const;
  /**
   * @brief The magnitude of the vector.
   */
  const double magnitude() const;

  std::shared_ptr<Vector> operator+(const Vector& other) const;
  std::shared_ptr<Vector> operator-(const Vector& other) const;
  std::shared_ptr<Vector> operator*(double scalar) const;
  std::shared_ptr<Vector> operator*(int scalar) const;
  std::shared_ptr<Vector> operator/(double scalar) const;
  std::shared_ptr<Vector> operator/(int scalar) const;
  std::shared_ptr<Vector> operator-() const;

  /**
   * @brief Updates the vector to start from teh given DeviceCVoltageStates.
   * @param state the new device voltage state.
   * @returns the displaced vector which starts at the given state.
   */
  const std::shared_ptr<Vector> update_start_from_states(
      const communications::voltage_states::DeviceVoltageStatesSP& state) const;
  /**
   * @brief Displaces the origin of a vector by a point.
   * @param point the diplacement
   * @param unit the unit of displacement
   */
  const std::shared_ptr<Vector> translate(
      const generic::MapSP<physics::device_structures::BaseConnection, double>
                                         point,
      const physics::units::SymbolUnitSP unit) const;
  /**
   * @brief Displaces the origin of a vector by a point.
   * @param point the diplacement
   */
  const std::shared_ptr<Vector> translate(
      const generic::MapSP<physics::device_structures::BaseConnection, Quantity>
          point) const;
  /**
   * @brief Displaces the origin of a vector by a point.
   * @param point the diplacement
   */
  const std::shared_ptr<Vector> translate(const PointSP& point) const;
  /**
   * @brief Translates a vector to the origin.
   */
  const std::shared_ptr<Vector> translate_to_origin() const;
  /**
   * @brief Extends a vector in place with its start point anchored.
   */
  const std::shared_ptr<Vector> extend(const double& extension) const;
  /**
   * @brief Extends a vector in place with its start point anchored.
   */
  const std::shared_ptr<Vector> extend(const int& extension) const;
  /**
   * @brief Shrinks a vector in place with its start point anchored.
   */
  const std::shared_ptr<Vector> shrink(const double& shrink) const;
  /**
   * @brief Shrinks a vector in place with its start point anchored.
   */
  const std::shared_ptr<Vector> shrink(const int& shrink) const;
  /**
   * @brief Generates the unit vector for the direction of this vector.
   */
  const std::shared_ptr<Vector> unit_vector() const;
  /**
   * @brief Returns the normalized vector starting at the anchored starting
   * point.
   */
  const std::shared_ptr<Vector> normalize() const;
  /**
   * @brief Projects this vector onto another.
   */
  const std::shared_ptr<Vector> project(
      const std::shared_ptr<Vector>& other) const;
  /**
   * @brief Updates the unit of this vector.
   */
  void update_unit(const physics::units::SymbolUnitSP& unit);

 protected:
  Vector();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
           generic::Map<physics::device_structures::BaseConnection,
                        math::DeltaQuantity>>(this),
       _unit);
  }
};
using VectorSP = std::shared_ptr<Vector>;
}  // namespace falcon_core::math
