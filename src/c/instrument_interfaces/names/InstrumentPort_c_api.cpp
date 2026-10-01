#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"

#include <falcon-core/instrument_interfaces/names/InstrumentPort.hpp>

#include "falcon-core/CerealMacro_c_api.h"
#include "falcon-core/Precompiled_c_api.h"

namespace fin = falcon_core::instrument_interfaces::names;

extern "C" {
DEFINE_C_API_COPY_TEMPLATE(InstrumentPort, fin::InstrumentPort);
DEFINE_C_API_DESTROY_TEMPLATE(InstrumentPort, fin::InstrumentPort);
DEFINE_C_API_EQUAL_TEMPLATE(InstrumentPort, fin::InstrumentPort);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(InstrumentPort, fin::InstrumentPort);
DEFINE_C_API_TO_JSON_TEMPLATE(InstrumentPort, fin::InstrumentPort);
DEFINE_C_API_FROM_JSON_TEMPLATE(InstrumentPort, fin::InstrumentPort);
InstrumentPortHandle InstrumentPort_create_port(
    StringHandle default_name, StringHandle instrument_name, Scope scope,
    Access access, InstrumentCharacteristic characteristic, PortType type,
    ConnectionHandle pseudo_name, Instrument instrument_type,
    SymbolUnitHandle units, StringHandle description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: default_name cannot be null");
  }
  if (!instrument_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_setting: instrument_name cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_port: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_pseudo_name =
      nullptr;
  if (pseudo_name) {
    real_pseudo_name =
        *static_cast<falcon_core::physics::device_structures::ConnectionSP *>(
            pseudo_name);
  }
  return new fin::InstrumentPortSP(std::make_shared<fin::InstrumentPort>(
      std::string(default_name->raw, default_name->length),
      std::string(instrument_name->raw, instrument_name->length),
      static_cast<fin::Scope>(scope), static_cast<fin::Access>(access),
      static_cast<fin::InstrumentCharacteristic>(characteristic),
      static_cast<fin::PortType>(type), real_pseudo_name,
      static_cast<fin::Instrument>(instrument_type),
      *static_cast<falcon_core::physics::units::SymbolUnitSP *>(units),
      std::string(description->raw, description->length)));
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle InstrumentPort_create_setting(
    StringHandle default_name, StringHandle instrument_name, Scope scope,
    Access access, InstrumentCharacteristic characteristic,
    ConnectionHandle pseudo_name, Instrument instrument_type,
    SymbolUnitHandle units, StringHandle description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_setting: default_name cannot be null");
  }
  if (!instrument_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_setting: instrument_name cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_setting: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_setting: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_pseudo_name =
      nullptr;
  if (pseudo_name) {
    real_pseudo_name =
        *static_cast<falcon_core::physics::device_structures::ConnectionSP *>(
            pseudo_name);
  }
  return new fin::InstrumentPortSP(fin::InstrumentPort::Setting(
      std::string(default_name->raw, default_name->length),
      std::string(instrument_name->raw, instrument_name->length),
      fin::Scope(scope), fin::Access(access),
      fin::InstrumentCharacteristic(characteristic), real_pseudo_name,
      static_cast<fin::Instrument>(instrument_type),
      *static_cast<falcon_core::physics::units::SymbolUnitSP *>(units),
      std::string(description->raw, description->length)));
  FALCON_C_API_END(nullptr)
}
InstrumentPortHandle InstrumentPort_create_knob(StringHandle default_name,
                                                StringHandle instrument_name,
                                                ConnectionHandle pseudo_name,
                                                Instrument instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: default_name cannot be null");
  }
  if (!instrument_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: instrument_name cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_knob: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_pseudo_name =
      nullptr;
  if (pseudo_name) {
    real_pseudo_name =
        *static_cast<falcon_core::physics::device_structures::ConnectionSP *>(
            pseudo_name);
  }
  return new fin::InstrumentPortSP(fin::InstrumentPort::Knob(
      std::string(default_name->raw, default_name->length),
      std::string(instrument_name->raw, instrument_name->length),
      real_pseudo_name, static_cast<fin::Instrument>(instrument_type),
      *static_cast<falcon_core::physics::units::SymbolUnitSP *>(units),
      std::string(description->raw, description->length)));
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle InstrumentPort_create_meter(StringHandle default_name,
                                                 StringHandle instrument_name,
                                                 ConnectionHandle pseudo_name,
                                                 Instrument instrument_type,
                                                 SymbolUnitHandle units,
                                                 StringHandle description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: default_name cannot be null");
  }
  if (!instrument_name) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: instrument_name cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "InstrumentPort_create_meter: description cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP real_pseudo_name =
      nullptr;
  if (pseudo_name) {
    real_pseudo_name =
        *static_cast<falcon_core::physics::device_structures::ConnectionSP *>(
            pseudo_name);
  }
  return new fin::InstrumentPortSP(fin::InstrumentPort::Meter(
      std::string(default_name->raw, default_name->length),
      std::string(instrument_name->raw, instrument_name->length),
      real_pseudo_name, static_cast<fin::Instrument>(instrument_type),
      *static_cast<falcon_core::physics::units::SymbolUnitSP *>(units),
      std::string(description->raw, description->length)));
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle InstrumentPort_create_timer() {
  FALCON_C_API_BEGIN
  return new fin::InstrumentPortSP(fin::InstrumentPort::Timer());
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle InstrumentPort_create_execution_clock() {
  FALCON_C_API_BEGIN
  return new fin::InstrumentPortSP(fin::InstrumentPort::ExecutionClock());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentPort_default_name(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_default_name: handle cannot be null");
  }
  std::string name =
      (*static_cast<fin::InstrumentPortSP *>(handle))->default_name();
  return String_create(name.c_str(), name.size());
  FALCON_C_API_END(nullptr)
}
StringHandle InstrumentPort_instrument_name(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_instrument_name: handle cannot be null");
  }
  std::string name =
      (*static_cast<fin::InstrumentPortSP *>(handle))->instrument_name();
  return String_create(name.c_str(), name.size());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle InstrumentPort_pseudo_name(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_pseudo_name: handle cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionSP pseudo_name =
      (*static_cast<fin::InstrumentPortSP *>(handle))->pseudo_name();
  return new falcon_core::physics::device_structures::ConnectionSP(pseudo_name);
  FALCON_C_API_END(nullptr)
}

Instrument InstrumentPort_instrument_type(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_instrument_type: handle cannot be null");
  }

  return static_cast<Instrument>(
      (*static_cast<fin::InstrumentPortSP *>(handle))->instrument_type());

  FALCON_C_API_END(INSTRUMENT_DC_VOLTAGE_SOURCE)
}
Scope InstrumentPort_scope(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument("InstrumentPort_scope: handle cannot be null");
  }

  return static_cast<Scope>(
      (*static_cast<fin::InstrumentPortSP *>(handle))->scope());

  FALCON_C_API_END(SCOPE_LOCAL)
}
Access InstrumentPort_access(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument("InstrumentPort_access: handle cannot be null");
  }

  return static_cast<Access>(
      (*static_cast<fin::InstrumentPortSP *>(handle))->access());

  FALCON_C_API_END(ACCESS_READWRITE)
}

InstrumentCharacteristic
InstrumentPort_characteristic(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_characteristic: handle cannot be null");
  }

  return static_cast<InstrumentCharacteristic>(
      (*static_cast<fin::InstrumentPortSP *>(handle))->characteristic());

  FALCON_C_API_END(INSTRUMENT_CHARACTERISTIC_NONE)
}

SymbolUnitHandle InstrumentPort_units(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("InstrumentPort_units: handle cannot be null");
  }
  falcon_core::physics::units::SymbolUnitSP units =
      (*static_cast<fin::InstrumentPortSP *>(handle))->units();
  return new falcon_core::physics::units::SymbolUnitSP(units);
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentPort_description(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_description: handle cannot be null");
  }
  std::string description =
      (*static_cast<fin::InstrumentPortSP *>(handle))->description();
  return String_create(description.c_str(), description.size());
  FALCON_C_API_END(nullptr)
}

StringHandle
InstrumentPort_instrument_facing_name(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_instrument_facing_name: handle cannot be null");
  }
  std::string name =
      (*static_cast<fin::InstrumentPortSP *>(handle))->instrument_facing_name();
  return String_create(name.c_str(), name.size());
  FALCON_C_API_END(nullptr)
}
PortType InstrumentPort_type(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument("InstrumentPort_type: handle cannot be null");
  }

  return static_cast<PortType>(
      (*static_cast<fin::InstrumentPortSP *>(handle))->type());

  FALCON_C_API_END(PortType::PORT_TYPE_SETTING)
}

bool InstrumentPort_is_knob(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_is_knob: handle cannot be null");
  }
  return (*static_cast<fin::InstrumentPortSP *>(handle))->is_knob();
  FALCON_C_API_END(false)
}

bool InstrumentPort_is_meter(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_is_meter: handle cannot be null");
  }
  return (*static_cast<fin::InstrumentPortSP *>(handle))->is_meter();
  FALCON_C_API_END(false)
}

bool InstrumentPort_is_setting(InstrumentPortHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument(
        "InstrumentPort_is_setting: handle cannot be null");
  }

  return (*static_cast<fin::InstrumentPortSP *>(handle))->is_setting();

  FALCON_C_API_END(false)
}
}
