/**
 * @file BaseLabelledArrays.hpp
 * @brief Defines the BaseLabelledArrays template for FalconCore.
 */

#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
namespace falcon_core::math::arrays {

/**
 * @brief Container for multiple labelled arrays.
 * @param T Type of labelled array.
 */
template <typename ArrayType>
class BaseLabelledArrays : public generic::List<ArrayType> {
  static_assert(std::is_base_of_v<generic::FArray<double>, ArrayType>,
                "T must inherit from FArray");
  static_assert(std::is_base_of_v<IsLabelled<double>, ArrayType>,
                "T must inherit from IsLabelled");

 public:
  BaseLabelledArrays() = default;
  BaseLabelledArrays(const std::vector<std::shared_ptr<ArrayType>>& items)
      : generic::List<std::shared_ptr<ArrayType>>(items) {
    check_array_labels();
  }
  /**
   * @brief Returns the internal vector of labelled arrays.
   */
  std::vector<std::shared_ptr<ArrayType>>& arrays() { return this->items(); }
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
    ar(cereal::base_class<generic::List<ArrayType>>(this));
  }
};
}  // namespace falcon_core::math::arrays
