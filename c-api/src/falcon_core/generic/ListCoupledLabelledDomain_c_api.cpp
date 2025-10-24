#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"
#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>());
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_fill_value(size_t count, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(count, stored_obj));
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(count));
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create(const CoupledLabelledDomainHandle* data, size_t count) {
    std::vector<falcon_core::math::domains::CoupledLabelledDomainSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(data[i]), [](falcon_core::math::domains::CoupledLabelledDomain*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(vec));
}

void ListCoupledLabelledDomain_destroy(ListCoupledLabelledDomainHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
}

size_t ListCoupledLabelledDomain_size(ListCoupledLabelledDomainHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->size();
}

bool ListCoupledLabelledDomain_empty(ListCoupledLabelledDomainHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->empty();
}

void ListCoupledLabelledDomain_erase_at(ListCoupledLabelledDomainHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->erase_at(idx);
}

void ListCoupledLabelledDomain_clear(ListCoupledLabelledDomainHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->clear();
}

void ListCoupledLabelledDomain_push_back(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->push_back(stored_obj);
}

bool ListCoupledLabelledDomain_contains(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->contains(stored_obj);
}

size_t ListCoupledLabelledDomain_index(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::CoupledLabelledDomain>(static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value), [](falcon_core::math::domains::CoupledLabelledDomain*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->index(stored_obj);
}

size_t ListCoupledLabelledDomain_items(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::domains::CoupledLabelledDomain(*list->items()[i]);
}
    return n;
}

CoupledLabelledDomainHandle ListCoupledLabelledDomain_at(ListCoupledLabelledDomainHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::CoupledLabelledDomain(*obj);
}

bool ListCoupledLabelledDomain_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(b);
    return *listA == *listB;
}

bool ListCoupledLabelledDomain_not_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b) {
    return !ListCoupledLabelledDomain_equal(a, b);
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_intersection(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(*result);
}

StringHandle      ListCoupledLabelledDomain_to_json_string(ListCoupledLabelledDomainHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>::from_json_string<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(*ptr);
}
