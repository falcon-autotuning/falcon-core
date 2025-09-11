#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray1D.hpp"

namespace falcon_core::math::labelled_arrays {

LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    arrays::MeasuredArraySP                              array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : LabelledMeasuredArray(array, label) {}
LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    arrays::MeasuredArray1DSP                            array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : LabelledMeasuredArray(
          std::dynamic_pointer_cast<arrays::MeasuredArray>(array), label) {}
LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    arrays::BaseArraySP<double>                          array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : LabelledMeasuredArray(array, label) {}
arrays::MeasuredArray1DSP LabelledMeasuredArray1D::array() const {
  return std::dynamic_pointer_cast<arrays::MeasuredArray1D>(
      LabelledMeasuredArray::array());
}
void LabelledMeasuredArray1D::smooth(const size_t window_size) {
  if (!this->array()) {
    throw std::runtime_error("Array is null");
  }
  this->array()->smooth(window_size);
}

}  // namespace falcon_core::math::labelled_arrays

// Cereal registration for LabelledMeasuredArray1D
CEREAL_REGISTER_TYPE(
    falcon_core::math::labelled_arrays::LabelledMeasuredArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::labelled_arrays::LabelledMeasuredArray,
    falcon_core::math::labelled_arrays::LabelledMeasuredArray1D)
