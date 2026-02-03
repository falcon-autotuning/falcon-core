#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringString_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairStringHandleStringHandle = falcon_core::generic::Pair<std::string, std::string>;
DEFINE_C_API_COPY_TEMPLATE(PairStringString, MACROPairStringHandleStringHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairStringString, MACROPairStringHandleStringHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairStringString, MACROPairStringHandleStringHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairStringString, MACROPairStringHandleStringHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairStringString, MACROPairStringHandleStringHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairStringString, MACROPairStringHandleStringHandle);
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
}
