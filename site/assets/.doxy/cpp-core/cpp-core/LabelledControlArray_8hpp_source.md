

# File LabelledControlArray.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**LabelledControlArray.hpp**](LabelledControlArray_8hpp.md)

[Go to the documentation of this file](LabelledControlArray_8hpp.md)


```C++


#pragma once

#include "cereal/types/base_class.hpp"
#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class LabelledControlArray : public ControlArray, public IsLabelled<double> {
 public:
  LabelledControlArray(const LabelledControlArray& other);
  LabelledControlArray& operator=(const LabelledControlArray& other);
  LabelledControlArray(
      const arrays::ControlArraySP&                               array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledControlArray(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledControlArray(
      const generic::FArraySP<double>&                      array,
      const instrument_interfaces::names::InstrumentPortSP& port);

  // Arithmetic operators
  std::shared_ptr<LabelledControlArray> operator+(const double other) const;

  std::shared_ptr<LabelledControlArray> operator+(const int other) const;

  std::shared_ptr<LabelledControlArray> operator+(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledControlArray> operator-(const double other) const;

  std::shared_ptr<LabelledControlArray> operator-(const int other) const;

  std::shared_ptr<LabelledControlArray> operator-(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledControlArray> operator-() const;

  std::shared_ptr<LabelledControlArray> operator*(const double other) const;

  std::shared_ptr<LabelledControlArray> operator*(const int other) const;

  std::shared_ptr<LabelledControlArray> operator/(const double other) const;

  std::shared_ptr<LabelledControlArray> operator/(const int other) const;

  std::shared_ptr<LabelledControlArray> operator^(const double other) const;

  std::shared_ptr<LabelledControlArray> abs() const;
  double min() const;

  std::shared_ptr<LabelledControlArray> min(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const;

  std::shared_ptr<LabelledControlArray> max(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledControlArray> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<LabelledControlArray> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;
  bool operator==(const LabelledControlArray& other) const;
  bool operator!=(const LabelledControlArray& other) const;

 protected:
  LabelledControlArray();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray>(this), _label);
  }
};
using LabelledControlArraySP = std::shared_ptr<LabelledControlArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


