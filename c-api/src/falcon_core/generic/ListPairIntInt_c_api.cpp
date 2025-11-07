#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairIntInt_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairIntIntHandle ListPairIntInt_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>();
}

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<int, int>>(*static_cast<falcon_core::generic::Pair<int, int>*>(value));
    
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(
        count, stored_obj);
}
 

ListPairIntIntHandle ListPairIntInt_create(PairIntIntHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairIntInt_create");
}
    std::vector<falcon_core::generic::PairSP<int, int>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<int, int>>(*static_cast<falcon_core::generic::Pair<int, int>*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(vec);
}

void ListPairIntInt_destroy(ListPairIntIntHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairIntInt_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle);
}

size_t ListPairIntInt_size(ListPairIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->size();
}

bool ListPairIntInt_empty(ListPairIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->empty();
}

void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->erase_at(idx);
}

void ListPairIntInt_clear(ListPairIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->clear();
}

void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<int, int>>(*static_cast<falcon_core::generic::Pair<int, int>*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->push_back(stored_obj);
}

bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<int, int>>(*static_cast<falcon_core::generic::Pair<int, int>*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->contains(stored_obj);
}

size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<int, int>>(*static_cast<falcon_core::generic::Pair<int, int>*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->index(stored_obj);
}

size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairIntInt_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<int, int>(*list->items()[i]);
}
    return n;
}

PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<int, int>(*obj);
}

bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(b);
    return *listA == *listB;
}

bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_not_equal");
}
    return !ListPairIntInt_equal(a, b);
}

ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(*result);
}

StringHandle      ListPairIntInt_to_json_string(ListPairIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairIntIntHandle ListPairIntInt_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairIntInt_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<int, int>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<int, int>>(*ptr);
}
