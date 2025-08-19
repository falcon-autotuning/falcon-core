#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

class AnalyticFunction : public generic::Song {
 public:
  virtual ~AnalyticFunction()             = default;
  virtual double evaluate(double x) const = 0;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this));
  }
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::analytic_functions;
CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::analytic_functions::AnalyticFunction)
