#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

ListInterpretationContextHandle ListInterpretationContext_create_empty() {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>();
}

ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value));
    
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        count, stored_obj);
}
 

ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListInterpretationContext_create");
}
    std::vector<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(vec);
}

void ListInterpretationContext_destroy(ListInterpretationContextHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListInterpretationContext_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
}

size_t ListInterpretationContext_size(ListInterpretationContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->size();
}

bool ListInterpretationContext_empty(ListInterpretationContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->empty();
}

void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->erase_at(idx);
}

void ListInterpretationContext_clear(ListInterpretationContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->clear();
}

void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->push_back(stored_obj);
}

bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->contains(stored_obj);
}

size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->index(stored_obj);
}

size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListInterpretationContext_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*list->items()[i]);
}
    return n;
}

InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*obj);
}

bool ListInterpretationContext_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(b);
    return *listA == *listB;
}

bool ListInterpretationContext_not_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_not_equal");
}
    return !ListInterpretationContext_equal(a, b);
}

ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*result);
}

StringHandle      ListInterpretationContext_to_json_string(ListInterpretationContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListInterpretationContextHandle ListInterpretationContext_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListInterpretationContext_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*ptr);
}
