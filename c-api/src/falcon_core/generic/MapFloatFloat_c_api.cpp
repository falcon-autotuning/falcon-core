#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapFloatFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapFloatFloatHandle MapFloatFloat_create_empty() {
    return new std::shared_ptr<falcon_core::generic::Map<float,float>>(
            std::make_shared<falcon_core::generic::Map<float,float>>());
}

MapFloatFloatHandle MapFloatFloat_create(const PairFloatFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<float,float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<float,float>>*>(
            data[i]));
    }
    return new std::shared_ptr<falcon_core::generic::Map<float,float>>(
            std::make_shared<falcon_core::generic::Map<float,float>>(vec));
}

void MapFloatFloat_destroy(MapFloatFloatHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle);
}

void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle, const float key, const float value) {
    auto correct_key = key;
    auto correct_value = value;
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->insert_or_assign(correct_key,correct_value);
}

void MapFloatFloat_insert(MapFloatFloatHandle handle, const float key, const float value) {
    auto correct_key = key;
    auto correct_value = value;
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->insert(correct_key,correct_value);
}

float MapFloatFloat_at(MapFloatFloatHandle handle, const float key) {
    auto correct_key = key;
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->at(correct_key);
}

void MapFloatFloat_erase(MapFloatFloatHandle handle, const float key) {
    auto correct_key = key;
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->erase(correct_key);
}

size_t MapFloatFloat_size(MapFloatFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->size();
}

bool MapFloatFloat_empty(MapFloatFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->empty();
}


void MapFloatFloat_clear(MapFloatFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->clear();
}

bool MapFloatFloat_contains(MapFloatFloatHandle handle, float key) {
    auto correct_key = key;
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle))->contains(correct_key);
}

ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new std::shared_ptr<falcon_core::generic::List<float>>(keys_sp);
}

ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new std::shared_ptr<falcon_core::generic::List<float>>(values_sp);
}

ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<float,float>> items_sp = map->items(); // shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<Key,Value>>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<float,float>>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<float,float>>>(items_sp));
}

bool MapFloatFloat_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::Map<float,float>>*>(b);
    return *listA == *listB;
}

bool MapFloatFloat_not_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
    return !MapFloatFloat_equal(a, b);
}
