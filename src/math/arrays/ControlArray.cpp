#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core::math::arrays {

ControlArray::ControlArray() : FArray<double>() {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray::ControlArray(const xt::xarray<double>& arr)
    : FArray<double>(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray::ControlArray(xt::xarray<double>&& arr) noexcept
    : FArray<double>(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::ControlArray)
