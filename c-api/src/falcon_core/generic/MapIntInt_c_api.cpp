#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapIntInt_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapIntIntHandle MapIntInt_create_empty() {
    return new std::shared_ptr<falcon_core::generic::Map<int,int>>(
            std::make_shared<falcon_core::generic::Map<int,int>>());
}

MapIntIntHandle MapIntInt_create(const PairIntIntHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<int,int>> vec(data, data + count);
    return new std::shared_ptr<falcon_core::generic::Map<int,int>>(
            std::make_shared<falcon_core::generic::Map<int,int>>(vec));
}

void MapIntInt_destroy(MapIntIntHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle);
}

void MapIntInt_insert_or_assign(MapIntIntHandle handle, const int key, const int value) {
    auto correct_key = key;
    auto correct_value = value;
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->insert_or_assign(correct_key,correct_value);
}

void MapIntInt_insert(MapIntIntHandle handle, const int key, const int value) {
    auto correct_key = key;
    auto correct_value = value;
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->insert(correct_key,correct_value);
}

int MapIntInt_at(MapIntIntHandle handle, const int key) {
    auto correct_key = key;
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->at(correct_key);
}

void MapIntInt_erase(MapIntIntHandle handle, const int key) {
    auto correct_key = key;
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->erase(correct_key);
}

size_t MapIntInt_size(MapIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->size();
}

bool MapIntInt_empty(MapIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->empty();
}


void MapIntInt_clear(MapIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->clear();
}

bool MapIntInt_contains(MapIntIntHandle handle, int key) {
    auto correct_key = key;
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle))->contains(correct_key);
}

ListIntHandle MapIntInt_keys(MapIntIntHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new std::shared_ptr<falcon_core::generic::List<int>>(keys_sp);
}

ListIntHandle MapIntInt_values(MapIntIntHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new std::shared_ptr<falcon_core::generic::List<int>>(values_sp);
}

ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<int,int>> items_sp = map->items(); // shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<Key,Value>>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int,int>>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int,int>>>(items_sp));
}

bool MapIntInt_equal(MapIntIntHandle a, MapIntIntHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::Map<int,int>>*>(b);
    return *listA == *listB;
}

bool MapIntInt_not_equal(MapIntIntHandle a, MapIntIntHandle b) {
    return !MapIntInt_equal(a, b);
}
