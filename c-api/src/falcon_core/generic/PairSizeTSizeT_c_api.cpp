#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairSizeTSizeT_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second) {
    FALCON_C_API_BEGIN
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<size_t, size_t>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_destroy");
}
    delete static_cast<falcon_core::generic::Pair<size_t, size_t>*>(handle);
    FALCON_C_API_END()
}

size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_first");
}
    return static_cast<falcon_core::generic::Pair<size_t, size_t>*>(handle)->first();
    FALCON_C_API_END(0)
}

size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_second");
}
    return static_cast<falcon_core::generic::Pair<size_t, size_t>*>(handle)->second();
    FALCON_C_API_END(0)
}

bool PairSizeTSizeT_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<size_t,size_t>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairSizeTSizeT_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<size_t,size_t>::from_json_string<falcon_core::generic::Pair<size_t,size_t>>(json->raw);
  return new falcon_core::generic::Pair<size_t,size_t>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
