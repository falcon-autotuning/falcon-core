#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairStringDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairStringHandledouble = falcon_core::generic::Pair<std::string, double>;
DEFINE_C_API_COPY_TEMPLATE(PairStringDouble, MACROPairStringHandledouble)
DEFINE_C_API_DESTROY_TEMPLATE(PairStringDouble, MACROPairStringHandledouble);
DEFINE_C_API_EQUAL_TEMPLATE(PairStringDouble, MACROPairStringHandledouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairStringDouble, MACROPairStringHandledouble);
DEFINE_C_API_TO_JSON_TEMPLATE(PairStringDouble, MACROPairStringHandledouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairStringDouble, MACROPairStringHandledouble);
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
}
