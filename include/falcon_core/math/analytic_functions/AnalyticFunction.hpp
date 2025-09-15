#pragma once

#include "falcon_core/generic/Map.hpp"

/**
 * @file AnalyticFunction.hpp
 * @brief A class for a gunction that can be used to describe analytic time
 * domain shaped.
 *
 * This function can wrap a function of the form
 * def func(cls, t: Number=0.0, x: Number=0.0,... **parameters:Number) -> Number
 * where the user can specify the specific arguments if they so choose.
 * Every argument must be a keywork argument, so a default value must be
 * supplied.
 */

namespace falcon_core::math::analytic_functions {

using InstrumentFacingName = std::string;
using VariableName         = std::string;
class AnalyticFunction
    : public generic::Map<InstrumentFacingName, VariableName> {
 public:
  /**
   * @brief Construct an AnalyticFunction with a mapping of the function's
   * arguments to their names.
   * @param mapping A mapping of the function's arguments to their names.
   */
  AnalyticFunction(
      const generic::MapSP<InstrumentFacingName, VariableName>& mapping);
  /**
   * @brief Return a mapping of the function's arguments to their names.
   */
  generic::MapSP<InstrumentFacingName, VariableName> mapping() const;
  /**
   * @brief The core function that needs to be implemented by the user.
   * @param args A mapping of the function's arguments to their values.
   * @return The result of the function.
   */
  double virtual _function(
      const generic::MapSP<VariableName, double>& args) const;
  /**
   * @brief Maps the names of the space onto the functions arguments.
   */
  generic::MapSP<VariableName, double> name_mapping(
      const generic::MapSP<InstrumentFacingName, double>& args) const;
  /**
   * @brief Returns the evaluated analytic function.
   */
  double function(
      const generic::MapSP<InstrumentFacingName, double>& args) const;

 protected:
  AnalyticFunction();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Map<InstrumentFacingName, VariableName>>(
        this));
  }
};
using AnalyticFunctionSP = std::shared_ptr<AnalyticFunction>;
}  // namespace falcon_core::math::analytic_functions
