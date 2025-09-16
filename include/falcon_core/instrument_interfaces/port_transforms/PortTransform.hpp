#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

/**
 * @brief A transform that maps a port to a time domain analytic function.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransform
    : public math::analytic_functions::ValidatedAnalyticFunction {
 public:
  PortTransform(
      names::InstrumentPortSP                               port,
      math::analytic_functions::ValidatedAnalyticFunctionSP transform);
  bool validate_transform();

 private:
  names::InstrumentPortSP _port;

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

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
