#include <falcon-core/math/Axes.hpp>
#include "falcon-core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/List.hpp>
#include <falcon-core/math/domains/CoupledLabelledDomain.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesCoupledLabelledDomainHandle= falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>;
DEFINE_C_API_COPY_TEMPLATE(AxesCoupledLabelledDomain, MACROAxesCoupledLabelledDomainHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesCoupledLabelledDomain, MACROAxesCoupledLabelledDomainHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesCoupledLabelledDomain, MACROAxesCoupledLabelledDomainHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesCoupledLabelledDomain, MACROAxesCoupledLabelledDomainHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesCoupledLabelledDomain, MACROAxesCoupledLabelledDomainHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesCoupledLabelledDomain, MACROAxesCoupledLabelledDomainHandle);
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>(
        std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>());
    FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create(ListCoupledLabelledDomainHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesCoupledLabelledDomain_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::CoupledLabelledDomain>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>(
            std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesCoupledLabelledDomain_size(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesCoupledLabelledDomain_empty(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesCoupledLabelledDomain_erase_at(AxesCoupledLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesCoupledLabelledDomain_clear(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesCoupledLabelledDomain_push_back(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesCoupledLabelledDomain_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesCoupledLabelledDomain_contains(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesCoupledLabelledDomain_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesCoupledLabelledDomain_index(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesCoupledLabelledDomain_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesCoupledLabelledDomain_items(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesCoupledLabelledDomain_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at(AxesCoupledLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(obj);
    FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>(std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>(result));
    FALCON_C_API_END(nullptr)
}
}
