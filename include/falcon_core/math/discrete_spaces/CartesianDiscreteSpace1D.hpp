#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class CartesianDiscreteSpace1D : public BaseCartesianDiscreteSpace {
 public:
  using BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace;

  CartesianDiscreteSpace1D();
  CartesianDiscreteSpace1D(std::shared_ptr<spaces::Cartesian1DSpace> space,
                           std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes);

  static std::shared_ptr<CartesianDiscreteSpace1D> from_division(
      int division,
      std::shared_ptr<domains::CoupledKnobDomain> shared_domain,
      std::shared_ptr<domains::Domain> domain);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
