#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"
#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>();
    FALCON_C_API_END(nullptr)
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_fill_value(size_t count, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(
        count, stored_obj);
    FALCON_C_API_END(nullptr)
}
 

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create(CoupledLabelledDomainHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListCoupledLabelledDomain_create");
}
    std::vector<falcon_core::math::domains::CoupledLabelledDomainSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(vec);
    FALCON_C_API_END(nullptr)
}

void ListCoupledLabelledDomain_destroy(ListCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    FALCON_C_API_END()
}

size_t ListCoupledLabelledDomain_size(ListCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool ListCoupledLabelledDomain_empty(ListCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void ListCoupledLabelledDomain_erase_at(ListCoupledLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void ListCoupledLabelledDomain_clear(ListCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->clear();
    FALCON_C_API_END()
}

void ListCoupledLabelledDomain_push_back(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListCoupledLabelledDomain_contains(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListCoupledLabelledDomain_index(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListCoupledLabelledDomain_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(*static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListCoupledLabelledDomain_items(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
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
    FALCON_C_API_END(0)
}

CoupledLabelledDomainHandle ListCoupledLabelledDomain_at(ListCoupledLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::CoupledLabelledDomain(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListCoupledLabelledDomain_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListCoupledLabelledDomain_not_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_not_equal");
}
    return !ListCoupledLabelledDomain_equal(a, b);
    FALCON_C_API_END(false)
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_intersection(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(*result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListCoupledLabelledDomain_to_json_string(ListCoupledLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListCoupledLabelledDomain_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListCoupledLabelledDomain_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>::from_json_string<falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::domains::CoupledLabelledDomain>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
