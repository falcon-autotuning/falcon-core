#include "falcon-core/math/Point_c_api.h"

#include <falcon-core/math/Point.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::physics;

extern "C" {
DEFINE_C_API_COPY(Point);
DEFINE_C_API_DESTROY(Point);
DEFINE_C_API_EQUAL(Point);
DEFINE_C_API_NOT_EQUAL(Point);
DEFINE_C_API_TO_JSON(Point);
DEFINE_C_API_FROM_JSON(Point);
PointHandle Point_create_empty() {
  FALCON_C_API_BEGIN
  return new PointSP(std::make_shared<Point>());
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
      *static_cast<generic::MapSP<device_structures::Connection, double>*>(
          items);
  units::SymbolUnitSP real_unit = *static_cast<units::SymbolUnitSP*>(unit);
  return new PointSP(std::make_shared<Point>(real_items, real_unit));
  FALCON_C_API_END(nullptr)
}

PointHandle Point_create_from_parent(MapConnectionQuantityHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "Point_create_from_parent: items cannot be null");
  }
  generic::MapSP<device_structures::Connection, Quantity> real_items =
      *static_cast<generic::MapSP<device_structures::Connection, Quantity>*>(
          items);
  return new PointSP(std::make_shared<Point>(real_items));
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle Point_unit(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_unit: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  return new units::SymbolUnitSP(self->unit());
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
  self->insert_or_assign(*static_cast<device_structures::ConnectionSP*>(key),
                         *static_cast<QuantitySP*>(value));
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
  self->insert(*static_cast<device_structures::ConnectionSP*>(key),
               *static_cast<QuantitySP*>(value));
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
  auto    value = self->at(*static_cast<device_structures::ConnectionSP*>(key));
  return new QuantitySP(value);
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
  self->erase(*static_cast<device_structures::ConnectionSP*>(key));
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
  return self->contains(*static_cast<device_structures::ConnectionSP*>(key));
  FALCON_C_API_END(false)
}

ListConnectionHandle Point_keys(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_keys: handle cannot be null");
  }
  PointSP self = *static_cast<PointSP*>(handle);
  auto    keys = self->keys();
  return new generic::ListSP<device_structures::Connection>(keys);
  FALCON_C_API_END(nullptr)
}

ListQuantityHandle Point_values(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_values: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  auto    values = self->values();
  return new generic::ListSP<Quantity>(values);
  FALCON_C_API_END(nullptr)
}

ListPairConnectionQuantityHandle Point_items(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_items: handle cannot be null");
  }
  PointSP self  = *static_cast<PointSP*>(handle);
  auto    items = self->items();
  return new generic::ListSP<
      generic::Pair<device_structures::Connection, Quantity>>(items);
  FALCON_C_API_END(nullptr)
}

MapConnectionQuantityHandle Point_coordinates(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_coordinates: handle cannot be null");
  }
  PointSP self   = *static_cast<PointSP*>(handle);
  auto    coords = self->coordinates();
  return new generic::MapSP<device_structures::Connection, Quantity>(coords);
  FALCON_C_API_END(nullptr)
}

ListConnectionHandle Point_connections(PointHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Point_connections: handle cannot be null");
  }
  PointSP self  = *static_cast<PointSP*>(handle);
  auto    conns = self->connections();
  return new generic::ListSP<device_structures::Connection>(conns);
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
  units::SymbolUnitSP real_unit = *static_cast<units::SymbolUnitSP*>(unit);
  self->set_unit(real_unit);
  FALCON_C_API_END()
}
}
