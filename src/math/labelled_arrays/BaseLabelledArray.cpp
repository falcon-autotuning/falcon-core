#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

template <typename ArrayType, typename LabelType>
BaseLabelledArray<ArrayType, LabelType>::BaseLabelledArray(
    std::shared_ptr<ArrayType> array, std::shared_ptr<LabelType> label)
    : _array(std::move(array)), _label(std::move(label)) {}

template <typename ArrayType, typename LabelType>
BaseLabelledArray<ArrayType, LabelType>::BaseLabelledArray() = default;

template <typename ArrayType, typename LabelType>
const std::shared_ptr<ArrayType>&
BaseLabelledArray<ArrayType, LabelType>::array() const {
  return _array;
}

template <typename ArrayType, typename LabelType>
const std::shared_ptr<LabelType>&
BaseLabelledArray<ArrayType, LabelType>::label() const {
  return _label;
}

template <typename ArrayType, typename LabelType>
template <class Archive>
void BaseLabelledArray<ArrayType, LabelType>::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _array, _label);
}

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
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
