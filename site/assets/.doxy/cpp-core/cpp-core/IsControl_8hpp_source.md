

# File IsControl.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**IsControl.hpp**](IsControl_8hpp.md)

[Go to the documentation of this file](IsControl_8hpp.md)


```C++
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
  int principle_dimension() const {
    std::shared_lock<std::shared_timed_mutex> lock_pd(_mu_principle_dimension);
    return _principle_dimension;
  }
  IncreasingAlignmentSP alignment() const {
    std::shared_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
    return _alignment;
  }
  void update_alignments() {
    std::unique_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
    _alignment = _determine_alignments();
  }
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
```


