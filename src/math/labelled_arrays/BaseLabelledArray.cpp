#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

#include "falcon_core/math/arrays/BaseArray.hpp"

// Explicit instantiation for your used types
using BLA = falcon_core::math::labelled_arrays::
    BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>;
template class falcon_core::math::labelled_arrays::
    BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>;
template void falcon_core::math::labelled_arrays::BaseLabelledArray<
    falcon_core::math::arrays::BaseArray<double>,
    int>::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive&);
template void falcon_core::math::labelled_arrays::BaseLabelledArray<
    falcon_core::math::arrays::BaseArray<double>,
    int>::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive&);

CEREAL_REGISTER_TYPE(BLA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, BLA)
