#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairFloatFloat_c_api.h"

PairFloatFloatHandle PairFloatFloat_create(float first, float second) {
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<float, float>(first_obj, second_obj);
}

void PairFloatFloat_destroy(PairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_destroy");
}
    delete static_cast<falcon_core::generic::Pair<float, float>*>(handle);
}

float PairFloatFloat_first(PairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_first");
}
    return static_cast<falcon_core::generic::Pair<float, float>*>(handle)->first();
}

float PairFloatFloat_second(PairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_second");
}
    return static_cast<falcon_core::generic::Pair<float, float>*>(handle)->second();
}

bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<float, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<float, float>*>(b);
    return *pair_a == *pair_b;
}

bool PairFloatFloat_not_equal(PairFloatFloatHandle a, PairFloatFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<float, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<float, float>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<float,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairFloatFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<float,float>::from_json_string<falcon_core::generic::Pair<float,float>>(json->raw);
  return new falcon_core::generic::Pair<float,float>(*ptr);
}
