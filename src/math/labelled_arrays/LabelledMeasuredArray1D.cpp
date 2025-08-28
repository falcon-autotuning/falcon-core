#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray1D.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    std::shared_ptr<arrays::MeasuredArray<double>> array,
    std::shared_ptr<LabelType>                     label)
    : BaseLabelledArray<arrays::MeasuredArray<double>, LabelType>(array,
                                                                  label) {}
const arrays::MeasuredArray<double>& LabelledMeasuredArray1D::get_array()
    const {
  if (!this->_array) {
    throw std::runtime_error("Array is null");
  }
  return *this->_array;
}

template <class Archive>
void LabelledMeasuredArray1D::serialize(Archive& ar) {
  ar(cereal::base_class<
      BaseLabelledArray<arrays::MeasuredArray<double>, LabelType>>(this));
}

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::math::labelled_arrays::LabelledMeasuredArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledMeasuredArray1D)
