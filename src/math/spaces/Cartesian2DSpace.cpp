#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

Cartesian2DSpace::Cartesian2DSpace(const std::vector<double>& deltas,
                                   std::shared_ptr<domains::Domain> domain)
    : CartesianSpace(deltas, domain) {
  if (deltas.size() != 2) {
    throw std::invalid_argument("A 2D space must have two deltas.");
  }
}

Cartesian2DSpace::Cartesian2DSpace() = default;

template <class Archive>
void Cartesian2DSpace::serialize(Archive& ar) {
  ar(cereal::base_class<CartesianSpace>(this));
}

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian2DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian2DSpace)
