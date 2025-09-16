#include "falcon_core/math/Point.hpp"

#include "falcon_core/math/Quantity.hpp"

namespace falcon_core::math {

Point::Point() = default;
Point::Point(const generic::MapSP<physics::device_structures::BaseConnection,
                                  double>&       init,
             const physics::units::SymbolUnitSP& unit)
    : _unit(unit),
      generic::
          Map<physics::device_structures::BaseConnection, Quantity, Point>() {
  for (const auto pair : *init) {
    insert(pair.first, std::make_shared<Quantity>(pair.second, unit));
  }
}
Point::Point(const generic::MapSP<physics::device_structures::BaseConnection,
                                  Quantity>& init)
    : _unit(init->at(init->keys().at(0))->unit()),
      generic::
          Map<physics::device_structures::BaseConnection, Quantity, Point>() {
  for (const auto pair : *init) {
    QuantitySP quantity = pair.second;
    quantity->convert_to(_unit);
    insert(pair.first, quantity);
  }
}
void Point::insert_or_assign(
    const physics::device_structures::BaseConnectionSP& key,
    const QuantitySP&                                   value) {
  value->convert_to(_unit);
  Map::insert_or_assign(key, value);
}
std::pair<Point::iterator, bool> Point::insert(
    const physics::device_structures::BaseConnectionSP& key,
    const QuantitySP&                                   value) {
  value->convert_to(_unit);
  return Map::insert(key, value);
}

const physics::units::SymbolUnitSP Point::unit() const { return _unit; }
const generic::MapSP<physics::device_structures::BaseConnection, Quantity>
Point::coordinates() const {
  auto map = std::make_shared<
      generic::Map<physics::device_structures::BaseConnection, Quantity>>();
  for (const auto& pair : items()) {
    map->insert(pair.first, pair.second);
  }
  return map;
}
const generic::ListSP<physics::device_structures::BaseConnection>
Point::connections() const {
  return std::make_shared<
      generic::List<physics::device_structures::BaseConnection>>(keys());
}

PointSP Point::operator+(const PointSP& other) const {
  PointSP result = clone();
  for (const auto& kv : other->items()) {
    auto it = result->find(kv.first);
    if (it != result->end()) {
      *it->second += kv.second;
    } else {
      result->insert_or_assign(kv.first, kv.second);
    }
  }
  return result;
}

PointSP Point::operator-(const PointSP& other) const {
  PointSP result = clone();
  for (const auto& kv : other->items()) {
    auto it = result->find(kv.first);
    if (it != result->end()) {
      *it->second -= kv.second;
    } else {
      result->insert_or_assign(kv.first, kv.second);
    }
  }
  return result;
}

PointSP Point::operator*(double scalar) const {
  PointSP result = clone();
  for (auto& kv : result->items()) {
    *kv.second *= scalar;
  }
  return result;
}

PointSP Point::operator/(double scalar) const {
  PointSP result = clone();
  for (auto& kv : result->items()) {
    *kv.second /= scalar;
  }
  return result;
}

PointSP Point::operator-() const {
  PointSP result = clone();
  for (auto& kv : result->items()) {
    kv.second = -*kv.second;
  }
  return result;
}

void Point::set_unit(physics::units::SymbolUnitSP unit) { _unit = unit; }

}  // namespace falcon_core::math
using MapP = falcon_core::generic::Map<
    falcon_core::physics::device_structures::BaseConnection,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_TYPE(MapP)
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MapP)
CEREAL_REGISTER_POLYMORPHIC_RELATION(MapP, falcon_core::math::Point)
