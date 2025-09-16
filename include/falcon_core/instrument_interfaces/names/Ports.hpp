#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core::instrument_interfaces::names {

// Generic collection of instrument ports
template <typename Port>
class Ports : public generic::List<Port> {
  static_assert(std::is_base_of<InstrumentPort, Port>::value,
                "Port must be derived from InstrumentPort");

 public:
  Ports() = default;
  /**
   * @brief Initialize ports from a collection of port.
   */
  Ports(const std::vector<typename generic::List<Port>::StoredValue> ports)
      : generic::List<Port>(ports) {}
  /**
   * @brief return the collection of ports.
   */
  generic::ListSP<Port> ports() const {
    return std::make_shared<generic::List<Port>>(this->items());
  }
  /**
   * @brief Return the default names of the ports.
   */
  generic::ListSP<std::string> get_default_names() const {
    generic::ListSP<std::string> result;
    for (const auto& port : this->items()) {
      result->push_back(port->default_name());
    }
    return result;
  }
  /**
   * @brief Return the pseudo names of the ports.
   * @throws std::runtime_error if any port does not have a pseudo name.
   */
  generic::ListSP<physics::device_structures::BaseConnectionSP>
  get_pseudo_names() const {
    generic::ListSP<physics::device_structures::BaseConnectionSP> result;
    for (const auto& port : this->items()) {
      if (!port->pseudo_name()) {
        throw std::runtime_error("Port does not have a pseudo name");
      }
      result->push_back(port->pseudo_name());
    }
    return result;
  }
  /**
   * @brief Return the raw string names of the ports.
   */
  generic::ListSP<std::string> _get_raw_names() const {
    generic::ListSP<std::string> result;
    for (const physics::device_structures::BaseConnectionSP& port :
         *get_pseudo_names()) {
      result->push_back(port->name());
    }
    return result;
  }
  /**
   * @brief Gets a llist of names to satisfy an instrument interface.
   */
  generic::ListSP<std::string> _get_instrument_facing_names() const {
    generic::ListSP<std::string> result;
    for (const typename generic::List<Port>::StoredValue& port :
         this->items()) {
      result->push_back(port->instrument_facing_name());
    }
    return result;
  }
  /**
   * @brief Check if any port has the given pseudo name.
   * @param name The pseudo name to check for.
   * @return The port with the given name
   * @throws std::runtime_error if no port has the given name.
   */
  typename generic::List<Port>::StoredValue _get_psuedoname_matching_port(
      const physics::device_structures::BaseConnectionSP& name) const {
    for (const typename generic::List<Port>::StoredValue& port :
         this->items()) {
      if (port->pseudo_name() && *(port->pseudo_name()) == *name) {
        return port;
      }
    }
    std::ostringstream oss;
    oss << "No port found matching pseudo name: " << name->name();
    throw std::runtime_error(oss.str());
  }
  /**
   * @brief Check if any port has the given instrument type.
   * @param type The instrument type to check for.
   * @return The port with the given instrument type.
   * @throws std::runtime_error if no port has the given type.
   */
  typename generic::List<Port>::StoredValue _get_instrument_type_matching_port(
      const Instrument& type) const {
    for (const typename generic::List<Port>::StoredValue& port :
         this->items()) {
      if (port->instrument_type() == type) {
        return port;
      }
    }
    std::ostringstream oss;
    oss << "No port found matching instrument type: " << type;
    throw std::runtime_error(oss.str());
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<Port>>(this));
  }
};
template <typename T>
using PortsSP = std::shared_ptr<Ports<T>>;
}  // namespace falcon_core::instrument_interfaces::names
