#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListdouble= falcon_core::generic::List<double>;
DEFINE_C_API_COPY_TEMPLATE(ListDouble, MACROListdouble)
DEFINE_C_API_DESTROY_TEMPLATE(ListDouble, MACROListdouble);
DEFINE_C_API_EQUAL_TEMPLATE(ListDouble, MACROListdouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListDouble, MACROListdouble);
DEFINE_C_API_TO_JSON_TEMPLATE(ListDouble, MACROListdouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListDouble, MACROListdouble);
ListDoubleHandle ListDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<double>(std::make_shared<falcon_core::generic::List<double>>());
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle ListDouble_fill_value(size_t count, double value) {
    FALCON_C_API_BEGIN
    auto stored_obj = value;
    return new falcon_core::generic::ListSP<double>(
        std::make_shared<falcon_core::generic::List<double>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 ListDoubleHandle ListDouble_allocate(size_t count) {
    return new falcon_core::generic::ListSP<double>(std::make_shared<falcon_core::generic::List<double>>(count));
}


ListDoubleHandle ListDouble_create(double* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListDouble_create");
}
    std::vector<double> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::ListSP<double>(
        std::make_shared<falcon_core::generic::List<double>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListDouble_size(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_size");
}
    return (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListDouble_empty(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListDouble_erase_at(ListDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListDouble_clear(ListDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_clear");
}
    (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListDouble_push_back(ListDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_push_back");
}
    auto stored_obj = value;
    (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListDouble_contains(ListDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_contains");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListDouble_index(ListDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDouble_index");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->index(stored_obj);
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
    auto list = *static_cast<falcon_core::generic::ListSP<double>*>(handle);
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
    auto obj = (*static_cast<falcon_core::generic::ListSP<double>*>(handle))->at(idx);
    return obj;
    FALCON_C_API_END(0.0)
}

ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListDouble_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<double>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<double>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<double>(result);
    FALCON_C_API_END(nullptr)
}
}
