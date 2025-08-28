#pragma once

#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray1D.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

class LabelledMeasuredArrays
    : public BaseLabelledArrays<LabelledMeasuredArray1D> {
 public:
  LabelledMeasuredArrays();

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
