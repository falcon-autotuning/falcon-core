#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDouble_c_api.h"

ListDoubleHandle ListDouble_create_empty() {
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>());
}

ListDoubleHandle ListDouble_allocate(size_t count) {
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>(count));
}

void ListDouble_destroy(ListDoubleHandle handle) {
    delete static_cast<falcon_core::generic::List<double>*>(handle);
}

size_t ListDouble_size(ListDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<double>*>(handle)->size();
}

bool ListDouble_empty(ListDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<double>*>(handle)->empty();
}

void ListDouble_erase_at(ListDoubleHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<double>*>(handle)->erase_at(idx);
}

void ListDouble_clear(ListDoubleHandle handle) {
    static_cast<falcon_core::generic::List<double>*>(handle)->clear();
}

bool ListDouble_equal(ListDoubleHandle a, ListDoubleHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<double>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<double>>*>(b);
    return *listA == *listB;
}

bool ListDouble_not_equal(ListDoubleHandle a, ListDoubleHandle b) {
    return !ListDouble_equal(a, b);
}

ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other) {
    auto listA = static_cast<falcon_core::generic::List<double>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<double>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<double>>(*listB));
    return new falcon_core::generic::List<double>(*result);
}

ListDoubleHandle ListDouble_fill_value(size_t count, double value) {
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>(count, value));
}

ListDoubleHandle ListDouble_create(const double* data, size_t count) {
    std::vector<double> vec(data, data + count);
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>(vec));
}

void ListDouble_push_back(ListDoubleHandle handle, double value) {
    static_cast<falcon_core::generic::List<double>*>(handle)->push_back(value);
}

double ListDouble_at(ListDoubleHandle handle, size_t idx) {
    return static_cast<falcon_core::generic::List<double>*>(handle)->at(idx);
}

size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<double>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListDouble_contains(ListDoubleHandle handle, double value) {
    return static_cast<falcon_core::generic::List<double>*>(handle)->contains(value);
}

size_t ListDouble_index(ListDoubleHandle handle, double value) {
    return static_cast<falcon_core::generic::List<double>*>(handle)->index(value);
}
