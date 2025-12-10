#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairInterpretationContextHandledouble = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>;
DEFINE_C_API_COPY_TEMPLATE(PairInterpretationContextDouble, MACROPairInterpretationContextHandledouble)
DEFINE_C_API_DESTROY_TEMPLATE(PairInterpretationContextDouble, MACROPairInterpretationContextHandledouble);
DEFINE_C_API_EQUAL_TEMPLATE(PairInterpretationContextDouble, MACROPairInterpretationContextHandledouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairInterpretationContextDouble, MACROPairInterpretationContextHandledouble);
DEFINE_C_API_TO_JSON_TEMPLATE(PairInterpretationContextDouble, MACROPairInterpretationContextHandledouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairInterpretationContextDouble, MACROPairInterpretationContextHandledouble);
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextDouble_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(first);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(pair->first());
    FALCON_C_API_END(nullptr)
}

double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_second");
}
    return (*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle))->second();
    FALCON_C_API_END(0.0)
}
}
