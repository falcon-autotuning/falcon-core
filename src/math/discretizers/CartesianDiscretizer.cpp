#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include <memory>

namespace falcon_core {
namespace math {
namespace discretizers {

CartesianDiscretizer::CartesianDiscretizer(double delta)
    : BaseDiscretizer(delta, std::make_shared<domains::Domain>(-1.0, 1.0)) {}

CartesianDiscretizer::CartesianDiscretizer() = default;

template <class Archive>
void CartesianDiscretizer::serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscretizer>(this));
}

}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::CartesianDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::CartesianDiscretizer)
