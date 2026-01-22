/**
 * @file BaseLabelledDomain.hpp
 * @brief Defines the BaseLabelledDomain template for FalconCore.
 */

#pragma once

#include <memory>

#include "falcon_core/export.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/domains/Domain.hpp"
namespace falcon_core {
namespace math {
namespace domains {

/**
 * @brief Domain with an associated label with the instrument associated.
 */
class FALCON_CORE_CPP_API LabelledDomain : public Domain {
  instrument_interfaces::names::InstrumentPortSP _port;
  mutable std::shared_timed_mutex                _mu_port;

 public:
  LabelledDomain(const LabelledDomain& other);
  LabelledDomain& operator=(const LabelledDomain& other);
  /**
   * @brief Construct a labelled domain.
   * @default_name The default_name for the instrument.
   * @bounds The bounds on the domain.
   * @psuedo_name The name of the connection on the instrument if available.
   * @instrument_type The type of instrument connected to
   * @lesser_bound_contained If the lesser_bound is contained in the domain.
   * @greater_bound_contained If the greater_bound is contained in the domain.
   * @units The units of the instrument.
   * @description The description of the instrument.
   */
  LabelledDomain(
      const std::string&                              default_name,
      const std::pair<double, double>&                bounds,
      const physics::device_structures::ConnectionSP& psuedo_name,
      const instrument_interfaces::names::Instrument& instrument_type,
      bool                                            lesser_bound_contained,
      bool                                            greater_bound_contained,
      const physics::units::SymbolUnitSP&             units,
      const std::string&                              description,
      const instrument_interfaces::names::PortType    type =
          instrument_interfaces::names::PortType::Knob);
  /**
   * @brief Construct a labelled domain.
   * @param bounds Minimum, Maximum pair of the domain.
   * @param port Shared pointer to the port.
   */
  static const std::shared_ptr<LabelledDomain> from_port(
      const std::pair<double, double>&                      bounds,
      const instrument_interfaces::names::InstrumentPortSP& port,
      const bool& lesser_bound_contained  = true,
      const bool& greater_bound_contained = true);
  /**
   * @brief Create a LabelledDomain from an existing knob and domain.
   * @param knob The knob to associate with the domain.
   * @param domain The domain to associate with the knob.
   * @return A created LabelledDomain.
   */
  static const std::shared_ptr<LabelledDomain> from_port_and_domain(
      const instrument_interfaces::names::InstrumentPortSP& port,
      const DomainSP&                                       domain);
  /**
   * @brief Create a LabelledDomain from an existing domain.
   * @param domain The domain to associate with the knob.
   * @param default_name The default name of the knob.
   * @param pseudo_name The optional colloquial name of the knob.
   * @param instrument_type The type of instrument the knob belongs to.
   * @param units the units of the knob's domain.
   * @param description A description of the knob.
   * @return A created LabelledDomain.
   */
  static const std::shared_ptr<LabelledDomain> from_domain(
      const DomainSP&                                 domain,
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name,
      const instrument_interfaces::names::Instrument& instrument_type,
      const physics::units::SymbolUnitSP&             units =
          physics::units::SymbolUnit::Volt(),
      const std::string& description = "");

  /**
   * @brief Get the port.
   * @return Shared pointer to the port.
   */
  const instrument_interfaces::names::InstrumentPortSP& port() const;
  /**
   * @brief Gets the domain associated with the port.
   */
  std::shared_ptr<Domain> domain() const;
  /**
   * @brief Checks if the port matches the given port.
   * @param port The port to compare with.
   * @return True if the ports match, false otherwise.
   */
  bool matching_port(
      const instrument_interfaces::names::InstrumentPortSP& port) const;
  bool operator==(const LabelledDomain& other) const;
  bool operator!=(const LabelledDomain& other) const;

 protected:
  LabelledDomain();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_port(_mu_port);
    ar(cereal::base_class<Domain>(this), _port);
  }
};
using LabelledDomainSP = std::shared_ptr<LabelledDomain>;
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
