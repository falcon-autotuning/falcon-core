#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionPairQuantityQuantity_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <falcon_core/math/Quantity.hpp>

PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create(ConnectionHandle first, PairQuantityQuantityHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionPairQuantityQuantity_create");
                }
                auto first_obj= std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(first),[](falcon_core::physics::device_structures::Connection*) {});
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionPairQuantityQuantity_create");
                }
                auto second_obj= std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(second),[](falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*) {});
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(first_obj, second_obj);
}

void PairConnectionPairQuantityQuantity_destroy(PairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
}

ConnectionHandle PairConnectionPairQuantityQuantity_first(PairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second(PairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    return new falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>(*pair->second());
}

bool PairConnectionPairQuantityQuantity_equal(PairConnectionPairQuantityQuantityHandle a, PairConnectionPairQuantityQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(b);
    return *pair_a == *pair_b;
}

bool PairConnectionPairQuantityQuantity_not_equal(PairConnectionPairQuantityQuantityHandle a, PairConnectionPairQuantityQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairConnectionPairQuantityQuantity_to_json_string(PairConnectionPairQuantityQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionPairQuantityQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(*ptr);
}
