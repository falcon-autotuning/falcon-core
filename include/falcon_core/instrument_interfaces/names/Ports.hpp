#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core::instrument_interfaces::names {

// Generic collection of instrument ports
class Ports : public generic::List<InstrumentPort> {
 public:
  Ports();
  /**
   * @brief Initialize ports from a collection of port.
   */
  Ports(const std::vector<InstrumentPortSP> ports);
  /**
   * @brief Initialize ports from a collection of port.
   */
  Ports(const generic::ListSP<InstrumentPort> ports);
  /**
   * @brief return the collection of ports.
   */
  generic::ListSP<InstrumentPort> ports() const;
  /**
   * @brief Return the default names of the ports.
   */
  generic::ListSP<std::string> get_default_names() const;
  /**
   * @brief Return the pseudo names of the ports.
   * @throws std::runtime_error if any port does not have a pseudo name.
   */
  generic::ListSP<physics::device_structures::Connection> get_pseudo_names()
      const;
  /**
   * @brief Return the raw string names of the ports.
   */
  generic::ListSP<std::string> _get_raw_names() const;
  /**
   * @brief Gets a llist of names to satisfy an instrument interface.
   */
  generic::ListSP<std::string> _get_instrument_facing_names() const;
  /**
   * @brief Check if any port has the given pseudo name.
   * @param name The pseudo name to check for.
   * @return The port with the given name
   * @throws std::runtime_error if no port has the given name.
   */
  InstrumentPortSP _get_psuedoname_matching_port(
      const physics::device_structures::ConnectionSP& name) const;
  /**
   * @brief Check if any port has the given instrument type.
   * @param type The instrument type to check for.
   * @return The port with the given instrument type.
   * @throws std::runtime_error if no port has the given type.
   */
  InstrumentPortSP _get_instrument_type_matching_port(
      const Instrument& type) const;
  /**
   * @brief Check if the ports contains only knobs.
   * @return True if the ports only contain knobs.
   */
  const bool is_knobs() const;
  /**
   * @brief Check if the ports contains only meters.
   * @return True if the ports only contain meters.
   */
  const bool is_meters() const;
  bool       operator==(const Ports& other) const;
  bool       operator!=(const Ports& other) const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<InstrumentPort>>(this));
  }
};
using PortsSP = std::shared_ptr<Ports>;
}  // namespace falcon_core::instrument_interfaces::names
