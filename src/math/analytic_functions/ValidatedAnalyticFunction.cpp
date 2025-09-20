#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

namespace falcon_core::math::analytic_functions {
void ValidatedAnalyticFunction::validate_function_signature(
    const AnalyticFunctionSP& function) const {
  std::set<std::string> input_variables;
  for (const auto& pair : *function->mapping()) {
    input_variables.insert(pair.first);
  }
  if (input_variables.find(instrument_interfaces::InstrumentTypes::CLOCK) ==
      input_variables.end()) {
    throw std::runtime_error(
        "ValidatedAnalyticFunction requires a clock port.");
  }
  generic::List<std::string> port_names =
      _ports->_get_instrument_facing_names()->items();
  for (const auto& var : input_variables) {
    if (!port_names.contains(var)) {
      throw std::runtime_error("Function requires input variable '" + var +
                               "' that is not included in the provided ports.");
    }
  }
}

ValidatedAnalyticFunction::ValidatedAnalyticFunction(
    instrument_interfaces::names::PortsSP ports, AnalyticFunctionSP function)
    : _ports(std::move(ports)) {
  set_function(std::move(function));
}
const instrument_interfaces::names::PortsSP& ValidatedAnalyticFunction::ports()
    const {
  return _ports;
}
const AnalyticFunctionSP& ValidatedAnalyticFunction::function() const {
  return _function;
}
void ValidatedAnalyticFunction::set_function(AnalyticFunctionSP function) {
  validate_function_signature(function);
  _function = std::move(function);
}
generic::ListSP<std::string> ValidatedAnalyticFunction::input_variables()
    const {
  return ports()->_get_instrument_facing_names();
}
bool ValidatedAnalyticFunction::validate_port(
    const instrument_interfaces::names::InstrumentPortSP& port) const {
  return ports()->contains(port);
}

}  // namespace falcon_core::math::analytic_functions
//
CEREAL_REGISTER_TYPE(
    falcon_core::math::analytic_functions::ValidatedAnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::analytic_functions::ValidatedAnalyticFunction)
