#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

#include <cereal/types/polymorphic.hpp>

#include "falcon_core/math/arrays/BaseArray.hpp"

// Register the actual type used in your test and arrays
using LabelledArrayType = falcon_core::math::labelled_arrays::
    BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>;
using LabelledArraysType =
    falcon_core::math::labelled_arrays::BaseLabelledArrays<LabelledArrayType>;

CEREAL_REGISTER_TYPE(LabelledArraysType)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     LabelledArraysType)
