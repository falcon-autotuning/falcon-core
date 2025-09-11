/**
 * @file BaseLabelledArrays.hpp
 * @brief Defines the BaseLabelledArrays template for FalconCore.
 */

#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

namespace falcon_core::math::labelled_arrays {

/**
 * @brief Container for multiple labelled arrays.
 * @param T Type of labelled array.
 */
template <typename T>
class BaseLabelledArrays : public generic::List<BaseLabelledArray<T>> {
 public:
  BaseLabelledArrays() = default;
  BaseLabelledArrays(const std::vector<BaseLabelledArraySP<T>>& items)
      : generic::List<BaseLabelledArray<T>>(items) {
    check_array_labels();
  }
  /**
   * @brief Returns the internal vector of labelled arrays.
   */
  std::vector<BaseLabelledArraySP<T>>& arrays() { return this->items(); }
  /**
   * @brief Returns the labels of all labelled arrays.
   */
  generic::ListSP<autotuner_interfaces::contexts::AcquisitionContext> labels()
      const {
    auto list = std::make_shared<
        generic::List<autotuner_interfaces::contexts::AcquisitionContext>>();
    for (const auto& item : this->items()) {
      list->push_back(item->label());
    }
    return list;
  }
  /**
   * @brief Checks that all array labels are unique.
   * @throws std::runtime_error if any labels are not unique.
   */
  void check_array_labels() const {
    generic::List<autotuner_interfaces::contexts::AcquisitionContext> seen;
    for (autotuner_interfaces::contexts::AcquisitionContextSP& label :
         *labels()) {
      if (seen.contains(label)) {
        throw std::runtime_error("Array labels are not unique.");
      }
      seen.push_back(label);
    }
  }

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<BaseLabelledArray<T>>>(this));
  }
};
}  // namespace falcon_core::math::labelled_arrays
