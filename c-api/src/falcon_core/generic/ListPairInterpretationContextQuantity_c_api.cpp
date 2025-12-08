#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
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
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>SP*>(value);
    
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
        vec.push_back(*static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>SP*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairInterpretationContextQuantity_destroy(ListPairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    FALCON_C_API_END()
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
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>SP*>(value);
    
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
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>SP*>(value);
    
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
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>SP*>(value);
    
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
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>SP(list->items()[i]);
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
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairInterpretationContextQuantity_equal(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairInterpretationContextQuantity_not_equal(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
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

StringHandle      ListPairInterpretationContextQuantity_to_json_string(ListPairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairInterpretationContextQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
