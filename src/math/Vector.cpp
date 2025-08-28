#include "falcon_core/math/Vector.hpp"

#include <cmath>
#include <memory>
#include <set>

namespace falcon_core {
namespace math {

Vector::Vector(PointSP end, PointSP start)
    : _end(end), _start(start), _unit(end->unit()) {
  update_connections();
}

Vector::Vector(PointSP end)
    : _end(end),
      _start(std::make_shared<Point>(end->unit())),
      _unit(end->unit()) {
  update_connections();
}

Vector::Vector(const generic::Map<BaseConnection, double>& end,
               SymbolUnitSP                                unit)
    : _end(std::make_shared<Point>(unit)),
      _start(std::make_shared<Point>(unit)),
      _unit(unit) {
  for (const auto& kv : end) {
    (*_end)[kv.first]   = kv.second;
    (*_start)[kv.first] = 0.0;
  }
  update_connections();
}

Vector::Vector(const generic::Map<BaseConnection, double>& end,
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

const PointSP&          Vector::end() const { return _end; }
const PointSP&          Vector::start() const { return _start; }
const BaseConnectionsSP Vector::connections() const { return _connections; }
SymbolUnitSP            Vector::unit() const { return _unit; }

std::pair<double, double> Vector::operator[](
    const BaseConnectionSP& conn) const {
  double end_val   = (*_end)[conn];
  double start_val = (*_start)[conn];
  return std::make_pair(end_val, start_val);
}

std::shared_ptr<Vector> Vector::operator+(const Vector& other) const {
  auto new_start = _start->operator+(*other._start);
  auto new_end   = _end->operator+(*other._end);
  return std::make_shared<Vector>(new_end, new_start);
}

std::shared_ptr<Vector> Vector::operator-(const Vector& other) const {
  auto new_start = _start->operator-(*other._start);
  auto new_end   = _end->operator-(*other._end);
  return std::make_shared<Vector>(new_end, new_start);
}

std::shared_ptr<Vector> Vector::operator*(double scalar) const {
  auto new_start = _start->operator*(scalar);
  auto new_end   = _end->operator*(scalar);
  return std::make_shared<Vector>(new_end, new_start);
}

std::shared_ptr<Vector> Vector::operator/(double scalar) const {
  auto new_start = _start->operator/(scalar);
  auto new_end   = _end->operator/(scalar);
  return std::make_shared<Vector>(new_end, new_start);
}

std::shared_ptr<Vector> Vector::operator-() const {
  auto new_start = _start->operator-();
  auto new_end   = _end->operator-();
  return std::make_shared<Vector>(new_end, new_start);
}

double Vector::magnitude() const {
  double sum = 0.0;
  for (const auto& conn : *_connections) {
    double diff = (*end())[conn] - (*start())[conn];
    sum += diff * diff;
  }
  return std::sqrt(sum);
}

void Vector::convert_to(SymbolUnitSP target_unit) {
  _end->set_unit(target_unit);
  _start->set_unit(target_unit);
  _unit = target_unit;
}

Vector::Vector() = default;

void Vector::update_connections() {
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

template <class Archive>
void Vector::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this),
     _end,
     _start,
     _connections,
     _unit);
}

}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::Vector)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Vector)
