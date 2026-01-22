#pragma once
#include "falcon_core/export.h"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/FArrayProtocol.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
template <typename T>
class FALCON_CORE_CPP_API Is1D : public virtual generic::IFArray<T> {
 public:
  /**
   * @brief Check if the array is 1D.
   * @returns True if the array is 1D, False otherwise.
   */
  bool is_1D() const { return this->shape().size() == 1; }
  /**
   * @brief Return the data as a 1D array.
   * @returns The data as a 1D array.
   * @throws std::runtime_error if not 1D.
   */
  generic::FArraySP<T> as_1D() const {
    if (!is_1D()) throw std::runtime_error("Not a 1D array");
    return std::make_shared<generic::FArray<T>>(this->data());
  }
  /**
   * @brief Get the first element of the 1D array.
   * @returns The first element of the 1D array.
   */
  T get_start() const { return (*this)(0); }
  /**
   * @brief Get the last element of the 1D array.
   * @returns The last element of the 1D array.
   */
  T get_end() const { return (*this)(this->size() - 1); }
  /**
   * @brief Check if the array is decreasing.
   * @returns True if the array is decreasing, False otherwise.
   */
  bool is_decreasing() const { return get_start() > get_end(); }
  /**
   * @brief Check if the array is increasing.
   * @returns True if the array is increasing, False otherwise.
   */
  bool is_increasing() const { return get_start() < get_end(); }
  /**
   * @brief Get the distance between the first and last element of the 1D
   * array.
   * @returns The distance between the first and last element of the 1D array.
   */
  T get_distance() const { return std::abs(get_start() - get_end()); }
  /**
   * @brief Get the mean of the 1D array.
   * @returns The mean value.
   */
  double get_mean() const { return xt::mean(this->data())(); }

  /**
   * @brief Get the standard deviation of the 1D array.
   * @returns The standard deviation value.
   */
  double get_std() const { return xt::stddev(this->data())(); }

  /**
   * @brief Reverse the 1D array.
   */
  void reverse() { std::reverse(this->data().begin(), this->data().end()); }

  /**
   * @brief Get the index of the closest element to the given value.
   * @param value The value to find the closest index to.
   * @returns The index of the closest element.
   */
  size_t get_closest_index(double value) const {
    auto& arr = this->data();
    auto  it =
        std::min_element(arr.begin(), arr.end(), [value](double a, double b) {
          return std::abs(a - value) < std::abs(b - value);
        });
    return std::distance(arr.begin(), it);
  }

  /**
   * @brief Splits the array into even divisions if possible.
   * @param divisions The number of divisions to split the array into.
   * @returns The divisions as a ListSP of BaseArray segments.
   * @throws std::runtime_error if array cannot be evenly divided.
   */
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
