#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairFloatFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairFloatFloatHandle ListPairFloatFloat_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>());
}

ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(count, stored_obj));
}

ListPairFloatFloatHandle ListPairFloatFloat_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(count));
}

ListPairFloatFloatHandle ListPairFloatFloat_create(PairFloatFloatHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairFloatFloat_create");
}
    std::vector<falcon_core::generic::PairSP<float, float>> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListPairFloatFloat_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(data[i]), [](falcon_core::generic::Pair<float, float>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(
        falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(vec));
}

void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairFloatFloat_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle);
}

size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->size();
}

bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->empty();
}

void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->erase_at(idx);
}

void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->clear();
}

void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->push_back(stored_obj);
}

bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->contains(stored_obj);
}

size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<float, float>>(static_cast<falcon_core::generic::Pair<float, float>*>(value), [](falcon_core::generic::Pair<float, float>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->index(stored_obj);
}

size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairFloatFloat_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<float, float>(*list->items()[i]);
}
    return n;
}

PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<float, float>(*obj);
}

bool ListPairFloatFloat_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(b);
    return *listA == *listB;
}

bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_not_equal");
}
    return !ListPairFloatFloat_equal(a, b);
}

ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(*result);
}

StringHandle      ListPairFloatFloat_to_json_string(ListPairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairFloatFloatHandle ListPairFloatFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairFloatFloat_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<float, float>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<float, float>>(*ptr);
}
