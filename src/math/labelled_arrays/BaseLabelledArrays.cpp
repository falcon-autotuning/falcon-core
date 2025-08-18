#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

#include <cereal/types/polymorphic.hpp>
#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

// Type aliases to avoid macro issues with template commas
using LabelledArrayType = falcon_core::math::labelled_arrays::BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>;
using LabelledArraysType = falcon_core::math::labelled_arrays::BaseLabelledArrays<LabelledArrayType>;

CEREAL_REGISTER_TYPE(LabelledArraysType)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LabelledArraysType)
