#include "falcon_core/math/AnalyticFunction.hpp"

#include <exprtk.hpp>
#include <regex>
#include <stdexcept>
#include <string>

#include "xtensor/xadapt.hpp"

namespace falcon_core {
namespace math {
size_t maxXindex(const std::string& expr) {
  std::regex           x_index_regex(R"(x\[(\d+)\])");
  std::sregex_iterator iter(expr.begin(), expr.end(), x_index_regex);
  std::sregex_iterator end;
  size_t               found     = 0;
  size_t               max_index = 0;
  for (; iter != end; ++iter) {
    size_t idx = std::stoul((*iter)[1].str());
    if (idx > max_index) max_index = idx;
    ++found;
  }
  return found ? (max_index + 1) : 0;
}
void enforceMatchingSize(const std::string& expr, const int& labelSize) {
  int exprSize;
  exprSize = maxXindex(expr);
  if (exprSize != labelSize) {
    throw std::length_error(
        "Expected the dimensionality of x in the expression of " +
        std::to_string(exprSize) +
        " to match the dimensionality of the labels " +
        std::to_string(labelSize));
  }
}
void compileExpression(const std::string&          expr,
                       exprtk::expression<double>& tkExpression,
                       double&                     t,
                       std::vector<double>&        x) {
  exprtk::symbol_table<double> symbol_table;
  symbol_table.add_vector("x", x.data(), x.size());
  symbol_table.add_variable("t", t);
  tkExpression.register_symbol_table(symbol_table);
  exprtk::parser<double> parser;
  bool                   success = parser.compile(expr, tkExpression);
  if (!success) {
    throw std::invalid_argument("AnalyticFunction: Compilation error...\n");
  }
}
void populateXvector(std::vector<double>&                        x,
                     const std::vector<VariableName>&            labels,
                     const generic::MapSP<VariableName, double>& args) {
  for (size_t i = 0; i < labels.size(); ++i) {
    std::string label = labels[i];
    try {
      x[i] = args->at(label);
    } catch (const std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
      throw std::invalid_argument("AnalyticFunction: Expected the label " +
                                  label + " to be in the map.");
    }
  }
}
AnalyticFunction::AnalyticFunction()
    : generic::List<VariableName>(), _expression("") {}
AnalyticFunction::AnalyticFunction(const generic::ListSP<VariableName>& labels,
                                   const std::string& expression)
    : generic::List<VariableName>(
          labels ? *labels
                 : throw std::invalid_argument(
                       "AnalyticFunction: need to specify labels.")),
      _expression(expression) {
  exprtk::expression<double> tkExpression;
  double                     t = 0.0;
  std::vector<double>        x(items().size(), 0.0);
  if (expression.empty()) {
    throw std::invalid_argument(
        "AnalyticFunction: expression cannot be empty.");
  }
  enforceMatchingSize(_expression, items().size());
  compileExpression(_expression, tkExpression, t, x);
}
const generic::ListSP<VariableName> AnalyticFunction::labels() const {
  return std::make_shared<generic::List<VariableName>>(items());
}
AnalyticFunctionSP AnalyticFunction::Identity() {
  std::string                   expression = "x[0]";
  generic::ListSP<VariableName> labels =
      std::make_shared<generic::List<VariableName>>();
  labels->push_back(std::string("x"));
  return std::make_shared<AnalyticFunction>(labels, expression);
}
AnalyticFunctionSP AnalyticFunction::Constant(const double& value) {
  std::string                   expression = std::to_string(value);
  generic::ListSP<VariableName> labels =
      std::make_shared<generic::List<VariableName>>();
  return std::make_shared<AnalyticFunction>(labels, expression);
}
void AnalyticFunction::checkSafeEvaluateArgs(
    const generic::MapSP<VariableName, double>& args) const {
  if (!args) {
    throw std::invalid_argument(
        "AnalyticFunction: Expected a map but got nothing.");
  }
  if (args->size() != labels()->size()) {
    throw std::invalid_argument(
        "AnalyticFunction: Expected that the number of arguments in the map " +
        std::to_string(args->size()) +
        " to have the same size as the number of arguments in the labels " +
        std::to_string(labels()->size()));
  }
}
double AnalyticFunction::evaluate(
    const generic::MapSP<VariableName, double>& args,
    const double&                               time) const {
  exprtk::expression<double> tkExpression;
  std::vector<double>        x(items().size(), 0.0);
  double                     t = time;
  checkSafeEvaluateArgs(args);
  populateXvector(x, items(), args);
  compileExpression(_expression, tkExpression, t, x);
  return tkExpression.value();
}
generic::FArraySP<double> AnalyticFunction::evaluate(
    const generic::MapSP<VariableName, double>& args,
    const double&                               deltaT,
    const double&                               maxTime) const {
  exprtk::expression<double> tkExpression;
  std::vector<double>        x(items().size(), 0.0);
  double                     t = 0.0;
  checkSafeEvaluateArgs(args);
  populateXvector(x, items(), args);
  compileExpression(_expression, tkExpression, t, x);
  std::vector<double> rawVec;
  for (t = 0.0; t < maxTime; t += deltaT) {
    rawVec.push_back(tkExpression.value());
  }
  xt::xarray<double> rawArray = xt::adapt(rawVec);
  return std::make_shared<generic::FArray<double>>(rawArray);
}
bool AnalyticFunction::operator==(const AnalyticFunction& other) const {
  return (_expression == other._expression) &&
         generic::List<VariableName>::operator==(other);
}
bool AnalyticFunction::operator!=(const AnalyticFunction& other) const {
  return !(*this == other);
}
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::VariableName>,
    falcon_core::math::AnalyticFunction)
