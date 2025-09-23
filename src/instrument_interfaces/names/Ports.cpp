#include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core::instrument_interfaces::names {

Ports::Ports() : generic::List<InstrumentPort>() {}
Ports::Ports(const std::vector<std::shared_ptr<InstrumentPort>> ports)
    : generic::List<InstrumentPort>(ports) {}
Ports::Ports(const generic::ListSP<InstrumentPort> ports)
    : generic::List<InstrumentPort>(*ports) {}
generic::ListSP<InstrumentPort> Ports::ports() const {
  return std::make_shared<generic::List<InstrumentPort>>(this->items());
}
generic::ListSP<std::string> Ports::get_default_names() const {
  generic::ListSP<std::string> result;
  for (const auto& port : this->items()) {
    result->push_back(port->default_name());
  }
  return result;
}
generic::ListSP<physics::device_structures::Connection>
Ports::get_pseudo_names() const {
  generic::ListSP<physics::device_structures::Connection> result;
  for (const auto& port : this->items()) {
    if (!port->pseudo_name()) {
      throw std::runtime_error("Port does not have a pseudo name");
    }
    result->push_back(port->pseudo_name());
  }
  return result;
}
generic::ListSP<std::string> Ports::_get_raw_names() const {
  generic::ListSP<std::string> result;
  for (const physics::device_structures::ConnectionSP& port :
       *get_pseudo_names()) {
    result->push_back(port->name());
  }
  return result;
}
generic::ListSP<std::string> Ports::_get_instrument_facing_names() const {
  generic::ListSP<std::string> result;
  for (const typename generic::List<InstrumentPort>::StoredValue& port :
       this->items()) {
    result->push_back(port->instrument_facing_name());
  }
  return result;
}
InstrumentPortSP Ports::_get_psuedoname_matching_port(
    const physics::device_structures::ConnectionSP& name) const {
  for (const typename generic::List<InstrumentPort>::StoredValue& port :
       this->items()) {
    if (port->pseudo_name() && *(port->pseudo_name()) == *name) {
      return port;
    }
  }
  std::ostringstream oss;
  oss << "No port found matching pseudo name: " << name->name();
  throw std::runtime_error(oss.str());
}
InstrumentPortSP Ports::_get_instrument_type_matching_port(
    const Instrument& type) const {
  for (const typename generic::List<InstrumentPort>::StoredValue& port :
       this->items()) {
    if (port->instrument_type() == type) {
      return port;
    }
  }
  std::ostringstream oss;
  oss << "No port found matching instrument type: " << type;
  throw std::runtime_error(oss.str());
}
const bool Ports::is_knobs() const {
  for (const InstrumentPortSP& port : items()) {
    if (!port->is_knob()) {
      return false;
    }
  }
  return true;
}
const bool Ports::is_meters() const {
  for (const InstrumentPortSP& port : items()) {
    if (!port->is_meter()) {
      return false;
    }
  }
  return true;
}

}  // namespace falcon_core::instrument_interfaces::names
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Ports)
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::instrument_interfaces::names::InstrumentPort>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::names::InstrumentPort>,
    falcon_core::instrument_interfaces::names::Ports)
