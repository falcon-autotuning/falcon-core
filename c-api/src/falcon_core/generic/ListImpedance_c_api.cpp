#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListImpedance_c_api.h"
#include <falcon_core/physics/device_structures/Impedance.hpp>

ListImpedanceHandle ListImpedance_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>());
}

ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Impedance>(static_cast<falcon_core::physics::device_structures::Impedance*>(value), [](falcon_core::physics::device_structures::Impedance*) {} );
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(count, stored_obj));
}

ListImpedanceHandle ListImpedance_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(count));
}

ListImpedanceHandle ListImpedance_create(const ImpedanceHandle* data, size_t count) {
    std::vector<falcon_core::physics::device_structures::ImpedanceSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::physics::device_structures::Impedance>(static_cast<falcon_core::physics::device_structures::Impedance*>(data[i]), [](falcon_core::physics::device_structures::Impedance*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(vec));
}

void ListImpedance_destroy(ListImpedanceHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle);
}

size_t ListImpedance_size(ListImpedanceHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->size();
}

bool ListImpedance_empty(ListImpedanceHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->empty();
}

void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->erase_at(idx);
}

void ListImpedance_clear(ListImpedanceHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->clear();
}

void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Impedance>(static_cast<falcon_core::physics::device_structures::Impedance*>(value), [](falcon_core::physics::device_structures::Impedance*) {} );
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->push_back(stored_obj);
}

bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Impedance>(static_cast<falcon_core::physics::device_structures::Impedance*>(value), [](falcon_core::physics::device_structures::Impedance*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->contains(stored_obj);
}

size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Impedance>(static_cast<falcon_core::physics::device_structures::Impedance*>(value), [](falcon_core::physics::device_structures::Impedance*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->index(stored_obj);
}

size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::device_structures::Impedance(*list->items()[i]);
}
    return n;
}

ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->at(idx);
    return new falcon_core::physics::device_structures::Impedance(*obj);
}

bool ListImpedance_equal(ListImpedanceHandle a, ListImpedanceHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(b);
    return *listA == *listB;
}

bool ListImpedance_not_equal(ListImpedanceHandle a, ListImpedanceHandle b) {
    return !ListImpedance_equal(a, b);
}

ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(*result);
}

StringHandle      ListImpedance_to_json_string(ListImpedanceHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListImpedanceHandle ListImpedance_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>::from_json_string<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(json->raw);
  return new falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>(*ptr);
}
