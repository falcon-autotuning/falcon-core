#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core::math::discrete_spaces {

class CartesianDiscreteSpace : public BaseCartesianDiscreteSpace {
 public:
  CartesianDiscreteSpace(
      const spaces::UnitSpaceSP&                     space,
      const AxesSP<domains::CoupledLabelledDomain>&  axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing);

  static std::shared_ptr<CartesianDiscreteSpace> from_divisions(
      const generic::ListSP<int>&                    divisions,
      const AxesSP<domains::CoupledLabelledDomain>&  axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing,
      const domains::DomainSP&                       domain =
          std::make_shared<domains::Domain>(std::pair<double, double>(0, 1)));

 private:
  CartesianDiscreteSpace();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseCartesianDiscreteSpace>(this));
  }
};
using CartesianDiscreteSpaceSP = std::shared_ptr<CartesianDiscreteSpace>;
}  // namespace falcon_core::math::discrete_spaces
