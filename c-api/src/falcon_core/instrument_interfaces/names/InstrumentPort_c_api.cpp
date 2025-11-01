#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"

#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::instrument_interfaces::names;

InstrumentPortHandle InstrumentPort_create_port(StringHandle     default_name,
                                                ConnectionHandle psuedo_name,
                                                StringHandle instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle     description) {
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: default_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: instrument_type cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_psuedo_name =
      nullptr;
  if (psuedo_name) {
    real_psuedo_name =
        std::make_shared<falcon_core::physics::device_structures::Connection>(
            *static_cast<falcon_core::physics::device_structures::Connection*>(
                psuedo_name));
  }
  return new InstrumentPort(
      std::string(default_name->raw, default_name->length),
      real_psuedo_name,
      std::string(instrument_type->raw, instrument_type->length),
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          *static_cast<falcon_core::physics::units::SymbolUnit*>(units)),
      std::string(description->raw, description->length),
      PortType::InstrumentPort);
}

InstrumentPortHandle InstrumentPort_create_knob(StringHandle     default_name,
                                                ConnectionHandle psuedo_name,
                                                StringHandle instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle     description) {
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: default_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: instrument_type cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_psuedo_name =
      nullptr;
  if (psuedo_name) {
    real_psuedo_name =
        std::make_shared<falcon_core::physics::device_structures::Connection>(
            *static_cast<falcon_core::physics::device_structures::Connection*>(
                psuedo_name));
  }
  return InstrumentPort::Knob(
             std::string(default_name->raw, default_name->length),
             real_psuedo_name,
             std::string(instrument_type->raw, instrument_type->length),
             std::make_shared<falcon_core::physics::units::SymbolUnit>(
                 *static_cast<falcon_core::physics::units::SymbolUnit*>(units)),
             std::string(description->raw, description->length))
      .get();
}

InstrumentPortHandle InstrumentPort_create_meter(StringHandle     default_name,
                                                 ConnectionHandle psuedo_name,
                                                 StringHandle instrument_type,
                                                 SymbolUnitHandle units,
                                                 StringHandle     description) {
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: default_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: instrument_type cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_psuedo_name =
      nullptr;
  if (psuedo_name) {
    real_psuedo_name =
        std::make_shared<falcon_core::physics::device_structures::Connection>(
            *static_cast<falcon_core::physics::device_structures::Connection*>(
                psuedo_name));
  }
  return InstrumentPort::Meter(
             std::string(default_name->raw, default_name->length),
             real_psuedo_name,
             std::string(instrument_type->raw, instrument_type->length),
             std::make_shared<falcon_core::physics::units::SymbolUnit>(
                 *static_cast<falcon_core::physics::units::SymbolUnit*>(units)),
             std::string(description->raw, description->length))
      .get();
}

InstrumentPortHandle InstrumentPort_create_timer() {
  return InstrumentPort::Timer().get();
}

InstrumentPortHandle InstrumentPort_create_execution_clock() {
  return InstrumentPort::ExecutionClock().get();
}

void InstrumentPort_destroy(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_destroy: handle cannot be null");
  }
  delete static_cast<InstrumentPort*>(handle);
}

StringHandle InstrumentPort_default_name(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_default_name: handle cannot be null");
  }
  std::string name = static_cast<InstrumentPort*>(handle)->default_name();
  return String_create(name.c_str(), name.size());
}

ConnectionHandle InstrumentPort_psuedo_name(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_psuedo_name: handle cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP psuedo_name =
      static_cast<InstrumentPort*>(handle)->pseudo_name();
  if (!psuedo_name) {
    return nullptr;
  }
  return new falcon_core::physics::device_structures::Connection(*psuedo_name);
}

StringHandle InstrumentPort_instrument_type(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_instrument_type: handle cannot be null");
  }
  std::string type = static_cast<InstrumentPort*>(handle)->instrument_type();
  return String_create(type.c_str(), type.size());
}

SymbolUnitHandle InstrumentPort_units(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument("InstrumentPort_units: handle cannot be null");
  }
  falcon_core::physics::units::SymbolUnitSP units =
      static_cast<InstrumentPort*>(handle)->units();
  return new falcon_core::physics::units::SymbolUnit(*units);
}

StringHandle InstrumentPort_description(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_description: handle cannot be null");
  }
  std::string description = static_cast<InstrumentPort*>(handle)->description();
  return String_create(description.c_str(), description.size());
}

StringHandle InstrumentPort_instrument_facing_name(
    InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_instrument_facing_name: handle cannot be null");
  }
  std::string name =
      static_cast<InstrumentPort*>(handle)->instrument_facing_name();
  return String_create(name.c_str(), name.size());
}

bool InstrumentPort_is_knob(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_is_knob: handle cannot be null");
  }
  return static_cast<InstrumentPort*>(handle)->is_knob();
}

bool InstrumentPort_is_meter(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_is_meter: handle cannot be null");
  }
  return static_cast<InstrumentPort*>(handle)->is_meter();
}

bool InstrumentPort_is_port(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_is_port: handle cannot be null");
  }
  return static_cast<InstrumentPort*>(handle)->is_port();
}

bool InstrumentPort_equal(InstrumentPortHandle handle,
                          InstrumentPortHandle other) {
  if (!handle) {
    throw std::invalid_argument("InstrumentPort_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("InstrumentPort_equal: other cannot be null");
  }
  return *(static_cast<InstrumentPort*>(handle)) ==
         *(static_cast<InstrumentPort*>(other));
}

bool InstrumentPort_not_equal(InstrumentPortHandle handle,
                              InstrumentPortHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "InstrumentPort_not_equal: other cannot be null");
  }
  return *(static_cast<InstrumentPort*>(handle)) !=
         *(static_cast<InstrumentPort*>(other));
}

StringHandle InstrumentPort_to_json_string(InstrumentPortHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<InstrumentPort*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

InstrumentPortHandle InstrumentPort_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "InstrumentPort_from_json_string: json cannot be null");
  }
  auto ptr = InstrumentPort::from_json_string<InstrumentPort>(json->raw);
  return ptr.get();
}
