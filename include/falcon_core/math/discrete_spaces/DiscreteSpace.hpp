#pragma once

#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class DiscreteSpace : public BaseDiscreteSpace {
 public:
  using BaseDiscreteSpace::BaseDiscreteSpace;  // Inherit constructors

  DiscreteSpace(const spaces::UnitSpaceSP&                     space,
                const AxesSP<domains::CoupledKnobDomain>&      axes,
                const AxesSP<generic::Map<std::string, bool>>& increasing);

 private:
  friend class cereal::access;
  DiscreteSpace();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscreteSpace>(this));
  }
};
using DiscreteSpaceSP = std::shared_ptr<DiscreteSpace>;
}  // namespace falcon_core::math::discrete_spaces
