#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairIntInt_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairIntIntHandle ListPairIntInt_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>());
    FALCON_C_API_END(nullptr)
}

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairIntIntHandle ListPairIntInt_create(PairIntIntHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairIntInt_create");
}
    std::vector<falcon_core::generic::PairSP<int, int>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairIntInt_destroy(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairIntInt_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairIntInt_size(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairIntInt_empty(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairIntInt_clear(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairIntInt_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<int, int>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<int, int>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairIntInt_equal(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairIntInt_not_equal(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairIntInt_to_json_string(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairIntIntHandle ListPairIntInt_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairIntInt_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<int, int>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
