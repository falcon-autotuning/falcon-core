#include "falcon_core/physics/device_structures/Impedance_c_api.h"

#include <falcon_core/physics/device_structures/Impedance.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::physics::device_structures;

extern "C" {
DEFINE_C_API_COPY(Impedance);
DEFINE_C_API_DESTROY(Impedance);
DEFINE_C_API_EQUAL(Impedance);
DEFINE_C_API_NOT_EQUAL(Impedance);
DEFINE_C_API_TO_JSON(Impedance);
DEFINE_C_API_FROM_JSON(Impedance);
ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance) {
  FALCON_C_API_BEGIN
  if (!connection) {
    throw std::invalid_argument("Impedance_create: connection cannot be null");
  }
  return new ImpedanceSP(std::make_shared<Impedance>(
      *static_cast<ConnectionSP*>(connection), resistance, capacitance));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle Impedance_connection(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_connection: handle cannot be null");
  }
  auto conn = (*static_cast<ImpedanceSP*>(handle))->connection();
  return new ConnectionSP(conn);
  FALCON_C_API_END(nullptr)
}

double Impedance_resistance(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_resistance: handle cannot be null");
  }
  return (*static_cast<ImpedanceSP*>(handle))->resistance();
  FALCON_C_API_END(0.0)
}

double Impedance_capacitance(ImpedanceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedance_capacitance: handle cannot be null");
  }
  return (*static_cast<ImpedanceSP*>(handle))->capacitance();
  FALCON_C_API_END(0.0)
}
}
