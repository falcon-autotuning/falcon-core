#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionFloat_create");
                }
                auto first_obj= *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(first);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairConnectionFloat_destroy(PairConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle);
    FALCON_C_API_END()
}

ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle);
    return new falcon_core::physics::device_structures::ConnectionSP(pair->first());
    FALCON_C_API_END(nullptr)
}

float PairConnectionFloat_second(PairConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_second");
}
    return (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle))->second();
    FALCON_C_API_END(0.0)
}

bool PairConnectionFloat_equal(PairConnectionFloatHandle handle, PairConnectionFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairConnectionFloat_not_equal(PairConnectionFloatHandle handle, PairConnectionFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionFloat_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>(ptr);
    FALCON_C_API_END(nullptr)
}
}
