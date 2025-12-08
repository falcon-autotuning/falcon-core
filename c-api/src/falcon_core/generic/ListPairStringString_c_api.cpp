#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringString_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairStringStringHandle ListPairStringString_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>>());
    FALCON_C_API_END(nullptr)
}

ListPairStringStringHandle ListPairStringString_fill_value(size_t count, PairStringStringHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringString_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<std::string, std::string>SP*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairStringStringHandle ListPairStringString_create(PairStringStringHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairStringString_create");
}
    std::vector<falcon_core::generic::PairSP<std::string, std::string>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::Pair<std::string, std::string>SP*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairStringString_destroy(ListPairStringStringHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairStringString_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairStringString_size(ListPairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairStringString_empty(ListPairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairStringString_erase_at(ListPairStringStringHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairStringString_clear(ListPairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairStringString_push_back(ListPairStringStringHandle handle, PairStringStringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringString_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<std::string, std::string>SP*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairStringString_contains(ListPairStringStringHandle handle, PairStringStringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringString_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<std::string, std::string>SP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairStringString_index(ListPairStringStringHandle handle, PairStringStringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringString_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<std::string, std::string>SP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairStringString_items(ListPairStringStringHandle handle, PairStringStringHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairStringString_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<std::string, std::string>SP(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairStringStringHandle ListPairStringString_at(ListPairStringStringHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<std::string, std::string>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairStringString_equal(ListPairStringStringHandle handle, ListPairStringStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringString_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairStringString_not_equal(ListPairStringStringHandle handle, ListPairStringStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringString_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairStringStringHandle ListPairStringString_intersection(ListPairStringStringHandle handle, ListPairStringStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringString_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairStringString_to_json_string(ListPairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringString_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairStringStringHandle ListPairStringString_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairStringString_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, std::string>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
