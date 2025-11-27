/**
 * @file BaseLabelledArrays.hpp
 * @brief Defines the BaseLabelledArrays template for FalconCore.
 */

#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
/**
 * @brief Container for multiple labelled arrays.
 * @param T Type of labelled array.
 */
template <typename ArrayType>
class LabelledArrays : public generic::List<ArrayType> {
  static_assert(std::is_base_of<generic::FArray<double>, ArrayType>::value,
                "T must inherit from FArray");
  static_assert(std::is_base_of<IsLabelled<double>, ArrayType>::value,
                "T must inherit from IsLabelled");

 public:
  LabelledArrays() : generic::List<ArrayType>() {}
  LabelledArrays(const std::vector<std::shared_ptr<ArrayType>>& items)
      : generic::List<ArrayType>(items) {
    check_array_labels();
  }
  /**
   * @brief Construct a collection of labelled measured arrays.
   */
  static std::shared_ptr<LabelledArrays<LabelledMeasuredArray>>
  LabelledMeasuredArrays(const std::vector<LabelledMeasuredArraySP>& arrays) {
    return std::make_shared<LabelledArrays<LabelledMeasuredArray>>(arrays);
  }
  static std::shared_ptr<LabelledArrays<LabelledMeasuredArray>>
  LabelledMeasuredArrays() {
    return std::make_shared<LabelledArrays<LabelledMeasuredArray>>();
  }
  /**
   * @brief Construct a collection of labelled control arrays.
   */
  static std::shared_ptr<LabelledArrays<LabelledControlArray>>
  LabelledControlArrays(const std::vector<LabelledControlArraySP>& arrays) {
    return std::make_shared<LabelledArrays<LabelledControlArray>>(arrays);
  }
  static std::shared_ptr<LabelledArrays<LabelledControlArray>>
  LabelledControlArrays() {
    return std::make_shared<LabelledArrays<LabelledControlArray>>();
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
    auto all_labels = *labels();
    for (autotuner_interfaces::contexts::AcquisitionContextSP& label :
         all_labels) {
      if (seen.contains(label)) {
        throw std::runtime_error("Array labels are not unique.");
      }
      seen.push_back(label);
    }
  }
  /**
   * @brief Checks if the contents are of control arrays.
   */
  bool is_control_arrays() const {
    for (const std::shared_ptr<ArrayType>& array : this->items()) {
      if (!array || !dynamic_cast<const ControlArray*>(array.get())) {
        return false;
      }
    }
    return true;
  }
  /**
   * @brief Checks if the contents are of measured arrays.
   */
  bool is_measured_arrays() const {
    for (const std::shared_ptr<ArrayType>& array : this->items()) {
      if (!array || !dynamic_cast<const MeasuredArray*>(array.get())) {
        return false;
      }
    }
    return true;
  }

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<ArrayType>>(this));
  }
};
template <typename T>
using LabelledArraysSP = std::shared_ptr<LabelledArrays<T>>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
