#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledDomain_c_api.h"
#include <falcon_core/math/domains/LabelledDomain.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListLabelledDomainHandle ListLabelledDomain_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>(std::make_shared<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>());
    FALCON_C_API_END(nullptr)
}

ListLabelledDomainHandle ListLabelledDomain_fill_value(size_t count, LabelledDomainHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::LabelledDomain>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListLabelledDomainHandle ListLabelledDomain_create(LabelledDomainHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledDomain_create");
}
    std::vector<falcon_core::math::domains::LabelledDomainSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::domains::LabelledDomain>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListLabelledDomain_destroy(ListLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListLabelledDomain_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle);
    FALCON_C_API_END()
}

size_t ListLabelledDomain_size(ListLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListLabelledDomain_empty(ListLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListLabelledDomain_erase_at(ListLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListLabelledDomain_clear(ListLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListLabelledDomain_push_back(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::LabelledDomain>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListLabelledDomain_contains(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::LabelledDomain>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListLabelledDomain_index(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::domains::LabelledDomain>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListLabelledDomain_items(ListLabelledDomainHandle handle, LabelledDomainHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledDomain_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::domains::LabelledDomain>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledDomainHandle ListLabelledDomain_at(ListLabelledDomainHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->at(idx);
    return new falcon_core::math::domains::LabelledDomain(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListLabelledDomain_equal(ListLabelledDomainHandle handle, ListLabelledDomainHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListLabelledDomain_not_equal(ListLabelledDomainHandle handle, ListLabelledDomainHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListLabelledDomainHandle ListLabelledDomain_intersection(ListLabelledDomainHandle handle, ListLabelledDomainHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListLabelledDomain_to_json_string(ListLabelledDomainHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListLabelledDomainHandle ListLabelledDomain_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListLabelledDomain_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>::from_json_string<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::math::domains::LabelledDomain>(ptr);
    FALCON_C_API_END(nullptr)
}
}
