#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class CartesianDiscreteSpace2D : public BaseCartesianDiscreteSpace {
 public:
  CartesianDiscreteSpace2D(
      const spaces::UnitSpaceSP&                     space,
      const AxesSP<domains::CoupledLabelledDomain>&  axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing);

 protected:
  CartesianDiscreteSpace2D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseCartesianDiscreteSpace>(this));
  }
};
using CartesianDiscreteSpace2DSP = std::shared_ptr<CartesianDiscreteSpace2D>;
}  // namespace falcon_core::math::discrete_spaces
