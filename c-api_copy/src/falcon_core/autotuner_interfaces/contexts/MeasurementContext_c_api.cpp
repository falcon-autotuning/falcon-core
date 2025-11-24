#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"

#include <falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces;
using namespace falcon_core::autotuner_interfaces::contexts;

extern "C" {
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
      std::make_shared<physics::device_structures::Connection>(
          *static_cast<physics::device_structures::Connection*>(connection));
  return new MeasurementContext(MeasurementContext(
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
      std::make_shared<instrument_interfaces::names::InstrumentPort>(
          *static_cast<instrument_interfaces::names::InstrumentPort*>(port));
  return new MeasurementContext(MeasurementContext(
      real_port->pseudo_name(), real_port->instrument_type()));
  FALCON_C_API_END(nullptr)
}

void MeasurementContext_destroy(MeasurementContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "MeasurementContext_destroy: handle cannot be null");
  }
  delete static_cast<MeasurementContext*>(handle);
  FALCON_C_API_END()
}

ConnectionHandle MeasurementContext_connection(
    MeasurementContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "MeasurementContext_connection: handle cannot be null");
  }
  auto measurement_context = static_cast<MeasurementContext*>(handle);
  return new physics::device_structures::Connection(
      *(measurement_context->connection()));
  FALCON_C_API_END(nullptr)
}

StringHandle MeasurementContext_instrument_type(
    MeasurementContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "MeasurementContext_instrument_type: handle cannot be null");
  }
  auto        measurement_context = static_cast<MeasurementContext*>(handle);
  std::string instr_type          = measurement_context->instrument_type();
  return String_create(instr_type.c_str(), instr_type.size());
  FALCON_C_API_END(nullptr)
}

bool MeasurementContext_equal(MeasurementContextHandle a,
                              MeasurementContextHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "MeasurementContext_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "MeasurementContext_equal: handle b cannot be null");
  }
  return *(static_cast<MeasurementContext*>(a)) ==
         *(static_cast<MeasurementContext*>(b));
  FALCON_C_API_END(false)
}

bool MeasurementContext_not_equal(MeasurementContextHandle a,
                                  MeasurementContextHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "MeasurementContext_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "MeasurementContext_not_equal: handle b cannot be null");
  }
  return *(static_cast<MeasurementContext*>(a)) !=
         *(static_cast<MeasurementContext*>(b));
  FALCON_C_API_END(false)
}

StringHandle MeasurementContext_to_json_string(
    MeasurementContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "MeasurementContext_to_json_string: handle cannot be null");
  }
  MeasurementContext self = *static_cast<MeasurementContext*>(handle);
  std::string        json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

MeasurementContextHandle MeasurementContext_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "MeasurementContext_from_json_string: json cannot be null");
  }
  std::string raw_json(json->raw);
  auto ptr = MeasurementContext::from_json_string<MeasurementContext>(raw_json);
  return new MeasurementContext(*ptr);
  FALCON_C_API_END(nullptr)
}
}
