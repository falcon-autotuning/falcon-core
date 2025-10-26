#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>());
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value(size_t count, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(count, stored_obj));
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(count));
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create(LabelledMeasuredArrayHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::LabelledMeasuredArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(data[i]), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(vec));
}

void ListLabelledMeasuredArray_destroy(ListLabelledMeasuredArrayHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
}

size_t ListLabelledMeasuredArray_size(ListLabelledMeasuredArrayHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
}

bool ListLabelledMeasuredArray_empty(ListLabelledMeasuredArrayHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
}

void ListLabelledMeasuredArray_erase_at(ListLabelledMeasuredArrayHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
}

void ListLabelledMeasuredArray_clear(ListLabelledMeasuredArrayHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
}

void ListLabelledMeasuredArray_push_back(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
}

bool ListLabelledMeasuredArray_contains(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
}

size_t ListLabelledMeasuredArray_index(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
}

size_t ListLabelledMeasuredArray_items(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledMeasuredArray(*list->items()[i]);
}
    return n;
}

LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at(ListLabelledMeasuredArrayHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
}

bool ListLabelledMeasuredArray_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(b);
    return *listA == *listB;
}

bool ListLabelledMeasuredArray_not_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b) {
    return !ListLabelledMeasuredArray_equal(a, b);
}

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(*result);
}

StringHandle      ListLabelledMeasuredArray_to_json_string(ListLabelledMeasuredArrayHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
}
