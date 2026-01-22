

# File FArray.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**generic**](dir_b58ad87d7b49f24215c248c1165fe6c1.md) **>** [**FArray.hpp**](FArray_8hpp.md)

[Go to the documentation of this file](FArray_8hpp.md)


```C++
#pragma once

#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/xtensor.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include "falcon_core/generic/FArrayProtocol.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Song.hpp"
#define XTENSOR_ENABLE_CEREAL
#include <cereal/archives/binary.hpp>

namespace falcon_core {
namespace generic {

template <typename T>
class FArray : public generic::Song, public virtual IFArray<T> {
 public:
  using array_type      = xt::xarray<T>;
  using value_type      = T;
  using reference       = T&;
  using const_reference = const T&;

  FArray<T>(const FArray<T>& other) { _data = other.data(); }
  FArray<T>& operator=(const FArray<T>& other) {
    if (this != &other) {
      _data = other.data();
    }
    return *this;
  }
  FArray() = default;
  FArray(const array_type& arr) : _data(arr) {}
  FArray(array_type&& arr) noexcept : _data(std::move(arr)) {}
  explicit FArray(const std::vector<size_t>& shape) : _data(shape) {}

  static std::shared_ptr<FArray<T>> zeros(const std::vector<size_t>& shape) {
    return std::make_shared<FArray<T>>(xt::zeros<T>(shape));
  }
  static std::shared_ptr<FArray<T>> empty(const std::vector<size_t>& shape) {
    return std::make_shared<FArray<T>>(xt::empty<T>(shape));
  }

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return data()(std::forward<Args>(args)...);
  }
  template <typename... Args>
  decltype(auto) operator()(Args&&... args) const {
    return data()(std::forward<Args>(args)...);
  }
  reference       operator()(size_t i) override { return data()(i); }
  const_reference operator()(size_t i) const override { return data()(i); }

  [[nodiscard]] const xt::dynamic_shape<size_t>& shape()
      const noexcept override {
    return data().shape();
  }
  [[nodiscard]] size_t size() const noexcept override { return _data.size(); }
  [[nodiscard]] size_t dimension() const noexcept override {
    return _data.dimension();
  }
  [[nodiscard]] T* raw_data() noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data.data();
  }
  [[nodiscard]] const T* raw_data() const noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data.data();
  }
  [[nodiscard]] array_type& data() noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data;
  }
  [[nodiscard]] const array_type& data() const noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data;
  }

  typename array_type::iterator begin() noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data.begin();
  }
  typename array_type::iterator end() noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data.end();
  }
  typename array_type::const_iterator cbegin() const noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data.cbegin();
  }
  typename array_type::const_iterator cend() const noexcept override {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_data);
    return _data.cend();
  }

  FArray<T>& operator+=(const FArray<T>& other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data += other.data();
    return *this;
  }
  FArray<T>& operator+=(const double other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    auto ones = xt::ones_like(_data) * other;
    _data += ones;
    return *this;
  }
  FArray<T>& operator+=(const int other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    auto ones = xt::ones_like(_data) * other;
    _data += ones;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator+(const double other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result.data()) * other;
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data += ones;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator+(const int other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result.data()) * other;
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data += ones;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator+(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for addition.");
    }
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data += other->data();
    return std::make_shared<FArray<T>>(result);
  }
  FArray<T>& operator-=(const FArray<T>& other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data = _data - other.data();
    return *this;
  }
  FArray<T>& operator-=(const double other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    auto ones = xt::ones_like(_data) * other;
    _data     = _data - ones;
    return *this;
  }
  FArray<T>& operator-=(const int other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    auto ones = xt::ones_like(_data) * other;
    _data     = _data - ones;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator-() const {
    FArray<T> result(*this);
    return result * -1;
  }
  std::shared_ptr<FArray<T>> operator-() { return (*this) * -1; }
  std::shared_ptr<FArray<T>> operator-(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for subtraction.");
    }
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data -= other->data();
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator-(const double other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result.data()) * other;
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data -= ones;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator-(const int other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result.data()) * other;
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data -= ones;
    return std::make_shared<FArray<T>>(result);
  }
  FArray<T>& operator*=(const double other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data *= other;
    return *this;
  }
  FArray<T>& operator*=(const int other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data *= other;
    return *this;
  }
  FArray<T>& operator*=(const FArray<T>& other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data *= other._data;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator*(const double other) const {
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data *= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator*(const int other) const {
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data *= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator*(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for multiplication.");
    }
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data *= other->data();
    return std::make_shared<FArray<T>>(result);
  }
  FArray<T>& operator/=(const double other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data /= other;
    return *this;
  }
  FArray<T>& operator/=(const int other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data /= other;
    return *this;
  }
  FArray<T>& operator/=(const FArray<T>& other) {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data /= other._data;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator/(const double other) const {
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data /= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator/(const int other) const {
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data /= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator/(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for division.");
    }
    FArray<T>                                 result(*this);
    std::shared_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data /= other->data();
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<double>> operator^(const double other) const {
    return std::make_shared<FArray<double>>(xt::pow(this->data(), other));
  }
  std::shared_ptr<FArray<T>> operator^(const int other) const {
    return std::make_shared<FArray<T>>(xt::pow(this->data(), other));
  }
  void pow_inplace(const T other) {
    this->_data = xt::pow(this->data(), other);
  }
  std::shared_ptr<FArray<T>> abs() const {
    FArray<T>                                 result(*this);
    std::unique_lock<std::shared_timed_mutex> lock_data(result._mu_data);
    result._data = xt::abs(result._data);
    lock_data.unlock();
    return std::make_shared<FArray<T>>(result);
  }
  T                          min() const override { return xt::amin(data())(); }
  std::shared_ptr<FArray<T>> min(const std::shared_ptr<FArray<T>> other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for min.");
    }
    return std::make_shared<FArray<T>>(xt::minimum(data(), other->data()));
  }
  T                          max() const override { return xt::amax(data())(); }
  std::shared_ptr<FArray<T>> max(const std::shared_ptr<FArray<T>> other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for max.");
    }
    return std::make_shared<FArray<T>>(xt::maximum(data(), other->data()));
  }

  template <typename... Args>
  decltype(auto) view(Args&&... args) {
    return xt::view(data(), std::forward<Args>(args)...);
  }
  template <typename... Args>
  decltype(auto) view(Args&&... args) const {
    return xt::view(data(), std::forward<Args>(args)...);
  }
  // Assignment and conversion
  FArray<T>& operator=(const array_type& arr) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_data);
    _data = arr;
    return *this;
  }
  operator array_type&() override { return data(); }
  operator const array_type&() const override { return data(); }

  bool operator==(const FArray<T>& other) const {
    return data() == other.data();
  }
  bool operator!=(const FArray<T>& other) const { return !(*this == other); }
  bool operator>(const T& value) const override {
    return xt::any(data() > value);
  }

  bool operator<(const T& value) const override {
    return xt::any(data() < value);
  }

  void remove_offset(const T& offset) override {
    std::unique_lock<std::shared_timed_mutex> lock_data(_mu_data);
    _data -= offset;
  }

  T sum() const override { return xt::sum(data())(); }

  std::shared_ptr<FArray<T>> reshape(const std::vector<size_t>& shape) const {
    return std::make_shared<FArray<T>>(xt::reshape_view(data(), shape));
  }

  ListSP<List<size_t>> where(const T& value) const override {
    auto mask    = xt::equal(data(), value);
    auto indices = std::make_shared<List<List<size_t>>>();
    for (size_t i = 0; i < data().size(); ++i) {
      if (mask.flat(i)) {
        auto idx      = xt::unravel_index(i, data().shape());
        auto idx_list = std::make_shared<List<size_t>>();
        for (auto v : idx) idx_list->push_back(static_cast<size_t>(v));
        indices->push_back(idx_list);
      }
    }
    return indices;
  }

  std::shared_ptr<FArray<T>> flip(size_t axis) const {
    return std::make_shared<FArray<T>>(xt::flip(data(), axis));
  }

  ListSP<FArray<T>> gradient() const {
    auto   grads = std::make_shared<List<FArray<T>>>();
    size_t ndim  = data().dimension();
    for (size_t axis = 0; axis < ndim; ++axis) {
      grads->push_back(gradient(axis));
    }
    return grads;
  }

  std::shared_ptr<FArray<T>> gradient(size_t axis) const {
    auto          shape = data().shape();
    xt::xarray<T> grad  = xt::zeros<T>(shape);

    // Iterate over all indices, compute finite difference along axis
    xt::xindex idx(shape.size(), 0);
    auto       total = data().size();
    for (size_t flat = 0; flat < total; ++flat) {
      auto unravel = xt::unravel_index(flat, shape);
      idx.clear();
      for (auto v : unravel) idx.push_back(static_cast<unsigned long>(v));

      xt::xindex idx_prev = idx;
      xt::xindex idx_next = idx;

      if (idx[axis] == 0) {
        idx_next[axis]  = 1;
        grad.flat(flat) = data()[idx_next] - data()[idx];
      } else if (idx[axis] == shape[axis] - 1) {
        idx_prev[axis]  = shape[axis] - 2;
        grad.flat(flat) = data()[idx] - data()[idx_prev];
      } else {
        idx_prev[axis]  = idx[axis] - 1;
        idx_next[axis]  = idx[axis] + 1;
        grad.flat(flat) = (data()[idx_next] - data()[idx_prev]) / 2;
      }
    }
    return std::make_shared<FArray<T>>(grad);
  }

  double get_sum_of_squares() const { return (*this ^ 2.0)->sum(); }
  double get_sum_of_squares(const int other) const {
    return (*(*this - other) ^ 2.0)->sum();
  }
  double get_sum_of_squares(const double other) const {
    return (*(*this - other) ^ 2.0)->sum();
  }
  double get_sum_of_squares(
      const std::shared_ptr<generic::FArray<T>>& other) const {
    return (*(*this - other) ^ 2.0)->sum();
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_data(_mu_data);
    ar(cereal::base_class<generic::Song>(this), _data);
  }

 private:
  array_type                      _data;
  mutable std::shared_timed_mutex _mu_data;
};
template <typename T>
using FArraySP = std::shared_ptr<FArray<T>>;

}  // namespace generic
}  // namespace falcon_core
```


