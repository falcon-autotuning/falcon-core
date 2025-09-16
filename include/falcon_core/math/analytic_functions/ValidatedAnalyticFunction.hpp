#pragma once

#include "falcon_core/instrument_interfaces/InstrumentTypes.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"
/**
 * @file ValidatedAnalyticFunction.hpp
 * @brief Defines an analytic function with validated port mapping.
 */
namespace falcon_core::math::analytic_functions {
/**
 * @brief Analytic function with validated port mapping.
 *
 * @details
 * This class wraps an AnalyticFunction and a set of ports, ensuring
 * that the function signature is compatible with the provided ports.
 * For example, it can check for the presence of a "clock" port.
 *
 * @tparam PortsType The type of ports container.
 */
class ValidatedAnalyticFunction : public generic::Song {
  instrument_interfaces::names::PortsSP<
      instrument_interfaces::names::InstrumentPort>
                     _ports;
  AnalyticFunctionSP _function;
  /**
   * @brief Validate that the function signature matches the ports.
   * @throws std::runtime_error if validation fails.
   */
  void validate_function_signature(const AnalyticFunctionSP& function) const;

 public:
  /**
   * @brief Construct a validated analytic function.
   * @param ports The ports container.
   * @param function The analytic function.
   * @throws std::runtime_error if validation fails.
   */
  ValidatedAnalyticFunction(
      instrument_interfaces::names::PortsSP<
          instrument_interfaces::names::InstrumentPort> ports,
      AnalyticFunctionSP                                function);
  /**
   * @brief Get the ports.
   */
  const instrument_interfaces::names::PortsSP<
      instrument_interfaces::names::InstrumentPort>&
  ports() const;
  /**
   * @brief Get the analytic function.
   */
  const AnalyticFunctionSP& function() const;
  void                      set_function(AnalyticFunctionSP function);
  /**
   * @brief Return the input variables of the function.
   */
  generic::ListSP<std::string> input_variables() const;
  /**
   * @brief Validate that the port is in the domain.
   * @param port The port to check.
   * @return True if the port is in the domain, false otherwise.
   */
  bool validate_port(
      const instrument_interfaces::names::InstrumentPortSP& port) const;

 protected:
  friend class cereal::access;
  ValidatedAnalyticFunction() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _ports, _function);
  }
};
// template <typename T>
using ValidatedAnalyticFunctionSP = std::shared_ptr<ValidatedAnalyticFunction>;
}  // namespace falcon_core::math::analytic_functions
