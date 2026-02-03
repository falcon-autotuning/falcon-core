#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListLabelledControlArray1D_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListLabelledControlArray1DHandle= falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>;
DEFINE_C_API_COPY_TEMPLATE(ListLabelledControlArray1D, MACROListLabelledControlArray1DHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListLabelledControlArray1D, MACROListLabelledControlArray1DHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListLabelledControlArray1D, MACROListLabelledControlArray1DHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListLabelledControlArray1D, MACROListLabelledControlArray1DHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListLabelledControlArray1D, MACROListLabelledControlArray1DHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListLabelledControlArray1D, MACROListLabelledControlArray1DHandle);
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>());
    FALCON_C_API_END(nullptr)
}

ListLabelledControlArray1DHandle ListLabelledControlArray1D_fill_value(size_t count, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListLabelledControlArray1DHandle ListLabelledControlArray1D_create(LabelledControlArray1DHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledControlArray1D_create");
}
    std::vector<falcon_core::math::arrays::LabelledControlArray1DSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListLabelledControlArray1D_size(ListLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListLabelledControlArray1D_empty(ListLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListLabelledControlArray1D_erase_at(ListLabelledControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListLabelledControlArray1D_clear(ListLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListLabelledControlArray1D_push_back(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListLabelledControlArray1D_contains(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListLabelledControlArray1D_index(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray1D_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListLabelledControlArray1D_items(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledControlArray1D_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledControlArray1DHandle ListLabelledControlArray1D_at(ListLabelledControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(obj);
    FALCON_C_API_END(nullptr)
}

ListLabelledControlArray1DHandle ListLabelledControlArray1D_intersection(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray1D_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>(result);
    FALCON_C_API_END(nullptr)
}
}
