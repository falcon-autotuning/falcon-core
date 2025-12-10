#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairfloatfloat = falcon_core::generic::Pair<float, float>;
DEFINE_C_API_COPY_TEMPLATE(PairFloatFloat, MACROPairfloatfloat)
DEFINE_C_API_DESTROY_TEMPLATE(PairFloatFloat, MACROPairfloatfloat);
DEFINE_C_API_EQUAL_TEMPLATE(PairFloatFloat, MACROPairfloatfloat);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairFloatFloat, MACROPairfloatfloat);
DEFINE_C_API_TO_JSON_TEMPLATE(PairFloatFloat, MACROPairfloatfloat);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairFloatFloat, MACROPairfloatfloat);
PairFloatFloatHandle PairFloatFloat_create(float first, float second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::PairSP<float, float>(
        std::make_shared<falcon_core::generic::Pair<float, float>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

float PairFloatFloat_first(PairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_first");
}
    return (*static_cast<falcon_core::generic::PairSP<float, float>*>(handle))->first();
    FALCON_C_API_END(0.0)
}

float PairFloatFloat_second(PairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_second");
}
    return (*static_cast<falcon_core::generic::PairSP<float, float>*>(handle))->second();
    FALCON_C_API_END(0.0)
}
}
