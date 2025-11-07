#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListImpedance_c_api.h"
#include <falcon_core/physics/device_structures/Impedance.hpp>

ListImpedanceHandle ListImpedance_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>();
}

ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::physics::device_structures::Impedance>(*static_cast<falcon_core::physics::device_structures::Impedance*>(value));
    
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(
        count, stored_obj);
}
 

ListImpedanceHandle ListImpedance_create(ImpedanceHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListImpedance_create");
}
    std::vector<falcon_core::physics::device_structures::ImpedanceSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::physics::device_structures::Impedance>(*static_cast<falcon_core::physics::device_structures::Impedance*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(vec);
}

void ListImpedance_destroy(ListImpedanceHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListImpedance_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle);
}

size_t ListImpedance_size(ListImpedanceHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->size();
}

bool ListImpedance_empty(ListImpedanceHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->empty();
}

void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->erase_at(idx);
}

void ListImpedance_clear(ListImpedanceHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->clear();
}

void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::physics::device_structures::Impedance>(*static_cast<falcon_core::physics::device_structures::Impedance*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->push_back(stored_obj);
}

bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::physics::device_structures::Impedance>(*static_cast<falcon_core::physics::device_structures::Impedance*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->contains(stored_obj);
}

size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::physics::device_structures::Impedance>(*static_cast<falcon_core::physics::device_structures::Impedance*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->index(stored_obj);
}

size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListImpedance_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::device_structures::Impedance(*list->items()[i]);
}
    return n;
}

ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->at(idx);
    return new falcon_core::physics::device_structures::Impedance(*obj);
}

bool ListImpedance_equal(ListImpedanceHandle a, ListImpedanceHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListImpedance_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(b);
    return *listA == *listB;
}

bool ListImpedance_not_equal(ListImpedanceHandle a, ListImpedanceHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListImpedance_not_equal");
}
    return !ListImpedance_equal(a, b);
}

ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListImpedance_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(*result);
}

StringHandle      ListImpedance_to_json_string(ListImpedanceHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListImpedanceHandle ListImpedance_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListImpedance_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>::from_json_string<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(json->raw);
  return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(*ptr);
}
