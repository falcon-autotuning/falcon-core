#pragma once
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

/**
 * @file Axes.hpp
 * @brief Defines the Axes container for FalconCore.
 */

namespace falcon_core {
namespace math {

/**
 * @brief Container for a collection of axis objects.
 *
 * @details
 * Axes is a vector-like container for axis objects, such as discretizers or numeric axes.
 * Provides standard vector access methods.
 *
 * @tparam T The type of axis object (e.g., double, BaseDiscretizer).
 */
template <typename T>
class Axes : public generic::Song {
 public:
  using StoredType = typename std::conditional<
      std::is_arithmetic<T>::value ||
      std::is_same<T, std::string>::value ||
      std::is_same<T, char>::value ||
      std::is_same<T, bool>::value,
      T,
      std::shared_ptr<T>>::type;

  /**
   * @brief Default constructor.
   */
  Axes() = default;

  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const std::vector<StoredType>& items) : _items(items) {}

  // Vector-like methods

  /**
   * @brief Get the number of axes.
   * @return Number of axes.
   */
  size_t size() const { return _items.size(); }

  /**
   * @brief Check if the container is empty.
   * @return True if empty, false otherwise.
   */
  bool empty() const { return _items.empty(); }

  /**
   * @brief Add an axis to the container.
   * @param item Axis object.
   */
  void push_back(const StoredType& item) { _items.push_back(item); }

  /**
   * @brief Access axis at index (const).
   * @param idx Index.
   * @return Axis object.
   */
  const StoredType& at(size_t idx) const { return _items.at(idx); }

  /**
   * @brief Access axis at index (mutable).
   * @param idx Index.
   * @return Axis object.
   */
  StoredType& at(size_t idx) { return _items.at(idx); }

  /**
   * @brief Get all axis items (const).
   * @return Vector of axis objects.
   */
  const std::vector<StoredType>& items() const { return _items; }

  /**
   * @brief Get all axis items (mutable).
   * @return Vector of axis objects.
   */
  std::vector<StoredType>& items() { return _items; }

#ifndef SWIG
  /**
   * @brief Indexing operator (const).
   * @param idx Index.
   * @return Axis object.
   */
  const StoredType& operator[](size_t idx) const { return _items[idx]; }

  /**
   * @brief Indexing operator (mutable).
   * @param idx Index.
   * @return Axis object.
   */
  StoredType& operator[](size_t idx) { return _items[idx]; }
#endif

 private:
  std::vector<StoredType> _items; ///< Container for axis objects.

  friend class cereal::access;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _items);
  }
};

}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math;

#ifndef SWIG
CEREAL_REGISTER_TYPE(Axes<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Axes<double>)
CEREAL_REGISTER_TYPE(Axes<falcon_core::math::discretizers::BaseDiscretizer>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    Axes<falcon_core::math::discretizers::BaseDiscretizer>)
#endif
