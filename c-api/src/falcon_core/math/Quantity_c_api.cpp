#include "falcon_core/math/Quantity_c_api.h"

#include <falcon_core/math/Quantity.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {
QuantityHandle Quantity_create(double value, SymbolUnitHandle unit) {
  FALCON_C_API_BEGIN
  if (!unit) {
    throw std::invalid_argument("Quantity_create: unit cannot be null");
  }
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  return new Quantity(value, real_unit);
  FALCON_C_API_END(nullptr)
}

void Quantity_destroy(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_destroy: handle cannot be null");
  }
  delete static_cast<Quantity*>(handle);
  FALCON_C_API_END()
}

double Quantity_value(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_value: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return self.value();
  FALCON_C_API_END(0.0)
}

SymbolUnitHandle Quantity_unit(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_unit: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new falcon_core::physics::units::SymbolUnit(*self.unit());
  FALCON_C_API_END(nullptr)
}

void Quantity_convert_to(QuantityHandle handle, SymbolUnitHandle target_unit) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_convert_to: handle cannot be null");
  }
  if (!target_unit) {
    throw std::invalid_argument(
        "Quantity_convert_to: target_unit cannot be null");
  }
  Quantity* self = static_cast<Quantity*>(handle);
  falcon_core::physics::units::SymbolUnitSP real_target_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(target_unit));
  self->convert_to(real_target_unit);
  FALCON_C_API_END()
}

QuantityHandle Quantity_multiply_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_multiply_int: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self * other));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_double(QuantityHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_double: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self * other));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_quantity(QuantityHandle handle,
                                          QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_multiply_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self * oself));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_equals_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_equals_int: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  self *= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_equals_double(QuantityHandle handle,
                                               double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_equals_double: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  self *= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_multiply_equals_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self *= oself;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_divide_int: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self / other));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_double(QuantityHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_double: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self / other));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_quantity(QuantityHandle handle,
                                        QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_divide_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self / oself));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_equals_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_equals_int: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  self /= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_equals_double(QuantityHandle handle,
                                             double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_equals_double: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  self /= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_equals_quantity(QuantityHandle handle,
                                               QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_divide_equals_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self /= oself;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_power(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_power: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self ^ other));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_add_quantity(QuantityHandle handle,
                                     QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_add_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Quantity_add_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self + oself));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_add_equals_quantity(QuantityHandle handle,
                                            QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_add_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_add_equals_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self += oself;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_subtract_quantity(QuantityHandle handle,
                                          QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_subtract_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_subtract_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  return new Quantity(*(self - oself));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_subtract_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_subtract_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Quantity_subtract_equals_quantity: other cannot be null");
  }
  Quantity   self  = *static_cast<Quantity*>(handle);
  QuantitySP oself = std::make_shared<Quantity>(*static_cast<Quantity*>(other));
  self -= oself;
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_negate(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_negate: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(-self));
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_abs(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_abs: handle cannot be null");
  }
  Quantity self = *static_cast<Quantity*>(handle);
  return new Quantity(*(self.abs()));
  FALCON_C_API_END(nullptr)
}

bool Quantity_equal(QuantityHandle a, QuantityHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Quantity_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Quantity_equal: b cannot be null");
  }
  Quantity self_a = *static_cast<Quantity*>(a);
  Quantity self_b = *static_cast<Quantity*>(b);
  return self_a == self_b;
  FALCON_C_API_END(false)
}

bool Quantity_not_equal(QuantityHandle a, QuantityHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Quantity_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Quantity_not_equal: b cannot be null");
  }
  Quantity self_a = *static_cast<Quantity*>(a);
  Quantity self_b = *static_cast<Quantity*>(b);
  return self_a != self_b;
  FALCON_C_API_END(false)
}

StringHandle Quantity_to_json_string(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_to_json_string: handle cannot be null");
  }
  Quantity    self = *static_cast<Quantity*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Quantity_from_json_string: json cannot be null");
  }
  auto ptr = Quantity::from_json_string<Quantity>(json->raw);
  return new Quantity(*ptr);
  FALCON_C_API_END(nullptr)
}
}
