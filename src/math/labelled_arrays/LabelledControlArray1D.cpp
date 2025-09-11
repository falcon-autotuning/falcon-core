#include "falcon_core/math/labelled_arrays/LabelledControlArray1D.hpp"

namespace falcon_core::math::labelled_arrays {

LabelledControlArray1D::LabelledControlArray1D(
    arrays::ControlArraySP                               array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : LabelledControlArray(array, label) {}
LabelledControlArray1D::LabelledControlArray1D(
    arrays::ControlArray1DSP                             array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : LabelledControlArray(
          std::dynamic_pointer_cast<arrays::ControlArray>(array), label) {}
LabelledControlArray1D::LabelledControlArray1D(
    arrays::BaseArraySP<double>                          array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : LabelledControlArray(array, label) {}
arrays::ControlArray1DSP LabelledControlArray1D::array() const {
  return std::dynamic_pointer_cast<arrays::ControlArray1D>(
      LabelledControlArray::array());
}

}  // namespace falcon_core::math::labelled_arrays

// Cereal registration for LabelledControlArray1D
CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::labelled_arrays::LabelledControlArray,
    falcon_core::math::labelled_arrays::LabelledControlArray1D)
