#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"

namespace falcon_core::math::spaces {

Cartesian2DSpace::Cartesian2DSpace() = default;
Cartesian2DSpace::Cartesian2DSpace(const std::vector<double>& deltas,
                                   const domains::DomainSP&   domain)
    : CartesianSpace(deltas, domain) {
  if (deltas.size() != 2) {
    throw std::invalid_argument("A 2D space must have two deltas.");
  }
}

}  // namespace falcon_core::math::spaces

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian2DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian2DSpace)
