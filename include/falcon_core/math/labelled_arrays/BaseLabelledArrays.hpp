/**
 * @file BaseLabelledArrays.hpp
 * @brief Defines the BaseLabelledArrays template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

/// @brief Container for multiple labelled arrays.
/// @tparam T Type of labelled array.
template <typename T>
class BaseLabelledArrays : public generic::Song {
 public:
  /// @brief Type alias for value type.
  using value_type = T;
  /// @brief Type alias for container type.
  using container_type = std::vector<std::shared_ptr<value_type>>;

  BaseLabelledArrays();

  void append(const std::shared_ptr<value_type> &labelled_array);
  const container_type &get_arrays() const;

 private:
  container_type _arrays;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<generic::Song>(this), _arrays);
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
