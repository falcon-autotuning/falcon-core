#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntFloat_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairIntFloatHandle PairIntFloat_create(int first, float second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::PairSP<int, float>(
        std::make_shared<falcon_core::generic::Pair<int, float>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairIntFloat_destroy(PairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntFloat_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<int, float>*>(handle);
    FALCON_C_API_END()
}

int PairIntFloat_first(PairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntFloat_first");
}
    return (*static_cast<falcon_core::generic::PairSP<int, float>*>(handle))->first();
    FALCON_C_API_END(0)
}

float PairIntFloat_second(PairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntFloat_second");
}
    return (*static_cast<falcon_core::generic::PairSP<int, float>*>(handle))->second();
    FALCON_C_API_END(0.0)
}

bool PairIntFloat_equal(PairIntFloatHandle handle, PairIntFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairIntFloat_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<int, float>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<int, float>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairIntFloat_not_equal(PairIntFloatHandle handle, PairIntFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairIntFloat_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<int, float>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<int, float>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntFloat_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<int,float>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairIntFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<int,float>::from_json_string<falcon_core::generic::Pair<int,float>>(json->raw);
  return new falcon_core::generic::PairSP<int,float>(ptr);
    FALCON_C_API_END(nullptr)
}
}
