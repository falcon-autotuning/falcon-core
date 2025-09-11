#pragma once

#include "falcon_core/math/arrays/MeasuredArray1D.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray.hpp"

namespace falcon_core::math::labelled_arrays {

class LabelledMeasuredArray1D : public LabelledMeasuredArray,
                                public IsLabelled1D<LabelledMeasuredArray> {
 public:
  LabelledMeasuredArray1D(
      arrays::MeasuredArraySP                              array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  LabelledMeasuredArray1D(
      arrays::MeasuredArray1DSP                            array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  LabelledMeasuredArray1D(
      arrays::BaseArraySP<array_type>                      array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  arrays::MeasuredArray1DSP array() const;
  void                      smooth(const size_t window_size);

 protected:
  friend class cereal::access;
  LabelledMeasuredArray1D() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<LabelledMeasuredArray>(this));
  }
};

}  // namespace falcon_core::math::labelled_arrays
