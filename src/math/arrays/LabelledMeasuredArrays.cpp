#include "falcon_core/math/arrays/LabelledMeasuredArrays.hpp"

namespace falcon_core::math::arrays {

LabelledMeasuredArrays::LabelledMeasuredArrays() = default;
LabelledMeasuredArrays::LabelledMeasuredArrays(
    const std::vector<LabelledMeasuredArraySP>& arrays)
    : BaseLabelledArrays(arrays) {}
}  // namespace falcon_core::math::arrays

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledMeasuredArrays)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseLabelledArrays<
        falcon_core::math::arrays::LabelledMeasuredArray>,
    falcon_core::math::arrays::LabelledMeasuredArrays)
