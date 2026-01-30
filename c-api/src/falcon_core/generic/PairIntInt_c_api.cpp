#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntInt_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairintint = falcon_core::generic::Pair<int, int>;
DEFINE_C_API_COPY_TEMPLATE(PairIntInt, MACROPairintint)
DEFINE_C_API_DESTROY_TEMPLATE(PairIntInt, MACROPairintint);
DEFINE_C_API_EQUAL_TEMPLATE(PairIntInt, MACROPairintint);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairIntInt, MACROPairintint);
DEFINE_C_API_TO_JSON_TEMPLATE(PairIntInt, MACROPairintint);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairIntInt, MACROPairintint);
PairIntIntHandle PairIntInt_create(int first, int second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::PairSP<int, int>(
        std::make_shared<falcon_core::generic::Pair<int, int>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

int PairIntInt_first(PairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntInt_first");
}
    return (*static_cast<falcon_core::generic::PairSP<int, int>*>(handle))->first();
    FALCON_C_API_END(0)
}

int PairIntInt_second(PairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntInt_second");
}
    return (*static_cast<falcon_core::generic::PairSP<int, int>*>(handle))->second();
    FALCON_C_API_END(0)
}
}
