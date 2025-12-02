#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListDoubleHandle ListDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::List<double>();
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle ListDouble_fill_value(size_t count, double value) {
    FALCON_C_API_BEGIN
    auto stored_obj = value;
    return new falcon_core::generic::List<double>(
        count, stored_obj);
    FALCON_C_API_END(nullptr)
}
 ListDoubleHandle ListDouble_allocate(size_t count) {
    return new falcon_core::generic::List<double>(count);
}


ListDoubleHandle ListDouble_create(double* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListDouble_create");
}
    std::vector<double> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::List<double>(vec);
    FALCON_C_API_END(nullptr)
}

void ListDouble_destroy(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListDouble_destroy");
    }
    delete static_cast<falcon_core::generic::List<double>*>(handle);
    FALCON_C_API_END()
}

size_t ListDouble_size(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_size");
}
    return static_cast<falcon_core::generic::List<double>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool ListDouble_empty(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_empty");
}
    return static_cast<falcon_core::generic::List<double>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void ListDouble_erase_at(ListDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_erase_at");
}
    static_cast<falcon_core::generic::List<double>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void ListDouble_clear(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_clear");
}
    static_cast<falcon_core::generic::List<double>*>(handle)->clear();
    FALCON_C_API_END()
}

void ListDouble_push_back(ListDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::generic::List<double>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListDouble_contains(ListDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<double>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListDouble_index(ListDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::generic::List<double>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListDouble_items");
}
    auto list = static_cast<falcon_core::generic::List<double>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
    FALCON_C_API_END(0)
}

double ListDouble_at(ListDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_at");
}
    auto obj = static_cast<falcon_core::generic::List<double>*>(handle)->at(idx);
    return obj;
    FALCON_C_API_END(0.0)
}

bool ListDouble_equal(ListDoubleHandle a, ListDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListDouble_equal");
}
    auto listA = static_cast<falcon_core::generic::List<double>*>(a);
    auto listB = static_cast<falcon_core::generic::List<double>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListDouble_not_equal(ListDoubleHandle a, ListDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListDouble_not_equal");
}
    return !ListDouble_equal(a, b);
    FALCON_C_API_END(false)
}

ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListDouble_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<double>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<double>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<double>>(*listB));
    return new falcon_core::generic::List<double>(*result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListDouble_to_json_string(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<double>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle ListDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListDouble_from_json_string");
}
  auto ptr = falcon_core::generic::List<double>::from_json_string<falcon_core::generic::List<double>>(json->raw);
  return new falcon_core::generic::List<double>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
