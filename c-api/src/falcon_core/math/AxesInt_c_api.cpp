#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesInt_c_api.h"
#include <falcon_core/generic/List.hpp>

AxesIntHandle AxesInt_create_empty() {
    return new falcon_core::math::Axes<int>(
        falcon_core::math::Axes<int>());
}

AxesIntHandle AxesInt_create_raw(const int* data, size_t count) {
    std::vector<int> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::math::Axes<int>(
        falcon_core::math::Axes<int>(vec));
}

AxesIntHandle AxesInt_create(ListIntHandle data) {
    auto list = static_cast<falcon_core::generic::List<int>*>(data);
    return new falcon_core::math::Axes<int>(
            std::shared_ptr<falcon_core::generic::List<int>>(list));
}

void AxesInt_destroy(AxesIntHandle handle) {
    delete static_cast<falcon_core::math::Axes<int>*>(handle);
}

size_t AxesInt_size(AxesIntHandle handle) {
    return static_cast<falcon_core::math::Axes<int>*>(handle)->size();
}

bool AxesInt_empty(AxesIntHandle handle) {
    return static_cast<falcon_core::math::Axes<int>*>(handle)->empty();
}

void AxesInt_erase_at(AxesIntHandle handle, size_t idx) {
    static_cast<falcon_core::math::Axes<int>*>(handle)->erase_at(idx);
}

void AxesInt_clear(AxesIntHandle handle) {
    static_cast<falcon_core::math::Axes<int>*>(handle)->clear();
}

void AxesInt_push_back(AxesIntHandle handle, int value) {
    auto stored_obj = value;
    static_cast<falcon_core::math::Axes<int>*>(handle)->push_back(stored_obj);
}

bool AxesInt_contains(AxesIntHandle handle, int value) {
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<int>*>(handle)->contains(stored_obj);
}

size_t AxesInt_index(AxesIntHandle handle, int value) {
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<int>*>(handle)->index(stored_obj);
}

size_t AxesInt_items(AxesIntHandle handle, int* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::math::Axes<int>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

int AxesInt_at(AxesIntHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::Axes<int>*>(handle)->at(idx);
    return obj;
}

bool AxesInt_equal(AxesIntHandle a, AxesIntHandle b) {
    auto listA = static_cast<falcon_core::math::Axes<int>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<int>*>(b);
    return *listA == *listB;
}

bool AxesInt_not_equal(AxesIntHandle a, AxesIntHandle b) {
    return !AxesInt_equal(a, b);
}

AxesIntHandle AxesInt_intersection(AxesIntHandle handle, AxesIntHandle other) {
    auto listA = static_cast<falcon_core::math::Axes<int>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<int>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<int>>(*listB));
    return new falcon_core::math::Axes<int>(result);
}

StringHandle      AxesInt_to_json_string(AxesIntHandle handle) {
    std::string json = static_cast<falcon_core::math::Axes<int>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
AxesIntHandle AxesInt_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::Axes<int>::from_json_string<falcon_core::math::Axes<int>>(json->raw);
  return new falcon_core::math::Axes<int>(*ptr);
}
