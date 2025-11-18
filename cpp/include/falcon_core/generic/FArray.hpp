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

  FArray() = default;
  FArray(const array_type& arr) : _data(arr) {}
  FArray(array_type&& arr) noexcept : _data(std::move(arr)) {}
  explicit FArray(const std::vector<size_t>& shape) : _data(shape) {}

  FArray(const FArray&)                   = default;
  FArray(FArray&&) noexcept               = default;
  FArray<T>& operator=(const FArray&)     = default;
  FArray<T>& operator=(FArray&&) noexcept = default;

  static std::shared_ptr<FArray<T>> zeros(const std::vector<size_t>& shape) {
    return std::make_shared<FArray<T>>(xt::zeros<T>(shape));
  }
  static std::shared_ptr<FArray<T>> empty(const std::vector<size_t>& shape) {
    return std::make_shared<FArray<T>>(xt::empty<T>(shape));
  }

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return _data(std::forward<Args>(args)...);
  }
  template <typename... Args>
  decltype(auto) operator()(Args&&... args) const {
    return _data(std::forward<Args>(args)...);
  }
  reference       operator()(size_t i) override { return _data(i); }
  const_reference operator()(size_t i) const override { return _data(i); }

  [[nodiscard]] const xt::dynamic_shape<size_t>& shape()
      const noexcept override {
    return _data.shape();
  }
  [[nodiscard]] size_t size() const noexcept override { return _data.size(); }
  [[nodiscard]] size_t dimension() const noexcept override {
    return _data.dimension();
  }
  [[nodiscard]] T*       data() noexcept override { return _data.data(); }
  [[nodiscard]] const T* data() const noexcept override { return _data.data(); }

  typename array_type::iterator begin() noexcept override {
    return _data.begin();
  }
  typename array_type::iterator end() noexcept override { return _data.end(); }
  typename array_type::const_iterator cbegin() const noexcept override {
    return _data.cbegin();
  }
  typename array_type::const_iterator cend() const noexcept override {
    return _data.cend();
  }

  FArray<T>& operator+=(const FArray<T>& other) {
    _data += other._data;
    return *this;
  }
  FArray<T>& operator+=(const double other) {
    auto ones = xt::ones_like(_data) * other;
    _data += ones;
    return *this;
  }
  FArray<T>& operator+=(const int other) {
    auto ones = xt::ones_like(_data) * other;
    _data += ones;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator+(const double other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result._data) * other;
    result._data += ones;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator+(const int other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result._data) * other;
    result._data += ones;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator+(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for addition.");
    }
    FArray<T> result(*this);
    result._data += other->_data;
    return std::make_shared<FArray<T>>(result);
  }
  FArray<T>& operator-=(const FArray<T>& other) {
    _data = _data - other._data;
    return *this;
  }
  FArray<T>& operator-=(const double other) {
    auto ones = xt::ones_like(_data) * other;
    _data     = _data - ones;
    return *this;
  }
  FArray<T>& operator-=(const int other) {
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
    FArray<T> result(*this);
    result._data -= other->_data;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator-(const double other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result._data) * other;
    result._data -= ones;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator-(const int other) const {
    FArray<T> result(*this);
    auto      ones = xt::ones_like(result._data) * other;
    result._data -= ones;
    return std::make_shared<FArray<T>>(result);
  }
  FArray<T>& operator*=(const double other) {
    _data *= other;
    return *this;
  }
  FArray<T>& operator*=(const int other) {
    _data *= other;
    return *this;
  }
  FArray<T>& operator*=(const FArray<T>& other) {
    _data *= other._data;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator*(const double other) const {
    FArray<T> result(*this);
    result._data *= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator*(const int other) const {
    FArray<T> result(*this);
    result._data *= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator*(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for multiplication.");
    }
    FArray<T> result(*this);
    result._data *= other->_data;
    return std::make_shared<FArray<T>>(result);
  }
  FArray<T>& operator/=(const double other) {
    _data /= other;
    return *this;
  }
  FArray<T>& operator/=(const int other) {
    _data /= other;
    return *this;
  }
  FArray<T>& operator/=(const FArray<T>& other) {
    _data /= other._data;
    return *this;
  }
  std::shared_ptr<FArray<T>> operator/(const double other) const {
    FArray<T> result(*this);
    result._data /= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator/(const int other) const {
    FArray<T> result(*this);
    result._data /= other;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<T>> operator/(
      const std::shared_ptr<FArray<T>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for division.");
    }
    FArray<T> result(*this);
    result._data /= other->_data;
    return std::make_shared<FArray<T>>(result);
  }
  std::shared_ptr<FArray<double>> operator^(const double other) const {
    FArray<double> result(*this);
    result._data = xt::pow(result._data, other);
    return std::make_shared<FArray<double>>(result);
  }
  std::shared_ptr<FArray<T>> operator^(const int other) const {
    FArray<T> result(*this);
    result._data = xt::pow(result._data, other);
    return std::make_shared<FArray<T>>(result);
  }
  void operator^(const T other) { this->_data = xt::pow(this->_data, other); }
  std::shared_ptr<FArray<T>> abs() const {
    FArray<T> result(*this);
    result._data = xt::abs(result._data);
    return std::make_shared<FArray<T>>(result);
  }
  T                          min() const override { return xt::amin(_data)(); }
  std::shared_ptr<FArray<T>> min(const std::shared_ptr<FArray<T>> other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for min.");
    }
    return std::make_shared<FArray<T>>(xt::minimum(_data, other->_data));
  }
  T                          max() const override { return xt::amax(_data)(); }
  std::shared_ptr<FArray<T>> max(const std::shared_ptr<FArray<T>> other) const {
    if (!other) {
      throw std::invalid_argument(
          "FArray: The other array cannot be null for max.");
    }
    return std::make_shared<FArray<T>>(xt::maximum(_data, other->_data));
  }

  template <typename... Args>
  decltype(auto) view(Args&&... args) {
    return xt::view(_data, std::forward<Args>(args)...);
  }
  template <typename... Args>
  decltype(auto) view(Args&&... args) const {
    return xt::view(_data, std::forward<Args>(args)...);
  }
  // Assignment and conversion
  FArray<T>& operator=(const array_type& arr) {
    _data = arr;
    return *this;
  }
  operator array_type&() override { return _data; }
  operator const array_type&() const override { return _data; }

  bool operator==(const FArray<T>& other) const {
    return xtensor() == other.xtensor();
  }
  bool operator!=(const FArray<T>& other) const { return !(*this == other); }
  /**
   * @brief Check if any of the data is greater than the value.
   * @param value The value to compare to.
   * @return True if any of the data is greater than the value, False otherwise.
   */
  bool operator>(const T& value) const override {
    return xt::any(_data > value);
  }

  /**
   * @brief Check if any of the data is less than the value.
   * @param value The value to compare to.
   * @return True if any of the data is less than the value, False otherwise.
   */
  bool operator<(const T& value) const override {
    return xt::any(_data < value);
  }

  /**
   * @brief Remove the offset from the data.
   * @param offset The offset to remove.
   */
  void remove_offset(const T& offset) override { _data -= offset; }

  /**
   * @brief Return the sum of the data.
   * @return The sum of the data.
   */
  T sum() const override { return xt::sum(_data)(); }

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped FArray.
   */
  std::shared_ptr<FArray<T>> reshape(const std::vector<size_t>& shape) const {
    return std::make_shared<FArray<T>>(xt::reshape_view(_data, shape));
  }

  /**
   * @brief Return the indices of the data where the value is.
   * @param value The value to search for.
   * @return Indices where the value matches.
   */
  ListSP<List<size_t>> where(const T& value) const override {
    auto mask    = xt::equal(_data, value);
    auto indices = std::make_shared<List<List<size_t>>>();
    for (size_t i = 0; i < _data.size(); ++i) {
      if (mask.flat(i)) {
        auto idx      = xt::unravel_index(i, _data.shape());
        auto idx_list = std::make_shared<List<size_t>>();
        for (auto v : idx) idx_list->push_back(static_cast<size_t>(v));
        indices->push_back(idx_list);
      }
    }
    return indices;
  }

  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped FArray.
   */
  std::shared_ptr<FArray<T>> flip(size_t axis) const {
    return std::make_shared<FArray<T>>(xt::flip(_data, axis));
  }

  /**
   * @brief Return the gradient of the data along all axes.
   *
   * Computes the gradient for each axis of the array using finite differences:
   * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
   * - For boundary points, uses forward (first element) or backward (last
   * element) difference.
   *
   * @return A vector of FArray gradients (one for each axis).
   */
  ListSP<FArray<T>> gradient() const {
    auto   grads = std::make_shared<List<FArray<T>>>();
    size_t ndim  = _data.dimension();
    for (size_t axis = 0; axis < ndim; ++axis) {
      grads->push_back(gradient(axis));
    }
    return grads;
  }

  /**
   * @brief Return the gradient of the data along a given axis.
   *
   * Computes the gradient along the specified axis using finite differences:
   * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
   * - For boundary points, uses forward (first element) or backward (last
   * element) difference.
   *
   * @param axis The axis to compute the gradient.
   * @return The gradient FArray.
   */
  std::shared_ptr<FArray<T>> gradient(size_t axis) const {
    auto          shape = _data.shape();
    xt::xarray<T> grad  = xt::zeros<T>(shape);

    // Iterate over all indices, compute finite difference along axis
    xt::xindex idx(shape.size(), 0);
    auto       total = _data.size();
    for (size_t flat = 0; flat < total; ++flat) {
      auto unravel = xt::unravel_index(flat, shape);
      idx.clear();
      for (auto v : unravel) idx.push_back(static_cast<unsigned long>(v));

      xt::xindex idx_prev = idx;
      xt::xindex idx_next = idx;

      if (idx[axis] == 0) {
        idx_next[axis]  = 1;
        grad.flat(flat) = _data[idx_next] - _data[idx];
      } else if (idx[axis] == shape[axis] - 1) {
        idx_prev[axis]  = shape[axis] - 2;
        grad.flat(flat) = _data[idx] - _data[idx_prev];
      } else {
        idx_prev[axis]  = idx[axis] - 1;
        idx_next[axis]  = idx[axis] + 1;
        grad.flat(flat) = (_data[idx_next] - _data[idx_prev]) / 2;
      }
    }
    return std::make_shared<FArray<T>>(grad);
  }

  array_type&       xtensor() noexcept override { return _data; }
  const array_type& xtensor() const noexcept override { return _data; }

  double get_sum_of_squares() const { return (*this ^ 2)->sum(); }
  double get_sum_of_squares(const int other) const {
    return (*(*this - other) ^ 2).sum();
  }
  double get_sum_of_squares(const double other) const {
    return (*(*this - other) ^ 2).sum();
  }
  double get_sum_of_squares(
      const std::shared_ptr<generic::FArray<T>>& other) const {
    return (*(*this - other) ^ 2).sum();
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _data);
  }

 private:
  array_type _data;
};
template <typename T>
using FArraySP = std::shared_ptr<FArray<T>>;

}  // namespace generic
}  // namespace falcon_core
