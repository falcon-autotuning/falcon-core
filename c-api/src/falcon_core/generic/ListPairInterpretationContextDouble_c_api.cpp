#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>());
}

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_fill_value(size_t count, PairInterpretationContextDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(count, stored_obj));
}

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(count));
}

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_create(PairInterpretationContextDoubleHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(vec));
}

void ListPairInterpretationContextDouble_destroy(ListPairInterpretationContextDoubleHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle);
}

size_t ListPairInterpretationContextDouble_size(ListPairInterpretationContextDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->size();
}

bool ListPairInterpretationContextDouble_empty(ListPairInterpretationContextDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->empty();
}

void ListPairInterpretationContextDouble_erase_at(ListPairInterpretationContextDoubleHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->erase_at(idx);
}

void ListPairInterpretationContextDouble_clear(ListPairInterpretationContextDoubleHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->clear();
}

void ListPairInterpretationContextDouble_push_back(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->push_back(stored_obj);
}

bool ListPairInterpretationContextDouble_contains(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->contains(stored_obj);
}

size_t ListPairInterpretationContextDouble_index(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->index(stored_obj);
}

size_t ListPairInterpretationContextDouble_items(ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>(*list->items()[i]);
}
    return n;
}

PairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_at(ListPairInterpretationContextDoubleHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>(*obj);
}

bool ListPairInterpretationContextDouble_equal(ListPairInterpretationContextDoubleHandle a, ListPairInterpretationContextDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(b);
    return *listA == *listB;
}

bool ListPairInterpretationContextDouble_not_equal(ListPairInterpretationContextDoubleHandle a, ListPairInterpretationContextDoubleHandle b) {
    return !ListPairInterpretationContextDouble_equal(a, b);
}

ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_intersection(ListPairInterpretationContextDoubleHandle handle, ListPairInterpretationContextDoubleHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(*result);
}

StringHandle      ListPairInterpretationContextDouble_to_json_string(ListPairInterpretationContextDoubleHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(*ptr);
}
