#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include <cereal/types/polymorphic.hpp>

// Register the actual type used in your test and arrays
using BLA = falcon_core::math::labelled_arrays::BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>;
CEREAL_REGISTER_TYPE(BLA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, BLA)
