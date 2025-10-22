#include "falcon_core/physics/device_structures/Impedance_c_api.h"

#include <falcon_core/physics/device_structures/Impedance.hpp>
using namespace falcon_core::physics::device_structures;

extern "C" {

ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance) {
  return new Impedance(
      std::shared_ptr<Connection>(static_cast<Connection*>(connection),
                                  [](Connection*) {}),
      resistance,
      capacitance);
}

void Impedance_destroy(ImpedanceHandle handle) {
  delete static_cast<Impedance*>(handle);
}

ConnectionHandle Impedance_connection(ImpedanceHandle handle) {
  const auto conn = static_cast<Impedance*>(handle)->connection();
  return static_cast<ConnectionHandle>(conn.get());
}

double Impedance_resistance(ImpedanceHandle handle) {
  auto resistance = static_cast<Impedance*>(handle)->resistance();
  return resistance;
}

double Impedance_capacitance(ImpedanceHandle handle) {
  auto capacitance = static_cast<Impedance*>(handle)->capacitance();
  return capacitance;
}

bool Impedance_equal(ImpedanceHandle a, ImpedanceHandle b) {
  return *(static_cast<Impedance*>(a)) == *(static_cast<Impedance*>(b));
}

bool Impedance_not_equal(ImpedanceHandle a, ImpedanceHandle b) {
  return *(static_cast<Impedance*>(a)) != *(static_cast<Impedance*>(b));
}

const char* Impedance_to_json_string(ImpedanceHandle handle) {
  static thread_local std::string json;
  json = static_cast<Impedance*>(handle)->to_json_string();
  return json.c_str();
}

ImpedanceHandle Impedance_from_json_string(const char* json) {
  auto ptr = Impedance::from_json_string<Impedance>(std::string(json));
  return new Impedance(*ptr);
}
}
