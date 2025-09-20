#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"
/**
 * @file Identity.hpp
 * @brief A special type of AnalyticFunction that does nothing to the
 * underlaying discrete data.
 */

namespace falcon_core::math::analytic_functions {

/**
 * @brief Analytic function that returns its input unchanged.
 */
class IdentityFunction : public AnalyticFunction {
  instrument_interfaces::names::InstrumentPortSP _port;

 public:
  /**
   * @brief Initialize an IdentityFunction with the given port.
   * @param port The instrument port associated with this identity function.
   */
  IdentityFunction(const instrument_interfaces::names::InstrumentPortSP& port);
  double _function(const generic::MapSP<std::string, double>& data) const;

 protected:
  IdentityFunction();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<AnalyticFunction>(this), _port);
  }
};

/**
 * @brief A type of function that does nothing to the underlaying discrete data.
 */
class Identity : public ValidatedAnalyticFunction {
 public:
  Identity(const instrument_interfaces::names::PortsSP&          ports,
           const instrument_interfaces::names::InstrumentPortSP& port);

 protected:
  Identity();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ValidatedAnalyticFunction>(this));
  }
};
using IdentitySP         = std::shared_ptr<Identity>;
using IdentityFunctionSP = std::shared_ptr<IdentityFunction>;
}  // namespace falcon_core::math::analytic_functions
