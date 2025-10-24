#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListListSizeT_c_api.h"

ListListSizeTHandle ListListSizeT_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        falcon_core::generic::List<falcon_core::generic::List<size_t>>());
}

ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        falcon_core::generic::List<falcon_core::generic::List<size_t>>(count, stored_obj));
}

ListListSizeTHandle ListListSizeT_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        falcon_core::generic::List<falcon_core::generic::List<size_t>>(count));
}

ListListSizeTHandle ListListSizeT_create(const ListSizeTHandle* data, size_t count) {
    std::vector<falcon_core::generic::ListSP<size_t>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(data[i]), [](falcon_core::generic::List<size_t>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
        falcon_core::generic::List<falcon_core::generic::List<size_t>>(vec));
}

void ListListSizeT_destroy(ListListSizeTHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle);
}

size_t ListListSizeT_size(ListListSizeTHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->size();
}

bool ListListSizeT_empty(ListListSizeTHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->empty();
}

void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->erase_at(idx);
}

void ListListSizeT_clear(ListListSizeTHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->clear();
}

void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->push_back(stored_obj);
}

bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->contains(stored_obj);
}

size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::List<size_t>>(static_cast<falcon_core::generic::List<size_t>*>(value), [](falcon_core::generic::List<size_t>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->index(stored_obj);
}

size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::List<size_t>(*list->items()[i]);
}
    return n;
}

ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->at(idx);
    return new falcon_core::generic::List<size_t>(*obj);
}

bool ListListSizeT_equal(ListListSizeTHandle a, ListListSizeTHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(b);
    return *listA == *listB;
}

bool ListListSizeT_not_equal(ListListSizeTHandle a, ListListSizeTHandle b) {
    return !ListListSizeT_equal(a, b);
}

ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::List<size_t>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*result);
}

StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::List<size_t>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::List<size_t>>::from_json_string<falcon_core::generic::List<falcon_core::generic::List<size_t>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*ptr);
}
