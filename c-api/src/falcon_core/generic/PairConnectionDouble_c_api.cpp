#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionDouble_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    auto second_obj = second;
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle);
    FALCON_C_API_END()
}

ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

double PairConnectionDouble_second(PairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_second");
}
    return (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle))->second();
    FALCON_C_API_END(0.0)
}

bool PairConnectionDouble_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairConnectionDouble_not_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairConnectionDouble_to_json_string(PairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionDouble_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairConnectionDoubleHandle PairConnectionDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,double>(ptr);
    FALCON_C_API_END(nullptr)
}
}
