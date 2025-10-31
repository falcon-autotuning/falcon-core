#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringDouble_c_api.h"

PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second) {
    
                if (!first) {
                throw std::invalid_argument("Null string handle passed to PairStringDouble_create");
                }
                std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::Pair<std::string, double>(first_obj, second_obj);
}

void PairStringDouble_destroy(PairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_destroy");
}
    delete static_cast<falcon_core::generic::Pair<std::string, double>*>(handle);
}

StringHandle PairStringDouble_first(PairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_first");
}
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, double>*>(handle)->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

double PairStringDouble_second(PairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_second");
}
    return static_cast<falcon_core::generic::Pair<std::string, double>*>(handle)->second();
}

bool PairStringDouble_equal(PairStringDoubleHandle a, PairStringDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairStringDouble_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, double>*>(b);
    return *pair_a == *pair_b;
}

bool PairStringDouble_not_equal(PairStringDoubleHandle a, PairStringDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairStringDouble_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, double>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, double>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<std::string,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairStringDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<std::string,double>::from_json_string<falcon_core::generic::Pair<std::string,double>>(json->raw);
  return new falcon_core::generic::Pair<std::string,double>(*ptr);
}
