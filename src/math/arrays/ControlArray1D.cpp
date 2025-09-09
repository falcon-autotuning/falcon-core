#include "falcon_core/math/arrays/ControlArray1D.hpp"

// No implementation needed as all logic is inherited from ControlArray/FArray.

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::arrays::ControlArray1D)
