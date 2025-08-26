/**
 * @file IncreasingAlignment.hpp
 * @brief Defines the IncreasingAlignment class for FalconCore.
 */

#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/// @brief Marker class for increasing alignment of arrays.
class IncreasingAlignment : public generic::Song {
 public:
  /// @brief Default constructor.
  IncreasingAlignment() = default;

 private:
  friend class cereal::access;
  /// @brief Serialization method for cereal.
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this));
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::IncreasingAlignment)
#endif
