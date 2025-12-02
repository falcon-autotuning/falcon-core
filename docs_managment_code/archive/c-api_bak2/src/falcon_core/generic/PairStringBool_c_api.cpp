#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringBool_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairStringBoolHandle PairStringBool_create(StringHandle first, bool second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null string handle passed to PairStringBool_create");
                }
                std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::Pair<std::string, bool>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairStringBool_destroy(PairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_destroy");
}
    delete static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle);
    FALCON_C_API_END()
}

StringHandle PairStringBool_first(PairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_first");
}
    
std::string cppstring = static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle)->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}

bool PairStringBool_second(PairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_second");
}
    return static_cast<falcon_core::generic::Pair<std::string, bool>*>(handle)->second();
    FALCON_C_API_END(false)
}

bool PairStringBool_equal(PairStringBoolHandle a, PairStringBoolHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairStringBool_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, bool>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, bool>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairStringBool_not_equal(PairStringBoolHandle a, PairStringBoolHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairStringBool_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<std::string, bool>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<std::string, bool>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<std::string,bool>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairStringBoolHandle PairStringBool_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairStringBool_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<std::string,bool>::from_json_string<falcon_core::generic::Pair<std::string,bool>>(json->raw);
  return new falcon_core::generic::Pair<std::string,bool>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
