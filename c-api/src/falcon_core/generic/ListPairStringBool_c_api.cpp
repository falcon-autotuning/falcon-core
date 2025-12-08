#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringBool_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairStringBoolHandle ListPairStringBool_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>());
    FALCON_C_API_END(nullptr)
}

ListPairStringBoolHandle ListPairStringBool_fill_value(size_t count, PairStringBoolHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairStringBoolHandle ListPairStringBool_create(PairStringBoolHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairStringBool_create");
}
    std::vector<falcon_core::generic::PairSP<std::string, bool>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairStringBool_destroy(ListPairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairStringBool_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairStringBool_size(ListPairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairStringBool_empty(ListPairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairStringBool_erase_at(ListPairStringBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairStringBool_clear(ListPairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairStringBool_push_back(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairStringBool_contains(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairStringBool_index(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairStringBool_items(ListPairStringBoolHandle handle, PairStringBoolHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairStringBool_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairStringBoolHandle ListPairStringBool_at(ListPairStringBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<std::string, bool>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairStringBool_equal(ListPairStringBoolHandle handle, ListPairStringBoolHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairStringBool_not_equal(ListPairStringBoolHandle handle, ListPairStringBoolHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairStringBoolHandle ListPairStringBool_intersection(ListPairStringBoolHandle handle, ListPairStringBoolHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairStringBool_to_json_string(ListPairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairStringBoolHandle ListPairStringBool_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairStringBool_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string, bool>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
