#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"

#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces;
using namespace falcon_core::autotuner_interfaces::contexts;

extern "C" {
AcquisitionContextHandle AcquisitionContext_create(ConnectionHandle connection,
                                                   StringHandle instrument_type,
                                                   SymbolUnitHandle units) {
  FALCON_C_API_BEGIN
  if (!connection) {
    throw std::invalid_argument(
        "AcquisitionContext_create: connection handle cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "AcquisitionContext_create: instrument_type handle cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "AcquisitionContext_create: units handle cannot be null");
  }
  physics::device_structures::ConnectionSP real_connection =
      *static_cast<physics::device_structures::ConnectionSP*>(connection);
  std::string instr_type =
      std::string(instrument_type->raw, instrument_type->length);
  physics::units::SymbolUnitSP real_units =
      *static_cast<physics::units::SymbolUnitSP*>(units);
  return new AcquisitionContextSP(std::make_shared<AcquisitionContext>(
      real_connection, instr_type, real_units));
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle AcquisitionContext_create_from_port(
    InstrumentPortHandle port) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument(
        "AcquisitionContext_create_from_port: port handle cannot be null");
  }
  instrument_interfaces::names::InstrumentPortSP real_port =
      *static_cast<instrument_interfaces::names::InstrumentPortSP*>(port);
  return new AcquisitionContextSP(
      std::make_shared<AcquisitionContext>(real_port));
  FALCON_C_API_END(nullptr)
}

void AcquisitionContext_destroy(AcquisitionContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_destroy: handle cannot be null");
  }
  delete static_cast<AcquisitionContextSP*>(handle);
  FALCON_C_API_END()
}

ConnectionHandle AcquisitionContext_connection(
    AcquisitionContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_connection: handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  return new physics::device_structures::ConnectionSP(self->connection());
  FALCON_C_API_END(nullptr)
}

StringHandle AcquisitionContext_instrument_type(
    AcquisitionContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_instrument_type: handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  return String_create(self->instrument_type().c_str(),
                       self->instrument_type().size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle AcquisitionContext_units(AcquisitionContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_units: handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  return new physics::units::SymbolUnitSP(self->units());
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle AcquisitionContext_division_unit(
    AcquisitionContextHandle handle, SymbolUnitHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_division_unit: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_division_unit: other handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  physics::units::SymbolUnitSP other_unit =
      *static_cast<physics::units::SymbolUnitSP*>(other);
  return new AcquisitionContextSP(*self / other_unit);
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle AcquisitionContext_division(
    AcquisitionContextHandle handle, AcquisitionContextHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_division: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_division: other handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  AcquisitionContextSP octx = *static_cast<AcquisitionContextSP*>(other);
  return new AcquisitionContextSP(*self / octx);
  FALCON_C_API_END(nullptr)
}

bool AcquisitionContext_match_connection(AcquisitionContextHandle handle,
                                         ConnectionHandle         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_match_connection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_match_connection: other handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  physics::device_structures::ConnectionSP oconn =
      *static_cast<physics::device_structures::ConnectionSP*>(other);
  return self->match_connection(oconn);
  FALCON_C_API_END(false)
}

bool AcquisitionContext_match_instrument_type(AcquisitionContextHandle handle,
                                              StringHandle             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_match_instrument_type: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_match_instrument_type: other handle cannot be "
        "null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  std::string          oinstr_type = std::string(other->raw, other->length);
  return self->match_instrument_type(oinstr_type);
  FALCON_C_API_END(false)
}

bool AcquisitionContext_equal(AcquisitionContextHandle handle,
                              AcquisitionContextHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_equal: handle b cannot be null");
  }
  return *(static_cast<AcquisitionContextSP*>(handle)) ==
         *(static_cast<AcquisitionContextSP*>(other));
  FALCON_C_API_END(false)
}

bool AcquisitionContext_not_equal(AcquisitionContextHandle handle,
                                  AcquisitionContextHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_not_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_not_equal: handle b cannot be null");
  }
  return *(static_cast<AcquisitionContextSP*>(handle)) !=
         *(static_cast<AcquisitionContextSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle AcquisitionContext_to_json_string(
    AcquisitionContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_to_json_string: handle cannot be null");
  }
  AcquisitionContextSP self = *static_cast<AcquisitionContextSP*>(handle);
  std::string          json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle AcquisitionContext_from_json_string(
    const StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "AcquisitionContext_from_json_string: json cannot be null");
  }
  std::string          raw_json(json->raw);
  AcquisitionContextSP context =
      AcquisitionContext::from_json_string<AcquisitionContext>(raw_json);
  return new AcquisitionContextSP(context);
  FALCON_C_API_END(nullptr)
}
}
