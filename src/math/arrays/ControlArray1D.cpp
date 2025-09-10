#include "falcon_core/math/arrays/ControlArray1D.hpp"

namespace falcon_core::math::arrays {

ControlArray1D::ControlArray1D() : ControlArray() {}
ControlArray1D::ControlArray1D(const xt::xarray<double>& arr)
    : ControlArray(arr) {}
ControlArray1D::ControlArray1D(xt::xarray<double>&& arr) noexcept
    : ControlArray(arr) {}

}  // namespace falcon_core::math::arrays

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::arrays::ControlArray1D)
