#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

/**
 * @brief A transform that maps a port to a time domain analytic function.
 */
namespace falcon_core::instrument_interfaces::port_transforms {

class PortTransform
    : public math::analytic_functions::ValidatedAnalyticFunction {
  names::InstrumentPortSP _port;
  /**
   * @brief Validated that the transform is valid.
   */
  bool validate_transform();

 public:
  /**
   * @brief Construct a port transform
   * @param port the port that the transform applies to.
   * @param transfrom the transform that we want to communicate.
   */
  PortTransform(
      names::InstrumentPortSP                               port,
      math::analytic_functions::ValidatedAnalyticFunctionSP transform);
  /**
   * @brief Returns the port associated with the transform.
   */
  const names::InstrumentPortSP port() const;
  /**
   * @brief Return the transform.
   */
  const math::analytic_functions::ValidatedAnalyticFunctionSP transform() const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<math::analytic_functions::ValidatedAnalyticFunction>(
           this),
       _port);
  };
  PortTransform();
};
using PortTransformSP = std::shared_ptr<PortTransform>;
}  // namespace falcon_core::instrument_interfaces::port_transforms
