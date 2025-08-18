#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include <cereal/types/polymorphic.hpp>

using namespace falcon_core;
using namespace falcon_core::math::labelled_arrays;

CEREAL_REGISTER_TYPE(BaseLabelledArrays<falcon_core::math::arrays::BaseArray<double>>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BaseLabelledArrays<falcon_core::math::arrays::BaseArray<double>>)
