#pragma once

#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/LabelledControlArray.hpp"
namespace falcon_core::math::labelled_arrays {

class LabelledControlArrays : public BaseLabelledArrays<double> {
 public:
  LabelledControlArrays();
  LabelledControlArrays(const std::vector<LabelledControlArraySP>& arrays);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArrays<double>>(this));
  }
};

}  // namespace falcon_core::math::labelled_arrays
