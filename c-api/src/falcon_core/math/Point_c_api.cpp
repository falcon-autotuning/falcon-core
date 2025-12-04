#include "falcon_core/math/Point_c_api.h"

#include <falcon_core/math/Point.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::physics;

extern "C" {
PointHandle Point_create_empty() {
  FALCON_C_API_BEGIN
  return new std::shared_ptr<Point>(std::make_shared<Point>());
  FALCON_C_API_END(nullptr)
}

PointHandle Point_create(MapConnectionDoubleHandle items,
                         SymbolUnitHandle          unit) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument("Point_create: items cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument("Point_create: unit cannot be null");
  }
  generic::MapSP<device_structures::Connection, double> real_items =
      std::make_shared<generic::Map<device_structures::Connection, double>>(
          *static_cast<generic::Map<device_structures::Connection, double>*>(
              items));
  units::SymbolUnitSP real_unit = std::make_shared<units::SymbolUnit>(
      *static_cast<units::SymbolUnit*>(unit));
  return new std::shared_ptr<Point>(
      std::make_shared<Point>(real_items, real_unit));
  FALCON_C_API_END(nullptr)
}

PointHandle Point_create_from_parent(MapConnectionQuantityHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "Point_create_from_parent: items cannot be null");
  }
  generic::MapSP<device_structures::Connection, Quantity> real_items =
      std::make_shared<generic::Map<device_structures::Connection, Quantity>>(
          *static_cast<generic::Map<device_structures::Connection, Quantity>*>(
              items));
  return new std::shared_ptr<Point>(std::make_shared<Point>(real_items));
  FALCON_C_API_END(nullptr)
}

void Point_destroy(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_destroy: handle cannot be null");
  }
  delete static_cast<PointSP*>(handle);
  FALCON_C_API_END()
}

SymbolUnitHandle Point_unit(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_unit: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  return new units::SymbolUnit(*self->unit());
  FALCON_C_API_END(nullptr)
}

void Point_insert_or_assign(PointHandle      handle,
                            ConnectionHandle key,
                            QuantityHandle   value) {
  FALCON_C_API_BEGIN
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
  PointSP self = *static_cast<PointSP*>(handle);
  self->insert_or_assign(
      std::make_shared<device_structures::Connection>(
          *static_cast<device_structures::Connection*>(key)),
      std::make_shared<Quantity>(*static_cast<Quantity*>(value)));
  FALCON_C_API_END()
}

void Point_insert(PointHandle      handle,
                  ConnectionHandle key,
                  QuantityHandle   value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_insert: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_insert: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Point_insert: value cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  self->insert(std::make_shared<device_structures::Connection>(
                   *static_cast<device_structures::Connection*>(key)),
               std::make_shared<Quantity>(*static_cast<Quantity*>(value)));
  FALCON_C_API_END()
}

QuantityHandle Point_at(PointHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_at: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_at: key cannot be null");
  }
  PointSP self  = *static_cast<PointSP*>(handle);
  auto    value = self->at(std::make_shared<device_structures::Connection>(
      *static_cast<device_structures::Connection*>(key)));
  return new Quantity(*value);
  FALCON_C_API_END(nullptr)
}

void Point_erase(PointHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_erase: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_erase: key cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  self->erase(std::make_shared<device_structures::Connection>(
      *static_cast<device_structures::Connection*>(key)));
  FALCON_C_API_END()
}

size_t Point_size(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_size: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool Point_empty(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_empty: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void Point_clear(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_clear: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  self->clear();
  FALCON_C_API_END()
}

bool Point_contains(PointHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_contains: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Point_contains: key cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  return self->contains(std::make_shared<device_structures::Connection>(
      *static_cast<device_structures::Connection*>(key)));
  FALCON_C_API_END(false)
}

ListConnectionHandle Point_keys(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_keys: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  auto    keys = self->keys();
  return new generic::List<device_structures::Connection>(*keys);
  FALCON_C_API_END(nullptr)
}

ListQuantityHandle Point_values(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_values: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  auto    values = self->values();
  return new generic::List<Quantity>(*values);
  FALCON_C_API_END(nullptr)
}

ListPairConnectionQuantityHandle Point_items(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_items: handle cannot be null");
  }
  PointSP self  = *static_cast<PointSP*>(handle);
  auto    items = self->items();
  return new generic::List<
      generic::Pair<device_structures::Connection, Quantity>>(*items);
  FALCON_C_API_END(nullptr)
}

MapConnectionQuantityHandle Point_coordinates(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_coordinates: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  auto    coords = self->coordinates();
  return new generic::Map<device_structures::Connection, Quantity>(*coords);
  FALCON_C_API_END(nullptr)
}

ListConnectionHandle Point_connections(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_connections: handle cannot be null");
  }
  PointSP self  = *static_cast<PointSP*>(handle);
  auto    conns = self->connections();
  return new generic::List<device_structures::Connection>(*conns);
  FALCON_C_API_END(nullptr)
}

PointHandle Point_addition(PointHandle handle, PointHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_addition: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Point_addition: other cannot be null");
  }
  PointSP self     = *static_cast<PointSP*>(handle);
  PointSP other_pt = *static_cast<PointSP*>(other);
  PointSP result   = *self + other_pt;
  return new PointSP(result);
  FALCON_C_API_END(nullptr)
}

PointHandle Point_subtraction(PointHandle handle, PointHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_subtraction: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Point_subtraction: other cannot be null");
  }
  PointSP self     = *static_cast<PointSP*>(handle);
  PointSP other_pt = *static_cast<PointSP*>(other);
  PointSP result   = *self - other_pt;
  return new PointSP(result);
  FALCON_C_API_END(nullptr)
}

PointHandle Point_multiplication(PointHandle handle, double scalar) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_multiplication: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  PointSP result = *self * scalar;
  return new PointSP(result);
  FALCON_C_API_END(nullptr)
}

PointHandle Point_division(PointHandle handle, double scalar) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_division: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  PointSP result = *self / scalar;
  return new PointSP(result);
  FALCON_C_API_END(nullptr)
}

PointHandle Point_negation(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_negation: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  PointSP result = -*self;
  return new PointSP(result);
  FALCON_C_API_END(nullptr)
}

void Point_set_unit(PointHandle handle, SymbolUnitHandle unit) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_set_unit: handle cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument("Point_set_unit: unit cannot be null");
  }
  PointSP             self      = *static_cast<PointSP*>(handle);
  units::SymbolUnitSP real_unit = std::make_shared<units::SymbolUnit>(
      *static_cast<units::SymbolUnit*>(unit));
  self->set_unit(real_unit);
  FALCON_C_API_END()
}

bool Point_equal(PointHandle a, PointHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Point_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Point_equal: b cannot be null");
  }
  PointSP self_a = *static_cast<PointSP*>(a);
  PointSP self_b = *static_cast<PointSP*>(b);
  return *self_a == *self_b;
  FALCON_C_API_END(false)
}

bool Point_not_equal(PointHandle a, PointHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Point_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Point_not_equal: b cannot be null");
  }
  PointSP self_a = *static_cast<PointSP*>(a);
  PointSP self_b = *static_cast<PointSP*>(b);
  return *self_a != *self_b;
  FALCON_C_API_END(false)
}

StringHandle Point_to_json_string(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_to_json_string: handle cannot be null");
  }
  PointSP     self = *static_cast<PointSP*>(handle);
  std::string json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

PointHandle Point_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument("Point_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new PointSP(Point::from_json_string<Point>(json_str));
  FALCON_C_API_END(nullptr)
}
}
