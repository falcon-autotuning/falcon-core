#pragma once

#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class CartesianDiscreteSpace1D : public BaseCartesianDiscreteSpace {
 public:
  CartesianDiscreteSpace1D(const spaces::UnitSpaceSP&          space,
                           const domains::CoupledKnobDomainSP& shared_domain,
                           const generic::MapSP<std::string, bool>& increasing);

  static std::shared_ptr<CartesianDiscreteSpace1D> from_divisions(
      const int&                               division,
      const domains::CoupledKnobDomainSP&      shared_domain,
      const generic::MapSP<std::string, bool>& increasing,
      const domains::DomainSP&                 domain =
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
