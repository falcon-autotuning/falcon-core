#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>();
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value(size_t count, LabelledMeasuredArrayHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(
        count, stored_obj);
}
 

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create(LabelledMeasuredArrayHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledMeasuredArray_create");
}
    std::vector<falcon_core::math::arrays::LabelledMeasuredArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(vec);
}

void ListLabelledMeasuredArray_destroy(ListLabelledMeasuredArrayHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
}

size_t ListLabelledMeasuredArray_size(ListLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
}

bool ListLabelledMeasuredArray_empty(ListLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
}

void ListLabelledMeasuredArray_erase_at(ListLabelledMeasuredArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
}

void ListLabelledMeasuredArray_clear(ListLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
}

void ListLabelledMeasuredArray_push_back(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
}

bool ListLabelledMeasuredArray_contains(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
}

size_t ListLabelledMeasuredArray_index(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledMeasuredArray_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
}

size_t ListLabelledMeasuredArray_items(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledMeasuredArray_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledMeasuredArray(*list->items()[i]);
}
    return n;
}

LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at(ListLabelledMeasuredArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
}

bool ListLabelledMeasuredArray_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(b);
    return *listA == *listB;
}

bool ListLabelledMeasuredArray_not_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_not_equal");
}
    return !ListLabelledMeasuredArray_equal(a, b);
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(*result);
}

StringHandle      ListLabelledMeasuredArray_to_json_string(ListLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledMeasuredArray_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListLabelledMeasuredArray_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
}
