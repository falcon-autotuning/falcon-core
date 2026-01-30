#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListPairChannelConnections_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairChannelConnectionsHandle= falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairChannelConnections, MACROListPairChannelConnectionsHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairChannelConnections, MACROListPairChannelConnectionsHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairChannelConnections, MACROListPairChannelConnectionsHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairChannelConnections, MACROListPairChannelConnectionsHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairChannelConnections, MACROListPairChannelConnectionsHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairChannelConnections, MACROListPairChannelConnectionsHandle);
ListPairChannelConnectionsHandle ListPairChannelConnections_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>>());
    FALCON_C_API_END(nullptr)
}

ListPairChannelConnectionsHandle ListPairChannelConnections_fill_value(size_t count, PairChannelConnectionsHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairChannelConnectionsHandle ListPairChannelConnections_create(PairChannelConnectionsHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairChannelConnections_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairChannelConnections_size(ListPairChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairChannelConnections_empty(ListPairChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairChannelConnections_erase_at(ListPairChannelConnectionsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairChannelConnections_clear(ListPairChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairChannelConnections_push_back(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairChannelConnections_contains(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairChannelConnections_index(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairChannelConnections_items(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairChannelConnections_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairChannelConnectionsHandle ListPairChannelConnections_at(ListPairChannelConnectionsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairChannelConnectionsHandle ListPairChannelConnections_intersection(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(result);
    FALCON_C_API_END(nullptr)
}
}
