

# File ControlArray.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**ControlArray.hpp**](ControlArray_8hpp.md)

[Go to the documentation of this file](ControlArray_8hpp.md)


```C++

#pragma once

#include "falcon_core/math/arrays/IsControl.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

class ControlArray : public generic::FArray<double>, public IsControl<double> {
 protected:
  friend class cereal::access;
  ControlArray();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<FArray<double>>(this),
       principle_dimension(),
       alignment());
  }

 public:
  ControlArray(const ControlArray& other);
  ControlArray& operator=(const ControlArray& other);
  ControlArray(const xt::xarray<double>& arr);
  ControlArray(const generic::FArraySP<double>& arr);
  ControlArray(xt::xarray<double>&& arr) noexcept;
  // Arithmetic operators
  std::shared_ptr<ControlArray> operator+(const double other) const;

  std::shared_ptr<ControlArray> operator+(const int other) const;

  std::shared_ptr<ControlArray> operator+(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<ControlArray> operator-(const double other) const;

  std::shared_ptr<ControlArray> operator-(const int other) const;

  std::shared_ptr<ControlArray> operator-(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray> operator-() const;

  std::shared_ptr<ControlArray> operator*(const double other) const;

  std::shared_ptr<ControlArray> operator*(const int other) const;

  std::shared_ptr<ControlArray> operator/(const double other) const;

  std::shared_ptr<ControlArray> operator/(const int other) const;

  std::shared_ptr<ControlArray> operator^(const double other) const;

  std::shared_ptr<ControlArray> abs() const;
  double min() const override;

  std::shared_ptr<ControlArray> min(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> min(
      const std::shared_ptr<FArray<double>>& other) const;
  double max() const override;

  std::shared_ptr<ControlArray> max(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray> reshape(const std::vector<size_t>& shape) const;
  std::shared_ptr<ControlArray> flip(size_t axis) const;
  generic::FArraySP<double> gradient(size_t axis) const override;
  generic::ListSP<generic::FArray<double>> gradient() const override;
};
using ControlArraySP = std::shared_ptr<ControlArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


