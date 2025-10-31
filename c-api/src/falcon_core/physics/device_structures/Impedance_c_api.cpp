#include "falcon_core/physics/device_structures/Impedance_c_api.h"

#include <falcon_core/physics/device_structures/Impedance.hpp>
using namespace falcon_core::physics::device_structures;

ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance) {
  if (!connection) {
    throw std::invalid_argument("Impedance_create: connection cannot be null");
  }
  return new Impedance(
      std::shared_ptr<Connection>(static_cast<Connection*>(connection),
                                  [](Connection*) {}),
      resistance,
      capacitance);
}

void Impedance_destroy(ImpedanceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Impedance_destroy: handle cannot be null");
  }
  delete static_cast<Impedance*>(handle);
}

ConnectionHandle Impedance_connection(ImpedanceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Impedance_connection: handle cannot be null");
  }
  const auto conn = static_cast<Impedance*>(handle)->connection();
  return static_cast<ConnectionHandle>(conn.get());
}

double Impedance_resistance(ImpedanceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Impedance_resistance: handle cannot be null");
  }
  auto resistance = static_cast<Impedance*>(handle)->resistance();
  return resistance;
}

double Impedance_capacitance(ImpedanceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Impedance_capacitance: handle cannot be null");
  }
  auto capacitance = static_cast<Impedance*>(handle)->capacitance();
  return capacitance;
}

bool Impedance_equal(ImpedanceHandle a, ImpedanceHandle b) {
  if (!a) {
    throw std::invalid_argument("Impedance_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "Impedance_equal: second handle cannot be null");
  }
  return *(static_cast<Impedance*>(a)) == *(static_cast<Impedance*>(b));
}

bool Impedance_not_equal(ImpedanceHandle a, ImpedanceHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "Impedance_not_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "Impedance_not_equal: second handle cannot be null");
  }
  return *(static_cast<Impedance*>(a)) != *(static_cast<Impedance*>(b));
}

StringHandle Impedance_to_json_string(ImpedanceHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Impedance_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<Impedance*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

ImpedanceHandle Impedance_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Impedance_from_json_string: json cannot be null");
  }
  auto ptr = Impedance::from_json_string<Impedance>(json->raw);
  return new Impedance(*ptr);
}
