#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransform : public generic::Song {
 public:
  PortTransform(
      std::shared_ptr<math::analytic_functions::AnalyticFunction> function)
      : _function(std::move(function)) {}

  double apply(double value) const {
    if (!_function) return value;
    return _function->evaluate(value);
  }

 private:
  std::shared_ptr<math::analytic_functions::AnalyticFunction> _function;
};
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
