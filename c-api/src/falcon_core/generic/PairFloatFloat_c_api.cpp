#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairFloatFloatHandle PairFloatFloat_create(float first, float second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<float, float>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairFloatFloat_destroy(PairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_destroy");
}
    delete static_cast<falcon_core::generic::Pair<float, float>*>(handle);
    FALCON_C_API_END()
}

float PairFloatFloat_first(PairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_first");
}
    return static_cast<falcon_core::generic::Pair<float, float>*>(handle)->first();
    FALCON_C_API_END(0.0)
}

float PairFloatFloat_second(PairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_second");
}
    return static_cast<falcon_core::generic::Pair<float, float>*>(handle)->second();
    FALCON_C_API_END(0.0)
}

bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<float, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<float, float>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairFloatFloat_not_equal(PairFloatFloatHandle a, PairFloatFloatHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<float, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<float, float>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairFloatFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<float,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairFloatFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<float,float>::from_json_string<falcon_core::generic::Pair<float,float>>(json->raw);
  return new falcon_core::generic::Pair<float,float>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
