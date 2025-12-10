#include "falcon_core/math/Quantity_c_api.h"

#include <falcon_core/math/Quantity.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::math;

extern "C" {
DEFINE_C_API_COPY(Quantity);
DEFINE_C_API_DESTROY(Quantity);
DEFINE_C_API_EQUAL(Quantity);
DEFINE_C_API_NOT_EQUAL(Quantity);
DEFINE_C_API_TO_JSON(Quantity);
DEFINE_C_API_FROM_JSON(Quantity);
QuantityHandle Quantity_create(double value, SymbolUnitHandle unit) {
  FALCON_C_API_BEGIN
  if (!unit) {
    throw std::invalid_argument("Quantity_create: unit cannot be null");
  }
  falcon_core::physics::units::SymbolUnitSP real_unit =
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(unit);
  return new QuantitySP(std::make_shared<Quantity>(value, real_unit));
  FALCON_C_API_END(nullptr)
}

double Quantity_value(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_value: handle cannot be null");
  }
  return (*static_cast<QuantitySP*>(handle))->value();
  FALCON_C_API_END(0.0)
}

SymbolUnitHandle Quantity_unit(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_unit: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new falcon_core::physics::units::SymbolUnit(*self->unit());
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
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  falcon_core::physics::units::SymbolUnitSP real_target_unit =
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(target_unit);
  self->convert_to(real_target_unit);
  FALCON_C_API_END()
}

QuantityHandle Quantity_multiply_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_multiply_int: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(*self * other);
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_double(QuantityHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_double: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(*self * other);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  return new QuantitySP(*self * oself);
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_multiply_equals_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_multiply_equals_int: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  self->operator*=(other);
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
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  self->operator*=(other);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  self->operator*=(oself);
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_divide_int: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(*self / other);
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_double(QuantityHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_double: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(*self / other);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  return new QuantitySP(*self / oself);
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_divide_equals_int(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Quantity_divide_equals_int: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  self->operator/=(other);
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
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  self->operator/=(other);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  self->operator/=(oself);
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_power(QuantityHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_power: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(*self ^ other);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  return new QuantitySP(*self + oself);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  self->operator+=(oself);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  return new QuantitySP(*self - oself);
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
  QuantitySP self  = *static_cast<QuantitySP*>(handle);
  QuantitySP oself = *static_cast<QuantitySP*>(other);
  self->operator-=(oself);
  return handle;
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_negate(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_negate: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(-*self);
  FALCON_C_API_END(nullptr)
}

QuantityHandle Quantity_abs(QuantityHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Quantity_abs: handle cannot be null");
  }
  QuantitySP self = *static_cast<QuantitySP*>(handle);
  return new QuantitySP(self->abs());
  FALCON_C_API_END(nullptr)
}
}
