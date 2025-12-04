#include "falcon_core/math/Point.hpp"

#include <stdexcept>

#include "cereal/types/polymorphic.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace math {
Point::Point(const Point& other)
    : generic::Map<physics::device_structures::Connection, Quantity>(other) {
  std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
  _unit = std::make_shared<physics::units::SymbolUnit>(*other.unit());
}
Point Point::operator=(const Point& other) {
  if (this != &other) {
    generic::Map<physics::device_structures::Connection, Quantity>::operator=(
        other);
    std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
    _unit = std::make_shared<physics::units::SymbolUnit>(*other.unit());
  }
  return *this;
}
Point::Point()
    : generic::Map<physics::device_structures::Connection, Quantity>() {}
Point::Point(
    const generic::MapSP<physics::device_structures::Connection, double>& init,
    const physics::units::SymbolUnitSP&                                   unit)
    : _unit(unit),
      generic::Map<physics::device_structures::Connection, Quantity>() {
  if (!init || !unit) {
    throw std::invalid_argument(
        "Point: The initial map and unit cannot be null.");
  }
  for (const auto pair : *init) {
    insert(pair->first(), std::make_shared<Quantity>(pair->second(), unit));
  }
}
Point::Point(const generic::MapSP<physics::device_structures::Connection,
                                  Quantity>& init)
    : generic::Map<physics::device_structures::Connection, Quantity>() {
  if (!init) {
    throw std::invalid_argument("Point: The initial map cannot be null.");
  }
  for (const auto pair : *init) {
    insert(pair->first(), pair->second());
  }
}
void Point::insert_or_assign(
    const physics::device_structures::ConnectionSP& key,
    const QuantitySP&                               value) {
  if (!key || !value) {
    throw std::invalid_argument("Point: The key and value cannot be null.");
  }
  // If default constructing an empty Point a unit can still be set by the first
  // inserted entry.
  std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
  if (items()->empty()) {
    this->_unit = value->unit();
  }
  value->convert_to(this->_unit);
  return Map::insert_or_assign(key, value);
}
std::pair<Point::iterator, bool> Point::insert(
    const physics::device_structures::ConnectionSP& key,
    const QuantitySP&                               value) {
  if (!key || !value) {
    throw std::invalid_argument("Point: The key and value cannot be null.");
  }
  // If default constructing an empty Point a unit can still be set by the first
  // inserted entry.
  std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
  if (items()->empty()) {
    this->_unit = value->unit();
  }
  value->convert_to(this->_unit);
  return Map::insert(key, value);
}

const physics::units::SymbolUnitSP Point::unit() const {
  std::shared_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
  return _unit;
}
const generic::MapSP<physics::device_structures::Connection, Quantity>
Point::coordinates() const {
  auto map = std::make_shared<
      generic::Map<physics::device_structures::Connection, Quantity>>();
  for (const auto& pair : *items()) {
    map->insert(pair->first(), pair->second());
  }
  return map;
}
const generic::ListSP<physics::device_structures::Connection>
Point::connections() const {
  return keys();
}

PointSP Point::operator+(const PointSP& other) const {
  if (!other) {
    throw std::invalid_argument("Point: The other point cannot be null.");
  }
  auto new_map = std::make_shared<
      generic::Map<physics::device_structures::Connection, Quantity>>();
  for (const auto& kv : *items()) {
    new_map->insert_or_assign(
        kv->first(),
        std::make_shared<Quantity>(*kv->second()));  // deep copy
  }
  PointSP result = std::make_shared<Point>(new_map);
  for (const auto& kv : *other->items()) {
    auto it = result->find(kv->first());
    if (it != result->end()) {
      *(*it)->second() += kv->second();
    } else {
      result->insert_or_assign(
          kv->first(),
          std::make_shared<Quantity>(*kv->second()));  // deep copy
    }
  }
  return result;
}

PointSP Point::operator-(const PointSP& other) const {
  if (!other) {
    throw std::invalid_argument("Point: The other point cannot be null.");
  }
  auto new_map = std::make_shared<
      generic::Map<physics::device_structures::Connection, Quantity>>();
  for (const auto& kv : *items()) {
    new_map->insert(kv->first(),
                    std::make_shared<Quantity>(*kv->second()));  // deep copy
  }
  PointSP result = std::make_shared<Point>(new_map);
  for (const auto& kv : *other->items()) {
    auto it = result->find(kv->first());
    if (it != result->end()) {
      *(*it)->second() -= kv->second();
    } else {
      result->insert_or_assign(kv->first(), -*kv->second());
    }
  }
  return result;
}

PointSP Point::operator*(double scalar) const {
  auto new_map = std::make_shared<
      generic::Map<physics::device_structures::Connection, Quantity>>();
  for (const auto& kv : *items()) {
    new_map->insert(kv->first(),
                    std::make_shared<Quantity>(*kv->second()));  // deep copy
  }
  PointSP result = std::make_shared<Point>(new_map);
  for (auto& kv : *result->items()) {
    *kv->second() *= scalar;
  }
  return result;
}

PointSP Point::operator/(double scalar) const {
  auto new_map = std::make_shared<
      generic::Map<physics::device_structures::Connection, Quantity>>();
  for (const auto& kv : *items()) {
    new_map->insert(kv->first(),
                    std::make_shared<Quantity>(*kv->second()));  // deep copy
  }
  PointSP result = std::make_shared<Point>(new_map);
  for (auto& kv : *result->items()) {
    *kv->second() /= scalar;
  }
  return result;
}

PointSP Point::operator-() const {
  auto new_map = std::make_shared<
      generic::Map<physics::device_structures::Connection, Quantity>>();
  for (const auto& kv : *items()) {
    new_map->insert(kv->first(),
                    -*kv->second());  // negate value
  }
  return std::make_shared<Point>(new_map);
}

void Point::set_unit(physics::units::SymbolUnitSP unit) {
  if (!unit) {
    throw std::invalid_argument("Point: The unit cannot be null.");
  }
  _unit = unit;
}
bool Point::operator==(const Point& other) const {
  return (*unit() == *other.unit()) &&
         (Map<physics::device_structures::Connection, Quantity>::operator==(
             other));
}
bool Point::operator!=(const Point& other) const { return !(*this == other); }

}  // namespace math
}  // namespace falcon_core
using MapP = falcon_core::generic::Map<
    falcon_core::physics::device_structures::Connection,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(MapP, falcon_core::math::Point)
