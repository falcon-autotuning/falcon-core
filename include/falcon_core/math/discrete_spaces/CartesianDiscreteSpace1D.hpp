#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class CartesianDiscreteSpace1D : public BaseCartesianDiscreteSpace {
 public:
  using BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace;

  CartesianDiscreteSpace1D() = default;
  CartesianDiscreteSpace1D(std::shared_ptr<spaces::Cartesian1DSpace> space,
                           std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes)
      : BaseCartesianDiscreteSpace(space, axes) {}

  // Factory method for from_division
  static std::shared_ptr<CartesianDiscreteSpace1D> from_division(
      int division,
      std::shared_ptr<domains::CoupledKnobDomain> shared_domain,
      std::shared_ptr<domains::Domain> domain);

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
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace, falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
#endif
