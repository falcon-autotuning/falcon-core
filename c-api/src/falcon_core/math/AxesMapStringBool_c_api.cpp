#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesMapStringBool_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Map.hpp>

AxesMapStringBoolHandle AxesMapStringBool_create_empty() {
    return new falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>());
}

AxesMapStringBoolHandle AxesMapStringBool_create_raw(const MapStringBoolHandle* data, size_t count) {
    std::vector<falcon_core::generic::MapSP<std::string, bool>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(data[i]), [](falcon_core::generic::Map<std::string, bool>*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>(
        falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>(vec));
}

AxesMapStringBoolHandle AxesMapStringBool_create(ListMapStringBoolHandle data) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>*>(data);
    return new falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(list));
}

void AxesMapStringBool_destroy(AxesMapStringBoolHandle handle) {
    delete static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle);
}

size_t AxesMapStringBool_size(AxesMapStringBoolHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->size();
}

bool AxesMapStringBool_empty(AxesMapStringBoolHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->empty();
}

void AxesMapStringBool_erase_at(AxesMapStringBoolHandle handle, size_t idx) {
    static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->erase_at(idx);
}

void AxesMapStringBool_clear(AxesMapStringBoolHandle handle) {
    static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->clear();
}

void AxesMapStringBool_push_back(AxesMapStringBoolHandle handle, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->push_back(stored_obj);
}

bool AxesMapStringBool_contains(AxesMapStringBoolHandle handle, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->contains(stored_obj);
}

size_t AxesMapStringBool_index(AxesMapStringBoolHandle handle, MapStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(static_cast<falcon_core::generic::Map<std::string, bool>*>(value), [](falcon_core::generic::Map<std::string, bool>*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->index(stored_obj);
}

size_t AxesMapStringBool_items(AxesMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Map<std::string, bool>(*list->items()[i]);
}
    return n;
}

MapStringBoolHandle AxesMapStringBool_at(AxesMapStringBoolHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->at(idx);
    return new falcon_core::generic::Map<std::string, bool>(*obj);
}

bool AxesMapStringBool_equal(AxesMapStringBoolHandle a, AxesMapStringBoolHandle b) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(b);
    return *listA == *listB;
}

bool AxesMapStringBool_not_equal(AxesMapStringBoolHandle a, AxesMapStringBoolHandle b) {
    return !AxesMapStringBool_equal(a, b);
}

AxesMapStringBoolHandle AxesMapStringBool_intersection(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>>(*listB));
    return new falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>(result);
}

StringHandle      AxesMapStringBool_to_json_string(AxesMapStringBoolHandle handle) {
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
AxesMapStringBoolHandle AxesMapStringBool_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>::from_json_string<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>(*ptr);
}
