#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairSizeTSizeT_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairsize_tsize_t = falcon_core::generic::Pair<size_t, size_t>;
DEFINE_C_API_COPY_TEMPLATE(PairSizeTSizeT, MACROPairsize_tsize_t)
DEFINE_C_API_DESTROY_TEMPLATE(PairSizeTSizeT, MACROPairsize_tsize_t);
DEFINE_C_API_EQUAL_TEMPLATE(PairSizeTSizeT, MACROPairsize_tsize_t);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairSizeTSizeT, MACROPairsize_tsize_t);
DEFINE_C_API_TO_JSON_TEMPLATE(PairSizeTSizeT, MACROPairsize_tsize_t);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairSizeTSizeT, MACROPairsize_tsize_t);
PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::PairSP<size_t, size_t>(
        std::make_shared<falcon_core::generic::Pair<size_t, size_t>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_first");
}
    return (*static_cast<falcon_core::generic::PairSP<size_t, size_t>*>(handle))->first();
    FALCON_C_API_END(0)
}

size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_second");
}
    return (*static_cast<falcon_core::generic::PairSP<size_t, size_t>*>(handle))->second();
    FALCON_C_API_END(0)
}
}
