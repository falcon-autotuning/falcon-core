#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairInterpretationContextQuantity_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <falcon_core/math/Quantity.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairInterpretationContextHandleQuantityHandle = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(PairInterpretationContextQuantity, MACROPairInterpretationContextHandleQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairInterpretationContextQuantity, MACROPairInterpretationContextHandleQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairInterpretationContextQuantity, MACROPairInterpretationContextHandleQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairInterpretationContextQuantity, MACROPairInterpretationContextHandleQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairInterpretationContextQuantity, MACROPairInterpretationContextHandleQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairInterpretationContextQuantity, MACROPairInterpretationContextHandleQuantityHandle);
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextQuantity_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextQuantity_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(pair->first());
    FALCON_C_API_END(nullptr)
}

QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    return new std::shared_ptr<falcon_core::math::Quantity>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
