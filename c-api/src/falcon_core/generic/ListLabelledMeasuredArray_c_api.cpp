#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListLabelledMeasuredArray_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListLabelledMeasuredArrayHandle= falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>;
DEFINE_C_API_COPY_TEMPLATE(ListLabelledMeasuredArray, MACROListLabelledMeasuredArrayHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListLabelledMeasuredArray, MACROListLabelledMeasuredArrayHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListLabelledMeasuredArray, MACROListLabelledMeasuredArrayHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListLabelledMeasuredArray, MACROListLabelledMeasuredArrayHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListLabelledMeasuredArray, MACROListLabelledMeasuredArrayHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListLabelledMeasuredArray, MACROListLabelledMeasuredArrayHandle);
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>());
    FALCON_C_API_END(nullptr)
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value(size_t count, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create(LabelledMeasuredArrayHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledMeasuredArray_create");
}
    std::vector<falcon_core::math::arrays::LabelledMeasuredArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListLabelledMeasuredArray_size(ListLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListLabelledMeasuredArray_empty(ListLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListLabelledMeasuredArray_erase_at(ListLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListLabelledMeasuredArray_clear(ListLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListLabelledMeasuredArray_push_back(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListLabelledMeasuredArray_contains(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListLabelledMeasuredArray_index(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListLabelledMeasuredArray_items(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledMeasuredArray_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at(ListLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(obj);
    FALCON_C_API_END(nullptr)
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>(result);
    FALCON_C_API_END(nullptr)
}
}
