#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListSizeT_c_api.h"

ListSizeTHandle ListSizeT_create_empty() {
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>());
}

ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value) {
    auto stored_obj = value;
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>(count, stored_obj));
}

ListSizeTHandle ListSizeT_allocate(size_t count) {
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>(count));
}

ListSizeTHandle ListSizeT_create(const size_t* data, size_t count) {
    std::vector<size_t> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>(vec));
}

void ListSizeT_destroy(ListSizeTHandle handle) {
    delete static_cast<falcon_core::generic::List<size_t>*>(handle);
}

size_t ListSizeT_size(ListSizeTHandle handle) {
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->size();
}

bool ListSizeT_empty(ListSizeTHandle handle) {
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->empty();
}

void ListSizeT_erase_at(ListSizeTHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<size_t>*>(handle)->erase_at(idx);
}

void ListSizeT_clear(ListSizeTHandle handle) {
    static_cast<falcon_core::generic::List<size_t>*>(handle)->clear();
}

void ListSizeT_push_back(ListSizeTHandle handle, size_t value) {
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<size_t>*>(handle)->push_back(stored_obj);
}

bool ListSizeT_contains(ListSizeTHandle handle, size_t value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->contains(stored_obj);
}

size_t ListSizeT_index(ListSizeTHandle handle, size_t value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->index(stored_obj);
}

size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<size_t>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

size_t ListSizeT_at(ListSizeTHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<size_t>*>(handle)->at(idx);
    return obj;
}

bool ListSizeT_equal(ListSizeTHandle a, ListSizeTHandle b) {
    auto listA = static_cast<falcon_core::generic::List<size_t>*>(a);
    auto listB = static_cast<falcon_core::generic::List<size_t>*>(b);
    return *listA == *listB;
}

bool ListSizeT_not_equal(ListSizeTHandle a, ListSizeTHandle b) {
    return !ListSizeT_equal(a, b);
}

ListSizeTHandle ListSizeT_intersection(ListSizeTHandle handle, ListSizeTHandle other) {
    auto listA = static_cast<falcon_core::generic::List<size_t>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<size_t>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<size_t>>(*listB));
    return new falcon_core::generic::List<size_t>(*result);
}

StringHandle      ListSizeT_to_json_string(ListSizeTHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<size_t>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListSizeTHandle ListSizeT_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<size_t>::from_json_string<falcon_core::generic::List<size_t>>(json->raw);
  return new falcon_core::generic::List<size_t>(*ptr);
}
