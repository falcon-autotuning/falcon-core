#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionPairQuantityQuantity_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <falcon_core/math/Quantity.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create(ConnectionHandle first, PairQuantityQuantityHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionPairQuantityQuantity_create");
                }
                auto first_obj= *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionPairQuantityQuantity_create");
                }
                auto second_obj= *static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>SP*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairConnectionPairQuantityQuantity_destroy(PairConnectionPairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    FALCON_C_API_END()
}

ConnectionHandle PairConnectionPairQuantityQuantity_first(PairConnectionPairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    return new falcon_core::physics::device_structures::ConnectionSP(pair->first());
    FALCON_C_API_END(nullptr)
}

PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second(PairConnectionPairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    return new falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>SP(pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairConnectionPairQuantityQuantity_equal(PairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairConnectionPairQuantityQuantity_not_equal(PairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairConnectionPairQuantityQuantity_to_json_string(PairConnectionPairQuantityQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionPairQuantityQuantity_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionPairQuantityQuantity_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
