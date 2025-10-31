#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapGnameGroup_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>

MapGnameGroupHandle MapGnameGroup_create_empty() {
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>());
}

MapGnameGroupHandle MapGnameGroup_create(const PairGnameGroupHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapGnameGroup_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(
            falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(vec));
}

void MapGnameGroup_destroy(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
}

void MapGnameGroup_insert_or_assign(MapGnameGroupHandle handle, const GnameHandle key, const GroupHandle value) {
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
}

void MapGnameGroup_insert(MapGnameGroupHandle handle, const GnameHandle key, const GroupHandle value) {
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
}

GroupHandle MapGnameGroup_at(MapGnameGroupHandle handle, const GnameHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    return new falcon_core::physics::config::core::Group(*static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->at(correct_key));
}

void MapGnameGroup_erase(MapGnameGroupHandle handle, const GnameHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->erase(correct_key);
}

size_t MapGnameGroup_size(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->size();
}

bool MapGnameGroup_empty(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->empty();
}


void MapGnameGroup_clear(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->clear();
}

bool MapGnameGroup_contains(MapGnameGroupHandle handle, GnameHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Gname*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->contains(correct_key);
}

ListGnameHandle MapGnameGroup_keys(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(*keys_sp);
}

ListGroupHandle MapGnameGroup_values(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(*values_sp);
}

ListPairGnameGroupHandle MapGnameGroup_items(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(items_sp);
}

bool MapGnameGroup_equal(MapGnameGroupHandle a, MapGnameGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(b);
    return *listA == *listB;
}

bool MapGnameGroup_not_equal(MapGnameGroupHandle a, MapGnameGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_not_equal");
}
    return !MapGnameGroup_equal(a, b);
}

StringHandle      MapGnameGroup_to_json_string(MapGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MapGnameGroupHandle MapGnameGroup_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to MapGnameGroup_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(*ptr);
}
