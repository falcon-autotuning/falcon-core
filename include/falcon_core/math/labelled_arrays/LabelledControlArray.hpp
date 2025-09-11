/**
 * @file LabelledControlArray.hpp
 * @brief Defines the a control array with a label.
 */

#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
namespace falcon_core::math::labelled_arrays {

/**
 * @brief An array with a context label attached.
 */
class LabelledControlArray : public BaseLabelledArray<double> {
 public:
  /**
   * @brief Construct a new Labelled Control Array object.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledControlArray(
      arrays::ControlArraySP                               array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  /**
   * @brief Another constructor for a new Labelled Control Array object using a
   * BaseArray.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledControlArray(
      arrays::BaseArraySP<double>                          array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);

 protected:
  LabelledControlArray();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArray>(this));
  }
};
using LabelledControlArraySP = std::shared_ptr<LabelledControlArray>;
}  // namespace falcon_core::math::labelled_arrays
