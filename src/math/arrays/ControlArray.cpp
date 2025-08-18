#include "falcon_core/math/arrays/ControlArray.hpp"

using namespace falcon_core;
using namespace falcon_core::math::arrays;

#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(ControlArray<float>)
CEREAL_REGISTER_TYPE(ControlArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseArray<float>, ControlArray<float>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseArray<double>, ControlArray<double>)
