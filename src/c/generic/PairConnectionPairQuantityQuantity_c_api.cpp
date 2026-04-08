#include <falcon-core/generic/Pair.hpp>
#include "falcon-core/generic/PairConnectionPairQuantityQuantity_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/physics/device_structures/Connection.hpp>
#include <falcon-core/math/Quantity.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairConnectionHandlePairQuantityQuantityHandle = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>;
DEFINE_C_API_COPY_TEMPLATE(PairConnectionPairQuantityQuantity, MACROPairConnectionHandlePairQuantityQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairConnectionPairQuantityQuantity, MACROPairConnectionHandlePairQuantityQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairConnectionPairQuantityQuantity, MACROPairConnectionHandlePairQuantityQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairConnectionPairQuantityQuantity, MACROPairConnectionHandlePairQuantityQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairConnectionPairQuantityQuantity, MACROPairConnectionHandlePairQuantityQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairConnectionPairQuantityQuantity, MACROPairConnectionHandlePairQuantityQuantityHandle);
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create(ConnectionHandle first, PairQuantityQuantityHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionPairQuantityQuantity_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionPairQuantityQuantity_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionPairQuantityQuantity_first(PairConnectionPairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second(PairConnectionPairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    return new std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
