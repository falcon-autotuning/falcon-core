#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

Cartesian1DSpace::Cartesian1DSpace(double                           delta,
                                   std::shared_ptr<domains::Domain> domain)
    : CartesianSpace(std::vector<double>{delta}, domain) {}

Cartesian1DSpace::Cartesian1DSpace() = default;

template <class Archive>
void Cartesian1DSpace::serialize(Archive& ar) {
  ar(cereal::base_class<CartesianSpace>(this));
}

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian1DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian1DSpace)
