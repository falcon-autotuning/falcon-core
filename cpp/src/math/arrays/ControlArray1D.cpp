#include "falcon_core/math/arrays/ControlArray1D.hpp"

#include "falcon_core/generic/FArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
ControlArray1D::ControlArray1D() : ControlArray() {}
ControlArray1D::ControlArray1D(const xt::xarray<double>& arr)
    : ControlArray(arr) {}
ControlArray1D::ControlArray1D(const generic::FArraySP<double>& arr)
    : ControlArray(arr ? *arr : generic::FArray<double>()) {
  if (!arr) {
    throw std::invalid_argument("ControlArray: input array must not be null.");
  }
}
ControlArray1D::ControlArray1D(const ControlArraySP& arr) : ControlArray(arr) {}
ControlArray1D::ControlArray1D(xt::xarray<double>&& arr) noexcept
    : ControlArray(arr) {}
ControlArray1DSP ControlArray1D::operator+(const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

ControlArray1DSP ControlArray1D::operator+(const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

ControlArray1DSP ControlArray1D::operator+(
    const ControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator+(other));
}

ControlArray1DSP ControlArray1D::operator+(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray1D::operator+(std::make_shared<ControlArray1D>(other));
}

ControlArray1DSP ControlArray1D::operator-(const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

ControlArray1DSP ControlArray1D::operator-(const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

ControlArray1DSP ControlArray1D::operator-(
    const ControlArray1DSP& other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

ControlArray1DSP ControlArray1D::operator-(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator-(other));
}

ControlArray1DSP ControlArray1D::operator-() const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::operator-());
}

ControlArray1DSP ControlArray1D::operator*(const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator*(other));
}

ControlArray1DSP ControlArray1D::operator*(const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator*(other));
}

ControlArray1DSP ControlArray1D::operator/(const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator/(other));
}

ControlArray1DSP ControlArray1D::operator/(const int other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator/(other));
}

ControlArray1DSP ControlArray1D::operator^(const double other) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::operator^(other));
}

ControlArray1DSP ControlArray1D::abs() const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::abs());
}

double ControlArray1D::min() const { return generic::FArray<double>::min(); }

ControlArray1DSP ControlArray1D::min(const ControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<ControlArray1D>(generic::FArray<double>::min(other));
}

ControlArray1DSP ControlArray1D::min(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<ControlArray1D>(generic::FArray<double>::min(other));
}

double ControlArray1D::max() const { return generic::FArray<double>::max(); }

ControlArray1DSP ControlArray1D::max(const ControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<ControlArray1D>(generic::FArray<double>::max(other));
}

ControlArray1DSP ControlArray1D::max(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<ControlArray1D>(generic::FArray<double>::max(other));
}

ControlArray1DSP ControlArray1D::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<ControlArray1D>(
      generic::FArray<double>::reshape(shape));
}

ControlArray1DSP ControlArray1D::flip(size_t axis) const {
  return std::make_shared<ControlArray1D>(generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> ControlArray1D::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> ControlArray1D::gradient() const {
  return generic::FArray<double>::gradient();
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
