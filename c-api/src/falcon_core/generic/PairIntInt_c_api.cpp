#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairIntInt_c_api.h"

PairIntIntHandle PairIntInt_create(int first, int second) {
    auto first_obj = first;
    auto second_obj = second;
    return new falcon_core::generic::Pair<int, int>(first_obj, second_obj);
}

void PairIntInt_destroy(PairIntIntHandle handle) {
    delete static_cast<falcon_core::generic::Pair<int, int>*>(handle);
}

int PairIntInt_first(PairIntIntHandle handle) {
    return static_cast<falcon_core::generic::Pair<int, int>*>(handle)->first();
}

int PairIntInt_second(PairIntIntHandle handle) {
    return static_cast<falcon_core::generic::Pair<int, int>*>(handle)->second();
}

bool PairIntInt_equal(PairIntIntHandle a, PairIntIntHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<int, int>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<int, int>*>(b);
    return *pair_a == *pair_b;
}

const char*      PairIntInt_to_json_string(PairIntIntHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::Pair<int,int>*>(handle)->to_json_string();
  return json.c_str();
}
PairIntIntHandle PairIntInt_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::Pair<int,int>::from_json_string<falcon_core::generic::Pair<int,int>>(std::string(json));
  return new falcon_core::generic::Pair<int,int>(*ptr);
}
