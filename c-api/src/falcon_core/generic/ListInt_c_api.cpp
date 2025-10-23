#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInt_c_api.h"

ListIntHandle ListInt_create_empty() {
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>());
}

ListIntHandle ListInt_allocate(size_t count) {
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>(count));
}

void ListInt_destroy(ListIntHandle handle) {
    delete static_cast<falcon_core::generic::List<int>*>(handle);
}

size_t ListInt_size(ListIntHandle handle) {
    return static_cast<falcon_core::generic::List<int>*>(handle)->size();
}

bool ListInt_empty(ListIntHandle handle) {
    return static_cast<falcon_core::generic::List<int>*>(handle)->empty();
}

void ListInt_erase_at(ListIntHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<int>*>(handle)->erase_at(idx);
}

void ListInt_clear(ListIntHandle handle) {
    static_cast<falcon_core::generic::List<int>*>(handle)->clear();
}

bool ListInt_equal(ListIntHandle a, ListIntHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<int>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<int>>*>(b);
    return *listA == *listB;
}

bool ListInt_not_equal(ListIntHandle a, ListIntHandle b) {
    return !ListInt_equal(a, b);
}

ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other) {
    auto listA = static_cast<falcon_core::generic::List<int>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<int>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<int>>(*listB));
    return new falcon_core::generic::List<int>(*result);
}

ListIntHandle ListInt_fill_value(size_t count, int value) {
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>(count, value));
}

ListIntHandle ListInt_create(const int* data, size_t count) {
    std::vector<int> vec(data, data + count);
    return new falcon_core::generic::List<int>(
        falcon_core::generic::List<int>(vec));
}

void ListInt_push_back(ListIntHandle handle, int value) {
    static_cast<falcon_core::generic::List<int>*>(handle)->push_back(value);
}

int ListInt_const_at(ListIntHandle handle, size_t idx) {
    return static_cast<falcon_core::generic::List<int>*>(handle)->at(idx);
}

int ListInt_at(ListIntHandle handle, size_t idx) {
    return static_cast<falcon_core::generic::List<int>*>(handle)->at(idx);
}

size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<int>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListInt_contains(ListIntHandle handle, int value) {
    return static_cast<falcon_core::generic::List<int>*>(handle)->contains(value);
}

size_t ListInt_index(ListIntHandle handle, int value) {
    return static_cast<falcon_core::generic::List<int>*>(handle)->index(value);
}
