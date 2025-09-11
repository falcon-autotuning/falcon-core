#pragma once

#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray.hpp"
namespace falcon_core::math::labelled_arrays {

class LabelledMeasuredArrays : public BaseLabelledArrays<double> {
 public:
  LabelledMeasuredArrays();
  LabelledMeasuredArrays(const std::vector<LabelledMeasuredArraySP>& arrays);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArrays<double>>(this));
  }
};

}  // namespace falcon_core::math::labelled_arrays
