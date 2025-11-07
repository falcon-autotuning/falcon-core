#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionQuantity_create");
                }
                auto first_obj= std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionQuantity_create");
                }
                auto second_obj= std::make_shared<falcon_core::math::Quantity>(*static_cast<falcon_core::math::Quantity*>(second));
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(first_obj, second_obj);
}

void PairConnectionQuantity_destroy(PairConnectionQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
}

ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->second());
}

bool PairConnectionQuantity_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(b);
    return *pair_a == *pair_b;
}

bool PairConnectionQuantity_not_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairConnectionQuantity_to_json_string(PairConnectionQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionQuantity_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairConnectionQuantityHandle PairConnectionQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::math::Quantity>(*ptr);
}
