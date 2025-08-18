#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

#include <cereal/types/polymorphic.hpp>

#include "falcon_core/generic/Song.hpp"

// Example registration for float/int, add more as needed
CEREAL_REGISTER_TYPE(
    falcon_core::math::labelled_arrays::BaseLabelledArray<float, int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::BaseLabelledArray<float, int>)
