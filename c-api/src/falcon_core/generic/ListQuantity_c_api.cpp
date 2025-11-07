#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListQuantity_c_api.h"
#include <falcon_core/math/Quantity.hpp>

ListQuantityHandle ListQuantity_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::Quantity>();
}

ListQuantityHandle ListQuantity_fill_value(size_t count, QuantityHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(value));
    
    return new falcon_core::generic::List<falcon_core::math::Quantity>(
        count, stored_obj);
}
 

ListQuantityHandle ListQuantity_create(QuantityHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListQuantity_create");
}
    std::vector<falcon_core::math::QuantitySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::math::Quantity>(vec);
}

void ListQuantity_destroy(ListQuantityHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListQuantity_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle);
}

size_t ListQuantity_size(ListQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->size();
}

bool ListQuantity_empty(ListQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->empty();
}

void ListQuantity_erase_at(ListQuantityHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->erase_at(idx);
}

void ListQuantity_clear(ListQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->clear();
}

void ListQuantity_push_back(ListQuantityHandle handle, QuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->push_back(stored_obj);
}

bool ListQuantity_contains(ListQuantityHandle handle, QuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->contains(stored_obj);
}

size_t ListQuantity_index(ListQuantityHandle handle, QuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->index(stored_obj);
}

size_t ListQuantity_items(ListQuantityHandle handle, QuantityHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListQuantity_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::Quantity(*list->items()[i]);
}
    return n;
}

QuantityHandle ListQuantity_at(ListQuantityHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->at(idx);
    return new falcon_core::math::Quantity(*obj);
}

bool ListQuantity_equal(ListQuantityHandle a, ListQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListQuantity_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(b);
    return *listA == *listB;
}

bool ListQuantity_not_equal(ListQuantityHandle a, ListQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListQuantity_not_equal");
}
    return !ListQuantity_equal(a, b);
}

ListQuantityHandle ListQuantity_intersection(ListQuantityHandle handle, ListQuantityHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListQuantity_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::Quantity>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::Quantity>(*result);
}

StringHandle      ListQuantity_to_json_string(ListQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::Quantity>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListQuantityHandle ListQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::Quantity>::from_json_string<falcon_core::generic::List<falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::Quantity>(*ptr);
}
