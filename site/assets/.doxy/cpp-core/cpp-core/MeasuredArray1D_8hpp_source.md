

# File MeasuredArray1D.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**MeasuredArray1D.hpp**](MeasuredArray1D_8hpp.md)

[Go to the documentation of this file](MeasuredArray1D_8hpp.md)


```C++


#pragma once

#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class MeasuredArray1D : public MeasuredArray, public Is1D<double> {
 public:
  using value_type = double;
  MeasuredArray1D();
  MeasuredArray1D(const generic::FArraySP<double>& arr);
  MeasuredArray1D(const MeasuredArraySP& arr);
  MeasuredArray1D(const xt::xarray<double>& arr);
  MeasuredArray1D(xt::xarray<double>&& arr) noexcept;
  static std::shared_ptr<MeasuredArray1D> zeros(
      const std::vector<size_t>& shape) {
    return std::make_shared<MeasuredArray1D>(xt::zeros<double>(shape));
  }
  static std::shared_ptr<MeasuredArray1D> empty(
      const std::vector<size_t>& shape) {
    return std::make_shared<MeasuredArray1D>(xt::empty<double>(shape));
  }
  // Arithmetic operators
  std::shared_ptr<MeasuredArray1D> operator+(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator+(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator+(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<MeasuredArray1D> operator-(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator-(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator-(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> operator-() const;

  std::shared_ptr<MeasuredArray1D> operator*(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator*(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator*(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> operator/(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator/(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator/(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> operator^(const double other) const;

  std::shared_ptr<MeasuredArray1D> abs() const;
  double min() const;

  std::shared_ptr<MeasuredArray1D> min(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const;

  std::shared_ptr<MeasuredArray1D> max(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<MeasuredArray1D> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<MeasuredArray>(this));
  }
};
using MeasuredArray1DSP = std::shared_ptr<MeasuredArray1D>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


