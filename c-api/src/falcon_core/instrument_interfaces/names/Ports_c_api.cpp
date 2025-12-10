#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"

#include <falcon_core/instrument_interfaces/names/Ports.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::instrument_interfaces::names;

extern "C" {
DEFINE_C_API_COPY(Ports);
DEFINE_C_API_DESTROY(Ports);
DEFINE_C_API_EQUAL(Ports);
DEFINE_C_API_NOT_EQUAL(Ports);
DEFINE_C_API_TO_JSON(Ports);
DEFINE_C_API_FROM_JSON(Ports);
PortsHandle Ports_create_empty() {
  FALCON_C_API_BEGIN
  return new PortsSP(std::make_shared<Ports>());
  FALCON_C_API_END(nullptr)
}

PortsHandle Ports_create(ListInstrumentPortHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument("Ports_create: items cannot be null");
  }
  falcon_core::generic::ListSP<InstrumentPort> item_list =
      *static_cast<falcon_core::generic::ListSP<InstrumentPort>*>(items);
  return new PortsSP(std::make_shared<Ports>(item_list->items()));
  FALCON_C_API_END(nullptr)
}

ListInstrumentPortHandle Ports_ports(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_ports: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return new falcon_core::generic::ListSP<InstrumentPort>(
      std::make_shared<falcon_core::generic::List<InstrumentPort>>(
          self->ports()->items()));
  FALCON_C_API_END(nullptr)
}

ListStringHandle Ports_default_names(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_default_names: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::generic::ListSP<std::string> names = self->get_default_names();
  return new falcon_core::generic::ListSP<std::string>(
      std::make_shared<falcon_core::generic::List<std::string>>(
          names->items()));
  FALCON_C_API_END(nullptr)
}

ListConnectionHandle Ports_get_psuedo_names(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Ports_get_psuedo_names: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::generic::ListSP<
      falcon_core::physics::device_structures::Connection>
      names = self->get_pseudo_names();
  return new falcon_core::generic::ListSP<
      falcon_core::physics::device_structures::Connection>(
      std::make_shared<falcon_core::generic::List<
          falcon_core::physics::device_structures::Connection>>(
          names->items()));
  FALCON_C_API_END(nullptr)
}

ListStringHandle Ports__get_raw_names(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports__get_raw_names: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return new falcon_core::generic::ListSP<std::string>(
      std::make_shared<falcon_core::generic::List<std::string>>(
          self->_get_raw_names()->items()));
  FALCON_C_API_END(nullptr)
}

ListStringHandle Ports__get_instrument_facing_names(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Ports__get_instrument_facing_names: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return new falcon_core::generic::ListSP<std::string>(
      std::make_shared<falcon_core::generic::List<std::string>>(
          self->_get_instrument_facing_names()->items()));
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle Ports__get_psuedoname_matching_port(
    PortsHandle handle, ConnectionHandle name) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Ports__get_psuedoname_matching_port: handle cannot be null");
  }
  if (!name) {
    throw std::invalid_argument(
        "Ports__get_psuedoname_matching_port: name cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_name =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          name);
  return new InstrumentPortSP(self->_get_psuedoname_matching_port(real_name));
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle Ports__get_instrument_type_matching_port(
    PortsHandle handle, StringHandle type) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Ports__get_instrument_type_matching_port: handle cannot be null");
  }
  if (!type) {
    throw std::invalid_argument(
        "Ports__get_instrument_type_matching_port: type cannot be null");
  }
  PortsSP     self = *static_cast<PortsSP*>(handle);
  std::string real_type(type->raw, type->length);
  return new InstrumentPortSP(
      self->_get_instrument_type_matching_port(real_type));
  FALCON_C_API_END(nullptr)
}

bool Ports_is_knobs(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_is_knobs: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return self->is_knobs();
  FALCON_C_API_END(false)
}

bool Ports_is_meters(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_is_meters: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return self->is_meters();
  FALCON_C_API_END(false)
}

PortsHandle Ports_intersection(PortsHandle handle, PortsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Ports_intersection: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Ports_intersection: second handle cannot be null");
  }
  PortsSP self       = *static_cast<PortsSP*>(handle);
  PortsSP real_other = *static_cast<PortsSP*>(other);
  PortsSP result     = std::make_shared<Ports>(self->intersection(real_other));
  return new PortsSP(result);
  FALCON_C_API_END(nullptr)
}

void Ports_push_back(PortsHandle handle, InstrumentPortHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Ports_push_back: value cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_value =
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(value);
  self->push_back(real_value);
  FALCON_C_API_END()
}

size_t Ports_size(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_size: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool Ports_empty(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_empty: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void Ports_erase_at(PortsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_erase_at: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void Ports_clear(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_clear: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  self->clear();
  FALCON_C_API_END()
}

InstrumentPortHandle Ports_at(PortsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_at: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  return new InstrumentPort(*self->at(idx));
  FALCON_C_API_END(nullptr)
}

ListStringHandle Ports_items(PortsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_items: handle cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::generic::ListSP<std::string> list_of_strings =
      std::make_shared<falcon_core::generic::List<std::string>>();
  for (const auto& port : self->items()) {
    std::string name = port->default_name();
    list_of_strings->push_back(name);
  }
  return new falcon_core::generic::ListSP<std::string>(
      std::make_shared<falcon_core::generic::List<std::string>>(
          list_of_strings->items()));
  FALCON_C_API_END(nullptr)
}

bool Ports_contains(PortsHandle handle, InstrumentPortHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Ports_contains: value cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_value =
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(value);
  return self->contains(real_value);
  FALCON_C_API_END(false)
}

size_t Ports_index(PortsHandle handle, InstrumentPortHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Ports_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Ports_index: value cannot be null");
  }
  PortsSP self = *static_cast<PortsSP*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_value =
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(value);
  return self->index(real_value);
  FALCON_C_API_END(0)
}
}
