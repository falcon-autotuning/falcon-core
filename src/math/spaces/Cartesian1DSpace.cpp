#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"

namespace falcon_core::math::spaces {

Cartesian1DSpace::Cartesian1DSpace() = default;
Cartesian1DSpace::Cartesian1DSpace(const double             delta,
                                   const domains::DomainSP& domain)
    : CartesianSpace(std::vector<double>{delta}, domain) {}

}  // namespace falcon_core::math::spaces

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian1DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian1DSpace)
