#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
namespace falcon_core::math::discretizers {

CartesianDiscretizer::CartesianDiscretizer(double delta)
    : BaseDiscretizer(delta, std::make_shared<domains::Domain>(-1.0, 1.0)) {}

CartesianDiscretizer::CartesianDiscretizer() = default;

}  // namespace falcon_core::math::discretizers

CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::CartesianDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::CartesianDiscretizer)
