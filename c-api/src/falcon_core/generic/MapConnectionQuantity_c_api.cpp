#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

MapConnectionQuantityHandle MapConnectionQuantity_create_empty() {
    return new std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(
            std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>());
}

MapConnectionQuantityHandle MapConnectionQuantity_create(const PairConnectionQuantityHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(
            data[i]));
    }
    return new std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(
            std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(vec));
}

void MapConnectionQuantity_destroy(MapConnectionQuantityHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle);
}

void MapConnectionQuantity_insert_or_assign(MapConnectionQuantityHandle handle, const ConnectionHandle key, const QuantityHandle value) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto correct_value = std::make_shared<falcon_core::math::Quantity>(temp_value);
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->insert_or_assign(correct_key,correct_value);
}

void MapConnectionQuantity_insert(MapConnectionQuantityHandle handle, const ConnectionHandle key, const QuantityHandle value) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto correct_value = std::make_shared<falcon_core::math::Quantity>(temp_value);
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->insert(correct_key,correct_value);
}

QuantityHandle MapConnectionQuantity_at(MapConnectionQuantityHandle handle, const ConnectionHandle key) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->at(correct_key);
}

void MapConnectionQuantity_erase(MapConnectionQuantityHandle handle, const ConnectionHandle key) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->erase(correct_key);
}

size_t MapConnectionQuantity_size(MapConnectionQuantityHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->size();
}

bool MapConnectionQuantity_empty(MapConnectionQuantityHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->empty();
}


void MapConnectionQuantity_clear(MapConnectionQuantityHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->clear();
}

bool MapConnectionQuantity_contains(MapConnectionQuantityHandle handle, ConnectionHandle key) {
    auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle))->contains(correct_key);
}

ListConnectionHandle MapConnectionQuantity_keys(MapConnectionQuantityHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(keys_sp);
}

ListQuantityHandle MapConnectionQuantity_values(MapConnectionQuantityHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::math::Quantity>>(values_sp);
}

ListPairConnectionQuantityHandle MapConnectionQuantity_items(MapConnectionQuantityHandle handle) {
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>> items_sp = map->items(); // shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<Key,Value>>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>>(items_sp));
}

bool MapConnectionQuantity_equal(MapConnectionQuantityHandle a, MapConnectionQuantityHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>*>(b);
    return *listA == *listB;
}

bool MapConnectionQuantity_not_equal(MapConnectionQuantityHandle a, MapConnectionQuantityHandle b) {
    return !MapConnectionQuantity_equal(a, b);
}
