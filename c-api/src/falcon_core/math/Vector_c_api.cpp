#include "falcon_core/math/Vector_c_api.h"

#include <falcon_core/math/Vector.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {

VectorHandle Vector_create(PointHandle start, PointHandle end) {
  PointSP real_start = std::make_shared<Point>(*static_cast<Point*>(start));
  PointSP real_end   = std::make_shared<Point>(*static_cast<Point*>(end));
  return new Vector(real_start, real_end);
}

VectorHandle Vector_create_from_end(PointHandle end) {
  PointSP real_end = std::make_shared<Point>(*static_cast<Point*>(end));
  return new Vector(real_end);
}

VectorHandle Vector_create_from_quantities(MapConnectionQuantityHandle start,
                                           MapConnectionQuantityHandle end) {
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
}

VectorHandle Vector_create_from_end_quantities(
    MapConnectionQuantityHandle end) {
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_end = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(end));
  return new Vector(real_end);
}

VectorHandle Vector_create_from_doubles(MapConnectionDoubleHandle start,
                                        MapConnectionDoubleHandle end,
                                        SymbolUnitHandle          unit) {
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
}

VectorHandle Vector_create_from_end_doubles(MapConnectionDoubleHandle end,
                                            SymbolUnitHandle          unit) {
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
}

VectorHandle Vector_create_from_parent(MapConnectionQuantityHandle items) {
  falcon_core::generic::
      MapSP<falcon_core::physics::device_structures::Connection, Quantity>
          real_items = std::make_shared<falcon_core::generic::Map<
              falcon_core::physics::device_structures::Connection,
              Quantity>>(
              *static_cast<falcon_core::generic::Map<
                  falcon_core::physics::device_structures::Connection,
                  Quantity>*>(items));
  return new Vector(real_items);
}

void Vector_destroy(VectorHandle handle) {
  delete static_cast<Vector*>(handle);
}

PointHandle Vector_endPoint(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new Point(*self.endPoint());
}

PointHandle Vector_startPoint(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new Point(*self.startPoint());
}

MapConnectionQuantityHandle Vector_end_quantities(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, Quantity>(
          *self.end_quantities());
}

MapConnectionQuantityHandle Vector_start_quantities(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, Quantity>(
          *self.start_quantities());
}

MapConnectionDoubleHandle Vector_end_map(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, double>(
          *self.end_map());
}

MapConnectionDoubleHandle Vector_start_map(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::
      Map<falcon_core::physics::device_structures::Connection, double>(
          *self.start_map());
}

ListConnectionHandle Vector_connections(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(*self.connections());
}

SymbolUnitHandle Vector_unit(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::physics::units::SymbolUnit(*self.unit());
}

ConnectionHandle Vector_principle_connection(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *self.principle_connection());
}

double Vector_magnitude(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return self.magnitude();
}

void Vector_insert_or_assign(VectorHandle               handle,
                             ConnectionHandle           key,
                             PairQuantityQuantityHandle value) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::generic::PairSP<Quantity, Quantity> real_value =
      std::make_shared<falcon_core::generic::Pair<Quantity, Quantity>>(
          *static_cast<falcon_core::generic::Pair<Quantity, Quantity>*>(value));
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  self.insert_or_assign(real_key, real_value);
}

void Vector_insert(VectorHandle               handle,
                   ConnectionHandle           key,
                   PairQuantityQuantityHandle value) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::generic::PairSP<Quantity, Quantity> real_value =
      std::make_shared<falcon_core::generic::Pair<Quantity, Quantity>>(
          *static_cast<falcon_core::generic::Pair<Quantity, Quantity>*>(value));
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  self.insert(real_key, real_value);
}

PairQuantityQuantityHandle Vector_at(VectorHandle     handle,
                                     ConnectionHandle key) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  return new falcon_core::generic::Pair<Quantity, Quantity>(*self.at(real_key));
}

void Vector_erase(VectorHandle handle, ConnectionHandle key) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
}

size_t Vector_size(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return self.size();
}

bool Vector_empty(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return self.empty();
}

void Vector_clear(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  self.clear();
}

bool Vector_contains(VectorHandle handle, ConnectionHandle key) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              key));
  return self.contains(real_key);
}

ListConnectionHandle Vector_keys(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(*self.keys());
}
ListPairQuantityQuantityHandle Vector_values(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<
      falcon_core::generic::Pair<Quantity, Quantity>>(*self.values());
}

ListPairConnectionPairQuantityQuantityHandle Vector_items(VectorHandle handle) {
  Vector self = *static_cast<Vector*>(handle);
  return new falcon_core::generic::List<falcon_core::generic::Pair<
      falcon_core::physics::device_structures::Connection,
      falcon_core::generic::Pair<Quantity, Quantity>>>(self.items());
}

VectorHandle Vector_addition(VectorHandle handle, VectorHandle other) {
  Vector   self      = *static_cast<Vector*>(handle);
  VectorSP other_vec = std::make_shared<Vector>(*static_cast<Vector*>(other));
  VectorSP result    = self + other_vec;
  return new Vector(*result);
}

VectorHandle Vector_subtraction(VectorHandle handle, VectorHandle other) {
  Vector   self      = *static_cast<Vector*>(handle);
  VectorSP other_vec = std::make_shared<Vector>(*static_cast<Vector*>(other));
  VectorSP result    = self - other_vec;
  return new Vector(*result);
}

VectorHandle Vector_double_multiplication(VectorHandle handle, double scalar) {
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self * scalar;
  return new Vector(*result);
}

VectorHandle Vector_int_multiplication(VectorHandle handle, int scalar) {
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self * scalar;
  return new Vector(*result);
}

VectorHandle Vector_double_division(VectorHandle handle, double scalar) {
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self / scalar;
  return new Vector(*result);
}

VectorHandle Vector_int_division(VectorHandle handle, double scalar) {
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = self / scalar;
  return new Vector(*result);
}

VectorHandle Vector_negation(VectorHandle handle) {
  Vector   self   = *static_cast<Vector*>(handle);
  VectorSP result = -self;
  return new Vector(*result);
}

VectorHandle Vector_update_start_from_states(VectorHandle              handle,
                                             DeviceVoltageStatesHandle state) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::communications::voltage_states::DeviceVoltageStatesSP
      real_state = std::make_shared<
          falcon_core::communications::voltage_states::DeviceVoltageStates>(
          *static_cast<falcon_core::communications::voltage_states::
                           DeviceVoltageStates*>(state));
  VectorSP result = self.update_start_from_states(real_state);
  return new Vector(*result);
}
VectorHandle Vector_translate_doubles(VectorHandle              handle,
                                      MapConnectionDoubleHandle point,
                                      SymbolUnitHandle          unit) {
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
}

VectorHandle Vector_translate_quantities(VectorHandle                handle,
                                         MapConnectionQuantityHandle point) {
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
}

VectorHandle Vector_translate(VectorHandle handle, PointHandle point) {
  Vector  self       = *static_cast<Vector*>(handle);
  PointSP real_point = std::make_shared<Point>(*static_cast<Point*>(point));
  auto    result     = self.translate(real_point);
  return new Vector(result);
}

VectorHandle Vector_translate_to_origin(VectorHandle handle) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.translate_to_origin();
  return new Vector(result);
}

VectorHandle Vector_double_extend(VectorHandle handle, double extension) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.extend(extension);
  return new Vector(result);
}

VectorHandle Vector_int_extend(VectorHandle handle, int extension) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.extend(extension);
  return new Vector(result);
}

VectorHandle Vector_double_shrink(VectorHandle handle, double extension) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.shrink(extension);
  return new Vector(result);
}

VectorHandle Vector_int_shrink(VectorHandle handle, int extension) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.shrink(extension);
  return new Vector(result);
}

VectorHandle Vector_unit_vector(VectorHandle handle) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.unit_vector();
  return new Vector(result);
}

VectorHandle Vector_normalize(VectorHandle handle) {
  Vector self   = *static_cast<Vector*>(handle);
  auto   result = self.normalize();
  return new Vector(result);
}

VectorHandle Vector_project(VectorHandle handle, VectorHandle other) {
  Vector   self      = *static_cast<Vector*>(handle);
  VectorSP other_vec = std::make_shared<Vector>(*static_cast<Vector*>(other));
  auto     result    = self.project(other_vec);
  return new Vector(result);
}

void Vector_update_unit(VectorHandle handle, SymbolUnitHandle unit) {
  Vector self = *static_cast<Vector*>(handle);
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  self.update_unit(real_unit);
}

bool Vector_equal(VectorHandle a, VectorHandle b) {
  Vector self_a = *static_cast<Vector*>(a);
  Vector self_b = *static_cast<Vector*>(b);
  return self_a == self_b;
}

bool Vector_not_equal(VectorHandle a, VectorHandle b) {
  Vector self_a = *static_cast<Vector*>(a);
  Vector self_b = *static_cast<Vector*>(b);
  return self_a != self_b;
}

StringHandle Vector_to_json_string(VectorHandle handle) {
  Vector      self = *static_cast<Vector*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

VectorHandle Vector_from_json_string(StringHandle json) {
  std::string raw_json = json->raw;
  auto        ptr      = Vector::from_json_string<Vector>(raw_json);
  return new Vector(*ptr);
}

#ifdef __cplusplus
}
#endif
