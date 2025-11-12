#pragma once

#include "falcon_core/generic/List.hpp"

/**
 * @file Axes.hpp
 * @brief Defines the Axes container for FalconCore.
 */

namespace falcon_core {
namespace math {
template <typename Value>
static const generic::List<Value>& list_check_and_deref(
    const generic::ListSP<Value>& items) {
  if (!items) throw std::invalid_argument("Axes: items must not be null.");
  return *items;
}
/**
 * @brief Container for a collection of axis objects.
 *
 * @details
 * Axes is a vector-like container for axis objects, such as discretizers or
 * numeric axes. Provides standard vector access methods.
 *
 * The order matters, as it is used to index the hypercube
 *
 * @tparam T The type of axis object (e.g., double, BaseDiscretizer).
 */
template <typename Value>
class Axes : public generic::List<Value> {
 public:
  Axes() = default;
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const typename generic::List<Value>::Container& items)
      : generic::List<Value>(items) {}
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const generic::ListSP<Value>& items)
      : generic::List<Value>(list_check_and_deref<Value>(items)) {}
  bool operator==(const Axes<Value>& other) const {
    return operator_equal_impl(
        other, typename generic::category::determine_tag<Value>::type{});
  }
  bool operator!=(const Axes<Value>& other) const { return !(*this == other); }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<Value>>(this));
  }
  bool operator_equal_impl(const Axes<Value>& other,
                           generic::category::song_tag) const {
    if (this->size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
      const std::shared_ptr<Value> our_conn   = this->at(i);
      const std::shared_ptr<Value> other_conn = other.at(i);
      if (*our_conn != *other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator_equal_impl(const Axes<Value>& other,
                           generic::category::primitive_tag) const {
    if (this->size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
      const Value our_conn   = this->at(i);
      const Value other_conn = other.at(i);
      if (our_conn != other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator_equal_impl(const Axes<Value>& other,
                           generic::category::other_tag) const {
    throw std::runtime_error("Unsupported type for Axes");
  }
};
template <typename V>
using AxesSP = std::shared_ptr<Axes<V>>;
}  // namespace math
}  // namespace falcon_core
