#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairDoubleDouble_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<double, double>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_destroy");
}
    delete static_cast<falcon_core::generic::Pair<double, double>*>(handle);
    FALCON_C_API_END()
}

double PairDoubleDouble_first(PairDoubleDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_first");
}
    return static_cast<falcon_core::generic::Pair<double, double>*>(handle)->first();
    FALCON_C_API_END(0.0)
}

double PairDoubleDouble_second(PairDoubleDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_second");
}
    return static_cast<falcon_core::generic::Pair<double, double>*>(handle)->second();
    FALCON_C_API_END(0.0)
}

bool PairDoubleDouble_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<double, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<double, double>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairDoubleDouble_not_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<double, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<double, double>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairDoubleDouble_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<double,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairDoubleDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<double,double>::from_json_string<falcon_core::generic::Pair<double,double>>(json->raw);
  return new falcon_core::generic::Pair<double,double>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
