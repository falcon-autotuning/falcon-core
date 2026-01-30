#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairDoubleDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairdoubledouble = falcon_core::generic::Pair<double, double>;
DEFINE_C_API_COPY_TEMPLATE(PairDoubleDouble, MACROPairdoubledouble)
DEFINE_C_API_DESTROY_TEMPLATE(PairDoubleDouble, MACROPairdoubledouble);
DEFINE_C_API_EQUAL_TEMPLATE(PairDoubleDouble, MACROPairdoubledouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairDoubleDouble, MACROPairdoubledouble);
DEFINE_C_API_TO_JSON_TEMPLATE(PairDoubleDouble, MACROPairdoubledouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairDoubleDouble, MACROPairdoubledouble);
PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::PairSP<double, double>(
        std::make_shared<falcon_core::generic::Pair<double, double>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

double PairDoubleDouble_first(PairDoubleDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_first");
}
    return (*static_cast<falcon_core::generic::PairSP<double, double>*>(handle))->first();
    FALCON_C_API_END(0.0)
}

double PairDoubleDouble_second(PairDoubleDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_second");
}
    return (*static_cast<falcon_core::generic::PairSP<double, double>*>(handle))->second();
    FALCON_C_API_END(0.0)
}
}
