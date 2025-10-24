#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListBool_c_api.h"

ListBoolHandle ListBool_create_empty() {
    return new falcon_core::generic::List<bool>(
        falcon_core::generic::List<bool>());
}

ListBoolHandle ListBool_fill_value(size_t count, bool value) {
    auto stored_obj = value;
    return new falcon_core::generic::List<bool>(
        falcon_core::generic::List<bool>(count, stored_obj));
}

ListBoolHandle ListBool_allocate(size_t count) {
    return new falcon_core::generic::List<bool>(
        falcon_core::generic::List<bool>(count));
}

ListBoolHandle ListBool_create(const bool* data, size_t count) {
    std::vector<bool> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<bool>(
        falcon_core::generic::List<bool>(vec));
}

void ListBool_destroy(ListBoolHandle handle) {
    delete static_cast<falcon_core::generic::List<bool>*>(handle);
}

size_t ListBool_size(ListBoolHandle handle) {
    return static_cast<falcon_core::generic::List<bool>*>(handle)->size();
}

bool ListBool_empty(ListBoolHandle handle) {
    return static_cast<falcon_core::generic::List<bool>*>(handle)->empty();
}

void ListBool_erase_at(ListBoolHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<bool>*>(handle)->erase_at(idx);
}

void ListBool_clear(ListBoolHandle handle) {
    static_cast<falcon_core::generic::List<bool>*>(handle)->clear();
}

void ListBool_push_back(ListBoolHandle handle, bool value) {
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<bool>*>(handle)->push_back(stored_obj);
}

bool ListBool_contains(ListBoolHandle handle, bool value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<bool>*>(handle)->contains(stored_obj);
}

size_t ListBool_index(ListBoolHandle handle, bool value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<bool>*>(handle)->index(stored_obj);
}

size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<bool>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListBool_at(ListBoolHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<bool>*>(handle)->at(idx);
    return obj;
}

bool ListBool_equal(ListBoolHandle a, ListBoolHandle b) {
    auto listA = static_cast<falcon_core::generic::List<bool>*>(a);
    auto listB = static_cast<falcon_core::generic::List<bool>*>(b);
    return *listA == *listB;
}

bool ListBool_not_equal(ListBoolHandle a, ListBoolHandle b) {
    return !ListBool_equal(a, b);
}

ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other) {
    auto listA = static_cast<falcon_core::generic::List<bool>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<bool>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<bool>>(*listB));
    return new falcon_core::generic::List<bool>(*result);
}

StringHandle      ListBool_to_json_string(ListBoolHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<bool>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListBoolHandle ListBool_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<bool>::from_json_string<falcon_core::generic::List<bool>>(json->raw);
  return new falcon_core::generic::List<bool>(*ptr);
}
