#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <falcon_core/math/Quantity.hpp>

ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>());
}

ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_fill_value(size_t count, PairConnectionPairQuantityQuantityHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionPairQuantityQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(
        count, stored_obj);
}
 

ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_create(PairConnectionPairQuantityQuantityHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairConnectionPairQuantityQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(vec));
}

void ListPairConnectionPairQuantityQuantity_destroy(ListPairConnectionPairQuantityQuantityHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle);
}

size_t ListPairConnectionPairQuantityQuantity_size(ListPairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->size();
}

bool ListPairConnectionPairQuantityQuantity_empty(ListPairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->empty();
}

void ListPairConnectionPairQuantityQuantity_erase_at(ListPairConnectionPairQuantityQuantityHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->erase_at(idx);
}

void ListPairConnectionPairQuantityQuantity_clear(ListPairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->clear();
}

void ListPairConnectionPairQuantityQuantity_push_back(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionPairQuantityQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->push_back(stored_obj);
}

bool ListPairConnectionPairQuantityQuantity_contains(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionPairQuantityQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionPairQuantityQuantity_index(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionPairQuantityQuantity_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->index(stored_obj);
}

size_t ListPairConnectionPairQuantityQuantity_items(ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionPairQuantityQuantity_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(*list->items()[i]);
}
    return n;
}

PairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_at(ListPairConnectionPairQuantityQuantityHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(*obj);
}

bool ListPairConnectionPairQuantityQuantity_equal(ListPairConnectionPairQuantityQuantityHandle a, ListPairConnectionPairQuantityQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionPairQuantityQuantity_not_equal(ListPairConnectionPairQuantityQuantityHandle a, ListPairConnectionPairQuantityQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_not_equal");
}
    return !ListPairConnectionPairQuantityQuantity_equal(a, b);
}

ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_intersection(ListPairConnectionPairQuantityQuantityHandle handle, ListPairConnectionPairQuantityQuantityHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(*result);
}

StringHandle      ListPairConnectionPairQuantityQuantity_to_json_string(ListPairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionPairQuantityQuantity_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairConnectionPairQuantityQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(*ptr);
}
