/**
 * @file IncreasingAlignment.hpp
 * @brief Defines the IncreasingAlignment class for FalconCore.
 */

#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/**
 * @brief A three state system.
 * The three states are 1, -1, and 0.
 * 0 implies no trend in the domain.
 */
class IncreasingAlignment : public generic::Song {
  int _alignment;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), _alignment);
  }

 public:
  IncreasingAlignment();
  IncreasingAlignment(const bool alignment);
  /**
   * @brief Return the alignment of the domain.
   */
  int  alignment() const;
  bool operator==(const IncreasingAlignment& other) const;
  bool operator!=(const IncreasingAlignment& other) const;
};
using IncreasingAlignmentSP = std::shared_ptr<IncreasingAlignment>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
