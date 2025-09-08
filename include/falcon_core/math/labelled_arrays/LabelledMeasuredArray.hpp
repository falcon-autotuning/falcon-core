#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

class LabelledMeasuredArray
    : public BaseLabelledArray<arrays::MeasuredArray<double>> {
 public:
  using MatrixType = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;
  /**
   * @brief Initialize a labelled array.
   * @param array The measured data.
   * @param label The AcquisitionContext label.
   */
  LabelledMeasuredArray(
      std::shared_ptr<arrays::MeasuredArray<double>> array,
      std::shared_ptr<autotuner_interfaces::contexts::AcquisitionContext>
          label);
  /**
   * @brief Create a labelled array from a raw array.
   * @param array The measured data.
   * @param The AquisitionContext label.
   */
  LabelledMeasuredArray(
      MatrixType                                                    array,
      std::shared_ptr<instrument_interfaces::names::InstrumentPort> label);

 private:
  friend class cereal::access;
  LabelledMeasuredArray();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
