#include "falcon_core/math/arrays/BaseArray.hpp"
#include <cereal/types/polymorphic.hpp>

// Register the actual type used in your test and arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::BaseArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::arrays::BaseArray<double>)
