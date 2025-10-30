#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInterpretationContextQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty() {
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>());
}

MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create(const PairInterpretationContextQuantityHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(vec));
}

void MapInterpretationContextQuantity_destroy(MapInterpretationContextQuantityHandle handle) {
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
}

void MapInterpretationContextQuantity_insert_or_assign(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key, const QuantityHandle value) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto correct_value = std::make_shared<falcon_core::math::Quantity>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapInterpretationContextQuantity_insert(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key, const QuantityHandle value) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto correct_value = std::make_shared<falcon_core::math::Quantity>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->insert(correct_key,correct_value);
}

QuantityHandle MapInterpretationContextQuantity_at(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return new falcon_core::math::Quantity(*static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->at(correct_key));
}

void MapInterpretationContextQuantity_erase(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->erase(correct_key);
}

size_t MapInterpretationContextQuantity_size(MapInterpretationContextQuantityHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->size();
}

bool MapInterpretationContextQuantity_empty(MapInterpretationContextQuantityHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->empty();
}


void MapInterpretationContextQuantity_clear(MapInterpretationContextQuantityHandle handle) {
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->clear();
}

bool MapInterpretationContextQuantity_contains(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key) {
    auto temp_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->contains(correct_key);
}

ListInterpretationContextHandle MapInterpretationContextQuantity_keys(MapInterpretationContextQuantityHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*keys_sp);
}

ListQuantityHandle MapInterpretationContextQuantity_values(MapInterpretationContextQuantityHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<falcon_core::math::Quantity>(*values_sp);
}

ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items(MapInterpretationContextQuantityHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(items_sp);
}

bool MapInterpretationContextQuantity_equal(MapInterpretationContextQuantityHandle a, MapInterpretationContextQuantityHandle b) {
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(b);
    return *listA == *listB;
}

bool MapInterpretationContextQuantity_not_equal(MapInterpretationContextQuantityHandle a, MapInterpretationContextQuantityHandle b) {
    return !MapInterpretationContextQuantity_equal(a, b);
}

StringHandle      MapInterpretationContextQuantity_to_json_string(MapInterpretationContextQuantityHandle handle) {
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(*ptr);
}
