#include "falcon_core/math/arrays/ControlArray1D.hpp"

#include "falcon_core/generic/FArray.hpp"

namespace falcon_core::math::arrays {
ControlArray1D::ControlArray1D() : ControlArray() {
  _principle_dimension = 0;
  _alignment = std::make_shared<IncreasingAlignment>(IncreasingAlignment(true));
}
ControlArray1D::ControlArray1D(const xt::xarray<double>& arr)
    : ControlArray(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray1D::ControlArray1D(const generic::FArraySP<double>& arr)
    : ControlArray(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray1D::ControlArray1D(const ControlArraySP& arr) : ControlArray(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray1D::ControlArray1D(xt::xarray<double>&& arr) noexcept
    : ControlArray(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
std::shared_ptr<ControlArray1D> ControlArray1D::operator+(
    const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator+(
    const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator+(
    const std::shared_ptr<ControlArray1D>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator-(
    const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator-(
    const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator-(
    const std::shared_ptr<ControlArray1D>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator-() const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::operator-());
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator*(
    const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator*(
    const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator*(
    const std::shared_ptr<ControlArray1D>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator/(
    const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator/(
    const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator/(
    const std::shared_ptr<ControlArray1D>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator/(other));
}
std::shared_ptr<ControlArray1D> ControlArray1D::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::operator^(
    const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::abs() const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::abs());
}

std::shared_ptr<ControlArray1D> ControlArray1D::min(
    const std::shared_ptr<ControlArray1D>& other) const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::min(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::min(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::max(
    const std::shared_ptr<ControlArray1D>& other) const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::max(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::max(other));
}

std::shared_ptr<ControlArray1D> ControlArray1D::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<ControlArray1D> ControlArray1D::flip(size_t axis) const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> ControlArray1D::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> ControlArray1D::gradient() const {
  return generic::FArray<double>::gradient();
}
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::ControlArray1D)
