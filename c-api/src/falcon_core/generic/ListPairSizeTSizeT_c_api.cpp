#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairSizeTSizeT_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>(
        falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>());
}

ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value(size_t count, PairSizeTSizeTHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(static_cast<falcon_core::generic::Pair<size_t, size_t>*>(value), [](falcon_core::generic::Pair<size_t, size_t>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>(
        count, stored_obj);
}
 

ListPairSizeTSizeTHandle ListPairSizeTSizeT_create(PairSizeTSizeTHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairSizeTSizeT_create");
}
    std::vector<falcon_core::generic::PairSP<size_t, size_t>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(static_cast<falcon_core::generic::Pair<size_t, size_t>*>(data[i]), [](falcon_core::generic::Pair<size_t, size_t>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>(
        falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>(vec));
}

void ListPairSizeTSizeT_destroy(ListPairSizeTSizeTHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle);
}

size_t ListPairSizeTSizeT_size(ListPairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->size();
}

bool ListPairSizeTSizeT_empty(ListPairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->empty();
}

void ListPairSizeTSizeT_erase_at(ListPairSizeTSizeTHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->erase_at(idx);
}

void ListPairSizeTSizeT_clear(ListPairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->clear();
}

void ListPairSizeTSizeT_push_back(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(static_cast<falcon_core::generic::Pair<size_t, size_t>*>(value), [](falcon_core::generic::Pair<size_t, size_t>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->push_back(stored_obj);
}

bool ListPairSizeTSizeT_contains(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(static_cast<falcon_core::generic::Pair<size_t, size_t>*>(value), [](falcon_core::generic::Pair<size_t, size_t>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->contains(stored_obj);
}

size_t ListPairSizeTSizeT_index(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(static_cast<falcon_core::generic::Pair<size_t, size_t>*>(value), [](falcon_core::generic::Pair<size_t, size_t>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->index(stored_obj);
}

size_t ListPairSizeTSizeT_items(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairSizeTSizeT_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<size_t, size_t>(*list->items()[i]);
}
    return n;
}

PairSizeTSizeTHandle ListPairSizeTSizeT_at(ListPairSizeTSizeTHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<size_t, size_t>(*obj);
}

bool ListPairSizeTSizeT_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(b);
    return *listA == *listB;
}

bool ListPairSizeTSizeT_not_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_not_equal");
}
    return !ListPairSizeTSizeT_equal(a, b);
}

ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>(*result);
}

StringHandle      ListPairSizeTSizeT_to_json_string(ListPairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairSizeTSizeTHandle ListPairSizeTSizeT_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairSizeTSizeT_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>(*ptr);
}
