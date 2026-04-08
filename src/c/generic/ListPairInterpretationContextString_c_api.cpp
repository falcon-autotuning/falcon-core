#include <falcon-core/generic/List.hpp>
#include "falcon-core/generic/ListPairInterpretationContextString_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/Pair.hpp>
#include <falcon-core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairInterpretationContextStringHandle= falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairInterpretationContextString, MACROListPairInterpretationContextStringHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairInterpretationContextString, MACROListPairInterpretationContextStringHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairInterpretationContextString, MACROListPairInterpretationContextStringHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairInterpretationContextString, MACROListPairInterpretationContextStringHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairInterpretationContextString, MACROListPairInterpretationContextStringHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairInterpretationContextString, MACROListPairInterpretationContextStringHandle);
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>>());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_fill_value(size_t count, PairInterpretationContextStringHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairInterpretationContextString_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairInterpretationContextString_size(ListPairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairInterpretationContextString_empty(ListPairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairInterpretationContextString_erase_at(ListPairInterpretationContextStringHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairInterpretationContextString_clear(ListPairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairInterpretationContextString_push_back(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairInterpretationContextString_contains(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairInterpretationContextString_index(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairInterpretationContextString_items(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInterpretationContextString_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairInterpretationContextStringHandle ListPairInterpretationContextString_at(ListPairInterpretationContextStringHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_intersection(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(result);
    FALCON_C_API_END(nullptr)
}
}
