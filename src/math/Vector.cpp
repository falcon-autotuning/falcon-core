#include "falcon_core/math/Vector.hpp"

#include <cmath>

#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core::math {

Vector::Vector() = default;
Vector::Vector(const PointSP& start, const PointSP& end)
    : _unit(end->unit()),
      _connections(std::make_shared<physics::device_structures::Connections>()),
      generic::Map<physics::device_structures::Connection,
                   generic::Pair<Quantity, Quantity>>() {
  for (const physics::device_structures::ConnectionSP& connection :
       *end->connections()) {
    _connections->push_back(connection);
  }
  for (const physics::device_structures::ConnectionSP& connection :
       *start->connections()) {
    if (!_connections->contains(connection)) {
      _connections->push_back(connection);
    }
  }
  for (const physics::device_structures::ConnectionSP connectionSP :
       *_connections) {
    QuantitySP first, second;
    if (start->contains(connectionSP)) {
      first = start->at(connectionSP);
      first->convert_to(_unit);
    } else {
      first = std::make_shared<Quantity>(0.0, _unit);
    }
    if (end->contains(connectionSP)) {
      second = end->at(connectionSP);
      second->convert_to(_unit);
    } else {
      second = std::make_shared<Quantity>(0.0, _unit);
    }
    insert(connectionSP,
           std::make_shared<generic::Pair<Quantity, Quantity>>(first, second));
  }
}
Vector::Vector(const PointSP& end) {
  PointSP start = std::make_shared<Point>();
  Vector(start, end);
}
Vector::Vector(const generic::MapSP<physics::device_structures::Connection,
                                    Quantity>& start,
               const generic::MapSP<physics::device_structures::Connection,
                                    Quantity>& end) {
  PointSP startPoint = std::make_shared<Point>(start);
  PointSP endPoint   = std::make_shared<Point>(end);
  Vector(startPoint, endPoint);
}
Vector::Vector(const generic::MapSP<physics::device_structures::Connection,
                                    Quantity>& end) {
  Vector(std::make_shared<
             generic::Map<physics::device_structures::Connection, Quantity>>(),
         end);
}
Vector::Vector(
    const generic::MapSP<physics::device_structures::Connection, double>& start,
    const generic::MapSP<physics::device_structures::Connection, double>& end,
    falcon_core::physics::units::SymbolUnitSP unit) {
  PointSP startPoint = std::make_shared<Point>(start, unit);
  PointSP endPoint   = std::make_shared<Point>(end, unit);
  Vector(startPoint, endPoint);
}
Vector::Vector(
    const generic::MapSP<physics::device_structures::Connection, double>& end,
    falcon_core::physics::units::SymbolUnitSP unit) {
  Vector(std::make_shared<
             generic::Map<physics::device_structures::Connection, double>>(),
         end,
         unit);
}
Vector::Vector(const generic::MapSP<physics::device_structures::Connection,
                                    generic::Pair<Quantity, Quantity>> map)
    : generic::Map<physics::device_structures::Connection,
                   generic::Pair<Quantity, Quantity>>(*map) {}

const PointSP Vector::endPoint() const {
  PointSP result;
  for (const auto pair : items()) {
    result->insert(pair->first(), pair->second()->second());
  }
  return result;
}
const PointSP Vector::startPoint() const {
  PointSP result;
  for (const auto pair : items()) {
    result->insert(pair->first(), pair->second()->first());
  }
  return result;
}
const generic::MapSP<physics::device_structures::Connection, Quantity>
Vector::end_quantities() const {
  generic::MapSP<physics::device_structures::Connection, Quantity> result;
  for (const auto pair : items()) {
    result->insert(pair->first(), pair->second()->second());
  }
  return result;
}
const generic::MapSP<physics::device_structures::Connection, Quantity>
Vector::start_quantities() const {
  generic::MapSP<physics::device_structures::Connection, Quantity> result;
  for (const auto pair : items()) {
    result->insert(pair->first(), pair->second()->first());
  }
  return result;
}
const generic::MapSP<physics::device_structures::Connection, double>
Vector::end_map() const {
  generic::MapSP<physics::device_structures::Connection, double> result;
  for (const auto pair : items()) {
    result->insert(pair->first(), pair->second()->second()->value());
  }
  return result;
}
const generic::MapSP<physics::device_structures::Connection, double>
Vector::start_map() const {
  generic::MapSP<physics::device_structures::Connection, double> result;
  for (const auto pair : items()) {
    result->insert(pair->first(), pair->second()->first()->value());
  }
  return result;
}
const physics::device_structures::ConnectionsSP& Vector::connections() const {
  return _connections;
}
const falcon_core::physics::units::SymbolUnitSP& Vector::unit() const {
  return _unit;
}
const physics::device_structures::ConnectionSP Vector::principle_connection()
    const {
  physics::device_structures::ConnectionSP big_conn = connections()->at(0);
  double big_value = (*at(big_conn)->second() - at(big_conn)->first())->value();
  for (const physics::device_structures::ConnectionSP& conn : *connections()) {
    double temp = (*at(conn)->second() - at(conn)->first())->value();
    if (temp > big_value) {
      big_value = temp;
      big_conn  = conn;
    }
  }
  return big_conn;
}
const double Vector::magnitude() const {
  double sum = 0.0;
  for (const physics::device_structures::ConnectionSP& conn : *_connections) {
    double diff = (*at(conn)->second() - at(conn)->first())->value();
    sum += diff * diff;
  }
  return std::sqrt(sum);
}

VectorSP Vector::operator+(const Vector& other) const {
  auto new_start = startPoint()->operator+(other.startPoint());
  auto new_end   = endPoint()->operator+(other.endPoint());
  return std::make_shared<Vector>(new_end, new_start);
}

VectorSP Vector::operator-(const Vector& other) const {
  auto new_start = startPoint()->operator-(other.startPoint());
  auto new_end   = endPoint()->operator-(other.endPoint());
  return std::make_shared<Vector>(new_end, new_start);
}

VectorSP Vector::operator*(double scalar) const {
  auto new_start = startPoint()->operator*(scalar);
  auto new_end   = endPoint()->operator*(scalar);
  return std::make_shared<Vector>(new_end, new_start);
}

VectorSP Vector::operator/(double scalar) const {
  auto new_start = startPoint()->operator/(scalar);
  auto new_end   = endPoint()->operator/(scalar);
  return std::make_shared<Vector>(new_end, new_start);
}

VectorSP Vector::operator-() const {
  auto new_start = startPoint()->operator-();
  auto new_end   = endPoint()->operator-();
  return std::make_shared<Vector>(new_end, new_start);
}
const VectorSP Vector::translate(const PointSP& point) const {
  PointSP startPoint = *this->startPoint() + point;
  PointSP endPoint   = *this->endPoint() + point;
  return std::make_shared<Vector>(startPoint, endPoint);
}
const VectorSP Vector::translate(
    const generic::MapSP<physics::device_structures::Connection, double> point,
    const physics::units::SymbolUnitSP unit) const {
  PointSP adjustment = std::make_shared<Point>(point, unit);
  return translate(adjustment);
}
const VectorSP Vector::translate(
    const generic::MapSP<physics::device_structures::Connection, Quantity>
        point) const {
  PointSP adjustment = std::make_shared<Point>(point);
  return translate(adjustment);
}
const VectorSP Vector::translate_to_origin() const {
  return translate(-*startPoint());
}
const VectorSP Vector::update_start_from_states(
    const communications::voltage_states::DeviceVoltageStatesSP& state) const {
  VectorSP originVector = translate_to_origin();
  return originVector->translate(state->to_point());
}
const VectorSP Vector::unit_vector() const {
  VectorSP origin = translate_to_origin();
  return *origin / magnitude();
}
const VectorSP Vector::extend(const double& extension) const {
  VectorSP origin = translate_to_origin();
  VectorSP scaled = *origin * extension;
  return scaled->translate(startPoint());
}
const VectorSP Vector::extend(const int& extension) const {
  return extend(double(extension));
}
const VectorSP Vector::shrink(const double& shrink) const {
  VectorSP origin = translate_to_origin();
  VectorSP scaled = *origin / shrink;
  return scaled->translate(startPoint());
}
const VectorSP Vector::shrink(const int& shrink) const {
  return extend(double(shrink));
}
const VectorSP Vector::normalize() const { return shrink(magnitude()); }
void           Vector::update_unit(const physics::units::SymbolUnitSP& unit) {
  for (auto pair : items()) {
    pair->second()->first()->convert_to(unit);
    pair->second()->second()->convert_to(unit);
  }
}
const VectorSP Vector::project(const VectorSP& other) const {
  VectorSP clone = std::make_shared<Vector>(startPoint(), endPoint());
  clone->update_unit(other->unit());
  PointSP ourEnd   = clone->translate_to_origin()->endPoint();
  PointSP otherEnd = other->translate_to_origin()->endPoint();
  physics::device_structures::ConnectionsSP shared =
      connections()->intersection(other->connections());
  generic::MapSP<physics::device_structures::Connection, Quantity> rawPoint;
  for (const physics::device_structures::ConnectionSP& conn : *shared) {
    rawPoint->insert(conn, *ourEnd->at(conn) * otherEnd->at(conn));
  }
  VectorSP result = std::make_shared<Vector>(rawPoint);
  return result->translate(startPoint());
}
}  // namespace falcon_core::math

CEREAL_REGISTER_TYPE(falcon_core::math::Vector)
using MBD = falcon_core::generic::Map<
    falcon_core::physics::device_structures::Connection,
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(MBD, falcon_core::math::Vector)
