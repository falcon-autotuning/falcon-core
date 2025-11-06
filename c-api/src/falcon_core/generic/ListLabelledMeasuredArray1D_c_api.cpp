#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"
#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>

ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>());
}

ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_fill_value(size_t count, LabelledMeasuredArray1DHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(
        count, stored_obj);
}
 

ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create(LabelledMeasuredArray1DHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledMeasuredArray1D_create");
}
    std::vector<falcon_core::math::arrays::LabelledMeasuredArray1DSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(data[i]), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(vec));
}

void ListLabelledMeasuredArray1D_destroy(ListLabelledMeasuredArray1DHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
}

size_t ListLabelledMeasuredArray1D_size(ListLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->size();
}

bool ListLabelledMeasuredArray1D_empty(ListLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->empty();
}

void ListLabelledMeasuredArray1D_erase_at(ListLabelledMeasuredArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->erase_at(idx);
}

void ListLabelledMeasuredArray1D_clear(ListLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->clear();
}

void ListLabelledMeasuredArray1D_push_back(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->push_back(stored_obj);
}

bool ListLabelledMeasuredArray1D_contains(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->contains(stored_obj);
}

size_t ListLabelledMeasuredArray1D_index(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->index(stored_obj);
}

size_t ListLabelledMeasuredArray1D_items(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledMeasuredArray1D_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledMeasuredArray1D(*list->items()[i]);
}
    return n;
}

LabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_at(ListLabelledMeasuredArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray1D(*obj);
}

bool ListLabelledMeasuredArray1D_equal(ListLabelledMeasuredArray1DHandle a, ListLabelledMeasuredArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(b);
    return *listA == *listB;
}

bool ListLabelledMeasuredArray1D_not_equal(ListLabelledMeasuredArray1DHandle a, ListLabelledMeasuredArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_not_equal");
}
    return !ListLabelledMeasuredArray1D_equal(a, b);
}

ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_intersection(ListLabelledMeasuredArray1DHandle handle, ListLabelledMeasuredArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(*result);
}

StringHandle      ListLabelledMeasuredArray1D_to_json_string(ListLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListLabelledMeasuredArray1D_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(*ptr);
}
