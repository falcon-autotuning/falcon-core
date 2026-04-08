#include <falcon-core/generic/Pair.hpp>
#include "falcon-core/generic/PairInterpretationContextString_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairInterpretationContextHandleStringHandle = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>;
DEFINE_C_API_COPY_TEMPLATE(PairInterpretationContextString, MACROPairInterpretationContextHandleStringHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairInterpretationContextString, MACROPairInterpretationContextHandleStringHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairInterpretationContextString, MACROPairInterpretationContextHandleStringHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairInterpretationContextString, MACROPairInterpretationContextHandleStringHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairInterpretationContextString, MACROPairInterpretationContextHandleStringHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairInterpretationContextString, MACROPairInterpretationContextHandleStringHandle);
PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextString_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null string handle passed to PairInterpretationContextString_create");
                }
                std::string second_obj(second->raw, second->length);
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(pair->first());
    FALCON_C_API_END(nullptr)
}

StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_second");
}
    
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle))->second();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}
}
