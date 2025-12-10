#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"

#include <falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces;
using namespace falcon_core::autotuner_interfaces::contexts;

extern "C" {
DEFINE_C_API_COPY(MeasurementContext);
DEFINE_C_API_DESTROY(MeasurementContext);
DEFINE_C_API_EQUAL(MeasurementContext);
DEFINE_C_API_NOT_EQUAL(MeasurementContext);
DEFINE_C_API_TO_JSON(MeasurementContext);
DEFINE_C_API_FROM_JSON(MeasurementContext);
MeasurementContextHandle MeasurementContext_create(
    ConnectionHandle connection, StringHandle instrument_type) {
  FALCON_C_API_BEGIN
  if (!connection) {
    throw std::invalid_argument(
        "MeasurementContext_create: connection handle cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "MeasurementContext_create: instrument_type cannot be null");
  }
  physics::device_structures::ConnectionSP real_connection =
      *static_cast<physics::device_structures::ConnectionSP*>(connection);
  return new MeasurementContextSP(std::make_shared<MeasurementContext>(
      real_connection,
      std::string(instrument_type->raw, instrument_type->length)));
  FALCON_C_API_END(nullptr)
}

MeasurementContextHandle MeasurementContext_create_from_port(
    InstrumentPortHandle port) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument(
        "MeasurementContext_create_from_port: port handle cannot be null");
  }
  instrument_interfaces::names::InstrumentPortSP real_port =
      *static_cast<instrument_interfaces::names::InstrumentPortSP*>(port);
  return new MeasurementContextSP(std::make_shared<MeasurementContext>(
      real_port->pseudo_name(), real_port->instrument_type()));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle MeasurementContext_connection(
    MeasurementContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "MeasurementContext_connection: handle cannot be null");
  }
  auto measurement_context = *static_cast<MeasurementContextSP*>(handle);
  return new physics::device_structures::ConnectionSP(
      measurement_context->connection());
  FALCON_C_API_END(nullptr)
}

StringHandle MeasurementContext_instrument_type(
    MeasurementContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "MeasurementContext_instrument_type: handle cannot be null");
  }
  auto        measurement_context = *static_cast<MeasurementContextSP*>(handle);
  std::string instr_type          = measurement_context->instrument_type();
  return String_create(instr_type.c_str(), instr_type.size());
  FALCON_C_API_END(nullptr)
}
}
