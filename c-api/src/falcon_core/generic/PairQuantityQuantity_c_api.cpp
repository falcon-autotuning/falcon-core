#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include <falcon_core/math/Quantity.hpp>

PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairQuantityQuantity_create");
                }
                auto first_obj= std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairQuantityQuantity_create");
                }
                auto second_obj= std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(second));
    return new falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>(first_obj, second_obj);
}

void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
}

QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->first());
}

QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->second());
}

bool PairQuantityQuantity_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(b);
    return *pair_a == *pair_b;
}

bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairQuantityQuantity_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairQuantityQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>(*ptr);
}
