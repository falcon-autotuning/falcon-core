#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/AnalyticFunction.hpp"

/**
 * @brief A transform that maps a port to a time domain analytic function.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransform : public math::AnalyticFunction {
  names::InstrumentPortSP         _port;
  mutable std::shared_timed_mutex _mu_port;

 public:
  PortTransform(const PortTransform& other);
  PortTransform& operator=(const PortTransform& other);
  /**
   * @brief Construct a port transform
   * @param port the port that the transform applies to.
   * @param transfrom the transform that we want to communicate.
   */
  PortTransform(const names::InstrumentPortSP&  port,
                const math::AnalyticFunctionSP& transform);
  /**
   * @brief Construct a constant transform attached to a specific port.
   * @param port The port that this tranform applies to.
   */
  static std::shared_ptr<PortTransform> ConstantTransform(
      const names::InstrumentPortSP& port, const double& value);
  /**
   * @brief Construct an identity transform attached to a specific port.
   * @param port The port that this tranform applies to.
   */
  static std::shared_ptr<PortTransform> IdentityTransform(
      const names::InstrumentPortSP& port);
  /**
   * @brief Returns the port associated with the transform.
   */
  const names::InstrumentPortSP port() const;
  bool                          operator==(const PortTransform& other) const;
  bool                          operator!=(const PortTransform& other) const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_p(_mu_port);
    ar(cereal::base_class<math::AnalyticFunction>(this), _port);
  };
  PortTransform();
};
using PortTransformSP = std::shared_ptr<PortTransform>;
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
