#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"

#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces;
using namespace falcon_core::autotuner_interfaces::contexts;

AcquisitionContextHandle AcquisitionContext_create(ConnectionHandle connection,
                                                   StringHandle instrument_type,
                                                   SymbolUnitHandle units) {
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
      std::make_shared<physics::device_structures::Connection>(
          *static_cast<physics::device_structures::Connection*>(connection));
  std::string instr_type =
      std::string(instrument_type->raw, instrument_type->length);
  physics::units::SymbolUnitSP real_units =
      std::make_shared<physics::units::SymbolUnit>(
          *static_cast<physics::units::SymbolUnit*>(units));
  return new AcquisitionContext(real_connection, instr_type, real_units);
}

AcquisitionContextHandle AcquisitionContext_create_from_port(
    InstrumentPortHandle port) {
  if (!port) {
    throw std::invalid_argument(
        "AcquisitionContext_create_from_port: port handle cannot be null");
  }
  instrument_interfaces::names::InstrumentPortSP real_port =
      std::make_shared<instrument_interfaces::names::InstrumentPort>(
          *static_cast<instrument_interfaces::names::InstrumentPort*>(port));
  return new AcquisitionContext(real_port);
}

void AcquisitionContext_destroy(AcquisitionContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_destroy: handle cannot be null");
  }
  delete static_cast<AcquisitionContext*>(handle);
}

ConnectionHandle AcquisitionContext_connection(
    AcquisitionContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_connection: handle cannot be null");
  }
  AcquisitionContext self = *static_cast<AcquisitionContext*>(handle);
  return new physics::device_structures::Connection(*(self.connection()));
}

StringHandle AcquisitionContext_instrument_type(
    AcquisitionContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_instrument_type: handle cannot be null");
  }
  AcquisitionContext self = *static_cast<AcquisitionContext*>(handle);
  return String_create(self.instrument_type().c_str(),
                       self.instrument_type().size());
}

SymbolUnitHandle AcquisitionContext_units(AcquisitionContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_units: handle cannot be null");
  }
  AcquisitionContext self = *static_cast<AcquisitionContext*>(handle);
  return new physics::units::SymbolUnit(*(self.units()));
}

AcquisitionContextHandle AcquisitionContext_division_unit(
    AcquisitionContextHandle handle, SymbolUnitHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_division_unit: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_division_unit: other handle cannot be null");
  }
  AcquisitionContext           self = *static_cast<AcquisitionContext*>(handle);
  physics::units::SymbolUnitSP other_unit =
      std::make_shared<physics::units::SymbolUnit>(
          *static_cast<physics::units::SymbolUnit*>(other));
  return new AcquisitionContext(*(self / other_unit));
}

AcquisitionContextHandle AcquisitionContext_division(
    AcquisitionContextHandle handle, AcquisitionContextHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_division: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_division: other handle cannot be null");
  }
  AcquisitionContext   self = *static_cast<AcquisitionContext*>(handle);
  AcquisitionContextSP octx = std::make_shared<AcquisitionContext>(
      *static_cast<AcquisitionContext*>(other));
  return new AcquisitionContext(*(self / octx));
}

bool AcquisitionContext_match_connection(AcquisitionContextHandle handle,
                                         ConnectionHandle         other) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_match_connection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_match_connection: other handle cannot be null");
  }
  AcquisitionContext self = *static_cast<AcquisitionContext*>(handle);
  physics::device_structures::ConnectionSP oconn =
      std::make_shared<physics::device_structures::Connection>(
          *static_cast<physics::device_structures::Connection*>(other));
  return self.match_connection(oconn);
}

bool AcquisitionContext_match_instrument_type(AcquisitionContextHandle handle,
                                              StringHandle             other) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_match_instrument_type: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "AcquisitionContext_match_instrument_type: other handle cannot be "
        "null");
  }
  AcquisitionContext self        = *static_cast<AcquisitionContext*>(handle);
  std::string        oinstr_type = std::string(other->raw, other->length);
  return self.match_instrument_type(oinstr_type);
}

bool AcquisitionContext_equal(AcquisitionContextHandle a,
                              AcquisitionContextHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "AcquisitionContext_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "AcquisitionContext_equal: handle b cannot be null");
  }
  return *(static_cast<AcquisitionContext*>(a)) ==
         *(static_cast<AcquisitionContext*>(b));
}

bool AcquisitionContext_not_equal(AcquisitionContextHandle a,
                                  AcquisitionContextHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "AcquisitionContext_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "AcquisitionContext_not_equal: handle b cannot be null");
  }
  return *(static_cast<AcquisitionContext*>(a)) !=
         *(static_cast<AcquisitionContext*>(b));
}

StringHandle AcquisitionContext_to_json_string(
    AcquisitionContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "AcquisitionContext_to_json_string: handle cannot be null");
  }
  AcquisitionContext self = *static_cast<AcquisitionContext*>(handle);
  std::string        json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

AcquisitionContextHandle AcquisitionContext_from_json_string(
    const StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "AcquisitionContext_from_json_string: json cannot be null");
  }
  std::string          raw_json(json->raw);
  AcquisitionContextSP context =
      AcquisitionContext::from_json_string<AcquisitionContext>(raw_json);
  return new AcquisitionContext(*context);
}
