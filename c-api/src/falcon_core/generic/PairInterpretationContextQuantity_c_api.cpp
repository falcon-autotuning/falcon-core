#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <falcon_core/math/Quantity.hpp>

PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextQuantity_create");
                }
                auto first_obj= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(first),[](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {});
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairInterpretationContextQuantity_create");
                }
                auto second_obj= std::shared_ptr<falcon_core::math::Quantity>(static_cast<falcon_core::math::Quantity*>(second),[](falcon_core::math::Quantity*) {});
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(first_obj, second_obj);
}

void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
}

InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContext(*pair->first());
}

QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->second());
}

bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle a, PairInterpretationContextQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(b);
    return *pair_a == *pair_b;
}

bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle a, PairInterpretationContextQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInterpretationContextQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(*ptr);
}
