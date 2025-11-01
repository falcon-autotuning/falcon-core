#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"

#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::communications::voltage_states;

DeviceVoltageStatesHandle DeviceVoltageStates_create_empty() {
  return new DeviceVoltageStates(DeviceVoltageStates());
}

DeviceVoltageStatesHandle DeviceVoltageStates_create(
    ListDeviceVoltageStateHandle items) {
  return new DeviceVoltageStates(DeviceVoltageStates());
}

void DeviceVoltageStates_destroy(DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_destroy: handle cannot be null");
  }
  delete static_cast<DeviceVoltageStates*>(handle);
}

ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_states: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return new falcon_core::generic::List<
      falcon_core::communications::voltage_states::DeviceVoltageState>(
      *self.states());
}

void DeviceVoltageStates_add_state(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  state) {
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
}

DeviceVoltageStatesHandle DeviceVoltageStates_find_state(
    DeviceVoltageStatesHandle handle, ConnectionHandle connection) {
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
}

PointHandle DeviceVoltageStates_to_point(DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_to_point: handle cannot be null");
  }
  DeviceVoltageStates        self = *static_cast<DeviceVoltageStates*>(handle);
  falcon_core::math::PointSP result = self.to_point();
  return new falcon_core::math::Point(*result);
}

DeviceVoltageStatesHandle DeviceVoltageStates_intersection(
    DeviceVoltageStatesHandle handle, DeviceVoltageStatesHandle other) {
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
}

void DeviceVoltageStates_push_back(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  value) {
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
}

size_t DeviceVoltageStates_size(DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_size: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return self.size();
}

bool DeviceVoltageStates_empty(DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_empty: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return self.empty();
}

void DeviceVoltageStates_erase_at(DeviceVoltageStatesHandle handle,
                                  size_t                    idx) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_erase_at: handle cannot be null");
  }
  DeviceVoltageStates* self = static_cast<DeviceVoltageStates*>(handle);
  self->erase_at(idx);
}

void DeviceVoltageStates_clear(DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_clear: handle cannot be null");
  }
  DeviceVoltageStates* self = static_cast<DeviceVoltageStates*>(handle);
  self->clear();
}

const DeviceVoltageStateHandle DeviceVoltageStates_const_at(
    DeviceVoltageStatesHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_const_at: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return new falcon_core::communications::voltage_states::DeviceVoltageState(
      *(self.at(idx)));
}

DeviceVoltageStateHandle DeviceVoltageStates_at(
    DeviceVoltageStatesHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_at: handle cannot be null");
  }
  DeviceVoltageStates self  = *static_cast<DeviceVoltageStates*>(handle);
  auto                state = self.at(idx);
  return new falcon_core::communications::voltage_states::DeviceVoltageState(
      *state);
}

ListDeviceVoltageStateHandle DeviceVoltageStates_items(
    DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_items: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return new falcon_core::generic::List<
      falcon_core::communications::voltage_states::DeviceVoltageState>(
      self.items());
}

bool DeviceVoltageStates_contains(DeviceVoltageStatesHandle handle,
                                  DeviceVoltageStateHandle  value) {
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
}

size_t DeviceVoltageStates_index(DeviceVoltageStatesHandle handle,
                                 DeviceVoltageStateHandle  value) {
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
}

bool DeviceVoltageStates_equal(DeviceVoltageStatesHandle a,
                               DeviceVoltageStatesHandle b) {
  if (!a) {
    throw std::invalid_argument("DeviceVoltageStates_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("DeviceVoltageStates_equal: b cannot be null");
  }
  return *(static_cast<DeviceVoltageStates*>(a)) ==
         *(static_cast<DeviceVoltageStates*>(b));
}

bool DeviceVoltageStates_not_equal(DeviceVoltageStatesHandle a,
                                   DeviceVoltageStatesHandle b) {
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
}

StringHandle DeviceVoltageStates_to_json_string(
    DeviceVoltageStatesHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_to_json_string: handle cannot be null");
  }
  DeviceVoltageStates self = *static_cast<DeviceVoltageStates*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

DeviceVoltageStatesHandle DeviceVoltageStates_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "DeviceVoltageStates_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new DeviceVoltageStates(
      *DeviceVoltageStates::from_json_string<DeviceVoltageStates>(json_str));
}
