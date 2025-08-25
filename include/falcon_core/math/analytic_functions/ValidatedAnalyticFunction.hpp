#pragma once

#include <algorithm>
#include <cereal/types/memory.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

/**
 * @file ValidatedAnalyticFunction.hpp
 * @brief Defines an analytic function with validated port mapping.
 */

namespace falcon_core {
namespace math {
namespace analytic_functions {

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
template <typename PortsType>
class ValidatedAnalyticFunction : public generic::Song {
 public:
  using FunctionPtr = std::shared_ptr<AnalyticFunction>;
  using PortsPtr    = std::shared_ptr<PortsType>;

  /**
   * @brief Construct a validated analytic function.
   * @param ports The ports container.
   * @param function The analytic function.
   * @throws std::runtime_error if validation fails.
   */
  ValidatedAnalyticFunction(PortsPtr ports, FunctionPtr function)
      : _ports(std::move(ports)), _function(std::move(function)) {
    validate_function_signature();
  }

  /**
   * @brief Get the ports container.
   * @return Shared pointer to ports.
   */
  const PortsPtr& ports() const { return _ports; }

  /**
   * @brief Get the analytic function.
   * @return Shared pointer to function.
   */
  const FunctionPtr& function() const { return _function; }

  /**
   * @brief Evaluate the underlying function.
   * @param x Input value.
   * @return Function value at x.
   */
  double evaluate(double x) const { return _function->evaluate(x); }

  // You may want to add a more general call operator for multiple arguments

 private:
  PortsPtr    _ports;    ///< Ports container.
  FunctionPtr _function; ///< Analytic function.

  /**
   * @brief Validate that the function signature matches the ports.
   * @throws std::runtime_error if validation fails.
   */
  void validate_function_signature() const {
    // This is a placeholder. You should implement your own logic
    // to check that the ports and function mapping are compatible.
    // For example, check that a port named "clock" exists.
    bool has_clock = false;
    for (const auto& port : _ports->items()) {
      // Replace with your actual clock port check
      if (port->instrument_type() == "CLOCK" ||
          port->default_name() == "clock") {
        has_clock = true;
        break;
      }
    }
    if (!has_clock) {
      throw std::runtime_error(
          "ValidatedAnalyticFunction requires a clock port.");
    }
  }

  friend class cereal::access;
  /**
   * @brief Default constructor for serialization.
   */
  ValidatedAnalyticFunction() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _ports, _function);
  }
};

}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using ValidatedAF_KnobPorts =
    falcon_core::math::analytic_functions::ValidatedAnalyticFunction<
        falcon_core::instrument_interfaces::names::Ports<
            falcon_core::instrument_interfaces::names::Knob>>;
CEREAL_REGISTER_TYPE(ValidatedAF_KnobPorts)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     ValidatedAF_KnobPorts)
#endif  // !SWIG
