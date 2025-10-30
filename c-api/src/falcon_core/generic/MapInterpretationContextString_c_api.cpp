#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInterpretationContextString_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

MapInterpretationContextStringHandle MapInterpretationContextString_create_empty() {
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>());
}

MapInterpretationContextStringHandle MapInterpretationContextString_create(const PairInterpretationContextStringHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(vec));
}

void MapInterpretationContextString_destroy(MapInterpretationContextStringHandle handle) {
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
}

void MapInterpretationContextString_insert_or_assign(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key, const StringHandle value) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    auto correct_value = std::string(value->raw, value->length);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapInterpretationContextString_insert(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key, const StringHandle value) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    auto correct_value = std::string(value->raw, value->length);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->insert(correct_key,correct_value);
}

StringHandle MapInterpretationContextString_at(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    
  auto string =
      static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle)
          ->at(correct_key);
  return String_create(string.data(), string.size());
            
}

void MapInterpretationContextString_erase(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->erase(correct_key);
}

size_t MapInterpretationContextString_size(MapInterpretationContextStringHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->size();
}

bool MapInterpretationContextString_empty(MapInterpretationContextStringHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->empty();
}


void MapInterpretationContextString_clear(MapInterpretationContextStringHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->clear();
}

bool MapInterpretationContextString_contains(MapInterpretationContextStringHandle handle, InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->contains(correct_key);
}

ListInterpretationContextHandle MapInterpretationContextString_keys(MapInterpretationContextStringHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*keys_sp);
}

ListStringHandle MapInterpretationContextString_values(MapInterpretationContextStringHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<std::string>(*values_sp);
}

ListPairInterpretationContextStringHandle MapInterpretationContextString_items(MapInterpretationContextStringHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(items_sp);
}

bool MapInterpretationContextString_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b) {
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(b);
    return *listA == *listB;
}

bool MapInterpretationContextString_not_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b) {
    return !MapInterpretationContextString_equal(a, b);
}

StringHandle      MapInterpretationContextString_to_json_string(MapInterpretationContextStringHandle handle) {
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
MapInterpretationContextStringHandle MapInterpretationContextString_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(*ptr);
}
