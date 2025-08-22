#pragma once
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class DiscreteSpace : public BaseDiscreteSpace {
 public:
  using BaseDiscreteSpace::BaseDiscreteSpace; // Inherit constructors

  DiscreteSpace() = default;
  DiscreteSpace(std::shared_ptr<spaces::UnitSpace> space,
                std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes)
      : BaseDiscreteSpace(space, axes) {}

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
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::DiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseDiscreteSpace, falcon_core::math::discrete_spaces::DiscreteSpace)
#endif
