#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntInt_c_api.h"

PairIntIntHandle PairIntInt_create(int first, int second) {
    return new falcon_core::generic::Pair<int, int>(first, second);
}

void PairIntInt_destroy(PairIntIntHandle handle) {
    delete static_cast<falcon_core::generic::Pair<int, int>*>(handle);
}

int PairIntInt_first(PairIntIntHandle handle) {
    return static_cast<falcon_core::generic::Pair<int, int>*>(handle)->first();
}

int PairIntInt_second(PairIntIntHandle handle) {
    return static_cast<falcon_core::generic::Pair<int, int>*>(handle)->second();
}

bool PairIntInt_equal(PairIntIntHandle a, PairIntIntHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<int, int>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<int, int>*>(b);
    return *pair_a == *pair_b;
}
