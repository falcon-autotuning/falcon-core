#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListControlArray_c_api.h"
#include <falcon_core/math/arrays/ControlArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListControlArrayHandle ListControlArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>());
    FALCON_C_API_END(nullptr)
}

ListControlArrayHandle ListControlArray_fill_value(size_t count, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListControlArrayHandle ListControlArray_create(ControlArrayHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListControlArray_create");
}
    std::vector<falcon_core::math::arrays::ControlArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListControlArray_destroy(ListControlArrayHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListControlArray_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle);
    FALCON_C_API_END()
}

size_t ListControlArray_size(ListControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListControlArray_empty(ListControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListControlArray_erase_at(ListControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListControlArray_clear(ListControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListControlArray_push_back(ListControlArrayHandle handle, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListControlArray_contains(ListControlArrayHandle handle, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListControlArray_index(ListControlArrayHandle handle, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListControlArray_items(ListControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListControlArray_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::ControlArray>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ControlArrayHandle ListControlArray_at(ListControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::ControlArray>(obj);
    FALCON_C_API_END(nullptr)
}

bool ListControlArray_equal(ListControlArrayHandle handle, ListControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListControlArray_not_equal(ListControlArrayHandle handle, ListControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListControlArrayHandle ListControlArray_intersection(ListControlArrayHandle handle, ListControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListControlArray_to_json_string(ListControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListControlArrayHandle ListControlArray_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListControlArray_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::ControlArray>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray>(ptr);
    FALCON_C_API_END(nullptr)
}
}
