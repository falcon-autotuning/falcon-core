/**
 * @file Vector.hpp
 * @brief Defines the Vector class for FalconCore.
 */

#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

/**
 * @brief Represents a vector in a multi-dimensional space, defined by start and
 * end points.
 *
 * @details
 * Vector supports arithmetic operations, magnitude calculation, and unit
 * conversion. Each vector is defined by two points and a set of device
 * connections.
 */
class Vector : public generic::Song {
  PointSP                      _end;
  PointSP                      _start;
  BaseConnectionsSP            _connections;
  physics::units::SymbolUnitSP _unit;

 public:
  Vector(PointSP end, PointSP start);
  Vector(PointSP end);
  Vector(const generic::Map<BaseConnection, double>& end,
         falcon_core::physics::units::SymbolUnitSP   unit);
  Vector(const generic::Map<BaseConnection, double>& end,
         const generic::Map<BaseConnection, double>& start,
         falcon_core::physics::units::SymbolUnitSP   unit);

  const PointSP&                            end() const;
  const PointSP&                            start() const;
  const BaseConnectionsSP                   connections() const;
  falcon_core::physics::units::SymbolUnitSP unit() const;

  std::pair<double, double> operator[](const BaseConnectionSP& conn) const;

  std::shared_ptr<Vector> operator+(const Vector& other) const;
  std::shared_ptr<Vector> operator-(const Vector& other) const;
  std::shared_ptr<Vector> operator*(double scalar) const;
  std::shared_ptr<Vector> operator/(double scalar) const;
  std::shared_ptr<Vector> operator-() const;

  double magnitude() const;
  void   convert_to(falcon_core::physics::units::SymbolUnitSP target_unit);

  template <class Archive>
  void serialize(Archive& ar);

  Vector();

 private:
  void update_connections();
};

}  // namespace math
}  // namespace falcon_core
