#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInterpretationContextDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create_empty() {
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>());
}

MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create(const PairInterpretationContextDoubleHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(vec));
}

void MapInterpretationContextDouble_destroy(MapInterpretationContextDoubleHandle handle) {
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
}

void MapInterpretationContextDouble_insert_or_assign(MapInterpretationContextDoubleHandle handle, const InterpretationContextHandle key, const double value) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapInterpretationContextDouble_insert(MapInterpretationContextDoubleHandle handle, const InterpretationContextHandle key, const double value) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->insert(correct_key,correct_value);
}

double MapInterpretationContextDouble_at(MapInterpretationContextDoubleHandle handle, const InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->at(correct_key);
}

void MapInterpretationContextDouble_erase(MapInterpretationContextDoubleHandle handle, const InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->erase(correct_key);
}

size_t MapInterpretationContextDouble_size(MapInterpretationContextDoubleHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->size();
}

bool MapInterpretationContextDouble_empty(MapInterpretationContextDoubleHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->empty();
}


void MapInterpretationContextDouble_clear(MapInterpretationContextDoubleHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->clear();
}

bool MapInterpretationContextDouble_contains(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->contains(correct_key);
}

ListInterpretationContextHandle MapInterpretationContextDouble_keys(MapInterpretationContextDoubleHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*keys_sp);
}

ListDoubleHandle MapInterpretationContextDouble_values(MapInterpretationContextDoubleHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<double>(*values_sp);
}

ListPairInterpretationContextDoubleHandle MapInterpretationContextDouble_items(MapInterpretationContextDoubleHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(items_sp);
}

bool MapInterpretationContextDouble_equal(MapInterpretationContextDoubleHandle a, MapInterpretationContextDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(b);
    return *listA == *listB;
}

bool MapInterpretationContextDouble_not_equal(MapInterpretationContextDoubleHandle a, MapInterpretationContextDoubleHandle b) {
    return !MapInterpretationContextDouble_equal(a, b);
}

StringHandle      MapInterpretationContextDouble_to_json_string(MapInterpretationContextDoubleHandle handle) {
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
MapInterpretationContextDoubleHandle MapInterpretationContextDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(*ptr);
}
