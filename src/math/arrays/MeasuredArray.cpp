#include "falcon_core/math/arrays/MeasuredArray.hpp"

namespace falcon_core::math::arrays {

MeasuredArray::MeasuredArray() : BaseArray<double>() {}
MeasuredArray::MeasuredArray(const xt::xarray<double>& arr)
    : BaseArray<double>(arr) {}
MeasuredArray::MeasuredArray(xt::xarray<double>&& arr) noexcept
    : BaseArray<double>(arr) {}
}  // namespace falcon_core::math::arrays

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseArray<double>,
    falcon_core::math::arrays::MeasuredArray)
