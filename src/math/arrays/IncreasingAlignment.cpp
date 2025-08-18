#include "falcon_core/math/arrays/IncreasingAlignment.hpp"
#include <cereal/types/polymorphic.hpp>
#include "falcon_core/generic/Song.hpp"

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::arrays::IncreasingAlignment)
