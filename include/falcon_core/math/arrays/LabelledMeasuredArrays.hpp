#pragma once

#include "falcon_core/math/arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
namespace falcon_core::math::arrays {

class LabelledMeasuredArrays
    : public BaseLabelledArrays<LabelledMeasuredArray> {
 public:
  LabelledMeasuredArrays();
  LabelledMeasuredArrays(const std::vector<LabelledMeasuredArraySP>& arrays);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArrays<LabelledMeasuredArray>>(this));
  }
};
using LabelledMeasuredArraysSP = std::shared_ptr<LabelledMeasuredArrays>;
}  // namespace falcon_core::math::arrays
