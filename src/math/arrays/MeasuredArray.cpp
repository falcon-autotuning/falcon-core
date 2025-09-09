#include "falcon_core/math/arrays/MeasuredArray.hpp"

// No implementation needed as all logic is inherited from BaseArray/FArray.

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::arrays::MeasuredArray<double>)
