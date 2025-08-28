#pragma once

#include "falcon_core/math/arrays/MeasuredArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

template <typename LabelType>
class LabelledMeasuredArray
    : public BaseLabelledArray<arrays::MeasuredArray<double>, LabelType> {
 public:
  LabelledMeasuredArray(std::shared_ptr<arrays::MeasuredArray<double>> array,
                        std::shared_ptr<LabelType> label);

 private:
  friend class cereal::access;
  LabelledMeasuredArray();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
