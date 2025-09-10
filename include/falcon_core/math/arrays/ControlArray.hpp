/**
 * @file ControlArray.hpp
 * @brief Defines the ControlArray for control independant axis data for falcon.
 */

#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

namespace falcon_core::math::arrays {

/**
 * @brief Array type for control independant axis data
 */
class ControlArray : public BaseArray<double> {
  int                   _principle_dimension;
  IncreasingAlignmentSP _alignment;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseArray<double>>(this),
       _principle_dimension,
       _alignment);
  }

 public:
  ControlArray();
  ControlArray(const xt::xarray<double>& arr);
  ControlArray(xt::xarray<double>&& arr) noexcept;
  /**
   * @brief Return the principle dimension of the array.
   */
  int principle_dimension() const;
  /**
   * @brief Return the increasing alignments for each dimension.
   */
  IncreasingAlignmentSP alignment() const;
  /**
   * @brief Recalculates the alignments zmerinobased on current data.
   */
  void update_alignments();
  /**
   * @brief Determine the alignment for each dimension of the array.
   * for each dimension checks if the values are increasing, decreasing, or not
   * changing.
   * @returns the alignment for each dimension.
   * @throws std::runtime_error if no alignment is found.
   * @throws std::runtime_error if more than one alignment is found.
   */
  IncreasingAlignmentSP _determine_alignments();
};
}  // namespace falcon_core::math::arrays
