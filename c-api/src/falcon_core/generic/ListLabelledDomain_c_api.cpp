#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledDomain_c_api.h"
#include <falcon_core/math/domains/LabelledDomain.hpp>

ListLabelledDomainHandle ListLabelledDomain_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>());
}

ListLabelledDomainHandle ListLabelledDomain_fill_value(size_t count, LabelledDomainHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(count, stored_obj));
}

ListLabelledDomainHandle ListLabelledDomain_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(count));
}

ListLabelledDomainHandle ListLabelledDomain_create(LabelledDomainHandle* data, size_t count) {
    std::vector<falcon_core::math::domains::LabelledDomainSP> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListLabelledDomain_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(data[i]), [](falcon_core::math::domains::LabelledDomain*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(vec));
}

void ListLabelledDomain_destroy(ListLabelledDomainHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListLabelledDomain_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle);
}

size_t ListLabelledDomain_size(ListLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->size();
}

bool ListLabelledDomain_empty(ListLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->empty();
}

void ListLabelledDomain_erase_at(ListLabelledDomainHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->erase_at(idx);
}

void ListLabelledDomain_clear(ListLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->clear();
}

void ListLabelledDomain_push_back(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->push_back(stored_obj);
}

bool ListLabelledDomain_contains(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->contains(stored_obj);
}

size_t ListLabelledDomain_index(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledDomain_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->index(stored_obj);
}

size_t ListLabelledDomain_items(ListLabelledDomainHandle handle, LabelledDomainHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledDomain_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::domains::LabelledDomain(*list->items()[i]);
}
    return n;
}

LabelledDomainHandle ListLabelledDomain_at(ListLabelledDomainHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::LabelledDomain(*obj);
}

bool ListLabelledDomain_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(b);
    return *listA == *listB;
}

bool ListLabelledDomain_not_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_not_equal");
}
    return !ListLabelledDomain_equal(a, b);
}

ListLabelledDomainHandle ListLabelledDomain_intersection(ListLabelledDomainHandle handle, ListLabelledDomainHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(*result);
}

StringHandle      ListLabelledDomain_to_json_string(ListLabelledDomainHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledDomain_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListLabelledDomainHandle ListLabelledDomain_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListLabelledDomain_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>::from_json_string<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(*ptr);
}
