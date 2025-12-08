#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListGroup_c_api.h"
#include <falcon_core/physics/config/core/Group.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListGroupHandle ListGroup_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>(std::make_shared<falcon_core::generic::List<falcon_core::physics::config::core::Group>>());
    FALCON_C_API_END(nullptr)
}

ListGroupHandle ListGroup_fill_value(size_t count, GroupHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::physics::config::core::GroupSP*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::config::core::Group>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListGroupHandle ListGroup_create(GroupHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListGroup_create");
}
    std::vector<falcon_core::physics::config::core::GroupSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::physics::config::core::GroupSP*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::config::core::Group>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListGroup_destroy(ListGroupHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListGroup_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle);
    FALCON_C_API_END()
}

size_t ListGroup_size(ListGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListGroup_empty(ListGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListGroup_erase_at(ListGroupHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListGroup_clear(ListGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListGroup_push_back(ListGroupHandle handle, GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::physics::config::core::GroupSP*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListGroup_contains(ListGroupHandle handle, GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::physics::config::core::GroupSP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListGroup_index(ListGroupHandle handle, GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::physics::config::core::GroupSP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListGroup_items(ListGroupHandle handle, GroupHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListGroup_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::config::core::GroupSP(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

GroupHandle ListGroup_at(ListGroupHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->at(idx);
    return new falcon_core::physics::config::core::Group(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListGroup_equal(ListGroupHandle handle, ListGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListGroup_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListGroup_not_equal(ListGroupHandle handle, ListGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListGroup_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListGroupHandle ListGroup_intersection(ListGroupHandle handle, ListGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListGroup_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListGroup_to_json_string(ListGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListGroupHandle ListGroup_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListGroup_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::List<falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>(ptr);
    FALCON_C_API_END(nullptr)
}
}
