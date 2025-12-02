#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesControlArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/ControlArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesControlArrayHandle AxesControlArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>());
    FALCON_C_API_END(nullptr)
}

AxesControlArrayHandle AxesControlArray_create(ListControlArrayHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesControlArray_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesControlArray_destroy(AxesControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle);
    FALCON_C_API_END()
}

size_t AxesControlArray_size(AxesControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesControlArray_empty(AxesControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesControlArray_erase_at(AxesControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesControlArray_clear(AxesControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->clear();
    FALCON_C_API_END()
}

void AxesControlArray_push_back(AxesControlArrayHandle handle, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::ControlArray>(*static_cast<falcon_core::math::arrays::ControlArray*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesControlArray_contains(AxesControlArrayHandle handle, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::ControlArray>(*static_cast<falcon_core::math::arrays::ControlArray*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesControlArray_index(AxesControlArrayHandle handle, ControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::ControlArray>(*static_cast<falcon_core::math::arrays::ControlArray*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesControlArray_items(AxesControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
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
    FALCON_C_API_END(0)
}

ControlArrayHandle AxesControlArray_at(AxesControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::ControlArray(*obj);
    FALCON_C_API_END(nullptr)
}

bool AxesControlArray_equal(AxesControlArrayHandle a, AxesControlArrayHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesControlArray_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesControlArray_not_equal(AxesControlArrayHandle a, AxesControlArrayHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesControlArray_not_equal");
}
    return !AxesControlArray_equal(a, b);
    FALCON_C_API_END(false)
}

AxesControlArrayHandle AxesControlArray_intersection(AxesControlArrayHandle handle, AxesControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesControlArray_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesControlArray_to_json_string(AxesControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesControlArrayHandle AxesControlArray_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesControlArray_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
