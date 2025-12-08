#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringDouble_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null string handle passed to PairStringDouble_create");
                }
                std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<std::string, double>(
        std::make_shared<falcon_core::generic::Pair<std::string, double>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairStringDouble_destroy(PairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<std::string, double>*>(handle);
    FALCON_C_API_END()
}

StringHandle PairStringDouble_first(PairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_first");
}
    
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<std::string, double>*>(handle))->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}

double PairStringDouble_second(PairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_second");
}
    return (*static_cast<falcon_core::generic::PairSP<std::string, double>*>(handle))->second();
    FALCON_C_API_END(0.0)
}

bool PairStringDouble_equal(PairStringDoubleHandle handle, PairStringDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairStringDouble_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<std::string, double>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<std::string, double>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairStringDouble_not_equal(PairStringDoubleHandle handle, PairStringDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairStringDouble_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<std::string, double>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<std::string, double>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringDouble_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<std::string,double>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairStringDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<std::string,double>::from_json_string<falcon_core::generic::Pair<std::string,double>>(json->raw);
  return new falcon_core::generic::PairSP<std::string,double>(ptr);
    FALCON_C_API_END(nullptr)
}
}
