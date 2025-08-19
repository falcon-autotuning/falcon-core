#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

using namespace falcon_core;
using namespace falcon_core::math::arrays;

#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, IncreasingAlignment)
