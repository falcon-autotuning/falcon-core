#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include <falcon_core/math/arrays/LabelledControlArray.hpp>

ListLabelledControlArrayHandle ListLabelledControlArray_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>());
}

ListLabelledControlArrayHandle ListLabelledControlArray_fill_value(size_t count, LabelledControlArrayHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(
        count, stored_obj);
}
 

ListLabelledControlArrayHandle ListLabelledControlArray_create(LabelledControlArrayHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListLabelledControlArray_create");
}
    std::vector<falcon_core::math::arrays::LabelledControlArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(data[i]), [](falcon_core::math::arrays::LabelledControlArray*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(vec));
}

void ListLabelledControlArray_destroy(ListLabelledControlArrayHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListLabelledControlArray_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle);
}

size_t ListLabelledControlArray_size(ListLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->size();
}

bool ListLabelledControlArray_empty(ListLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->empty();
}

void ListLabelledControlArray_erase_at(ListLabelledControlArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->erase_at(idx);
}

void ListLabelledControlArray_clear(ListLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->clear();
}

void ListLabelledControlArray_push_back(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->push_back(stored_obj);
}

bool ListLabelledControlArray_contains(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->contains(stored_obj);
}

size_t ListLabelledControlArray_index(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListLabelledControlArray_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->index(stored_obj);
}

size_t ListLabelledControlArray_items(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListLabelledControlArray_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledControlArray(*list->items()[i]);
}
    return n;
}

LabelledControlArrayHandle ListLabelledControlArray_at(ListLabelledControlArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray(*obj);
}

bool ListLabelledControlArray_equal(ListLabelledControlArrayHandle a, ListLabelledControlArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(b);
    return *listA == *listB;
}

bool ListLabelledControlArray_not_equal(ListLabelledControlArrayHandle a, ListLabelledControlArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_not_equal");
}
    return !ListLabelledControlArray_equal(a, b);
}

ListLabelledControlArrayHandle ListLabelledControlArray_intersection(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(*result);
}

StringHandle      ListLabelledControlArray_to_json_string(ListLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListLabelledControlArray_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListLabelledControlArrayHandle ListLabelledControlArray_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListLabelledControlArray_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(*ptr);
}
