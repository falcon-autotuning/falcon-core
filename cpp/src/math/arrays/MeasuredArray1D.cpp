#include "falcon_core/math/arrays/MeasuredArray1D.hpp"

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
MeasuredArray1D::MeasuredArray1D() : MeasuredArray() {}
MeasuredArray1D::MeasuredArray1D(const xt::xarray<double>& arr)
    : MeasuredArray(arr) {}
MeasuredArray1D::MeasuredArray1D(const generic::FArraySP<double>& arr)
    : MeasuredArray(arr) {}
MeasuredArray1D::MeasuredArray1D(const MeasuredArraySP& arr)
    : MeasuredArray(arr) {}
MeasuredArray1D::MeasuredArray1D(xt::xarray<double>&& arr) noexcept
    : MeasuredArray(arr) {}
std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator+(
    const double other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator+(
    const int other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator+(
    const std::shared_ptr<MeasuredArray1D>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator-(
    const double other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator-(
    const int other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator-(
    const std::shared_ptr<MeasuredArray1D>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator-() const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator-());
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator*(
    const double other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator*(
    const int other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator*(
    const std::shared_ptr<MeasuredArray1D>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator/(
    const double other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator/(
    const int other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator/(
    const std::shared_ptr<MeasuredArray1D>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator/(other));
}
std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::operator^(
    const double other) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::abs() const {
  return std::make_shared<MeasuredArray1D>(generic::FArray<double>::abs());
}

double MeasuredArray1D::min() const { return generic::FArray<double>::min(); }

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::min(
    const std::shared_ptr<MeasuredArray1D>& other) const {
  return std::make_shared<MeasuredArray1D>(generic::FArray<double>::min(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<MeasuredArray1D>(generic::FArray<double>::min(other));
}

double MeasuredArray1D::max() const { return generic::FArray<double>::max(); }

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::max(
    const std::shared_ptr<MeasuredArray1D>& other) const {
  return std::make_shared<MeasuredArray1D>(generic::FArray<double>::max(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<MeasuredArray1D>(generic::FArray<double>::max(other));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<MeasuredArray1D>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<MeasuredArray1D> MeasuredArray1D::flip(size_t axis) const {
  return std::make_shared<MeasuredArray1D>(generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> MeasuredArray1D::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> MeasuredArray1D::gradient() const {
  return generic::FArray<double>::gradient();
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
