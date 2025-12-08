#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextDouble_create");
                }
                auto first_obj= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(first);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    FALCON_C_API_END()
}

InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP(pair->first());
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

bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInterpretationContextDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(ptr);
    FALCON_C_API_END(nullptr)
}
}
