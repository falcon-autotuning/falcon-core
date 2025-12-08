#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairConnectionQuantityHandle ListPairConnectionQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>>());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_fill_value(size_t count, PairConnectionQuantityHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairConnectionQuantityHandle ListPairConnectionQuantity_create(PairConnectionQuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairConnectionQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairConnectionQuantity_destroy(ListPairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairConnectionQuantity_size(ListPairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairConnectionQuantity_empty(ListPairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairConnectionQuantity_erase_at(ListPairConnectionQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairConnectionQuantity_clear(ListPairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairConnectionQuantity_push_back(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairConnectionQuantity_contains(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairConnectionQuantity_index(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairConnectionQuantity_items(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionQuantity_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairConnectionQuantityHandle ListPairConnectionQuantity_at(ListPairConnectionQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairConnectionQuantity_equal(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairConnectionQuantity_not_equal(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_intersection(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairConnectionQuantity_to_json_string(ListPairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionQuantity_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairConnectionQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
