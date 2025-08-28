#include "falcon_core/math/labelled_arrays/LabelledControlArrays.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

LabelledControlArrays::LabelledControlArrays() = default;

template <class Archive>
void LabelledControlArrays::serialize(Archive& ar) {
  ar(cereal::base_class<BaseLabelledArrays<LabelledControlArray1D>>(this));
}

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledControlArrays)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledControlArrays)
