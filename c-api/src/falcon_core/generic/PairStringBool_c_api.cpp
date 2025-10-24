#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringBool_c_api.h"

PairStringBoolHandle PairStringBool_create(StringHandle first, bool second) {
    std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::Pair<std::string, bool>(first_obj, second_obj);
}

void PairStringBool_destroy(PairStringBoolHandle handle) {
    delete static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle);
}

StringHandle PairStringBool_first(PairStringBoolHandle handle) {
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle)->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

bool PairStringBool_second(PairStringBoolHandle handle) {
    return static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle)->second();
}

bool PairStringBool_equal(PairStringBoolHandle a, PairStringBoolHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, bool>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, bool>*>(b);
    return *pair_a == *pair_b;
}

StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle) {
std::string json = static_cast<falcon_core::generic::Pair<std::string,bool>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
PairStringBoolHandle PairStringBool_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Pair<std::string,bool>::from_json_string<falcon_core::generic::Pair<std::string,bool>>(json->raw);
  return new falcon_core::generic::Pair<std::string,bool>(*ptr);
}
