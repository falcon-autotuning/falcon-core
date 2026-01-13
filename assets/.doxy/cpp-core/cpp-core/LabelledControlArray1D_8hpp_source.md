

# File LabelledControlArray1D.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**LabelledControlArray1D.hpp**](LabelledControlArray1D_8hpp.md)

[Go to the documentation of this file](LabelledControlArray1D_8hpp.md)


```C++

#pragma once

#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class LabelledControlArray1D : public LabelledControlArray,
                               public Is1D<double> {
 public:
  LabelledControlArray1D(
      const arrays::ControlArraySP&                               array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledControlArray1D(
      const arrays::ControlArray1DSP&                             array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledControlArray1D(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  // Arithmetic operators
  std::shared_ptr<LabelledControlArray1D> operator+(const double other) const;

  std::shared_ptr<LabelledControlArray1D> operator+(const int other) const;

  std::shared_ptr<LabelledControlArray1D> operator+(
      const std::shared_ptr<LabelledControlArray1D>& other) const;

  std::shared_ptr<LabelledControlArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledControlArray1D> operator-(const double other) const;

  std::shared_ptr<LabelledControlArray1D> operator-(const int other) const;

  std::shared_ptr<LabelledControlArray1D> operator-(
      const std::shared_ptr<LabelledControlArray1D>& other) const;

  std::shared_ptr<LabelledControlArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledControlArray1D> operator-() const;

  std::shared_ptr<LabelledControlArray1D> operator*(const double other) const;

  std::shared_ptr<LabelledControlArray1D> operator*(const int other) const;

  std::shared_ptr<LabelledControlArray1D> operator/(const double other) const;

  std::shared_ptr<LabelledControlArray1D> operator/(const int other) const;

  std::shared_ptr<LabelledControlArray1D> operator^(const double other) const;

  std::shared_ptr<LabelledControlArray1D> abs() const;
  double min() const;

  std::shared_ptr<LabelledControlArray1D> min(
      const std::shared_ptr<LabelledControlArray1D>& other) const;

  std::shared_ptr<LabelledControlArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const;

  std::shared_ptr<LabelledControlArray1D> max(
      const std::shared_ptr<LabelledControlArray1D>& other) const;

  std::shared_ptr<LabelledControlArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledControlArray1D> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<LabelledControlArray1D> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;

 protected:
  LabelledControlArray1D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<LabelledControlArray>(this));
  }
};
using LabelledControlArray1DSP = std::shared_ptr<LabelledControlArray1D>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


