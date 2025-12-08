#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListSizeT_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListSizeTHandle ListSizeT_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<size_t>(std::make_shared<falcon_core::generic::List<size_t>>());
    FALCON_C_API_END(nullptr)
}

ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value) {
    FALCON_C_API_BEGIN
    auto stored_obj = value;
    return new falcon_core::generic::ListSP<size_t>(
        std::make_shared<falcon_core::generic::List<size_t>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 ListSizeTHandle ListSizeT_allocate(size_t count) {
    return new falcon_core::generic::ListSP<size_t>(std::make_shared<falcon_core::generic::List<size_t>>(count));
}


ListSizeTHandle ListSizeT_create(size_t* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListSizeT_create");
}
    std::vector<size_t> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::ListSP<size_t>(
        std::make_shared<falcon_core::generic::List<size_t>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListSizeT_destroy(ListSizeTHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListSizeT_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<size_t>*>(handle);
    FALCON_C_API_END()
}

size_t ListSizeT_size(ListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_size");
}
    return (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListSizeT_empty(ListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListSizeT_erase_at(ListSizeTHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListSizeT_clear(ListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_clear");
}
    (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListSizeT_push_back(ListSizeTHandle handle, size_t value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_push_back");
}
    auto stored_obj = value;
    (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListSizeT_contains(ListSizeTHandle handle, size_t value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_contains");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListSizeT_index(ListSizeTHandle handle, size_t value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_index");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListSizeT_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<size_t>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
    FALCON_C_API_END(0)
}

size_t ListSizeT_at(ListSizeTHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->at(idx);
    return obj;
    FALCON_C_API_END(0)
}

bool ListSizeT_equal(ListSizeTHandle handle, ListSizeTHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListSizeT_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<size_t>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<size_t>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListSizeT_not_equal(ListSizeTHandle handle, ListSizeTHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListSizeT_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<size_t>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<size_t>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListSizeTHandle ListSizeT_intersection(ListSizeTHandle handle, ListSizeTHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListSizeT_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<size_t>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<size_t>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<size_t>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListSizeT_to_json_string(ListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListSizeT_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<size_t>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListSizeTHandle ListSizeT_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListSizeT_from_json_string");
}
  auto ptr = falcon_core::generic::List<size_t>::from_json_string<falcon_core::generic::List<size_t>>(json->raw);
  return new falcon_core::generic::ListSP<size_t>(ptr);
    FALCON_C_API_END(nullptr)
}
}
