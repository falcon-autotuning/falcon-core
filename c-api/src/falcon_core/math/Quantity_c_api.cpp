#include "falcon_core/math/Quantity_c_api.h"

#include <falcon_core/math/Quantity.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {

QuantityHandle Quantity_create(double value, SymbolUnitHandle unit) {
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  return new Quantity(value, real_unit);
}

void Quantity_destroy(QuantityHandle handle) {
  delete static_cast<Quantity*>(handle);
}

double Quantity_value(QuantityHandle handle) {
  Quantity self = *static_cast<Quantity*>(handle);
  return self.value();
}

SymbolUnitHandle Quantity_unit(QuantityHandle handle) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new falcon_core::physics::units::SymbolUnit(*self.unit());
}

void Quantity_convert_to(QuantityHandle handle, SymbolUnitHandle target_unit) {
  Quantity self = *static_cast<Quantity*>(handle);
  falcon_core::physics::units::SymbolUnitSP real_target_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(target_unit));
  self.convert_to(real_target_unit);
}

QuantityHandle Quantity_multiply_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self * other));
}

QuantityHandle Quantity_multiply_double(QuantityHandle handle, double other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self * other));
}

QuantityHandle Quantity_multiply_quantity(QuantityHandle handle,
                                          QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self * oself));
}

QuantityHandle Quantity_multiply_equals_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self *= other;
  return handle;
}

QuantityHandle Quantity_multiply_equals_double(QuantityHandle handle,
                                               double         other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self *= other;
  return handle;
}

QuantityHandle Quantity_multiply_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self *= oself;
  return handle;
}

QuantityHandle Quantity_divide_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self / other));
}

QuantityHandle Quantity_divide_double(QuantityHandle handle, double other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self / other));
}

QuantityHandle Quantity_divide_quantity(QuantityHandle handle,
                                        QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self / oself));
}

QuantityHandle Quantity_divide_equals_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self /= other;
  return handle;
}

QuantityHandle Quantity_divide_equals_double(QuantityHandle handle,
                                             double         other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self /= other;
  return handle;
}

QuantityHandle Quantity_divide_equals_quantity(QuantityHandle handle,
                                               QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self /= oself;
  return handle;
}

QuantityHandle Quantity_power(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self ^ other));
}

QuantityHandle Quantity_add_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self + other));
}

QuantityHandle Quantity_add_double(QuantityHandle handle, double other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self + other));
}

QuantityHandle Quantity_add_quantity(QuantityHandle handle,
                                     QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self + oself));
}

QuantityHandle Quantity_add_equals_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self += other;
  return handle;
}

QuantityHandle Quantity_add_equals_double(QuantityHandle handle, double other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self += other;
  return handle;
}

QuantityHandle Quantity_add_equals_quantity(QuantityHandle handle,
                                            QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self += oself;
  return handle;
}

QuantityHandle Quantity_subtract_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self - other));
}

QuantityHandle Quantity_subtract_double(QuantityHandle handle, double other) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self - other));
}

QuantityHandle Quantity_subtract_quantity(QuantityHandle handle,
                                          QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self - oself));
}

QuantityHandle Quantity_subtract_equals_int(QuantityHandle handle, int other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self -= other;
  return handle;
}

QuantityHandle Quantity_subtract_equals_double(QuantityHandle handle,
                                               double         other) {
  Quantity self = *static_cast<Quantity*>(handle);
  self -= other;
  return handle;
}

QuantityHandle Quantity_subtract_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other) {
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self -= oself;
  return handle;
}

QuantityHandle Quantity_negate(QuantityHandle handle) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(-self));
}

QuantityHandle Quantity_abs(QuantityHandle handle) {
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self.abs()));
}

bool Quantity_equal(QuantityHandle a, QuantityHandle b) {
  Quantity self_a = *static_cast<Quantity*>(a);
  Quantity self_b = *static_cast<Quantity*>(b);
  return self_a == self_b;
}

bool Quantity_not_equal(QuantityHandle a, QuantityHandle b) {
  Quantity self_a = *static_cast<Quantity*>(a);
  Quantity self_b = *static_cast<Quantity*>(b);
  return self_a != self_b;
}

StringHandle Quantity_to_json_string(QuantityHandle handle) {
  Quantity    self = *static_cast<Quantity*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

QuantityHandle Quantity_from_json_string(StringHandle json) {
  auto ptr = Quantity::from_json_string<Quantity>(json->raw);
  return new Quantity(*ptr);
}

#ifdef __cplusplus
}
#endif
