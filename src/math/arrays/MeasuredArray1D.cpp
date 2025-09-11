#include "falcon_core/math/arrays/MeasuredArray1D.hpp"

namespace falcon_core::math::arrays {

MeasuredArray1D::MeasuredArray1D() : MeasuredArray() {}
MeasuredArray1D::MeasuredArray1D(const xt::xarray<double>& arr)
    : MeasuredArray(arr) {}
MeasuredArray1D::MeasuredArray1D(xt::xarray<double>&& arr) noexcept
    : MeasuredArray(arr) {}
void MeasuredArray1D::smooth(size_t window_size) {
  auto&              arr    = this->xtensor();
  size_t             n      = arr.size();
  xt::xarray<double> result = xt::zeros<double>({n});
  for (size_t i = 0; i < n; ++i) {
    size_t start = (i < window_size / 2) ? 0 : i - window_size / 2;
    size_t end   = std::min(n, i + window_size / 2 + 1);
    result(i)    = xt::mean(xt::view(arr, xt::range(start, end)))();
  }
  arr = result;
}

}  // namespace falcon_core::math::arrays

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::arrays::MeasuredArray,
                                     falcon_core::math::arrays::MeasuredArray1D)
