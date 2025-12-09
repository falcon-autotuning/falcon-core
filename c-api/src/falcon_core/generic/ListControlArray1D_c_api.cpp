#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListControlArray1D_c_api.h"
#include <falcon_core/math/arrays/ControlArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListControlArray1DHandle ListControlArray1D_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>());
    FALCON_C_API_END(nullptr)
}

ListControlArray1DHandle ListControlArray1D_fill_value(size_t count, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListControlArray1DHandle ListControlArray1D_create(ControlArray1DHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListControlArray1D_create");
}
    std::vector<falcon_core::math::arrays::ControlArray1DSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListControlArray1D_destroy(ListControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListControlArray1D_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    FALCON_C_API_END()
}

size_t ListControlArray1D_size(ListControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListControlArray1D_empty(ListControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListControlArray1D_erase_at(ListControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListControlArray1D_clear(ListControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListControlArray1D_push_back(ListControlArray1DHandle handle, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListControlArray1D_contains(ListControlArray1DHandle handle, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListControlArray1D_index(ListControlArray1DHandle handle, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListControlArray1D_items(ListControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListControlArray1D_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ControlArray1DHandle ListControlArray1D_at(ListControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(obj);
    FALCON_C_API_END(nullptr)
}

bool ListControlArray1D_equal(ListControlArray1DHandle handle, ListControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListControlArray1D_not_equal(ListControlArray1DHandle handle, ListControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListControlArray1DHandle ListControlArray1D_intersection(ListControlArray1DHandle handle, ListControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListControlArray1D_to_json_string(ListControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListControlArray1DHandle ListControlArray1D_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListControlArray1D_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>(ptr);
    FALCON_C_API_END(nullptr)
}
}
