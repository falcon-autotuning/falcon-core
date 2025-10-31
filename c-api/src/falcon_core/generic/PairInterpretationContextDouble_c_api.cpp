#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextDouble_create");
                }
                auto first_obj= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(first),[](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {});
    auto second_obj = second;
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>(first_obj, second_obj);
}

void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
}

InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*pair->first());
}

double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_second");
}
    return static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle)->second();
}

bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle a, PairInterpretationContextDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(b);
    return *pair_a == *pair_b;
}

bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle a, PairInterpretationContextDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextDouble_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInterpretationContextDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(*ptr);
}
