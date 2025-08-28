#include "falcon_core/math/labelled_arrays/LabelledMeasuredArrays.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

LabelledMeasuredArrays::LabelledMeasuredArrays() = default;

template <class Archive>
void LabelledMeasuredArrays::serialize(Archive& ar) {
  ar(cereal::base_class<BaseLabelledArrays<LabelledMeasuredArray1D>>(this));
}

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledMeasuredArrays)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledMeasuredArrays)
