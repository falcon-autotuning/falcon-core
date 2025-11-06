#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListControlArray1D_c_api.h"
#include <falcon_core/math/arrays/ControlArray1D.hpp>

ListControlArray1DHandle ListControlArray1D_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>());
}

ListControlArray1DHandle ListControlArray1D_fill_value(size_t count, ControlArray1DHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>(
        count, stored_obj);
}
 

ListControlArray1DHandle ListControlArray1D_create(ControlArray1DHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListControlArray1D_create");
}
    std::vector<falcon_core::math::arrays::ControlArray1DSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(data[i]), [](falcon_core::math::arrays::ControlArray1D*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>(
        falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>(vec));
}

void ListControlArray1D_destroy(ListControlArray1DHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListControlArray1D_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle);
}

size_t ListControlArray1D_size(ListControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->size();
}

bool ListControlArray1D_empty(ListControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->empty();
}

void ListControlArray1D_erase_at(ListControlArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->erase_at(idx);
}

void ListControlArray1D_clear(ListControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->clear();
}

void ListControlArray1D_push_back(ListControlArray1DHandle handle, ControlArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->push_back(stored_obj);
}

bool ListControlArray1D_contains(ListControlArray1DHandle handle, ControlArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->contains(stored_obj);
}

size_t ListControlArray1D_index(ListControlArray1DHandle handle, ControlArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListControlArray1D_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->index(stored_obj);
}

size_t ListControlArray1D_items(ListControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListControlArray1D_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::ControlArray1D(*list->items()[i]);
}
    return n;
}

ControlArray1DHandle ListControlArray1D_at(ListControlArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::ControlArray1D(*obj);
}

bool ListControlArray1D_equal(ListControlArray1DHandle a, ListControlArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(b);
    return *listA == *listB;
}

bool ListControlArray1D_not_equal(ListControlArray1DHandle a, ListControlArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_not_equal");
}
    return !ListControlArray1D_equal(a, b);
}

ListControlArray1DHandle ListControlArray1D_intersection(ListControlArray1DHandle handle, ListControlArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>(*result);
}

StringHandle      ListControlArray1D_to_json_string(ListControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListControlArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListControlArray1DHandle ListControlArray1D_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListControlArray1D_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>::from_json_string<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>(*ptr);
}
