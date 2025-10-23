#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnection_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second) {
    auto first_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(first),[](falcon_core::physics::device_structures::Connection*) {});
    auto second_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(second),[](falcon_core::physics::device_structures::Connection*) {});
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>(first_obj, second_obj);
}

void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
}

ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->second());
}

bool PairConnectionConnection_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(b);
    return *pair_a == *pair_b;
}
