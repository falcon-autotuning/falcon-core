#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>());
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_fill_value(size_t count, PairInterpretationContextQuantityHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(count, stored_obj));
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(count));
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListPairInterpretationContextQuantity_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(vec));
}

void ListPairInterpretationContextQuantity_destroy(ListPairInterpretationContextQuantityHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
}

size_t ListPairInterpretationContextQuantity_size(ListPairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->size();
}

bool ListPairInterpretationContextQuantity_empty(ListPairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->empty();
}

void ListPairInterpretationContextQuantity_erase_at(ListPairInterpretationContextQuantityHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->erase_at(idx);
}

void ListPairInterpretationContextQuantity_clear(ListPairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->clear();
}

void ListPairInterpretationContextQuantity_push_back(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->push_back(stored_obj);
}

bool ListPairInterpretationContextQuantity_contains(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->contains(stored_obj);
}

size_t ListPairInterpretationContextQuantity_index(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->index(stored_obj);
}

size_t ListPairInterpretationContextQuantity_items(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInterpretationContextQuantity_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(*list->items()[i]);
}
    return n;
}

PairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_at(ListPairInterpretationContextQuantityHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(*obj);
}

bool ListPairInterpretationContextQuantity_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(b);
    return *listA == *listB;
}

bool ListPairInterpretationContextQuantity_not_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_not_equal");
}
    return !ListPairInterpretationContextQuantity_equal(a, b);
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_intersection(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(*result);
}

StringHandle      ListPairInterpretationContextQuantity_to_json_string(ListPairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextQuantity_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairInterpretationContextQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(*ptr);
}
