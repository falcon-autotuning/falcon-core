#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListImpedance_c_api.h"
#include <falcon_core/physics/device_structures/Impedance.hpp>

ListImpedanceHandle ListImpedance_create_empty() {
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>());
}

ListImpedanceHandle ListImpedance_allocate(size_t count) {
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(count));
}

ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ImpedanceSP*>(value);
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(count, stored_obj));
}

ListImpedanceHandle ListImpedance_create(const ImpedanceHandle* data, size_t count) {
    std::vector<falcon_core::physics::device_structures::ImpedanceSP> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::physics::device_structures::ImpedanceSP*>(data[i]));
    }
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(vec));
}

void ListImpedance_destroy(ListImpedanceHandle handle) {
    delete static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle);
}

void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ImpedanceSP*>(value);
    (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->push_back(stored_obj);
}

size_t ListImpedance_size(ListImpedanceHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->size();
}

bool ListImpedance_empty(ListImpedanceHandle handle) {
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->empty();
}

void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->erase_at(idx);
}

void ListImpedance_clear(ListImpedanceHandle handle) {
    (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->clear();
}

ImpedanceHandle ListImpedance_const_at(ListImpedanceHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->at(idx);
    return new falcon_core::physics::device_structures::ImpedanceSP(obj);
}

ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->at(idx);
    return new falcon_core::physics::device_structures::ImpedanceSP(obj);
}

size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::physics::device_structures::ImpedanceSP(list->items()[i]);
    }
    return n;
}

bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ImpedanceSP*>(value);
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->contains(stored_obj);
}

size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ImpedanceSP*>(value);
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle))->index(stored_obj);
}

ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(result);
}

bool ListImpedance_equal(ListImpedanceHandle a, ListImpedanceHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>*>(b);
    return *listA == *listB;
}

bool ListImpedance_not_equal(ListImpedanceHandle a, ListImpedanceHandle b) {
    return !ListImpedance_equal(a, b);
}
