#include "falcon_core/math/arrays/BaseArray.hpp"

using namespace falcon_core;
using namespace falcon_core::math::arrays;

#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(BaseArray<float>)
CEREAL_REGISTER_TYPE(BaseArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BaseArray<float>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BaseArray<double>)
