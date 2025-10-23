#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListLabelledDomain_c_api.h"
#include <falcon_core/math/domains/LabelledDomain.hpp>

ListLabelledDomainHandle ListLabelledDomain_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>());
}

ListLabelledDomainHandle ListLabelledDomain_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(count));
}

void ListLabelledDomain_destroy(ListLabelledDomainHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle);
}

size_t ListLabelledDomain_size(ListLabelledDomainHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->size();
}

bool ListLabelledDomain_empty(ListLabelledDomainHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->empty();
}

void ListLabelledDomain_erase_at(ListLabelledDomainHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->erase_at(idx);
}

void ListLabelledDomain_clear(ListLabelledDomainHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->clear();
}

bool ListLabelledDomain_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>*>(b);
    return *listA == *listB;
}

bool ListLabelledDomain_not_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b) {
    return !ListLabelledDomain_equal(a, b);
}

ListLabelledDomainHandle ListLabelledDomain_intersection(ListLabelledDomainHandle handle, ListLabelledDomainHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(*result);
}

ListLabelledDomainHandle ListLabelledDomain_fill_value(size_t count, LabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(count, stored_obj));
}

ListLabelledDomainHandle ListLabelledDomain_create(const LabelledDomainHandle* data, size_t count) {
    std::vector<falcon_core::math::domains::LabelledDomainSP> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(data[i]), [](falcon_core::math::domains::LabelledDomain*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(
        falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>(vec));
}

void ListLabelledDomain_push_back(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->push_back(stored_obj);
}

LabelledDomainHandle ListLabelledDomain_at(ListLabelledDomainHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->at(idx);
    return new falcon_core::math::domains::LabelledDomain(*obj);
}

size_t ListLabelledDomain_items(ListLabelledDomainHandle handle, LabelledDomainHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::math::domains::LabelledDomain(*list->items()[i]);
    }
    return n;
}

bool ListLabelledDomain_contains(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->contains(stored_obj);
}

size_t ListLabelledDomain_index(ListLabelledDomainHandle handle, LabelledDomainHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::domains::LabelledDomain>(static_cast<falcon_core::math::domains::LabelledDomain*>(value), [](falcon_core::math::domains::LabelledDomain*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>*>(handle)->index(stored_obj);
}
