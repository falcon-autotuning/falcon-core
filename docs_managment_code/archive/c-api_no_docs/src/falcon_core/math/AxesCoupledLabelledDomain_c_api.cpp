#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>());
    FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_raw(const CoupledLabelledDomainHandle* data, size_t count) {
    FALCON_C_API_BEGIN
    std::vector<falcon_core::math::domains::CoupledLabelledDomainSP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesCoupledLabelledDomain_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(data[i])));
    }

    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(vec));
    FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create(ListCoupledLabelledDomainHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesCoupledLabelledDomain_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesCoupledLabelledDomain_destroy(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    FALCON_C_API_END()
}

size_t AxesCoupledLabelledDomain_size(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesCoupledLabelledDomain_empty(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesCoupledLabelledDomain_erase_at(AxesCoupledLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesCoupledLabelledDomain_clear(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->clear();
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
            auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->push_back(stored_obj);
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
            auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->contains(stored_obj);
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
            auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->index(stored_obj);
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
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::domains::CoupledLabelledDomain(*list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at(AxesCoupledLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::CoupledLabelledDomain(*obj);
    FALCON_C_API_END(nullptr)
}

bool AxesCoupledLabelledDomain_equal(AxesCoupledLabelledDomainHandle a, AxesCoupledLabelledDomainHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesCoupledLabelledDomain_not_equal(AxesCoupledLabelledDomainHandle a, AxesCoupledLabelledDomainHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_not_equal");
}
    return !AxesCoupledLabelledDomain_equal(a, b);
    FALCON_C_API_END(false)
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesCoupledLabelledDomain_to_json_string(AxesCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesCoupledLabelledDomain_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesCoupledLabelledDomain_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>::from_json_string<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
