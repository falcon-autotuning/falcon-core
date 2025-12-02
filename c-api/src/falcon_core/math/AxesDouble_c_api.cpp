#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesDouble_c_api.h"
#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesDoubleHandle AxesDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<double>(
        falcon_core::math::Axes<double>());
    FALCON_C_API_END(nullptr)
}

AxesDoubleHandle AxesDouble_create(ListDoubleHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesDouble_create");
}
    auto list = *static_cast<falcon_core::generic::List<double>*>(data);
    return new falcon_core::math::Axes<double>(
            std::make_shared<falcon_core::generic::List<double>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesDouble_destroy(AxesDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_destroy");
}
    delete static_cast<falcon_core::math::Axes<double>*>(handle);
    FALCON_C_API_END()
}

size_t AxesDouble_size(AxesDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_size");
}
    return static_cast<falcon_core::math::Axes<double>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesDouble_empty(AxesDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_empty");
}
    return static_cast<falcon_core::math::Axes<double>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesDouble_erase_at(AxesDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_erase_at");
}
    static_cast<falcon_core::math::Axes<double>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesDouble_clear(AxesDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_clear");
}
    static_cast<falcon_core::math::Axes<double>*>(handle)->clear();
    FALCON_C_API_END()
}

void AxesDouble_push_back(AxesDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::math::Axes<double>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesDouble_contains(AxesDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<double>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesDouble_index(AxesDoubleHandle handle, double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<double>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesDouble_items(AxesDoubleHandle handle, double* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
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
    FALCON_C_API_END(0)
}

double AxesDouble_at(AxesDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_at");
}
    auto obj = static_cast<falcon_core::math::Axes<double>*>(handle)->at(idx);
    return obj;
    FALCON_C_API_END(0.0)
}

bool AxesDouble_equal(AxesDoubleHandle a, AxesDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesDouble_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<double>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<double>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesDouble_not_equal(AxesDoubleHandle a, AxesDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesDouble_not_equal");
}
    return !AxesDouble_equal(a, b);
    FALCON_C_API_END(false)
}

AxesDoubleHandle AxesDouble_intersection(AxesDoubleHandle handle, AxesDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesDouble_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<double>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<double>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<double>>(*listB));
    return new falcon_core::math::Axes<double>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesDouble_to_json_string(AxesDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDouble_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<double>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesDoubleHandle AxesDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesDouble_from_json_string");
}
  auto ptr = falcon_core::math::Axes<double>::from_json_string<falcon_core::math::Axes<double>>(json->raw);
  return new falcon_core::math::Axes<double>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
