#pragma once
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/FArrayProtocol.hpp"
#include "falcon_core/math/arrays/IncreasingAlignment.hpp"
namespace falcon_core::math::arrays {
template <typename T>
class IsControl : public virtual generic::IFArray<T> {
  int                   _principle_dimension;
  IncreasingAlignmentSP _alignment;

 public:
  virtual generic::FArraySP<T>                gradient(size_t axis) const = 0;
  virtual generic::ListSP<generic::FArray<T>> gradient() const            = 0;
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
    auto                                               shape = this->shape();

    for (size_t dim = 0; dim < shape.size(); ++dim) {
      if (shape[dim] <= 1) continue;

      generic::FArraySP<double> grad = this->gradient(dim);

      if (xt::all(grad->xtensor() < 0)) {
        alignments.emplace_back(std::make_shared<IncreasingAlignment>(false),
                                dim);
      } else if (xt::all(grad->xtensor() > 0)) {
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
