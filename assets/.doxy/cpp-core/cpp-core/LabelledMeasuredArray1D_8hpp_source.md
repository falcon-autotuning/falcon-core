

# File LabelledMeasuredArray1D.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**LabelledMeasuredArray1D.hpp**](LabelledMeasuredArray1D_8hpp.md)

[Go to the documentation of this file](LabelledMeasuredArray1D_8hpp.md)


```C++

#pragma once

#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray1D.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class LabelledMeasuredArray1D : public LabelledMeasuredArray,
                                public Is1D<double> {
 public:
  LabelledMeasuredArray1D(
      const arrays::MeasuredArraySP&                              array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledMeasuredArray1D(
      const arrays::MeasuredArray1DSP&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledMeasuredArray1D(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  // Arithmetic operators
  std::shared_ptr<LabelledMeasuredArray1D> operator+(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator+(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator+(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-() const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator^(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> abs() const;
  double min() const;

  std::shared_ptr<LabelledMeasuredArray1D> min(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const;

  std::shared_ptr<LabelledMeasuredArray1D> max(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<LabelledMeasuredArray1D> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;

 protected:
  LabelledMeasuredArray1D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<LabelledMeasuredArray>(this));
  }
};
using LabelledMeasuredArray1DSP = std::shared_ptr<LabelledMeasuredArray1D>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


