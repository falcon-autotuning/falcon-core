#include "falcon_core/physics/device_structures/Connection_c_api.h"

#include <falcon_core/physics/device_structures/Connection.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {

ConnectionHandle Connection_create_barrier_gate(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "Connection_create_barrier_gate: Name cannot be null");
  }
  return new ConnectionSP(std::make_shared<Connection>(
      std::string(name->raw, name->length), DeviceFeature::BarrierGate));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Connection_create_plunger_gate(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "Connection_create_plunger_gate: Name cannot be null");
  }
  return new ConnectionSP(std::make_shared<Connection>(
      std::string(name->raw, name->length), DeviceFeature::PlungerGate));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Connection_create_reservoir_gate(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "Connection_create_reservoir_gate: Name cannot be null");
  }
  return new ConnectionSP(std::make_shared<Connection>(
      std::string(name->raw, name->length), DeviceFeature::ReservoirGate));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Connection_create_screening_gate(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "Connection_create_screening_gate: Name cannot be null");
  }
  return new ConnectionSP(std::make_shared<Connection>(
      std::string(name->raw, name->length), DeviceFeature::ScreeningGate));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Connection_create_ohmic(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument("Connection_create_ohmic: Name cannot be null");
  }
  return new ConnectionSP(std::make_shared<Connection>(
      std::string(name->raw, name->length), DeviceFeature::Ohmic));
  FALCON_C_API_END(nullptr)
}

void Connection_destroy(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_destroy: handle cannot be null");
  }
  delete static_cast<ConnectionSP*>(handle);
  return;
  FALCON_C_API_END()
}

StringHandle Connection_name(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_name: handle cannot be null");
  }
  std::string name = (*static_cast<ConnectionSP*>(handle))->name();
  return String_create(name.c_str(), name.size());
  FALCON_C_API_END(nullptr)
}

StringHandle Connection_type(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_type: handle cannot be null");
  }
  std::string type = (*static_cast<ConnectionSP*>(handle))->type();
  return String_create(type.c_str(), type.size());
  FALCON_C_API_END(nullptr)
}

bool Connection_is_dot_gate(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connection_is_dot_gate: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_dot_gate();
  FALCON_C_API_END(false)
}

bool Connection_is_barrier_gate(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connection_is_barrier_gate: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_barrier_gate();
  FALCON_C_API_END(false)
}

bool Connection_is_plunger_gate(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connection_is_plunger_gate: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_plunger_gate();
  FALCON_C_API_END(false)
}

bool Connection_is_reservoir_gate(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connection_is_reservoir_gate: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_reservoir_gate();
  FALCON_C_API_END(false)
}

bool Connection_is_screening_gate(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connection_is_screening_gate: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_screening_gate();
  FALCON_C_API_END(false)
}

bool Connection_is_ohmic(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_is_ohmic: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_ohmic();
  FALCON_C_API_END(false)
}

bool Connection_is_gate(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_is_gate: handle cannot be null");
  }
  return (*static_cast<ConnectionSP*>(handle))->is_gate();
  FALCON_C_API_END(false)
}

bool Connection_equal(ConnectionHandle handle, ConnectionHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Connection_equal: handle cannot be null");
  }
  return *(*static_cast<ConnectionSP*>(handle)) ==
         *(*static_cast<ConnectionSP*>(other));
  FALCON_C_API_END(false)
}

bool Connection_not_equal(ConnectionHandle handle, ConnectionHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connection_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Connection_not_equal: handle cannot be null");
  }
  return *(*static_cast<ConnectionSP*>(handle)) !=
         *(*static_cast<ConnectionSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle Connection_to_json_string(ConnectionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connection_to_json_string: handle cannot be null");
  }
  std::string json = (*static_cast<ConnectionSP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Connection_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Connection_from_json_string: json cannot be null");
  }
  auto ptr = Connection::from_json_string<Connection>(json->raw);
  return new ConnectionSP(ptr);
  FALCON_C_API_END(nullptr)
}

}  // extern "C"
