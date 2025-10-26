#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>

ListAcquisitionContextHandle ListAcquisitionContext_create_empty() {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>());
}

ListAcquisitionContextHandle ListAcquisitionContext_fill_value(size_t count, AcquisitionContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value), [](falcon_core::autotuner_interfaces::contexts::AcquisitionContext*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(count, stored_obj));
}

ListAcquisitionContextHandle ListAcquisitionContext_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(count));
}

ListAcquisitionContextHandle ListAcquisitionContext_create(AcquisitionContextHandle* data, size_t count) {
    std::vector<falcon_core::autotuner_interfaces::contexts::AcquisitionContextSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(data[i]), [](falcon_core::autotuner_interfaces::contexts::AcquisitionContext*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(vec));
}

void ListAcquisitionContext_destroy(ListAcquisitionContextHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle);
}

size_t ListAcquisitionContext_size(ListAcquisitionContextHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->size();
}

bool ListAcquisitionContext_empty(ListAcquisitionContextHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->empty();
}

void ListAcquisitionContext_erase_at(ListAcquisitionContextHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->erase_at(idx);
}

void ListAcquisitionContext_clear(ListAcquisitionContextHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->clear();
}

void ListAcquisitionContext_push_back(ListAcquisitionContextHandle handle, AcquisitionContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value), [](falcon_core::autotuner_interfaces::contexts::AcquisitionContext*) {} );
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->push_back(stored_obj);
}

bool ListAcquisitionContext_contains(ListAcquisitionContextHandle handle, AcquisitionContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value), [](falcon_core::autotuner_interfaces::contexts::AcquisitionContext*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->contains(stored_obj);
}

size_t ListAcquisitionContext_index(ListAcquisitionContextHandle handle, AcquisitionContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(static_cast<falcon_core::autotuner_interfaces::contexts::AcquisitionContext*>(value), [](falcon_core::autotuner_interfaces::contexts::AcquisitionContext*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->index(stored_obj);
}

size_t ListAcquisitionContext_items(ListAcquisitionContextHandle handle, AcquisitionContextHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::contexts::AcquisitionContext(*list->items()[i]);
}
    return n;
}

AcquisitionContextHandle ListAcquisitionContext_at(ListAcquisitionContextHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::contexts::AcquisitionContext(*obj);
}

bool ListAcquisitionContext_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(b);
    return *listA == *listB;
}

bool ListAcquisitionContext_not_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b) {
    return !ListAcquisitionContext_equal(a, b);
}

ListAcquisitionContextHandle ListAcquisitionContext_intersection(ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*result);
}

StringHandle      ListAcquisitionContext_to_json_string(ListAcquisitionContextHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListAcquisitionContextHandle ListAcquisitionContext_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*ptr);
}
