#include "falcon_core/math/arrays/ControlArray1D.hpp"

#include <cereal/types/polymorphic.hpp>

using namespace falcon_core::math::arrays;

// Register ControlArray1D for polymorphic serialization
CEREAL_REGISTER_TYPE(ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, ControlArray1D)
