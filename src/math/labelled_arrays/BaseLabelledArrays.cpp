#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

#include <cereal/types/polymorphic.hpp>
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include "falcon_core/math/arrays/BaseArray.hpp"

using namespace falcon_core;
using namespace falcon_core::math::labelled_arrays;

// Register BaseLabelledArrays<BaseLabelledArray<BaseArray<double>, int>>
CEREAL_REGISTER_TYPE(BaseLabelledArrays<BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    generic::Song,
    BaseLabelledArrays<BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>>)
