#pragma once

#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class CartesianDiscreteSpace1D : public BaseCartesianDiscreteSpace {
 public:
  CartesianDiscreteSpace1D(
      const spaces::UnitSpaceSP&                     space,
      const AxesSP<domains::CoupledKnobDomain>&      axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing);

  static std::shared_ptr<CartesianDiscreteSpace1D> from_divisions(
      const generic::ListSP<int>&                    divisions,
      const AxesSP<domains::CoupledKnobDomain>&      axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing,
      const domains::DomainSP&                       domain =
          std::make_shared<domains::Domain>(std::pair<double, double>(0, 1)));

 protected:
  CartesianDiscreteSpace1D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseCartesianDiscreteSpace>(this));
  }
};
using CartesianDiscreteSpace1DSP = std::shared_ptr<CartesianDiscreteSpace1D>;
}  // namespace falcon_core::math::discrete_spaces
