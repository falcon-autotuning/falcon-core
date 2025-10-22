#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <string>
using namespace falcon_core::physics::device_structures;

extern "C" {

ConnectionHandle Connection_create_barrier_gate(const char* name) {
  return new Connection(std::string(name), DeviceFeature::BarrierGate);
}

ConnectionHandle Connection_create_plunger_gate(const char* name) {
  return new Connection(std::string(name), DeviceFeature::PlungerGate);
}

ConnectionHandle Connection_create_reservoir_gate(const char* name) {
  return new Connection(std::string(name), DeviceFeature::ReservoirGate);
}

ConnectionHandle Connection_create_screening_gate(const char* name) {
  return new Connection(std::string(name), DeviceFeature::ScreeningGate);
}

ConnectionHandle Connection_create_ohmic(const char* name) {
  return new Connection(std::string(name), DeviceFeature::Ohmic);
}

void Connection_destroy(ConnectionHandle handle) {
  delete static_cast<Connection*>(handle);
}

const char* Connection_name(ConnectionHandle handle) {
  static thread_local std::string name;
  name = static_cast<Connection*>(handle)->name();
  return name.c_str();
}

const char* Connection_type(ConnectionHandle handle) {
  static thread_local std::string type;
  type = static_cast<Connection*>(handle)->type();
  return type.c_str();
}

bool Connection_is_dot_gate(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_dot_gate();
}

bool Connection_is_barrier_gate(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_barrier_gate();
}

bool Connection_is_plunger_gate(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_plunger_gate();
}

bool Connection_is_reservoir_gate(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_reservoir_gate();
}

bool Connection_is_screening_gate(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_screening_gate();
}

bool Connection_is_ohmic(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_ohmic();
}

bool Connection_is_gate(ConnectionHandle handle) {
  return static_cast<Connection*>(handle)->is_gate();
}

bool Connection_equal(ConnectionHandle a, ConnectionHandle b) {
  return *(static_cast<Connection*>(a)) == *(static_cast<Connection*>(b));
}

bool Connection_not_equal(ConnectionHandle a, ConnectionHandle b) {
  return *(static_cast<Connection*>(a)) != *(static_cast<Connection*>(b));
}

// --- Song methods ---

const char* Connection_to_json_string(ConnectionHandle handle) {
  static thread_local std::string json;
  json = static_cast<Connection*>(handle)->to_json_string();
  return json.c_str();
}

ConnectionHandle Connection_from_json_string(const char* json) {
  auto ptr = Connection::from_json_string<Connection>(std::string(json));
  return new Connection(*ptr);
}
}
