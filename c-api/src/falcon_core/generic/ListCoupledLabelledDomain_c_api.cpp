#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"
#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>();
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_fill_value(size_t count, CoupledLabelledDomainHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(
        count, stored_obj);
}
 

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create(CoupledLabelledDomainHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListCoupledLabelledDomain_create");
}
    std::vector<falcon_core::math::domains::CoupledLabelledDomainSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(vec);
}

void ListCoupledLabelledDomain_destroy(ListCoupledLabelledDomainHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
}

size_t ListCoupledLabelledDomain_size(ListCoupledLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->size();
}

bool ListCoupledLabelledDomain_empty(ListCoupledLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->empty();
}

void ListCoupledLabelledDomain_erase_at(ListCoupledLabelledDomainHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->erase_at(idx);
}

void ListCoupledLabelledDomain_clear(ListCoupledLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->clear();
}

void ListCoupledLabelledDomain_push_back(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->push_back(stored_obj);
}

bool ListCoupledLabelledDomain_contains(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->contains(stored_obj);
}

size_t ListCoupledLabelledDomain_index(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->index(stored_obj);
}

size_t ListCoupledLabelledDomain_items(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListCoupledLabelledDomain_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::domains::CoupledLabelledDomain(*list->items()[i]);
}
    return n;
}

CoupledLabelledDomainHandle ListCoupledLabelledDomain_at(ListCoupledLabelledDomainHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::CoupledLabelledDomain(*obj);
}

bool ListCoupledLabelledDomain_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(b);
    return *listA == *listB;
}

bool ListCoupledLabelledDomain_not_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_not_equal");
}
    return !ListCoupledLabelledDomain_equal(a, b);
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_intersection(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(*result);
}

StringHandle      ListCoupledLabelledDomain_to_json_string(ListCoupledLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListCoupledLabelledDomain_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>::from_json_string<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(*ptr);
}
