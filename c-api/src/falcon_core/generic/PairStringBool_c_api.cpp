#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairStringBool_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairStringHandlebool = falcon_core::generic::Pair<std::string, bool>;
DEFINE_C_API_COPY_TEMPLATE(PairStringBool, MACROPairStringHandlebool)
DEFINE_C_API_DESTROY_TEMPLATE(PairStringBool, MACROPairStringHandlebool);
DEFINE_C_API_EQUAL_TEMPLATE(PairStringBool, MACROPairStringHandlebool);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairStringBool, MACROPairStringHandlebool);
DEFINE_C_API_TO_JSON_TEMPLATE(PairStringBool, MACROPairStringHandlebool);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairStringBool, MACROPairStringHandlebool);
PairStringBoolHandle PairStringBool_create(StringHandle first, bool second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null string handle passed to PairStringBool_create");
                }
                std::string first_obj(first->raw, first->length);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<std::string, bool>(
        std::make_shared<falcon_core::generic::Pair<std::string, bool>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

StringHandle PairStringBool_first(PairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_first");
}
    
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<std::string, bool>*>(handle))->first();
StringHandle cstr = String_create(cppstring.data(), cppstring.size());
return cstr;
    FALCON_C_API_END(nullptr)
}

bool PairStringBool_second(PairStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairStringBool_second");
}
    return (*static_cast<falcon_core::generic::PairSP<std::string, bool>*>(handle))->second();
    FALCON_C_API_END(false)
}
}
