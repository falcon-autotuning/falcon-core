#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListAcquisitionContextHandle ListAcquisitionContext_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>();
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle ListAcquisitionContext_fill_value(size_t count, AcquisitionContextHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListAcquisitionContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value));
    
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(
        count, stored_obj);
    FALCON_C_API_END(nullptr)
}
 

ListAcquisitionContextHandle ListAcquisitionContext_create(AcquisitionContextHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListAcquisitionContext_create");
}
    std::vector<falcon_core::autotuner_interfaces::contexts::AcquisitionContextSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(vec);
    FALCON_C_API_END(nullptr)
}

void ListAcquisitionContext_destroy(ListAcquisitionContextHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListAcquisitionContext_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle);
    FALCON_C_API_END()
}

size_t ListAcquisitionContext_size(ListAcquisitionContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool ListAcquisitionContext_empty(ListAcquisitionContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void ListAcquisitionContext_erase_at(ListAcquisitionContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void ListAcquisitionContext_clear(ListAcquisitionContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->clear();
    FALCON_C_API_END()
}

void ListAcquisitionContext_push_back(ListAcquisitionContextHandle handle, AcquisitionContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListAcquisitionContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListAcquisitionContext_contains(ListAcquisitionContextHandle handle, AcquisitionContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListAcquisitionContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListAcquisitionContext_index(ListAcquisitionContextHandle handle, AcquisitionContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListAcquisitionContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListAcquisitionContext_items(ListAcquisitionContextHandle handle, AcquisitionContextHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListAcquisitionContext_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::contexts::AcquisitionContext(*list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

AcquisitionContextHandle ListAcquisitionContext_at(ListAcquisitionContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::contexts::AcquisitionContext(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListAcquisitionContext_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListAcquisitionContext_not_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_not_equal");
}
    return !ListAcquisitionContext_equal(a, b);
    FALCON_C_API_END(false)
}

ListAcquisitionContextHandle ListAcquisitionContext_intersection(ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListAcquisitionContext_to_json_string(ListAcquisitionContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListAcquisitionContext_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle ListAcquisitionContext_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListAcquisitionContext_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
