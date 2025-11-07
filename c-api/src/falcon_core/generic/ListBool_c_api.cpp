#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListBool_c_api.h"

ListBoolHandle ListBool_create_empty() {
    return new falcon_core::generic::List<bool>();
}

ListBoolHandle ListBool_fill_value(size_t count, bool value) {
    auto stored_obj = value;
    return new falcon_core::generic::List<bool>(
        count, stored_obj);
}
 ListBoolHandle ListBool_allocate(size_t count) {
    return new falcon_core::generic::List<bool>(count);
}


ListBoolHandle ListBool_create(bool* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListBool_create");
}
    std::vector<bool> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<bool>(vec);
}

void ListBool_destroy(ListBoolHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListBool_destroy");
    }
    delete static_cast<falcon_core::generic::List<bool>*>(handle);
}

size_t ListBool_size(ListBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_size");
}
    return static_cast<falcon_core::generic::List<bool>*>(handle)->size();
}

bool ListBool_empty(ListBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_empty");
}
    return static_cast<falcon_core::generic::List<bool>*>(handle)->empty();
}

void ListBool_erase_at(ListBoolHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_erase_at");
}
    static_cast<falcon_core::generic::List<bool>*>(handle)->erase_at(idx);
}

void ListBool_clear(ListBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_clear");
}
    static_cast<falcon_core::generic::List<bool>*>(handle)->clear();
}

void ListBool_push_back(ListBoolHandle handle, bool value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<bool>*>(handle)->push_back(stored_obj);
}

bool ListBool_contains(ListBoolHandle handle, bool value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<bool>*>(handle)->contains(stored_obj);
}

size_t ListBool_index(ListBoolHandle handle, bool value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<bool>*>(handle)->index(stored_obj);
}

size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListBool_items");
}
    auto list = static_cast<falcon_core::generic::List<bool>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListBool_at(ListBoolHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_at");
}
    auto obj = static_cast<falcon_core::generic::List<bool>*>(handle)->at(idx);
    return obj;
}

bool ListBool_equal(ListBoolHandle a, ListBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListBool_equal");
}
    auto listA = static_cast<falcon_core::generic::List<bool>*>(a);
    auto listB = static_cast<falcon_core::generic::List<bool>*>(b);
    return *listA == *listB;
}

bool ListBool_not_equal(ListBoolHandle a, ListBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListBool_not_equal");
}
    return !ListBool_equal(a, b);
}

ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListBool_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<bool>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<bool>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<bool>>(*listB));
    return new falcon_core::generic::List<bool>(*result);
}

StringHandle      ListBool_to_json_string(ListBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<bool>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListBoolHandle ListBool_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListBool_from_json_string");
}
  auto ptr = falcon_core::generic::List<bool>::from_json_string<falcon_core::generic::List<bool>>(json->raw);
  return new falcon_core::generic::List<bool>(*ptr);
}
