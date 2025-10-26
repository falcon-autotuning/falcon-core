#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListMapStringBool_c_api.h"
#include <falcon_core/generic/Map.hpp>

ListMapStringBoolHandle ListMapStringBool_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>());
}

ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(count, stored_obj));
}

ListMapStringBoolHandle ListMapStringBool_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(count));
}

ListMapStringBoolHandle ListMapStringBool_create(MapStringBoolHandle* data, size_t count) {
    std::vector<falcon_core::generic::MapSP<std::string, bool>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(data[i]), [](falcon_core::generic::Map<std::string, bool>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(vec));
}

void ListMapStringBool_destroy(ListMapStringBoolHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle);
}

size_t ListMapStringBool_size(ListMapStringBoolHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->size();
}

bool ListMapStringBool_empty(ListMapStringBoolHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->empty();
}

void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->erase_at(idx);
}

void ListMapStringBool_clear(ListMapStringBoolHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->clear();
}

void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->push_back(stored_obj);
}

bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->contains(stored_obj);
}

size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->index(stored_obj);
}

size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Map<std::string, bool>(*list->items()[i]);
}
    return n;
}

MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->at(idx);
    return new falcon_core::generic::Map<std::string, bool>(*obj);
}

bool ListMapStringBool_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(b);
    return *listA == *listB;
}

bool ListMapStringBool_not_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b) {
    return !ListMapStringBool_equal(a, b);
}

ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(*result);
}

StringHandle      ListMapStringBool_to_json_string(ListMapStringBoolHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListMapStringBoolHandle ListMapStringBool_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>(*ptr);
}
