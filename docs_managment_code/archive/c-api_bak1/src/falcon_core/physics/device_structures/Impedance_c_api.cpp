#include "falcon_core/physics/device_structures/Impedance_c_api.h"

#include <falcon_core/physics/device_structures/Impedance.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {
ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance) {
  FALCON_C_API_BEGIN
  if (!connection) {
    throw std::invalid_argument("Impedance_create: connection cannot be null");
  }
  return new Impedance(
      std::shared_ptr<Connection>(static_cast<Connection*>(connection),
                                  [](Connection*) {}),
      resistance,
      capacitance);
  FALCON_C_API_END(nullptr)
}

void Impedance_destroy(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_destroy: handle cannot be null");
  }
  delete static_cast<Impedance*>(handle);
  FALCON_C_API_END()
}

ConnectionHandle Impedance_connection(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_connection: handle cannot be null");
  }
  const auto conn = static_cast<Impedance*>(handle)->connection();
  return static_cast<ConnectionHandle>(conn.get());
  FALCON_C_API_END(nullptr)
}

double Impedance_resistance(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_resistance: handle cannot be null");
  }
  auto resistance = static_cast<Impedance*>(handle)->resistance();
  return resistance;
  FALCON_C_API_END(0.0)
}

double Impedance_capacitance(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_capacitance: handle cannot be null");
  }
  auto capacitance = static_cast<Impedance*>(handle)->capacitance();
  return capacitance;
  FALCON_C_API_END(0.0)
}

bool Impedance_equal(ImpedanceHandle a, ImpedanceHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Impedance_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "Impedance_equal: second handle cannot be null");
  }
  return *(static_cast<Impedance*>(a)) == *(static_cast<Impedance*>(b));
  FALCON_C_API_END(false)
}

bool Impedance_not_equal(ImpedanceHandle a, ImpedanceHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "Impedance_not_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "Impedance_not_equal: second handle cannot be null");
  }
  return *(static_cast<Impedance*>(a)) != *(static_cast<Impedance*>(b));
  FALCON_C_API_END(false)
}

StringHandle Impedance_to_json_string(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Impedance_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<Impedance*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ImpedanceHandle Impedance_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Impedance_from_json_string: json cannot be null");
  }
  auto ptr = Impedance::from_json_string<Impedance>(json->raw);
  return new Impedance(*ptr);
  FALCON_C_API_END(nullptr)
}
}
