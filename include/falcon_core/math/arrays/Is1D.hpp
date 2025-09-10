#pragma once
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/math/arrays/BaseArray.hpp"
namespace falcon_core::math::arrays {
template <typename T>
struct is_farray : std::false_type {};

template <typename U>
struct is_farray<generic::FArray<U>> : std::true_type {};

template <typename T>
concept IsFArray = is_farray<T>::value;
/// @brief CRTP mixin that provides 1D-specific functionality to array classes.
/// The class that inherits from this must satisfy the IsFArray concept.
template <typename Derived>
class Is1D {
 public:
  /**
   * @brief Check if the array is 1D.
   * @returns True if the array is 1D, False otherwise.
   */
  bool is_1D() const {
    static_assert(IsFArray<Derived>, "Is1D mixin requires IsFArray type.");
    return static_cast<const Derived*>(this)->shape().size() == 1;
  }

  /**
   * @brief Return the data as a 1D array.
   * @returns The data as a 1D array.
   * @throws std::runtime_error if not 1D.
   */
  xt::xarray<typename Derived::value_type> as_1D() const {
    if (!is_1D()) throw std::runtime_error("Not a 1D array");
    return static_cast<const Derived*>(this)->data();
  }
  /**
   * @brief Get a single item from the 1D array at the specified index.
   * @param index The index to access.
   * @returns The scalar value at the index.
   * @throws std::out_of_range if index is invalid.
   */
  typename Derived::value_type get_item_1d(size_t index) const {
    return static_cast<const Derived*>(this)->at(index);
  }

  /**
   * @brief Get a slice of items from the 1D array.
   * @param start The starting index of the slice.
   * @param end The ending index (exclusive) of the slice.
   * @returns A BaseArray containing the sliced values.
   * @throws std::out_of_range if indices are invalid.
   */
  BaseArraySP<typename Derived::value_type> get_slice_1d(size_t start,
                                                         size_t end) const {
    auto d = static_cast<const Derived*>(this);
    if (start > end || end > d->size())
      throw std::out_of_range("Invalid slice indices");
    return BaseArray<typename Derived::value_type>(
        std::vector<typename Derived::value_type>(d->data().begin() + start,
                                                  d->data().begin() + end));
  }

  /**
   * @brief Get values at multiple indices from the 1D array.
   * @param indices The list of indices to access.
   * @returns A vector containing the values at the specified indices.
   * @throws std::out_of_range if any index is invalid.
   */
  generic::ListSP<typename Derived::value_type> get_indices_1d(
      const generic::ListSP<size_t>& indices) const {
    auto d = static_cast<const Derived*>(this);
    generic::ListSP<typename Derived::value_type> result;
    for (auto idx : *indices) {
      if (idx >= d->size()) throw std::out_of_range("Index out of range");
      result->push_back(d->at(idx));
    }
    return result;
  }

  /**
   * @brief Return iterator over the data.
   * @returns Iterator to the beginning of the data.
   */
  typename Derived::value_type begin() const { return as_1D().begin(); }
  typename Derived::value_type end() const { return as_1D().end(); }

  /**
   * @brief Return the length of the data.
   * @returns The length of the data.
   */
  size_t length() const { return as_1D().size(); }

  /**
   * @brief Get the first element of the 1D array.
   * @returns The first element of the 1D array.
   */
  typename Derived::value_type get_start() const {
    return static_cast<const Derived*>(this)->at(0);
  }

  /**
   * @brief Get the last element of the 1D array.
   * @returns The last element of the 1D array.
   */
  typename Derived::value_type get_end() const {
    auto d = static_cast<const Derived*>(this);
    return d->at(d->size() - 1);
  }

  /**
   * @brief Get the minimum value in the 1D array.
   * @returns The minimum value in the 1D array.
   */
  typename Derived::value_type get_min() const { return as_1D().min(); }

  /**
   * @brief Get the maximum value in the 1D array.
   * @returns The maximum value in the 1D array.
   */
  typename Derived::value_type get_max() const { return as_1D().max(); }

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
   * @brief Get the distance between the first and last element of the 1D array.
   * @returns The distance between the first and last element of the 1D array.
   */
  typename Derived::value_type get_distance() const {
    return std::abs(get_start() - get_end());
  }

  /**
   * @brief Get the mean of the 1D array.
   * @returns The mean value.
   */
  double get_mean() const {
    auto  d   = static_cast<const Derived*>(this);
    auto& arr = d->data();
    return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
  }

  /**
   * @brief Get the standard deviation of the 1D array.
   * @returns The standard deviation value.
   */
  double get_std() const {
    auto   d      = static_cast<const Derived*>(this);
    auto&  arr    = d->data();
    double mean   = get_mean();
    double sum_sq = 0.0;
    for (auto v : arr) sum_sq += (v - mean) * (v - mean);
    return std::sqrt(sum_sq / arr.size());
  }

  /**
   * @brief Reverse the 1D array.
   */
  void reverse() {
    auto d = static_cast<Derived*>(this);
    std::reverse(d->data().begin(), d->data().end());
  }

  /**
   * @brief Get the index of the closest element to the given value.
   * @param value The value to find the closest index to.
   * @returns The index of the closest element.
   */
  size_t get_closest_index(double value) const {
    auto  d   = static_cast<const Derived*>(this);
    auto& arr = d->data();
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
  generic::ListSP<BaseArray<typename Derived::value_type>> even_divisions(
      size_t divisions) const {
    auto   d                = static_cast<const Derived*>(this);
    auto&  arr              = d->data();
    size_t partition_length = arr.size() / divisions;
    if (arr.size() % divisions != 0)
      throw std::runtime_error("Array cannot be evenly divided");
    auto result = std::make_shared<
        generic::List<BaseArray<typename Derived::value_type>>>();
    for (size_t i = 0; i < divisions; ++i) {
      BaseArray<typename Derived::value_type> segment(
          std::vector<typename Derived::value_type>(
              arr.begin() + i * partition_length,
              arr.begin() + (i + 1) * partition_length));
      result->push_back(segment);
    }
    return result;
  }
};
}  // namespace falcon_core::math::arrays
