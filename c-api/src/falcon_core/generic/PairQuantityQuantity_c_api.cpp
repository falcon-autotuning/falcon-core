#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include <falcon_core/math/Quantity.hpp>

PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second) {
    auto first_obj= std::shared_ptr<falcon_core::math::Quantity>(static_cast<falcon_core::math::Quantity*>(first),[](falcon_core::math::Quantity*) {});
    auto second_obj= std::shared_ptr<falcon_core::math::Quantity>(static_cast<falcon_core::math::Quantity*>(second),[](falcon_core::math::Quantity*) {});
    return new falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>(first_obj, second_obj);
}

void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
}

QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->first());
}

QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->second());
}

bool PairQuantityQuantity_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(b);
    return *pair_a == *pair_b;
}

StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle) {
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::math::Quantity,falcon_core::math::Quantity>(*ptr);
}
