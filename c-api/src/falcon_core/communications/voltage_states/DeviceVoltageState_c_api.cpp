#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"

#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::communications::voltage_states;

extern "C" {
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
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              connection));
  falcon_core::physics::units::SymbolUnitSP real_unit =
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(unit));
  return new std::shared_ptr<DeviceVoltageState>(
      std::make_shared<DeviceVoltageState>(
          real_connection, voltage, real_unit));
  FALCON_C_API_END(nullptr)
}

void DeviceVoltageState_destroy(DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_destroy: handle cannot be null");
  }
  delete static_cast<DeviceVoltageStateSP*>(handle);
  FALCON_C_API_END()
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
  return new falcon_core::physics::units::SymbolUnit(*unit);
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
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(target_unit));
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

bool DeviceVoltageState_equal(DeviceVoltageStateHandle handle,
                              DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_equal: handle b cannot be null");
  }
  return *(static_cast<DeviceVoltageStateSP*>(handle)) ==
         *(static_cast<DeviceVoltageStateSP*>(other));
  FALCON_C_API_END(false)
}

bool DeviceVoltageState_not_equal(DeviceVoltageStateHandle handle,
                                  DeviceVoltageStateHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_not_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_not_equal: handle b cannot be null");
  }
  return *(static_cast<DeviceVoltageStateSP*>(handle)) !=
         *(static_cast<DeviceVoltageStateSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle DeviceVoltageState_to_json_string(
    DeviceVoltageStateHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_to_json_string: handle cannot be null");
  }
  std::string json =
      (*static_cast<DeviceVoltageStateSP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageState_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "DeviceVoltageState_from_json_string: json cannot be null");
  }
  auto ptr =
      DeviceVoltageState::from_json_string<DeviceVoltageState>(json->raw);
  return new DeviceVoltageStateSP(std::make_shared<DeviceVoltageState>(*ptr));
  FALCON_C_API_END(nullptr)
}
}
