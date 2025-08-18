#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

using namespace falcon_core;
using namespace falcon_core::math::labelled_arrays;

CEREAL_REGISTER_TYPE(BaseLabelledArray<float, int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BaseLabelledArray<float, int>)
