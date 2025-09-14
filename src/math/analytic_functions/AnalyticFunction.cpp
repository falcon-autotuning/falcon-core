#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core::math::analytic_functions {

AnalyticFunction::AnalyticFunction() = default;
AnalyticFunction::AnalyticFunction(
    const generic::MapSP<InstrumentFacingName, VariableName>& items)
    : generic::Map<InstrumentFacingName, VariableName>(*items) {}
std::map<InstrumentFacingName, VariableName> AnalyticFunction::mapping() const {
  std::map<InstrumentFacingName, VariableName> result;
  for (const auto& pair : this->items()) {
    result[pair.first] = pair.second;
  }
  return result;
}
double AnalyticFunction::_function(
    const generic::MapSP<VariableName, double>&) const {
  throw std::runtime_error(
      "AnalyticFunction::_function not implemented in derived class");
}
generic::MapSP<VariableName, double> AnalyticFunction::name_mapping(
    const generic::MapSP<InstrumentFacingName, double>& args) const {
  generic::MapSP<VariableName, double> result =
      std::make_shared<generic::Map<VariableName, double>>();
  for (auto pair : args->items()) {
    VariableName var_name = this->at(pair.first);
    if (this->contains(var_name)) {
      result->insert(var_name, pair.second);
    }
  }
  return result;
}
double AnalyticFunction::function(
    const generic::MapSP<InstrumentFacingName, double>& args) const {
  generic::MapSP<VariableName, double> function_arguments =
      this->name_mapping(args);
  return _function(function_arguments);
}
}  // namespace falcon_core::math::analytic_functions

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::AnalyticFunction)
using MIV = falcon_core::generic::Map<
    falcon_core::math::analytic_functions::InstrumentFacingName,
    falcon_core::math::analytic_functions::VariableName>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    MIV, falcon_core::math::analytic_functions::AnalyticFunction)
