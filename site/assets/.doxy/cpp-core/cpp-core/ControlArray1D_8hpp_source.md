

# File ControlArray1D.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**ControlArray1D.hpp**](ControlArray1D_8hpp.md)

[Go to the documentation of this file](ControlArray1D_8hpp.md)


```C++


#pragma once

#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/Is1D.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class ControlArray1D : public ControlArray, public Is1D<double> {
 protected:
  friend class cereal::access;
  ControlArray1D();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray>(this),
       principle_dimension(),
       alignment());
  }

 public:
  ControlArray1D(const xt::xarray<double>& arr);
  ControlArray1D(const generic::FArraySP<double>& arr);
  ControlArray1D(const ControlArraySP& arr);
  ControlArray1D(xt::xarray<double>&& arr) noexcept;
  // Arithmetic operators
  std::shared_ptr<ControlArray1D> operator+(const double other) const;

  std::shared_ptr<ControlArray1D> operator+(const int other) const;

  std::shared_ptr<ControlArray1D> operator+(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<ControlArray1D> operator-(const double other) const;

  std::shared_ptr<ControlArray1D> operator-(const int other) const;

  std::shared_ptr<ControlArray1D> operator-(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray1D> operator-() const;

  std::shared_ptr<ControlArray1D> operator*(const double other) const;

  std::shared_ptr<ControlArray1D> operator*(const int other) const;

  std::shared_ptr<ControlArray1D> operator/(const double other) const;

  std::shared_ptr<ControlArray1D> operator/(const int other) const;

  std::shared_ptr<ControlArray1D> operator^(const double other) const;

  std::shared_ptr<ControlArray1D> abs() const;
  double min() const;

  std::shared_ptr<ControlArray1D> min(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const;

  std::shared_ptr<ControlArray1D> max(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray1D> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<ControlArray1D> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;
};
using ControlArray1DSP = std::shared_ptr<ControlArray1D>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


