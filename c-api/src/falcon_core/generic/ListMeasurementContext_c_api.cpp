#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListMeasurementContext_c_api.h"
#include <falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>

ListMeasurementContextHandle ListMeasurementContext_create_empty() {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>());
}

ListMeasurementContextHandle ListMeasurementContext_fill_value(size_t count, MeasurementContextHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(count, stored_obj));
}

ListMeasurementContextHandle ListMeasurementContext_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(count));
}

ListMeasurementContextHandle ListMeasurementContext_create(MeasurementContextHandle* data, size_t count) {
    std::vector<falcon_core::autotuner_interfaces::contexts::MeasurementContextSP> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListMeasurementContext_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(data[i]), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(vec));
}

void ListMeasurementContext_destroy(ListMeasurementContextHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListMeasurementContext_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
}

size_t ListMeasurementContext_size(ListMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->size();
}

bool ListMeasurementContext_empty(ListMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->empty();
}

void ListMeasurementContext_erase_at(ListMeasurementContextHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->erase_at(idx);
}

void ListMeasurementContext_clear(ListMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->clear();
}

void ListMeasurementContext_push_back(ListMeasurementContextHandle handle, MeasurementContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->push_back(stored_obj);
}

bool ListMeasurementContext_contains(ListMeasurementContextHandle handle, MeasurementContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->contains(stored_obj);
}

size_t ListMeasurementContext_index(ListMeasurementContextHandle handle, MeasurementContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMeasurementContext_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->index(stored_obj);
}

size_t ListMeasurementContext_items(ListMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListMeasurementContext_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::contexts::MeasurementContext(*list->items()[i]);
}
    return n;
}

MeasurementContextHandle ListMeasurementContext_at(ListMeasurementContextHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::contexts::MeasurementContext(*obj);
}

bool ListMeasurementContext_equal(ListMeasurementContextHandle a, ListMeasurementContextHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(b);
    return *listA == *listB;
}

bool ListMeasurementContext_not_equal(ListMeasurementContextHandle a, ListMeasurementContextHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_not_equal");
}
    return !ListMeasurementContext_equal(a, b);
}

ListMeasurementContextHandle ListMeasurementContext_intersection(ListMeasurementContextHandle handle, ListMeasurementContextHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*result);
}

StringHandle      ListMeasurementContext_to_json_string(ListMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMeasurementContext_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListMeasurementContextHandle ListMeasurementContext_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListMeasurementContext_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*ptr);
}
