#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListControlArray_c_api.h"
#include <falcon_core/math/arrays/ControlArray.hpp>

ListControlArrayHandle ListControlArray_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(
        falcon_core::generic::List<falcon_core::math::arrays::ControlArray>());
}

ListControlArrayHandle ListControlArray_fill_value(size_t count, ControlArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(
        falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(count, stored_obj));
}

ListControlArrayHandle ListControlArray_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(
        falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(count));
}

ListControlArrayHandle ListControlArray_create(ControlArrayHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::ControlArraySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(data[i]), [](falcon_core::math::arrays::ControlArray*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(
        falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(vec));
}

void ListControlArray_destroy(ListControlArrayHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle);
}

size_t ListControlArray_size(ListControlArrayHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->size();
}

bool ListControlArray_empty(ListControlArrayHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->empty();
}

void ListControlArray_erase_at(ListControlArrayHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->erase_at(idx);
}

void ListControlArray_clear(ListControlArrayHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->clear();
}

void ListControlArray_push_back(ListControlArrayHandle handle, ControlArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->push_back(stored_obj);
}

bool ListControlArray_contains(ListControlArrayHandle handle, ControlArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->contains(stored_obj);
}

size_t ListControlArray_index(ListControlArrayHandle handle, ControlArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->index(stored_obj);
}

size_t ListControlArray_items(ListControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::ControlArray(*list->items()[i]);
}
    return n;
}

ControlArrayHandle ListControlArray_at(ListControlArrayHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::ControlArray(*obj);
}

bool ListControlArray_equal(ListControlArrayHandle a, ListControlArrayHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(b);
    return *listA == *listB;
}

bool ListControlArray_not_equal(ListControlArrayHandle a, ListControlArrayHandle b) {
    return !ListControlArray_equal(a, b);
}

ListControlArrayHandle ListControlArray_intersection(ListControlArrayHandle handle, ListControlArrayHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(*result);
}

StringHandle      ListControlArray_to_json_string(ListControlArrayHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListControlArrayHandle ListControlArray_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::ControlArray>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray>(*ptr);
}
