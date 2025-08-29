#pragma once
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class DiscreteSpace : public BaseDiscreteSpace {
 public:
  using BaseDiscreteSpace::BaseDiscreteSpace; // Inherit constructors

  DiscreteSpace();
  DiscreteSpace(std::shared_ptr<spaces::UnitSpace> space,
                std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes);

  // Additional methods as needed

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
