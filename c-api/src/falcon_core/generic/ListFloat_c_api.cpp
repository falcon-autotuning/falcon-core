#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListFloat_c_api.h"

ListFloatHandle ListFloat_create_empty() {
    return new std::shared_ptr<falcon_core::generic::List<float>>(
        std::make_shared<falcon_core::generic::List<float>>());
}

ListFloatHandle ListFloat_allocate(size_t count) {
    return new std::shared_ptr<falcon_core::generic::List<float>>(
        std::make_shared<falcon_core::generic::List<float>>(count));
}

ListFloatHandle ListFloat_fill_value(size_t count, float value) {
    return new std::shared_ptr<falcon_core::generic::List<float>>(
        std::make_shared<falcon_core::generic::List<float>>(count, value));
}

ListFloatHandle ListFloat_create(const float* data, size_t count) {
    std::vector<float> vec(data, data + count);
    return new std::shared_ptr<falcon_core::generic::List<float>>(
        std::make_shared<falcon_core::generic::List<float>>(vec));
}

void ListFloat_destroy(ListFloatHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle);
}

void ListFloat_push_back(ListFloatHandle handle, float value) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->push_back(value);
}

size_t ListFloat_size(ListFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->size();
}

bool ListFloat_empty(ListFloatHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->empty();
}

void ListFloat_erase_at(ListFloatHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->erase_at(idx);
}

void ListFloat_clear(ListFloatHandle handle) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->clear();
}

float ListFloat_const_at(ListFloatHandle handle, size_t idx) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->at(idx);
}

float ListFloat_at(ListFloatHandle handle, size_t idx) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->at(idx);
}

size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListFloat_contains(ListFloatHandle handle, float value) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->contains(value);
}

size_t ListFloat_index(ListFloatHandle handle, float value) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle))->index(value);
}

ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<falcon_core::generic::List<float>>(result);
}

bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<float>>*>(b);
    return *listA == *listB;
}

bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b) {
    return !ListFloat_equal(a, b);
}
