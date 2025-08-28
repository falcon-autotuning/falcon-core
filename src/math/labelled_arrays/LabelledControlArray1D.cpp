#include "falcon_core/math/labelled_arrays/LabelledControlArray1D.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

LabelledControlArray1D::LabelledControlArray1D(
    std::shared_ptr<arrays::ControlArray1D> array,
    std::shared_ptr<LabelType> label)
    : BaseLabelledArray<arrays::ControlArray1D, LabelType>(array, label) {}

LabelledControlArray1D::LabelledControlArray1D() = default;

const arrays::ControlArray1D& LabelledControlArray1D::get_array() const {
  if (!this->_array) {
    throw std::runtime_error("Array is null");
  }
  return *this->_array;
}

template <class Archive>
void LabelledControlArray1D::serialize(Archive& ar) {
  ar(cereal::base_class<BaseLabelledArray<arrays::ControlArray1D, LabelType>>(this));
}

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledControlArray1D)
