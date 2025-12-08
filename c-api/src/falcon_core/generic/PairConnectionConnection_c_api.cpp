#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnection_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionConnection_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionConnection_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    FALCON_C_API_END()
}

ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairConnectionConnection_equal(PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairConnectionConnection_not_equal(PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairConnectionConnection_to_json_string(PairConnectionConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairConnectionConnectionHandle PairConnectionConnection_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionConnection_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>(ptr);
    FALCON_C_API_END(nullptr)
}
}
