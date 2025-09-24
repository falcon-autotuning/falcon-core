#pragma once
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class CartesianDiscreteSpace2D : public BaseDiscreteSpace {
 public:
  CartesianDiscreteSpace2D(
      const UnitSpaceSP&                             space,
      const AxesSP<domains::CoupledLabelledDomain>&  axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing);

 protected:
  CartesianDiscreteSpace2D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscreteSpace>(this));
  }
};
using CartesianDiscreteSpace2DSP = std::shared_ptr<CartesianDiscreteSpace2D>;
}  // namespace falcon_core::math::discrete_spaces
