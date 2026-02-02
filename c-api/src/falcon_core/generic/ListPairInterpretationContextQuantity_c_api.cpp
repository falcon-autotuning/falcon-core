#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListPairInterpretationContextQuantity_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairInterpretationContextQuantityHandle= falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairInterpretationContextQuantity, MACROListPairInterpretationContextQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairInterpretationContextQuantity, MACROListPairInterpretationContextQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairInterpretationContextQuantity, MACROListPairInterpretationContextQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairInterpretationContextQuantity, MACROListPairInterpretationContextQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairInterpretationContextQuantity, MACROListPairInterpretationContextQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairInterpretationContextQuantity, MACROListPairInterpretationContextQuantityHandle);
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_fill_value(size_t count, PairInterpretationContextQuantityHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairInterpretationContextQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairInterpretationContextQuantity_size(ListPairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairInterpretationContextQuantity_empty(ListPairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairInterpretationContextQuantity_erase_at(ListPairInterpretationContextQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairInterpretationContextQuantity_clear(ListPairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairInterpretationContextQuantity_push_back(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairInterpretationContextQuantity_contains(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairInterpretationContextQuantity_index(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairInterpretationContextQuantity_items(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInterpretationContextQuantity_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_at(ListPairInterpretationContextQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_intersection(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(result);
    FALCON_C_API_END(nullptr)
}
}
