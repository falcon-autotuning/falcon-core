#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListGroup_c_api.h"
#include <falcon_core/physics/config/core/Group.hpp>

ListGroupHandle ListGroup_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(
        falcon_core::generic::List<falcon_core::physics::config::core::Group>());
}

ListGroupHandle ListGroup_fill_value(size_t count, GroupHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::core::Group>(static_cast<falcon_core::physics::config::core::Group*>(value), [](falcon_core::physics::config::core::Group*) {} );
    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(
        count, stored_obj);
}

ListGroupHandle ListGroup_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(
        falcon_core::generic::List<falcon_core::physics::config::core::Group>(count));
}

ListGroupHandle ListGroup_create(GroupHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListGroup_create");
}
    std::vector<falcon_core::physics::config::core::GroupSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::physics::config::core::Group>(static_cast<falcon_core::physics::config::core::Group*>(data[i]), [](falcon_core::physics::config::core::Group*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(
        falcon_core::generic::List<falcon_core::physics::config::core::Group>(vec));
}

void ListGroup_destroy(ListGroupHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListGroup_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle);
}

size_t ListGroup_size(ListGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->size();
}

bool ListGroup_empty(ListGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->empty();
}

void ListGroup_erase_at(ListGroupHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->erase_at(idx);
}

void ListGroup_clear(ListGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->clear();
}

void ListGroup_push_back(ListGroupHandle handle, GroupHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::core::Group>(static_cast<falcon_core::physics::config::core::Group*>(value), [](falcon_core::physics::config::core::Group*) {} );
    static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->push_back(stored_obj);
}

bool ListGroup_contains(ListGroupHandle handle, GroupHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::core::Group>(static_cast<falcon_core::physics::config::core::Group*>(value), [](falcon_core::physics::config::core::Group*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->contains(stored_obj);
}

size_t ListGroup_index(ListGroupHandle handle, GroupHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGroup_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::core::Group>(static_cast<falcon_core::physics::config::core::Group*>(value), [](falcon_core::physics::config::core::Group*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->index(stored_obj);
}

size_t ListGroup_items(ListGroupHandle handle, GroupHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListGroup_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::config::core::Group(*list->items()[i]);
}
    return n;
}

GroupHandle ListGroup_at(ListGroupHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->at(idx);
    return new falcon_core::physics::config::core::Group(*obj);
}

bool ListGroup_equal(ListGroupHandle a, ListGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListGroup_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(b);
    return *listA == *listB;
}

bool ListGroup_not_equal(ListGroupHandle a, ListGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListGroup_not_equal");
}
    return !ListGroup_equal(a, b);
}

ListGroupHandle ListGroup_intersection(ListGroupHandle handle, ListGroupHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListGroup_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::config::core::Group>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(*result);
}

StringHandle      ListGroup_to_json_string(ListGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGroup_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::physics::config::core::Group>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListGroupHandle ListGroup_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListGroup_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::List<falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::List<falcon_core::physics::config::core::Group>(*ptr);
}
