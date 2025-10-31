#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>());
}

ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(count, stored_obj));
}

ListPairConnectionFloatHandle ListPairConnectionFloat_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(count));
}

ListPairConnectionFloatHandle ListPairConnectionFloat_create(PairConnectionFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListPairConnectionFloat_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(vec));
}

void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle);
}

size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->size();
}

bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->empty();
}

void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->erase_at(idx);
}

void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->clear();
}

void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->push_back(stored_obj);
}

bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->index(stored_obj);
}

size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionFloat_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>(*list->items()[i]);
}
    return n;
}

PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>(*obj);
}

bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_not_equal");
}
    return !ListPairConnectionFloat_equal(a, b);
}

ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(*result);
}

StringHandle      ListPairConnectionFloat_to_json_string(ListPairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionFloat_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairConnectionFloatHandle ListPairConnectionFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairConnectionFloat_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(*ptr);
}
