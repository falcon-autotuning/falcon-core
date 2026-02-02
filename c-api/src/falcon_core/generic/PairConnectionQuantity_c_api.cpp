#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairConnectionHandleQuantityHandle = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(PairConnectionQuantity, MACROPairConnectionHandleQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairConnectionQuantity, MACROPairConnectionHandleQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairConnectionQuantity, MACROPairConnectionHandleQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairConnectionQuantity, MACROPairConnectionHandleQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairConnectionQuantity, MACROPairConnectionHandleQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairConnectionQuantity, MACROPairConnectionHandleQuantityHandle);
PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionQuantity_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionQuantity_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    return new std::shared_ptr<falcon_core::math::Quantity>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
