#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>());
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        count, stored_obj);
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(count));
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairConnectionDouble_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(vec));
}

void ListPairConnectionDouble_destroy(ListPairConnectionDoubleHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
}

size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->size();
}

bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->empty();
}

void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->erase_at(idx);
}

void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->clear();
}

void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->push_back(stored_obj);
}

bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->index(stored_obj);
}

size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionDouble_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>(*list->items()[i]);
}
    return n;
}

PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>(*obj);
}

bool ListPairConnectionDouble_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionDouble_not_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_not_equal");
}
    return !ListPairConnectionDouble_equal(a, b);
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(*result);
}

StringHandle      ListPairConnectionDouble_to_json_string(ListPairConnectionDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairConnectionDouble_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(*ptr);
}
