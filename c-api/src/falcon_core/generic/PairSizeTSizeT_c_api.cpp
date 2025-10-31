#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairSizeTSizeT_c_api.h"

PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second) {
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<size_t, size_t>(first_obj, second_obj);
}

void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_destroy");
}
    delete static_cast<falcon_core::generic::Pair<size_t, size_t>*>(handle);
}

size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_first");
}
    return static_cast<falcon_core::generic::Pair<size_t, size_t>*>(handle)->first();
}

size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_second");
}
    return static_cast<falcon_core::generic::Pair<size_t, size_t>*>(handle)->second();
}

bool PairSizeTSizeT_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(b);
    return *pair_a == *pair_b;
}

bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<size_t, size_t>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairSizeTSizeT_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<size_t,size_t>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairSizeTSizeT_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<size_t,size_t>::from_json_string<falcon_core::generic::Pair<size_t,size_t>>(json->raw);
  return new falcon_core::generic::Pair<size_t,size_t>(*ptr);
}
