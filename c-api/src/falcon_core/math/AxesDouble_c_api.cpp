#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesDouble_c_api.h"
#include <falcon_core/generic/List.hpp>

AxesDoubleHandle AxesDouble_create_empty() {
    return new falcon_core::math::Axes<double>(
        falcon_core::math::Axes<double>());
}

AxesDoubleHandle AxesDouble_create_raw(const double* data, size_t count) {
    std::vector<double> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::math::Axes<double>(
        falcon_core::math::Axes<double>(vec));
}

AxesDoubleHandle AxesDouble_create(ListDoubleHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesDouble_create");
}
    auto list = static_cast<falcon_core::generic::List<double>*>(data);
    return new falcon_core::math::Axes<double>(
            std::shared_ptr<falcon_core::generic::List<double>>(list));
}

void AxesDouble_destroy(AxesDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_destroy");
}
    delete static_cast<falcon_core::math::Axes<double>*>(handle);
}

size_t AxesDouble_size(AxesDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_size");
}
    return static_cast<falcon_core::math::Axes<double>*>(handle)->size();
}

bool AxesDouble_empty(AxesDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_empty");
}
    return static_cast<falcon_core::math::Axes<double>*>(handle)->empty();
}

void AxesDouble_erase_at(AxesDoubleHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_erase_at");
}
    static_cast<falcon_core::math::Axes<double>*>(handle)->erase_at(idx);
}

void AxesDouble_clear(AxesDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_clear");
}
    static_cast<falcon_core::math::Axes<double>*>(handle)->clear();
}

void AxesDouble_push_back(AxesDoubleHandle handle, double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::math::Axes<double>*>(handle)->push_back(stored_obj);
}

bool AxesDouble_contains(AxesDoubleHandle handle, double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<double>*>(handle)->contains(stored_obj);
}

size_t AxesDouble_index(AxesDoubleHandle handle, double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<double>*>(handle)->index(stored_obj);
}

size_t AxesDouble_items(AxesDoubleHandle handle, double* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesDouble_items");
}
    auto list = static_cast<falcon_core::math::Axes<double>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

double AxesDouble_at(AxesDoubleHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_at");
}
    auto obj = static_cast<falcon_core::math::Axes<double>*>(handle)->at(idx);
    return obj;
}

bool AxesDouble_equal(AxesDoubleHandle a, AxesDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesDouble_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<double>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<double>*>(b);
    return *listA == *listB;
}

bool AxesDouble_not_equal(AxesDoubleHandle a, AxesDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesDouble_not_equal");
}
    return !AxesDouble_equal(a, b);
}

AxesDoubleHandle AxesDouble_intersection(AxesDoubleHandle handle, AxesDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesDouble_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<double>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<double>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<double>>(*listB));
    return new falcon_core::math::Axes<double>(result);
}

StringHandle      AxesDouble_to_json_string(AxesDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<double>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesDoubleHandle AxesDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesDouble_from_json_string");
}
  auto ptr = falcon_core::math::Axes<double>::from_json_string<falcon_core::math::Axes<double>>(json->raw);
  return new falcon_core::math::Axes<double>(*ptr);
}
