#include "falcon_core/math/arrays/LabelledControlArrays.hpp"

namespace falcon_core::math::arrays {

LabelledControlArrays::LabelledControlArrays() = default;
LabelledControlArrays::LabelledControlArrays(
    const std::vector<LabelledControlArraySP>& arrays)
    : BaseLabelledArrays(arrays) {}
}  // namespace falcon_core::math::arrays

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledControlArrays)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseLabelledArrays<
        falcon_core::math::arrays::LabelledControlArray>,
    falcon_core::math::arrays::LabelledControlArrays)
