#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnection_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairConnectionHandleConnectionHandle = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>;
DEFINE_C_API_COPY_TEMPLATE(PairConnectionConnection, MACROPairConnectionHandleConnectionHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairConnectionConnection, MACROPairConnectionHandleConnectionHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairConnectionConnection, MACROPairConnectionHandleConnectionHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairConnectionConnection, MACROPairConnectionHandleConnectionHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairConnectionConnection, MACROPairConnectionHandleConnectionHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairConnectionConnection, MACROPairConnectionHandleConnectionHandle);
PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionConnection_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionConnection_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
