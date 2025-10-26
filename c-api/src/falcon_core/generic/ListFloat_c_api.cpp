#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListFloat_c_api.h"

ListFloatHandle ListFloat_create_empty() {
    return new falcon_core::generic::List<float>(
        falcon_core::generic::List<float>());
}

ListFloatHandle ListFloat_fill_value(size_t count, float value) {
    auto stored_obj = value;
    return new falcon_core::generic::List<float>(
        falcon_core::generic::List<float>(count, stored_obj));
}

ListFloatHandle ListFloat_allocate(size_t count) {
    return new falcon_core::generic::List<float>(
        falcon_core::generic::List<float>(count));
}

ListFloatHandle ListFloat_create(float* data, size_t count) {
    std::vector<float> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<float>(
        falcon_core::generic::List<float>(vec));
}

void ListFloat_destroy(ListFloatHandle handle) {
    delete static_cast<falcon_core::generic::List<float>*>(handle);
}

size_t ListFloat_size(ListFloatHandle handle) {
    return static_cast<falcon_core::generic::List<float>*>(handle)->size();
}

bool ListFloat_empty(ListFloatHandle handle) {
    return static_cast<falcon_core::generic::List<float>*>(handle)->empty();
}

void ListFloat_erase_at(ListFloatHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<float>*>(handle)->erase_at(idx);
}

void ListFloat_clear(ListFloatHandle handle) {
    static_cast<falcon_core::generic::List<float>*>(handle)->clear();
}

void ListFloat_push_back(ListFloatHandle handle, float value) {
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<float>*>(handle)->push_back(stored_obj);
}

bool ListFloat_contains(ListFloatHandle handle, float value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<float>*>(handle)->contains(stored_obj);
}

size_t ListFloat_index(ListFloatHandle handle, float value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<float>*>(handle)->index(stored_obj);
}

size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<float>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

float ListFloat_at(ListFloatHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<float>*>(handle)->at(idx);
    return obj;
}

bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b) {
    auto listA = static_cast<falcon_core::generic::List<float>*>(a);
    auto listB = static_cast<falcon_core::generic::List<float>*>(b);
    return *listA == *listB;
}

bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b) {
    return !ListFloat_equal(a, b);
}

ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other) {
    auto listA = static_cast<falcon_core::generic::List<float>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<float>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<float>>(*listB));
    return new falcon_core::generic::List<float>(*result);
}

StringHandle      ListFloat_to_json_string(ListFloatHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<float>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListFloatHandle ListFloat_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<float>::from_json_string<falcon_core::generic::List<float>>(json->raw);
  return new falcon_core::generic::List<float>(*ptr);
}
