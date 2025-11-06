#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairChannelConnections_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>

ListPairChannelConnectionsHandle ListPairChannelConnections_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>());
}

ListPairChannelConnectionsHandle ListPairChannelConnections_fill_value(size_t count, PairChannelConnectionsHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(
        count, stored_obj);
}
 

ListPairChannelConnectionsHandle ListPairChannelConnections_create(PairChannelConnectionsHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairChannelConnections_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(vec));
}

void ListPairChannelConnections_destroy(ListPairChannelConnectionsHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairChannelConnections_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle);
}

size_t ListPairChannelConnections_size(ListPairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->size();
}

bool ListPairChannelConnections_empty(ListPairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->empty();
}

void ListPairChannelConnections_erase_at(ListPairChannelConnectionsHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->erase_at(idx);
}

void ListPairChannelConnections_clear(ListPairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->clear();
}

void ListPairChannelConnections_push_back(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->push_back(stored_obj);
}

bool ListPairChannelConnections_contains(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->contains(stored_obj);
}

size_t ListPairChannelConnections_index(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairChannelConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->index(stored_obj);
}

size_t ListPairChannelConnections_items(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairChannelConnections_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>(*list->items()[i]);
}
    return n;
}

PairChannelConnectionsHandle ListPairChannelConnections_at(ListPairChannelConnectionsHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>(*obj);
}

bool ListPairChannelConnections_equal(ListPairChannelConnectionsHandle a, ListPairChannelConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(b);
    return *listA == *listB;
}

bool ListPairChannelConnections_not_equal(ListPairChannelConnectionsHandle a, ListPairChannelConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_not_equal");
}
    return !ListPairChannelConnections_equal(a, b);
}

ListPairChannelConnectionsHandle ListPairChannelConnections_intersection(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(*result);
}

StringHandle      ListPairChannelConnections_to_json_string(ListPairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairChannelConnections_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairChannelConnectionsHandle ListPairChannelConnections_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairChannelConnections_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>(*ptr);
}
