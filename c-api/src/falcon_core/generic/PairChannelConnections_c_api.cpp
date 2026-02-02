#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairChannelConnections_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairChannelHandleConnectionsHandle = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>;
DEFINE_C_API_COPY_TEMPLATE(PairChannelConnections, MACROPairChannelHandleConnectionsHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairChannelConnections, MACROPairChannelHandleConnectionsHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairChannelConnections, MACROPairChannelHandleConnectionsHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairChannelConnections, MACROPairChannelHandleConnectionsHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairChannelConnections, MACROPairChannelHandleConnectionsHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairChannelConnections, MACROPairChannelHandleConnectionsHandle);
PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairChannelConnections_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairChannelConnections_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(handle);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(pair->first());
    FALCON_C_API_END(nullptr)
}

ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connections>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
