#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDeviceVoltageState_c_api.h"
#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>

ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty() {
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(
        falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>());
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value(size_t count, DeviceVoltageStateHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::communications::voltage_states::DeviceVoltageState>(static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value), [](falcon_core::communications::voltage_states::DeviceVoltageState*) {} );
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(
        falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(count, stored_obj));
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(
        falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(count));
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_create(DeviceVoltageStateHandle* data, size_t count) {
    std::vector<falcon_core::communications::voltage_states::DeviceVoltageStateSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::communications::voltage_states::DeviceVoltageState>(static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(data[i]), [](falcon_core::communications::voltage_states::DeviceVoltageState*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(
        falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(vec));
}

void ListDeviceVoltageState_destroy(ListDeviceVoltageStateHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle);
}

size_t ListDeviceVoltageState_size(ListDeviceVoltageStateHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->size();
}

bool ListDeviceVoltageState_empty(ListDeviceVoltageStateHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->empty();
}

void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->erase_at(idx);
}

void ListDeviceVoltageState_clear(ListDeviceVoltageStateHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->clear();
}

void ListDeviceVoltageState_push_back(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::communications::voltage_states::DeviceVoltageState>(static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value), [](falcon_core::communications::voltage_states::DeviceVoltageState*) {} );
    static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->push_back(stored_obj);
}

bool ListDeviceVoltageState_contains(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::communications::voltage_states::DeviceVoltageState>(static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value), [](falcon_core::communications::voltage_states::DeviceVoltageState*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->contains(stored_obj);
}

size_t ListDeviceVoltageState_index(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::communications::voltage_states::DeviceVoltageState>(static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value), [](falcon_core::communications::voltage_states::DeviceVoltageState*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->index(stored_obj);
}

size_t ListDeviceVoltageState_items(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::communications::voltage_states::DeviceVoltageState(*list->items()[i]);
}
    return n;
}

DeviceVoltageStateHandle ListDeviceVoltageState_at(ListDeviceVoltageStateHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->at(idx);
    return new falcon_core::communications::voltage_states::DeviceVoltageState(*obj);
}

bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(b);
    return *listA == *listB;
}

bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b) {
    return !ListDeviceVoltageState_equal(a, b);
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>>(*listB));
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(*result);
}

StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>::from_json_string<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>>(json->raw);
  return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(*ptr);
}
