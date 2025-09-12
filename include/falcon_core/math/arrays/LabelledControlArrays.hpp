#pragma once

#include "falcon_core/math/arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
namespace falcon_core::math::arrays {

class LabelledControlArrays : public BaseLabelledArrays<LabelledControlArray> {
 public:
  LabelledControlArrays();
  LabelledControlArrays(const std::vector<LabelledControlArraySP>& arrays);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArrays<LabelledControlArray>>(this));
  }
};

}  // namespace falcon_core::math::arrays
