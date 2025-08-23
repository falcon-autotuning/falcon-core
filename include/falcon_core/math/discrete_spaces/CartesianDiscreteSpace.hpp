#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class CartesianDiscreteSpace : public BaseCartesianDiscreteSpace {
 public:
  using BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace;

  CartesianDiscreteSpace() = default;
  CartesianDiscreteSpace(std::shared_ptr<spaces::CartesianSpace> space,
                         std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes)
      : BaseCartesianDiscreteSpace(space, axes) {}

  // Factory method for from_divisions
  static std::shared_ptr<CartesianDiscreteSpace> from_divisions(
      const std::vector<int>& divisions,
      std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes,
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
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::CartesianDiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace, falcon_core::math::discrete_spaces::CartesianDiscreteSpace)
#endif
