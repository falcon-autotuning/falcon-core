#pragma once

#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {

class CartesianDiscretizer : public BaseDiscretizer {
 public:
  CartesianDiscretizer(double delta)
      : BaseDiscretizer(delta, std::make_shared<domains::Domain>(-1.0, 1.0)) {}

  using BaseDiscretizer::BaseDiscretizer;

 private:
  friend class cereal::access;
  CartesianDiscretizer() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscretizer>(this));
  }
};
}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::discretizers;

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::CartesianDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::CartesianDiscretizer)
#endif
