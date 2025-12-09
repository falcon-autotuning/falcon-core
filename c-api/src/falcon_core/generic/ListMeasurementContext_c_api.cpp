#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListMeasurementContext_c_api.h"
#include <falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListMeasurementContextHandle ListMeasurementContext_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>());
    FALCON_C_API_END(nullptr)
}

ListMeasurementContextHandle ListMeasurementContext_fill_value(size_t count, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListMeasurementContextHandle ListMeasurementContext_create(MeasurementContextHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListMeasurementContext_create");
}
    std::vector<falcon_core::autotuner_interfaces::contexts::MeasurementContextSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListMeasurementContext_destroy(ListMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListMeasurementContext_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    FALCON_C_API_END()
}

size_t ListMeasurementContext_size(ListMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListMeasurementContext_empty(ListMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListMeasurementContext_erase_at(ListMeasurementContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListMeasurementContext_clear(ListMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListMeasurementContext_push_back(ListMeasurementContextHandle handle, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListMeasurementContext_contains(ListMeasurementContextHandle handle, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListMeasurementContext_index(ListMeasurementContextHandle handle, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListMeasurementContext_items(ListMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListMeasurementContext_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

MeasurementContextHandle ListMeasurementContext_at(ListMeasurementContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(obj);
    FALCON_C_API_END(nullptr)
}

bool ListMeasurementContext_equal(ListMeasurementContextHandle handle, ListMeasurementContextHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListMeasurementContext_not_equal(ListMeasurementContextHandle handle, ListMeasurementContextHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListMeasurementContextHandle ListMeasurementContext_intersection(ListMeasurementContextHandle handle, ListMeasurementContextHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListMeasurementContext_to_json_string(ListMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListMeasurementContextHandle ListMeasurementContext_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListMeasurementContext_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(ptr);
    FALCON_C_API_END(nullptr)
}
}
