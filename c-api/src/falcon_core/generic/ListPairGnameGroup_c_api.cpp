#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairGnameGroup_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairGnameGroupHandle ListPairGnameGroup_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>>());
    FALCON_C_API_END(nullptr)
}

ListPairGnameGroupHandle ListPairGnameGroup_fill_value(size_t count, PairGnameGroupHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairGnameGroupHandle ListPairGnameGroup_create(PairGnameGroupHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairGnameGroup_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairGnameGroup_destroy(ListPairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairGnameGroup_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairGnameGroup_size(ListPairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairGnameGroup_empty(ListPairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairGnameGroup_erase_at(ListPairGnameGroupHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairGnameGroup_clear(ListPairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairGnameGroup_push_back(ListPairGnameGroupHandle handle, PairGnameGroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairGnameGroup_contains(ListPairGnameGroupHandle handle, PairGnameGroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairGnameGroup_index(ListPairGnameGroupHandle handle, PairGnameGroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairGnameGroup_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairGnameGroup_items(ListPairGnameGroupHandle handle, PairGnameGroupHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairGnameGroup_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairGnameGroupHandle ListPairGnameGroup_at(ListPairGnameGroupHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairGnameGroup_equal(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairGnameGroup_not_equal(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairGnameGroupHandle ListPairGnameGroup_intersection(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairGnameGroup_to_json_string(ListPairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairGnameGroup_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairGnameGroupHandle ListPairGnameGroup_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairGnameGroup_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
