#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairConnectionDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairConnectionHandledouble = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>;
DEFINE_C_API_COPY_TEMPLATE(PairConnectionDouble, MACROPairConnectionHandledouble)
DEFINE_C_API_DESTROY_TEMPLATE(PairConnectionDouble, MACROPairConnectionHandledouble);
DEFINE_C_API_EQUAL_TEMPLATE(PairConnectionDouble, MACROPairConnectionHandledouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairConnectionDouble, MACROPairConnectionHandledouble);
DEFINE_C_API_TO_JSON_TEMPLATE(PairConnectionDouble, MACROPairConnectionHandledouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairConnectionDouble, MACROPairConnectionHandledouble);
PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionDouble_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

double PairConnectionDouble_second(PairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_second");
}
    return (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle))->second();
    FALCON_C_API_END(0.0)
}
}
