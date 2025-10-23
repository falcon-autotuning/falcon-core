#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>());
}

ListPairConnectionFloatHandle ListPairConnectionFloat_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(count));
}

void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle);
}

size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->size();
}

bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->empty();
}

void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->erase_at(idx);
}

void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->clear();
}

bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b) {
    return !ListPairConnectionFloat_equal(a, b);
}

ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(*result);
}

ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(count, stored_obj));
}

ListPairConnectionFloatHandle ListPairConnectionFloat_create(const PairConnectionFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(vec));
}

void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->push_back(stored_obj);
}

PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>(*obj);
}

size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>(*list->items()[i]);
    }
    return n;
}

bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>*>(handle)->index(stored_obj);
}
