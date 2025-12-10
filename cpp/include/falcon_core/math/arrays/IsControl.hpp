#pragma once
#include <shared_mutex>

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/FArrayProtocol.hpp"
#include "falcon_core/math/arrays/IncreasingAlignment.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
template <typename T>
class IsControl : public virtual generic::IFArray<T> {
 protected:
  int                             _principle_dimension;
  IncreasingAlignmentSP           _alignment;
  mutable std::shared_timed_mutex _mu_alignment;
  mutable std::shared_timed_mutex _mu_principle_dimension;

 public:
  virtual generic::FArraySP<T>                gradient(size_t axis) const = 0;
  virtual generic::ListSP<generic::FArray<T>> gradient() const            = 0;
  /**
   * @brief Return the principle dimension of the array.
   */
  int principle_dimension() const {
    std::shared_lock<std::shared_timed_mutex> lock_pd(_mu_principle_dimension);
    return _principle_dimension;
  }
  /**
   * @brief Return the increasing alignments for each dimension.
   */
  IncreasingAlignmentSP alignment() const {
    std::shared_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
    return _alignment;
  }
  /**
   * @brief Recalculates the alignments zmerinobased on current data.
   */
  void update_alignments() {
    std::unique_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
    _alignment = _determine_alignments();
  }
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

      if (xt::all(grad->data() < 0)) {
        alignments.emplace_back(std::make_shared<IncreasingAlignment>(false),
                                dim);
      } else if (xt::all(grad->data() > 0)) {
        alignments.emplace_back(std::make_shared<IncreasingAlignment>(true),
                                dim);
      }
    }

    if (alignments.empty()) {
      throw std::runtime_error("IsControl: The array must have an alignment.");
    }
    if (alignments.size() > 1) {
      throw std::runtime_error(
          "IsControl: The array must have exactly one alignment dimension.");
    }
    std::unique_lock<std::shared_timed_mutex> lock_pd(_mu_principle_dimension);
    _principle_dimension = alignments[0].second;
    return alignments[0].first;
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
