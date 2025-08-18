#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

using namespace falcon_core;
using namespace falcon_core::math::labelled_arrays;

#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(BaseLabelledArray<float, int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BaseLabelledArray<float, int>)
