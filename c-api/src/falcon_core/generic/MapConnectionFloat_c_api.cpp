#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

MapConnectionFloatHandle MapConnectionFloat_create_empty() {
    return new std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>(
            std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>());
}

MapConnectionFloatHandle MapConnectionFloat_create(const PairConnectionFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>> vec(data, data + count);
    return new std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>(
            std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>(vec));
}

void MapConnectionFloat_destroy(MapConnectionFloatHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle);
}

void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle, const ConnectionHandle key, const float value) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto correct_value = value;
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->insert_or_assign(correct_key,correct_value);
}

void MapConnectionFloat_insert(MapConnectionFloatHandle handle, const ConnectionHandle key, const float value) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto correct_value = value;
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->insert(correct_key,correct_value);
}

float MapConnectionFloat_at(MapConnectionFloatHandle handle, const ConnectionHandle key) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->at(correct_key);
}

void MapConnectionFloat_erase(MapConnectionFloatHandle handle, const ConnectionHandle key) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->erase(correct_key);
}

size_t MapConnectionFloat_size(MapConnectionFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->size();
}

bool MapConnectionFloat_empty(MapConnectionFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->empty();
}


void MapConnectionFloat_clear(MapConnectionFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->clear();
}

bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle))->contains(correct_key);
}

ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(keys_sp);
}

ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new std::shared_ptr<falcon_core::generic::List<float>>(values_sp);
}

ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>> items_sp = map->items(); // shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<Key,Value>>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>>(items_sp));
}

bool MapConnectionFloat_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>*>(b);
    return *listA == *listB;
}

bool MapConnectionFloat_not_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b) {
    return !MapConnectionFloat_equal(a, b);
}
