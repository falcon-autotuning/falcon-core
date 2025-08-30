#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

/**
 * @brief A transform that maps a port to a time domain analytic function.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransform : public generic::Song {
 public:
  PortTransform(
      std::shared_ptr<math::analytic_functions::AnalyticFunction> function);
  PortTransform();

  double apply(double value) const;

  template <class Archive>
  void serialize(Archive& ar);

 private:
  std::shared_ptr<math::analytic_functions::AnalyticFunction> _function;

 protected:
  friend class cereal::access;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
