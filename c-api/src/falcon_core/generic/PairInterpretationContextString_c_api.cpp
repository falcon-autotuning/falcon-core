#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextString_create");
                }
                auto first_obj= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null string handle passed to PairInterpretationContextString_create");
                }
                std::string second_obj(second->raw, second->length);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>(first_obj, second_obj);
}

void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
}

InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*pair->first());
}

StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_second");
}
    
std::string cppstring = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle)->second();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(b);
    return *pair_a == *pair_b;
}

bool PairInterpretationContextString_not_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInterpretationContextString_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(*ptr);
}
