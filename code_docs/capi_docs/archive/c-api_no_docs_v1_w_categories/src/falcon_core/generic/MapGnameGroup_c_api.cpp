#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapGnameGroup_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapGnameGroupHandle MapGnameGroup_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(); 
    FALCON_C_API_END(nullptr)
}

MapGnameGroupHandle MapGnameGroup_create( PairGnameGroupHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapGnameGroup_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>
        (*static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(vec);
    FALCON_C_API_END(nullptr)
}

void MapGnameGroup_destroy(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    FALCON_C_API_END()
}

void MapGnameGroup_insert_or_assign(MapGnameGroupHandle handle,  GnameHandle key,  GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapGnameGroup_at");
            }
            auto temp_value = *static_cast<falcon_core::physics::config::core::Group*>(value);
auto correct_value = std::make_shared<falcon_core::physics::config::core::Group>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapGnameGroup_insert(MapGnameGroupHandle handle,  GnameHandle key,  GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapGnameGroup_at");
            }
            auto temp_value = *static_cast<falcon_core::physics::config::core::Group*>(value);
auto correct_value = std::make_shared<falcon_core::physics::config::core::Group>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->insert(correct_key,correct_value);
    FALCON_C_API_END()
}

GroupHandle MapGnameGroup_at(MapGnameGroupHandle handle,  GnameHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    return new falcon_core::physics::config::core::Group(*static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapGnameGroup_erase(MapGnameGroupHandle handle,  GnameHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapGnameGroup_size(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapGnameGroup_empty(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapGnameGroup_clear(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->clear();
    FALCON_C_API_END()
}

bool MapGnameGroup_contains(MapGnameGroupHandle handle, GnameHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListGnameHandle MapGnameGroup_keys(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListGroupHandle MapGnameGroup_values(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairGnameGroupHandle MapGnameGroup_items(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapGnameGroup_equal(MapGnameGroupHandle a, MapGnameGroupHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapGnameGroup_not_equal(MapGnameGroupHandle a, MapGnameGroupHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_not_equal");
}
    return !MapGnameGroup_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapGnameGroup_to_json_string(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapGnameGroupHandle MapGnameGroup_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapGnameGroup_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
