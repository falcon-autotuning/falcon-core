#pragma once

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <cereal/types/memory.hpp>
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

// You may need to include the correct Ports header for your use case
// #include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

template <typename PortsType>
class ValidatedAnalyticFunction : public generic::Song {
 public:
  using FunctionPtr = std::shared_ptr<AnalyticFunction>;
  using PortsPtr    = std::shared_ptr<PortsType>;

  ValidatedAnalyticFunction(PortsPtr ports, FunctionPtr function)
      : _ports(std::move(ports)), _function(std::move(function)) {
    validate_function_signature();
  }

  // Accessors
  const PortsPtr& ports() const { return _ports; }
  const FunctionPtr& function() const { return _function; }

  // Call operator: forwards to the underlying function
  double evaluate(double x) const {
    return _function->evaluate(x);
  }

  // You may want to add a more general call operator for multiple arguments

 private:
  PortsPtr    _ports;
  FunctionPtr _function;

  // Example validation: check for a "clock" port
  void validate_function_signature() const {
    // This is a placeholder. You should implement your own logic
    // to check that the ports and function mapping are compatible.
    // For example, check that a port named "clock" exists.
    // If PortsType has a method like get_instrument_facing_names(), use it.
    // Here is a generic example:
    bool has_clock = false;
    for (const auto& port : _ports->items()) {
      // Replace with your actual clock port check
      if (port->instrument_type() == "CLOCK" || port->default_name() == "clock") {
        has_clock = true;
        break;
      }
    }
    if (!has_clock) {
      throw std::runtime_error("ValidatedAnalyticFunction requires a clock port.");
    }
  }

  friend class cereal::access;
  ValidatedAnalyticFunction() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _ports, _function);
  }
};

}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

// Example registration for a specific Ports type:
// using ValidatedAF_KnobPorts = falcon_core::math::analytic_functions::ValidatedAnalyticFunction<falcon_core::instrument_interfaces::names::Ports<falcon_core::instrument_interfaces::names::Knob>>;
// CEREAL_REGISTER_TYPE(ValidatedAF_KnobPorts)
// CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ValidatedAF_KnobPorts)
