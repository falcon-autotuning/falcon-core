#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <falcon_core/math/Quantity.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
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

void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    FALCON_C_API_END()
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

bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInterpretationContextQuantity_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInterpretationContextQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(ptr);
    FALCON_C_API_END(nullptr)
}
}
