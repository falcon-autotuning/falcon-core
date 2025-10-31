#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringBool_c_api.h"

PairStringBoolHandle PairStringBool_create(StringHandle first, bool second) {
    
                if (!first) {
                throw std::invalid_argument("Null string handle passed to PairStringBool_create");
                }
                std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::Pair<std::string, bool>(first_obj, second_obj);
}

void PairStringBool_destroy(PairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_destroy");
}
    delete static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle);
}

StringHandle PairStringBool_first(PairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_first");
}
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle)->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

bool PairStringBool_second(PairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_second");
}
    return static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle)->second();
}

bool PairStringBool_equal(PairStringBoolHandle a, PairStringBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairStringBool_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, bool>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, bool>*>(b);
    return *pair_a == *pair_b;
}

bool PairStringBool_not_equal(PairStringBoolHandle a, PairStringBoolHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairStringBool_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, bool>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, bool>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<std::string,bool>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairStringBoolHandle PairStringBool_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairStringBool_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<std::string,bool>::from_json_string<falcon_core::generic::Pair<std::string,bool>>(json->raw);
  return new falcon_core::generic::Pair<std::string,bool>(*ptr);
}
