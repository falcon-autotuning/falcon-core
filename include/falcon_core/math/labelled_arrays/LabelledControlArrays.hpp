#pragma once

#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/LabelledControlArray1D.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

class LabelledControlArrays
    : public BaseLabelledArrays<LabelledControlArray1D> {
 public:
  LabelledControlArrays();

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
