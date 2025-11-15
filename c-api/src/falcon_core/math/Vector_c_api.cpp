#include "falcon_core/math/Vector_c_api.h"

#include <falcon_core/math/Vector.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {
VectorHandle Vector_create(PointHandle start, PointHandle end) {
  FALCON_C_API_BEGIN
  if (!start) {
    throw std::invalid_argument("Vector_create: start cannot be null");
  }
  if (!end) {
    throw std::invalid_argument("Vector_create: end cannot be null");
  }
  PointSP real_start = std::make_shared<Point>(*static_cast<Point*>(start));
  PointSP real_end   = std::make_shared<Point>(*static_cast<Point*>(end));
  return new Vector(real_start, real_end);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_create_from_end(PointHandle end) {
  FALCON_C_API_BEGIN
  if (!end) {
    throw std::invalid_argument("Vector_create_from_end: end cannot be null");
  }
  PointSP real_end = std::make_shared<Point>(*static_cast<Point*>(end));
  return new Vector(real_end);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_create_from_quantities(MapConnectionQuantityHandle start,
                                           MapConnectionQuantityHandle end) {
  FALCON_C_API_BEGIN
  if (!start) {
    throw std::invalid_argument(
        "Vector_create_from_quantities: start cannot be null");
  }
  if (!end) {
    throw std::invalid_argument(
        "Vector_create_from_quantities: end cannot be null");
  }
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_start = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(start));
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_end = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(end));
  return new Vector(real_start, real_end);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_create_from_end_quantities(
    MapConnectionQuantityHandle end) {
  FALCON_C_API_BEGIN
  if (!end) {
    throw std::invalid_argument(
        "Vector_create_from_end_quantities: end cannot be null");
  }
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_end = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(end));
  return new Vector(real_end);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_create_from_doubles(MapConnectionDoubleHandle start,
                                        MapConnectionDoubleHandle end,
                                        SymbolUnitHandle          unit) {
  FALCON_C_API_BEGIN
  if (!start) {
    throw std::invalid_argument(
        "Vector_create_from_doubles: start cannot be null");
  }
  if (!end) {
    throw std::invalid_argument(
        "Vector_create_from_doubles: end cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument(
        "Vector_create_from_doubles: unit cannot be null");
  }
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, double>
          real_start = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              double>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  double>*>(start));
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, double>
          real_end = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              double>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  double>*>(end));
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  return new Vector(real_start, real_end, real_unit);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_create_from_end_doubles(MapConnectionDoubleHandle end,
                                            SymbolUnitHandle          unit) {
  FALCON_C_API_BEGIN
  if (!end) {
    throw std::invalid_argument(
        "Vector_create_from_end_doubles: end cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument(
        "Vector_create_from_end_doubles: unit cannot be null");
  }
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, double>
          real_end = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              double>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  double>*>(end));
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  return new Vector(real_end, real_unit);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_create_from_parent(MapConnectionQuantityHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "Vector_create_from_parent: items cannot be null");
  }
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_items = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(items));
  return new Vector(real_items);
  FALCON_C_API_END(nullptr)
}

void Vector_destroy(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_destroy: handle cannot be null");
  }
  delete static_cast<Vector*>(handle);
  FALCON_C_API_END()
}

PointHandle Vector_endPoint(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_endPoint: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new Point(*self.endPoint());
  FALCON_C_API_END(nullptr)
}

PointHandle Vector_startPoint(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_startPoint: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new Point(*self.startPoint());
  FALCON_C_API_END(nullptr)
}

MapConnectionQuantityHandle Vector_end_quantities(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_end_quantities: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, Quantity>(
          *self.end_quantities());
  FALCON_C_API_END(nullptr)
}

MapConnectionQuantityHandle Vector_start_quantities(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_start_quantities: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, Quantity>(
          *self.start_quantities());
  FALCON_C_API_END(nullptr)
}

MapConnectionDoubleHandle Vector_end_map(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_end_map: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, double>(
          *self.end_map());
  FALCON_C_API_END(nullptr)
}

MapConnectionDoubleHandle Vector_start_map(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_start_map: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, double>(
          *self.start_map());
  FALCON_C_API_END(nullptr)
}

ListConnectionHandle Vector_connections(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_connections: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(*self.connections());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle Vector_unit(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_unit: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::physics::units::SymbolUnit(*self.unit());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Vector_principle_connection(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_principle_connection: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *self.principle_connection());
  FALCON_C_API_END(nullptr)
}

double Vector_magnitude(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_magnitude: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return self.magnitude();
  FALCON_C_API_END(0.0)
}

void Vector_insert_or_assign(VectorHandle               handle,
                             ConnectionHandle           key,
                             PairQuantityQuantityHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_insert_or_assign: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Vector_insert_or_assign: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "Vector_insert_or_assign: value cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::generic::PairSP<Quantity, Quantity> real_value =
      std::make_shared<falcon_core::generic::Pair<Quantity, Quantity>>(
          *static_cast<falcon_core::generic::Pair<Quantity, Quantity>*>(value));
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  self.insert_or_assign(real_key, real_value);
  FALCON_C_API_END()
}

void Vector_insert(VectorHandle               handle,
                   ConnectionHandle           key,
                   PairQuantityQuantityHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_insert: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Vector_insert: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Vector_insert: value cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::generic::PairSP<Quantity, Quantity> real_value =
      std::make_shared<falcon_core::generic::Pair<Quantity, Quantity>>(
          *static_cast<falcon_core::generic::Pair<Quantity, Quantity>*>(value));
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  self.insert(real_key, real_value);
  FALCON_C_API_END()
}

PairQuantityQuantityHandle Vector_at(VectorHandle     handle,
                                     ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_at: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Vector_at: key cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  return new falcon_core::generic::Pair<Quantity, Quantity>(*self.at(real_key));
  FALCON_C_API_END(nullptr)
}

void Vector_erase(VectorHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_erase: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Vector_erase: key cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  FALCON_C_API_END()
}

size_t Vector_size(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_size: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return self.size();
  FALCON_C_API_END(0)
}

bool Vector_empty(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_empty: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return self.empty();
  FALCON_C_API_END(false)
}

void Vector_clear(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_clear: handle cannot be null");
  }
  Vector* self = static_cast<Vector*>(handle);
  self->clear();
  FALCON_C_API_END()
}

bool Vector_contains(VectorHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_contains: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("Vector_contains: key cannot be null");
  }
  Vector* self = static_cast<Vector*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  return self->contains(real_key);
  FALCON_C_API_END(false)
}

ListConnectionHandle Vector_keys(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_keys: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(*self.keys());
  FALCON_C_API_END(nullptr)
}
ListPairQuantityQuantityHandle Vector_values(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_values: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<
      falcon_core::generic::Pair<Quantity, Quantity>>(*self.values());
  FALCON_C_API_END(nullptr)
}

ListPairConnectionPairQuantityQuantityHandle Vector_items(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_items: handle cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<falcon_core::generic::Pair<
      falcon_core::physics::device_structures::Connection,
      falcon_core::generic::Pair<Quantity, Quantity>>>(self.items());
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_addition(VectorHandle handle, VectorHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_addition: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Vector_addition: other cannot be null");
  }
  Vector   self      = *static_cast<Vector*>(handle);
  VectorSP other_vec = std::make_shared<Vector>(*static_cast<Vector*>(other));
  VectorSP result    = self + other_vec;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_subtraction(VectorHandle handle, VectorHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_subtraction: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Vector_subtraction: other cannot be null");
  }
  Vector   self      = *static_cast<Vector*>(handle);
  VectorSP other_vec = std::make_shared<Vector>(*static_cast<Vector*>(other));
  VectorSP result    = self - other_vec;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_double_multiplication(VectorHandle handle, double scalar) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_double_multiplication: handle cannot be null");
  }
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self * scalar;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_int_multiplication(VectorHandle handle, int scalar) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_int_multiplication: handle cannot be null");
  }
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self * scalar;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_double_division(VectorHandle handle, double scalar) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_double_division: handle cannot be null");
  }
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self / scalar;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_int_division(VectorHandle handle, double scalar) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_int_division: handle cannot be null");
  }
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self / scalar;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_negation(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_negation: handle cannot be null");
  }
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = -self;
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_update_start_from_states(VectorHandle              handle,
                                             DeviceVoltageStatesHandle state) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_update_start_from_states: handle cannot be null");
  }
  if (!state) {
    throw std::invalid_argument(
        "Vector_update_start_from_states: state cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::communications::voltage_states::DeviceVoltageStatesSP
      real_state = std::make_shared<
          falcon_core::communications::voltage_states::DeviceVoltageStates>(
          *static_cast<falcon_core::communications::voltage_states::
                           DeviceVoltageStates*>(state));
  VectorSP result = self.update_start_from_states(real_state);
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}
VectorHandle Vector_translate_doubles(VectorHandle              handle,
                                      MapConnectionDoubleHandle point,
                                      SymbolUnitHandle          unit) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_translate_doubles: handle cannot be null");
  }
  if (!point) {
    throw std::invalid_argument(
        "Vector_translate_doubles: point cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument(
        "Vector_translate_doubles: unit cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, double>
          real_point = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              double>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  double>*>(point));
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  VectorSP result = self.translate(real_point, real_unit);
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_translate_quantities(VectorHandle                handle,
                                         MapConnectionQuantityHandle point) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_translate_quantities: handle cannot be null");
  }
  if (!point) {
    throw std::invalid_argument(
        "Vector_translate_quantities: point cannot be null");
  }
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_point = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(point));
  VectorSP result = self.translate(real_point);
  return new Vector(*result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_translate(VectorHandle handle, PointHandle point) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_translate: handle cannot be null");
  }
  if (!point) {
    throw std::invalid_argument("Vector_translate: point cannot be null");
  }
  Vector  self       = *static_cast<Vector*>(handle);
  PointSP real_point = std::make_shared<Point>(*static_cast<Point*>(point));
  auto    result     = self.translate(real_point);
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_translate_to_origin(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Vector_translate_to_origin: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.translate_to_origin();
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_double_extend(VectorHandle handle, double extension) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_double_extend: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.extend(extension);
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_int_extend(VectorHandle handle, int extension) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_int_extend: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.extend(extension);
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_double_shrink(VectorHandle handle, double extension) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_double_shrink: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.shrink(extension);
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_int_shrink(VectorHandle handle, int extension) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_int_shrink: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.shrink(extension);
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_unit_vector(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_unit_vector: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.unit_vector();
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_normalize(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_normalize: handle cannot be null");
  }
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.normalize();
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_project(VectorHandle handle, VectorHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_project: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Vector_project: other cannot be null");
  }
  Vector   self      = *static_cast<Vector*>(handle);
  VectorSP other_vec = std::make_shared<Vector>(*static_cast<Vector*>(other));
  auto     result    = self.project(other_vec);
  return new Vector(result);
  FALCON_C_API_END(nullptr)
}

void Vector_update_unit(VectorHandle handle, SymbolUnitHandle unit) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_update_unit: handle cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument("Vector_update_unit: unit cannot be null");
  }
  Vector*                                   self = static_cast<Vector*>(handle);
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  self->update_unit(real_unit);
  FALCON_C_API_END()
}

bool Vector_equal(VectorHandle a, VectorHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Vector_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Vector_equal: b cannot be null");
  }
  Vector self_a = *static_cast<Vector*>(a);
  Vector self_b = *static_cast<Vector*>(b);
  return self_a == self_b;
  FALCON_C_API_END(false)
}

bool Vector_not_equal(VectorHandle a, VectorHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Vector_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Vector_not_equal: b cannot be null");
  }
  Vector self_a = *static_cast<Vector*>(a);
  Vector self_b = *static_cast<Vector*>(b);
  return self_a != self_b;
  FALCON_C_API_END(false)
}

StringHandle Vector_to_json_string(VectorHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Vector_to_json_string: handle cannot be null");
  }
  Vector      self = *static_cast<Vector*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

VectorHandle Vector_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument("Vector_from_json_string: json cannot be null");
  }
  std::string raw_json = json->raw;
  auto        ptr      = Vector::from_json_string<Vector>(raw_json);
  return new Vector(*ptr);
  FALCON_C_API_END(nullptr)
}
}
