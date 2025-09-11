/**
 * @file BaseArray.hpp
 * @brief Defines the BaseArray template for FalconCore.
 */

#pragma once

#include <memory>

#include "falcon_core/generic/FArray.hpp"

namespace falcon_core::math::arrays {

template <typename T>
class BaseArray : public generic::FArray<T> {
 public:
  using value_type = T;
  BaseArray()      = default;
  BaseArray(const xt::xarray<T>& arr) : generic::FArray<T>(arr) {}
  BaseArray(xt::xarray<T>&& arr) noexcept : generic::FArray<T>(arr) {}
  explicit BaseArray(const std::vector<size_t>& shape)
      : generic::FArray<T>(shape) {}
  double get_sum_of_squares() const { return (*(this ^ 2)).data().sum(); }
  double get_sum_of_squares(const int other) const {
    return ((*(this->data() - other) ^ 2)).data().sum();
  }
  double get_sum_of_squares(const double other) const {
    return ((*(this->data() - other) ^ 2)).data().sum();
  }
  double get_sum_of_squares(
      const std::shared_ptr<generic::FArray<T>>& other) const {
    return ((*(this->data() - other->data()) ^ 2)).data().sum();
  }
  double get_sum_of_squares(const std::shared_ptr<BaseArray<T>>& other) const {
    return ((*(this->data() - other->data()) ^ 2)).data().sum();
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::FArray<T>>(this));
  }
};

template <typename T>
using BaseArraySP = std::shared_ptr<BaseArray<T>>;

}  // namespace falcon_core::math::arrays
