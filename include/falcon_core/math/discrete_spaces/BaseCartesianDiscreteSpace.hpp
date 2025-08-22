#pragma once
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"
#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class BaseCartesianDiscreteSpace : public BaseDiscreteSpace {
 public:
  using AxesType = Axes<domains::CoupledKnobDomain>;
  using SpacePtr = std::shared_ptr<spaces::CartesianSpace>;

  BaseCartesianDiscreteSpace() = default;
  BaseCartesianDiscreteSpace(SpacePtr space,
                             std::shared_ptr<AxesType> axes)
      : BaseDiscreteSpace(space, axes) {}

  const SpacePtr& space() const {
    return std::static_pointer_cast<spaces::CartesianSpace>(BaseDiscreteSpace::space());
  }

  // Additional methods as needed

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscreteSpace>(this));
  }
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseDiscreteSpace, falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace)
#endif
