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
template <typename T>
class Axes : public generic::List<T> {
 public:
  Axes() = default;
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const generic::List<T>::Container& items)
      : generic::List<T>(items) {}
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const generic::ListSP<T>& items) : generic::List<T>(*items) {}

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<T>>(this));
  }
};
template <typename V>
using AxesSP = std::shared_ptr<Axes<V>>;
}  // namespace falcon_core::math
