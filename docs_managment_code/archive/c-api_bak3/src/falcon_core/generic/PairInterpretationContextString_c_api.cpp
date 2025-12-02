#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextString_create");
                }
                auto first_obj= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null string handle passed to PairInterpretationContextString_create");
                }
                std::string second_obj(second->raw, second->length);
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
    FALCON_C_API_END()
}

InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*pair->first());
    FALCON_C_API_END(nullptr)
}

StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_second");
}
    
std::string cppstring = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(handle)->second();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}

bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairInterpretationContextString_not_equal(PairInterpretationContextStringHandle a, PairInterpretationContextStringHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextString_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInterpretationContextString_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
