#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDouble_c_api.h"

ListDoubleHandle ListDouble_create_empty() {
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>());
}

ListDoubleHandle ListDouble_fill_value(size_t count, double value) {
    auto stored_obj = value;
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>(count, stored_obj));
}

ListDoubleHandle ListDouble_allocate(size_t count) {
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>(count));
}

ListDoubleHandle ListDouble_create(double* data, size_t count) {
    std::vector<double> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<double>(
        falcon_core::generic::List<double>(vec));
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

void ListDouble_push_back(ListDoubleHandle handle, double value) {
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<double>*>(handle)->push_back(stored_obj);
}

bool ListDouble_contains(ListDoubleHandle handle, double value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<double>*>(handle)->contains(stored_obj);
}

size_t ListDouble_index(ListDoubleHandle handle, double value) {
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<double>*>(handle)->index(stored_obj);
}

size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<double>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

double ListDouble_at(ListDoubleHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<double>*>(handle)->at(idx);
    return obj;
}

bool ListDouble_equal(ListDoubleHandle a, ListDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::List<double>*>(a);
    auto listB = static_cast<falcon_core::generic::List<double>*>(b);
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

StringHandle      ListDouble_to_json_string(ListDoubleHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<double>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListDoubleHandle ListDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<double>::from_json_string<falcon_core::generic::List<double>>(json->raw);
  return new falcon_core::generic::List<double>(*ptr);
}
