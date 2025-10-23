#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second) {
    auto first_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(first),[](falcon_core::physics::device_structures::Connection*) {});
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>(first_obj, second);
}

void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(handle);
}

ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

double PairConnectionDouble_second(PairConnectionDoubleHandle handle) {
    return static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(handle)->second();
}

bool PairConnectionDouble_equal(PairConnectionDoubleHandle a, PairConnectionDoubleHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>*>(b);
    return *pair_a == *pair_b;
}
