#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInterpretationContextString_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapInterpretationContextStringHandle MapInterpretationContextString_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(); 
    FALCON_C_API_END(nullptr)
}

MapInterpretationContextStringHandle MapInterpretationContextString_create( PairInterpretationContextStringHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapInterpretationContextString_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>
        (*static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(vec);
    FALCON_C_API_END(nullptr)
}

void MapInterpretationContextString_destroy(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
    FALCON_C_API_END()
}

void MapInterpretationContextString_insert_or_assign(MapInterpretationContextStringHandle handle,  InterpretationContextHandle key,  StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextString_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    
                if (!value) {
                throw std::invalid_argument("Null string handle passed to MapInterpretationContextString_at");
                }
                auto correct_value = std::string(value->raw, value->length);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapInterpretationContextString_insert(MapInterpretationContextStringHandle handle,  InterpretationContextHandle key,  StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextString_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    
                if (!value) {
                throw std::invalid_argument("Null string handle passed to MapInterpretationContextString_at");
                }
                auto correct_value = std::string(value->raw, value->length);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->insert(correct_key,correct_value);
    FALCON_C_API_END()
}

StringHandle MapInterpretationContextString_at(MapInterpretationContextStringHandle handle,  InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextString_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    
  auto string =
      static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle)
          ->at(correct_key);
  return String_create(string.data(), string.size());
            
    FALCON_C_API_END(nullptr)
}

void MapInterpretationContextString_erase(MapInterpretationContextStringHandle handle,  InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextString_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapInterpretationContextString_size(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapInterpretationContextString_empty(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapInterpretationContextString_clear(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->clear();
    FALCON_C_API_END()
}

bool MapInterpretationContextString_contains(MapInterpretationContextStringHandle handle, InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextString_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListInterpretationContextHandle MapInterpretationContextString_keys(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListStringHandle MapInterpretationContextString_values(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<std::string>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextStringHandle MapInterpretationContextString_items(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(*items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapInterpretationContextString_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapInterpretationContextString_not_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_not_equal");
}
    return !MapInterpretationContextString_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapInterpretationContextString_to_json_string(MapInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextString_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapInterpretationContextStringHandle MapInterpretationContextString_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapInterpretationContextString_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
