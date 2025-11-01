#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"

#include <falcon_core/instrument_interfaces/names/Ports.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::instrument_interfaces::names;

PortsHandle Ports_create_empty() { return new Ports(Ports()); }

PortsHandle Ports_create(ListInstrumentPortHandle items) {
  if (!items) {
    throw std::invalid_argument("Ports_create: items cannot be null");
  }
  falcon_core::generic::ListSP<InstrumentPort> item_list =
      std::make_shared<falcon_core::generic::List<InstrumentPort>>(
          *static_cast<falcon_core::generic::List<InstrumentPort>*>(items));
  return new Ports(item_list->items());
}

void Ports_destroy(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_destroy: handle cannot be null");
  }
  delete static_cast<Ports*>(handle);
}

ListInstrumentPortHandle Ports_ports(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_ports: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return new falcon_core::generic::List<InstrumentPort>(self.ports()->items());
}

ListStringHandle Ports_default_names(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_default_names: handle cannot be null");
  }
  Ports                                     self = *static_cast<Ports*>(handle);
  falcon_core::generic::ListSP<std::string> names = self.get_default_names();
  return new falcon_core::generic::List<std::string>(names->items());
}

ListConnectionHandle Ports_get_psuedo_names(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Ports_get_psuedo_names: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  falcon_core::generic::ListSP<
      falcon_core::physics::device_structures::Connection>
      names = self.get_pseudo_names();
  return new falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>(names->items());
}

ListStringHandle Ports__get_raw_names(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports__get_raw_names: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return new falcon_core::generic::List<std::string>(
      self._get_raw_names()->items());
}

ListStringHandle Ports__get_instrument_facing_names(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Ports__get_instrument_facing_names: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return new falcon_core::generic::List<std::string>(
      self._get_instrument_facing_names()->items());
}

InstrumentPortHandle Ports__get_psuedoname_matching_port(
    PortsHandle handle, ConnectionHandle name) {
  if (!handle) {
    throw std::invalid_argument(
        "Ports__get_psuedoname_matching_port: handle cannot be null");
  }
  if (!name) {
    throw std::invalid_argument(
        "Ports__get_psuedoname_matching_port: name cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_name =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              name));
  return new InstrumentPort(*self._get_psuedoname_matching_port(real_name));
}

InstrumentPortHandle Ports__get_instrument_type_matching_port(
    PortsHandle handle, StringHandle type) {
  if (!handle) {
    throw std::invalid_argument(
        "Ports__get_instrument_type_matching_port: handle cannot be null");
  }
  if (!type) {
    throw std::invalid_argument(
        "Ports__get_instrument_type_matching_port: type cannot be null");
  }
  Ports       self = *static_cast<Ports*>(handle);
  std::string real_type(type->raw, type->length);
  return new InstrumentPort(
      *self._get_instrument_type_matching_port(real_type));
}

bool Ports_is_knobs(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_is_knobs: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return self.is_knobs();
}

bool Ports_is_meters(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_is_meters: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return self.is_meters();
}

PortsHandle Ports_intersection(PortsHandle handle, PortsHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Ports_intersection: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Ports_intersection: second handle cannot be null");
  }
  Ports   self       = *static_cast<Ports*>(handle);
  PortsSP real_other = std::make_shared<Ports>(*static_cast<Ports*>(other));
  Ports   result     = self.intersection(real_other);
  return new Ports(result);
}

void Ports_push_back(PortsHandle handle, InstrumentPortHandle value) {
  if (!handle) {
    throw std::invalid_argument("Ports_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Ports_push_back: value cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_value =
      std::make_shared<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          *static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(
              value));
  self.push_back(real_value);
}

size_t Ports_size(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_size: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return self.size();
}

bool Ports_empty(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_empty: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return self.empty();
}

void Ports_erase_at(PortsHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("Ports_erase_at: handle cannot be null");
  }
  Ports* self = static_cast<Ports*>(handle);
  self->erase_at(idx);
}

void Ports_clear(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_clear: handle cannot be null");
  }
  Ports* self = static_cast<Ports*>(handle);
  self->clear();
}

const InstrumentPortHandle Ports_const_at(PortsHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("Ports_const_at: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return new InstrumentPort(*self.at(idx));
}

InstrumentPortHandle Ports_at(PortsHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("Ports_at: handle cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  return new InstrumentPort(*self.at(idx));
}

ListStringHandle Ports_items(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_items: handle cannot be null");
  }
  Ports                                     self = *static_cast<Ports*>(handle);
  falcon_core::generic::ListSP<std::string> list_of_strings =
      std::make_shared<falcon_core::generic::List<std::string>>();
  for (const auto& port : self.items()) {
    std::string name = port->default_name();
    list_of_strings->push_back(name);
  }
  return new falcon_core::generic::List<std::string>(list_of_strings->items());
}

bool Ports_contains(PortsHandle handle, InstrumentPortHandle value) {
  if (!handle) {
    throw std::invalid_argument("Ports_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Ports_contains: value cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_value =
      std::make_shared<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          *static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(
              value));
  return self.contains(real_value);
}

size_t Ports_index(PortsHandle handle, InstrumentPortHandle value) {
  if (!handle) {
    throw std::invalid_argument("Ports_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Ports_index: value cannot be null");
  }
  Ports self = *static_cast<Ports*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_value =
      std::make_shared<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          *static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(
              value));
  return self.index(real_value);
}

bool Ports_equal(PortsHandle a, PortsHandle b) {
  if (!a) {
    throw std::invalid_argument("Ports_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Ports_equal: b cannot be null");
  }
  Ports self_a = *static_cast<Ports*>(a);
  Ports self_b = *static_cast<Ports*>(b);
  return self_a == self_b;
}

bool Ports_not_equal(PortsHandle a, PortsHandle b) {
  if (!a) {
    throw std::invalid_argument("Ports_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Ports_not_equal: b cannot be null");
  }
  Ports self_a = *static_cast<Ports*>(a);
  Ports self_b = *static_cast<Ports*>(b);
  return self_a != self_b;
}

StringHandle Ports_to_json_string(PortsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Ports_to_json_string: handle cannot be null");
  }
  Ports       self = *static_cast<Ports*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

PortsHandle Ports_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument("Ports_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw, json->length);
  return new Ports(
      *falcon_core::instrument_interfaces::names::Ports::from_json_string<
          Ports>(json_str));
}
