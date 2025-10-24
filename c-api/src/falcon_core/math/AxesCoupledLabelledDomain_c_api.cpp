#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>());
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_raw(const CoupledLabelledDomainHandle* data, size_t count) {
    std::vector<falcon_core::math::domains::CoupledLabelledDomainSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(data[i]), [](falcon_core::math::domains::CoupledLabelledDomain*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(vec));
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create(ListCoupledLabelledDomainHandle data) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(list));
}

void AxesCoupledLabelledDomain_destroy(AxesCoupledLabelledDomainHandle handle) {
    delete static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
}

size_t AxesCoupledLabelledDomain_size(AxesCoupledLabelledDomainHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->size();
}

bool AxesCoupledLabelledDomain_empty(AxesCoupledLabelledDomainHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->empty();
}

void AxesCoupledLabelledDomain_erase_at(AxesCoupledLabelledDomainHandle handle, size_t idx) {
    static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->erase_at(idx);
}

void AxesCoupledLabelledDomain_clear(AxesCoupledLabelledDomainHandle handle) {
    static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->clear();
}

void AxesCoupledLabelledDomain_push_back(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->push_back(stored_obj);
}

bool AxesCoupledLabelledDomain_contains(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->contains(stored_obj);
}

size_t AxesCoupledLabelledDomain_index(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->index(stored_obj);
}

size_t AxesCoupledLabelledDomain_items(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::domains::CoupledLabelledDomain(*list->items()[i]);
}
    return n;
}

CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at(AxesCoupledLabelledDomainHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::CoupledLabelledDomain(*obj);
}

bool AxesCoupledLabelledDomain_equal(AxesCoupledLabelledDomainHandle a, AxesCoupledLabelledDomainHandle b) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(b);
    return *listA == *listB;
}

bool AxesCoupledLabelledDomain_not_equal(AxesCoupledLabelledDomainHandle a, AxesCoupledLabelledDomainHandle b) {
    return !AxesCoupledLabelledDomain_equal(a, b);
}

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(result);
}

StringHandle      AxesCoupledLabelledDomain_to_json_string(AxesCoupledLabelledDomainHandle handle) {
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>::from_json_string<falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>(*ptr);
}
