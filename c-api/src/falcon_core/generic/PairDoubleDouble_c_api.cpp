#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairDoubleDouble_c_api.h"

PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second) {
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<double, double>(first_obj, second_obj);
}

void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle) {
    delete static_cast<falcon_core::generic::Pair<double, double>*>(handle);
}

double PairDoubleDouble_first(PairDoubleDoubleHandle handle) {
    return static_cast<falcon_core::generic::Pair<double, double>*>(handle)->first();
}

double PairDoubleDouble_second(PairDoubleDoubleHandle handle) {
    return static_cast<falcon_core::generic::Pair<double, double>*>(handle)->second();
}

bool PairDoubleDouble_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<double, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<double, double>*>(b);
    return *pair_a == *pair_b;
}

StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle) {
std::string json = static_cast<falcon_core::generic::Pair<double,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Pair<double,double>::from_json_string<falcon_core::generic::Pair<double,double>>(json->raw);
  return new falcon_core::generic::Pair<double,double>(*ptr);
}
