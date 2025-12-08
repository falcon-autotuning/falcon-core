#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringString_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null string handle passed to PairStringString_create");
                }
                std::string first_obj(first->raw, first->length);
    
                if (!second) {
                throw std::invalid_argument("Null string handle passed to PairStringString_create");
                }
                std::string second_obj(second->raw, second->length);
    return new falcon_core::generic::PairSP<std::string, std::string>(
        std::make_shared<falcon_core::generic::Pair<std::string, std::string>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairStringString_destroy(PairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringString_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(handle);
    FALCON_C_API_END()
}

StringHandle PairStringString_first(PairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringString_first");
}
    
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(handle))->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}

StringHandle PairStringString_second(PairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringString_second");
}
    
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(handle))->second();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}

bool PairStringString_equal(PairStringStringHandle handle, PairStringStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairStringString_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairStringString_not_equal(PairStringStringHandle handle, PairStringStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairStringString_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<std::string, std::string>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairStringString_to_json_string(PairStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringString_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<std::string,std::string>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairStringStringHandle PairStringString_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairStringString_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<std::string,std::string>::from_json_string<falcon_core::generic::Pair<std::string,std::string>>(json->raw);
  return new falcon_core::generic::PairSP<std::string,std::string>(ptr);
    FALCON_C_API_END(nullptr)
}
}
