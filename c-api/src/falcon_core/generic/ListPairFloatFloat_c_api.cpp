#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairFloatFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairFloatFloatHandle ListPairFloatFloat_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>());
}

ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(count, stored_obj));
}

ListPairFloatFloatHandle ListPairFloatFloat_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(count));
}

ListPairFloatFloatHandle ListPairFloatFloat_create(const PairFloatFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<float, float>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(data[i]), [](falcon_core::generic::Pair<float, float>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(vec));
}

void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle);
}

size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->size();
}

bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->empty();
}

void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->erase_at(idx);
}

void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->clear();
}

void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->push_back(stored_obj);
}

bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->contains(stored_obj);
}

size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->index(stored_obj);
}

size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<float, float>(*list->items()[i]);
}
    return n;
}

PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<float, float>(*obj);
}

bool ListPairFloatFloat_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(b);
    return *listA == *listB;
}

bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b) {
    return !ListPairFloatFloat_equal(a, b);
}

ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(*result);
}

StringHandle      ListPairFloatFloat_to_json_string(ListPairFloatFloatHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairFloatFloatHandle ListPairFloatFloat_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<float, float>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(*ptr);
}
