#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListString_c_api.h"

ListStringHandle ListString_create_empty() {
    return new falcon_core::generic::List<std::string>();
}

ListStringHandle ListString_fill_value(size_t count, StringHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    return new falcon_core::generic::List<std::string>(
        count, stored_obj);
}
 ListStringHandle ListString_allocate(size_t count) {
    return new falcon_core::generic::List<std::string>(count);
}


ListStringHandle ListString_create(StringHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListString_create");
}
    std::vector<std::string> vec;
    
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(data[i]->raw);
    }

    return new falcon_core::generic::List<std::string>(vec);
}

void ListString_destroy(ListStringHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListString_destroy");
    }
    delete static_cast<falcon_core::generic::List<std::string>*>(handle);
}

size_t ListString_size(ListStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_size");
}
    return static_cast<falcon_core::generic::List<std::string>*>(handle)->size();
}

bool ListString_empty(ListStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_empty");
}
    return static_cast<falcon_core::generic::List<std::string>*>(handle)->empty();
}

void ListString_erase_at(ListStringHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_erase_at");
}
    static_cast<falcon_core::generic::List<std::string>*>(handle)->erase_at(idx);
}

void ListString_clear(ListStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_clear");
}
    static_cast<falcon_core::generic::List<std::string>*>(handle)->clear();
}

void ListString_push_back(ListStringHandle handle, StringHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    static_cast<falcon_core::generic::List<std::string>*>(handle)->push_back(stored_obj);
}

bool ListString_contains(ListStringHandle handle, StringHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    return static_cast<falcon_core::generic::List<std::string>*>(handle)->contains(stored_obj);
}

size_t ListString_index(ListStringHandle handle, StringHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    return static_cast<falcon_core::generic::List<std::string>*>(handle)->index(stored_obj);
}

size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListString_items");
}
    auto list = static_cast<falcon_core::generic::List<std::string>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
    for (size_t i = 0; i < n; ++i) {
        auto str      = list->items()[i];
        out_buffer[i] = String_create(str.data(), str.size());
    }

    return n;
}

StringHandle ListString_at(ListStringHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_at");
}
    auto obj = static_cast<falcon_core::generic::List<std::string>*>(handle)->at(idx);
    return String_create(obj.data(), obj.size());
}

bool ListString_equal(ListStringHandle a, ListStringHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListString_equal");
}
    auto listA = static_cast<falcon_core::generic::List<std::string>*>(a);
    auto listB = static_cast<falcon_core::generic::List<std::string>*>(b);
    return *listA == *listB;
}

bool ListString_not_equal(ListStringHandle a, ListStringHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListString_not_equal");
}
    return !ListString_equal(a, b);
}

ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListString_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<std::string>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<std::string>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<std::string>>(*listB));
    return new falcon_core::generic::List<std::string>(*result);
}

StringHandle      ListString_to_json_string(ListStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<std::string>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListStringHandle ListString_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListString_from_json_string");
}
  auto ptr = falcon_core::generic::List<std::string>::from_json_string<falcon_core::generic::List<std::string>>(json->raw);
  return new falcon_core::generic::List<std::string>(*ptr);
}
