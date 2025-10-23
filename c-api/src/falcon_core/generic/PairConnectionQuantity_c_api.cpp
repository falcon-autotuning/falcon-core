#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionQuantityHandle PairConnectionQuantity_create(ConnectionHandle first, QuantityHandle second) {
    auto first_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(first),[](falcon_core::physics::device_structures::Connection*) {});
    auto second_obj = std::shared_ptr<falcon_core::math::Quantity>(static_cast<falcon_core::math::Quantity*>(second),[](falcon_core::math::Quantity*) {});
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>(first_obj, second_obj);
}

void PairConnectionQuantity_destroy(PairConnectionQuantityHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
}

ConnectionHandle PairConnectionQuantity_first(PairConnectionQuantityHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

QuantityHandle PairConnectionQuantity_second(PairConnectionQuantityHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(handle);
    return new falcon_core::math::Quantity(*pair->second());
}

bool PairConnectionQuantity_equal(PairConnectionQuantityHandle a, PairConnectionQuantityHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>*>(b);
    return *pair_a == *pair_b;
}
