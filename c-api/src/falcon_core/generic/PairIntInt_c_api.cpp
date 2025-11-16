#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntInt_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairIntIntHandle PairIntInt_create(int first, int second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<int, int>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairIntInt_destroy(PairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntInt_destroy");
}
    delete static_cast<falcon_core::generic::Pair<int, int>*>(handle);
    FALCON_C_API_END()
}

int PairIntInt_first(PairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntInt_first");
}
    return static_cast<falcon_core::generic::Pair<int, int>*>(handle)->first();
    FALCON_C_API_END(0)
}

int PairIntInt_second(PairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntInt_second");
}
    return static_cast<falcon_core::generic::Pair<int, int>*>(handle)->second();
    FALCON_C_API_END(0)
}

bool PairIntInt_equal(PairIntIntHandle a, PairIntIntHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairIntInt_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<int, int>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<int, int>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairIntInt_not_equal(PairIntIntHandle a, PairIntIntHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairIntInt_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<int, int>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<int, int>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairIntInt_to_json_string(PairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairIntInt_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<int,int>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairIntIntHandle PairIntInt_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairIntInt_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<int,int>::from_json_string<falcon_core::generic::Pair<int,int>>(json->raw);
  return new falcon_core::generic::Pair<int,int>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
