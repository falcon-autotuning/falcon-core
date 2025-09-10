
#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core::math::arrays {

ControlArray::ControlArray()
    : BaseArray<double>(),
      _principle_dimension(0),
      _alignment(_determine_alignments()) {}
ControlArray::ControlArray(const xt::xarray<double>& arr)
    : BaseArray<double>(arr),
      _principle_dimension(0),
      _alignment(_determine_alignments()) {}
ControlArray::ControlArray(xt::xarray<double>&& arr) noexcept
    : BaseArray<double>(arr),
      _principle_dimension(0),
      _alignment(_determine_alignments()) {}
int ControlArray::principle_dimension() const { return _principle_dimension; }
IncreasingAlignmentSP ControlArray::alignment() const { return _alignment; }
void ControlArray::update_alignments() { _alignment = _determine_alignments(); }
IncreasingAlignmentSP ControlArray::_determine_alignments() {
  std::vector<std::pair<IncreasingAlignmentSP, int>> alignments;
  auto                                               shape = this->shape();

  for (size_t dim = 0; dim < shape.size(); ++dim) {
    if (shape[dim] <= 1) continue;

    generic::FArraySP<double> grad = this->gradient(dim);

    if (xt::all(grad->xtensor() < 0)) {
      alignments.emplace_back(std::make_shared<IncreasingAlignment>(false),
                              dim);
    } else if (xt::all(grad->xtensor() > 0)) {
      alignments.emplace_back(std::make_shared<IncreasingAlignment>(true), dim);
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
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseArray<double>,
    falcon_core::math::arrays::ControlArray)
