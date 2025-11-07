#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionFloat_create");
                }
                auto first_obj= std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(first));
    auto second_obj = second;
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>(first_obj, second_obj);
}

void PairConnectionFloat_destroy(PairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(handle);
}

ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

float PairConnectionFloat_second(PairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_second");
}
    return static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(handle)->second();
}

bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(b);
    return *pair_a == *pair_b;
}

bool PairConnectionFloat_not_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>(*ptr);
}
