#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>());
}

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_fill_value(size_t count, PairInterpretationContextStringHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(count, stored_obj));
}

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(count));
}

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairInterpretationContextString_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListPairInterpretationContextString_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(vec));
}

void ListPairInterpretationContextString_destroy(ListPairInterpretationContextStringHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle);
}

size_t ListPairInterpretationContextString_size(ListPairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->size();
}

bool ListPairInterpretationContextString_empty(ListPairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->empty();
}

void ListPairInterpretationContextString_erase_at(ListPairInterpretationContextStringHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->erase_at(idx);
}

void ListPairInterpretationContextString_clear(ListPairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->clear();
}

void ListPairInterpretationContextString_push_back(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->push_back(stored_obj);
}

bool ListPairInterpretationContextString_contains(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->contains(stored_obj);
}

size_t ListPairInterpretationContextString_index(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInterpretationContextString_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->index(stored_obj);
}

size_t ListPairInterpretationContextString_items(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInterpretationContextString_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>(*list->items()[i]);
}
    return n;
}

PairInterpretationContextStringHandle ListPairInterpretationContextString_at(ListPairInterpretationContextStringHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>(*obj);
}

bool ListPairInterpretationContextString_equal(ListPairInterpretationContextStringHandle a, ListPairInterpretationContextStringHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(b);
    return *listA == *listB;
}

bool ListPairInterpretationContextString_not_equal(ListPairInterpretationContextStringHandle a, ListPairInterpretationContextStringHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_not_equal");
}
    return !ListPairInterpretationContextString_equal(a, b);
}

ListPairInterpretationContextStringHandle ListPairInterpretationContextString_intersection(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(*result);
}

StringHandle      ListPairInterpretationContextString_to_json_string(ListPairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInterpretationContextString_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairInterpretationContextString_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(*ptr);
}
