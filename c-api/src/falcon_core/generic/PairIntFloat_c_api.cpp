#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntFloat_c_api.h"

PairIntFloatHandle PairIntFloat_create(int first, float second) {
    return new falcon_core::generic::Pair<int, float>(first, second);
}

void PairIntFloat_destroy(PairIntFloatHandle handle) {
    delete static_cast<falcon_core::generic::Pair<int, float>*>(handle);
}

int PairIntFloat_first(PairIntFloatHandle handle) {
    return static_cast<falcon_core::generic::Pair<int, float>*>(handle)->first();
}

float PairIntFloat_second(PairIntFloatHandle handle) {
    return static_cast<falcon_core::generic::Pair<int, float>*>(handle)->second();
}

bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<int, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<int, float>*>(b);
    return *pair_a == *pair_b;
}
