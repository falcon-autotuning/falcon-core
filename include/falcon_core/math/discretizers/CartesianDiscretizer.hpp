#pragma once

#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {

class CartesianDiscretizer : public BaseDiscretizer {
 public:
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
CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::CartesianDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::CartesianDiscretizer)
