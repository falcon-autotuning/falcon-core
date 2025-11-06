#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListListSizeT_c_api.h"

ListListSizeTHandle ListListSizeT_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        falcon_core::generic::List<falcon_core::generic::List<size_t>>());
}

ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        count, stored_obj);
}
 

ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListListSizeT_create");
}
    std::vector<falcon_core::generic::ListSP<size_t>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(data[i]), [](falcon_core::generic::List<size_t>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        falcon_core::generic::List<falcon_core::generic::List<size_t>>(vec));
}

void ListListSizeT_destroy(ListListSizeTHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListListSizeT_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle);
}

size_t ListListSizeT_size(ListListSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->size();
}

bool ListListSizeT_empty(ListListSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->empty();
}

void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->erase_at(idx);
}

void ListListSizeT_clear(ListListSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->clear();
}

void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->push_back(stored_obj);
}

bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->contains(stored_obj);
}

size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->index(stored_obj);
}

size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListListSizeT_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::List<size_t>(*list->items()[i]);
}
    return n;
}

ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->at(idx);
    return new falcon_core::generic::List<size_t>(*obj);
}

bool ListListSizeT_equal(ListListSizeTHandle a, ListListSizeTHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListListSizeT_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(b);
    return *listA == *listB;
}

bool ListListSizeT_not_equal(ListListSizeTHandle a, ListListSizeTHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListListSizeT_not_equal");
}
    return !ListListSizeT_equal(a, b);
}

ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListListSizeT_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::List<size_t>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*result);
}

StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListListSizeT_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::List<size_t>>::from_json_string<falcon_core::generic::List<falcon_core::generic::List<size_t>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*ptr);
}
