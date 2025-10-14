#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairFloatFloat_c_api.h"

PairFloatFloatHandle PairFloatFloat_create(float first, float second) {
    return new falcon_core::generic::Pair<float, float>(first, second);
}

void PairFloatFloat_destroy(PairFloatFloatHandle handle) {
    delete static_cast<falcon_core::generic::Pair<float, float>*>(handle);
}

float PairFloatFloat_first(PairFloatFloatHandle handle) {
    return static_cast<falcon_core::generic::Pair<float, float>*>(handle)->first();
}

float PairFloatFloat_second(PairFloatFloatHandle handle) {
    return static_cast<falcon_core::generic::Pair<float, float>*>(handle)->second();
}

bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<float, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<float, float>*>(b);
    return *pair_a == *pair_b;
}
