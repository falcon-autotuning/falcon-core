#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairIntFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairIntFloatHandle ListPairIntFloat_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, float>>());
}

ListPairIntFloatHandle ListPairIntFloat_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(count));
}

void ListPairIntFloat_destroy(ListPairIntFloatHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle);
}

size_t ListPairIntFloat_size(ListPairIntFloatHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->size();
}

bool ListPairIntFloat_empty(ListPairIntFloatHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->empty();
}

void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->erase_at(idx);
}

void ListPairIntFloat_clear(ListPairIntFloatHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->clear();
}

bool ListPairIntFloat_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(b);
    return *listA == *listB;
}

bool ListPairIntFloat_not_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b) {
    return !ListPairIntFloat_equal(a, b);
}

ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(*result);
}

ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, float>>(static_cast<falcon_core::generic::Pair<int, float>*>(value), [](falcon_core::generic::Pair<int, float>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(count, stored_obj));
}

ListPairIntFloatHandle ListPairIntFloat_create(const PairIntFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<int, float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<int, float>>(static_cast<falcon_core::generic::Pair<int, float>*>(data[i]), [](falcon_core::generic::Pair<int, float>*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(vec));
}

void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, float>>(static_cast<falcon_core::generic::Pair<int, float>*>(value), [](falcon_core::generic::Pair<int, float>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->push_back(stored_obj);
}

PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<int, float>(*obj);
}

size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::Pair<int, float>(*list->items()[i]);
    }
    return n;
}

bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, float>>(static_cast<falcon_core::generic::Pair<int, float>*>(value), [](falcon_core::generic::Pair<int, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->contains(stored_obj);
}

size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<int, float>>(static_cast<falcon_core::generic::Pair<int, float>*>(value), [](falcon_core::generic::Pair<int, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->index(stored_obj);
}

const char*      ListPairIntFloat_to_json_string(ListPairIntFloatHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>*>(handle)->to_json_string();
  return json.c_str();
}
ListPairIntFloatHandle ListPairIntFloat_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<int, float>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>>(std::string(json));
  return new falcon_core::generic::List<falcon_core::generic::Pair<int, float>>(*ptr);
}
