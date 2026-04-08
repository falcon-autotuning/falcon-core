#include "falcon-core/communications/voltage_states/DeviceVoltageStates_c_api.h"

#include <falcon-core/communications/voltage_states/DeviceVoltageStates.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core::communications::voltage_states;

extern "C" {
DEFINE_C_API_COPY(DeviceVoltageStates);
DEFINE_C_API_DESTROY(DeviceVoltageStates);
DEFINE_C_API_EQUAL(DeviceVoltageStates);
DEFINE_C_API_NOT_EQUAL(DeviceVoltageStates);
DEFINE_C_API_TO_JSON(DeviceVoltageStates);
DEFINE_C_API_FROM_JSON(DeviceVoltageStates);
DeviceVoltageStatesHandle DeviceVoltageStates_create_empty() {
  FALCON_C_API_BEGIN
  return new DeviceVoltageStatesSP(std::make_shared<DeviceVoltageStates>());
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
      *static_cast<falcon_core::generic::ListSP<DeviceVoltageState>*>(items);
  return new DeviceVoltageStatesSP(std::make_shared<DeviceVoltageStates>(list));
  FALCON_C_API_END(nullptr)
}

ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_states: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  return new falcon_core::generic::ListSP<DeviceVoltageState>(self->states());
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
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  DeviceVoltageStateSP  real_state = *static_cast<DeviceVoltageStateSP*>(state);
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
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_connection =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          connection);
  DeviceVoltageStateSP result = self->find_state(real_connection);
  return new DeviceVoltageStateSP(result);
  FALCON_C_API_END(nullptr)
}

PointHandle DeviceVoltageStates_to_point(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_to_point: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  falcon_core::math::PointSP result = self->to_point();
  return new falcon_core::math::PointSP(result);
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
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  DeviceVoltageStatesSP other_self =
      *static_cast<DeviceVoltageStatesSP*>(other);
  falcon_core::generic::ListSP<DeviceVoltageState> result =
      self->intersection(other_self);
  return new DeviceVoltageStatesSP(
      std::make_shared<DeviceVoltageStates>(result));
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
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  DeviceVoltageStateSP  value_ptr = *static_cast<DeviceVoltageStateSP*>(value);
  self->push_back(value_ptr);
  FALCON_C_API_END()
}

size_t DeviceVoltageStates_size(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_size: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool DeviceVoltageStates_empty(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_empty: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void DeviceVoltageStates_erase_at(DeviceVoltageStatesHandle handle,
                                  size_t                    idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_erase_at: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void DeviceVoltageStates_clear(DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_clear: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  self->clear();
  FALCON_C_API_END()
}

DeviceVoltageStateHandle DeviceVoltageStates_at(
    DeviceVoltageStatesHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_at: handle cannot be null");
  }
  DeviceVoltageStatesSP self  = *static_cast<DeviceVoltageStatesSP*>(handle);
  DeviceVoltageStateSP  state = self->at(idx);
  return new DeviceVoltageStateSP(state);
  FALCON_C_API_END(nullptr)
}

ListDeviceVoltageStateHandle DeviceVoltageStates_items(
    DeviceVoltageStatesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DeviceVoltageStates_items: handle cannot be null");
  }
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  return new falcon_core::generic::ListSP<DeviceVoltageState>(
      std::make_shared<falcon_core::generic::List<DeviceVoltageState>>(
          self->items()));
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
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  DeviceVoltageStateSP  real_value = *static_cast<DeviceVoltageStateSP*>(value);
  return self->contains(real_value);
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
  DeviceVoltageStatesSP self = *static_cast<DeviceVoltageStatesSP*>(handle);
  DeviceVoltageStateSP  real_value = *static_cast<DeviceVoltageStateSP*>(value);
  return self->index(real_value);
  FALCON_C_API_END(0)
}
}
