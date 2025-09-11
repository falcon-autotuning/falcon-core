/**
 * @file ControlArray.hpp
 * @brief Defines the ControlArray for control independant axis data for falcon.
 */

#pragma once

#include "falcon_core/math/arrays/IsControl.hpp"
namespace falcon_core::math::arrays {

/**
 * @brief Array type for control independant axis data
 */
class ControlArray : public generic::FArray<double>, public IsControl<double> {
 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<FArray<double>>(this),
       principle_dimension(),
       alignment());
  }

 public:
  ControlArray();
  ControlArray(const xt::xarray<double>& arr);
  ControlArray(const FArray<double>& arr);
  ControlArray(xt::xarray<double>&& arr) noexcept;
  ControlArray(const ControlArray&)                = default;
  ControlArray(ControlArray&&) noexcept            = default;
  ControlArray& operator=(const ControlArray&)     = default;
  ControlArray& operator=(ControlArray&&) noexcept = default;
  static std::shared_ptr<ControlArray> zeros(const std::vector<size_t>& shape) {
    return std::make_shared<ControlArray>(xt::zeros<double>(shape));
  }
  static std::shared_ptr<ControlArray> empty(const std::vector<size_t>& shape) {
    return std::make_shared<ControlArray>(xt::empty<double>(shape));
  }
  // Arithmetic operators
  std::shared_ptr<ControlArray> operator+(const double other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator+(other));
  }

  std::shared_ptr<ControlArray> operator+(const int other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator+(other));
  }

  std::shared_ptr<ControlArray> operator+(
      const std::shared_ptr<ControlArray>& other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator+(other));
  }

  std::shared_ptr<ControlArray> operator-(const double other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator-(other));
  }

  std::shared_ptr<ControlArray> operator-(const int other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator-(other));
  }

  std::shared_ptr<ControlArray> operator-(
      const std::shared_ptr<ControlArray>& other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator-(other));
  }

  std::shared_ptr<ControlArray> operator-() const {
    return std::make_shared<ControlArray>(generic::FArray<double>::operator-());
  }

  std::shared_ptr<ControlArray> operator*(const double other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator*(other));
  }

  std::shared_ptr<ControlArray> operator*(const int other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator*(other));
  }

  std::shared_ptr<ControlArray> operator*(
      const std::shared_ptr<ControlArray>& other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator*(other));
  }

  std::shared_ptr<ControlArray> operator/(const double other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator/(other));
  }

  std::shared_ptr<ControlArray> operator/(const int other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator/(other));
  }

  std::shared_ptr<ControlArray> operator/(
      const std::shared_ptr<ControlArray>& other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator/(other));
  }

  std::shared_ptr<ControlArray> operator^(const double other) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::operator^(other));
  }

  std::shared_ptr<ControlArray> abs() const {
    return std::make_shared<ControlArray>(generic::FArray<double>::abs());
  }

  std::shared_ptr<ControlArray> min(
      const std::shared_ptr<ControlArray>& other) const {
    return std::make_shared<ControlArray>(generic::FArray<double>::min());
  }

  std::shared_ptr<ControlArray> max(
      const std::shared_ptr<ControlArray>& other) const {
    return std::make_shared<ControlArray>(generic::FArray<double>::max());
  }

  std::shared_ptr<ControlArray> reshape(
      const std::vector<size_t>& shape) const {
    return std::make_shared<ControlArray>(
        generic::FArray<double>::reshape(shape));
  }

  std::shared_ptr<ControlArray> flip(size_t axis) const {
    return std::make_shared<ControlArray>(generic::FArray<double>::flip(axis));
  }
  generic::FArraySP<double> gradient(size_t axis) const {
    return generic::FArray<double>::gradient(axis);
  }
  generic::ListSP<generic::FArray<double>> gradient() const {
    return generic::FArray<double>::gradient();
  }
};
using ControlArraySP = std::shared_ptr<ControlArray>;
}  // namespace falcon_core::math::arrays
