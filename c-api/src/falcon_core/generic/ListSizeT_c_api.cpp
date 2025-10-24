#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListSizeT_c_api.h"

ListSizeTHandle ListSizeT_create_empty() {
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>());
}

ListSizeTHandle ListSizeT_allocate(size_t count) {
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>(count));
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

ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value) {
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>(count, value));
}

ListSizeTHandle ListSizeT_create(const size_t* data, size_t count) {
    std::vector<size_t> vec(data, data + count);
    return new falcon_core::generic::List<size_t>(
        falcon_core::generic::List<size_t>(vec));
}

void ListSizeT_push_back(ListSizeTHandle handle, size_t value) {
    static_cast<falcon_core::generic::List<size_t>*>(handle)->push_back(value);
}

size_t ListSizeT_at(ListSizeTHandle handle, size_t idx) {
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->at(idx);
}

size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<size_t>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListSizeT_contains(ListSizeTHandle handle, size_t value) {
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->contains(value);
}

size_t ListSizeT_index(ListSizeTHandle handle, size_t value) {
    return static_cast<falcon_core::generic::List<size_t>*>(handle)->index(value);
}
