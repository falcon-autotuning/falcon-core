

# File LabelledArrays.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**LabelledArrays.hpp**](LabelledArrays_8hpp.md)

[Go to the documentation of this file](LabelledArrays_8hpp.md)


```C++


#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
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
  static std::shared_ptr<LabelledArrays<LabelledMeasuredArray>>
  LabelledMeasuredArrays(const std::vector<LabelledMeasuredArraySP>& arrays) {
    return std::make_shared<LabelledArrays<LabelledMeasuredArray>>(arrays);
  }
  static std::shared_ptr<LabelledArrays<LabelledMeasuredArray>>
  LabelledMeasuredArrays() {
    return std::make_shared<LabelledArrays<LabelledMeasuredArray>>();
  }
  static std::shared_ptr<LabelledArrays<LabelledControlArray>>
  LabelledControlArrays(const std::vector<LabelledControlArraySP>& arrays) {
    return std::make_shared<LabelledArrays<LabelledControlArray>>(arrays);
  }
  static std::shared_ptr<LabelledArrays<LabelledControlArray>>
  LabelledControlArrays() {
    return std::make_shared<LabelledArrays<LabelledControlArray>>();
  }
  std::vector<std::shared_ptr<ArrayType>> arrays() { return this->items(); }
  generic::ListSP<autotuner_interfaces::contexts::AcquisitionContext> labels()
      const {
    auto list = std::make_shared<
        generic::List<autotuner_interfaces::contexts::AcquisitionContext>>();
    for (const auto& item : this->items()) {
      list->push_back(item->label());
    }
    return list;
  }
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
  bool is_control_arrays() const {
    for (const std::shared_ptr<ArrayType>& array : this->items()) {
      if (!array || !dynamic_cast<const ControlArray*>(array.get())) {
        return false;
      }
    }
    return true;
  }
  bool is_measured_arrays() const {
    for (const std::shared_ptr<ArrayType>& array : this->items()) {
      if (!array || !dynamic_cast<const MeasuredArray*>(array.get())) {
        return false;
      }
    }
    return true;
  }
};
template <typename T>
using LabelledArraysSP = std::shared_ptr<LabelledArrays<T>>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


