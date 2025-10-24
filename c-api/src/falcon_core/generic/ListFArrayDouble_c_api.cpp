#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include <falcon_core/generic/FArray.hpp>

ListFArrayDoubleHandle ListFArrayDouble_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::FArray<double>>(
        falcon_core::generic::List<falcon_core::generic::FArray<double>>());
}

ListFArrayDoubleHandle ListFArrayDouble_fill_value(size_t count, FArrayDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::FArray<double>>(static_cast<falcon_core::generic::FArray<double>*>(value), [](falcon_core::generic::FArray<double>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::FArray<double>>(
        falcon_core::generic::List<falcon_core::generic::FArray<double>>(count, stored_obj));
}

ListFArrayDoubleHandle ListFArrayDouble_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::FArray<double>>(
        falcon_core::generic::List<falcon_core::generic::FArray<double>>(count));
}

ListFArrayDoubleHandle ListFArrayDouble_create(const FArrayDoubleHandle* data, size_t count) {
    std::vector<falcon_core::generic::FArraySP<double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::FArray<double>>(static_cast<falcon_core::generic::FArray<double>*>(data[i]), [](falcon_core::generic::FArray<double>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::FArray<double>>(
        falcon_core::generic::List<falcon_core::generic::FArray<double>>(vec));
}

void ListFArrayDouble_destroy(ListFArrayDoubleHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle);
}

size_t ListFArrayDouble_size(ListFArrayDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->size();
}

bool ListFArrayDouble_empty(ListFArrayDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->empty();
}

void ListFArrayDouble_erase_at(ListFArrayDoubleHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->erase_at(idx);
}

void ListFArrayDouble_clear(ListFArrayDoubleHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->clear();
}

void ListFArrayDouble_push_back(ListFArrayDoubleHandle handle, FArrayDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::FArray<double>>(static_cast<falcon_core::generic::FArray<double>*>(value), [](falcon_core::generic::FArray<double>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->push_back(stored_obj);
}

bool ListFArrayDouble_contains(ListFArrayDoubleHandle handle, FArrayDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::FArray<double>>(static_cast<falcon_core::generic::FArray<double>*>(value), [](falcon_core::generic::FArray<double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->contains(stored_obj);
}

size_t ListFArrayDouble_index(ListFArrayDoubleHandle handle, FArrayDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::FArray<double>>(static_cast<falcon_core::generic::FArray<double>*>(value), [](falcon_core::generic::FArray<double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->index(stored_obj);
}

size_t ListFArrayDouble_items(ListFArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::FArray<double>(*list->items()[i]);
}
    return n;
}

FArrayDoubleHandle ListFArrayDouble_at(ListFArrayDoubleHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->at(idx);
    return new falcon_core::generic::FArray<double>(*obj);
}

bool ListFArrayDouble_equal(ListFArrayDoubleHandle a, ListFArrayDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(b);
    return *listA == *listB;
}

bool ListFArrayDouble_not_equal(ListFArrayDoubleHandle a, ListFArrayDoubleHandle b) {
    return !ListFArrayDouble_equal(a, b);
}

ListFArrayDoubleHandle ListFArrayDouble_intersection(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::FArray<double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::FArray<double>>(*result);
}

StringHandle      ListFArrayDouble_to_json_string(ListFArrayDoubleHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::FArray<double>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListFArrayDoubleHandle ListFArrayDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::FArray<double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::FArray<double>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::FArray<double>>(*ptr);
}
