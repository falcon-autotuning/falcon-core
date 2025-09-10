/**
 * @file ControlArray.hpp
 * @brief Defines the ControlArray template for FalconCore.
 */

#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

namespace falcon_core::math::arrays {

/// @brief Array type for control data, derived from BaseArray.
/// @tparam T Element type.
template <typename T>
class ControlArray : public BaseArray<T> {
  int                   _principle_dimension;
  IncreasingAlignmentSP _alignment;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseArray<T>>(this),
       _principle_dimension,
       _alignment);
  }

 public:
  ControlArray()
      : BaseArray<T>(),
        _principle_dimension(0),
        _alignment(_determine_alignments()) {}
  ControlArray(const xt::xarray<T>& arr)
      : BaseArray<T>(arr),
        _principle_dimension(0),
        _alignment(_determine_alignments()) {}
  ControlArray(xt::xarray<T>&& arr) noexcept
      : BaseArray<T>(arr),
        _principle_dimension(0),
        _alignment(_determine_alignments()) {}
  /**
   * @brief Return the principle dimension of the array.
   */
  int principle_dimension() const { return _principle_dimension; }
  /**
   * @brief Return the increasing alignments for each dimension.
   */
  IncreasingAlignmentSP alignment() const { return _alignment; }
  /**
   * @brief Recalculates the alignments zmerinobased on current data.
   */
  void update_alignments() { _alignment = _determine_alignments(); }
  /**
   * @brief Determine the alignment for each dimension of the array.
   * for each dimension checks if the values are increasing, decreasing, or not
   * changing.
   * @returns the alignment for each dimension.
   * @throws std::runtime_error if no alignment is found.
   * @throws std::runtime_error if more than one alignment is found.
   */
  IncreasingAlignmentSP _determine_alignments() {
    std::vector<std::pair<IncreasingAlignmentSP, int>> alignments;
    auto shape = this->_data.shape();

    for (size_t dim = 0; dim < shape.size(); ++dim) {
      if (shape[dim] <= 1) continue;

      auto grad = this->gradient(dim);

      if (xt::all(grad < 0)) {
        alignments.emplace_back(std::make_shared<IncreasingAlignment>(false),
                                dim);
      } else if (xt::all(grad > 0)) {
        alignments.emplace_back(std::make_shared<IncreasingAlignment>(true),
                                dim);
      }
    }

    if (alignments.empty()) {
      throw std::runtime_error("The array must have an alignment.");
    }
    if (alignments.size() > 1) {
      throw std::runtime_error(
          "The array must have exactly one alignment dimension.");
    }

    _principle_dimension = alignments[0].second;
    return alignments[0].first;
  }
};
}  // namespace falcon_core::math::arrays
