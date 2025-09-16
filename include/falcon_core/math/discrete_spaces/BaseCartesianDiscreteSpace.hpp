#pragma once
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core::math::discrete_spaces {

class BaseCartesianDiscreteSpace : public BaseDiscreteSpace {
 public:
  /**
   * @brief Initialize the DiscreteSpace.
   * The order of the Knobs in teh axes are defined to line up with the space.
   * @param space the space taht the decirete values fill
   * @param axes the axes containing the discrete values.
   * @param increasing True if the axes are decreasing with the direction of the
   * domain or against.
   */
  BaseCartesianDiscreteSpace(
      const spaces::UnitSpaceSP&                     space,
      const AxesSP<domains::CoupledKnobDomain>&      axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing);

 protected:
  BaseCartesianDiscreteSpace() = default;
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscreteSpace>(this));
  }
};
using BaseCartesianDiscreteSpaceSP =
    std::shared_ptr<BaseCartesianDiscreteSpace>;
}  // namespace falcon_core::math::discrete_spaces
