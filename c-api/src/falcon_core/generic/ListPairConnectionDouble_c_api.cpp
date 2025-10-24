#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>());
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(count));
}

void ListPairConnectionDouble_destroy(ListPairConnectionDoubleHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
}

size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->size();
}

bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->empty();
}

void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->erase_at(idx);
}

void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->clear();
}

bool ListPairConnectionDouble_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionDouble_not_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b) {
    return !ListPairConnectionDouble_equal(a, b);
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(*result);
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(count, stored_obj));
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_create(const PairConnectionDoubleHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(vec));
}

void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->push_back(stored_obj);
}

PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>(*obj);
}

size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>(*list->items()[i]);
    }
    return n;
}

bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->index(stored_obj);
}

const char*      ListPairConnectionDouble_to_json_string(ListPairConnectionDoubleHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->to_json_string();
  return json.c_str();
}
ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>(std::string(json));
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(*ptr);
}
