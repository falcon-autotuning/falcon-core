

# File Is1D.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**Is1D.hpp**](Is1D_8hpp.md)

[Go to the documentation of this file](Is1D_8hpp.md)


```C++
#pragma once
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/FArrayProtocol.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
template <typename T>
class Is1D : public virtual generic::IFArray<T> {
 public:
  bool is_1D() const { return this->shape().size() == 1; }
  generic::FArraySP<T> as_1D() const {
    if (!is_1D()) throw std::runtime_error("Not a 1D array");
    return std::make_shared<generic::FArray<T>>(this->data());
  }
  T get_start() const { return (*this)(0); }
  T get_end() const { return (*this)(this->size() - 1); }
  bool is_decreasing() const { return get_start() > get_end(); }
  bool is_increasing() const { return get_start() < get_end(); }
  T get_distance() const { return std::abs(get_start() - get_end()); }
  double get_mean() const { return xt::mean(this->data())(); }

  double get_std() const { return xt::stddev(this->data())(); }

  void reverse() { std::reverse(this->data().begin(), this->data().end()); }

  size_t get_closest_index(double value) const {
    auto& arr = this->data();
    auto  it =
        std::min_element(arr.begin(), arr.end(), [value](double a, double b) {
          return std::abs(a - value) < std::abs(b - value);
        });
    return std::distance(arr.begin(), it);
  }

  generic::ListSP<generic::FArray<T>> even_divisions(size_t divisions) const {
    auto&  arr              = this->data();
    size_t partition_length = arr.size() / divisions;
    if (arr.size() % divisions != 0)
      throw std::runtime_error("Array cannot be evenly divided");
    auto result = std::make_shared<generic::List<generic::FArray<T>>>();
    for (size_t i = 0; i < divisions; ++i) {
      xt::xarray<T> segment = xt::view(
          arr, xt::range(i * partition_length, (i + 1) * partition_length));
      result->push_back(std::make_shared<generic::FArray<T>>(segment));
    }
    return result;
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


