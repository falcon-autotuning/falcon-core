#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class CartesianDiscreteSpace : public BaseCartesianDiscreteSpace {
 public:
  using BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace;

  CartesianDiscreteSpace();
  CartesianDiscreteSpace(std::shared_ptr<spaces::CartesianSpace> space,
                         std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes);

  static std::shared_ptr<CartesianDiscreteSpace> from_divisions(
      const std::vector<int>& divisions,
      std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes,
      std::shared_ptr<domains::Domain> domain);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
