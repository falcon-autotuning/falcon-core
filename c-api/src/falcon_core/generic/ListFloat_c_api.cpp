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
if (!data) {
throw std::invalid_argument("Null data handle passed to ListFloat_create");
}
    std::vector<float> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<float>(
        falcon_core::generic::List<float>(vec));
}

void ListFloat_destroy(ListFloatHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListFloat_destroy");
    }
    delete static_cast<falcon_core::generic::List<float>*>(handle);
}

size_t ListFloat_size(ListFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_size");
}
    return static_cast<falcon_core::generic::List<float>*>(handle)->size();
}

bool ListFloat_empty(ListFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_empty");
}
    return static_cast<falcon_core::generic::List<float>*>(handle)->empty();
}

void ListFloat_erase_at(ListFloatHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_erase_at");
}
    static_cast<falcon_core::generic::List<float>*>(handle)->erase_at(idx);
}

void ListFloat_clear(ListFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_clear");
}
    static_cast<falcon_core::generic::List<float>*>(handle)->clear();
}

void ListFloat_push_back(ListFloatHandle handle, float value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<float>*>(handle)->push_back(stored_obj);
}

bool ListFloat_contains(ListFloatHandle handle, float value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<float>*>(handle)->contains(stored_obj);
}

size_t ListFloat_index(ListFloatHandle handle, float value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<float>*>(handle)->index(stored_obj);
}

size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListFloat_items");
}
    auto list = static_cast<falcon_core::generic::List<float>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

float ListFloat_at(ListFloatHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_at");
}
    auto obj = static_cast<falcon_core::generic::List<float>*>(handle)->at(idx);
    return obj;
}

bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::List<float>*>(a);
    auto listB = static_cast<falcon_core::generic::List<float>*>(b);
    return *listA == *listB;
}

bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListFloat_not_equal");
}
    return !ListFloat_equal(a, b);
}

ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListFloat_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<float>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<float>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<float>>(*listB));
    return new falcon_core::generic::List<float>(*result);
}

StringHandle      ListFloat_to_json_string(ListFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<float>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListFloatHandle ListFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListFloat_from_json_string");
}
  auto ptr = falcon_core::generic::List<float>::from_json_string<falcon_core::generic::List<float>>(json->raw);
  return new falcon_core::generic::List<float>(*ptr);
}
