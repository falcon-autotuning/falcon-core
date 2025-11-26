#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesInt_c_api.h"
#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesIntHandle AxesInt_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<int>(
        falcon_core::math::Axes<int>());
    FALCON_C_API_END(nullptr)
}

AxesIntHandle AxesInt_create(ListIntHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesInt_create");
}
    auto list = *static_cast<falcon_core::generic::List<int>*>(data);
    return new falcon_core::math::Axes<int>(
            std::make_shared<falcon_core::generic::List<int>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesInt_destroy(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_destroy");
}
    delete static_cast<falcon_core::math::Axes<int>*>(handle);
    FALCON_C_API_END()
}

size_t AxesInt_size(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_size");
}
    return static_cast<falcon_core::math::Axes<int>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesInt_empty(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_empty");
}
    return static_cast<falcon_core::math::Axes<int>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesInt_erase_at(AxesIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_erase_at");
}
    static_cast<falcon_core::math::Axes<int>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesInt_clear(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_clear");
}
    static_cast<falcon_core::math::Axes<int>*>(handle)->clear();
    FALCON_C_API_END()
}

void AxesInt_push_back(AxesIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_push_back");
}
    auto stored_obj = value;
    static_cast<falcon_core::math::Axes<int>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesInt_contains(AxesIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_contains");
}
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<int>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesInt_index(AxesIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_index");
}
    auto stored_obj = value;
    return static_cast<falcon_core::math::Axes<int>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesInt_items(AxesIntHandle handle, int* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesInt_items");
}
    auto list = static_cast<falcon_core::math::Axes<int>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
    FALCON_C_API_END(0)
}

int AxesInt_at(AxesIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_at");
}
    auto obj = static_cast<falcon_core::math::Axes<int>*>(handle)->at(idx);
    return obj;
    FALCON_C_API_END(0)
}

bool AxesInt_equal(AxesIntHandle a, AxesIntHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesInt_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<int>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<int>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesInt_not_equal(AxesIntHandle a, AxesIntHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesInt_not_equal");
}
    return !AxesInt_equal(a, b);
    FALCON_C_API_END(false)
}

AxesIntHandle AxesInt_intersection(AxesIntHandle handle, AxesIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesInt_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<int>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<int>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<int>>(*listB));
    return new falcon_core::math::Axes<int>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesInt_to_json_string(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<int>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesIntHandle AxesInt_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesInt_from_json_string");
}
  auto ptr = falcon_core::math::Axes<int>::from_json_string<falcon_core::math::Axes<int>>(json->raw);
  return new falcon_core::math::Axes<int>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
