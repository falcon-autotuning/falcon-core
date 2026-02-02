#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairintfloat = falcon_core::generic::Pair<int, float>;
DEFINE_C_API_COPY_TEMPLATE(PairIntFloat, MACROPairintfloat)
DEFINE_C_API_DESTROY_TEMPLATE(PairIntFloat, MACROPairintfloat);
DEFINE_C_API_EQUAL_TEMPLATE(PairIntFloat, MACROPairintfloat);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairIntFloat, MACROPairintfloat);
DEFINE_C_API_TO_JSON_TEMPLATE(PairIntFloat, MACROPairintfloat);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairIntFloat, MACROPairintfloat);
PairIntFloatHandle PairIntFloat_create(int first, float second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::PairSP<int, float>(
        std::make_shared<falcon_core::generic::Pair<int, float>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

int PairIntFloat_first(PairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntFloat_first");
}
    return (*static_cast<falcon_core::generic::PairSP<int, float>*>(handle))->first();
    FALCON_C_API_END(0)
}

float PairIntFloat_second(PairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntFloat_second");
}
    return (*static_cast<falcon_core::generic::PairSP<int, float>*>(handle))->second();
    FALCON_C_API_END(0.0)
}
}
