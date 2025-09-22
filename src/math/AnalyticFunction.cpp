#include "falcon_core/math/AnalyticFunction.hpp"

#include <exprtk.hpp>
#include <stdexcept>

#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "xtensor/containers/xadapt.hpp"

namespace falcon_core::math {

AnalyticFunction::AnalyticFunction()
    : generic::List<VariableName>(), _expression("") {}
AnalyticFunction::AnalyticFunction(const generic::ListSP<VariableName>& labels,
                                   const std::string& expression)
    : generic::List<VariableName>(*labels), _expression(expression) {}
const generic::ListSP<VariableName> AnalyticFunction::labels() const {
  return std::make_shared<generic::List<VariableName>>(items());
}
AnalyticFunctionSP AnalyticFunction::Identity() {
  std::string                   expression = "x[0]";
  generic::ListSP<VariableName> labels;
  labels->push_back("x");
  return std::make_shared<AnalyticFunction>(labels, expression);
}
AnalyticFunctionSP AnalyticFunction::Constant(const double& value) {
  std::string                   expression = std::to_string(value);
  generic::ListSP<VariableName> labels;
  return std::make_shared<AnalyticFunction>(labels, expression);
}
double AnalyticFunction::evaluate(
    const generic::MapSP<VariableName, double>& args,
    const double&                               time) const {
  exprtk::symbol_table<double> symbol_table;
  exprtk::expression<double>   expression;
  exprtk::parser<double>       parser;
  std::vector<double>          x(items().size());
  double                       t = time;
  for (size_t i = 0; i < items().size(); ++i) {
    x[i] = args->at(items()[i]);
  }
  symbol_table.add_vector("x", x.data(), x.size());
  symbol_table.add_variable("t", t);
  expression.register_symbol_table(symbol_table);
  bool success = parser.compile(_expression, expression);
  if (!success) {
    throw std::runtime_error("Compilation error...\n");
  }
  return expression.value();
}
arrays::ControlArray1DSP AnalyticFunction::evaluate(
    const generic::MapSP<VariableName, double>& args,
    const double&                               deltaT,
    const double&                               maxTime) const {
  exprtk::symbol_table<double> symbol_table;
  exprtk::expression<double>   expression;
  exprtk::parser<double>       parser;
  double                       t         = 0.0;
  size_t                       numPoints = floor(maxTime / deltaT);
  std::vector<double>          x(items().size());
  for (size_t i = 0; i < items().size(); ++i) {
    x[i] = args->at(items()[i]);
  }
  symbol_table.add_vector("x", x.data(), x.size());
  symbol_table.add_variable("t", t);
  expression.register_symbol_table(symbol_table);
  bool success = parser.compile(_expression, expression);
  if (!success) {
    throw std::runtime_error("Compilation error...\n");
  }
  std::vector<double> rawVec;
  for (size_t i = 0; i < numPoints; ++i) {
    t += deltaT;
    rawVec.push_back(expression.value());
  }
  xt::xarray<double> rawArray = xt::adapt(rawVec);
  return std::make_shared<arrays::ControlArray1D>(rawArray);
}
}  // namespace falcon_core::math

CEREAL_REGISTER_TYPE(falcon_core::math::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::VariableName>,
    falcon_core::math::AnalyticFunction)
