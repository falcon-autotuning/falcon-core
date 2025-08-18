#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

#include <cereal/types/polymorphic.hpp>

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

using namespace falcon_core;
using namespace falcon_core::math::labelled_arrays;

// Register BaseLabelledArrays<BaseLabelledArray<BaseArray<double>, int>>
CEREAL_REGISTER_TYPE(
    BaseLabelledArrays<
        BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>>)

using BLA = BaseLabelledArrays<
    BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BLA)
