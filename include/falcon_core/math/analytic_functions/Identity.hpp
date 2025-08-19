#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

class Identity : public AnalyticFunction {
 public:
  Identity() = default;

  double evaluate(double x) const override { return x; }

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<AnalyticFunction>(this));
  }
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::analytic_functions;
CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::Identity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::analytic_functions::Identity)
