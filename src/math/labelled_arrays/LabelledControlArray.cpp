#include "falcon_core/math/labelled_arrays/LabelledControlArray.hpp"

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core::math::labelled_arrays {

LabelledControlArray::LabelledControlArray(
    arrays::ControlArraySP                               array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : BaseLabelledArray<double>(array, label) {}
LabelledControlArray::LabelledControlArray(
    arrays::BaseArraySP<double>                          array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : BaseLabelledArray<double>(array, label) {}
}  // namespace falcon_core::math::labelled_arrays

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::labelled_arrays::BaseLabelledArray<double>,
    falcon_core::math::labelled_arrays::LabelledControlArray)
