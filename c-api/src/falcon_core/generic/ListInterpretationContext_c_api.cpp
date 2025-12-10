#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListInterpretationContextHandle= falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>;
DEFINE_C_API_COPY_TEMPLATE(ListInterpretationContext, MACROListInterpretationContextHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListInterpretationContext, MACROListInterpretationContextHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListInterpretationContext, MACROListInterpretationContextHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListInterpretationContext, MACROListInterpretationContextHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListInterpretationContext, MACROListInterpretationContextHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListInterpretationContext, MACROListInterpretationContextHandle);
ListInterpretationContextHandle ListInterpretationContext_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>());
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListInterpretationContext_create");
}
    std::vector<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListInterpretationContext_size(ListInterpretationContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListInterpretationContext_empty(ListInterpretationContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListInterpretationContext_clear(ListInterpretationContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInterpretationContext_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListInterpretationContext_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(obj);
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListInterpretationContext_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(result);
    FALCON_C_API_END(nullptr)
}
}
