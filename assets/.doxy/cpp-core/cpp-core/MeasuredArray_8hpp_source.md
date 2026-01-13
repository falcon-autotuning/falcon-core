

# File MeasuredArray.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**MeasuredArray.hpp**](MeasuredArray_8hpp.md)

[Go to the documentation of this file](MeasuredArray_8hpp.md)


```C++

#pragma once

#include "falcon_core/generic/FArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class MeasuredArray : public generic::FArray<double> {
 protected:
  friend class cereal::access;
  MeasuredArray();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<FArray<double>>(this));
  }

 public:
  MeasuredArray(const MeasuredArray& other);
  MeasuredArray& operator=(const MeasuredArray& other);
  MeasuredArray(const generic::FArraySP<double>& arr);
  MeasuredArray(const xt::xarray<double>& arr);
  MeasuredArray(xt::xarray<double>&& arr) noexcept;
  // Arithmetic operators
  std::shared_ptr<MeasuredArray> operator+(const double other) const;

  std::shared_ptr<MeasuredArray> operator+(const int other) const;

  std::shared_ptr<MeasuredArray> operator+(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<MeasuredArray> operator-(const double other) const;

  std::shared_ptr<MeasuredArray> operator-(const int other) const;

  std::shared_ptr<MeasuredArray> operator-(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> operator-() const;

  std::shared_ptr<MeasuredArray> operator*(const double other) const;

  std::shared_ptr<MeasuredArray> operator*(const int other) const;

  std::shared_ptr<MeasuredArray> operator*(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> operator/(const double other) const;

  std::shared_ptr<MeasuredArray> operator/(const int other) const;

  std::shared_ptr<MeasuredArray> operator/(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> operator^(const double other) const;

  std::shared_ptr<MeasuredArray> abs() const;
  double min() const override;

  std::shared_ptr<MeasuredArray> min(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const override;

  std::shared_ptr<MeasuredArray> max(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> reshape(
      const std::vector<size_t>& shape) const;
  std::shared_ptr<MeasuredArray> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const;
  generic::ListSP<generic::FArray<double>> gradient() const;
  bool operator==(const MeasuredArray& other) const;
  bool operator!=(const MeasuredArray& other) const;
};
using MeasuredArraySP = std::shared_ptr<MeasuredArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


