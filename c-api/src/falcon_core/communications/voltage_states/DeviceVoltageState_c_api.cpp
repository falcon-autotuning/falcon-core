#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"

#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::communications::voltage_states;

DeviceVoltageStateHandle DeviceVoltageState_create(ConnectionHandle connection,
                                                   double           voltage,
                                                   SymbolUnitHandle unit) {
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
  return new DeviceVoltageState(real_connection, voltage, real_unit);
}

void DeviceVoltageState_destroy(DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_destroy: handle cannot be null");
  }
  delete static_cast<DeviceVoltageState*>(handle);
}

ConnectionHandle DeviceVoltageState_connection(
    DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_connection: handle cannot be null");
  }
  const auto conn = static_cast<DeviceVoltageState*>(handle)->connection();
  return static_cast<ConnectionHandle>(conn.get());
}

double DeviceVoltageState_voltage(DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_voltage: handle cannot be null");
  }
  auto voltage = static_cast<DeviceVoltageState*>(handle)->voltage();
  return voltage;
}

double DeviceVoltageState_value(DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_value: handle cannot be null");
  }
  auto value = static_cast<DeviceVoltageState*>(handle)->value();
  return value;
}

SymbolUnitHandle DeviceVoltageState_unit(DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_unit: handle cannot be null");
  }
  const auto unit = static_cast<DeviceVoltageState*>(handle)->unit();
  return static_cast<SymbolUnitHandle>(unit.get());
}

void DeviceVoltageState_convert_to(DeviceVoltageStateHandle handle,
                                   SymbolUnitHandle         target_unit) {
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
  static_cast<DeviceVoltageState*>(handle)->convert_to(real_target_unit);
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_int: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) * other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_double: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) * other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_quantity: other cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) *
          std::make_shared<DeviceVoltageState>(
              *static_cast<DeviceVoltageState*>(other)))
      .get();
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_int: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) *= other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_double: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) *= other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_multiply_equals_quantity: other cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) *=
      std::make_shared<DeviceVoltageState>(
          *static_cast<DeviceVoltageState*>(other));
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_divide_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_int: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) / other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_divide_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_double: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) / other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_divide_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_quantity: other cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) /
          std::make_shared<DeviceVoltageState>(
              *static_cast<DeviceVoltageState*>(other)))
      .get();
}

DeviceVoltageStateHandle DeviceVoltageState_divide_equals_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_int: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) /= other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_divide_equals_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_double: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) /= other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_divide_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_divide_equals_quantity: other cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) /=
      std::make_shared<DeviceVoltageState>(
          *static_cast<DeviceVoltageState*>(other));
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_power(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_power: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) ^ other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_add_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_int: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) + other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_add_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_double: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) + other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_add_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_quantity: other cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) +
          std::make_shared<DeviceVoltageState>(
              *static_cast<DeviceVoltageState*>(other)))
      .get();
}

DeviceVoltageStateHandle DeviceVoltageState_add_equals_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_equals_int: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) += other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_add_equals_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_equals_double: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) += other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_add_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_add_equals_quantity: other cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) +=
      std::make_shared<DeviceVoltageState>(
          *static_cast<DeviceVoltageState*>(other));
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_int: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) - other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_double: handle cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) - other).get();
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_quantity: other cannot be null");
  }
  return (*static_cast<DeviceVoltageState*>(handle) -
          std::make_shared<DeviceVoltageState>(
              *static_cast<DeviceVoltageState*>(other)))
      .get();
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_int(
    DeviceVoltageStateHandle handle, int other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_equals_int: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) -= other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_double(
    DeviceVoltageStateHandle handle, double other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_equals_double: handle cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) -= other;
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_equals_quantity: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageState_subtract_equals_quantity: other cannot be null");
  }
  (*static_cast<DeviceVoltageState*>(handle)) -=
      std::make_shared<DeviceVoltageState>(
          *static_cast<DeviceVoltageState*>(other));
  return handle;
}

DeviceVoltageStateHandle DeviceVoltageState_negate(
    DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_negate: handle cannot be null");
  }
  return (-*static_cast<DeviceVoltageState*>(handle)).get();
}

DeviceVoltageStateHandle DeviceVoltageState_abs(
    DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_abs: handle cannot be null");
  }
  return (static_cast<DeviceVoltageState*>(handle)->abs()).get();
}

bool DeviceVoltageState_equal(DeviceVoltageStateHandle a,
                              DeviceVoltageStateHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "DeviceVoltageState_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "DeviceVoltageState_equal: handle b cannot be null");
  }
  return *(static_cast<DeviceVoltageState*>(a)) ==
         *(static_cast<DeviceVoltageState*>(b));
}

bool DeviceVoltageState_not_equal(DeviceVoltageStateHandle a,
                                  DeviceVoltageStateHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "DeviceVoltageState_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "DeviceVoltageState_not_equal: handle b cannot be null");
  }
  return *(static_cast<DeviceVoltageState*>(a)) !=
         *(static_cast<DeviceVoltageState*>(b));
}

StringHandle DeviceVoltageState_to_json_string(
    DeviceVoltageStateHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageState_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<DeviceVoltageState*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

DeviceVoltageStateHandle DeviceVoltageState_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "DeviceVoltageState_from_json_string: json cannot be null");
  }
  auto ptr =
      DeviceVoltageState::from_json_string<DeviceVoltageState>(json->raw);
  return new DeviceVoltageState(*ptr);
}
