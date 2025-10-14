#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second) {
    auto first_obj = static_cast<falcon_core::physics::device_structures::ConnectionSP*>(first);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>(*first_obj, second);
}

void PairConnectionFloat_destroy(PairConnectionFloatHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(handle);
}

ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(handle);
    return new falcon_core::physics::device_structures::ConnectionSP(pair->first());
}

float PairConnectionFloat_second(PairConnectionFloatHandle handle) {
    return static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(handle)->second();
}

bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(b);
    return *pair_a == *pair_b;
}
