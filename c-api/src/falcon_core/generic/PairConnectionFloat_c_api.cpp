#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairConnectionHandlefloat = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>;
DEFINE_C_API_COPY_TEMPLATE(PairConnectionFloat, MACROPairConnectionHandlefloat)
DEFINE_C_API_DESTROY_TEMPLATE(PairConnectionFloat, MACROPairConnectionHandlefloat);
DEFINE_C_API_EQUAL_TEMPLATE(PairConnectionFloat, MACROPairConnectionHandlefloat);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairConnectionFloat, MACROPairConnectionHandlefloat);
DEFINE_C_API_TO_JSON_TEMPLATE(PairConnectionFloat, MACROPairConnectionHandlefloat);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairConnectionFloat, MACROPairConnectionHandlefloat);
PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionFloat_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

float PairConnectionFloat_second(PairConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_second");
}
    return (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle))->second();
    FALCON_C_API_END(0.0)
}
}
