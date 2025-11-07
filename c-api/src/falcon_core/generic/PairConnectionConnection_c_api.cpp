#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnection_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionConnection_create");
                }
                auto first_obj= std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionConnection_create");
                }
                auto second_obj= std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(second));
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>(first_obj, second_obj);
}

void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
}

ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->second());
}

bool PairConnectionConnection_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(b);
    return *pair_a == *pair_b;
}

bool PairConnectionConnection_not_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairConnectionConnection_to_json_string(PairConnectionConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnection_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairConnectionConnectionHandle PairConnectionConnection_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionConnection_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connection>(*ptr);
}
