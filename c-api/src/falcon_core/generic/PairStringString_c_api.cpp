#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringString_c_api.h"

PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second) {
    std::string first_obj(first->raw, first->length);
    std::string second_obj(second->raw, second->length);
    return new falcon_core::generic::Pair<std::string, std::string>(first_obj, second_obj);
}

void PairStringString_destroy(PairStringStringHandle handle) {
    delete static_cast<falcon_core::generic::Pair<std::string, std::string>*>(handle);
}

StringHandle PairStringString_first(PairStringStringHandle handle) {
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, std::string>*>(handle)->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

StringHandle PairStringString_second(PairStringStringHandle handle) {
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, std::string>*>(handle)->second();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
}

bool PairStringString_equal(PairStringStringHandle a, PairStringStringHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, std::string>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, std::string>*>(b);
    return *pair_a == *pair_b;
}

StringHandle      PairStringString_to_json_string(PairStringStringHandle handle) {
std::string json = static_cast<falcon_core::generic::Pair<std::string,std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
PairStringStringHandle PairStringString_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Pair<std::string,std::string>::from_json_string<falcon_core::generic::Pair<std::string,std::string>>(json->raw);
  return new falcon_core::generic::Pair<std::string,std::string>(*ptr);
}
