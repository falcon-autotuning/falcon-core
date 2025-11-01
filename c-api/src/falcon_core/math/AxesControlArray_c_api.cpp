#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesControlArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/ControlArray.hpp>

AxesControlArrayHandle AxesControlArray_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>());
}

AxesControlArrayHandle AxesControlArray_create_raw(const ControlArrayHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::ControlArraySP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesControlArray_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(data[i]), [](falcon_core::math::arrays::ControlArray*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(vec));
}

AxesControlArrayHandle AxesControlArray_create(ListControlArrayHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesControlArray_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(list));
}

void AxesControlArray_destroy(AxesControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle);
}

size_t AxesControlArray_size(AxesControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->size();
}

bool AxesControlArray_empty(AxesControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->empty();
}

void AxesControlArray_erase_at(AxesControlArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->erase_at(idx);
}

void AxesControlArray_clear(AxesControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->clear();
}

void AxesControlArray_push_back(AxesControlArrayHandle handle, ControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->push_back(stored_obj);
}

bool AxesControlArray_contains(AxesControlArrayHandle handle, ControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->contains(stored_obj);
}

size_t AxesControlArray_index(AxesControlArrayHandle handle, ControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray>(static_cast<falcon_core::math::arrays::ControlArray*>(value), [](falcon_core::math::arrays::ControlArray*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->index(stored_obj);
}

size_t AxesControlArray_items(AxesControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesControlArray_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::ControlArray(*list->items()[i]);
}
    return n;
}

ControlArrayHandle AxesControlArray_at(AxesControlArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::ControlArray(*obj);
}

bool AxesControlArray_equal(AxesControlArrayHandle a, AxesControlArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesControlArray_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(b);
    return *listA == *listB;
}

bool AxesControlArray_not_equal(AxesControlArrayHandle a, AxesControlArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesControlArray_not_equal");
}
    return !AxesControlArray_equal(a, b);
}

AxesControlArrayHandle AxesControlArray_intersection(AxesControlArrayHandle handle, AxesControlArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesControlArray_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(result);
}

StringHandle      AxesControlArray_to_json_string(AxesControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesControlArrayHandle AxesControlArray_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesControlArray_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(*ptr);
}
