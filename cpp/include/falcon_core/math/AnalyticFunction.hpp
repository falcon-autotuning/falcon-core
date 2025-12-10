#pragma once

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"

/**
 * @file AnalyticFunction.hpp
 * @brief A class for a gunction that can be used to describe analytic time
 * domain shaped.
 *
 * This supports functions of the form x[0]*t^2 + x[1] where the values that can
 * be set are elements of the x vector, and it can be evaluated as a function of
 * time at a later date. For time evaluation, it is assumed that this function
 * should be evaluated at t=0.
 *
 * Not that this vector should always start from 0, and you should not skip any
 * indexes.
 *
 * There are builtin labels, such that the arbitrary vector indexes can be
 * turned into human readable labels.
 */

namespace falcon_core {
namespace math {

using VariableName = std::string;
class AnalyticFunction : public generic::List<VariableName> {
  std::string                     _expression;
  mutable std::shared_timed_mutex _mu_expression;
  /**
   * @brief Checks that it is safe to evaluate the args that the user passed in.
   * @param args The user args from the evaluate function
   * @throw invalid_argument if the args are improper.
   */
  void checkSafeEvaluateArgs(
      const generic::MapSP<VariableName, double>& args) const;

 public:
  AnalyticFunction(const AnalyticFunction& other);
  AnalyticFunction& operator=(const AnalyticFunction& other);
  /**
   * @brief Construct an AnalyticFunction with a mapping of the function's
   * arguments to their names.
   * @param labels The label for each element of the vector
   * @param expression The mathematical expression to be evaluated
   */
  AnalyticFunction(const generic::ListSP<VariableName>& labels,
                   const std::string&                   expression);
  /**
   * @brief Construct an identity.
   * The equation is : x[0] where x[0] is some supplied quantity.
   */
  static std::shared_ptr<AnalyticFunction> Identity();
  /**
   * @brief Construct an constant function.
   * The equation is : const where const is supplied here on construction.
   */
  static std::shared_ptr<AnalyticFunction> Constant(const double& value);
  /**
   * @brief Return the set of labels in proper order of the function's arguments
   * to their names.
   */
  const generic::ListSP<VariableName> labels() const;
  /**
   * @brief Returns the evaluated analytic function.
   * @param args The vector arguments supplied with human readable names
   * @param time The time to evaluate the function at..
   */
  double evaluate(const generic::MapSP<VariableName, double>& args,
                  const double&                               time) const;
  /**
   * @brief Returns the evaluated analytic function.
   * @param args The vector arguments supplied with human readable names
   * @param deltaT The different between calculated datapoints
   * @param maxTime The total time to expend running the calculation.
   */
  generic::FArraySP<double> evaluate(
      const generic::MapSP<VariableName, double>& args,
      const double&                               deltaT,
      const double&                               maxTime) const;
  bool operator==(const AnalyticFunction& other) const;
  bool operator!=(const AnalyticFunction& other) const;

 protected:
  AnalyticFunction();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_expression(_mu_expression);
    ar(cereal::base_class<generic::List<VariableName>>(this), _expression);
  }
};
using AnalyticFunctionSP = std::shared_ptr<AnalyticFunction>;
}  // namespace math
}  // namespace falcon_core
