#pragma once

#include "falcon_core/generic/List.hpp"

/**
 * @file Axes.hpp
 * @brief Defines the Axes container for FalconCore.
 */

namespace falcon_core::math {

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
  explicit Axes(const generic::List<Value>::Container& items)
      : generic::List<Value>(items) {}
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const generic::ListSP<Value>& items)
      : generic::List<Value>(*items) {}
  template <typename T = Value>
    requires std::is_base_of_v<generic::Song, T> &&
             (!generic::is_primitive<T>::value)
  bool operator==(const Axes<T>& other) const {
    if (this->size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
      const std::shared_ptr<T> our_conn   = this->at(i);
      const std::shared_ptr<T> other_conn = other.at(i);
      if (*our_conn != *other_conn) {
        return false;
      }
    }
    return true;
  }
  template <typename T = Value>
    requires generic::is_primitive<T>::value
  bool operator==(const Axes<T>& other) const {
    if (this->size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
      const T our_conn   = this->at(i);
      const T other_conn = other.at(i);
      if (our_conn != other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator!=(const Axes<Value>& other) const { return !(*this == other); }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<Value>>(this));
  }
};
template <typename V>
using AxesSP = std::shared_ptr<Axes<V>>;
}  // namespace falcon_core::math
