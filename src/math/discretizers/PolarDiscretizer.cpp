#include "falcon_core/math/discretizers/PolarDiscretizer.hpp"

#include <memory>

#include "falcon_core/Constants.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {

PolarDiscretizer::PolarDiscretizer(double delta)
    : BaseDiscretizer(delta,
                      std::make_shared<domains::Domain>(
                          -2.0 * falcon_core::PI, 2.0 * falcon_core::PI)) {}

PolarDiscretizer::PolarDiscretizer() = default;

}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::PolarDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::PolarDiscretizer)
