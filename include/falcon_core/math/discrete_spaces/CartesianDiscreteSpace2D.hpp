#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class CartesianDiscreteSpace2D : public BaseCartesianDiscreteSpace {
 public:
  using BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace;

  CartesianDiscreteSpace2D() = default;
  CartesianDiscreteSpace2D(std::shared_ptr<spaces::Cartesian2DSpace> space,
                           std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes)
      : BaseCartesianDiscreteSpace(space, axes) {}

  // You may want a factory method for from_divisions, similar to CartesianDiscreteSpace

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseCartesianDiscreteSpace>(this));
  }
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::CartesianDiscreteSpace2D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace, falcon_core::math::discrete_spaces::CartesianDiscreteSpace2D)
#endif
