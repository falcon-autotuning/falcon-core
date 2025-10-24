#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairIntInt_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairIntIntHandle ListPairIntInt_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, int>>());
}

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, int>>(static_cast<falcon_core::generic::Pair<int, int>*>(value), [](falcon_core::generic::Pair<int, int>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(count, stored_obj));
}

ListPairIntIntHandle ListPairIntInt_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(count));
}

ListPairIntIntHandle ListPairIntInt_create(const PairIntIntHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<int, int>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<int, int>>(static_cast<falcon_core::generic::Pair<int, int>*>(data[i]), [](falcon_core::generic::Pair<int, int>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(vec));
}

void ListPairIntInt_destroy(ListPairIntIntHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle);
}

size_t ListPairIntInt_size(ListPairIntIntHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->size();
}

bool ListPairIntInt_empty(ListPairIntIntHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->empty();
}

void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->erase_at(idx);
}

void ListPairIntInt_clear(ListPairIntIntHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->clear();
}

void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, int>>(static_cast<falcon_core::generic::Pair<int, int>*>(value), [](falcon_core::generic::Pair<int, int>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->push_back(stored_obj);
}

bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, int>>(static_cast<falcon_core::generic::Pair<int, int>*>(value), [](falcon_core::generic::Pair<int, int>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->contains(stored_obj);
}

size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, int>>(static_cast<falcon_core::generic::Pair<int, int>*>(value), [](falcon_core::generic::Pair<int, int>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->index(stored_obj);
}

size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<int, int>(*list->items()[i]);
}
    return n;
}

PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<int, int>(*obj);
}

bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(b);
    return *listA == *listB;
}

bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
    return !ListPairIntInt_equal(a, b);
}

ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(*result);
}

StringHandle      ListPairIntInt_to_json_string(ListPairIntIntHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairIntIntHandle ListPairIntInt_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<int, int>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(*ptr);
}
