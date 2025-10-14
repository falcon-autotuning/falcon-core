#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairIntInt_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairIntIntHandle ListPairIntInt_create_empty() {
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>());
}

ListPairIntIntHandle ListPairIntInt_allocate(size_t count) {
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(count));
}

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(count, stored_obj));
}

ListPairIntIntHandle ListPairIntInt_create(const PairIntIntHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<int, int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<int, int>*>(data[i]));
    }
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(vec));
}

void ListPairIntInt_destroy(ListPairIntIntHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle);
}

void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->push_back(stored_obj);
}

size_t ListPairIntInt_size(ListPairIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->size();
}

bool ListPairIntInt_empty(ListPairIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->empty();
}

void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->erase_at(idx);
}

void ListPairIntInt_clear(ListPairIntIntHandle handle) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->clear();
}

PairIntIntHandle ListPairIntInt_const_at(ListPairIntIntHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<int, int>(obj);
}

PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<int, int>(obj);
}

size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::PairSP<int, int>(list->items()[i]);
    }
    return n;
}

bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->contains(stored_obj);
}

size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle))->index(stored_obj);
}

ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(result);
}

bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>*>(b);
    return *listA == *listB;
}

bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
    return !ListPairIntInt_equal(a, b);
}
