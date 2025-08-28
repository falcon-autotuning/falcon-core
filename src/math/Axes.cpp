#include "falcon_core/math/Axes.hpp"

#include <cereal/types/polymorphic.hpp>

#include "falcon_core/math/Axes.hpp"

// Explicit instantiation for Axes<double>
template class falcon_core::math::Axes<double>;
template class falcon_core::math::Axes<
    falcon_core::math::discretizers::BaseDiscretizer>;

// Cereal registration
CEREAL_REGISTER_TYPE(falcon_core::math::Axes<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Axes<double>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::discretizers::BaseDiscretizer>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::discretizers::BaseDiscretizer>)
