#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesInt_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesint= falcon_core::math::Axes<int>;
DEFINE_C_API_COPY_TEMPLATE(AxesInt, MACROAxesint)
DEFINE_C_API_DESTROY_TEMPLATE(AxesInt, MACROAxesint);
DEFINE_C_API_EQUAL_TEMPLATE(AxesInt, MACROAxesint);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesInt, MACROAxesint);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesInt, MACROAxesint);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesInt, MACROAxesint);
AxesIntHandle AxesInt_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<int>(
        std::make_shared<falcon_core::math::Axes<int>>());
    FALCON_C_API_END(nullptr)
}

AxesIntHandle AxesInt_create(ListIntHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesInt_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<int>*>(data);
    return new falcon_core::math::AxesSP<int>(
            std::make_shared<falcon_core::math::Axes<int>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesInt_size(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_size");
}
    return (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesInt_empty(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesInt_erase_at(AxesIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesInt_clear(AxesIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_clear");
}
    (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesInt_push_back(AxesIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_push_back");
}
    auto stored_obj = value;
    (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesInt_contains(AxesIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_contains");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesInt_index(AxesIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInt_index");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->index(stored_obj);
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
    auto list = *static_cast<falcon_core::math::AxesSP<int>*>(handle);
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
    auto obj = (*static_cast<falcon_core::math::AxesSP<int>*>(handle))->at(idx);
    return obj;
    FALCON_C_API_END(0)
}

AxesIntHandle AxesInt_intersection(AxesIntHandle handle, AxesIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesInt_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<int>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<int>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<int>(std::make_shared<falcon_core::math::Axes<int>>(result));
    FALCON_C_API_END(nullptr)
}
}
