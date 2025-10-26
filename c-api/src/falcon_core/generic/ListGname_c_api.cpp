#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListGname_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>

ListGnameHandle ListGname_create_empty() {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>());
}

ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(static_cast<falcon_core::autotuner_interfaces::names::Gname*>(value), [](falcon_core::autotuner_interfaces::names::Gname*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(count, stored_obj));
}

ListGnameHandle ListGname_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(count));
}

ListGnameHandle ListGname_create(GnameHandle* data, size_t count) {
    std::vector<falcon_core::autotuner_interfaces::names::GnameSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(static_cast<falcon_core::autotuner_interfaces::names::Gname*>(data[i]), [](falcon_core::autotuner_interfaces::names::Gname*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(vec));
}

void ListGname_destroy(ListGnameHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle);
}

size_t ListGname_size(ListGnameHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->size();
}

bool ListGname_empty(ListGnameHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->empty();
}

void ListGname_erase_at(ListGnameHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->erase_at(idx);
}

void ListGname_clear(ListGnameHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->clear();
}

void ListGname_push_back(ListGnameHandle handle, GnameHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(static_cast<falcon_core::autotuner_interfaces::names::Gname*>(value), [](falcon_core::autotuner_interfaces::names::Gname*) {} );
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->push_back(stored_obj);
}

bool ListGname_contains(ListGnameHandle handle, GnameHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(static_cast<falcon_core::autotuner_interfaces::names::Gname*>(value), [](falcon_core::autotuner_interfaces::names::Gname*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->contains(stored_obj);
}

size_t ListGname_index(ListGnameHandle handle, GnameHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(static_cast<falcon_core::autotuner_interfaces::names::Gname*>(value), [](falcon_core::autotuner_interfaces::names::Gname*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->index(stored_obj);
}

size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::names::Gname(*list->items()[i]);
}
    return n;
}

GnameHandle ListGname_at(ListGnameHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::names::Gname(*obj);
}

bool ListGname_equal(ListGnameHandle a, ListGnameHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(b);
    return *listA == *listB;
}

bool ListGname_not_equal(ListGnameHandle a, ListGnameHandle b) {
    return !ListGname_equal(a, b);
}

ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(*result);
}

StringHandle      ListGname_to_json_string(ListGnameHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListGnameHandle ListGname_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>(*ptr);
}
