#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"
#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>

ListLabelledControlArray1DHandle ListLabelledControlArray1D_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>());
}

ListLabelledControlArray1DHandle ListLabelledControlArray1D_fill_value(size_t count, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(count, stored_obj));
}

ListLabelledControlArray1DHandle ListLabelledControlArray1D_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(count));
}

ListLabelledControlArray1DHandle ListLabelledControlArray1D_create(LabelledControlArray1DHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::LabelledControlArray1DSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(data[i]), [](falcon_core::math::arrays::LabelledControlArray1D*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(vec));
}

void ListLabelledControlArray1D_destroy(ListLabelledControlArray1DHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
}

size_t ListLabelledControlArray1D_size(ListLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->size();
}

bool ListLabelledControlArray1D_empty(ListLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->empty();
}

void ListLabelledControlArray1D_erase_at(ListLabelledControlArray1DHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->erase_at(idx);
}

void ListLabelledControlArray1D_clear(ListLabelledControlArray1DHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->clear();
}

void ListLabelledControlArray1D_push_back(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->push_back(stored_obj);
}

bool ListLabelledControlArray1D_contains(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->contains(stored_obj);
}

size_t ListLabelledControlArray1D_index(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->index(stored_obj);
}

size_t ListLabelledControlArray1D_items(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledControlArray1D(*list->items()[i]);
}
    return n;
}

LabelledControlArray1DHandle ListLabelledControlArray1D_at(ListLabelledControlArray1DHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray1D(*obj);
}

bool ListLabelledControlArray1D_equal(ListLabelledControlArray1DHandle a, ListLabelledControlArray1DHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(b);
    return *listA == *listB;
}

bool ListLabelledControlArray1D_not_equal(ListLabelledControlArray1DHandle a, ListLabelledControlArray1DHandle b) {
    return !ListLabelledControlArray1D_equal(a, b);
}

ListLabelledControlArray1DHandle ListLabelledControlArray1D_intersection(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(*result);
}

StringHandle      ListLabelledControlArray1D_to_json_string(ListLabelledControlArray1DHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListLabelledControlArray1DHandle ListLabelledControlArray1D_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(*ptr);
}
