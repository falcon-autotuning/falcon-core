#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

ListInterpretationContextHandle ListInterpretationContext_create_empty() {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>());
}

ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(count, stored_obj));
}

ListInterpretationContextHandle ListInterpretationContext_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(count));
}

ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count) {
    std::vector<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(data[i]), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(vec));
}

void ListInterpretationContext_destroy(ListInterpretationContextHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
}

size_t ListInterpretationContext_size(ListInterpretationContextHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->size();
}

bool ListInterpretationContext_empty(ListInterpretationContextHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->empty();
}

void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->erase_at(idx);
}

void ListInterpretationContext_clear(ListInterpretationContextHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->clear();
}

void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->push_back(stored_obj);
}

bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->contains(stored_obj);
}

size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(value), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->index(stored_obj);
}

size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*list->items()[i]);
}
    return n;
}

InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*obj);
}

bool ListInterpretationContext_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(b);
    return *listA == *listB;
}

bool ListInterpretationContext_not_equal(ListInterpretationContextHandle a, ListInterpretationContextHandle b) {
    return !ListInterpretationContext_equal(a, b);
}

ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*result);
}

StringHandle      ListInterpretationContext_to_json_string(ListInterpretationContextHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListInterpretationContextHandle ListInterpretationContext_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*ptr);
}
