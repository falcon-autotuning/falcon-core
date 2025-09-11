#pragma once

#include "falcon_core/math/arrays/Is1D.hpp"

namespace falcon_core::math::labelled_arrays {

/**
 * @brief A mixin that provides 1D-specific functionality to labelled array
 * classes.
 *
 * The class that inherits from this must provide:
 * - array() method returning an array that implements Is1D mixin
 */
template <typename Parent>
class IsLabelled1D {
 public:
  using ArrayType = typename Parent::array_type;

  /**
   * @brief Get the array cast to Is1D type.
   * This avoids repetitive casting in all methods.
   */
  const arrays::Is1D<arrays::BaseArray<ArrayType>>& _1d_array() const {
    return static_cast<const arrays::Is1D<arrays::BaseArray<ArrayType>>&>(
        *array());
  }

  /**
   * @brief Get the first element of the 1D array.
   */
  ArrayType get_start() const { return _1d_array().get_start(); }

  /**
   * @brief Get the last element of the 1D array.
   */
  ArrayType get_end() const { return _1d_array().get_end(); }

  /**
   * @brief Get the minimum value in the 1D array.
   */
  ArrayType get_min() const { return _1d_array().get_min(); }

  /**
   * @brief Get the maximum value in the 1D array.
   */
  ArrayType get_max() const { return _1d_array().get_max(); }

  /**
   * @brief Check if the array is decreasing.
   */
  bool is_decreasing() const { return _1d_array().is_decreasing(); }

  /**
   * @brief Check if the array is increasing.
   */
  bool is_increasing() const { return _1d_array().is_increasing(); }

  /**
   * @brief Get the distance between the first and last element.
   */
  ArrayType get_distance() const { return _1d_array().get_distance(); }

  /**
   * @brief Get the standard deviation of the 1D array.
   */
  double get_std() const { return _1d_array().get_std(); }

  /**
   * @brief Get the mean of the 1D array.
   */
  double get_mean() const { return _1d_array().get_mean(); }

  /**
   * @brief Get the index of the closest element to the given value.
   * @param value The value to find the closest index to.
   */
  size_t get_closest_index(ArrayType value) const {
    return _1d_array().get_closest_index(value);
  }

  /**
   * @brief Reverse the 1D array.
   */
  void reverse() { _1d_array().reverse(); }
};

}  // namespace falcon_core::math::labelled_arrays
