#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

ListPairConnectionQuantityHandle ListPairConnectionQuantity_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>());
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(count));
}

void ListPairConnectionQuantity_destroy(ListPairConnectionQuantityHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
}

size_t ListPairConnectionQuantity_size(ListPairConnectionQuantityHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->size();
}

bool ListPairConnectionQuantity_empty(ListPairConnectionQuantityHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->empty();
}

void ListPairConnectionQuantity_erase_at(ListPairConnectionQuantityHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->erase_at(idx);
}

void ListPairConnectionQuantity_clear(ListPairConnectionQuantityHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->clear();
}

bool ListPairConnectionQuantity_equal(ListPairConnectionQuantityHandle a, ListPairConnectionQuantityHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionQuantity_not_equal(ListPairConnectionQuantityHandle a, ListPairConnectionQuantityHandle b) {
    return !ListPairConnectionQuantity_equal(a, b);
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_intersection(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(*result);
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_fill_value(size_t count, PairConnectionQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(count, stored_obj));
}

ListPairConnectionQuantityHandle ListPairConnectionQuantity_create(const PairConnectionQuantityHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(vec));
}

void ListPairConnectionQuantity_push_back(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->push_back(stored_obj);
}

PairConnectionQuantityHandle ListPairConnectionQuantity_at(ListPairConnectionQuantityHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(*obj);
}

size_t ListPairConnectionQuantity_items(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(*list->items()[i]);
    }
    return n;
}

bool ListPairConnectionQuantity_contains(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionQuantity_index(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->index(stored_obj);
}

const char*      ListPairConnectionQuantity_to_json_string(ListPairConnectionQuantityHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>*>(handle)->to_json_string();
  return json.c_str();
}
ListPairConnectionQuantityHandle ListPairConnectionQuantity_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>>(std::string(json));
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>(*ptr);
}
