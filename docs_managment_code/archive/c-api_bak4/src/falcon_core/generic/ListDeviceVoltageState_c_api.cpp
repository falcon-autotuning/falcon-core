#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDeviceVoltageState_c_api.h"
#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>();
    FALCON_C_API_END(nullptr)
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value(size_t count, DeviceVoltageStateHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDeviceVoltageState_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::communications::voltage_states::DeviceVoltageState>(*static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value));
    
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(
        count, stored_obj);
    FALCON_C_API_END(nullptr)
}
 

ListDeviceVoltageStateHandle ListDeviceVoltageState_create(DeviceVoltageStateHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListDeviceVoltageState_create");
}
    std::vector<falcon_core::communications::voltage_states::DeviceVoltageStateSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::communications::voltage_states::DeviceVoltageState>(*static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(vec);
    FALCON_C_API_END(nullptr)
}

void ListDeviceVoltageState_destroy(ListDeviceVoltageStateHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle);
    FALCON_C_API_END()
}

size_t ListDeviceVoltageState_size(ListDeviceVoltageStateHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool ListDeviceVoltageState_empty(ListDeviceVoltageStateHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void ListDeviceVoltageState_clear(ListDeviceVoltageStateHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->clear();
    FALCON_C_API_END()
}

void ListDeviceVoltageState_push_back(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDeviceVoltageState_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::communications::voltage_states::DeviceVoltageState>(*static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListDeviceVoltageState_contains(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDeviceVoltageState_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::communications::voltage_states::DeviceVoltageState>(*static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListDeviceVoltageState_index(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDeviceVoltageState_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::communications::voltage_states::DeviceVoltageState>(*static_cast<falcon_core::communications::voltage_states::DeviceVoltageState*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListDeviceVoltageState_items(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListDeviceVoltageState_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::communications::voltage_states::DeviceVoltageState(*list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

DeviceVoltageStateHandle ListDeviceVoltageState_at(ListDeviceVoltageStateHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->at(idx);
    return new falcon_core::communications::voltage_states::DeviceVoltageState(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_not_equal");
}
    return !ListDeviceVoltageState_equal(a, b);
    FALCON_C_API_END(false)
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>>(*listB));
    return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(*result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDeviceVoltageState_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListDeviceVoltageState_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>::from_json_string<falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>>(json->raw);
  return new falcon_core::generic::List<falcon_core::communications::voltage_states::DeviceVoltageState>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
