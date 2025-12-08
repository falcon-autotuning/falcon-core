#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapConnectionQuantityHandle MapConnectionQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>(std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>()); 
    FALCON_C_API_END(nullptr)
}

MapConnectionQuantityHandle MapConnectionQuantity_create( PairConnectionQuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapConnectionQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapConnectionQuantity_destroy(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_destroy");
}
    delete static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    FALCON_C_API_END()
}

void MapConnectionQuantity_insert_or_assign(MapConnectionQuantityHandle handle,  ConnectionHandle key,  QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapConnectionQuantity_at");
            }
            auto correct_value = *static_cast<falcon_core::math::QuantitySP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapConnectionQuantity_insert(MapConnectionQuantityHandle handle,  ConnectionHandle key,  QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapConnectionQuantity_at");
            }
            auto correct_value = *static_cast<falcon_core::math::QuantitySP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

QuantityHandle MapConnectionQuantity_at(MapConnectionQuantityHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return new falcon_core::math::QuantitySP((*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapConnectionQuantity_erase(MapConnectionQuantityHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapConnectionQuantity_size(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapConnectionQuantity_empty(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapConnectionQuantity_clear(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapConnectionQuantity_contains(MapConnectionQuantityHandle handle, ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListConnectionHandle MapConnectionQuantity_keys(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListQuantityHandle MapConnectionQuantity_values(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionQuantityHandle MapConnectionQuantity_items(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapConnectionQuantity_equal(MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_equal");
}
    auto listA = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle);
    auto listB = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapConnectionQuantity_not_equal(MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle);
    auto listB = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

StringHandle      MapConnectionQuantity_to_json_string(MapConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionQuantity_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapConnectionQuantityHandle MapConnectionQuantity_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapConnectionQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>(ptr);
    FALCON_C_API_END(nullptr)
}
}
