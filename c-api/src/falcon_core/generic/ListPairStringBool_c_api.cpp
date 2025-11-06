#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringBool_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairStringBoolHandle ListPairStringBool_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>());
}

ListPairStringBoolHandle ListPairStringBool_fill_value(size_t count, PairStringBoolHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        count, stored_obj);
}
 

ListPairStringBoolHandle ListPairStringBool_create(PairStringBoolHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairStringBool_create");
}
    std::vector<falcon_core::generic::PairSP<std::string, bool>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(data[i]), [](falcon_core::generic::Pair<std::string, bool>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(vec));
}

void ListPairStringBool_destroy(ListPairStringBoolHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairStringBool_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle);
}

size_t ListPairStringBool_size(ListPairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->size();
}

bool ListPairStringBool_empty(ListPairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->empty();
}

void ListPairStringBool_erase_at(ListPairStringBoolHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->erase_at(idx);
}

void ListPairStringBool_clear(ListPairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->clear();
}

void ListPairStringBool_push_back(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->push_back(stored_obj);
}

bool ListPairStringBool_contains(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->contains(stored_obj);
}

size_t ListPairStringBool_index(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->index(stored_obj);
}

size_t ListPairStringBool_items(ListPairStringBoolHandle handle, PairStringBoolHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairStringBool_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<std::string, bool>(*list->items()[i]);
}
    return n;
}

PairStringBoolHandle ListPairStringBool_at(ListPairStringBoolHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<std::string, bool>(*obj);
}

bool ListPairStringBool_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(b);
    return *listA == *listB;
}

bool ListPairStringBool_not_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_not_equal");
}
    return !ListPairStringBool_equal(a, b);
}

ListPairStringBoolHandle ListPairStringBool_intersection(ListPairStringBoolHandle handle, ListPairStringBoolHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(*result);
}

StringHandle      ListPairStringBool_to_json_string(ListPairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringBool_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairStringBoolHandle ListPairStringBool_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairStringBool_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(*ptr);
}
