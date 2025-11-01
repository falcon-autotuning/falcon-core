#include "falcon_core/math/Point_c_api.h"

#include <falcon_core/math/Point.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

PointHandle Point_create_empty() { return new Point(); }

PointHandle Point_create(MapConnectionDoubleHandle items,
                         SymbolUnitHandle          unit) {
  if (!items) {
    throw std::invalid_argument("Point_create: items cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument("Point_create: unit cannot be null");
  }
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, double>
          real_items = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              double>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  double>*>(items));
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  return new Point(real_items, real_unit);
}

PointHandle Point_create_from_parent(MapConnectionQuantityHandle items) {
  if (!items) {
    throw std::invalid_argument(
        "Point_create_from_parent: items cannot be null");
  }
  falcon_core::generic::MapSP<
      falcon_core::physics::device_structures::Connection,
      falcon_core::math::Quantity>
      real_items = std::make_shared<falcon_core::generic::Map<
          falcon_core::physics::device_structures::Connection,
          falcon_core::math::Quantity>>(
          *static_cast<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              falcon_core::math::Quantity>*>(items));
  return new Point(real_items);
}

void Point_destroy(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_destroy: handle cannot be null");
  }
  delete static_cast<Point*>(handle);
}

SymbolUnitHandle Point_unit(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_unit: handle cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  return new falcon_core::physics::units::SymbolUnit(*self.unit());
}

void Point_insert_or_assign(PointHandle      handle,
                            ConnectionHandle key,
                            QuantityHandle   value) {
  if (!handle) {
    throw std::invalid_argument(
        "Point_insert_or_assign: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_insert_or_assign: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Point_insert_or_assign: value cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  self.insert_or_assign(
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key)),
      std::make_shared<falcon_core::math::Quantity>(
          *static_cast<falcon_core::math::Quantity*>(value)));
}

void Point_insert(PointHandle      handle,
                  ConnectionHandle key,
                  QuantityHandle   value) {
  if (!handle) {
    throw std::invalid_argument("Point_insert: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_insert: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Point_insert: value cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  self.insert(
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key)),
      std::make_shared<falcon_core::math::Quantity>(
          *static_cast<falcon_core::math::Quantity*>(value)));
}

QuantityHandle Point_at(PointHandle handle, ConnectionHandle key) {
  if (!handle) {
    throw std::invalid_argument("Point_at: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_at: key cannot be null");
  }
  Point self  = *static_cast<Point*>(handle);
  auto  value = self.at(
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key)));
  return new falcon_core::math::Quantity(*value);
}

void Point_erase(PointHandle handle, ConnectionHandle key) {
  if (!handle) {
    throw std::invalid_argument("Point_erase: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_erase: key cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  self.erase(
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key)));
}

size_t Point_size(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_size: handle cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  return self.size();
}

bool Point_empty(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_empty: handle cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  return self.empty();
}

void Point_clear(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_clear: handle cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  self.clear();
}

bool Point_contains(PointHandle handle, ConnectionHandle key) {
  if (!handle) {
    throw std::invalid_argument("Point_contains: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_contains: key cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  return self.contains(
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key)));
}

ListConnectionHandle Point_keys(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_keys: handle cannot be null");
  }
  Point self = *static_cast<Point*>(handle);
  auto  keys = self.keys();
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(*keys);
}

ListQuantityHandle Point_values(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_values: handle cannot be null");
  }
  Point self   = *static_cast<Point*>(handle);
  auto  values = self.values();
  return new falcon_core::generic::List<falcon_core::math::Quantity>(*values);
}

ListPairConnectionQuantityHandle Point_items(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_items: handle cannot be null");
  }
  Point self  = *static_cast<Point*>(handle);
  auto  items = self.items();
  return new falcon_core::generic::List<falcon_core::generic::Pair<
      falcon_core::physics::device_structures::Connection,
      falcon_core::math::Quantity>>(items);
}

MapConnectionQuantityHandle Point_coordinates(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_coordinates: handle cannot be null");
  }
  Point self   = *static_cast<Point*>(handle);
  auto  coords = self.coordinates();
  return new falcon_core::generic::Map<
      falcon_core::physics::device_structures::Connection,
      falcon_core::math::Quantity>(*coords);
}

ListConnectionHandle Point_connections(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_connections: handle cannot be null");
  }
  Point self  = *static_cast<Point*>(handle);
  auto  conns = self.connections();
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(*conns);
}

PointHandle Point_addition(PointHandle handle, PointHandle other) {
  if (!handle) {
    throw std::invalid_argument("Point_addition: handle cannot be null");
  }
  Point   self     = *static_cast<Point*>(handle);
  PointSP other_pt = std::make_shared<Point>(*static_cast<Point*>(other));
  auto    result   = self + other_pt;
  return new Point(result);
}

PointHandle Point_subtraction(PointHandle handle, PointHandle other) {
  if (!handle) {
    throw std::invalid_argument("Point_subtraction: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Point_subtraction: other cannot be null");
  }
  Point   self     = *static_cast<Point*>(handle);
  PointSP other_pt = std::make_shared<Point>(*static_cast<Point*>(other));
  auto    result   = self - other_pt;
  return new Point(result);
}

PointHandle Point_multiplication(PointHandle handle, double scalar) {
  if (!handle) {
    throw std::invalid_argument("Point_multiplication: handle cannot be null");
  }
  Point self   = *static_cast<Point*>(handle);
  auto  result = self * scalar;
  return new Point(result);
}

PointHandle Point_division(PointHandle handle, double scalar) {
  if (!handle) {
    throw std::invalid_argument("Point_division: handle cannot be null");
  }
  Point self   = *static_cast<Point*>(handle);
  auto  result = self / scalar;
  return new Point(result);
}

PointHandle Point_negation(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_negation: handle cannot be null");
  }
  Point self   = *static_cast<Point*>(handle);
  auto  result = -self;
  return new Point(result);
}

void Point_set_unit(PointHandle handle, SymbolUnitHandle unit) {
  if (!handle) {
    throw std::invalid_argument("Point_set_unit: handle cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument("Point_set_unit: unit cannot be null");
  }
  Point                                     self = *static_cast<Point*>(handle);
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  self.set_unit(real_unit);
}

bool Point_equal(PointHandle a, PointHandle b) {
  if (!a) {
    throw std::invalid_argument("Point_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Point_equal: b cannot be null");
  }
  Point self_a = *static_cast<Point*>(a);
  Point self_b = *static_cast<Point*>(b);
  return self_a == self_b;
}

bool Point_not_equal(PointHandle a, PointHandle b) {
  if (!a) {
    throw std::invalid_argument("Point_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Point_not_equal: b cannot be null");
  }
  Point self_a = *static_cast<Point*>(a);
  Point self_b = *static_cast<Point*>(b);
  return self_a != self_b;
}

StringHandle Point_to_json_string(PointHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Point_to_json_string: handle cannot be null");
  }
  Point       self = *static_cast<Point*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

PointHandle Point_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument("Point_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new Point(*Point::from_json_string<Point>(json_str));
}
