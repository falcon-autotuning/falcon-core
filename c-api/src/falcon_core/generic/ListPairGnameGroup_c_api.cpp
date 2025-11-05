#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairGnameGroup_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>

ListPairGnameGroupHandle ListPairGnameGroup_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>());
}

ListPairGnameGroupHandle ListPairGnameGroup_fill_value(size_t count, PairGnameGroupHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(
        count, stored_obj);
}

ListPairGnameGroupHandle ListPairGnameGroup_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(count));
}

ListPairGnameGroupHandle ListPairGnameGroup_create(PairGnameGroupHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairGnameGroup_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(vec));
}

void ListPairGnameGroup_destroy(ListPairGnameGroupHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairGnameGroup_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
}

size_t ListPairGnameGroup_size(ListPairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->size();
}

bool ListPairGnameGroup_empty(ListPairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->empty();
}

void ListPairGnameGroup_erase_at(ListPairGnameGroupHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->erase_at(idx);
}

void ListPairGnameGroup_clear(ListPairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->clear();
}

void ListPairGnameGroup_push_back(ListPairGnameGroupHandle handle, PairGnameGroupHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->push_back(stored_obj);
}

bool ListPairGnameGroup_contains(ListPairGnameGroupHandle handle, PairGnameGroupHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->contains(stored_obj);
}

size_t ListPairGnameGroup_index(ListPairGnameGroupHandle handle, PairGnameGroupHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->index(stored_obj);
}

size_t ListPairGnameGroup_items(ListPairGnameGroupHandle handle, PairGnameGroupHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairGnameGroup_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(*list->items()[i]);
}
    return n;
}

PairGnameGroupHandle ListPairGnameGroup_at(ListPairGnameGroupHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(*obj);
}

bool ListPairGnameGroup_equal(ListPairGnameGroupHandle a, ListPairGnameGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(b);
    return *listA == *listB;
}

bool ListPairGnameGroup_not_equal(ListPairGnameGroupHandle a, ListPairGnameGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_not_equal");
}
    return !ListPairGnameGroup_equal(a, b);
}

ListPairGnameGroupHandle ListPairGnameGroup_intersection(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(*result);
}

StringHandle      ListPairGnameGroup_to_json_string(ListPairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairGnameGroupHandle ListPairGnameGroup_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairGnameGroup_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(*ptr);
}
