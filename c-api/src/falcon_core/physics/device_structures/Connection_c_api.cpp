#include "falcon_core/physics/device_structures/Connection_c_api.h"

#include <falcon_core/physics/device_structures/Connection.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {

ConnectionHandle Connection_create_barrier_gate(StringHandle name) {
  return new Connection(std::string(name->raw, name->length),
                        DeviceFeature::BarrierGate);
}

ConnectionHandle Connection_create_plunger_gate(StringHandle name) {
  return new Connection(std::string(name->raw, name->length),
                        DeviceFeature::PlungerGate);
}

ConnectionHandle Connection_create_reservoir_gate(StringHandle name) {
  return new Connection(std::string(name->raw, name->length),
                        DeviceFeature::ReservoirGate);
}

ConnectionHandle Connection_create_screening_gate(StringHandle name) {
  return new Connection(std::string(name->raw, name->length),
                        DeviceFeature::ScreeningGate);
}

ConnectionHandle Connection_create_ohmic(StringHandle name) {
  return new Connection(std::string(name->raw, name->length),
                        DeviceFeature::Ohmic);
}

void Connection_destroy(ConnectionHandle handle) {
  delete static_cast<Connection*>(handle);
}

StringHandle Connection_name(ConnectionHandle handle) {
  std::string name = static_cast<Connection*>(handle)->name();
  return String_create(name.c_str(), name.size());
}

StringHandle Connection_type(ConnectionHandle handle) {
  std::string type;
  return String_create(type.c_str(), type.size());
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

StringHandle Connection_to_json_string(ConnectionHandle handle) {
  std::string json = static_cast<Connection*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

ConnectionHandle Connection_from_json_string(StringHandle json) {
  auto ptr = Connection::from_json_string<Connection>(json->raw);
  return new Connection(*ptr);
}
}
