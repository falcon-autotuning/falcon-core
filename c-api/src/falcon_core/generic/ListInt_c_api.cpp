#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInt_c_api.h"

ListIntHandle ListInt_create_empty() {
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>());
}

ListIntHandle ListInt_fill_value(size_t count, int value) {
    auto stored_obj = value;
    return new falcon_core::generic::List<int>(
        count, stored_obj);
}

ListIntHandle ListInt_allocate(size_t count) {
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>(count));
}

ListIntHandle ListInt_create(int* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListInt_create");
}
    std::vector<int> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>(vec));
}

void ListInt_destroy(ListIntHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListInt_destroy");
    }
    delete static_cast<falcon_core::generic::List<int>*>(handle);
}

size_t ListInt_size(ListIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_size");
}
    return static_cast<falcon_core::generic::List<int>*>(handle)->size();
}

bool ListInt_empty(ListIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_empty");
}
    return static_cast<falcon_core::generic::List<int>*>(handle)->empty();
}

void ListInt_erase_at(ListIntHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_erase_at");
}
    static_cast<falcon_core::generic::List<int>*>(handle)->erase_at(idx);
}

void ListInt_clear(ListIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_clear");
}
    static_cast<falcon_core::generic::List<int>*>(handle)->clear();
}

void ListInt_push_back(ListIntHandle handle, int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<int>*>(handle)->push_back(stored_obj);
}

bool ListInt_contains(ListIntHandle handle, int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<int>*>(handle)->contains(stored_obj);
}

size_t ListInt_index(ListIntHandle handle, int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<int>*>(handle)->index(stored_obj);
}

size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListInt_items");
}
    auto list = static_cast<falcon_core::generic::List<int>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

int ListInt_at(ListIntHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_at");
}
    auto obj = static_cast<falcon_core::generic::List<int>*>(handle)->at(idx);
    return obj;
}

bool ListInt_equal(ListIntHandle a, ListIntHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListInt_equal");
}
    auto listA = static_cast<falcon_core::generic::List<int>*>(a);
    auto listB = static_cast<falcon_core::generic::List<int>*>(b);
    return *listA == *listB;
}

bool ListInt_not_equal(ListIntHandle a, ListIntHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListInt_not_equal");
}
    return !ListInt_equal(a, b);
}

ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListInt_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<int>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<int>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<int>>(*listB));
    return new falcon_core::generic::List<int>(*result);
}

StringHandle      ListInt_to_json_string(ListIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<int>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListIntHandle ListInt_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListInt_from_json_string");
}
  auto ptr = falcon_core::generic::List<int>::from_json_string<falcon_core::generic::List<int>>(json->raw);
  return new falcon_core::generic::List<int>(*ptr);
}
