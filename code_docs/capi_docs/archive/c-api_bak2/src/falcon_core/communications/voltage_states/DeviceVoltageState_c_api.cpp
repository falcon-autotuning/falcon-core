#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"

#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::communications::voltage_states;

extern "C" {
DEFINE_C_API_COPY(DeviceVoltageState);
DEFINE_C_API_DESTROY(DeviceVoltageState);
DEFINE_C_API_EQUAL(DeviceVoltageState);
DEFINE_C_API_NOT_EQUAL(DeviceVoltageState);
DEFINE_C_API_TO_JSON(DeviceVoltageState);
DEFINE_C_API_FROM_JSON(DeviceVoltageState);
DeviceVoltageStateHandle DeviceVoltageState_create(ConnectionHandle connection,
                                                   double           voltage,
                                                   SymbolUnitHandle unit) {
  FALCON_C_API_BEGIN
  if (!connection) {
    throw std::invalid_argument(
        "DeviceVoltageState_create: connection cannot be null");
  }
  if (!unit) {
    throw std::invalid_argument(
        "DeviceVoltageState_create: unit cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_connection =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          connection);
  falcon_core::physics::units::SymbolUnitSP real_unit =
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(unit);
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      real_connection, voltage, real_unit));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle DeviceVoltageState_connection(
    DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle)
    throw std::invalid_argument(
        "DeviceVoltageState_connection: handle cannot be null");
  const auto conn = (*static_cast<DeviceVoltageStateSP*>(handle))->connection();
  return new falcon_core::physics::device_structures::Connection(*conn);
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle DeviceVoltageState_unit(DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle)
    throw std::invalid_argument(
        "DeviceVoltageState_unit: handle cannot be null");
  const auto unit = (*static_cast<DeviceVoltageStateSP*>(handle))->unit();
  return new falcon_core::physics::units::SymbolUnitSP(unit);
  FALCON_C_API_END(nullptr)
}

double DeviceVoltageState_voltage(DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_voltage: handle cannot be null");
  }
  auto voltage = (*static_cast<DeviceVoltageStateSP*>(handle))->voltage();
  return voltage;
  FALCON_C_API_END(0.0)
}

double DeviceVoltageState_value(DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_value: handle cannot be null");
  }
  auto value = (*static_cast<DeviceVoltageStateSP*>(handle))->value();
  return value;
  FALCON_C_API_END(0.0)
}

void DeviceVoltageState_convert_to(DeviceVoltageStateHandle handle,
                                   SymbolUnitHandle         target_unit) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_convert_to: handle cannot be null");
  }
  if (!target_unit) {
    throw std::invalid_argument(
        "DeviceVoltageState_convert_to: target_unit cannot be null");
  }
  falcon_core::physics::units::SymbolUnitSP real_target_unit =
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(target_unit);
  (*static_cast<DeviceVoltageStateSP*>(handle))->convert_to(real_target_unit);
  FALCON_C_API_END()
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_int(
    DeviceVoltageStateHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_int: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = *self * other;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_double(
    DeviceVoltageStateHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_double: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = *self * other;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_quantity: other cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  DeviceVoltageStateSP other_quantity =
      *static_cast<DeviceVoltageStateSP*>(other);
  falcon_core::math::QuantitySP result = *self * other_quantity;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_int(
    DeviceVoltageStateHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_int: handle cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) *= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_double(
    DeviceVoltageStateHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_double: handle cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) *= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_quantity: other cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) *=
      *static_cast<DeviceVoltageStateSP*>(other);
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_divide_int(
    DeviceVoltageStateHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_int: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = *self / other;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_divide_double(
    DeviceVoltageStateHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_double: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = *self / other;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_divide_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_quantity: other cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  DeviceVoltageStateSP other_quantity =
      *static_cast<DeviceVoltageStateSP*>(other);
  falcon_core::math::QuantitySP result = *self / other_quantity;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_divide_equals_int(
    DeviceVoltageStateHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_int: handle cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) /= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_divide_equals_double(
    DeviceVoltageStateHandle handle, double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_double: handle cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) /= other;
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_divide_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_quantity: other cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) /=
      *static_cast<DeviceVoltageStateSP*>(other);
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_power(
    DeviceVoltageStateHandle handle, int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_power: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = *self ^ other;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_add_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_quantity: other cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  DeviceVoltageStateSP other_quantity =
      *static_cast<DeviceVoltageStateSP*>(other);
  falcon_core::math::QuantitySP result = *self + other_quantity;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_add_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_equals_quantity: other cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) +=
      *static_cast<DeviceVoltageStateSP*>(other);
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_quantity: other cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  DeviceVoltageStateSP other_quantity =
      *static_cast<DeviceVoltageStateSP*>(other);
  falcon_core::math::QuantitySP result = *self - other_quantity;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_equals_quantity: other cannot be null");
  }
  *(*static_cast<DeviceVoltageStateSP*>(handle)) -=
      *static_cast<DeviceVoltageStateSP*>(other);
  return handle;
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_negate(
    DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_negate: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = -*self;
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_abs(
    DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_abs: handle cannot be null");
  }
  DeviceVoltageStateSP self = *static_cast<DeviceVoltageStateSP*>(handle);
  falcon_core::math::QuantitySP result = self->abs();
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(
      self->connection(), result->value(), self->unit()));
  FALCON_C_API_END(nullptr)
}
}
