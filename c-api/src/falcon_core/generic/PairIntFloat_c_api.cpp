#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntFloat_c_api.h"

PairIntFloatHandle PairIntFloat_create(int first, float second) {
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<int, float>(first_obj, second_obj);
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

StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle) {
std::string json = static_cast<falcon_core::generic::Pair<int,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Pair<int,float>::from_json_string<falcon_core::generic::Pair<int,float>>(json->raw);
  return new falcon_core::generic::Pair<int,float>(*ptr);
}
