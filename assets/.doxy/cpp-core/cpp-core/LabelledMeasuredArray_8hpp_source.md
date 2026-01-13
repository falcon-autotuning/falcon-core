

# File LabelledMeasuredArray.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**LabelledMeasuredArray.hpp**](LabelledMeasuredArray_8hpp.md)

[Go to the documentation of this file](LabelledMeasuredArray_8hpp.md)


```C++

#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class LabelledMeasuredArray : public MeasuredArray, public IsLabelled<double> {
 public:
  LabelledMeasuredArray(const LabelledMeasuredArray& other);
  LabelledMeasuredArray& operator=(const LabelledMeasuredArray& other);
  LabelledMeasuredArray(
      const arrays::MeasuredArraySP&                              array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledMeasuredArray(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledMeasuredArray(
      const generic::FArraySP<double>&                      array,
      const instrument_interfaces::names::InstrumentPortSP& port);

  // Arithmetic operators
  std::shared_ptr<LabelledMeasuredArray> operator+(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator+(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator+(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-() const;

  std::shared_ptr<LabelledMeasuredArray> operator*(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator*(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator*(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator^(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> abs() const;
  double min() const;

  std::shared_ptr<LabelledMeasuredArray> min(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const;

  std::shared_ptr<LabelledMeasuredArray> max(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<LabelledMeasuredArray> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;
  bool operator==(const LabelledMeasuredArray& other) const;
  bool operator!=(const LabelledMeasuredArray& other) const;

 protected:
  LabelledMeasuredArray();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<MeasuredArray>(this), _label);
  }
};
using LabelledMeasuredArraySP = std::shared_ptr<LabelledMeasuredArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


