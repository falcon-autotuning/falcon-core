#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringDouble_c_api.h"

PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second) {
    std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::Pair<std::string, double>(first_obj, second_obj);
}

void PairStringDouble_destroy(PairStringDoubleHandle handle) {
    delete static_cast<falcon_core::generic::Pair<std::string, double>*>(handle);
}

StringHandle PairStringDouble_first(PairStringDoubleHandle handle) {
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, double>*>(handle)->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

double PairStringDouble_second(PairStringDoubleHandle handle) {
    return static_cast<falcon_core::generic::Pair<std::string, double>*>(handle)->second();
}

bool PairStringDouble_equal(PairStringDoubleHandle a, PairStringDoubleHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, double>*>(b);
    return *pair_a == *pair_b;
}

const char*      PairStringDouble_to_json_string(PairStringDoubleHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::Pair<std::string,double>*>(handle)->to_json_string();
  return json.c_str();
}
PairStringDoubleHandle PairStringDouble_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::Pair<std::string,double>::from_json_string<falcon_core::generic::Pair<std::string,double>>(std::string(json));
  return new falcon_core::generic::Pair<std::string,double>(*ptr);
}
