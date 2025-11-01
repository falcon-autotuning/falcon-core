#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPortTransform_c_api.h"
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>

ListPortTransformHandle ListPortTransform_create_empty() {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>());
}

ListPortTransformHandle ListPortTransform_fill_value(size_t count, PortTransformHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(value), [](falcon_core::instrument_interfaces::port_transforms::PortTransform*) {} );
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(count, stored_obj));
}

ListPortTransformHandle ListPortTransform_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(count));
}

ListPortTransformHandle ListPortTransform_create(PortTransformHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPortTransform_create");
}
    std::vector<falcon_core::instrument_interfaces::port_transforms::PortTransformSP> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListPortTransform_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(data[i]), [](falcon_core::instrument_interfaces::port_transforms::PortTransform*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(vec));
}

void ListPortTransform_destroy(ListPortTransformHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPortTransform_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
}

size_t ListPortTransform_size(ListPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->size();
}

bool ListPortTransform_empty(ListPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->empty();
}

void ListPortTransform_erase_at(ListPortTransformHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->erase_at(idx);
}

void ListPortTransform_clear(ListPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->clear();
}

void ListPortTransform_push_back(ListPortTransformHandle handle, PortTransformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(value), [](falcon_core::instrument_interfaces::port_transforms::PortTransform*) {} );
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->push_back(stored_obj);
}

bool ListPortTransform_contains(ListPortTransformHandle handle, PortTransformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(value), [](falcon_core::instrument_interfaces::port_transforms::PortTransform*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->contains(stored_obj);
}

size_t ListPortTransform_index(ListPortTransformHandle handle, PortTransformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(value), [](falcon_core::instrument_interfaces::port_transforms::PortTransform*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->index(stored_obj);
}

size_t ListPortTransform_items(ListPortTransformHandle handle, PortTransformHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPortTransform_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::instrument_interfaces::port_transforms::PortTransform(*list->items()[i]);
}
    return n;
}

PortTransformHandle ListPortTransform_at(ListPortTransformHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->at(idx);
    return new falcon_core::instrument_interfaces::port_transforms::PortTransform(*obj);
}

bool ListPortTransform_equal(ListPortTransformHandle a, ListPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPortTransform_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(b);
    return *listA == *listB;
}

bool ListPortTransform_not_equal(ListPortTransformHandle a, ListPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPortTransform_not_equal");
}
    return !ListPortTransform_equal(a, b);
}

ListPortTransformHandle ListPortTransform_intersection(ListPortTransformHandle handle, ListPortTransformHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPortTransform_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*listB));
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(*result);
}

StringHandle      ListPortTransform_to_json_string(ListPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPortTransformHandle ListPortTransform_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>::from_json_string<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>>(json->raw);
  return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(*ptr);
}
