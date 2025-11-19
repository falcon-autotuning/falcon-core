#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"

#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::communications::voltage_states;

extern "C" {
DeviceVoltageStatesHandle DeviceVoltageStates_create_empty() {
  FALCON_C_API_BEGIN
  return new DeviceVoltageStates(DeviceVoltageStates());
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStatesHandle DeviceVoltageStates_create(
    ListDeviceVoltageStateHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "DeviceVoltageStates_create: items cannot be null");
  }
  falcon_core::generic::ListSP<DeviceVoltageState> list =
      std::make_shared<falcon_core::generic::List<DeviceVoltageState>>(
          *static_cast<falcon_core::generic::List<DeviceVoltageState>*>(items));
  return new DeviceVoltageStates(list);
  FALCON_C_API_END(nullptr)
}

void DeviceVoltageStates_destroy(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_destroy: handle cannot be null");
  }
  delete static_cast<DeviceVoltageStates*>(handle);
  FALCON_C_API_END()
}

ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_states: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return new falcon_core::generic::List<
      falcon_core::communications::voltage_states::DeviceVoltageState>(
      *self.states());
  FALCON_C_API_END(nullptr)
}

void DeviceVoltageStates_add_state(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  state) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_add_state: handle cannot be null");
  }
  if (!state) {
    throw std::invalid_argument(
        "DeviceVoltageStates_add_state: state cannot be null");
  }
  DeviceVoltageStates* self = static_cast<DeviceVoltageStates*>(handle);
  falcon_core::communications::voltage_states::DeviceVoltageStateSP real_state =
      std::make_shared<
          falcon_core::communications::voltage_states::DeviceVoltageState>(
          *static_cast<
              falcon_core::communications::voltage_states::DeviceVoltageState*>(
              state));
  self->add_state(real_state);
  FALCON_C_API_END()
}

DeviceVoltageStatesHandle DeviceVoltageStates_find_state(
    DeviceVoltageStatesHandle handle, ConnectionHandle connection) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_find_state: handle cannot be null");
  }
  if (!connection) {
    throw std::invalid_argument(
        "DeviceVoltageStates_find_state: connection cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_connection =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              connection));
  falcon_core::communications::voltage_states::DeviceVoltageStateSP result =
      self.find_state(real_connection);
  return new falcon_core::communications::voltage_states::DeviceVoltageState(
      *result);
  FALCON_C_API_END(nullptr)
}

PointHandle DeviceVoltageStates_to_point(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_to_point: handle cannot be null");
  }
  DeviceVoltageStates        self = *static_cast<DeviceVoltageStates*>(handle);
  falcon_core::math::PointSP result = self.to_point();
  return new falcon_core::math::Point(*result);
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStatesHandle DeviceVoltageStates_intersection(
    DeviceVoltageStatesHandle handle, DeviceVoltageStatesHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DeviceVoltageStates_intersection: other cannot be null");
  }
  DeviceVoltageStates   self       = *static_cast<DeviceVoltageStates*>(handle);
  DeviceVoltageStatesSP other_self = std::make_shared<DeviceVoltageStates>(
      *static_cast<DeviceVoltageStates*>(other));
  falcon_core::communications::voltage_states::DeviceVoltageStates result =
      self.intersection(other_self);
  return new falcon_core::communications::voltage_states::DeviceVoltageStates(
      result);
  FALCON_C_API_END(nullptr)
}

void DeviceVoltageStates_push_back(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "DeviceVoltageStates_push_back: value cannot be null");
  }
  DeviceVoltageStates* self = static_cast<DeviceVoltageStates*>(handle);
  falcon_core::communications::voltage_states::DeviceVoltageStateSP value_ptr =
      std::make_shared<
          falcon_core::communications::voltage_states::DeviceVoltageState>(
          *static_cast<
              falcon_core::communications::voltage_states::DeviceVoltageState*>(
              value));
  self->push_back(value_ptr);
  FALCON_C_API_END()
}

size_t DeviceVoltageStates_size(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_size: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return self.size();
  FALCON_C_API_END(0)
}

bool DeviceVoltageStates_empty(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_empty: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return self.empty();
  FALCON_C_API_END(false)
}

void DeviceVoltageStates_erase_at(DeviceVoltageStatesHandle handle,
                                  size_t                    idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_erase_at: handle cannot be null");
  }
  DeviceVoltageStates* self = static_cast<DeviceVoltageStates*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void DeviceVoltageStates_clear(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_clear: handle cannot be null");
  }
  DeviceVoltageStates* self = static_cast<DeviceVoltageStates*>(handle);
  self->clear();
  FALCON_C_API_END()
}

const DeviceVoltageStateHandle DeviceVoltageStates_const_at(
    DeviceVoltageStatesHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_const_at: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return new falcon_core::communications::voltage_states::DeviceVoltageState(
      *(self.at(idx)));
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStateHandle DeviceVoltageStates_at(
    DeviceVoltageStatesHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_at: handle cannot be null");
  }
  DeviceVoltageStates self  = *static_cast<DeviceVoltageStates*>(handle);
  auto                state = self.at(idx);
  return new falcon_core::communications::voltage_states::DeviceVoltageState(
      *state);
  FALCON_C_API_END(nullptr)
}

ListDeviceVoltageStateHandle DeviceVoltageStates_items(
    DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_items: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return new falcon_core::generic::List<
      falcon_core::communications::voltage_states::DeviceVoltageState>(
      self.items());
  FALCON_C_API_END(nullptr)
}

bool DeviceVoltageStates_contains(DeviceVoltageStatesHandle handle,
                                  DeviceVoltageStateHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "DeviceVoltageStates_contains: value cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  falcon_core::communications::voltage_states::DeviceVoltageStateSP real_value =
      std::make_shared<
          falcon_core::communications::voltage_states::DeviceVoltageState>(
          *static_cast<
              falcon_core::communications::voltage_states::DeviceVoltageState*>(
              value));
  return self.contains(real_value);
  FALCON_C_API_END(false)
}

size_t DeviceVoltageStates_index(DeviceVoltageStatesHandle handle,
                                 DeviceVoltageStateHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "DeviceVoltageStates_index: value cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  falcon_core::communications::voltage_states::DeviceVoltageStateSP real_value =
      std::make_shared<
          falcon_core::communications::voltage_states::DeviceVoltageState>(
          *static_cast<
              falcon_core::communications::voltage_states::DeviceVoltageState*>(
              value));
  return self.index(real_value);
  FALCON_C_API_END(0)
}

bool DeviceVoltageStates_equal(DeviceVoltageStatesHandle a,
                               DeviceVoltageStatesHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("DeviceVoltageStates_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("DeviceVoltageStates_equal: b cannot be null");
  }
  return *(static_cast<DeviceVoltageStates*>(a)) ==
         *(static_cast<DeviceVoltageStates*>(b));
  FALCON_C_API_END(false)
}

bool DeviceVoltageStates_not_equal(DeviceVoltageStatesHandle a,
                                   DeviceVoltageStatesHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "DeviceVoltageStates_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "DeviceVoltageStates_not_equal: b cannot be null");
  }
  return *(static_cast<DeviceVoltageStates*>(a)) !=
         *(static_cast<DeviceVoltageStates*>(b));
  FALCON_C_API_END(false)
}

StringHandle DeviceVoltageStates_to_json_string(
    DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_to_json_string: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStatesHandle DeviceVoltageStates_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "DeviceVoltageStates_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new DeviceVoltageStates(
      *DeviceVoltageStates::from_json_string<DeviceVoltageStates>(json_str));
  FALCON_C_API_END(nullptr)
}
}
