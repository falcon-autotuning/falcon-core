#include "falcon_core/math/arrays/BaseArray.hpp"
#include <cereal/types/polymorphic.hpp>
#include "falcon_core/generic/Song.hpp"

// Register for float and double
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::BaseArray<float>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::BaseArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::arrays::BaseArray<float>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::arrays::BaseArray<double>)
