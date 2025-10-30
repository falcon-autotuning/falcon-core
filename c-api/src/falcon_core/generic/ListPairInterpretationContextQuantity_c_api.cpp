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

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_fill_value(size_t count, PairInterpretationContextQuantityList value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(count, stored_obj));
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(count));
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create(PairInterpretationContextQuantityList* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(vec));
}

void ListPairInterpretationContextQuantity_destroy(ListPairInterpretationContextQuantityHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
}

size_t ListPairInterpretationContextQuantity_size(ListPairInterpretationContextQuantityHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->size();
}

bool ListPairInterpretationContextQuantity_empty(ListPairInterpretationContextQuantityHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->empty();
}

void ListPairInterpretationContextQuantity_erase_at(ListPairInterpretationContextQuantityHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->erase_at(idx);
}

void ListPairInterpretationContextQuantity_clear(ListPairInterpretationContextQuantityHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->clear();
}

void ListPairInterpretationContextQuantity_push_back(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityList value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->push_back(stored_obj);
}

bool ListPairInterpretationContextQuantity_contains(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityList value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->contains(stored_obj);
}

size_t ListPairInterpretationContextQuantity_index(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityList value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->index(stored_obj);
}

size_t ListPairInterpretationContextQuantity_items(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityList* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(*list->items()[i]);
}
    return n;
}

PairInterpretationContextQuantityList ListPairInterpretationContextQuantity_at(ListPairInterpretationContextQuantityHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(*obj);
}

bool ListPairInterpretationContextQuantity_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(b);
    return *listA == *listB;
}

bool ListPairInterpretationContextQuantity_not_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b) {
    return !ListPairInterpretationContextQuantity_equal(a, b);
}

ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_intersection(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(*result);
}

StringHandle      ListPairInterpretationContextQuantity_to_json_string(ListPairInterpretationContextQuantityHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(*ptr);
}
