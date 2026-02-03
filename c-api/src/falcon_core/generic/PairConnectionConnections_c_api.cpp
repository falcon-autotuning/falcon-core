#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairConnectionConnections_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairConnectionHandleConnectionsHandle = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>;
DEFINE_C_API_COPY_TEMPLATE(PairConnectionConnections, MACROPairConnectionHandleConnectionsHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairConnectionConnections, MACROPairConnectionHandleConnectionsHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairConnectionConnections, MACROPairConnectionHandleConnectionsHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairConnectionConnections, MACROPairConnectionHandleConnectionsHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairConnectionConnections, MACROPairConnectionHandleConnectionsHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairConnectionConnections, MACROPairConnectionHandleConnectionsHandle);
PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionConnections_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionConnections_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connections>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
