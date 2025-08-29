#pragma once
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class CartesianDiscreteSpace2D : public BaseCartesianDiscreteSpace {
 public:
  using BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace;

  CartesianDiscreteSpace2D();
  CartesianDiscreteSpace2D(std::shared_ptr<spaces::Cartesian2DSpace> space,
                           std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes);

  // You may want a factory method for from_divisions, similar to CartesianDiscreteSpace

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
