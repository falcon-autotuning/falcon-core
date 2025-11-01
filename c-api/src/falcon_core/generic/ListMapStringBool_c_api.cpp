#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListMapStringBool_c_api.h"
#include <falcon_core/generic/Map.hpp>

ListMapStringBoolHandle ListMapStringBool_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>());
}

ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(count, stored_obj));
}

ListMapStringBoolHandle ListMapStringBool_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(count));
}

ListMapStringBoolHandle ListMapStringBool_create(MapStringBoolHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListMapStringBool_create");
}
    std::vector<falcon_core::generic::MapSP<std::string, bool>> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListMapStringBool_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(data[i]), [](falcon_core::generic::Map<std::string, bool>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(vec));
}

void ListMapStringBool_destroy(ListMapStringBoolHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListMapStringBool_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle);
}

size_t ListMapStringBool_size(ListMapStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->size();
}

bool ListMapStringBool_empty(ListMapStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->empty();
}

void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->erase_at(idx);
}

void ListMapStringBool_clear(ListMapStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->clear();
}

void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->push_back(stored_obj);
}

bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->contains(stored_obj);
}

size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->index(stored_obj);
}

size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListMapStringBool_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Map<std::string, bool>(*list->items()[i]);
}
    return n;
}

MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->at(idx);
    return new falcon_core::generic::Map<std::string, bool>(*obj);
}

bool ListMapStringBool_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(b);
    return *listA == *listB;
}

bool ListMapStringBool_not_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_not_equal");
}
    return !ListMapStringBool_equal(a, b);
}

ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(*result);
}

StringHandle      ListMapStringBool_to_json_string(ListMapStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListMapStringBoolHandle ListMapStringBool_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListMapStringBool_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(*ptr);
}
