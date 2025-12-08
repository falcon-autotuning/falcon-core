#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include <falcon_core/math/Quantity.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairQuantityQuantity_create");
                }
                auto first_obj= *static_cast<falcon_core::math::QuantitySP*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairQuantityQuantity_create");
                }
                auto second_obj= *static_cast<falcon_core::math::QuantitySP*>(second);
    return new falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    FALCON_C_API_END()
}

QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::QuantitySP(pair->first());
    FALCON_C_API_END(nullptr)
}

QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::QuantitySP(pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairQuantityQuantity_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::math::Quantity,falcon_core::math::Quantity>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairQuantityQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::math::Quantity,falcon_core::math::Quantity>(ptr);
    FALCON_C_API_END(nullptr)
}
}
