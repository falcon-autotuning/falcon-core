#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include <falcon_core/math/arrays/LabelledControlArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListLabelledControlArrayHandle ListLabelledControlArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>());
    FALCON_C_API_END(nullptr)
}

ListLabelledControlArrayHandle ListLabelledControlArray_fill_value(size_t count, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListLabelledControlArrayHandle ListLabelledControlArray_create(LabelledControlArrayHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledControlArray_create");
}
    std::vector<falcon_core::math::arrays::LabelledControlArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListLabelledControlArray_destroy(ListLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListLabelledControlArray_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    FALCON_C_API_END()
}

size_t ListLabelledControlArray_size(ListLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListLabelledControlArray_empty(ListLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListLabelledControlArray_erase_at(ListLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListLabelledControlArray_clear(ListLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListLabelledControlArray_push_back(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListLabelledControlArray_contains(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListLabelledControlArray_index(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListLabelledControlArray_items(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledControlArray_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledControlArrayHandle ListLabelledControlArray_at(ListLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(obj);
    FALCON_C_API_END(nullptr)
}

bool ListLabelledControlArray_equal(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListLabelledControlArray_not_equal(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListLabelledControlArrayHandle ListLabelledControlArray_intersection(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListLabelledControlArray_to_json_string(ListLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListLabelledControlArrayHandle ListLabelledControlArray_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListLabelledControlArray_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>(ptr);
    FALCON_C_API_END(nullptr)
}
}
