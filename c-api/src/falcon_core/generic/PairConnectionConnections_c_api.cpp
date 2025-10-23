#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>

PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second) {
    auto first_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(first),[](falcon_core::physics::device_structures::Connection*) {});
    auto second_obj = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(second),[](falcon_core::physics::device_structures::Connections*) {});
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(first_obj, second_obj);
}

void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
}

ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::physics::device_structures::Connections(*pair->second());
}

bool PairConnectionConnections_equal(PairConnectionConnectionsHandle a, PairConnectionConnectionsHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(b);
    return *pair_a == *pair_b;
}
